//
//  Skill.cpp
//  laba4
//
//  Created by Полина Подчуфарова on 21/11/2019.
//  Copyright © 2019 Полина Подчуфарова. All rights reserved.
//

#include <stdio.h>
#include "Skill.h"
namespace laba4{
    Skill:: Skill(const Skill& sk){
        name=sk.get_name();
        energy=sk.get_energy();
        min_knowledge=sk.get_min_knowledge();
        coefficient=sk.get_coefficient();
        creature=sk.get_creature();
    }
    Skill:: Skill (Skill &&sk){
        Creature creature0;
        name=sk.get_name();
        energy=sk.get_energy();
        min_knowledge=sk.get_min_knowledge();
        coefficient=sk.get_coefficient();
        creature=sk.get_creature();
        sk.set_coefficient(0);
        sk.set_min_knowledge(0);
        sk.set_name("");
        sk.set_energy(0);
        sk.set_creature(creature0);
    }
    ostream& operator <<(ostream& s, const Skill &sk){
        cout<<"Skill name: "<<sk.name<<endl;
        cout<<"Skill energy: "<<sk.energy<<endl;
        cout<<"Skill min knowledge: "<<sk.min_knowledge<<endl;
        cout<<"Skill coefficient; "<<sk.coefficient<<endl;
        cout<<"Skill creature: "<<sk.creature<<endl;
        return s;
    }
    Skill& Skill:: operator=(const Skill &sk){
        name=sk.get_name();
        energy=sk.get_energy();
        min_knowledge=sk.get_min_knowledge();
        coefficient=sk.get_coefficient();
        creature=sk.get_creature();
        return *this;
    }
}
