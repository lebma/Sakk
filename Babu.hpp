#ifndef BABU_HPP_INCLUDED
#define BABU_HPP_INCLUDED

#include "Mezo.hpp"

class Babu
{
protected:
    Mezo * itt_vagyok;
    bool leptem_mar;
    bool valasztottak;
public:
    Babu(Mezo *M);
    virtual void draw() const=0;
    virtual void lep(Mezo *ide);
    virtual int get_x() const;
    virtual int get_y() const;
    virtual bool lephetek_e(Mezo *mezo) const=0;
    virtual void kivalaszt();
    virtual void nem_valaszt();
    virtual void elfoglal();
    virtual void elhagy();
    virtual bool kiraly_vagyok() const;
};

#endif // BABU_HPP_INCLUDED
