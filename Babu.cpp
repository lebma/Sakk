#include "Babu.hpp"
#include <iostream>

Babu::Babu(Mezo *M)
{
    itt_vagyok=M;
    leptem_mar=false;
    valasztottak=false;
}

int Babu::get_x() const
{
    return itt_vagyok->get_x();
}

int Babu::get_y() const
{
    return itt_vagyok->get_y();
}

void Babu::lep(Mezo *ide)
{
    itt_vagyok=ide;
    valasztottak=false;
    leptem_mar=true;
}

void Babu::kivalaszt()
{
    valasztottak=true;
}

void Babu::nem_valaszt()
{
    valasztottak=false;
}

void Babu::elfoglal()
{
    itt_vagyok->set_foglalt(true);
}

void Babu::elhagy()
{
    itt_vagyok->set_foglalt(false);
}

bool Babu::kiraly_vagyok() const
{
    return false;
}
