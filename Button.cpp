#include "Button.hpp"
#include "graphics.hpp"
#include <sstream>
#include <iostream>

using namespace std;
using namespace genv;

Button::Button(int x, int y, int sx, int sy, string F, Window* P, function<void()> action)
    : Widget(x,y,sx,sy)
{
    _function=F;
    parent=P;
    _action=action;
}

void Button::draw() const
{
    gout << move_to(_x, _y) << color(150,150,150) << box(_size_x, _size_y);
    gout << move_to(_x+2, _y+2) << color(255,255,255) << box(_size_x-4, _size_y-4);
    gout << color(0,0,0) << move_to(_x+_size_x/2-gout.twidth(_function)/2,_y+_size_y/2+gout.cascent()/2) << color(0,0,0) << text(_function);
}

void Button::handle(event ev)
{
    if(ev.pos_x > _x && ev.pos_x < _x+_size_x && ev.pos_y > _y && ev.pos_y < _y+_size_y)
    {
        _action();
    }
    _selected=false;
}

void Button::log(ostream& logfile)
{
    logfile << "Button:" << endl;
    logfile << "\t" << "Function" << ".:" << _function << endl;
    logfile << "\t" << "Is pushed" << ".:" << _selected << endl << endl;
}

bool Button::_is_pushed()
{
    return _selected;
}

void Button::_push()
{
    _selected=!_selected;
}

void Button::_set_action(function<void()> action)
{
    _action=action;
}
