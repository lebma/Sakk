#include "Kiralyno.hpp"
#include "graphics.hpp"
#include <cstdlib>

using namespace genv;

Kiralyno::Kiralyno(Mezo* M)
    : Babu(M)
{
}

void Kiralyno::draw() const
{
    gout << move_to(100+50*get_x()+25,100+50*get_y()+25) << text("Kn");
}

bool Kiralyno::lephetek_e(Mezo *ide) const
{
    bool igen=false;
    if (ide->get_x()==get_x() || ide->get_y()==get_y()) igen=true;
    else if(abs(ide->get_x()-get_x())==abs(ide->get_y()-get_y())) igen=true;
    if(ide->get_x()==itt_vagyok->get_x() && ide->get_y()==itt_vagyok->get_y()) igen=false;
    return igen;
}
