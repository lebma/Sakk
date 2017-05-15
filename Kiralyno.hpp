#ifndef KIRALYNO_HPP_INCLUDED
#define KIRALYNO_HPP_INCLUDED

#include "Mezo.hpp"
#include "Babu.hpp"

class Kiralyno : public Babu
{
public:
    Kiralyno(Mezo* M);
    virtual void draw() const;
    virtual bool lephetek_e(Mezo *ide) const;
};

#endif // KIRALYNO_HPP_INCLUDED
