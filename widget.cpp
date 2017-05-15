#include "graphics.hpp"
#include "widget.hpp"
using namespace genv;

Widget::Widget(int x, int y, int sx, int sy)
{
    _x=x;
    _y=y;
    _size_x = sx;
    _size_y=sy;
    _selected=false;
}

bool Widget::is_selected(int mouse_x, int mouse_y) const
{
    return mouse_x>_x && mouse_x<_x+_size_x && mouse_y>_y && mouse_y<_y+_size_y;
}

void Widget::draw() const {
}

void Widget::handle(event ev) {
}

void Widget::log(ostream& logfile){
}

void Widget::deselect()
{
    _selected=false;
}
