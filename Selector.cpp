#include "Selector.hpp"
#include "graphics.hpp"
#include <vector>
#include <iostream>

using namespace std;
using namespace genv;

Selector::Selector(int x, int y, int sx, int sy, int H, vector<string> choices)
    : Widget(x,y,sx,sy)
{
    v=choices;
    choice=0;
    from=0;
    opened=false;
    height=H;
    scrolled=false;
}

void Selector::draw() const
{
    gout << move_to(_x,_y) << color(150,150,150) << box(_size_x,_size_y);
    gout << move_to(_x+2,_y+2) << color(255,255,255) << box(_size_x-_size_y-4,_size_y-4);
    gout << move_to(_x+2,_y+_size_y/2+gout.cascent()/2)<< color(0,0,0);
    if(v.size()<1)
    {
        gout << text("There is no choice");
    }
    else if(gout.twidth(v[choice]) <= (int)_size_x-4)
    {
        gout << text(v[choice]);
    }
    else
    {
        for (int i=v[choice].length()-1; i>=0; i--)
        {
            if(gout.twidth(v[choice].substr(0,i)) <= (int)_size_x-_size_y-4)
            {
                gout << text(v[choice].substr(0,i-3)) << text("...");
                break;
            }
        }
    }
    if(opened)
    {
        gout << move_to(_x,_y+_size_y) << color(150,150,150) << box(_size_x,2+25*min(height,(int)v.size()));
        gout << move_to(_x+2,_y+_size_y) << color(255,255,255) << box(_size_x-4,25*min(height,(int)v.size()));
        for (int i=from; i<from+min(height,(int)v.size()); i++)
        {
            if(choice==i)
            {
                gout << move_to(_x+2,_y+_size_y+(i-from)*25) << color(150,150,255) << box(_size_x-_size_y-4,25);
            }
            gout << move_to(_x+2,_y+_size_y+(25/2+gout.cascent()/2)+25*(i-from)) << color(0,0,0);
            if(gout.twidth(v[i]) <= (int)_size_x-4)
            {
                gout << text(v[i]);
            }
            else
            {
                for (int j=v[i].length()-1; j>=0; j--)
                {
                    if(gout.twidth(v[i].substr(0,j)) <= (int)_size_x-_size_y-4)
                    {
                        gout << text(v[i].substr(0,j-3)) << text("...");
                        break;
                    }
                }
            }
        }
        gout << move_to(_x+_size_x-_size_y+_size_y/3,_y+2*_size_y/3) << color(255,255,255) << line(_size_y/5,-_size_y/3);
        gout << move_to(_x+_size_x-_size_y+2*_size_y/3,_y+2*_size_y/3) << color(255,255,255) << line(-_size_y/5,-_size_y/3);
        if(height < v.size())
        {
            gout << move_to(_x+_size_x-_size_y-2,_y+_size_y) << color(150,150,150) << box(2,25*height);
            gout << move_to(_x+_size_x-_size_y,_y+_size_y+25*from*height/(int)v.size()) << color(150,150,150) << box(_size_y,2+25*height*height/(int)v.size());
        }
    }
    else
    {
        gout << move_to(_x+_size_x-_size_y+_size_y/3,_y+_size_y/3) << color(255,255,255) << line(_size_y/5,_size_y/3);
        gout << move_to(_x+_size_x-_size_y+2*_size_y/3,_y+_size_y/3) << color(255,255,255) << line(-_size_y/5,_size_y/3);
    }
}

void Selector::new_choice(string text)
{
    v.push_back(text);
}

void Selector::selection(event ev)
{
    if(ev.pos_x > _x && ev.pos_x < _x+_size_x-_size_y && ev.button==btn_left)
    {
        for(int i=0; i<height; i++)
        {
            if(ev.pos_y > _y+_size_y+i*25 && ev.pos_y < _y+_size_y+(i+1)*25)
            {
                choice=i+from;
                opened=false;
            }
        }
    }
    if(ev.keycode==key_down || ev.button==btn_wheeldown) choice=min(choice+1,(int)v.size()-1);
    if(ev.keycode==key_up || ev.button==btn_wheelup) choice=max(0,choice-1);
    if(choice<from) from--;
    if(choice>from+height-1) from++;
    if(ev.keycode==key_pgdn) choice=min(choice+10,(int)v.size()-1);
    if(ev.keycode==key_pgup) choice=max(0,choice-10);
    if(ev.keycode==key_enter) opened=false;
}

void Selector::handle(event ev)
{
    if(opened && ev.type==ev.button && !_selected) opened=false;
    if(ev.button==btn_left)
    {
        if(ev.pos_x >_x+_size_x-_size_y && ev.pos_x < _x+_size_x && ev.pos_y > _y && ev.pos_y < _y+_size_y)
        {
            opened=!opened;
        }
    }
    if(opened) selection(ev);
}

void Selector::log(ostream& logfile)
{
    logfile << "Selector:" << endl;
    for(int i=0; i<v.size(); i++)
    {
        logfile << "\t" << i << ".:" << v[i] << endl;
    }
    logfile << "\tchosen: " << v[choice] << endl << endl;
}

bool Selector::is_selected(int mouse_x, int mouse_y) const
{
    if(opened)
    {
        return mouse_x>_x && mouse_x<_x+_size_x && mouse_y>_y && mouse_y<_y+_size_y+2+25*min(height,(int)v.size());
    }
    else return mouse_x>_x && mouse_x<_x+_size_x && mouse_y>_y && mouse_y<_y+_size_y;
}

string Selector::_mitortent()
{
    return "selector";
}

void Selector::del_chosen()
{
    if (v.size() > 1)
    {
        if(choice!=v.size()-1)
        {
            for (int i=choice; i<v.size()-1; i++)
            {
                v[i]=v[i+1];
            }
        }
        choice=0;
        v.pop_back();
    }
    else v.clear();
}

string Selector::get_chosen()
{
    return v[choice];
}

int Selector::get_choice()
{
    return choice;
}

void Selector::deselect()
{
    _selected=false;
    if (opened) opened=false;
}
