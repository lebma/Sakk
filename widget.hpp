// *** ADDED BY HEADER FIXUP ***
#include <istream>
// *** END ***
#ifndef WIDGET_HPP_INCLUDED
#define WIDGET_HPP_INCLUDED

#include "graphics.hpp"
#include <iostream>

using namespace std;

class Widget
{
    protected:
        int _x, _y, _size_x, _size_y;
        bool _selected;
    public:
        Widget(int x, int y, int sx, int sy);
        virtual bool is_selected(int mouse_x, int mouse_y) const;
        virtual void draw() const;
        virtual void handle(genv::event ev);
        virtual void log(ostream& logfile);
        virtual void deselect();
};

#endif // WIDGET_HPP_INCLUDED
