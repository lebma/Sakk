#ifndef PARASZT_HPP_INCLUDED
#define PARASZT_HPP_INCLUDED

#include "Babu.hpp"
#include "Mezo.hpp"
class Babu;
class Mezo;

class Paraszt : public Babu
{
private:
    int _irany;
public:
    Paraszt(Mezo* M, int I);
    virtual void draw() const;
    virtual bool lephetek_e(Mezo *ide) const;
};

#endif // PARASZT_HPP_INCLUDED
