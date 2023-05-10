#include "zwierzeta.h"
#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>

Czlowiek::Czlowiek(int x, int y, Swiat *s)
{
    id=-1;
    nazwa = "Czlowiek";
    inicjatywa = 4;
    sila = 5;
    posx = x;
    posy = y;
    swiat = s;
    symbol = '8';
}

void Czlowiek::kolizja(Organizm *kol)
{

    if (sila > kol->sila)
    {
        swiat->add_log(nazwa + " zostaje zaatakowany przez " + kol->nazwa + " i wygrywa");
        kol->umrzyj();
    }
    else
    {
        swiat->add_log(nazwa + " zostaje zaatakowany przez " + kol->nazwa + " i przegrywa");
        swiat->del_organizm(posx, posy);
        umrzyj();
        kol->przesun(posx, posy);
    }
}

void Czlowiek::ultm()
{
    int tposx = posx;
    int tposy = posy;
    tposx--;
    tposy--;
    if (!swiat->czy_puste(tposx, tposy))
        swiat->at_pos(tposx, tposy)->umrzyj();

    tposx++;
    if (!swiat->czy_puste(tposx, tposy))
        swiat->at_pos(tposx, tposy)->umrzyj();

    tposx++;
    if (!swiat->czy_puste(tposx, tposy))
        swiat->at_pos(tposx, tposy)->umrzyj();

    tposx -= 2;
    tposy++;
    if (!swiat->czy_puste(tposx, tposy))
        swiat->at_pos(tposx, tposy)->umrzyj();

    tposx += 2;
    if (!swiat->czy_puste(tposx, tposy))
        swiat->at_pos(tposx, tposy)->umrzyj();

    tposx -= 2;
    tposy++;
    if (!swiat->czy_puste(tposx, tposy))
        swiat->at_pos(tposx, tposy)->umrzyj();

    tposx++;
    if (!swiat->czy_puste(tposx, tposy))
        swiat->at_pos(tposx, tposy)->umrzyj();

    tposx++;
    if (!swiat->czy_puste(tposx, tposy))
        swiat->at_pos(tposx, tposy)->umrzyj();
}

void Czlowiek::akcja()
{
    if (nazwa == "dead")
        umrzyj();
    czas_zycia++;
    if (!alive)
        return;

    swiat->rysuj();

    std::cout << "Rusz Człowieka(WSAD) (aby włączyć umiejętnośc kliknij e) (aby zapisac wcisnij z): \n";
    // system("stty raw");
    if (ult)
    {
        ultt--;
        if (ultt <= 0)
        {
            ult = 0;
            ultt = 5;
        }
        else
        {
            std::cout << "[Całopalenie aktywne][" << ultt << ']' << '\n';
        }
    }
    else if (cool >5)
    {
         std::cout << "[Całopalenie dostępne]\n";
    }
    else
    {
        cool++;
    }
    auto pt = std::make_pair(posx, posy);
    char c = getchar();

    
    while (true)
    {
        if (c == 'w' and posy > 0)
        {
            pt.second--;
            break;
        }
        if (c == 'z' and posy > 0)
        {
            swiat->zapisz();
        }
        else if (c == 's' and posy < swiat->h)
        {
            pt.second++;
            break;
        }
        else if (c == 'a' and posx > 0)
        {
            pt.first--;
            break;
        }
        else if (c == 'd' and posx < swiat->w)
        {
            pt.first++;
            break;
        }
        if (c == 'e')
        {
            if (!ult and cool>5)
            {
                ult = true;
                cool=0;
            }
        }
        c = getchar();
    }
    
    
    // system("stty cooked");

    if (ult)
    {
        ultm();
        swiat->rysuj();
    }

    if (swiat->czy_puste(pt.first, pt.second))
    {
        swiat->del_organizm(posx, posy);
        swiat->add_organizm(pt.first, pt.second, this);
        posx = pt.first;
        posy = pt.second;
    }
    else
    {
        swiat->at_pos(pt.first, pt.second)->kolizja(this);
    }
    if (ult)
    {
        ultm();
    }
    swiat->rysuj();
}

void Czlowiek::rozmnoz(int a, int b)
{
}

Wilk::Wilk(int x, int y, Swiat *s)
{
    id=0;
    nazwa = "wilk";
    inicjatywa = 5;
    sila = 9;
    posx = x;
    posy = y;
    swiat = s;
    symbol = 'W';
}

void Wilk::rozmnoz(int x, int y)
{
    swiat->add_organizm(x, y, new Wilk(x, y, swiat));
    swiat->add_log(nazwa + " rozmnaża się na polu: " + std::to_string(x) + " " + std::to_string(y));
}

void Wilk::kolizja(Organizm *kol)
{
    if (dynamic_cast<Wilk *>(kol) != NULL)
    {
        auto pt = losowe_puste_pole();
        rozmnoz(pt.first, pt.second);
    }
    else
    {

        if (sila > kol->sila)
        {
            swiat->add_log(nazwa + " zostaje zaatakowany przez " + kol->nazwa + " i wygrywa");
            kol->umrzyj();
        }
        else
        {
            swiat->add_log(nazwa + " zostaje zaatakowany przez " + kol->nazwa + " i przegrywa");
            swiat->del_organizm(posx, posy);
            umrzyj();
            kol->przesun(posx, posy);
        }
    }
}

Owca::Owca(int x, int y, Swiat *s)
{
    id=1;
    nazwa = "owca";
    inicjatywa = 4;
    sila = 4;
    posx = x;
    posy = y;
    swiat = s;
    symbol = 'O';
}

void Owca::rozmnoz(int x, int y)
{
    swiat->add_organizm(x, y, new Owca(x, y, swiat));
    swiat->add_log(nazwa + " rozmnaża się na polu: " + std::to_string(x) + " " + std::to_string(y));
}

void Owca::kolizja(Organizm *kol)
{
    if (dynamic_cast<Owca *>(kol) != NULL)
    {
        auto pt = losowe_puste_pole();
        rozmnoz(pt.first, pt.second);
    }
    else
    {

        if (sila > kol->sila)
        {
            swiat->add_log(nazwa + " zostaje zaatakowany przez " + kol->nazwa + " i wygrywa");
            kol->umrzyj();
        }
        else
        {
            swiat->add_log(nazwa + " zostaje zaatakowany przez " + kol->nazwa + " i przegrywa");
            swiat->del_organizm(posx, posy);
            umrzyj();
            kol->przesun(posx, posy);
        }
    }
}

void Lis::kolizja(Organizm *kol)
{
    if (dynamic_cast<Lis *>(kol) != NULL)
    {
        auto pt = losowe_puste_pole();
        rozmnoz(pt.first, pt.second);
    }
    else
    {

        if (sila > kol->sila)
        {
            swiat->add_log(nazwa + " zostaje zaatakowany przez " + kol->nazwa + " i wygrywa");
            kol->umrzyj();
        }
        else
        {
            swiat->add_log(nazwa + " zostaje zaatakowany przez " + kol->nazwa + " i przegrywa");
            swiat->del_organizm(posx, posy);
            umrzyj();
            kol->przesun(posx, posy);
        }
    }
}

void Lis::rozmnoz(int x, int y)
{
    swiat->add_organizm(x, y, new Owca(x, y, swiat));
    swiat->add_log(nazwa + " rozmnaża się na polu: " + std::to_string(x) + " " + std::to_string(y));
}

Lis::Lis(int x, int y, Swiat *s)
{
    id=2;
    nazwa = "lis";
    inicjatywa = 7;
    sila = 3;
    posx = x;
    posy = y;
    swiat = s;
    symbol = 'L';
}
void Lis::akcja()
{
    if (nazwa == "dead")
        umrzyj();
    czas_zycia++;
    auto pt = losowe_pole();

    if (swiat->czy_puste(pt.first, pt.second))
    {
        swiat->del_organizm(posx, posy);
        swiat->add_organizm(pt.first, pt.second, this);
        posx = pt.first;
        posy = pt.second;
    }
    else if (swiat->at_pos(pt.first, pt.second)->sila < sila)
    {
        swiat->at_pos(pt.first, pt.second)->kolizja(this);
    }
}

void Zolw::kolizja(Organizm *kol)
{
    if (dynamic_cast<Zolw *>(kol) != NULL)
    {
        auto pt = losowe_puste_pole();
        rozmnoz(pt.first, pt.second);
    }
    else
    {

        if (sila > kol->sila)
        {
            swiat->add_log(nazwa + " zostaje zaatakowany przez " + kol->nazwa + " i odpycha  napastnika");
            // kol->umrzyj();
        }
        else
        {
            swiat->add_log(nazwa + " zostaje zaatakowany przez " + kol->nazwa + " i przegrywa");
            swiat->del_organizm(posx, posy);
            umrzyj();
            kol->przesun(posx, posy);
        }
    }
}

void Zolw::rozmnoz(int x, int y)
{
    swiat->add_organizm(x, y, new Zolw(x, y, swiat));
    swiat->add_log(nazwa + " rozmnaża się na polu: " + std::to_string(x) + " " + std::to_string(y));
}

Zolw::Zolw(int x, int y, Swiat *s)
{
    id=3;
    nazwa = "zolw";
    inicjatywa = 1;
    sila = 2;
    posx = x;
    posy = y;
    swiat = s;
    symbol = 'Z';
}
void Zolw::akcja()
{
    if (nazwa == "dead")
        umrzyj();
    czas_zycia++;

    if (rand() % 5 == 0)
    {
        auto pt = losowe_pole();
        if (swiat->czy_puste(pt.first, pt.second))
        {
            swiat->del_organizm(posx, posy);
            swiat->add_organizm(pt.first, pt.second, this);
            posx = pt.first;
            posy = pt.second;
        }
        else
        {
            swiat->at_pos(pt.first, pt.second)->kolizja(this);
        }
    }
}

void Antylopa::kolizja(Organizm *kol)
{
    if (dynamic_cast<Antylopa *>(kol) != NULL)
    {
        auto pt = losowe_puste_pole();
        rozmnoz(pt.first, pt.second);
    }
    else
    {
        if (rand() % 2 == 0)
        {
            if (sila > kol->sila)
            {
                swiat->add_log(nazwa + " zostaje zaatakowany przez " + kol->nazwa + " i wygrywa");
                kol->umrzyj();
            }
            else
            {
                swiat->add_log(nazwa + " zostaje zaatakowany przez " + kol->nazwa + " i przegrywa");
                swiat->del_organizm(posx, posy);
                umrzyj();
                kol->przesun(posx, posy);
            }
        }
        else
        {
            swiat->add_log(nazwa + " ucieka przed przez " + kol->nazwa);
            auto pt = losowe_puste_pole();
            przesun(pt.first, pt.second);
        }
    }
}

void Antylopa::rozmnoz(int x, int y)
{
    swiat->add_organizm(x, y, new Antylopa(x, y, swiat));
    swiat->add_log(nazwa + " rozmnaża się na polu: " + std::to_string(x) + " " + std::to_string(y));
}

Antylopa::Antylopa(int x, int y, Swiat *s)
{
    id=4;
    nazwa = "antylopa";
    inicjatywa = 4;
    sila = 4;
    posx = x;
    posy = y;
    swiat = s;
    symbol = 'A';
}

void Antylopa::akcja()
{
    if (nazwa == "dead")
        umrzyj();
    czas_zycia++;
    auto pt = losowe_pole();

    if (swiat->czy_puste(pt.first, pt.second))
    {
        swiat->del_organizm(posx, posy);
        swiat->add_organizm(pt.first, pt.second, this);
        posx = pt.first;
        posy = pt.second;

        pt = losowe_pole();
        if (swiat->czy_puste(pt.first, pt.second))
        {
            swiat->del_organizm(posx, posy);
            swiat->add_organizm(pt.first, pt.second, this);
            posx = pt.first;
            posy = pt.second;
        }
        else
        {
            swiat->at_pos(pt.first, pt.second)->kolizja(this);
        }
    }
    else
    {
        swiat->at_pos(pt.first, pt.second)->kolizja(this);
    }
}

void cyberowca::kolizja(Organizm *kol)
{
    if (dynamic_cast<cyberowca *>(kol) != NULL)
    {
        auto pt = losowe_puste_pole();
        rozmnoz(pt.first, pt.second);
    }
    else
    {
        if (dynamic_cast<BarsczSosnowskiego *>(kol) != NULL)
        {
            swiat->add_log(nazwa + " zostaje zaatakowany przez " + kol->nazwa + " i go zjada");
            kol->umrzyj();
        }
        else if (sila > kol->sila)
        {
            swiat->add_log(nazwa + " zostaje zaatakowany przez " + kol->nazwa + " i wygrywa");
            kol->umrzyj();
        }
        else
        {
            swiat->add_log(nazwa + " zostaje zaatakowany przez " + kol->nazwa + " i przegrywa");
            swiat->del_organizm(posx, posy);

            umrzyj();
            kol->przesun(posx, posy);
        }
    }
}

void cyberowca::rozmnoz(int x, int y)
{
    swiat->add_organizm(x, y, new cyberowca(x, y, swiat));
    swiat->add_log(nazwa + " rozmnaża się na polu: " + std::to_string(x) + " " + std::to_string(y));
}

cyberowca::cyberowca(int x, int y, Swiat *s)
{
    id=5;
    nazwa = "cyberowca";
    inicjatywa = 4;
    sila = 11;
    posx = x;
    posy = y;
    swiat = s;
    symbol = 'C';
}



void cyberowca::akcja()
{
    if (nazwa=="dead")umrzyj();
    czas_zycia++;

    bool jest=0;
    int min_odl = INT32_MAX;

    auto mp = swiat->get_map();

    std::pair<int,int> min_ind; 
    for (auto it = mp->begin(); it != mp->end(); it++)
    {
        if (dynamic_cast<BarsczSosnowskiego*>(it->second) != NULL)
        {
            jest = true;
            int tmp =  abs(posx-it->second->get_x())+abs(posy-it->second->get_y());
            if (min_odl > tmp)
            {
                min_odl=tmp;
                min_ind.first = it->second->get_x();
                min_ind.second = it->second->get_y();
            }
        }
    }
    
    std::pair<int,int> pt={posx,posy}; 
    if(!jest)
    pt = losowe_pole();
    else
    {
        if (min_ind.first < posx)
        pt.first--;
        else if (min_ind.first > posx)
        pt.first++;

        if (min_ind.second < posy)
        pt.second--;
        else if (min_ind.second > posy)
        pt.second++;
    }

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