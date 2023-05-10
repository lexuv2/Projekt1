#include "roslina.h"

void Roslina::akcja()
{
    int rnd = rand()%100;
    if (rnd < szasna_na_rozmnozenie)
    {
        auto pt = losowe_puste_pole();
        rozmnoz(pt.first , pt.second);
    }
    
}

void Roslina::kolizja(Organizm*  kol)
{
    swiat->add_log(nazwa+ " zostaje rozdeptany przez "+kol->nazwa);
    
    umrzyj();
    kol->przesun(posx,posy);
}


