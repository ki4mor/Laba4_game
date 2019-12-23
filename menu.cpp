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


int get_int(int& a) {
	int r = 0;
	do {
		std::cin >> a;
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

//system("pause");
//system("cls");
    
char  dialog() {
	system("cls");
    cout<<"====Choose a task====="<<endl;
    cout<<"w- game loading"<<endl;//+
  //  cout<<"c-current game loading"<<endl;
    cout<<"q - output map"<<endl;//+
    cout<<"e - output school tab "<<endl;//
    cout<<"g - start game"<<endl;
 //   cout<<"s-save current state of the game"<<endl;//+
    char  d ;
    get_char(d);
    return d;
}
    char dialog_s(){
		
        cout<<"====Choose a task====="<<endl;
        cout<<"c - summon menu"<<endl;
        cout<<"o - unpgrade school"<<endl;
        cout<<"r - accumulate energy"<<endl;//+
        char  d ;
        get_char(d);
        return d;
    }
    
    void menu_s(char d,laba4::Summoner& S,laba4:: Landscape& L){
		switch (d) {
			case 'c': {//summon menu
			char d2;
			int fl = 1;
			laba4::School* sch = nullptr;
			laba4::Skill sk;
			laba4::Immoral_Troop* tr = nullptr;
			laba4::Coordinates p(0, 0);
			while (fl) {
				cout << "From what school do you want summon?" << endl;
				cout << "1.necromancy" << endl;
				cout << "2.animalism" << endl;
				cout << "3.demonology" << endl;
				cout << "4.other_realities" << endl;
				cout << "5.elementalis" << endl;
				menu::get_char(d2);
				switch (d2) {

				case '1': {
					sch = L.find_school("necromancy");
					fl = 0;
					break;
				}
				case '2': {
					sch = L.find_school("animalism");
					fl = 0;
					break;
				}
				case '3': {
					sch = L.find_school("demonology");
					fl = 0;
					break;
				}
				case '4': {
					sch = L.find_school("other_realities");
					fl = 0;
					break;
				}
				case '5': {
					sch = L.find_school("elemantalis");
					fl = 0;
					break;
				}

				default: {
					fl = 1;

					cout << "Incorrect choise, try again" << endl;
					system("pause");
					system("cls");

				}
				}
			}
			try {
				fl = 1;
				L.choose_skill(sch, sk, S);

			}
			catch (exception & ex) {
				cout << ex.what() << endl;
			}

			while (fl) {
				cout << "What troop do you want summon?" << endl;
				cout << "1.Immoral Troop" << endl;
				cout << "2.Ordinary Troop" << endl;
				cout << "3.Ressurecting Ordinary Troop" << endl;
				cout << "4.Ressurecting Immoral Troop" << endl;
				char d1;

				menu::get_char(d1);
				switch (d1) {
				case '1': {
					fl = 0;
					tr = new laba4::Immoral_Troop(4, 10, 0, 10, sk.get_creature(), sch, p);
					break;
				}
				case '2': {
					fl = 0;
					tr = new laba4::Ordinary_Troop(4, 10, 10, 0, 10, sk.get_creature(), sch, p);
					break;

				}
				case '3': {
					fl = 0;
					tr = new laba4::OResurrecting_Troop(4, 0, 10, 10, 0, 10, sk.get_creature(), sch, p);
					break;
				}
				case '4': {
					fl = 0;
					tr = new laba4::IResurrecting_Troop(4, 0, 10, 0, 10, sk.get_creature(), sch, p);
					//laba4::IResurrecting_Troop *ptr= dynamic_cast<laba4::IResurrecting_Troop*>(tr);//преобразование типа просто проверяла работает
					// cout<< ptr->get_dead_creatures()<<endl;
					break;
				}
				default: {
					fl = 1;

					cout << "Incorrect choise, try again" << endl;
					system("pause");
					system("cls");

				}
				}
			}
			if (S.get_energy() >= tr->get_count() * sk.get_energy()) {
				S.summon(tr);
				S.set_energy(S.get_energy() - tr->get_count() * sk.get_energy());
			}
			else
				cout << "You dont have so much energy" << endl;
			break;
			}
		case 'o': {
			int exp;
			char d3;
			int fl = 1;
			
				
				while (fl) {
					std::cout << "Your experience:" << S.get_experience() << std::endl;
					std::cout << "Enter count of experience:" << std::endl;

					menu::get_int(exp);
					if (exp >= 0)
						fl = 0;
					else {
						cout << "Incorrect count, try again" << endl;
						system("pause");
						system("cls");
					}
				}
				fl = 1;
				string a;
				while (fl) {
					std::cout << "Choose school:" << std::endl;
					std::cout << "1 - animalism " << std::endl;
					std::cout << "2 - demonology" << std::endl;
					std::cout << "3 - elementalism" << std::endl;
					std::cout << "4 - necromancy" << std::endl;
					std::cout << "5 - other_realities" << std::endl;
					menu::get_char(d3);//check
					switch (d3)
					{

					case '1': {
						fl = 0;
						a = "animalism";
						break;
					}
					case '2': {
						fl = 0;
						a = "demonology";
						break;
					}
					case '3': {
						fl = 0;
						a = "elementalism";
						break;
					}
					case '4': {
						fl = 0;
						a = "necromancy";
						break;
					}
					case '5': {
						fl = 0;
						a = "other_realities";
						break;
					}
					default: {
						cout << "Incorrect choise, try again" << endl;
						system("pause");
						system("cls");

					}
					}
				}
				try {
					L.school_upgrade(S, a, exp);
			}

			catch (std::exception & ex)
				{
				cout << ex.what() << endl;
			}
			
				break;
			}

			case 'r': {
				try {
				L.energy_accumulation(S);
				}
				catch (exception & ex) {
					cout << ex.what() << endl;
				}
				
				break;
			}

			default: {
			cout << "incorrect choice" << endl;

			}
		}
		system("pause");
		system("cls");
	}
    char dialog_troop(){
		
        cout<<"g - move menu"<<endl;
        cout<<"a - attack the point"<<endl;
        cout<<"h - ressurect your troop"<<endl;
        cout<<"z - exit"<<endl;
        char d;
        get_char(d);
        return d;
    }
    void menu_troop(char d,laba4::Landscape &L,laba4::Immoral_Troop *tr){
        int speed=tr->get_speed();
		
        while (speed >0){
			system("cls");
			cout << *tr << endl;
            L.print_map();
             cout<<"You can do "<<speed<<" steps"<<endl;
           d=dialog_troop();
    
        switch (d) {
            case 'z':{
				speed = 0;
                break;
            }
                
            case 'g':{//move menu
                        char  q;
                        string k;
                        std::cout << "Enter w, a, s, d to move your troop in the appropriate direction: " << std::endl;
                        get_char(q);
                        try {
                            
                            if ((q == 'w') || (q == 'a') || (q == 's') || (q == 'd')) {
                                if (L.move_troop(q, tr))
                                    speed--;
                            }
                            else
                                std::cout << "Wrong letter! " << std::endl;
                        }
                        catch (exception & x) {
                            cout << x.what() << endl;
                        }
						system("pause");
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
                        if (L.get_cell(tr->get_p().y-1,tr->get_p().x).get_cell() == laba4::EMPTY_CELL) {//проверка что клетка не часть ландшафта
                            if (L.get_cell(tr->get_p().y,tr->get_p().x).get_object() == laba4::USER_TROOP) {//проверка  мы атакуем за отряд юзера?
                                
                                if (L.get_cell( tr->get_p().y - 1,tr->get_p().x).get_object() == laba4::ENEMY_TROOP) {//проверка кого мы атакуем. Отряд?
                                    int k = 0;
                                    for (k; k < L.get_Enemy_Summoner().get_size_of_troops(); k++) {
                                        if ((L.get_Enemy_Summoner().get_troops(k)->get_p().x == tr->get_p().x) && (L.get_Enemy_Summoner().get_troops(k)->get_p().y == tr->get_p().y - 1))
                                            break;
                                    }
                                    L.get_Enemy_Summoner().get_troops(k)->take_damage(*tr); //даём пизды
                                    if ((typeid(*tr).name() == "Ordinary_Troop") || (typeid(*tr).name() == "OResurrecting_Troop")) {//если мы моральный даём пизды моралью
                                        laba4::Ordinary_Troop* ptr = dynamic_cast<laba4::Ordinary_Troop*>(tr);
                                        L.get_Enemy_Summoner().get_troops(k)->set_health(L.get_Enemy_Summoner().get_troops(k)->get_health() - ptr->get_moral());
                                    }
                                    if ((typeid(L.get_Enemy_Summoner().get_troops(k)).name() == "Ordinary_Troop") || (typeid(L.get_Enemy_Summoner().get_troops(k)).name() == "OResurrecting_Troop")) {
                                        laba4::Ordinary_Troop* ptr1 = dynamic_cast<laba4::Ordinary_Troop*>(L.get_Enemy_Summoner().get_troops(k));//если он моральный даём ему пизды его моралью
                                        L.get_Enemy_Summoner().get_troops(k)->set_health(L.get_Enemy_Summoner().get_troops(k)->get_health() + ptr1->get_moral());
                                    }
                                    if (typeid(L.get_Enemy_Summoner().get_troops(k)).name() == "IResurrecting_Troop")  {
                                        laba4::IResurrecting_Troop* ptr2 = dynamic_cast<laba4::IResurrecting_Troop*>(L.get_Enemy_Summoner().get_troops(k));// если он воскрешаемый пишем погибших
                                        ptr2->set_dead_creatures(10 - ptr2->get_count());
                                    }
                                    if (typeid(L.get_Enemy_Summoner().get_troops(k)).name() == "OResurrecting_Troop") {
                                        laba4::OResurrecting_Troop* ptr3 = dynamic_cast<laba4::OResurrecting_Troop*>(L.get_Enemy_Summoner().get_troops(k));// если он воскрешаемый пишем погибших
                                        ptr3->set_dead_creatures(10 - ptr3->get_count());
                                    }
                                    if (L.get_Enemy_Summoner().get_troops(k)->get_health() == 0)
                                        L.get_User_Summoner().set_experience(10);
                                    break;
                                }
                                if (L.get_cell( tr->get_p().y - 1,tr->get_p().x).get_object() == laba4::ENEMY_SUMMONER) {//проверка кого мы атакуем. Призыватель?
                                    int damage = tr->get_damage();
                                    if ((typeid(*tr).name() == "Ordinary_Troop") || (typeid(*tr).name() == "OResurrecting_Troop")) {
                                        laba4::Ordinary_Troop* ptr = dynamic_cast<laba4::Ordinary_Troop*>(tr);
                                        damage += ptr->get_moral();
                                    }
                                    L.get_Enemy_Summoner().set_health(L.get_Enemy_Summoner().get_health() - damage);
                                    break;
                                }
                                else {
                                    cout << "You cant do this! It is Friendlyfire!" << endl;
                                    break;
                                }
                            }
                            else { //мы атакуем за отряд врага
                                if (L.get_cell( tr->get_p().y - 1,tr->get_p().x).get_object() == laba4::USER_TROOP) {//проверка кого мы атакуем. Отряд?
                                    int k = 0;
                                    for (k; k < L.get_User_Summoner().get_size_of_troops(); k++) {
                                        if ((L.get_User_Summoner().get_troops(k)->get_p().x == tr->get_p().x) && (L.get_User_Summoner().get_troops(k)->get_p().y == tr->get_p().y - 1))
                                            break;
                                    }
                                    L.get_User_Summoner().get_troops(k)->take_damage(*tr); //даём пизды
                                    speed--;
                                    if ((typeid(*tr).name() == "Ordinary_Troop") || (typeid(*tr).name() == "OResurrecting_Troop")) {//если мы моральный даём пизды моралью
                                        laba4::Ordinary_Troop* ptr = dynamic_cast<laba4::Ordinary_Troop*>(tr);
                                        L.get_User_Summoner().get_troops(k)->set_health(L.get_User_Summoner().get_troops(k)->get_health() - ptr->get_moral());
                                    }
                                    if ((typeid(L.get_User_Summoner().get_troops(k)).name() == "Ordinary_Troop") || (typeid(L.get_User_Summoner().get_troops(k)).name() == "OResurrecting_Troop")) {
                                        laba4::Ordinary_Troop* ptr1 = dynamic_cast<laba4::Ordinary_Troop*>(L.get_User_Summoner().get_troops(k));//если он моральный даём ему пизды его моралью
                                        L.get_User_Summoner().get_troops(k)->set_health(L.get_User_Summoner().get_troops(k)->get_health() + ptr1->get_moral());
                                    }
                                    if (typeid(L.get_User_Summoner().get_troops(k)).name() == "IResurrecting_Troop") {
                                        laba4::IResurrecting_Troop* ptr2 = dynamic_cast<laba4::IResurrecting_Troop*>(L.get_User_Summoner().get_troops(k));// если он воскрешаемый пишем погибших
                                        ptr2->set_dead_creatures(10 - ptr2->get_count());
                                    }
                                    if (typeid(L.get_User_Summoner().get_troops(k)).name() == "OResurrecting_Troop") {
                                        laba4::OResurrecting_Troop* ptr3 = dynamic_cast<laba4::OResurrecting_Troop*>(L.get_User_Summoner().get_troops(k));// если он воскрешаемый пишем погибших
                                        ptr3->set_dead_creatures(10 - ptr3->get_count());
                                    }
                                    if (L.get_User_Summoner().get_troops(k)->get_health() == 0)
                                        L.get_Enemy_Summoner().set_experience(10);
                                    break;
                                }
                                if (L.get_cell(tr->get_p().y - 1,tr->get_p().x).get_object() == laba4::USER_SUMMONER) {//проверка кого мы атакуем. Призыватель?
                                    int damage = tr->get_damage();
                                    if ((typeid(*tr).name() == "Ordinary_Troop") || (typeid(*tr).name() == "OResurrecting_Troop")) {
                                        laba4::Ordinary_Troop* ptr = dynamic_cast<laba4::Ordinary_Troop*>(tr);
                                        damage += ptr->get_moral();
                                    }
                                    L.get_User_Summoner().set_health(L.get_User_Summoner().get_health() - damage);
                                    speed--;
                                    break;
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
                        if (L.get_cell( tr->get_p().y,tr->get_p().x-1 ).get_cell() == laba4::EMPTY_CELL) {//проверка что клетка не часть ландшафта
                            if (L.get_cell( tr->get_p().y,tr->get_p().x).get_object() == laba4::USER_TROOP) {//проверка  мы атакуем за отряд юзера?
                                
                                if (L.get_cell(tr->get_p().y,tr->get_p().x - 1).get_object() == laba4::ENEMY_TROOP) {//проверка кого мы атакуем. Отряд?
                                    int k = 0;
                                    for (k; k < L.get_Enemy_Summoner().get_size_of_troops(); k++) {
                                        if ((L.get_Enemy_Summoner().get_troops(k)->get_p().x == tr->get_p().x - 1) && (L.get_Enemy_Summoner().get_troops(k)->get_p().y == tr->get_p().y))
                                            break;
                                    }
                                    L.get_Enemy_Summoner().get_troops(k)->take_damage(*tr); //даём пизды
                                    speed--;
                                    if ((typeid(*tr).name() == "Ordinary_Troop") || (typeid(*tr).name() == "OResurrecting_Troop")) {//если мы моральный даём пизды моралью
                                        laba4::Ordinary_Troop* ptr = dynamic_cast<laba4::Ordinary_Troop*>(tr);
                                        L.get_Enemy_Summoner().get_troops(k)->set_health(L.get_Enemy_Summoner().get_troops(k)->get_health() - ptr->get_moral());
                                    }
                                    if ((typeid(L.get_Enemy_Summoner().get_troops(k)).name() == "Ordinary_Troop") || (typeid(L.get_Enemy_Summoner().get_troops(k)).name() == "OResurrecting_Troop")) {
                                        laba4::Ordinary_Troop* ptr1 = dynamic_cast<laba4::Ordinary_Troop*>(L.get_Enemy_Summoner().get_troops(k));//если он моральный даём ему пизды его моралью
                                        L.get_Enemy_Summoner().get_troops(k)->set_health(L.get_Enemy_Summoner().get_troops(k)->get_health() + ptr1->get_moral());
                                    }
                                    if (typeid(L.get_Enemy_Summoner().get_troops(k)).name() == "IResurrecting_Troop") {
                                        laba4::IResurrecting_Troop* ptr2 = dynamic_cast<laba4::IResurrecting_Troop*>(L.get_Enemy_Summoner().get_troops(k));// если он воскрешаемый пишем погибших
                                        ptr2->set_dead_creatures(10 - ptr2->get_count());
                                    }
                                    if (typeid(L.get_Enemy_Summoner().get_troops(k)).name() == "OResurrecting_Troop") {
                                        laba4::OResurrecting_Troop* ptr3 = dynamic_cast<laba4::OResurrecting_Troop*>(L.get_Enemy_Summoner().get_troops(k));// если он воскрешаемый пишем погибших
                                        ptr3->set_dead_creatures(10 - ptr3->get_count());
                                    }
                                    if (L.get_Enemy_Summoner().get_troops(k)->get_health() == 0)
                                        L.get_User_Summoner().set_experience(10);
                                    break;
                                }
                                if (L.get_cell( tr->get_p().y - 1,tr->get_p().x - 1).get_object() == laba4::ENEMY_SUMMONER) {//проверка кого мы атакуем. Призыватель?
                                    int damage = tr->get_damage();
                                    if ((typeid(*tr).name() == "Ordinary_Troop") || (typeid(*tr).name() == "OResurrecting_Troop")) {
                                        laba4::Ordinary_Troop* ptr = dynamic_cast<laba4::Ordinary_Troop*>(tr);
                                        damage += ptr->get_moral();
                                    }
                                    L.get_Enemy_Summoner().set_health(L.get_Enemy_Summoner().get_health() - damage);
                                    speed--;
                                    break;
                                }
                                else {
                                    cout << "You cant do this! It is Friendlyfire!" << endl;
                                    break;
                                }
                            }
                            else { //мы атакуем за отряд врага
                                if (L.get_cell( tr->get_p().y,tr->get_p().x - 1).get_object() == laba4::USER_TROOP) {//проверка кого мы атакуем. Отряд?
                                    int k = 0;
                                    for (k; k < L.get_User_Summoner().get_size_of_troops(); k++) {
                                        if ((L.get_Enemy_Summoner().get_troops(k)->get_p().x == tr->get_p().x - 1) && (L.get_Enemy_Summoner().get_troops(k)->get_p().y == tr->get_p().y))
                                            break;
                                    }
                                    L.get_User_Summoner().get_troops(k)->take_damage(*tr); //даём пизды
                                    speed--;
                                    if ((typeid(*tr).name() == "Ordinary_Troop") || (typeid(*tr).name() == "OResurrecting_Troop")) {//если мы моральный даём пизды моралью
                                        laba4::Ordinary_Troop* ptr = dynamic_cast<laba4::Ordinary_Troop*>(tr);
                                        L.get_User_Summoner().get_troops(k)->set_health(L.get_User_Summoner().get_troops(k)->get_health() - ptr->get_moral());
                                    }
                                    if ((typeid(L.get_User_Summoner().get_troops(k)).name() == "Ordinary_Troop") || (typeid(L.get_User_Summoner().get_troops(k)).name() == "OResurrecting_Troop")) {
                                        laba4::Ordinary_Troop* ptr1 = dynamic_cast<laba4::Ordinary_Troop*>(L.get_User_Summoner().get_troops(k));//если он моральный даём ему пизды его моралью
                                        L.get_User_Summoner().get_troops(k)->set_health(L.get_User_Summoner().get_troops(k)->get_health() + ptr1->get_moral());
                                    }
                                    if (typeid(L.get_User_Summoner().get_troops(k)).name() == "IResurrecting_Troop") {
                                        laba4::IResurrecting_Troop* ptr2 = dynamic_cast<laba4::IResurrecting_Troop*>(L.get_User_Summoner().get_troops(k));// если он воскрешаемый пишем погибших
                                        ptr2->set_dead_creatures(10 - ptr2->get_count());
                                    }
                                    if (typeid(L.get_User_Summoner().get_troops(k)).name() == "OResurrecting_Troop") {
                                        laba4::OResurrecting_Troop* ptr3 = dynamic_cast<laba4::OResurrecting_Troop*>(L.get_User_Summoner().get_troops(k));// если он воскрешаемый пишем погибших
                                        ptr3->set_dead_creatures(10 - ptr3->get_count());
                                    }
                                    if (L.get_User_Summoner().get_troops(k)->get_health() == 0)
                                        L.get_Enemy_Summoner().set_experience(10);
                                    
                                    break;
                                    
                                }
                                if (L.get_cell( tr->get_p().y,tr->get_p().x - 1).get_object() == laba4::USER_SUMMONER) {//проверка кого мы атакуем. Призыватель?
                                    int damage = tr->get_damage();
                                    if ((typeid(*tr).name() == "Ordinary_Troop") || (typeid(*tr).name() == "OResurrecting_Troop")) {
                                        laba4::Ordinary_Troop* ptr = dynamic_cast<laba4::Ordinary_Troop*>(tr);
                                        damage += ptr->get_moral();
                                    }
                                    L.get_User_Summoner().set_health(L.get_User_Summoner().get_health() - damage);
                                    speed--;
                                    break;
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
                        if (L.get_cell(tr->get_p().y + 1,tr->get_p().x).get_cell() == laba4::EMPTY_CELL) {//проверка что клетка не часть ландшафта
                            if (L.get_cell( tr->get_p().y,tr->get_p().x).get_object() == laba4::USER_TROOP) {//проверка  мы атакуем за отряд юзера?
                                
                                if (L.get_cell(tr->get_p().y + 1,tr->get_p().x).get_object() == laba4::ENEMY_TROOP) {//проверка кого мы атакуем. Отряд?
                                    int k = 0;
                                    for (k; k < L.get_Enemy_Summoner().get_size_of_troops(); k++) {
                                        if ((L.get_Enemy_Summoner().get_troops(k)->get_p().x == tr->get_p().x) && (L.get_Enemy_Summoner().get_troops(k)->get_p().y == tr->get_p().y + 1))
                                            break;
                                    }
                                    L.get_Enemy_Summoner().get_troops(k)->take_damage(*tr); //даём пизды
                                    speed--;
                                    if ((typeid(*tr).name() == "Ordinary_Troop") || (typeid(*tr).name() == "OResurrecting_Troop")) {//если мы моральный даём пизды моралью
                                        laba4::Ordinary_Troop* ptr = dynamic_cast<laba4::Ordinary_Troop*>(tr);
                                        L.get_Enemy_Summoner().get_troops(k)->set_health(L.get_Enemy_Summoner().get_troops(k)->get_health() - ptr->get_moral());
                                    }
                                    if ((typeid(L.get_Enemy_Summoner().get_troops(k)).name() == "Ordinary_Troop") || (typeid(L.get_Enemy_Summoner().get_troops(k)).name() == "OResurrecting_Troop")) {
                                        laba4::Ordinary_Troop* ptr1 = dynamic_cast<laba4::Ordinary_Troop*>(L.get_Enemy_Summoner().get_troops(k));//если он моральный даём ему пизды его моралью
                                        L.get_Enemy_Summoner().get_troops(k)->set_health(L.get_Enemy_Summoner().get_troops(k)->get_health() + ptr1->get_moral());
                                    }
                                    if (typeid(L.get_Enemy_Summoner().get_troops(k)).name() == "IResurrecting_Troop") {
                                        laba4::IResurrecting_Troop* ptr2 = dynamic_cast<laba4::IResurrecting_Troop*>(L.get_Enemy_Summoner().get_troops(k));// если он воскрешаемый пишем погибших
                                        ptr2->set_dead_creatures(10 - ptr2->get_count());
                                    }
                                    if (typeid(L.get_Enemy_Summoner().get_troops(k)).name() == "OResurrecting_Troop") {
                                        laba4::OResurrecting_Troop* ptr3 = dynamic_cast<laba4::OResurrecting_Troop*>(L.get_Enemy_Summoner().get_troops(k));// если он воскрешаемый пишем погибших
                                        ptr3->set_dead_creatures(10 - ptr3->get_count());
                                    }
                                    if (L.get_Enemy_Summoner().get_troops(k)->get_health() == 0)
                                        L.get_User_Summoner().set_experience(10);
                                    break;
                                }
                                if (L.get_cell( tr->get_p().y + 1,tr->get_p().x).get_object() == laba4::ENEMY_SUMMONER) {//проверка кого мы атакуем. Призыватель?
                                    int damage = tr->get_damage();
                                    if ((typeid(*tr).name() == "Ordinary_Troop") || (typeid(*tr).name() == "OResurrecting_Troop")) {
                                        laba4::Ordinary_Troop* ptr = dynamic_cast<laba4::Ordinary_Troop*>(tr);
                                        damage += ptr->get_moral();
                                    }
                                    L.get_Enemy_Summoner().set_health(L.get_Enemy_Summoner().get_health() - damage);
                                    speed--;
                                    break;
                                }
                                else {
                                    cout << "You cant do this! It is Friendlyfire!" << endl;
                                    break;
                                }
                            }
                            else { //мы атакуем за отряд врага
                                if (L.get_cell( tr->get_p().y + 1,tr->get_p().x).get_object() == laba4::USER_TROOP) {//проверка кого мы атакуем. Отряд?
                                    int k = 0;
                                    for (k; k < L.get_User_Summoner().get_size_of_troops(); k++) {
                                        if ((L.get_User_Summoner().get_troops(k)->get_p().x == tr->get_p().x) && (L.get_User_Summoner().get_troops(k)->get_p().y == tr->get_p().y + 1))
                                            break;
                                    }
                                    L.get_User_Summoner().get_troops(k)->take_damage(*tr); //даём пизды
                                    speed--;
                                    if ((typeid(*tr).name() == "Ordinary_Troop") || (typeid(*tr).name() == "OResurrecting_Troop")) {//если мы моральный даём пизды моралью
                                        laba4::Ordinary_Troop* ptr = dynamic_cast<laba4::Ordinary_Troop*>(tr);
                                        L.get_User_Summoner().get_troops(k)->set_health(L.get_User_Summoner().get_troops(k)->get_health() - ptr->get_moral());
                                    }
                                    if ((typeid(L.get_User_Summoner().get_troops(k)).name() == "Ordinary_Troop") || (typeid(L.get_User_Summoner().get_troops(k)).name() == "OResurrecting_Troop")) {
                                        laba4::Ordinary_Troop* ptr1 = dynamic_cast<laba4::Ordinary_Troop*>(L.get_User_Summoner().get_troops(k));//если он моральный даём ему пизды его моралью
                                        L.get_User_Summoner().get_troops(k)->set_health(L.get_User_Summoner().get_troops(k)->get_health() + ptr1->get_moral());
                                    }
                                    if (typeid(L.get_User_Summoner().get_troops(k)).name() == "IResurrecting_Troop") {
                                        laba4::IResurrecting_Troop* ptr2 = dynamic_cast<laba4::IResurrecting_Troop*>(L.get_User_Summoner().get_troops(k));// если он воскрешаемый пишем погибших
                                        ptr2->set_dead_creatures(10 - ptr2->get_count());
                                    }
                                    if (typeid(L.get_User_Summoner().get_troops(k)).name() == "OResurrecting_Troop") {
                                        laba4::OResurrecting_Troop* ptr3 = dynamic_cast<laba4::OResurrecting_Troop*>(L.get_User_Summoner().get_troops(k));// если он воскрешаемый пишем погибших
                                        ptr3->set_dead_creatures(10 - ptr3->get_count());
                                    }
                                    if (L.get_User_Summoner().get_troops(k)->get_health() == 0)
                                        L.get_Enemy_Summoner().set_experience(10);
                                    break;
                                }
                                if (L.get_cell( tr->get_p().y + 1,tr->get_p().x).get_object() == laba4::USER_SUMMONER) {//проверка кого мы атакуем. Призыватель?
                                    int damage = tr->get_damage();
                                    if ((typeid(*tr).name() == "Ordinary_Troop") || (typeid(*tr).name() == "OResurrecting_Troop")) {
                                        laba4::Ordinary_Troop* ptr = dynamic_cast<laba4::Ordinary_Troop*>(tr);
                                        damage += ptr->get_moral();
                                    }
                                    L.get_User_Summoner().set_health(L.get_User_Summoner().get_health() - damage);
                                    speed;
                                    break;
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
                
                if (q == 'd') {
                    if ((tr->get_p().x + 1) <= L.get_n() -1) {//проверка на выход за карту
                        if (L.get_cell(tr->get_p().y,tr->get_p().x + 1).get_cell() == laba4::EMPTY_CELL) {//проверка что клетка не часть ландшафта
                            if (L.get_cell( tr->get_p().y,tr->get_p().x).get_object() == laba4::USER_TROOP) {//проверка  мы атакуем за отряд юзера?
                                
                                if (L.get_cell( tr->get_p().y,tr->get_p().x + 1).get_object() == laba4::ENEMY_TROOP) {//проверка кого мы атакуем. Отряд?
                                    int k = 0;
                                    for (k; k < L.get_Enemy_Summoner().get_size_of_troops(); k++) {
                                        if ((L.get_Enemy_Summoner().get_troops(k)->get_p().x == tr->get_p().x + 1) && (L.get_Enemy_Summoner().get_troops(k)->get_p().y == tr->get_p().y))
                                            break;
                                    }
                                    L.get_Enemy_Summoner().get_troops(k)->take_damage(*tr); //даём пизды
                                    speed--;
                                    if ((typeid(*tr).name() == "Ordinary_Troop") || (typeid(*tr).name() == "OResurrecting_Troop")) {//если мы моральный даём пизды моралью
                                        laba4::Ordinary_Troop* ptr = dynamic_cast<laba4::Ordinary_Troop*>(tr);
                                        L.get_Enemy_Summoner().get_troops(k)->set_health(L.get_Enemy_Summoner().get_troops(k)->get_health() - ptr->get_moral());
                                    }
                                    if ((typeid(L.get_Enemy_Summoner().get_troops(k)).name() == "Ordinary_Troop") || (typeid(L.get_Enemy_Summoner().get_troops(k)).name() == "OResurrecting_Troop")) {
                                        laba4::Ordinary_Troop* ptr1 = dynamic_cast<laba4::Ordinary_Troop*>(L.get_Enemy_Summoner().get_troops(k));//если он моральный даём ему пизды его моралью
                                        L.get_Enemy_Summoner().get_troops(k)->set_health(L.get_Enemy_Summoner().get_troops(k)->get_health() + ptr1->get_moral());
                                    }
                                    if (typeid(L.get_Enemy_Summoner().get_troops(k)).name() == "IResurrecting_Troop") {
                                        laba4::IResurrecting_Troop* ptr2 = dynamic_cast<laba4::IResurrecting_Troop*>(L.get_Enemy_Summoner().get_troops(k));// если он воскрешаемый пишем погибших
                                        ptr2->set_dead_creatures(10 - ptr2->get_count());
                                    }
                                    if (typeid(L.get_Enemy_Summoner().get_troops(k)).name() == "OResurrecting_Troop") {
                                        laba4::OResurrecting_Troop* ptr3 = dynamic_cast<laba4::OResurrecting_Troop*>(L.get_Enemy_Summoner().get_troops(k));// если он воскрешаемый пишем погибших
                                        ptr3->set_dead_creatures(10 - ptr3->get_count());
                                    }
                                    if (L.get_Enemy_Summoner().get_troops(k)->get_health() == 0)
                                        L.get_User_Summoner().set_experience(10);
                                    break;
                                }
                                if (L.get_cell(tr->get_p().y ,tr->get_p().x + 1).get_object() == laba4::ENEMY_SUMMONER) {//проверка кого мы атакуем. Призыватель?
                                    int damage = tr->get_damage();
                                    if ((typeid(*tr).name() == "Ordinary_Troop") || (typeid(*tr).name() == "OResurrecting_Troop")) {
                                        laba4::Ordinary_Troop* ptr = dynamic_cast<laba4::Ordinary_Troop*>(tr);
                                        damage += ptr->get_moral();
                                    }
                                    L.get_Enemy_Summoner().set_health(L.get_Enemy_Summoner().get_health() - damage);
                                    speed--;
                                    break;
                                }
                                else {
                                    cout << "You cant do this! It is Friendlyfire!" << endl;
                                    break;
                                }
                            }
                            else { //мы атакуем за отряд врага
                                if (L.get_cell(tr->get_p().y,tr->get_p().x + 1).get_object() == laba4::USER_TROOP) {//проверка кого мы атакуем. Отряд?
                                    int k = 0;
                                    for (k; k < L.get_User_Summoner().get_size_of_troops(); k++) {
                                        if ((L.get_Enemy_Summoner().get_troops(k)->get_p().x == tr->get_p().x + 1) && (L.get_Enemy_Summoner().get_troops(k)->get_p().y == tr->get_p().y))
                                            break;
                                    }
                                    L.get_User_Summoner().get_troops(k)->take_damage(*tr); //даём пизды
                                    speed--;
                                    if ((typeid(*tr).name() == "Ordinary_Troop") || (typeid(*tr).name() == "OResurrecting_Troop")) {//если мы моральный даём пизды моралью
                                        laba4::Ordinary_Troop* ptr = dynamic_cast<laba4::Ordinary_Troop*>(tr);
                                        L.get_User_Summoner().get_troops(k)->set_health(L.get_User_Summoner().get_troops(k)->get_health() - ptr->get_moral());
                                    }
                                    if ((typeid(L.get_User_Summoner().get_troops(k)).name() == "Ordinary_Troop") || (typeid(L.get_User_Summoner().get_troops(k)).name() == "OResurrecting_Troop")) {
                                        laba4::Ordinary_Troop* ptr1 = dynamic_cast<laba4::Ordinary_Troop*>(L.get_User_Summoner().get_troops(k));//если он моральный даём ему пизды его моралью
                                        L.get_User_Summoner().get_troops(k)->set_health(L.get_User_Summoner().get_troops(k)->get_health() + ptr1->get_moral());
                                    }
                                    if (typeid(L.get_User_Summoner().get_troops(k)).name() == "IResurrecting_Troop") {
                                        laba4::IResurrecting_Troop* ptr2 = dynamic_cast<laba4::IResurrecting_Troop*>(L.get_User_Summoner().get_troops(k));// если он воскрешаемый пишем погибших
                                        ptr2->set_dead_creatures(10 - ptr2->get_count());
                                    }
                                    if (typeid(L.get_User_Summoner().get_troops(k)).name() == "OResurrecting_Troop") {
                                        laba4::OResurrecting_Troop* ptr3 = dynamic_cast<laba4::OResurrecting_Troop*>(L.get_User_Summoner().get_troops(k));// если он воскрешаемый пишем погибших
                                        ptr3->set_dead_creatures(10 - ptr3->get_count());
                                    }
                                    if (L.get_User_Summoner().get_troops(k)->get_health() == 0)
                                        L.get_Enemy_Summoner().set_experience(10);
                                    break;
                                }
                                if (L.get_cell(tr->get_p().y,tr->get_p().x + 1).get_object() == laba4::USER_SUMMONER) {//проверка кого мы атакуем. Призыватель?
                                    int damage = tr->get_damage();
                                    if ((typeid(*tr).name() == "Ordinary_Troop") || (typeid(*tr).name() == "OResurrecting_Troop")) {
                                        laba4::Ordinary_Troop* ptr = dynamic_cast<laba4::Ordinary_Troop*>(tr);
                                        damage += ptr->get_moral();
                                    }
                                    L.get_User_Summoner().set_health(L.get_User_Summoner().get_health() - damage);
                                    speed--;
                                    break;
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
                else {
                    if (typeid(*tr).name() != "IResurrecting_Troop") {
                        laba4::IResurrecting_Troop* ptr = dynamic_cast<laba4::IResurrecting_Troop*>(tr);
                        try {ptr->resurrect_creatures();}
                        catch (exception & x) {
                            cout << x.what() << endl;
                        }
                        speed--;
                    }
                    if (typeid(*tr).name() != "OResurrecting_Troop") {
                        laba4::OResurrecting_Troop* ptr = dynamic_cast<laba4::OResurrecting_Troop*>(tr);
                        try { ptr->resurrect_creatures(); }
                        catch (exception & x) {
                            cout << x.what() << endl;
                        }
                        speed--;
                    }
                }
				system("pause");
                break;
            }
            default:{
                cout<<"incorrect choice"<<endl;
				system("pause");
				system("cls");
            }
				
        }
		system("pause");
        }
		system("pause");
		system("cls");
    }
    

    

void menu_t(char d,laba4::Landscape &L) {
    switch (d) {
        /*case 'c':{
            L.input_map("input_map_save");
           // L.input_summoner("");
        }*/
        case 'w': {
            int k;
			system("cls");
            cout<<"Choose:"<<endl;
            cout<<"1 - Input map"<<endl;
            cout<<"2 - Genertion map"<<endl;
            do{
                menu::get_int(k);
                if (k==1) {
                    try{
                        L.input_map("input_map");
                         L.print_map();
						 system("pause");
						 system("cls");
                    }
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
          
            try{
                  laba4::Summoner ss;
                L.read_school();
                for (int i=0;i<5;i++){
                    s.first=L.get_School(i).get_name();
                    s.second=0;
                    school.push_back(s);
                }
				
				system("cls");
                cout<<"Enter name of your Summoner: "; cin>>name;
                try{
                    laba4::Summoner ss;
                    L.create_summoner(ss,name, school, "C:\\txt_files3\\User_Summoner.txt");
                    L.set_user_summoner(ss);
                    laba4:: Cell c0;
                    c0.set_object(laba4::USER_SUMMONER);
                    c0.set_cell(laba4::EMPTY_CELL);
                    L.set_rectangle(L.get_User_Summoner().get_coordinates(), c0);
                   
                }
                catch(exception &x){
                    cout<<x.what()<<endl;
                }
				
				system("cls");
                cout<<"Enter name of Enemy Summoner: "; cin>>name;
                try{
                    laba4::Summoner ss;
                    L.create_summoner(ss,name, school, "C:\\txt_files3\\Enemy_Summoners.txt");
                    L.set_enemy_summoner(ss);
                    laba4:: Cell c0;
                    c0.set_object(laba4::ENEMY_SUMMONER);
                    c0.set_cell(laba4::EMPTY_CELL);
                    L.set_rectangle(L.get_Enemy_Summoner().get_coordinates(), c0);
                   
                }
                catch(exception &x){
                    cout<<x.what()<<endl;
                }
            }
            catch (exception &ex){
                cout<<ex.what()<<endl;
            }
			system("cls");
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
        
       /* case's':{
            try{
                L.fprint_Summoner();
                L.fprint_map();
                L.fprint_school();
            }
            catch(exception &ex){
                cout<<ex.what()<<endl;
            }
            break;
        }*/
        case 'g':{
			system("cls");
            Try_To_Be_Smart:: Priorety_Queue<laba4::Object, unsigned> queue;
            laba4::Object ob,ob1;
            ob.Summoner=L.get_ptr_user_summoner();
            ob.Troop=nullptr;
            queue.push(ob, L.get_User_Summoner().get_initiative());
            ob1.Summoner=L.get_ptr_enemy_summoner();
            ob1.Troop=nullptr;
            queue.push(ob1, L.get_Enemy_Summoner().get_initiative());
            while ((L.get_User_Summoner().get_health()!=0)||(L.get_Enemy_Summoner().get_health()!=0)){
                L.print_summoner();
                if (queue.top().Troop==nullptr) {
                    queue.show();
                        char d = dialog_s();
                     int k1=queue.top().Summoner->get_size_of_troops();
                        menu_s(d,*queue.top().Summoner,L);
                    int k2=queue.top().Summoner->get_size_of_troops();
                    laba4::Object ob =queue.top();
                     queue.pop();
                    queue.push(ob,ob.Summoner->get_initiative());
                   
                    if (k2>k1){
                    laba4::Object ob1;
                        L.install_troop_in_cell(ob.Summoner);
                    ob1.Troop=ob.Summoner->get_troops(k2-1);
                    ob1.Summoner=ob.Summoner;
                    queue.push(ob1, ob1.Troop->get_initiative());
                    }
                }
                if (queue.top().Troop!=nullptr) {
                    queue.show();
                    menu_troop(d, L, queue.top().Troop);
                    laba4::Object ob4 =queue.top();
                    queue.pop();
                    queue.push(ob4,ob4.Troop->get_initiative());
                }
                L.print_map();
            }
            break;
        }
            
        default: {
            cout<<"incorrect choice"<<endl;
        }
    }
}
}
