#include "Paraszt.hpp"
#include "graphics.hpp"
#include <cstdlib>

using namespace genv;

Paraszt::Paraszt(Mezo* M,int I)
    : Babu(M)
{
    _irany=I;
}

void Paraszt::draw() const
{
    gout << move_to(100+50*get_x()+25,100+50*get_y()+25) << text("Pa");
}

bool Paraszt::lephetek_e(Mezo *ide) const
{
    bool igen=false;
    if (ide->get_foglalt()==false && ide->get_x()==get_x()+2*_irany && ide->get_y()==get_y() && !leptem_mar) igen=true;
    else if (ide->get_foglalt()==false && ide->get_x()==get_x()+_irany && ide->get_y()==get_y()) igen=true;
    else if (ide->get_foglalt() && ide->get_x()==get_x()+_irany && abs(ide->get_y()-get_y())==1) igen=true;
    if(ide->get_x()==itt_vagyok->get_x() && ide->get_y()==itt_vagyok->get_y()) igen=false;

    return igen;
}
