#ifndef JATEKOS_HPP_INCLUDED
#define JATEKOS_HPP_INCLUDED

#include "Babu.hpp"
#include <vector>
#include "Window.hpp"

using namespace std;

class Babu;
class Mezo;


class Jatekos
{
private:
    string _name;
    string _szin;
    bool vesztettem;
    Window *_parent;
    vector< vector<Mezo *> > tabla;
public:
    vector<Babu *> babuim;
    Jatekos(string N,string szin, Window *P,vector< vector<Mezo *> > tabla);
    Babu* valasztott_babu;
    virtual Babu* van_rajta_babum(Mezo *mezo) const;
    virtual void leptem();
    virtual string get_name() const;
    virtual void set_name(string new_name);
    virtual int babuim_szama() const;
    virtual void kirajzol() const;
    virtual void leutott_babu(Babu *ez);
    virtual bool van_kiralyom();
};

#endif // JATEKOS_HPP_INCLUDED
