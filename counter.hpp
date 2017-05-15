#ifndef COUNTER_HPP_INCLUDED
#define COUNTER_HPP_INCLUDED

#include "graphics.hpp"
#include "widget.hpp"

class Counter : public Widget {
    protected:
        int n, _max, _min;
    public:
        Counter(int x, int y, int sx, int sy, int Max, int Min, int N);
        virtual void draw() const ;
        virtual void handle(genv::event ev);
        virtual void counting(int diff) ;
        virtual void log(ostream& logfile);
        virtual string _mitortent();
        virtual int get_number();
};

#endif // COUNTER_HPP_INCLUDED
