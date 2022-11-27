#include <iostream>

using namespace std;

char AreaJuegoP1[10][10]={{'-', '-', '-', '-', '-', '-', '-', '-', '-', '-'}, {'-', '-', '-', '-', '-', '-', '-', '-', '-', '-'}, {'-', '-', '-', '-', '-', '-', '-', '-', '-', '-'}, {'-', '-', '-', '-', '-', '-', '-', '-', '-', '-'}, {'-', '-', '-', '-', '-', '-', '-', '-', '-', '-'}, {'-', '-', '-', '-', '-', '-', '-', '-', '-', '-'}, {'-', '-', '-', '-', '-', '-', '-', '-', '-', '-'}, {'-', '-', '-', '-', '-', '-', '-', '-', '-', '-'}, {'-', '-', '-', '-', '-', '-', '-', '-', '-', '-'}, {'-', '-', '-', '-', '-', '-', '-', '-', '-', '-'}};
char AreaJuegoP2[10][10]={{'-', '-', '-', '-', '-', '-', '-', '-', '-', '-'}, {'-', '-', '-', '-', '-', '-', '-', '-', '-', '-'}, {'-', '-', '-', '-', '-', '-', '-', '-', '-', '-'}, {'-', '-', '-', '-', '-', '-', '-', '-', '-', '-'}, {'-', '-', '-', '-', '-', '-', '-', '-', '-', '-'}, {'-', '-', '-', '-', '-', '-', '-', '-', '-', '-'}, {'-', '-', '-', '-', '-', '-', '-', '-', '-', '-'}, {'-', '-', '-', '-', '-', '-', '-', '-', '-', '-'}, {'-', '-', '-', '-', '-', '-', '-', '-', '-', '-'}, {'-', '-', '-', '-', '-', '-', '-', '-', '-', '-'}};
const string P1 = "Player 1";
const string P2 = "Player 2";
int player = 1;
int col, row;
string TipoBarco[5]={"Submarine","Destroyer","Cruiser","Battleship","Carrier"};

/*Carrier5,Battleship4,Cruiser3,Destroyer2-2,Submarine1-3*/

void gotoxy(int x, int y);

void makeboard();

void tableronaval();
void imprimirtablerodeprueba();
void pruebalogica();
void logicbattleship();

void buildships(int, int, int, string,string);


void putships(int, int, int);
int selectplay(int, int);
/*Playertype, shipsize, row,col*/
bool invalidplay(int, int, int, string,string);
void shootcannons(string, int);
void destroyship(string, int);
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
    bool invalidmove;
    
    string direccion,currentturn;
    bool valida;
    do
    {
    if (player%2==1)
    {
        currentturn = P1;
    } else {
        currentturn = P2;
    }
    cout << "Its " << currentturn << " turn, select your move\n";
    cout << "Shipsize:";
    cin >> tipodebarco;
    cout << "Direccion (Arriba,Abajo,Izquierda,Derecha):";
    cin >> direccion;
    cout << "Row(FILA):";
    cin >> row;
    cout << "Col(COLUMNA):";
    cin >> col;
    invalidmove = invalidplay(row, col, tipodebarco, direccion, currentturn);
    if (invalidmove == true)
    {
        cout << "Invalidmove";
    } 
    else if (invalidmove == false)
    {
        player++;
        buildships(row, col, tipodebarco, direccion, currentturn);
        imprimirtablerodeprueba();
    }
    
    
    }while (player>0);
    
}

void imprimirtablerodeprueba(){
    for (int i = 0; i < 10; i++)
    {
        gotoxy(20,20);
        for (int j = 0; j < 10; j++)
        {
            cout << AreaJuegoP1[i][j];
        }
        gotoxy(40,20);
        for (int j = 0; j < 10; j++)
        {
            cout << AreaJuegoP2[i][j];
        }
        
        cout << "\n";
    }
    
}

bool invalidplay (int row, int col, int barco,string direccion, string player){
    if (player == P1){
    if (direccion=="Arriba")
    {
        int contador=0;
        int row1=col;
        while (contador<barco)
        {
            if (AreaJuegoP1[row1][col]=='O'){
                return true;
            };
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
            if (AreaJuegoP1[row1][col]=='O'){
                return true;
            };
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
            if (AreaJuegoP1[row][col1]=='O'){
                return true;
            };
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
            if (AreaJuegoP1[row][col1]=='O'){
                return true;
            };
            col1++;
            contador++;   
        }
       
    }
    }
    //Player 2
    if (player == P2){
    if (direccion=="Arriba")
    {
        int contador=0;
        int row1=col;
        while (contador<barco)
        {
            if (AreaJuegoP2[row1][col]=='O'){
                return true;
            };
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
            if (AreaJuegoP2[row1][col]=='O'){
                return true;
            };
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
            if (AreaJuegoP2[row][col1]=='O'){
                return true;
            };
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
            if (AreaJuegoP2[row][col1]=='O'){
                return true;
            };
            col1++;
            contador++;   
        }
       
    }
    }
    return false;
}

void buildships(int row, int col, int barco,string direccion, string player){
    if (player == P1){
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
    //Player 2
    if (player == P2){
    if (direccion=="Arriba")
    {
        int contador=0;
        int row1=col;
        while (contador<barco)
        {
            AreaJuegoP2[row1][col]={'O'};
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
            AreaJuegoP2[row1][col]={'O'};
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
            AreaJuegoP2[row][col1]={'O'};
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
            AreaJuegoP2[row][col1]={'O'};
            col1++;
            contador++;   
        }
       
    }
    }
}


void gotoxy(int x, int y){
    cout << "\033[" << y << ";" << x << "f";
}

/*int menuBarcos(){
    1 Submarine [1] (3)
    2 Destroyer [2] (2)
    3 Cruiser  [3]
    4 Battleship 
    5 Carrier
}
*/