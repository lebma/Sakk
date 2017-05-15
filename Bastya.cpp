#include "Bastya.hpp"
#include "graphics.hpp"

using namespace genv;

Bastya::Bastya(Mezo *M)
:Babu(M)
{

}

void Bastya::draw() const
{
    gout << move_to(100+50*get_x()+25,100+50*get_y()+25) << text("Ba");
}

bool Bastya::lephetek_e(Mezo *ide) const
{
    bool igen=false;
    if (ide->get_x()==get_x()|| ide->get_y()==get_y()) igen=true;
    if(ide->get_x()==get_x() && ide->get_y()==get_y()) igen=false;
    return igen;
}
