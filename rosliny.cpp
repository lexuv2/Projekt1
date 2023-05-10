#include "rosliny.h"

#define log_romz false

Trawa::Trawa(int x, int y, Swiat *s)
{
    id=6;
    nazwa="trawa";
    inicjatywa = 0;
    sila = 0;
    posx = x;   
    posy = y;
    swiat = s;
    symbol = 'T';
}

void Trawa::rozmnoz(int x, int y)
{
    swiat->add_organizm(x,y,new Trawa(x,y,swiat));
    if(log_romz)
    swiat->add_log( nazwa+" rozmnaża się na polu: " + std::to_string(x) + " "+ std::to_string(y));
}


Mlecz::Mlecz(int x, int y, Swiat *s)
{
    id=7;
    nazwa="Mlecz";
    inicjatywa = 0;
    sila = 0;
    posx = x;   
    posy = y;
    swiat = s;
    symbol = 'M';
}

void Mlecz::rozmnoz(int x, int y)
{
    swiat->add_organizm(x,y,new Mlecz(x,y,swiat));
    if(log_romz)
    swiat->add_log( nazwa+" rozmnaża się na polu: " + std::to_string(x) + " "+ std::to_string(y));
}

void Mlecz::akcja()
{
    for  (int i=0;i<3;++i)
    {
    int rnd = rand()%100;
    if (rnd < szasna_na_rozmnozenie)
    {
        auto pt = losowe_puste_pole();
        rozmnoz(pt.first , pt.second);
    }
    }
}



Guarana::Guarana(int x, int y, Swiat *s)
{
    id=8;
    nazwa="Guarana";
    inicjatywa = 0;
    sila = 0;
    posx = x;   
    posy = y;
    swiat = s;
    symbol = 'G';
}

void Guarana::rozmnoz(int x, int y)
{
    swiat->add_organizm(x,y,new Guarana(x,y,swiat));
    if(log_romz)
    swiat->add_log( nazwa+" rozmnaża się na polu: " + std::to_string(x) + " "+ std::to_string(y));
}

void Guarana::kolizja(Organizm*  kol)
{
    swiat->add_log(nazwa+ " zostaje zjedzona przez "+kol->nazwa);
    kol->sila+=3;
    umrzyj();
    kol->przesun(posx,posy);
    
}



WilczeJagody::WilczeJagody(int x, int y, Swiat *s)
{
    id=9;
    nazwa="WilczeJagody";
    inicjatywa = 0;
    sila = 99;
    posx = x;   
    posy = y;
    swiat = s;
    symbol = 'J';
}

void WilczeJagody::rozmnoz(int x, int y)
{
    swiat->add_organizm(x,y,new WilczeJagody(x,y,swiat));
    if(log_romz)
    swiat->add_log( nazwa+" rozmnaża się na polu: " + std::to_string(x) + " "+ std::to_string(y));
}

void WilczeJagody::kolizja(Organizm*  kol)
{
    swiat->add_log(nazwa+ " zatruwa "+kol->nazwa);
    umrzyj();
    kol->umrzyj();
    //kol->przesun(posx,posy);
    
}




BarsczSosnowskiego::BarsczSosnowskiego(int x, int y, Swiat *s)
{
    id=10;
    nazwa="BarsczSosnowskiego";
    inicjatywa = 0;
    sila = 99;
    posx = x;   
    posy = y;
    swiat = s;
    symbol = 'B';
}

void BarsczSosnowskiego::rozmnoz(int x, int y)
{
    swiat->add_organizm(x,y,new BarsczSosnowskiego(x,y,swiat));
    if(log_romz)
    swiat->add_log( nazwa+" rozmnaża się na polu: " + std::to_string(x) + " "+ std::to_string(y));
}

void BarsczSosnowskiego::kolizja(Organizm*  kol)
{
    if (dynamic_cast<cyberowca*>(kol) == NULL)
    {
    swiat->add_log(nazwa+ " zatruwa "+kol->nazwa);
    kol->umrzyj();
    }
    //kol->przesun(posx,posy);
    else
    {
    swiat->add_log(nazwa+ " zsotaje jedzona przez "+kol->nazwa);
    umrzyj();
    kol->przesun(posx,posy);
    }
    
}
void BarsczSosnowskiego::akcja()
{
    int  tposx=posx;
    int  tposy=posy;
    tposx--;
    tposy--;
    if (!swiat->czy_puste(tposx,tposy))
    if (dynamic_cast<cyberowca*>(swiat->at_pos(tposx,tposy)) == NULL and (dynamic_cast<Zwierze*>(swiat->at_pos(tposx,tposy)) != NULL))
    swiat->at_pos(tposx,tposy)->umrzyj();



    tposx++;
    if (!swiat->czy_puste(tposx,tposy))
    if (dynamic_cast<cyberowca*>(swiat->at_pos(tposx,tposy)) == NULL and (dynamic_cast<Zwierze*>(swiat->at_pos(tposx,tposy)) != NULL))
    swiat->at_pos(tposx,tposy)->umrzyj();
    
    tposx++;
    if (!swiat->czy_puste(tposx,tposy))
    if (dynamic_cast<cyberowca*>(swiat->at_pos(tposx,tposy)) == NULL and (dynamic_cast<Zwierze*>(swiat->at_pos(tposx,tposy)) != NULL))
    swiat->at_pos(tposx,tposy)->umrzyj();

    tposx-=2;
    tposy++;
    if (!swiat->czy_puste(tposx,tposy))
    if (dynamic_cast<cyberowca*>(swiat->at_pos(tposx,tposy)) == NULL and (dynamic_cast<Zwierze*>(swiat->at_pos(tposx,tposy)) != NULL))
    swiat->at_pos(tposx,tposy)->umrzyj();

    tposx+=2;
    if (!swiat->czy_puste(tposx,tposy))
    if (dynamic_cast<cyberowca*>(swiat->at_pos(tposx,tposy)) == NULL and (dynamic_cast<Zwierze*>(swiat->at_pos(tposx,tposy)) != NULL))
    swiat->at_pos(tposx,tposy)->umrzyj();


    tposx-=2;
    tposy++;
    if (!swiat->czy_puste(tposx,tposy))
    if (dynamic_cast<cyberowca*>(swiat->at_pos(tposx,tposy)) == NULL and (dynamic_cast<Zwierze*>(swiat->at_pos(tposx,tposy)) != NULL))
    swiat->at_pos(tposx,tposy)->umrzyj();

    tposx++;
    if (!swiat->czy_puste(tposx,tposy))
    if (dynamic_cast<cyberowca*>(swiat->at_pos(tposx,tposy)) == NULL and (dynamic_cast<Zwierze*>(swiat->at_pos(tposx,tposy)) != NULL))
    swiat->at_pos(tposx,tposy)->umrzyj();

    tposx++;
    if (!swiat->czy_puste(tposx,tposy))
    if (dynamic_cast<cyberowca*>(swiat->at_pos(tposx,tposy)) == NULL and (dynamic_cast<Zwierze*>(swiat->at_pos(tposx,tposy)) != NULL))
    swiat->at_pos(tposx,tposy)->umrzyj();

}
