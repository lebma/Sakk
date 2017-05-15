#include "MyGame.hpp"
#include "graphics.hpp"
#include <vector>

using namespace genv;
using namespace std;

MyGame::MyGame(int XX,int YY)
    :Window(XX,YY)
    {
        valasztas_jon=true;
        vector< vector<Mezo *> > T;
        for(int i=0;i<8;i++)
        {
            vector<Mezo *> t;
            for(int j=0;j<8;j++)
            {
                Mezo * mezo=new Mezo(i,j,50);
                t.push_back(mezo);
                widgets.push_back(mezo);
            }
            T.push_back(t);
        }
        tabla=T;
        player1 = new Jatekos("Player 1","fekete",this,tabla);
        player2 = new Jatekos("Player 2","feher",this,tabla);
        ki_jon = player1;
        fejlec = new StaticString(300-gout.twidth("player 1's turn")/2,50,ki_jon->get_name()+"'s turn");
        widgets.push_back(fejlec);
    }

void MyGame::set_name_1(string new_name)
{
    player1 -> set_name(new_name);
    fejlec->uj_nev(new_name+"'s turn");
}
void MyGame::set_name_2(string new_name)
{
    player2->set_name(new_name);
}
void MyGame::event_loop()
{
    _opened=true;
    event ev;
    int focus = -1;
    for (int i=0; i<ki_jon->babuim.size(); i++)
    {
        player1->babuim[i]->elfoglal();
        player2->babuim[i]->elfoglal();
    }
    while(_opened && gin >> ev && ev.keycode!=key_escape && player1->van_kiralyom() && player2->van_kiralyom()) {
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
        if(ev.pos_x>=100 && ev.pos_x<=500 && ev.pos_y>=100 && ev.pos_y<=500 && ev.button==btn_left){
            if (!valasztas_jon && ki_jon->valasztott_babu->lephetek_e(tabla[ev.pos_x/50-2][ev.pos_y/50-2]))
            {
                ki_jon->valasztott_babu->elhagy();
                ki_jon->valasztott_babu->lep(tabla[ev.pos_x/50-2][ev.pos_y/50-2]);
                ki_jon->valasztott_babu->elfoglal();
                tabla[ev.pos_x/50-2][ev.pos_y/50-2]->deselect();

                set_valasztas_jon();
                ki_jon->valasztott_babu = 0;
                set_ki_jon();

                if(ki_jon->van_rajta_babum(tabla[ev.pos_x/50-2][ev.pos_y/50-2])!=0)
                {
                    ki_jon->leutott_babu(ki_jon->van_rajta_babum(tabla[ev.pos_x/50-2][ev.pos_y/50-2]));
                }

                fejlec->uj_nev(ki_jon->get_name()+"'s turn");
            }
            else if(!valasztas_jon && ev.pos_x/50-2==ki_jon->valasztott_babu->get_x() && ev.pos_y/50-2==ki_jon->valasztott_babu->get_y())
            {
                ki_jon->valasztott_babu=0;
                set_valasztas_jon();
            }
            else if(valasztas_jon && ki_jon->van_rajta_babum(tabla[ev.pos_x/50-2][ev.pos_y/50-2]))
            {
                ki_jon->valasztott_babu = ki_jon->van_rajta_babum(tabla[ev.pos_x/50-2][ev.pos_y/50-2]);
                if(ki_jon->valasztott_babu!=0) set_valasztas_jon();
                tabla[ev.pos_x/50-2][ev.pos_y/50-2]->handle(ev);
            }
        }
        for (size_t i=0;i<widgets.size();i++) {
            widgets[i]->draw();
        }
        player1->kirajzol();
        player2->kirajzol();
        gout << refresh;
        gout << move_to(0,0) << color(50,50,50) << box(_XX,_YY);
    }
}


bool MyGame::get_valasztas_jon() const
{
    return valasztas_jon;
}

void MyGame::set_valasztas_jon()
{
    valasztas_jon=!valasztas_jon;
}

void MyGame::set_ki_jon()
{
    if(ki_jon==player1) ki_jon=player2;
    else ki_jon=player1;
}
