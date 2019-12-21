//
//  Troop.h
//  
//
//  Created by Полина Подчуфарова on 16/11/2019.
//

#ifndef Immoral_Troop_h
#define Immoral_Troop_h
#include "School.h"
using namespace std;
namespace laba4{
    struct Coordinates{
        int x;
        int y;
        Coordinates(int x0,int y0): x(x0),y(y0){}
        Coordinates(){}
    };
  class Immoral_Troop{
    protected:
        unsigned speed;
        unsigned initiative;
        unsigned damage;
        unsigned protection;
        unsigned experience;
        unsigned count;
        unsigned health;
        Creature creature;
        School *ptr_school;
        Coordinates p;
      
    public:
        //getters
     // virtual unsigned get_moral() const =0;
        unsigned get_speed() const {    return speed;}
       unsigned get_initiative()const {    return initiative;}
        unsigned get_damage() const{ return damage; }
        unsigned get_protection() const{ return protection; }
        unsigned get_experience() const{ return experience; }
        unsigned get_count() const { return count; }
        unsigned get_health() const {return health;}
       Coordinates get_p() const {return p;}
        Creature get_creature()const { return creature; }
        School* get_ptr_school()const { return ptr_school; }
      //virtual  unsigned get_dead_creatures() const =0;

        //setters
        Immoral_Troop& set_speed(unsigned a) {  if (a>=0) speed=a; return *this; }
        Immoral_Troop& set_initiative(unsigned a) {  if (a>=0) initiative = a; return *this; }
        Immoral_Troop& set_damage(unsigned a) {  if (a>=0) damage = a; return *this; }
        Immoral_Troop& set_protection(unsigned a) {  if (a>=0) protection = a; return *this; }
        Immoral_Troop& set_experience(unsigned a) { if (a>=0) experience = a; return *this; }
        Immoral_Troop& set_count(unsigned a) {  if (a>=0) count = a; return *this; }
        Immoral_Troop& set_health(unsigned a){if (a>=0) health=a; return *this; }
       Immoral_Troop& set_p(Coordinates p0){if ((p0.x>=0)&&(p0.y>=0)) p=p0; return *this;}//границы
        Immoral_Troop& set_creature(Creature a) {creature=a; return *this;}
        Immoral_Troop& set_ptr_school(School* a){ptr_school=a; return *this;}
        //constructors
      Immoral_Troop():speed(0),initiative(0),damage(0),protection(0),experience(0),count(0),health(0), ptr_school(nullptr),p(0,0){
      }
      Immoral_Troop(unsigned , unsigned speed0,unsigned experience0, unsigned count0, Creature cr, School* sch,Coordinates p0);
      Immoral_Troop(const Immoral_Troop&);//copying
      Immoral_Troop(Immoral_Troop&&);//moving
      virtual ~Immoral_Troop(){}
        //methods
       virtual Immoral_Troop& operator =(const Immoral_Troop&);
	   virtual ostream& print(ostream& s) const;
	   friend ostream& operator <<(ostream& s, const Immoral_Troop&);
        virtual void attack(Immoral_Troop&);
        virtual void take_damage(Immoral_Troop&);
      virtual void move_troop(/*const char ch,int,int*/);

    };
}


#endif /* Troop_h */
