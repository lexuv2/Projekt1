#include "organizm.h"

Organizm::Organizm(int c,int d,Swiat* e)
{
    posx=c;
    posy=d;
    swiat = e;
}

Organizm::~Organizm()
{

}

void Organizm::rysowanie()
{
    std::cout << symbol;
}

std::pair<int,int> Organizm::losowe_pole()
{
    int dx=10000000;
    int dy=10000000;
    while (posx+dx >= swiat->w or posx+dx < 0  or posy+dy>=swiat->h  or posy+dy <0 or (dx==0 and dy==0))
    {
    dx = (rand()%3)-1;
    dy = (rand()%3)-1;

    }

    return {posx+dx,posy+dy};
}

std::pair<int,int> Organizm::losowe_puste_pole()
{
    auto  pt = losowe_pole();
    int i=0;
    while (!swiat->czy_puste(pt.first,pt.second))
    {
        
    pt = losowe_pole();
    i++;
    if (i==100)return {posx,posy};
    }


    return pt;
}

Organizm::Organizm()
{
    
}

void Organizm::umrzyj()
{
    swiat->del_organizm(posx,posy);
    nazwa="dead";
    //delete this;
}

void Organizm::przesun(int x,int y)
{
    swiat->del_organizm(posx,posy);
    posx=x;
    posy=y;
    swiat->add_organizm(posx,posy,this);
}

std::string Organizm::to_save()
{
    return std::to_string(id) + " "+std::to_string(posx) + " "+std::to_string(posy)+"\n";
} 


const int Organizm::get_x()
{
    return posx;
}

const int Organizm::get_y()
{
    return posy;
}