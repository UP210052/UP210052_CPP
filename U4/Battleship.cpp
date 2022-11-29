#include <iostream>

using namespace std;

char AreaJuegoP1[10][10]={{'-', '-', '-', '-', '-', '-', '-', '-', '-', '-'}, {'-', '-', '-', '-', '-', '-', '-', '-', '-', '-'}, {'-', '-', '-', '-', '-', '-', '-', '-', '-', '-'}, {'-', '-', '-', '-', '-', '-', '-', '-', '-', '-'}, {'-', '-', '-', '-', '-', '-', '-', '-', '-', '-'}, {'-', '-', '-', '-', '-', '-', '-', '-', '-', '-'}, {'-', '-', '-', '-', '-', '-', '-', '-', '-', '-'}, {'-', '-', '-', '-', '-', '-', '-', '-', '-', '-'}, {'-', '-', '-', '-', '-', '-', '-', '-', '-', '-'}, {'-', '-', '-', '-', '-', '-', '-', '-', '-', '-'}};
char AreaJuegoP2[10][10]={{'-', '-', '-', '-', '-', '-', '-', '-', '-', '-'}, {'-', '-', '-', '-', '-', '-', '-', '-', '-', '-'}, {'-', '-', '-', '-', '-', '-', '-', '-', '-', '-'}, {'-', '-', '-', '-', '-', '-', '-', '-', '-', '-'}, {'-', '-', '-', '-', '-', '-', '-', '-', '-', '-'}, {'-', '-', '-', '-', '-', '-', '-', '-', '-', '-'}, {'-', '-', '-', '-', '-', '-', '-', '-', '-', '-'}, {'-', '-', '-', '-', '-', '-', '-', '-', '-', '-'}, {'-', '-', '-', '-', '-', '-', '-', '-', '-', '-'}, {'-', '-', '-', '-', '-', '-', '-', '-', '-', '-'}};
const string P1 = "Player 1";
const string P2 = "Player 2";
int player = 1;
int col, row;
string TipoBarco[5]={"Submarine","Destroyer","Cruiser","Battleship","Carrier"};
int TiposBarcosP1[5]={3,2,1,1,1};
int TiposBarcosP2[5]={3,2,1,1,1};


/*Carrier5,Battleship4,Cruiser3,Destroyer2-2,Submarine1-3*/

void gotoxy(int x, int y);

void makeboard();

void tableronaval();
void imprimirtablerodeprueba();
void pruebalogica();
void logicbattleship();
void actualizarInventarioBarcos(int, string);
void buildships(int, int, int, string,string);



string Jugador1A[23][23] =   {{" - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "},
                              {"|BN"," | "," A "," | "," B "," | "," C "," | "," D "," | "," E "," | "," F "," | "," G "," | "," H "," | "," I "," | "," J "," | "},
                              {" _ "," _ "," _ "," _ "," _ "," _ "," _ "," _ "," _ "," _ "," _ "," _ "," _ "," _ "," _ "," _ "," _ "," _ "," _ "," _ "," _ "," _ "},
                              {"| 0"," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | "},
                              {"| -"," | "," - "," | "," - "," | "," - "," | "," - "," | "," - "," | "," - "," | "," - "," | "," - "," | "," - "," | "," - "," | "},
                              {"| 1"," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | "},
                              {"| -"," | "," - "," | "," - "," | "," - "," | "," - "," | "," - "," | "," - "," | "," - "," | "," - "," | "," - "," | "," - "," | "},
                              {"| 2"," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | "},
                              {"| -"," | "," - "," | "," - "," | "," - "," | "," - "," | "," - "," | "," - "," | "," - "," | "," - "," | "," - "," | "," - "," | "},
                              {"| 3"," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | "},
                              {"| -"," | "," - "," | "," - "," | "," - "," | "," - "," | "," - "," | "," - "," | "," - "," | "," - "," | "," - "," | "," - "," | "},
                              {"| 4"," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | "},
                              {"| -"," | "," - "," | "," - "," | "," - "," | "," - "," | "," - "," | "," - "," | "," - "," | "," - "," | "," - "," | "," - "," | "},
                              {"| 5"," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | "},
                              {"| -"," | "," - "," | "," - "," | "," - "," | "," - "," | "," - "," | "," - "," | "," - "," | "," - "," | "," - "," | "," - "," | "},
                              {"| 6"," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | "},
                              {"| -"," | "," - "," | "," - "," | "," - "," | "," - "," | "," - "," | "," - "," | "," - "," | "," - "," | "," - "," | "," - "," | "},
                              {"| 7"," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | "},
                              {"| -"," | "," - "," | "," - "," | "," - "," | "," - "," | "," - "," | "," - "," | "," - "," | "," - "," | "," - "," | "," - "," | "},
                              {"| 8"," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | "},
                              {"| -"," | "," - "," | "," - "," | "," - "," | "," - "," | "," - "," | "," - "," | "," - "," | "," - "," | "," - "," | "," - "," | "},
                              {"| 9"," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | "},
                              {" - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "},};                         

void putships(int, int, int);
int selectplay(int, int);
/*Playertype, shipsize, row,col*/
bool invalidplay(int, int, int, string,string);
void shootcannons(int, int, string);
bool Winner();



int main()
{
    int col, row, player;
    bool placeOccupied = true;
    //tableronaval();
    //makeboard();
    //preguntartipodebarco();
    //preguntarcordenada();Cruiser--;s por cada jugador
    pruebalogica();
    return 0;
}


void tableronaval(){
    for (int row = 0; row < 23; row++)
    {
        cout << endl;
        for (int col = 0; col < 23; col++)
        {
           cout << Jugador1A[row][col];
        }  
    }
}


void pruebalogica()
{
    int tipodebarco;
    bool invalidmove;
    
    string direccion,currentturn;
    bool valida;
    do
    {
    if (player<=8)
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
        cout << "Invalidmove\n";
    } 
    else if (invalidmove == false)
    {
        player++;
        buildships(row, col, tipodebarco, direccion, currentturn);
        actualizarInventarioBarcos(tipodebarco, currentturn);
        imprimirtablerodeprueba();
    }
    }while (player<=16);
    player = 1;
    do
    {
    if (player%2==1)
    {
        currentturn = P1;
    } else {
        currentturn = P2;
    }
    cout << currentturn << endl;
    cout << "Row";
    cin >> row;
    cout << "Column";
    cin >> col;
    shootcannons(row, col, currentturn);
    imprimirtablerodeprueba();
    player++;
    } while (player>0);
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
        if (TiposBarcosP1[barco-1]==0){
        return true;
        }
    } else if (player == P2){
        if (TiposBarcosP2[barco-1]==0){
        return true;
        }
    }
    
    
    if (direccion=="Arriba")
    {
        int contador=0;
        int row1=row;
        if (row<(barco-1)){
            return true;
        }
        while (contador<barco)
        {
            if (player == P1){
                if (AreaJuegoP1[row1][col]=='O'){
                return true;
                }
            } else if  (player == P2){
                if (AreaJuegoP2[row1][col]=='O'){
                return true;
                }
            } 
            row1--;
            contador++;
        }
        
    }
    if (direccion=="Abajo")
    {
        int contador=0;
        int row1=row;
        if ((row+barco)>10){
            return true;
        }
        while (contador<barco)
        {
            if (player == P1){
                if (AreaJuegoP1[row1][col]=='O'){
                return true;
                }
            } else if  (player == P2){
                if (AreaJuegoP2[row1][col]=='O'){
                return true;
                }
            }  
            row1++;
            contador++;
        }
        
    }
    if (direccion=="Izquierda")
    {
        int contador=0;
        int col1=col;
        if ((col-barco) < -1)
        {
            return true;
        }
        while (contador < barco)
        {
            if (player == P1){
                if (AreaJuegoP1[row][col1]=='O'){
                return true;
                }
            } else if (player == P2){
                if (AreaJuegoP2[row][col1]=='O'){
                return true;
                }
            }
            col1--;
            contador++;   
        }
        
    }
    if (direccion=="Derecha")
    {
        int contador=0;
        int col1=col;
        if ((col+barco)>10)
        {
            return true;
        }
        
        while (contador < barco)
        {
            if (player == P1){
                if (AreaJuegoP1[row][col1]=='O'){
                return true;
                }
            } else if (player == P2){
                if (AreaJuegoP2[row][col1]=='O'){
                return true;
                }
            }
            col1++;
            contador++;   
        }
       
    }
    return false;
}

void buildships(int row, int col, int barco,string direccion, string player){
    if (direccion=="Arriba")
    {
        int contador=0;
        int row1=row;
        while (contador<barco)
        {
            if (player== P1){
                AreaJuegoP1[row1][col]={'O'};
            }
            else if (player == P2){
                AreaJuegoP2[row1][col]={'O'};
            }
            row1--;
            contador++;
        }
        
    }
    if (direccion=="Abajo")
    {
        int contador=0;
        int row1=row;
        while (contador<barco)
        {
            if (player== P1){
                AreaJuegoP1[row1][col]={'O'};
            }
            else if (player == P2){
                AreaJuegoP2[row1][col]={'O'};
            }
            row1++;
            contador++;
        }
        
    }
    if (direccion=="Izquierda")
    {
        int contador=0;
        int col1=col;
        while (contador < barco)
        {
            if (player== P1){
                AreaJuegoP1[row][col1]={'O'};
            }
            else if (player == P2){
                AreaJuegoP2[row][col1]={'O'};
            }
            col1--;
            contador++;   
        }
        
    }
    if (direccion=="Derecha")
    {
        int contador=0;
        int col1=col;
        while (contador < barco)
        {
            if (player== P1){
                AreaJuegoP1[row][col1]={'O'};
            }
            else if (player == P2){
                AreaJuegoP2[row][col1]={'O'};
            }
            col1++;
            contador++;   
        }
       
    }
}


void gotoxy(int x, int y){
    cout << "\033[" << y << ";" << x << "f";
}

void actualizarInventarioBarcos(int barco, string player){
    if (barco==1)
    {
        if (player== P1){
            TiposBarcosP1[0]--;
        } else if (player == P2){
            TiposBarcosP2[0]--;
        }
        
    }else if (barco == 2)
    {
        if (player== P1){
            TiposBarcosP1[1]--;
        } else if (player == P2){
            TiposBarcosP2[1]--;
        }
    }else if (barco == 3)
    {
        if (player== P1){
            TiposBarcosP1[2]--;
        } else if (player == P2){
            TiposBarcosP2[2]--;
        }
    }else if (barco == 4)
    {
        if (player== P1){
            TiposBarcosP1[3]--;
        } else if (player == P2){
            TiposBarcosP2[3]--;
        }
    }else if (barco == 5){
        if (player== P1){
            TiposBarcosP1[4]--;
        } else if (player == P2){
            TiposBarcosP2[4]--;
        }
    }
}

void shootcannons(int row, int col, string player){
    if (player==P1)
    {
        if (AreaJuegoP2[row][col]=='O')
        {
            AreaJuegoP2[row][col]={'X'};
        }
        
    } else if(player==P2){
        if (AreaJuegoP1[row][col]=='O')
        {
            AreaJuegoP1[row][col]={'X'};
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
