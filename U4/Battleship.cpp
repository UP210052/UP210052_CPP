#include <iostream>

using namespace std;

char AreaJuegoP1[10][10]={{'-', '-', '-', '-', '-', '-', '-', '-', '-', '-'}, {'-', '-', '-', '-', '-', '-', '-', '-', '-', '-'}, {'-', '-', '-', '-', '-', '-', '-', '-', '-', '-'}, {'-', '-', '-', '-', '-', '-', '-', '-', '-', '-'}, {'-', '-', '-', '-', '-', '-', '-', '-', '-', '-'}, {'-', '-', '-', '-', '-', '-', '-', '-', '-', '-'}, {'-', '-', '-', '-', '-', '-', '-', '-', '-', '-'}, {'-', '-', '-', '-', '-', '-', '-', '-', '-', '-'}, {'-', '-', '-', '-', '-', '-', '-', '-', '-', '-'}, {'-', '-', '-', '-', '-', '-', '-', '-', '-', '-'}};
char AreaJuegoP2[10][10]={{'-', '-', '-', '-', '-', '-', '-', '-', '-', '-'}, {'-', '-', '-', '-', '-', '-', '-', '-', '-', '-'}, {'-', '-', '-', '-', '-', '-', '-', '-', '-', '-'}, {'-', '-', '-', '-', '-', '-', '-', '-', '-', '-'}, {'-', '-', '-', '-', '-', '-', '-', '-', '-', '-'}, {'-', '-', '-', '-', '-', '-', '-', '-', '-', '-'}, {'-', '-', '-', '-', '-', '-', '-', '-', '-', '-'}, {'-', '-', '-', '-', '-', '-', '-', '-', '-', '-'}, {'-', '-', '-', '-', '-', '-', '-', '-', '-', '-'}, {'-', '-', '-', '-', '-', '-', '-', '-', '-', '-'}};
const string P1 = "Player 1";
const string P2 = "Player 2";
int col, row;
string TipoBarco[5]={"Submarine","Destroyer","Cruiser","Battleship","Carrier"};

/*Carrier5,Battleship4,Cruiser3,Destroyer2-2,Submarine1-3*/

void makeboard();

void tableronaval();
void imprimirtablerodeprueba();
void pruebalogica();
void logicbattleship();

void buildships(int, int, int, string);


void putships(int, int, int);
int selectplay(int, int);
bool checkplay(int, int, int);
void shootcannons(string, int);
void fuckship(string, int);
bool Winner();



int main()
{
    int col, row, player;
    bool placeOccupied = true;
    //makeboard();
    //preguntartipodebarco();
    //preguntarcordenada();
    //selectplay();
    // placeOccupied = checkplay (1, 2, 2);
    // cout << placeOccupied;
    //putships();
    //repetir las hasta poner todos los barcos por cada jugador
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

bool checkplay (int player, int move, int move2){
    for (int row = 0; row < 10; row++)
    {
        for (int col = 0; col < 10; col++)
        {
            if (player == 1){
                if (AreaJuegoP1[row][col] == 'O')
                {
                    return true;
                }
            }else if (player == 2){
                if (AreaJuegoP2[row][col] =='O')
                {
                    return true;
                }
            }
        }
        
    }
    return false;
}

void buildships(int row, int col, int barco,string direccion){
    if (direccion=="Arriba")
    {
        int contador=0;
        int row1=col;
        while (contador<barco)
        {
            AreaJuegoP1[row1][col]={'O'};
            row1--;
            contador++;
        }
        
    }
    if (direccion=="Abajo")
    {
        int contador=0;
        int row1=col;
        while (contador<barco)
        {
            AreaJuegoP1[row1][col]={'O'};
            row1++;
            contador++;
        }
        
    }
    if (direccion=="Izquierda")
    {
        int contador=0;
        int col1=row;
        while (contador < barco)
        {
            AreaJuegoP1[row][col1]={'O'};
            col1--;
            contador++;   
        }
        
    }
    if (direccion=="Derecha")
    {
        int contador=0;
        int col1=row;
        while (contador < barco)
        {
            AreaJuegoP1[row][col1]={'O'};
            col1++;
            contador++;   
        }
       
    }
}

/*int menuBarcos(){
    1 Submarine [1] (3)
    2 Destroyer [2] (2)
    3 Cruiser  [3]
    4 Battleship 
    5 Carrier
}
*/