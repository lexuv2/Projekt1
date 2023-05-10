#pragma once
#include "organizm.h"
#include <bits/stdc++.h>
#include <fstream>


class Organizm;
class BarsczSosnowskiego;

class Swiat
{
private:
    /* data */
    std::deque<std::string> log;
    std::map<std::pair<int,int>,Organizm*> organizmy;
    int tura=0;
    
public:
    int h;
    int w;
    Organizm* spawn[20];
    Swiat();
    void init(int,int);
    ~Swiat();
    void rysuj();
    void wykonaj_ture();
    void add_organizm(int ,int, Organizm*);
    void del_organizm(int ,int);
    void add_log(std::string);
    bool czy_puste(int,int);
    void zapisz();
    std::pair<int,int> wczytaj();
    Organizm* at_pos(int,int);
    std::pair<int,int> najblizsza_trawa(int ,int);
    std::map<std::pair<int,int>,Organizm*>* get_map();
};


