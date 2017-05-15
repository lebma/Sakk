#ifndef BUTTON_HPP_INCLUDED
#define BUTTON_HPP_INCLUDED

#include "widget.hpp"
#include "Window.hpp"
#include <functional>

using namespace std;

class Button : public Widget{
    protected:
        string _function;
        Window *parent;
        function<void()> _action;
    public:
        Button(int x, int y, int sx, int sy, string F,Window* P,function<void()> action=[](){});
        virtual void draw() const;
        virtual void handle(genv::event ev);
        virtual void log(ostream& logfile);
        virtual bool _is_pushed();
        virtual void _push();
        virtual void _set_action(function<void()> action);
};

#endif // BUTTON HPP INCLUDED
