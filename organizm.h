#pragma once
#include "swiat.h"
#include <cstdlib>
#include <bits/stdc++.h>
class Swiat;

class Organizm
{
protected:
    /* data */
    
    
    int posx=0;
    int posy=0;
    int id=0;
    char symbol;
    Swiat* swiat;
    std::pair<int,int> losowe_pole();
    std::pair<int,int> losowe_puste_pole();
public:
    int sila=0;
    std::string nazwa;
    int czas_zycia=0;
    int inicjatywa=0;
    Organizm(int ,int,Swiat* /* args */);
    Organizm(/* args */);
    ~Organizm();
    virtual void akcja()=0;
    virtual void kolizja(Organizm* )=0;
    virtual void rozmnoz(int , int)=0;
    const int get_x();
    const int get_y();
    void umrzyj();
    void rysowanie();
    void przesun(int ,int);
    std::string to_save();
};