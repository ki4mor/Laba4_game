//
//  menu.cpp
//  laba4
//
//  Created by Полина Подчуфарова on 09/12/2019.
//  Copyright © 2019 Полина Подчуфарова. All rights reserved.
//

#include <stdio.h>
#include "menu.h"
#include "Landscape.h"
using namespace menu;
    int main(int argc, const char * argv[]){
        laba4::Landscape c;
        string q;
        do{
            char d = menu::dialog();
            menu::menu_t(d,c);
            cout<<"Enter exit for exit"<<endl;;
           cin>>q;
        } while (q!="exit");
         return 0;
    }


