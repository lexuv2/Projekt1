#include "zwierze.h"

void Zwierze::akcja()
{
    if (nazwa=="dead")umrzyj();
    czas_zycia++;
    auto pt = losowe_pole();

    if (swiat->czy_puste(pt.first,pt.second))
    {
        swiat->del_organizm(posx,posy);
        swiat->add_organizm(pt.first,pt.second,this);
        posx=pt.first;
        posy=pt.second;
    }
    else
    {
        swiat->at_pos(pt.first,pt.second)->kolizja(this);
    }

}