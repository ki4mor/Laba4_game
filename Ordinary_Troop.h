//
//  Ordinary_Troop.h
//  laba4
//
//  Created by Полина Подчуфарова on 20/11/2019.
//  Copyright © 2019 Полина Подчуфарова. All rights reserved.
//

#ifndef Ordinary_Troop_h
#define Ordinary_Troop_h
#include "Immoral_Troop.h"
namespace laba4 {
class Ordinary_Troop : public Immoral_Troop{
protected:
    int moral;
public:
    //constructors
    Ordinary_Troop():Immoral_Troop(){moral=0;}//default
    Ordinary_Troop(unsigned initiative0,int moral0,unsigned speed0,unsigned experience0, unsigned count0, Creature cr, School* sch,Coordinates p0):
    Immoral_Troop(initiative0, speed0,experience0,count0,cr,sch,p0){
        moral=moral0;
    }
    Ordinary_Troop(const Ordinary_Troop& O_Troop);
   
    //setters
    Ordinary_Troop& set_moral(int a) { if (a>=0) moral = a; return *this; }
    //getters
    virtual unsigned get_moral() const {return moral;};
    //methods
    Ordinary_Troop& operator=(const Ordinary_Troop& O_Troop);
    void upmoral();
    void balance_moral();
    void attack(Ordinary_Troop&);
    void take_damage(Ordinary_Troop&);
   void move_troop(/*const char ch,int,int*/);
   virtual ostream& print(ostream& s) const;
};
}
#endif /* Ordinary_Troop_h */
