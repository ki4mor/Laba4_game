//
//  Summoner.h
//  
//
//  Created by Полина Подчуфарова on 13/11/2019.
//

#ifndef Summoner_h
#define Summoner_h
#include "Immoral_Troop.h"
#include <vector>
#include <iostream>
using namespace std;
namespace laba4{
    class Summoner  {
    private:
        string name;
        unsigned initiative;
        int  health;
        const unsigned max_health=1000;
        unsigned energy;
        const unsigned max_energy=1000;
        unsigned experience;
        unsigned accumulation_coeficient;
        vector<Immoral_Troop*> troops;
        vector<pair<string,unsigned>> knowledge;
        Coordinates p;
    public:
        //getters
       string get_name()  const  {return name;}
       unsigned get_initiative()  const { return initiative;}
       unsigned get_max_health()  const {return max_health;}
       int get_health() const {return health; }
       unsigned get_max_energy()  const  {return max_energy;}
       unsigned get_energy()  const  {return energy;}
       unsigned get_accumulation_coeficient()  const  {return accumulation_coeficient;}
       unsigned get_experience()  const  {return experience;}
        Immoral_Troop* get_troops   (unsigned k) const {return troops[k];}
        pair<string,unsigned> get_knowledge (int k) const {return knowledge[k];}
       int get_size_of_knowledge() const {return knowledge.size();}
        int get_size_of_troops() const { return troops.size();}
        Coordinates get_coordinates() const { return p;}
        //setters
        Summoner& set_name(string nm){ name=nm; return *this;}
        Summoner& set_initiative(unsigned init){if (init>=0) initiative=init; return *this; }
        Summoner& set_health(int heal){ health=heal; return *this;}
        Summoner& set_energy(unsigned energ){if ((energ >=0)&&(energ<=max_energy))  energy=energ;return *this;}
        Summoner& set_accumulation_coeficient(unsigned accum){if (accum >=0) accumulation_coeficient=accum; return *this; }
        Summoner& set_experience(unsigned exper){if (exper>=0) experience=exper; return *this;}
        Summoner& set_troops(Immoral_Troop *tp){
            troops.push_back(tp);
            return *this; }
        Summoner& set_knowledge(const pair<string,unsigned> &aPair){if (aPair.second>=0) knowledge.push_back(aPair); return *this; }
        Summoner& set_coordinates(Coordinates p0){if ((p.x>=0)&&(p.y>=0)) p.x=p0.x;p.y=p0.y; return *this;}
        //constructors
        Summoner():initiative(0), health(0),energy(0), experience(0), accumulation_coeficient(0),name(""),p(0,0){};
        Summoner(string,
                 unsigned ,
                 unsigned ,
                 unsigned ,
                 unsigned ,
                 unsigned,
                 vector<Immoral_Troop*>,
                 vector<pair<string,unsigned>> ,
                 Coordinates p0);
        Summoner(const Summoner &);//copying constructor
        Summoner( Summoner &&);//moving constructor
        ~Summoner(){
            troops.clear();
            knowledge.clear();
        }
        
        //methods
        friend ostream& operator <<(ostream&,const Summoner&);
        Summoner & operator =(const Summoner&);
        void accumulate_energy();
        void upschool(string str, int exp);
        void take_damage( Immoral_Troop& enemy);
        void summon(Immoral_Troop *);
        //void change_initiative();
        ofstream & fsave(std::ofstream & s) const;
    };
}


#endif /* Summoner_h */
