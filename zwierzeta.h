#pragma once
#include "zwierze.h"
#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
#include "rosliny.h"

class Czlowiek: public Zwierze
{
    
    bool alive=true;
    bool ult=false;
    int ultt=5;
    int cool=10;
    public:
    void kolizja(Organizm*);
    void rozmnoz(int , int);
    void akcja();
    Czlowiek(int , int ,Swiat* );
    void ultm();


};


class Wilk: public Zwierze
{
    
    public:
    void kolizja(Organizm*);
    void rozmnoz(int , int);
    Wilk(int , int ,Swiat* );


};


class Owca: public Zwierze
{
    
    public:
   void kolizja(Organizm*);
    void rozmnoz(int , int);
    Owca(int , int ,Swiat* );
};

class Lis: public Zwierze
{
    public:
    void kolizja(Organizm*);
    void rozmnoz(int , int);
    void akcja();
    Lis(int , int ,Swiat* );
};

class Zolw: public Zwierze
{
    public:
    void kolizja(Organizm*);
    void rozmnoz(int , int);
    void akcja();
    Zolw(int , int ,Swiat* );
};


class Antylopa: public Zwierze
{
    public:
    void kolizja(Organizm*);
    void rozmnoz(int , int);
    void akcja();
    Antylopa(int , int ,Swiat* );
};


class cyberowca: public Zwierze
{
    public:
    void kolizja(Organizm*);
    void rozmnoz(int , int);
    void akcja();
    cyberowca(int , int ,Swiat* );
};
