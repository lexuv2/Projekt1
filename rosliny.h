#pragma once
#include "roslina.h"
#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
#include "zwierzeta.h"

class Swiat;

class Trawa: public Roslina
{
    public:
    //void kolizja(Organizm*);
    void rozmnoz(int , int);
    Trawa(int , int ,Swiat* );


};

class Mlecz: public Roslina
{
    public:
    //void kolizja(Organizm*);
    void rozmnoz(int , int);
    void akcja();
    Mlecz(int , int ,Swiat* );
};


class Guarana: public Roslina
{
    public:
    //void kolizja(Organizm*);
    void rozmnoz(int , int);
    void kolizja(Organizm*  kol);
    Guarana(int , int ,Swiat* );
};

class WilczeJagody: public Roslina
{
    public:
    //void kolizja(Organizm*);
    void rozmnoz(int , int);
    void kolizja(Organizm*  kol);
    WilczeJagody(int , int ,Swiat* );
};

class BarsczSosnowskiego: public Roslina
{
    public:
    //void kolizja(Organizm*);
    void rozmnoz(int , int);
    void kolizja(Organizm*  kol);
    void akcja();
    BarsczSosnowskiego(int , int ,Swiat* );
};