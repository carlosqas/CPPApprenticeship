#include <iostream>
#include <vector>

#include "Pilha.h"

using namespace std;


class Coordenada
{
public:
    Coordenada(int x=0, int y=0):x(x), y(y){}
    int getX(){return x;}
    void setX(int x){this->x = x;}
    int getY(){return y;}
    void setY(int y){this->y = y;}
    void setCoordenada(int x, int y){this->x = x; this->y = y;}

private:
    int x, y;

friend ostream& operator<<(ostream& out, Coordenada c)
{
    out << "(" << c.x << ", " << c.y << ")";
    return out;
}

friend bool operator!=(Coordenada a, Coordenada b)
{
    return ((a.x == b.x) && (a.y == b.y));
}

};

int main()
{
    //cout << labirinto[10][0]
    // Dimensões -> 20, 21 
    vector<string> labirinto = 
    {
	"XXXXXXXXXXXXXXXXXXXXX",
	"X     X     X     X X",
	"XX XX XXXXX X X X   X",
	"X   X       XXX XXX X",
	"X X X XXXXXXX   X   X",
	"X X   X   X X X   X X",
	"X XXXXX X X   XXXXX X",
	"X X     X XXX  X    X",
	"X X X X X   XX XX XXX",
	"X X XXX X X     X   X",
	"E X X X X XXXXX XXX X",
	"X     X X   X X X   X",
	"X XXXXX XXX X XXX X X",
	"X X       X X   X X X",
	"X   XXX X X XXX X X X",
	"XXX X X X X X X X XXX",
	"X X   X X   X   X   X",
	"X XXX XXXXXXXXX XXX X",
	"X                 X X",
	"XXXXXXXXXXXXXXXXXXXSX"
    };

    for(auto i:labirinto)
        cout << i << endl;


    return 0;
}