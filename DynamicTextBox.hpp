#ifndef DYNAMICTEXTBOX_HPP_INCLUDED
#define DYNAMICTEXTBOX_HPP_INCLUDED

#include "graphics.hpp"
#include "widget.hpp"

using namespace std;

class DynamicTextBox : public Widget {
protected:
    string name;
public:
    DynamicTextBox(int x, int y, int sx, int sy, string S);
    virtual void draw() const ;
    virtual void handle(genv::event ev);
    virtual void new_name(genv::event ev);
    virtual void log(ostream& logfile);
    virtual string get_name();
    virtual string _mitortent();
};

#endif // TEXTBOX_HPP_INCLUDED
