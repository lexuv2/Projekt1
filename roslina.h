#pragma once
#include "organizm.h"

class Roslina: public  Organizm
{
private:
    /* data */
   
public:
    const int szasna_na_rozmnozenie=4;    
    void akcja();
    void kolizja(Organizm* );
    
};

