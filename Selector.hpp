// *** ADDED BY HEADER FIXUP ***
#include <istream>
// *** END ***
#ifndef SELECTOR_HPP_INCLUDED
#define SELECTOR_HPP_INCLUDED

#include "graphics.hpp"
#include "widget.hpp"
#include <vector>
#include <iostream>

using namespace std;
using namespace genv;

class Selector : public Widget
{
   protected:
        vector<string> v;
        int choice,from,height;
        bool opened,scrolled;
    public:
        Selector(int x, int y, int sx, int sy, int H, vector<string> choices);
        virtual void draw() const ;
        virtual void handle(genv::event ev);
        virtual void selection(event ev) ;
        virtual void new_choice(string text);
        virtual void log(ostream& logfile);
        virtual bool is_selected(int mouse_x, int mouse_y) const;
        virtual string _mitortent();
        virtual void del_chosen();
        virtual string get_chosen();
        virtual int get_choice();
        virtual void deselect();

};


#endif // SELECTOR_HPP_INCLUDED
