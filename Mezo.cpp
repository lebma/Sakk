#include <istream>
#include "Mezo.hpp"
#include "graphics.hpp"
#include <iostream>

using namespace genv;

Mezo::Mezo(int X, int Y, int M)//, MyGame* P)
:Widget(X,Y,M,M)
{
    _foglalt=false;
   // _parent=P;
    if((X+Y)%2==0)
    {
        r=0;
        g=0;
        b=0;
    }
    else
    {
        r=255;
        g=255;
        b=255;
    }
}

void Mezo::draw() const
{
    gout << move_to(100+_x*50,100+_y*50) << color(r,g,b) << box(_size_x,_size_x);
    if (_selected)
    {
        gout << move_to(100+_x*50,100+_y*50) << color(200,200,100) << box(_size_x,_size_x);
    }
    if (_selected && _foglalt)
    {
        gout << move_to(100+_x*50,100+_y*50) << color(100,255,100) << box(_size_x,_size_x);
    }
}

bool Mezo::get_foglalt()
{
    return _foglalt;
}

int Mezo::get_x()
{
    return _x;
}

int Mezo::get_y()
{
    return _y;
}

bool Mezo::is_selected(int mouse_x, int mouse_y) const
{
    return mouse_x>100+50*_x && mouse_x<100+50*_x+_size_x && mouse_y>100+50*_y && mouse_y<100+50*_y+_size_y;
}

void Mezo::handle(event ev) {
    if(ev.button==btn_left && is_selected(ev.pos_x,ev.pos_y)) _selected=!_selected;
}

void Mezo::set_foglalt(bool valami)
{
    _foglalt=valami;
}
