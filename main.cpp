#include <iostream>
#include "swiat.h"
#include "zwierzeta.h"
#include "rosliny.h"

using namespace std;

int main()
{
    srand(193354);
    Swiat swiat;

    swiat.spawn[0] = new Wilk(0, 0, &swiat);
    swiat.spawn[1] = new Owca(0, 0, &swiat);
    swiat.spawn[2] = new Lis(0, 0, &swiat);
    swiat.spawn[3] = new Zolw(0, 0, &swiat);
    swiat.spawn[4] = new Antylopa(0, 0, &swiat);
    swiat.spawn[5] = new cyberowca(0, 0, &swiat);

    swiat.spawn[6] = new Trawa(0, 0, &swiat);
    swiat.spawn[7] = new Mlecz(0, 0, &swiat);
    swiat.spawn[8] = new Guarana(0, 0, &swiat);
    swiat.spawn[9] = new WilczeJagody(0, 0, &swiat);
    swiat.spawn[10] = new BarsczSosnowskiego(0, 0, &swiat);


    cout << "Jeśli chcesz załadować gre wciśnij l";
    char c;
    cin >> c;
    if (c == 'l')
    {

        auto pt = swiat.wczytaj();
        swiat.add_organizm(pt.first, pt.second, new Czlowiek(pt.first, pt.second, &swiat));
    }
    else
    {

        cout << "podaj rozmiar polanszy: ";
        int n, m;
        cin >> n >> m;
        swiat.init(n, m);

        swiat.add_organizm(1, 1, new Czlowiek(1, 1, &swiat));

        for (int i = 0; i <= 10; ++i)
        {
            for (int j = 0; j < 5; ++j)
            {
                int xx =rand() % m;
                int yy =  rand() % n;
                swiat.spawn[i]->rozmnoz(xx,yy);
            }
        }
    }
    swiat.rysuj();
    while (true)
    {

        swiat.wykonaj_ture();
        swiat.rysuj();
        // getchar();
    }
}
