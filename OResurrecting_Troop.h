//
//  Resurrecting_Troop.h
//  laba4
//
//  Created by Полина Подчуфарова on 20/11/2019.
//  Copyright © 2019 Полина Подчуфарова. All rights reserved.
//

#ifndef OResurrecting_Troop_h
#define OResurrecting_Troop_h
#include "Ordinary_Troop.h"
namespace laba4 {
    class OResurrecting_Troop:public Ordinary_Troop{
    private:
        unsigned dead_creatures;
    public:
        //getters
        unsigned get_dead_creatures()const {return dead_creatures;}
        //setters
        OResurrecting_Troop& set_dead_creatures(unsigned d_cr){
            dead_creatures=d_cr;
            return *this;
        }
        //constructors
     OResurrecting_Troop():Ordinary_Troop(){dead_creatures=0;}//default construction
        OResurrecting_Troop(unsigned initiative0,unsigned dead_creatures0,unsigned moral,unsigned speed0,unsigned experience0, unsigned count0, Creature cr, School* sch,Coordinates p0):
        Ordinary_Troop(initiative0 ,moral,speed0,experience0, count0,cr, sch, p0){
            dead_creatures=dead_creatures0;
        }
        OResurrecting_Troop(const OResurrecting_Troop&);//copying
        //methods
        OResurrecting_Troop& operator=(const OResurrecting_Troop&);
		virtual ostream& print(ostream& s) const;
       void resurrect_creatures();
    };
}

#endif /* Resurrecting_Troop_h */
