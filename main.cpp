#include "graphics.hpp"
#include "widget.hpp"
#include "counter.hpp"
#include <vector>
#include "Selector.hpp"
#include <fstream>
#include "DynamicTextBox.hpp"
#include "Button.hpp"
#include "Window.hpp"
#include "Mezo.hpp"
#include "Jatekos.hpp"
#include "MyGame.hpp"
#include "StaticString.hpp"

using namespace genv;
using namespace std;

class PlayerMenu : public Window
{
protected:
    DynamicTextBox* player_name_1;
    DynamicTextBox* player_name_2;
    StaticString* player_1;
    StaticString* player_2;
public:
    Button* accept;
    Button* go_back;
    PlayerMenu(int XX,int YY)
    :Window(XX,YY)
    {
        player_1 = new StaticString(50,200-gout.cascent(),"Player 1 (red):");
        player_2 = new StaticString(350,200-gout.cascent(),"Player 2 (blue):");

        widgets.push_back(player_1);
        widgets.push_back(player_2);

        accept = new Button(200,350,200,60, "accept", this);
        go_back = new Button(200,450,200,60,"back",this);
        player_name_1 = new DynamicTextBox(25,200,250,40,"player 1");
        player_name_2 = new DynamicTextBox(325,200,250,40,"player 2");

        widgets.push_back(accept);
        widgets.push_back(go_back);
        widgets.push_back(player_name_1);
        widgets.push_back(player_name_2);
    }
    string get_name_1()
    {
        return player_name_1->get_name();
    }
    string get_name_2()
    {
        return player_name_2->get_name();
    }
};

class MainMenu : public Window
{
public:
    Button* game;
    Button* quit;
    MainMenu(int XX,int YY)
    :Window(XX,YY)
    {
        game = new Button(150,150,300,100, "play", this);
        quit = new Button(150,350,300,100, "exit", this);

        widgets.push_back(game);
        widgets.push_back(quit);
    }
};

int main()
{
    MainMenu *menu = new MainMenu(600,600);
    gout.open(menu->get_XX(),menu->get_YY());

    PlayerMenu *playermenu = new PlayerMenu(600,600);

    MyGame *mygame = new MyGame(600,600);
    gout.open(mygame->get_XX(),mygame->get_YY());

    menu->quit->_set_action([&](){
                            menu->_close();
                            });

    menu->game->_set_action([&](){
                            menu->_close();
                            playermenu->event_loop();
                            });

    playermenu->go_back->_set_action([&](){
                                     playermenu->_close();
                                     menu->event_loop();
                                     });
    playermenu->accept->_set_action([&](){
                                    mygame->set_name_1(playermenu->get_name_1());
                                    mygame->set_name_2(playermenu->get_name_2());
                                    playermenu->_close();
                                    mygame->event_loop();
                                     });

    menu->event_loop();

    return 0;
}
