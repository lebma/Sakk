#include "graphics.hpp"
#include "StaticString.hpp"
using namespace genv;
using namespace std;

StaticString::StaticString(int x, int y, string N)
: Widget(x, y, gout.twidth(N), gout.cascent())
{
    _nev = N;
}

void StaticString::draw() const {
    gout << move_to(_x,_y) << color(255,255,150) << text(_nev);
}

void StaticString::log(ostream& logfile){
}

void StaticString::uj_nev(string valami){
    _nev=valami;
}

string StaticString::get_name() const{
    return _nev;
}
