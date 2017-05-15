// *** ADDED BY HEADER FIXUP ***
#include <istream>
// *** END ***
#include "counter.hpp"
#include "graphics.hpp"
#include <sstream>
#include <iostream>

using namespace genv;
using namespace std;

Counter::Counter(int x, int y, int sx, int sy, int Max, int Min, int N)
    : Widget(x,y,sx,sy)
{
    _max=Max;
    _min=Min;
    n=min(Max,max(Min,N));
}

void Counter::draw() const
{
    stringstream ss;
    string s;
    ss << n;
    ss >> s;
    gout << move_to(_x,_y) << color(150,150,150) << box(_size_x,_size_y);
    gout << move_to(_x+2,_y+2) << color(255,255,255) << box(_size_x-_size_y/2-4,_size_y-4);
    gout << move_to(_x+2,_y+_size_y/2+gout.cascent()/2)<< color(0,0,0) << text(s);
    gout << move_to(_x+_size_x-_size_y/2+_size_y/6,_y+_size_y/3) << color(255,255,255) << line(_size_y/8,-_size_y/4);
    gout << move_to(_x+_size_x-_size_y/2+2*_size_y/6,_y+_size_y/3) << color(255,255,255) << line(-_size_y/8,-_size_y/4);
    gout << move_to(_x+_size_x-_size_y/2+_size_y/6,_y+_size_y/2+_size_y/6) << color(255,255,255) << line(_size_y/8,_size_y/4);
    gout << move_to(_x+_size_x-_size_y/2+2*_size_y/6,_y+_size_y/2+_size_y/6) << color(255,255,255) << line(-_size_y/8,_size_y/4);
}

void Counter::handle(event ev)
{

    if(ev.button==btn_left)
    {
        if (ev.pos_x > _x+_size_x-_size_y/2 && ev.pos_x < _x+_size_x-_size_y/2+_size_x)
        {
            if(ev.pos_y > _y && ev.pos_y < _y+_size_y/2) counting(1);
            else if(ev.pos_y > _y+_size_y/2 && ev.pos_y < _y+_size_y) counting(-1);
        }
    }
    if(ev.keycode==key_pgdn) counting(-10);
    if(ev.keycode==key_pgup) counting(10);
    if(ev.keycode==key_down) counting(-1);
    if(ev.keycode==key_up)  counting(1);
}

void Counter::counting(int diff)
{
    n=n+diff;
    if (n>_max) n=_max;
    if (n<_min) n=_min;
}

void Counter::log(ostream& logfile)
{
    logfile << "Counter:" << endl;
    logfile << "\trange: [" << _min << ";" << _max << "]" << endl;
    logfile << "\tvalue: " << n << endl << endl;
}

string Counter::_mitortent()
{
    return "counter";
}

int Counter::get_number()
{
    return n;
}
