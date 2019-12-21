//
//  Ordinary_Troop.cpp
//  laba4
//
//  Created by Полина Подчуфарова on 21/11/2019.
//  Copyright © 2019 Полина Подчуфарова. All rights reserved.
//

#include <stdio.h>
#include "Ordinary_Troop.h"
namespace   laba4{
    Ordinary_Troop:: Ordinary_Troop(const Ordinary_Troop& O_Troop){
        moral=O_Troop.get_moral();
        damage=O_Troop.Immoral_Troop::get_damage();
        speed=O_Troop.get_speed();
        initiative=O_Troop.get_initiative();
        protection=O_Troop.get_protection();
        experience=O_Troop.get_experience();
        count=O_Troop.get_count();
        health=O_Troop.get_health();
        creature=O_Troop.get_creature();
        p=O_Troop.get_p();
        ptr_school=O_Troop.get_ptr_school();
    }
    Ordinary_Troop& Ordinary_Troop:: operator=(const Ordinary_Troop& O_Troop){
        moral=O_Troop.get_moral();
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
    
    void Ordinary_Troop:: upmoral() {
        moral+=5;
    }
    void Ordinary_Troop:: balance_moral(){
        if (moral>0) moral--;
        if (moral<0) moral++;
    }
    void Ordinary_Troop:: attack(Ordinary_Troop& tr){
        int attack=0;
        if (ptr_school->get_name()==tr.get_ptr_school()->get_school_dominant()) attack+=5;
        if (ptr_school->get_school_dominant()==tr.get_ptr_school()->get_name()) attack-=5;
        attack+=tr.get_health()+tr.get_protection()-damage+moral;
        if (attack<0) attack=0;
        if (attack==0) upmoral();
        tr.set_health(attack);
    }
    void Ordinary_Troop::  take_damage(Ordinary_Troop& tr){
        int count0=count;
        int taking_damage=0;
        if (ptr_school->get_name()==tr.get_ptr_school()->get_school_dominant()) taking_damage+=5;
        if (ptr_school->get_school_dominant()==tr.get_ptr_school()->get_name()) taking_damage-=5;
        taking_damage=health+protection-tr.get_damage()+moral;
        if (health>=taking_damage){
            health=taking_damage;
            if (creature.get_health()!=1)
                ((health%2==0))? count=health/creature.get_health(): count=health/creature.get_health()+1;//уменьшение кол-во
            else count=health/creature.get_health();
        }
        if (count0>count){moral--;}
    }
    void Ordinary_Troop:: move_troop(/*const char ch,int m,int n*/){
        /*if (ch=='W') ((p.y+1)<m-1) ? p.y++: p.y=m-1;
        if (ch=='D') ((p.x+1)<n-1) ? p.x++: p.x=n-1;
        if (ch=='S') ((p.y-1)>0) ? p.y--: p.y=0;
        if (ch=='A') ((p.x-1)>0) ? p.x--:p.x=0;*/
        balance_moral();
    }
	ostream& Ordinary_Troop::print(ostream& s) const {
		cout << "Speed:" << speed << endl;
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
