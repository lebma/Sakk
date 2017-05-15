#ifndef MYGAME_HPP_INCLUDED
#define MYGAME_HPP_INCLUDED

#include "StaticString.hpp"
#include "Window.hpp"
#include "Jatekos.hpp"

class MyGame : public Window
{
private:
    vector< vector<Mezo *> > tabla;
    bool valasztas_jon;
    StaticString *fejlec;
    Jatekos *player1;
    Jatekos *player2;
public:
    Jatekos *ki_jon;
    MyGame(int XX,int YY);
    virtual void set_name_1(string new_name);
    virtual void set_name_2(string new_name);
    virtual void event_loop();
    virtual bool get_valasztas_jon() const;
    virtual void set_valasztas_jon();
    virtual void set_ki_jon();
};
#endif // MYGAME_HPP_INCLUDED
