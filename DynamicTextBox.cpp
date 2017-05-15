// *** ADDED BY HEADER FIXUP ***
#include <istream>
// *** END ***
#include "DynamicTextBox.hpp"
#include "graphics.hpp"
#include <sstream>
#include <iostream>

using namespace std;
using namespace genv;

DynamicTextBox::DynamicTextBox(int x, int y, int sx, int sy, string S)
    : Widget(x,y,sx,sy)
{
    name=S;
}

void DynamicTextBox::draw() const
{
    gout << move_to(_x, _y) << color(150,150,150) << box(_size_x, _size_y);
    if (_selected)
    {
        gout << move_to(_x, _y) << color(255,150,150) << box(_size_x, _size_y);
    }
    gout << move_to(_x+2, _y+2) << color(255,255,255) << box(_size_x-4, _size_y-4);
    gout << move_to(_x+4,_y+_size_y/2+gout.cascent()/2) << color(0,0,0) << text(name);
}

void DynamicTextBox::handle(event ev)
{
    if (ev.button==btn_left) _selected=false;
    if(ev.pos_x > _x && ev.pos_x < _x+_size_x && ev.pos_y > _y && ev.pos_y < _y+_size_y && ev.button==btn_left) _selected=true;
    if (_selected)
    {
        new_name(ev);
    }
}

void DynamicTextBox::new_name(event ev)
{
    if(ev.type==ev_key && ev.keycode>0 && ev.keycode!=key_backspace && ev.keycode!=key_enter && ev.keycode!=key_lshift)
    {
        if (gout.twidth(name) < _size_x-10) name+=ev.keycode;
    }
    if(ev.keycode==key_backspace)
    {
        name=name.substr(0,name.length()-1);
    }
}

void DynamicTextBox::log(ostream& logfile)
{
    logfile << "DynamicTextBox:" << endl;
    logfile << "\t" << "name" << ".:" << name << endl;
    logfile << "\tselected: " << _selected << endl << endl;
    logfile << "\tselected: " << _selected << endl << endl;
}

string DynamicTextBox::get_name()
{
    return name;
}

string DynamicTextBox::_mitortent()
{
    return "dynamictextbox";
}
