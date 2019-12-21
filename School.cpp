//
//  School.cpp
//  laba4
//
//  Created by Полина Подчуфарова on 21/11/2019.
//  Copyright © 2019 Полина Подчуфарова. All rights reserved.
//

#include <stdio.h>
#include "School.h"
namespace laba4{
    School:: School(const School& sch){
        name=sch.get_name();
        school_dominant=sch.get_school_dominant();
        number_creatures=sch.get_number_creatures();
        for (int i=0;i<sch.get_size_of_data();i++)
            data.push_back(sch.get_data(i));
    }
    /*School:: School(School&&sch){
        name=sch.get_name();
        school_dominant=sch.get_school_dominant();
        number_creatures=sch.get_number_creatures();
        for (int i=0;i<sch.get_size_of_data();i++)
            data[i]=sch.get_data(i);
        Skill sk;
        sch.set_name("");
        sch.set_school_dominant("");
        sch.set_number_creatures(0);
        sch.set_data(sk);
     }*/
    
    ostream& operator <<(ostream& s, const School& sch){
        cout<<"School name: "<<sch.get_name()<<endl;
        cout<<"School dominant name: "<<sch.get_school_dominant()<<endl;
        cout<<"School number of creatures: "<<sch.get_number_creatures()<<endl;
        cout<<"School data: "<<endl;
        for (int i=0;i<sch.data.size();i++){
            cout<<sch.data[i]<<endl;
        }
        return s;
    }
    School& School:: operator=(const School &sch){
        name=sch.get_name();
        school_dominant=sch.get_school_dominant();
        number_creatures=sch.get_number_creatures();
        for (int i=0;i<sch.get_size_of_data();i++)
            data.push_back(sch.get_data(i));
        return *this;
    }
    School& School:: add_skill(Skill &sk){
        set_data(sk);
        return *this;
    }
}
