#ifndef FUTO_HPP_INCLUDED
#define FUTO_HPP_INCLUDED

#include "Mezo.hpp"
#include "Babu.hpp"

class Futo : public Babu
{
public:
    Futo(Mezo *M);
    virtual void draw() const;
    virtual bool lephetek_e(Mezo *ide) const;
};

#endif // FUTO_HPP_INCLUDED
