#include "widget.hpp"
#include "window.hpp"
#include "iostream"

using namespace genv;
using namespace std;

Window::Window(int XX, int YY)
{
    _XX=XX;
    _YY=YY;
    _opened=false;
}

void Window::event_loop()
{
    _opened=true;
    event ev;
    int focus = -1;
    while(_opened && gin >> ev && ev.keycode!=key_escape) {
        gout << move_to(0,0) << color(50,50,50) << box(_XX,_YY);
        if(focus==-1 || !widgets[focus]->is_selected(ev.pos_x,ev.pos_y))
        {
             if (ev.type == ev_mouse && ev.button==btn_left) {
                for (size_t i=0;i<widgets.size();i++) {
                    if (widgets[i]->is_selected(ev.pos_x, ev.pos_y)) {
                            focus = i;
                    }
                    else widgets[i]->deselect();
                }
            }
        }

        if (focus!=-1) {
            widgets[focus]->handle(ev);
        }
        for (size_t i=0;i<widgets.size();i++) {
            widgets[i]->draw();
        }
        if(focus!=-1) widgets[focus]->draw();
        gout << refresh;
       /* if(ev.keycode==key_f5)
        {
            for (int i=0;i<widgets.size();i++)
            {
                widgets[i]->log(logfile);
            }
        }*/
        gout << move_to(0,0) << color(50,50,50) << box(_XX,_YY);
    }
}
int Window::get_XX() const
{
    return _XX;
}
int Window::get_YY() const
{
    return _YY;
}

bool Window::get_opened() const
{
    return _opened;
}

void Window::_close()
{
    _opened=false;
}
