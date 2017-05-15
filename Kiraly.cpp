#include "Kiraly.hpp"
#include "graphics.hpp"
#include <cstdlib>

using namespace genv;

Kiraly::Kiraly(Mezo* M)
    : Babu(M)
{
}

void Kiraly::draw() const
{
    gout << move_to(100+50*get_x()+25,100+50*get_y()+25) << text("Ki");
}

bool Kiraly::lephetek_e(Mezo *ide) const
{
    bool igen=false;
    if (abs(ide->get_x()-get_x())<=1 && abs(ide->get_y()-get_y())<=1) igen=true;
    if(ide->get_x()==get_x() && ide->get_y()==get_y()) igen=false;
    return igen;
}

bool Kiraly::kiraly_vagyok() const
{
    return true;
}
