#include "swiat.h"
#include <bits/stdc++.h>
#include <fstream>

class cmp
{
public:
    bool operator()(Organizm *a, Organizm *b)
    {
        if (a->inicjatywa > b->inicjatywa)
            return !true;
        else if (a->inicjatywa < b->inicjatywa)
            return !false;
        else if (a->czas_zycia > b->czas_zycia)
            return !true;
        return !false;
    }
};

void Swiat::wykonaj_ture()
{
    tura++;
    std::priority_queue<Organizm *> q;
    for (auto it = organizmy.begin(); it != organizmy.end(); it++)
    {
        q.push(it->second);
    }
    while (!q.empty())
    {
        if (q.top()->nazwa == "dead")
        {
            q.top()->umrzyj();
            q.pop();
            continue;
        }
        q.top()->akcja();
        q.pop();
    }
}

void Swiat::rysuj()
{
    system("clear");
    std::cout << "Aleksander Iwicki 193354" << std::endl;
    for (int i = 0; i < h; ++i)
    {
        for (int j = 0; j < w; ++j)
        {
            if (czy_puste(j, i))
                std::cout << '.';
            else
                at_pos(j, i)->rysowanie();
        }
        if (log.size() >= h - i - 1)
            std::cout << '\t' << log[h - i - 1];
        std::cout << std::endl;
    }
}

Swiat::Swiat()
{

}
void Swiat::init(int n,int m)
{
    h=n;
    w=m;
}
Swiat::~Swiat()
{
}

void Swiat::add_organizm(int x, int y, Organizm *org)
{
    organizmy[{x, y}] = org;
}

void Swiat::del_organizm(int x, int y)
{
    organizmy.erase({x, y});
}

bool Swiat::czy_puste(int x, int y)
{
    bool ret = organizmy.find({x, y}) == organizmy.end();
    return (ret);
}

Organizm *Swiat::at_pos(int x, int y)
{
    return organizmy.find({x, y})->second;
}

void Swiat::add_log(std::string str)
{
    log.push_front(str);
    if (log.size() > h)
        log.pop_back();
}

void Swiat::zapisz()
{
    std::ofstream file;
    file.open("save.sav");
    file << h << " " << w<<'\n';
    for (auto it = organizmy.begin(); it != organizmy.end(); it++)
    {
        file << it->second->to_save();
    }

    file.close();
}

std::pair<int,int> Swiat::wczytaj()
{
    std::ifstream file;
    file.open("save.sav");
    file >> h >> w;
    
    std::pair<int,int> ret;

    int id, xx, yy;
    while (file >> id >> xx >> yy)
    {
        if (id != -1)
        {
            // add_organizm(xx,yy,spwawn[id])
            spawn[id]->rozmnoz(xx, yy);
        }
        else
        {
            ret.first=xx;
            ret.second=yy;
        }
    }

    file.close();
    return ret;
}


std::map<std::pair<int,int>,Organizm*>* Swiat::get_map()
{
    return &organizmy;
}