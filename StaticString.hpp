#ifndef STATICSTRING_HPP_INCLUDED
#define STATICSTRING_HPP_INCLUDED

#include "widget.hpp"
using namespace std;

class StaticString : public Widget
{
    protected:
        string _nev;
    public:
        StaticString(int x, int y, string N);
        virtual void draw() const;
        virtual void log(ostream& logfile);
        virtual void uj_nev(string valami);
        virtual string get_name() const;
};

#endif // STATICSTRING_HPP_INCLUDED
