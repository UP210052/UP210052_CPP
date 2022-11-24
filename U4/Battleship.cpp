#include <iostream>

using namespace std;

char AreaJuegoP1[10][10];
char AreaJuegoP2[10][10];
const string P1 = "Player 1";
const string P2 = "Player 2";
string TipoBarco[5]={"Submarine","Destroyer","Cruiser","Battleship","Carrier"};

/*Carrier5,Battleship4,Cruiser3,Destroyer2-2,Submarine1-3*/

void tableronaval();
void imprimirtablerodeprueba();
void pruebalogica();
void logicbattleship();

void buildships(int, int, int, string);


void putships(int, int, int);
int selectplay(int, int);
bool checkplay(int);
void shootcannons(string, int);
void fuckship(string, int);
bool Winner();
int row, col;



int main()
{
    pruebalogica();
    return 0;
}

void tableronaval()
{

}

void pruebalogica()
{
    int barco, tipodebarco;
    string direccion;
    bool valida;
    cout << "Tipo de barco";
    cin >> tipodebarco;
    cout << "Direccion";
    cin >> direccion;
    cout << "En que fila vas a poner tu jugada";
    cin >> row;
    cout << "En que columna vas a poner tu jugada";
    cin >> col;
    cout << "";
    buildships(row, col, tipodebarco, direccion);
    imprimirtablerodeprueba();
}

void imprimirtablerodeprueba(){
    for (int i = 0; i < 10; i++)
    {
        cout << "\n";
        for (int j = 0; j < 10; j++)
        {
            cout << AreaJuegoP1[i][j];
        }
        
    }
    
}

void buildships(int row, int col, int barco,string direccion){
    if (direccion=="Arriba")
    {
        for (int row1 = 0; row1 < barco; row1++)
        {
            AreaJuegoP1[row1][col]={'O'};
        }
        
    }
    if (direccion=="Abajo")
    {
        for (int row1 = 0; row1 < barco; row1--)
        {
            AreaJuegoP1[row1][col]={'O'};
        }
        
    }
    if (direccion=="Izquierda")
    {
        for (int col1 = 0; col1 < barco; col1--)
        {
            AreaJuegoP1[row][col1]={'O'};
        }
        
    }
    if (direccion=="Derecha")
    {
    for (int col1 = 0; col1 < barco; col1++)
    {
        AreaJuegoP1[row][col1]={'O'};
    }
       
    }
}
