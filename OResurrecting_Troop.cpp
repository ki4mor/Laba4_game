//
//  Resurrecting_Troop.cpp
//  laba4
//
//  Created by Полина Подчуфарова on 21/11/2019.
//  Copyright © 2019 Полина Подчуфарова. All rights reserved.
//

#include <stdio.h>
#include "OResurrecting_Troop.h"
namespace   laba4{
    OResurrecting_Troop& OResurrecting_Troop:: operator=(const OResurrecting_Troop& O_Troop){
        damage=O_Troop.get_damage();
        speed=O_Troop.get_speed();
        initiative=O_Troop.get_initiative();
        protection=O_Troop.get_protection();
        experience=O_Troop.get_experience();
        count=O_Troop.get_count();
        health=O_Troop.get_health();
        creature=O_Troop.get_creature();
        p=O_Troop.get_p();
        ptr_school=O_Troop.get_ptr_school();
        return *this;
    }
    OResurrecting_Troop::OResurrecting_Troop(const OResurrecting_Troop& O_Troop)
    {
        dead_creatures=O_Troop.get_dead_creatures();
        damage=O_Troop.get_damage();
        speed=O_Troop.get_speed();
        moral=O_Troop.get_moral();
        initiative=O_Troop.get_initiative();
        protection=O_Troop.get_protection();
        experience=O_Troop.get_experience();
        count=O_Troop.get_count();
        health=O_Troop.get_health();
        creature=O_Troop.get_creature();
        p=O_Troop.get_p();
        ptr_school=O_Troop.get_ptr_school();
    }
    void OResurrecting_Troop:: resurrect_creatures(){
        if (dead_creatures > 0) {
            if (dead_creatures >= 3) {
                count += 3;
                health += creature.get_health() * 3;
                dead_creatures -= 3;
            }
            else {
                count += dead_creatures;
                health += creature.get_health() * dead_creatures;
                dead_creatures =0;
            }
			cout << "Your troop successfully resserected" << endl;
        }
		else throw runtime_error("Your troop is full");
			
    }
	ostream& OResurrecting_Troop::print(ostream& s) const {
		cout << "Speed:" << speed << endl;
		cout << "Dead creatures:" << dead_creatures << endl;
		cout << "Moral: " << moral << endl;
		cout << "initiative: " << initiative << endl;
		cout << "damage: " << damage << endl;
		cout << "protection: " << protection << endl;
		cout << "experience: " << experience << endl;
		cout << "count: " << count << endl;
		cout << "health: " << health << endl;
		cout << "Creature: " << creature.get_name() << endl;
		cout << "School: " << ptr_school->get_name();
		return s;
	}
}
