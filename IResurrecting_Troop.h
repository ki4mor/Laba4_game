//
//  Resurrecting_Troop.h
//  laba4
//
//  Created by Полина Подчуфарова on 20/11/2019.
//  Copyright © 2019 Полина Подчуфарова. All rights reserved.
//

#ifndef IResurrecting_Troop_h
#define IResurrecting_Troop_h
#include "Immoral_Troop.h"
namespace laba4 {
    class IResurrecting_Troop:public Immoral_Troop{
    private:
        unsigned dead_creatures;
    public:
        //getters
        unsigned get_dead_creatures() const {return dead_creatures;}
        //setters
        IResurrecting_Troop& set_dead_creatures(unsigned d_cr){
            dead_creatures=d_cr;
            return *this;
        }
        //constructors
     IResurrecting_Troop():Immoral_Troop(){dead_creatures=0;}//default construction
        IResurrecting_Troop(unsigned initiative0,unsigned dead_creatures0,unsigned speed0,unsigned experience0, unsigned count0, Creature cr, School* sch,Coordinates p0):
        Immoral_Troop(initiative0,speed0,experience0,count0,cr, sch,p0){
            dead_creatures=dead_creatures0;
        }
        IResurrecting_Troop(const IResurrecting_Troop&);//copying
        IResurrecting_Troop& operator=(const IResurrecting_Troop&);
		virtual ostream& print(ostream& s) const;
       void resurrect_creatures();
    };
}

#endif /* Resurrecting_Troop_h */
