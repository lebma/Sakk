#ifndef MEZO_HPP_INCLUDED
#define MEZO_HPP_INCLUDED

#include "widget.hpp"
//#include "MyGame.hpp"

class Mezo : public Widget
{
protected:
    int r,g,b;
    bool _foglalt;
    bool _celpont;
    //MyGame* _parent;
public:
    Mezo(int X, int Y, int M);//, MyGame* P);
    virtual bool get_foglalt();
    virtual void draw() const;
    virtual int get_x();
    virtual int get_y();
    virtual bool is_selected(int mouse_x, int mouse_y) const;
    virtual void handle(genv::event ev);
    virtual void set_foglalt(bool valami);
};

#endif // MEZO_HPP_INCLUDED
