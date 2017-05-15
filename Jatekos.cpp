#include "Jatekos.hpp"
#include "Paraszt.hpp"
#include "Bastya.hpp"
#include "Lo.hpp"
#include "Futo.hpp"
#include "Kiraly.hpp"
#include "Kiralyno.hpp"
#include "graphics.hpp"

using namespace genv;
using namespace std;

Jatekos::Jatekos(string N,string szin,Window *P,vector< vector<Mezo *> > T)
{
    vesztettem=false;
    tabla=T;
    _name=N;
    _parent=P;
    _szin=szin;
    vector<Babu *> B;
    if (_szin=="fekete")
    {
        valasztott_babu = 0;
        for (int i=0; i<8; i++)
        {
            Paraszt *paraszt = new Paraszt(tabla[1][i],1);
            B.push_back(paraszt);
        }
        babuim=B;

        Bastya *bastya1 = new Bastya(tabla[0][0]);
        Bastya *bastya2 = new Bastya (tabla[0][7]);
        babuim.push_back(bastya1);
        babuim.push_back(bastya2);

        Lo *lo1 = new Lo(tabla[0][1]);
        Lo *lo2 = new Lo(tabla[0][6]);
        babuim.push_back(lo1);
        babuim.push_back(lo2);

        Futo *futo1 = new Futo(tabla[0][2]);
        Futo *futo2 = new Futo(tabla[0][5]);
        babuim.push_back(futo1);
        babuim.push_back(futo2);

        Kiralyno *kiralyno = new Kiralyno(tabla[0][3]);

        Kiraly *kiraly = new Kiraly(tabla[0][4]);
        babuim.push_back(kiraly);
        babuim.push_back(kiralyno);
    }
    else
    {
        for (int i=0; i<8; i++)
        {
            Paraszt *paraszt = new Paraszt(tabla[6][i],-1);
            B.push_back(paraszt);
        }
        babuim=B;

        Bastya *bastya1 = new Bastya(tabla[7][0]);
        Bastya *bastya2 = new Bastya (tabla[7][7]);
        babuim.push_back(bastya1);
        babuim.push_back(bastya2);

        Lo *lo1 = new Lo(tabla[7][1]);
        Lo *lo2 = new Lo(tabla[7][6]);
        babuim.push_back(lo1);
        babuim.push_back(lo2);

        Futo *futo1 = new Futo(tabla[7][2]);
        Futo *futo2 = new Futo(tabla[7][5]);
        babuim.push_back(futo1);
        babuim.push_back(futo2);


        Kiralyno *kiralyno = new Kiralyno(tabla[7][3]);

        Kiraly *kiraly = new Kiraly(tabla[7][4]);
        babuim.push_back(kiraly);
        babuim.push_back(kiralyno);
    }
    valasztott_babu = 0;
}

void Jatekos::leptem()
{
}

Babu* Jatekos::van_rajta_babum(Mezo *mezo) const
{
    for (int i=0; i<babuim.size(); i++)
    {
        if (babuim[i]->get_x()==mezo->get_x() && babuim[i]->get_y()==mezo->get_y())
        {
            return babuim[i];
        }
    }
    return 0;
}

string Jatekos::get_name() const
{
    return _name;
}

int Jatekos::babuim_szama() const
{
    return babuim.size();
}

void Jatekos::set_name(string new_name)
{
    _name=new_name;
}

void Jatekos::kirajzol() const
{
    if (_szin=="feher") gout << color(50,50,255);
    else gout << color(255,50,50);
    for (int i=0; i<babuim.size(); i++)
    {
        babuim[i]->draw();
    }
}

void Jatekos::leutott_babu(Babu *ez)
{
    if (ez!=babuim[babuim.size()-1])
    {
        int a=0;
        for(int i=0; i<babuim.size()-1; i++)
        {
            if (babuim[i]==ez) a=i;
        }
        for(int i=a; i<babuim.size()-1; i++)
        {
            babuim[i]=babuim[i+1];
        }
    }
    babuim.pop_back();
}

bool Jatekos::van_kiralyom()
{
    bool van=false;
    for (int i=0; i<babuim.size(); i++)
    {
        if (babuim[i]->kiraly_vagyok()) van=true;
    }
    return van;
}
