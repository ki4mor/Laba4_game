//
//  Landsccape.h
//  laba4
//
//  Created by Полина Подчуфарова on 19/11/2019.
//  Copyright © 2019 Полина Подчуфарова. All rights reserved.
//

#ifndef Landscape_h
#define Landscape_h
#include <string>
#include "Summoner.h"
#include "School.h"
#include <vector>
#include "Priorety_Queue.h"

using namespace std;

namespace laba4 {

    enum cell0 {POINT,EMPTYNESS,WALL,EMPTY_CELL};
    enum object0 {USER_SUMMONER,ENEMY_SUMMONER,USER_TROOP,ENEMY_TROOP,EMPTY_OBJECT};
    class Cell {
    private:
        cell0 cell;
        object0 object;
    public:
        //getters
        cell0 get_cell(){return cell;}
        object0 get_object(){return object;}
        //construction
        Cell(){cell=EMPTY_CELL; object=EMPTY_OBJECT;}
        Cell(char);
        //setters
        Cell& set_cell(cell0 c) {cell=c; return *this;}
        Cell& set_object(object0 o) {object=o; return *this;}
        
        friend ostream&  operator << (ostream& s, const Cell &a){
            if (a.cell==POINT)  cout<<'.';
            if (a.cell==WALL)  cout<<'#';
            if (a.cell==EMPTYNESS) cout<<' ';
            if (a.object==USER_SUMMONER)  cout<<'@';
            if (a.object==ENEMY_SUMMONER)  cout<<'*';
            if (a.object==USER_TROOP)  cout<<'U';
            if (a.object==ENEMY_TROOP)  cout<<'E';
            return s;
        }
        
    };
    class Object{
    public:
        Summoner* Summoner;
        Immoral_Troop* Troop;
    };
   
    class Landscape {
    private:
        int m;
        int n;
       vector <School> tab_schools;
        Summoner User_Summoner;
        Summoner Enemy_Summoner;
       vector<vector <Cell>> rectangle;
    public:
       
        Landscape():m(0),n(0) {
            Summoner User_Summoner;
            Summoner Enemy_Summoner;
        } //default constructions
        Landscape(Summoner User, Summoner Enemy);//construction
        Landscape(const Landscape&);
        ~Landscape(){
            tab_schools.clear();
            rectangle.clear();
            m=0;
            n=0;
        }
        //getters
        int get_n() const { return n; }
        int get_m() const { return m; }
        Summoner get_User_Summoner() const {return User_Summoner;}
        Summoner get_Enemy_Summoner() const {return Enemy_Summoner;}
        Cell get_cell(int i,int j) const {return rectangle[i][j];}
        School get_School(int i) const { return tab_schools[i];}
        vector<School> get_all_school() const {return tab_schools;}
        vector<vector <Cell>> get_rectangle() const {return rectangle;}
        Summoner * get_ptr_user_summoner()  {return &User_Summoner;}
         Summoner * get_ptr_enemy_summoner() {return &Enemy_Summoner;}
        
        //setters
        Landscape& set_n(int n0) {if (n0>=0) n=n0; return *this; }
        Landscape& set_m(int m0) {if (m0>=0)m=m0; return *this; }
        Landscape& set_user_summoner(Summoner s){User_Summoner=s; return *this;}
        Landscape& set_enemy_summoner(Summoner s){Enemy_Summoner=s; return *this;}
        Landscape& set_tab_school(School sc){ tab_schools.push_back(sc); return *this;}
         //functions
        friend ostream& operator <<(ostream& s, const  Landscape &a);
        void generation_map(int,int,int,int);
        void input_map();
        void create_summoner(Summoner&, string,vector<pair<string,unsigned>>&,const string);
        void read_school();
        void read_skill(School&);
        School* find_school(string);
        void install_troop_in_cell();
         void push_queue(Summoner* s,Immoral_Troop* tr, Try_To_Be_Smart::Priorety_Queue<Object,unsigned>& qq);
        Object& move_queue(Try_To_Be_Smart::Priorety_Queue<Object,unsigned>& qq);
        void print_map();
        int move_troop(char ch,Immoral_Troop*);
        void print_summoner();
        void print_school();
        void fprint_school();
        void fprint_skill(School&);
        void fprint_map();
        void fprint_Summoner();
        void school_upgrade(Summoner&,string,int);
        void energy_accumulation(Summoner &);
        void choose_skill(School*,Skill &sk,Summoner &);
       
    };
}
#endif /* Landsccape_h */
