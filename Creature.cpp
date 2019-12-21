//
//  Creature.cpp
//  laba4
//
//  Created by Полина Подчуфарова on 21/11/2019.
//  Copyright © 2019 Полина Подчуфарова. All rights reserved.
//

#include "Creature.h"
namespace laba4{
    Creature:: Creature(string name0, unsigned damage0,unsigned protection0, unsigned health0 ) {
        name=name0;
        damage=damage0;
        protection=protection0;
        health=health0;
    }
    Creature::Creature(const Creature &cr){//copying construction
        name=cr.get_name();
        damage=cr.get_damage();
        protection=cr.get_protection();
        health=cr.get_health();
    }
   Creature:: Creature(Creature &&cr):name(cr.get_name()),damage(cr.get_damage()),protection(get_protection()),health(cr.get_health()){
        cr.set_name("");
        cr.set_damage(0);
        cr.set_health(0);
        cr.set_protection(0);
    }
    Creature& Creature:: operator=(const Creature &cr){
        name=cr.get_name();
        damage=cr.get_damage();
        protection=cr.get_protection();
        health=cr.get_health();
        return *this;
    }
    ostream& operator <<(ostream& s,const Creature& cr){
        cout<<"Creature Name: "<<cr.name<<endl;
        cout<<"Creature Health: "<<cr.health<<endl;
        cout<<"Creature Damage: "<<cr.damage<<endl;
        cout<<"Creature Protection: "<<cr.protection<<endl;
        return s;
    }
    
}
