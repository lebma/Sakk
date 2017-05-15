#ifndef KIRALY_HPP_INCLUDED
#define KIRALY_HPP_INCLUDED

#include "Mezo.hpp"
#include "Babu.hpp"
class Babu;

class Kiraly : public Babu
{
public:
    Kiraly(Mezo* M);
    virtual void draw() const;
    virtual bool lephetek_e(Mezo *ide) const;
    virtual bool kiraly_vagyok() const;
};

#endif // KIRALY_HPP_INCLUDED
