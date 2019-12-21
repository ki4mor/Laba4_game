//
//  menu.h
//  laba4
//
//  Created by Полина Подчуфарова on 21/12/2019.
//  Copyright © 2019 Полина Подчуфарова. All rights reserved.
//

#ifndef menu_h
#define menu_h
#include "Landscape.h"
#include "OResurrecting_Troop.h"
#include "IResurrecting_Troop.h"
#include "Ordinary_Troop.h"
#include "menu.h"
using namespace std;
namespace menu {
    int get_char(char& str);
    char dialog();
    char dialog_troop();
    char dialog_s();
    void menu_t(char d,laba4::Landscape &L);
    void menu_s(char d,laba4::Summoner& s,laba4:: Landscape& L);
    void menu_troop(char d,laba4::Landscape &L,laba4::Immoral_Troop*);
    
}


#endif /* menu_h */
