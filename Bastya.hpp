#ifndef BASTYA_HPP_INCLUDED
#define BASTYA_HPP_INCLUDED

#include "Mezo.hpp"
#include "Babu.hpp"

class Bastya : public Babu
{
public:
    Bastya(Mezo *M);
    virtual void draw() const;
    virtual bool lephetek_e(Mezo *ide) const;
};


#endif // BASTYA_HPP_INCLUDED
