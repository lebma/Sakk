#ifndef WINDOW_HPP_INCLUDED
#define WINDOW_HPP_INCLUDED

#include "widget.hpp"
#include <vector>

class Window
{
protected:
    vector<Widget *> widgets;
    int _XX;
    int _YY;
    bool _opened;
public:
    Window(int XX,int YY);
    virtual void event_loop();
    virtual int get_XX() const;
    virtual int get_YY() const;
    virtual bool get_opened() const;
    virtual void _close();
};
#endif // WINDOW_HPP_INCLUDED
