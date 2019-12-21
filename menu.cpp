//
//  menu.cpp
//  laba4
//
//  Created by Полина Подчуфарова on 21/12/2019.
//  Copyright © 2019 Полина Подчуфарова. All rights reserved.
//

#include <stdio.h>
#include "menu.h"
using namespace std;
namespace menu {

int get_char(char& str) {
    
    int r = 0;
    do {
        std::cin >> str;
        if (std::cin.eof()) {
            std::cin.clear();
            return -1;
        }
        if (!std::cin.good()) {
            std::cin.clear();
            while (std::cin.get() != '\n');
            r++;
        }
        else r = 0;
    } while (r);
    return r;
}
    
    
char  dialog() {
    cout<<"choose a task"<<endl;
    cout<<"w-game loading"<<endl;//+
    cout<<"q-output map"<<endl;//+
    cout<<"e-output school tab "<<endl;//
    cout<<"g- start game"<<endl;
    cout<<"s-save current state of the game"<<endl;//+
    char  d ;
    get_char(d);
    return d;
}
    char dialog_s(){
        cout<<"choose a task"<<endl;
        cout<<"c-summon menu"<<endl;
        cout<<"o-unpgrade school"<<endl;
        cout<<"r-accumulate energy"<<endl;//+
        char  d ;
        get_char(d);
        return d;
    }
    //спросить насчёт имён призывателей
    void menu_s(char d,laba4::Summoner& s,laba4:: Landscape& L){
        char ch;
        cin>>ch;
        switch (d) {
                case 'c':{//summon menu
                    laba4::Summoner S=L.get_User_Summoner();
                    int d2;
                    laba4::School *sch;
                    laba4:: Skill sk;
                    laba4::Immoral_Troop *tr=nullptr;
                    laba4::Coordinates p(0,0);
                    cout<<"From what school do you want summon?"<<endl;
                    cout<<"1.necromancy"<<endl;
                    cout<<"2.animalism"<<endl;
                    cout<<"3.demonology"<<endl;
                    cout<<"4.other_realities"<<endl;
                    cout<<"5.elementalis"<<endl;
                    cin>>d2;
                    switch (d2) {
                        case 1:{
                            sch=L.find_school("necromancy");
                            break;
                        }
                        case 2:{
                            sch=L.find_school("animalism");
                            break;
                        }
                        case 3:{
                            sch=L.find_school("demonology");
                            break;
                        }
                        case 4:{
                            sch=L.find_school("other_realities");
                            break;
                        }
                        case 5:{
                            sch=L.find_school("elemantalis");
                            break;
                        }
                            
                        default:{
                            sch=nullptr;
                            cout<<"Incorrect choise"<<endl;
                            
                        }
                    }
                    try{
                        
                        L.choose_skill(sch,sk,S);
                        
                    }
                    catch(exception &ex){
                        cout<<ex.what()<<endl;
                    }
                    cout<<"What troop do you want summon?"<<endl;
                    cout<<"1.Immoral Troop"<<endl;
                    cout<<"2.Ordinary Troop"<<endl;
                    cout<<"3.Ressurecting Ordinary Troop"<<endl;
                    cout<<"4.Ressurecting Immoral Troop"<<endl;
                    int d1;
                    
                    cin>>d1;
                    switch (d1){
                        case 1:{
                            
                            tr=new laba4::Immoral_Troop(1,1,0,10,sk.get_creature(),sch,p);
                            break;
                        }
                        case 2:{
                            tr=new laba4::Ordinary_Troop(1,10,1,0,10,sk.get_creature(),sch,p);
                            break;
                            
                        }
                        case 3:{
                            tr=new laba4::OResurrecting_Troop(1,0,10,1,0,10,sk.get_creature(),sch,p);
                            break;
                        }
                        case 4:{
                            
                            tr=new laba4::IResurrecting_Troop(1,0,1,0,10,sk.get_creature(),sch,p);
                            //laba4::IResurrecting_Troop *ptr= dynamic_cast<laba4::IResurrecting_Troop*>(tr);//преобразование типа просто проверяла работает
                            // cout<< ptr->get_dead_creatures()<<endl;
                            break;
                        }
                    }
                    S.summon(tr);
                    L.set_user_summoner(S);
                    L.install_troop_in_cell();
                    L.print_summoner();
                    break;
                }
            case 'o':{
                try {
                    int exp,d;
                    std::cout<<"Your experience:" << s.get_experience() << std::endl;
                    std::cout <<"Enter count of experience:" << std::endl;
                    cin>>exp;
                    string a;
                    std::cout <<"Choose school:" << std::endl;
                    std::cout << "1 - animalism " << std::endl;
                    std::cout << "2 - demonology" << std::endl;
                    std::cout << "3 - elementalism" <<std::endl;
                    std::cout << "4 - necromancy" << std::endl;
                    std::cout <<"5 - other_realities" << std::endl;
                    cin>>d;//check
                    if (d == 1) {
                        a = "animalism";
                    }
                    if (d == 2) {
                        a = "demonology";
                    }
                    if (d == 3) {
                        a = "elementalism";
                    }
                    if (d == 4) {
                        a = "necromancy";
                    }
                    if (d == 5) {
                        a = "other_realities";
                    }
                     L.school_upgrade(s,a,exp);
                }
                
                catch (std::exception & ex)
                {
                    cout << ex.what() << endl;
                }
                break;
            }
            case 'r':{
                try{
                    L.energy_accumulation(s);
                }
                catch (exception &ex){
                    cout<<ex.what()<<endl;
                }
                break;
            }
            default:{
                 cout<<"incorrect choice"<<endl;
            }
        }
    }
    char dialog_troop(){
        cout<<"g- move menu"<<endl;
        cout<<"a-attack the point"<<endl;
        cout<<"h -ressurect your troop"<<endl;
        char d;
        get_char(d);
        return d;
    }
    void menu_troop(char d,laba4::Landscape &L,laba4::Immoral_Troop *tr){
            switch (d) {
               
                case 'g':{//move menu
					char  q;
					string k;
					L.print_map();
					if (tr->get_speed() <= 0) {
						std::cout << "You no have force to move!" << std::endl;
						break;
					}
					else
						do {
							std::cout << "Enter w, a, s, d to move your troop in the appropriate direction: " << std::endl;
							get_char(q);
							try {
								if ((q == 'w') || (q == 'a') || (q == 's') || (q == 'd')) {
									if (L.move_troop(q, tr))
										tr->set_speed(tr->get_speed() - 1);
								}
								else
									std::cout << "Wrong letter! " << std::endl;
							}
							catch (exception & x) {
								cout << x.what() << endl;
							}
							cout << "Enter exit for exit or go to continue" << endl;;
							cin >> k;
						} while (k != "exit");
                        break;
                        }
                case 'a':{
					char q;
					cout << "Enter character:" << endl;
					cout << "w - for attack point above you" << endl;
					cout << "a - for attack point to your left" << endl;
					cout << "s - for attack point below you" << endl;
					cout << "d - for attack point to your right" << endl;
					get_char(q);
					if (q == 'w') {
						if ((tr->get_p().y - 1) >= 0) {//проверка на выход за карту
							if (L.get_cell(tr->get_p().x, tr->get_p().y-1).get_cell() == laba4::EMPTY_CELL) {//проверка что клетка не часть ландшафта
								if (L.get_cell(tr->get_p().x, tr->get_p().y).get_object() == laba4::USER_TROOP) {//проверка  мы атакуем за отряд юзера? 
									
									if (L.get_cell(tr->get_p().x, tr->get_p().y - 1).get_object() == laba4::ENEMY_TROOP) {//проверка кого мы атакуем. Отряд?

									}
									if (L.get_cell(tr->get_p().x, tr->get_p().y - 1).get_object() == laba4::ENEMY_SUMMONER) {//проверка кого мы атакуем. Призыватель?

									}
									else {
										cout << "You cant do this! It is Friendlyfire!" << endl;
										break;
									}
								}
								else { //мы атакуем за отряд врага
									if (L.get_cell(tr->get_p().x, tr->get_p().y - 1).get_object() == laba4::USER_TROOP) {//проверка кого мы атакуем. Отряд?

									}
									if (L.get_cell(tr->get_p().x, tr->get_p().y - 1).get_object() == laba4::USER_SUMMONER) {//проверка кого мы атакуем. Призыватель?

									}
									else {
										cout << "You cant do this! It is Friendlyfire!" << endl;
										break;
									}

								}
							}
							else{
								cout << "There is no enemy objects!" << endl;
								break;
							}

						}
						else {
							cout << "End of map!" << endl;
							break;
					    }
					
					}

					if (q == 'a') {
						if ((tr->get_p().x - 1) >= 0) {//проверка на выход за карту
							if (L.get_cell(tr->get_p().x-1, tr->get_p().y ).get_cell() == laba4::EMPTY_CELL) {//проверка что клетка не часть ландшафта
								if (L.get_cell(tr->get_p().x, tr->get_p().y).get_object() == laba4::USER_TROOP) {//проверка  мы атакуем за отряд юзера? 

									if (L.get_cell(tr->get_p().x - 1, tr->get_p().y).get_object() == laba4::ENEMY_TROOP) {//проверка кого мы атакуем. Отряд?

									}
									if (L.get_cell(tr->get_p().x - 1, tr->get_p().y - 1).get_object() == laba4::ENEMY_SUMMONER) {//проверка кого мы атакуем. Призыватель?

									}
									else {
										cout << "You cant do this! It is Friendlyfire!" << endl;
										break;
									}
								}
								else { //мы атакуем за отряд врага
									if (L.get_cell(tr->get_p().x - 1, tr->get_p().y).get_object() == laba4::USER_TROOP) {//проверка кого мы атакуем. Отряд?

									}
									if (L.get_cell(tr->get_p().x - 1, tr->get_p().y).get_object() == laba4::USER_SUMMONER) {//проверка кого мы атакуем. Призыватель?

									}
									else {
										cout << "You cant do this! It is Friendlyfire!" << endl;
										break;
									}

								}
							}
							else {
								cout << "There is no enemy objects!" << endl;
								break;
							}

						}
						else {
							cout << "End of map!" << endl;
							break;
						}

					}

					if (q == 's') {
						if ((tr->get_p().y + 1) <= L.get_m() - 1) {//проверка на выход за карту
							if (L.get_cell(tr->get_p().x, tr->get_p().y + 1).get_cell() == laba4::EMPTY_CELL) {//проверка что клетка не часть ландшафта
								if (L.get_cell(tr->get_p().x, tr->get_p().y).get_object() == laba4::USER_TROOP) {//проверка  мы атакуем за отряд юзера? 

									if (L.get_cell(tr->get_p().x, tr->get_p().y + 1).get_object() == laba4::ENEMY_TROOP) {//проверка кого мы атакуем. Отряд?

									}
									if (L.get_cell(tr->get_p().x, tr->get_p().y + 1).get_object() == laba4::ENEMY_SUMMONER) {//проверка кого мы атакуем. Призыватель?

									}
									else {
										cout << "You cant do this! It is Friendlyfire!" << endl;
										break;
									}
								}
								else { //мы атакуем за отряд врага
									if (L.get_cell(tr->get_p().x, tr->get_p().y + 1).get_object() == laba4::USER_TROOP) {//проверка кого мы атакуем. Отряд?

									}
									if (L.get_cell(tr->get_p().x, tr->get_p().y + 1).get_object() == laba4::USER_SUMMONER) {//проверка кого мы атакуем. Призыватель?

									}
									else {
										cout << "You cant do this! It is Friendlyfire!" << endl;
										break;
									}

								}
							}
							else {
								cout << "There is no enemy objects!" << endl;
								break;
							}

						}
						else {
							cout << "End of map!" << endl;
							break;
						}

					}

					if (q == 'a') {
						if ((tr->get_p().x + 1) <= L.get_n() -1) {//проверка на выход за карту
							if (L.get_cell(tr->get_p().x + 1, tr->get_p().y).get_cell() == laba4::EMPTY_CELL) {//проверка что клетка не часть ландшафта
								if (L.get_cell(tr->get_p().x, tr->get_p().y).get_object() == laba4::USER_TROOP) {//проверка  мы атакуем за отряд юзера? 

									if (L.get_cell(tr->get_p().x + 1, tr->get_p().y).get_object() == laba4::ENEMY_TROOP) {//проверка кого мы атакуем. Отряд?

									}
									if (L.get_cell(tr->get_p().x + 1, tr->get_p().y ).get_object() == laba4::ENEMY_SUMMONER) {//проверка кого мы атакуем. Призыватель?

									}
									else {
										cout << "You cant do this! It is Friendlyfire!" << endl;
										break;
									}
								}
								else { //мы атакуем за отряд врага
									if (L.get_cell(tr->get_p().x + 1, tr->get_p().y).get_object() == laba4::USER_TROOP) {//проверка кого мы атакуем. Отряд?

									}
									if (L.get_cell(tr->get_p().x + 1, tr->get_p().y).get_object() == laba4::USER_SUMMONER) {//проверка кого мы атакуем. Призыватель?

									}
									else {
										cout << "You cant do this! It is Friendlyfire!" << endl;
										break;
									}

								}
							}
							else {
								cout << "There is no enemy objects!" << endl;
								break;
							}

						}
						else {
							cout << "End of map!" << endl;
							break;
						}

					}
					else {
						cout << "Incorrect Data" << endl;
					}
					break;
                }

                case 'h':{
                    if ((typeid(*tr).name()!="IResurrecting_Troop")&&(typeid(*tr).name()!="OResurrecting_Troop")){
                        cout<<"Your troop can't do this"<<endl;
                    }
                }
                default:{
                    cout<<"incorrect choice"<<endl;
                    }
                }
        }
    

void menu_t(char d,laba4::Landscape &L) {
    laba4::Summoner S;
    switch (d) {
        case 'w': {
            int k;
            cout<<"Choose:"<<endl;
            cout<<"1.Input map"<<endl;
            cout<<"2.Genertion map"<<endl;
            do{
                cin>>k;
                if (k==1) {
                    try{
                        L.input_map();}
                    catch(exception &ex){
                        cout<<ex.what()<<endl;
                    }
                    
                }
                if (k==2){
                    int m,n,wall,emptyness;
                    cout<<"Enter size of map m*n"<<endl;
                    cout<<"m: "; cin>>m; cout<<endl;
                    cout<<"n: "; cin>>n; cout<<endl;
                    cout<<"Enter number of walls: "; cin>>wall; cout<<endl;
                    cout<<"Enter number of emptyness: "; cin>>emptyness; cout<<endl;
                    L.generation_map(m, n, wall, emptyness);
                }
                if (!(k==1)||(k==2))
                    cout<<"Your input incorrect.Input again."<<endl;
            }while ( !((k==1)||(k==2)));
            vector<pair<string, unsigned>> school;
            pair<string,unsigned> s;
            string name;
            laba4::Summoner ss;
            try{
                L.read_school();
                for (int i=0;i<5;i++){
                    s.first=L.get_School(i).get_name();
                    s.second=0;
                    school.push_back(s);
                }
                cout<<"Enter name of your Summoner: "; cin>>name;
                try{
                    L.create_summoner(ss,name, school, "C:\\txt_files3\\User_Summoner.txt");
                    L.set_user_summoner(ss);
                }
                catch(exception &x){
                    cout<<x.what()<<endl;
                }
                cout<<"Enter name of Enemy Summoner: "; cin>>name;
                try{
                    L.create_summoner(ss,name, school, "C:\\txt_files3\\Enemy_Summoners.txt");
                    L.set_enemy_summoner(ss);
                }
                catch(exception &x){
                    cout<<x.what()<<endl;
                }
            }
            catch (exception &ex){
                cout<<ex.what()<<endl;
            }
            break;
        }
        case 'q': {
            L.print_map();
            break;
        }
        case 'e': {
            L.print_summoner();
            L.print_school();
            
            break;
        }
        
        case's':{
            try{
                L.fprint_Summoner();
                L.fprint_map();
                L.fprint_school();
            }
            catch(exception &ex){
                cout<<ex.what()<<endl;
            }
            
        }
        case 'g':{
            Try_To_Be_Smart:: Priorety_Queue<laba4::Object, unsigned> queue;
            laba4::Object ob,ob1;
            ob.Summoner=L.get_ptr_user_summoner();
            ob.Troop=nullptr;
            queue.push(ob, L.get_User_Summoner().get_initiative());
            ob1.Summoner=L.get_ptr_enemy_summoner();
            ob1.Troop=nullptr;
            queue.push(ob1, L.get_Enemy_Summoner().get_initiative());
            //тут дальше работа с очередью и двумя менюшками
			cout << "incorrect choice" << endl;
		
			break;
        }
            
        default: {
            cout<<"incorrect choice"<<endl;
        }
    }
}
}
