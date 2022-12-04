#include <iostream>
#include <unistd.h>
//#include <vistas.h>

using namespace std;

string AreaJuegoP1[10][10] = {{"-", "-", "-", "-", "-", "-", "-", "-", "-", "-"}, {"-", "-", "-", "-", "-", "-", "-", "-", "-", "-"}, {"-", "-", "-", "-", "-", "-", "-", "-", "-", "-"}, {"-", "-", "-", "-", "-", "-", "-", "-", "-", "-"}, {"-", "-", "-", "-", "-", "-", "-", "-", "-", "-"}, {"-", "-", "-", "-", "-", "-", "-", "-", "-", "-"}, {"-", "-", "-", "-", "-", "-", "-", "-", "-", "-"}, {"-", "-", "-", "-", "-", "-", "-", "-", "-", "-"}, {"-", "-", "-", "-", "-", "-", "-", "-", "-", "-"}, {"-", "-", "-", "-", "-", "-", "-", "-", "-", "-"}};
string AreaJuegoP2[10][10] = {{"-", "-", "-", "-", "-", "-", "-", "-", "-", "-"}, {"-", "-", "-", "-", "-", "-", "-", "-", "-", "-"}, {"-", "-", "-", "-", "-", "-", "-", "-", "-", "-"}, {"-", "-", "-", "-", "-", "-", "-", "-", "-", "-"}, {"-", "-", "-", "-", "-", "-", "-", "-", "-", "-"}, {"-", "-", "-", "-", "-", "-", "-", "-", "-", "-"}, {"-", "-", "-", "-", "-", "-", "-", "-", "-", "-"}, {"-", "-", "-", "-", "-", "-", "-", "-", "-", "-"}, {"-", "-", "-", "-", "-", "-", "-", "-", "-", "-"}, {"-", "-", "-", "-", "-", "-", "-", "-", "-", "-"}};
int TiposBarcosP1[5] = {3, 2, 1, 1, 1};
int TiposBarcosP2[5] = {3, 2, 1, 1, 1};
string TipoBarco[5] = {"Submarine", "Destroyer", "Cruiser", "Battleship", "Carrier"};
string Jugador1A[14][23] = {
    {" - ", " - ", " - ", " - ", " - ", " - ", " - ", " - ", " - ", " - ", " - ", " - ", " - ", " - ", " - ", " - ", " - ", " - ", " - ", " - ", " - ", " - "},
    {"|BN", " | ", " A ", " | ", " B ", " | ", " C ", " | ", " D ", " | ", " E ", " | ", " F ", " | ", " G ", " | ", " H ", " | ", " I ", " | ", " J ", " | "},
    {" _ ", " _ ", " _ ", " _ ", " _ ", " _ ", " _ ", " _ ", " _ ", " _ ", " _ ", " _ ", " _ ", " _ ", " _ ", " _ ", " _ ", " _ ", " _ ", " _ ", " _ ", " _ "},
    {"| 0", " | ", "   ", " | ", "   ", " | ", "   ", " | ", "   ", " | ", "   ", " | ", "   ", " | ", "   ", " | ", "   ", " | ", "   ", " | ", "   ", " | "},
    {"| 1", " | ", "   ", " | ", "   ", " | ", "   ", " | ", "   ", " | ", "   ", " | ", "   ", " | ", "   ", " | ", "   ", " | ", "   ", " | ", "   ", " | "},
    {"| 2", " | ", "   ", " | ", "   ", " | ", "   ", " | ", "   ", " | ", "   ", " | ", "   ", " | ", "   ", " | ", "   ", " | ", "   ", " | ", "   ", " | "},
    {"| 3", " | ", "   ", " | ", "   ", " | ", "   ", " | ", "   ", " | ", "   ", " | ", "   ", " | ", "   ", " | ", "   ", " | ", "   ", " | ", "   ", " | "},
    {"| 4", " | ", "   ", " | ", "   ", " | ", "   ", " | ", "   ", " | ", "   ", " | ", "   ", " | ", "   ", " | ", "   ", " | ", "   ", " | ", "   ", " | "},
    {"| 5", " | ", "   ", " | ", "   ", " | ", "   ", " | ", "   ", " | ", "   ", " | ", "   ", " | ", "   ", " | ", "   ", " | ", "   ", " | ", "   ", " | "},
    {"| 6", " | ", "   ", " | ", "   ", " | ", "   ", " | ", "   ", " | ", "   ", " | ", "   ", " | ", "   ", " | ", "   ", " | ", "   ", " | ", "   ", " | "},
    {"| 7", " | ", "   ", " | ", "   ", " | ", "   ", " | ", "   ", " | ", "   ", " | ", "   ", " | ", "   ", " | ", "   ", " | ", "   ", " | ", "   ", " | "},
    {"| 8", " | ", "   ", " | ", "   ", " | ", "   ", " | ", "   ", " | ", "   ", " | ", "   ", " | ", "   ", " | ", "   ", " | ", "   ", " | ", "   ", " | "},
    {"| 9", " | ", "   ", " | ", "   ", " | ", "   ", " | ", "   ", " | ", "   ", " | ", "   ", " | ", "   ", " | ", "   ", " | ", "   ", " | ", "   ", " | "},
    {" - ", " - ", " - ", " - ", " - ", " - ", " - ", " - ", " - ", " - ", " - ", " - ", " - ", " - ", " - ", " - ", " - ", " - ", " - ", " - ", " - ", " - "},
};

string Jugador2A[14][23] = {
    {" - ", " - ", " - ", " - ", " - ", " - ", " - ", " - ", " - ", " - ", " - ", " - ", " - ", " - ", " - ", " - ", " - ", " - ", " - ", " - ", " - ", " - "},
    {"|BN", " | ", " A ", " | ", " B ", " | ", " C ", " | ", " D ", " | ", " E ", " | ", " F ", " | ", " G ", " | ", " H ", " | ", " I ", " | ", " J ", " | "},
    {" _ ", " _ ", " _ ", " _ ", " _ ", " _ ", " _ ", " _ ", " _ ", " _ ", " _ ", " _ ", " _ ", " _ ", " _ ", " _ ", " _ ", " _ ", " _ ", " _ ", " _ ", " _ "},
    {"| 0", " | ", "   ", " | ", "   ", " | ", "   ", " | ", "   ", " | ", "   ", " | ", "   ", " | ", "   ", " | ", "   ", " | ", "   ", " | ", "   ", " | "},
    {"| 1", " | ", "   ", " | ", "   ", " | ", "   ", " | ", "   ", " | ", "   ", " | ", "   ", " | ", "   ", " | ", "   ", " | ", "   ", " | ", "   ", " | "},
    {"| 2", " | ", "   ", " | ", "   ", " | ", "   ", " | ", "   ", " | ", "   ", " | ", "   ", " | ", "   ", " | ", "   ", " | ", "   ", " | ", "   ", " | "},
    {"| 3", " | ", "   ", " | ", "   ", " | ", "   ", " | ", "   ", " | ", "   ", " | ", "   ", " | ", "   ", " | ", "   ", " | ", "   ", " | ", "   ", " | "},
    {"| 4", " | ", "   ", " | ", "   ", " | ", "   ", " | ", "   ", " | ", "   ", " | ", "   ", " | ", "   ", " | ", "   ", " | ", "   ", " | ", "   ", " | "},
    {"| 5", " | ", "   ", " | ", "   ", " | ", "   ", " | ", "   ", " | ", "   ", " | ", "   ", " | ", "   ", " | ", "   ", " | ", "   ", " | ", "   ", " | "},
    {"| 6", " | ", "   ", " | ", "   ", " | ", "   ", " | ", "   ", " | ", "   ", " | ", "   ", " | ", "   ", " | ", "   ", " | ", "   ", " | ", "   ", " | "},
    {"| 7", " | ", "   ", " | ", "   ", " | ", "   ", " | ", "   ", " | ", "   ", " | ", "   ", " | ", "   ", " | ", "   ", " | ", "   ", " | ", "   ", " | "},
    {"| 8", " | ", "   ", " | ", "   ", " | ", "   ", " | ", "   ", " | ", "   ", " | ", "   ", " | ", "   ", " | ", "   ", " | ", "   ", " | ", "   ", " | "},
    {"| 9", " | ", "   ", " | ", "   ", " | ", "   ", " | ", "   ", " | ", "   ", " | ", "   ", " | ", "   ", " | ", "   ", " | ", "   ", " | ", "   ", " | "},
    {" - ", " - ", " - ", " - ", " - ", " - ", " - ", " - ", " - ", " - ", " - ", " - ", " - ", " - ", " - ", " - ", " - ", " - ", " - ", " - ", " - ", " - "},
};
const string P1 = "Player 1";
const string P2 = "Player 2";
const string ADDBOATS = "Board whit ships";
const string NOBOATS = "Board without ships";
int player = 1;
int col, row;
char columna;

void gotoxy(int, int);
void mostrarmensajeinicio();
void dibujo();
void tableronaval(string, string);
void imprimirtablerodeprueba();
void pruebalogica();
void pruebafrontend();
void menuBarcos(string);
void ponerbarcos();
void dispararbarcos();
bool invalidplay(int, int, int, int, string);
void buildships(int, int, int, int, string);
void actualizarInventarioBarcos(int, string);
void shootcannons(int, int, string);
bool novalidshoot(int, int, string);
bool NoWinner(string);
int LettertoNumber(char);
void Printshipinventory(string);
void dibujo2();


int main()
{
    //dibujo();
    //pruebafrontend();
    //pruebalogica();
    dispararbarcos();
    return 0;
}

// Frontend
void gotoxy(int x, int y)
{
    cout << "\033[" << y << ";" << x << "f";
}

void mostrarmensajeinicio()
{
    int entrada;
    dibujo();
    gotoxy(58, 20);
    cout << "BIENVENIDO A BATALLA NAVAL";

    gotoxy(66, 24);
    cout << "Presione: " << endl;
    gotoxy(66, 25);
    cout << "1. Jugar" << endl;
    gotoxy(66, 26);
    cout << "2. Salir" << endl;
}

void dibujo2(){
    system("cls");
    gotoxy(80, 2);
    cout << "                         ____   _   _           \n";
    gotoxy(80, 3);
    cout << "                        |____| |_| |_|          \n";
    gotoxy(80, 4);
    cout << "                        |  O | | | | |          \n";
    gotoxy(80, 5);
    cout << "                    _   |  S | | | | |          \n";
    gotoxy(80, 6);
    cout << "                   |_|  |  C |_|_|_|_|_         \n ";
    gotoxy(80, 7);
    cout << "                   | |  |  A | o o o o |        \n";
    gotoxy(80, 8);
    cout << "                   | |  |  R |---------|         \n";
    gotoxy(80, 9);
    cout << "                ___| |__|____|_________|___      \n";
    gotoxy(80, 10);
    cout << "                \\         VICENTE         /     \n";
    gotoxy(80, 11);
    cout << "                 \\   o o o o o o o o o o /      \n";
    gotoxy(80, 12);
    cout << "                  \\---------------------/       \n";
    gotoxy(80, 13);
    cout << "                   \\      HECTOR       /        \n";
    gotoxy(80, 14);
    cout << "                    \\_________________/         \n";
    gotoxy(103, 16);
    cout << "BATALLA NAVAL \n";
    cout << "\n";
}

void dibujo()
{
    system("cls");
    gotoxy(0, 2);
    cout << "                                                            ____   _   _           \n";
    gotoxy(0, 3); 
    cout << "                                                           |____| |_| |_|          \n";
    gotoxy(0, 4);
    cout << "                                                           |    | | | | |          \n";
    gotoxy(0, 5);
    cout << "                                                       _   |    | | | | |          \n";
    gotoxy(0, 6);
    cout << "                                                      |_|  |    |_|_|_|_|_         \n ";
    gotoxy(0, 7);
    cout << "                                                      | |  |    | o o o o |        \n";
    gotoxy(0, 8);
    cout << "                                                      | |  |    |---------|         \n";
    gotoxy(0, 9);
    cout << "                                                   ___| |__|____|_________|___     \n";
    gotoxy(0, 10);
    cout << "                                                   \\                         /    \n";
    gotoxy(0, 11);
    cout << "                                                    \\   o o o o o o o o o o /     \n";
    gotoxy(0, 12);
    cout << "                                                     \\---------------------/                                               \n";
    gotoxy(0, 13);
    cout << "******************************************************\\                   /***********************************************************************\n";
    gotoxy(0, 14);
    cout << "*******************************************************\\_________________/************************************************************************\n";
    gotoxy(0, 15);
    cout << "**************************************************************************************************************************************************\n";
    cout << "\n";
}

void tableronaval(string player, string mode)
{
    int x = 0, y = 0;

    for (int rowJ = 0; rowJ <= 9; rowJ++)
    {
        for (int colJ = 0; colJ <= 9; colJ++)
        {
            Jugador1A[rowJ + 3][2 * colJ + 2] = ' ' + AreaJuegoP1[rowJ][colJ] + ' ';
        }
    }
    for (int rowJ = 0; rowJ <= 9; rowJ++)
    {
        for (int colJ = 0; colJ <= 9; colJ++)
        {
            Jugador2A[rowJ + 3][2 * colJ + 2] = ' ' + AreaJuegoP2[rowJ][colJ] + ' ';
        }
    }


    for (int row = 0; row < 14; row++)
    {

        cout << endl;
        if (player == P1)
        {
            if (mode == ADDBOATS){
                gotoxy(55, 20 + row);
            }
            if(mode == NOBOATS){
                gotoxy(2, 5 + row);
            }
            for (int col = 0; col < 23; col++)
            {
                if (mode == ADDBOATS){
                    cout << Jugador1A[row][col];
                } else if (mode == NOBOATS){
                    if (Jugador1A[row][col]== " O "){
                        cout << " - ";
                    }else{
                        cout << Jugador1A[row][col];
                    }
                }
            }
        }
        else
        {
            if (mode == ADDBOATS){
                gotoxy(55, 20 + row);
            }
            if(mode == NOBOATS){
                gotoxy(2, 23 + row);
            }
            for (int col = 0; col < 23; col++)
            {
                if (mode == ADDBOATS){
                    cout << Jugador2A[row][col];
                } else if (mode == NOBOATS){
                    
                    if (Jugador2A[row][col]== " O "){
                        cout << " - ";
                    }else{
                        cout << Jugador2A[row][col];
                    }
                }
            }
        }

    }
}

void imprimirtablerodeprueba()
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cout << AreaJuegoP1[i][j];
        }
        for (int j = 0; j < 10; j++)
        {
            cout << AreaJuegoP2[i][j];
        }

        cout << "\n";
    }
}

void menuBarcos(string turnplayer){

    gotoxy(5, 19);
    cout << "Submarine [1 Posicion] (";
    if(turnplayer == P1){
        cout << TiposBarcosP1[0];
    }else if(turnplayer == P2){
        cout << TiposBarcosP2[0];
    }
    cout << " Submariene)" << endl;

    gotoxy(5, 20);
    cout << "Destroyer [2 Posiciones] (";
    if(turnplayer == P1){
        cout << TiposBarcosP1[1];
    }else if(turnplayer == P2){
        cout << TiposBarcosP2[1];
    }
    cout << " Destroyers)" << endl;

    gotoxy(5, 21);
    cout << "Cruiser  [3 Posiciones] (";
    if(turnplayer == P1){
        cout << TiposBarcosP1[2];
    }else if(turnplayer == P2){
        cout << TiposBarcosP2[2];
    }
    cout << " Crusier)" << endl;


    gotoxy(5, 22);
    cout << "Battleship [4 Posiciones] (";
    if(turnplayer == P1){
        cout << TiposBarcosP1[3];
    }else if(turnplayer == P2){
        cout << TiposBarcosP2[3];
    }
    cout << " Battleship)" << endl;

    gotoxy(5, 23);
    cout << "Carrier [5 Posiciones] (";
    if(turnplayer == P1){
        cout << TiposBarcosP1[4];
    }else if(turnplayer == P2){
        cout << TiposBarcosP2[4];
    }
    cout << " Carrier)" << endl;
    cout << "\n";
}

void pruebafrontend(){
    int entrada;
    string currentturn=P1;

    mostrarmensajeinicio();
    gotoxy(66, 27);
    cin >> entrada;

    if (entrada == 1)
    {
        system("cls");
        dibujo();
        gotoxy(58, 17);
        cout << "BIENVENIDO A BATALLA NAVAL";
        ponerbarcos();
        dispararbarcos();
    }
    else if (entrada == 2)
    {
        system("cls");
        gotoxy(58, 5);
        cout << "GRACIAS POR JUGAR";
    }
    else
    {
        gotoxy(64, 29);
        cout << "INCORRECTO!!!";
    }
}

void mensajeganador(){
    cout << "El Ganador es: ";
}

// Backend
void pruebalogica()
{
    int tipodebarco;
    bool invalidmove;
    bool invalidshoot;
    bool Nohayganadoraun;
    int direccion;
    string currentturn;
    bool valida;

    do
    {
        if (player <= 8)
        {
            currentturn = P1;
        }
        else
        {
            currentturn = P2;
        }
        Printshipinventory(currentturn);
        cout << "Its " << currentturn << " turn, select your move\n";
        cout << "Shipsize:";
        cin >> tipodebarco;
        
        cout << "\n";
        cout << "Arriba - 1" << endl;
        cout << "Abajo - 2" << endl;
        cout << "Izquierda - 3" << endl;
        cout << "Derecha - 4" << endl;
        cout << "Direccion: ";
        cin >> direccion;

        cout << "\n";

        cout << "Row(NUMBER):";
        cin >> row;
        cout << "Col(LETTER):";
        cin >> columna;
        col = LettertoNumber(columna);
        invalidmove = invalidplay(row, col, tipodebarco, direccion, currentturn);
        if (invalidmove == true)
        {
            cout << "Invalidmove" << endl;
            cout << "\n";
        }
        else if (invalidmove == false)
        {
            player++;
            buildships(row, col, tipodebarco, direccion, currentturn);
            actualizarInventarioBarcos(tipodebarco, currentturn);
            imprimirtablerodeprueba();
            /*menuBarcos(turnplayer);
            cout << "\n";
            tableronaval();*/
        }
    } while (player <= 16);

    player = 1;
    do
    {
        if (player % 2 == 1)
        {
            currentturn = P1;
        }
        else
        {
            currentturn = P2;
        }
        cout << currentturn << endl;
        cout << "Row(NUMBER)\n";
        cin >> row;
        cout << "Column(LETTER)\n";
        cin >> columna;
        col = LettertoNumber(columna);
        invalidshoot=novalidshoot(row, col, currentturn);
        if (invalidshoot==false)
        {
            shootcannons(row, col, currentturn);
            imprimirtablerodeprueba();
            Nohayganadoraun = NoWinner(currentturn);
            player++;
        }else
        {
            cout << "Invalid shoot\n";
            Nohayganadoraun = NoWinner(currentturn);
        }
    } while (Nohayganadoraun == true);
    cout << "El ganador es " << currentturn << "\nFELICIDADES";
}

void ponerbarcos(){
    int tipodebarco;
    bool invalidmove;
    int direccion;
    string currentturn;
    bool valida;

    do
    {
        if (player <= 8)
        {
            currentturn = P1;
        }
        else
        {
            currentturn = P2;
        }
        system("cls");

        dibujo();

        menuBarcos(currentturn);
        gotoxy(0,26);
        cout << "Its " << currentturn << " turn, select your move\n"; 
        tableronaval(currentturn, ADDBOATS);
        gotoxy(0,28);
        cout << "Shipsize:";
        cin >> tipodebarco;
        cout << "\n";
        gotoxy(0, 29);
        cout << "Arriba - 1" << endl;
        cout << "Abajo - 2" << endl;
        cout << "Izquierda - 3" << endl;
        cout << "Derecha - 4" << endl;
        cout << "Direccion: ";
        cin >> direccion;
        cout << "\n";
        cout << "Row(FILA):";
        cin >> row;
        cout << "Col(COLUMNA):";
        cin >> columna;
        col = LettertoNumber(columna);
        invalidmove = invalidplay(row, col, tipodebarco, direccion, currentturn);
        if (invalidmove == true)
        {
            cout << "Invalidmove" << endl;
            cout << "\n";
            sleep(3);
            system("cls");
        }
        else if (invalidmove == false)
        {
            player++;
            buildships(row, col, tipodebarco, direccion, currentturn);
            actualizarInventarioBarcos(tipodebarco, currentturn);
            system("cls");
        }
    } while (player <= 16);     
}

void dispararbarcos(){
    player = 1;
    bool invalidshoot;
    bool Nohayganadoraun=false;
    string currentturn;
    do{
        if (player <= 1)
        {
            currentturn = P1;
        }
        else
        {
            currentturn = P2;
        }
        system("cls");

        dibujo2();

        gotoxy(30, 3);
        cout << "Player 1";
        cout << "\n";
        tableronaval(P1,NOBOATS);
        cout << "\n";
        cout << "\n";
        gotoxy(30, 21);
        cout <<  "Player 2";
        tableronaval(P2, NOBOATS);
        cout << "\n";
    
        gotoxy(90,19);
        cout << "Its " << currentturn << " turn, select your move\n";
        gotoxy(90, 21); 
        cout << "Row(NUMBER): ";
        cin >> row;
        gotoxy(90, 22); 
        cout << "Column(LETTER): ";
        cin >> columna;
        col = LettertoNumber(columna);
        invalidshoot=novalidshoot(row, col, currentturn);

        if (invalidshoot==false)
        {
            shootcannons(row, col, currentturn);
            Nohayganadoraun = NoWinner(currentturn);
            player++;
        }else
        {
            gotoxy(90, 24); 
            cout << "Invalid shoot\n";
            Nohayganadoraun = NoWinner(currentturn);
            sleep(3);
        }
    }while(Nohayganadoraun==true);
}

bool invalidplay(int row, int col, int barco, int direccion, string player)
{
    if (player == P1)
    {
        if (TiposBarcosP1[barco - 1] == 0)
        {
            return true;
        }
    }
    else if (player == P2)
    {
        if (TiposBarcosP2[barco - 1] == 0)
        {
            return true;
        }
    }
    if (row >= 10 || col >= 10 || col < 0 || row < 0)
    {
        return true;
    }

    else if (direccion < 1 || direccion > 4)
    {
        return true;
    }

    if (direccion == 1) // Arriba
    {
        int contador = 0;
        int row1 = row;
        if (row < (barco - 1))
        {
            return true;
            imprimirtablerodeprueba();
        }
        while (contador < barco)
        {
            if (player == P1)
            {
                if (AreaJuegoP1[row1][col] == "O")
                {
                    return true;
                }
            }
            else if (player == P2)
            {
                if (AreaJuegoP2[row1][col] == "O")
                {
                    return true;
                }
            }
            row1--;
            contador++;
        }
    }
    if (direccion == 2) // Abajo
    {
        int contador = 0;
        int row1 = row;
        if ((row + barco) > 10)
        {
            return true;
        }
        while (contador < barco)
        {
            if (player == P1)
            {
                if (AreaJuegoP1[row1][col] == "O")
                {
                    return true;
                }
            }
            else if (player == P2)
            {
                if (AreaJuegoP2[row1][col] == "O")
                {
                    return true;
                }
            }
            row1++;
            contador++;
        }
    }
    if (direccion == 3) // Izquierda
    {
        int contador = 0;
        int col1 = col;
        if ((col - barco) < -1)
        {
            return true;
        }
        while (contador < barco)
        {
            if (player == P1)
            {
                if (AreaJuegoP1[row][col1] == "O")
                {
                    return true;
                }
            }
            else if (player == P2)
            {
                if (AreaJuegoP2[row][col1] == "O")
                {
                    return true;
                }
            }
            col1--;
            contador++;
        }
    }
    if (direccion == 4) // Derecha
    {
        int contador = 0;
        int col1 = col;
        if ((col + barco) > 10)
        {
            return true;
        }

        while (contador < barco)
        {
            if (player == P1)
            {
                if (AreaJuegoP1[row][col1] == "O")
                {
                    return true;
                }
            }
            else if (player == P2)
            {
                if (AreaJuegoP2[row][col1] == "O")
                {
                    return true;
                }
            }
            col1++;
            contador++;
        }
    }
    return false;
}

void buildships(int row, int col, int barco, int direccion, string player)
{
    if (direccion == 1) // Arriba
    {
        int contador = 0;
        int row1 = row;
        while (contador < barco)
        {
            if (player == P1)
            {
                AreaJuegoP1[row1][col] = {'O'};
            }
            else if (player == P2)
            {
                AreaJuegoP2[row1][col] = {'O'};
            }
            row1--;
            contador++;
        }
    }
    if (direccion == 2) // Abajo
    {
        int contador = 0;
        int row1 = row;
        while (contador < barco)
        {
            if (player == P1)
            {
                AreaJuegoP1[row1][col] = {'O'};
            }
            else if (player == P2)
            {
                AreaJuegoP2[row1][col] = {'O'};
            }
            row1++;
            contador++;
        }
    }
    if (direccion == 3) // Izquierda
    {
        int contador = 0;
        int col1 = col;
        while (contador < barco)
        {
            if (player == P1)
            {
                AreaJuegoP1[row][col1] = {'O'};
            }
            else if (player == P2)
            {
                AreaJuegoP2[row][col1] = {'O'};
            }
            col1--;
            contador++;
        }
    }
    if (direccion == 4) // Derecha
    {
        int contador = 0;
        int col1 = col;
        while (contador < barco)
        {
            if (player == P1)
            {
                AreaJuegoP1[row][col1] = {'O'};
            }
            else if (player == P2)
            {
                AreaJuegoP2[row][col1] = {'O'};
            }
            col1++;
            contador++;
        }
    }
}

void actualizarInventarioBarcos(int barco, string player)
{
    if (barco == 1)
    {
        if (player == P1)
        {
            TiposBarcosP1[0]--;
        }
        else if (player == P2)
        {
            TiposBarcosP2[0]--;
        }
    }
    else if (barco == 2)
    {
        if (player == P1)
        {
            TiposBarcosP1[1]--;
        }
        else if (player == P2)
        {
            TiposBarcosP2[1]--;
        }
    }
    else if (barco == 3)
    {
        if (player == P1)
        {
            TiposBarcosP1[2]--;
        }
        else if (player == P2)
        {
            TiposBarcosP2[2]--;
        }
    }
    else if (barco == 4)
    {
        if (player == P1)
        {
            TiposBarcosP1[3]--;
        }
        else if (player == P2)
        {
            TiposBarcosP2[3]--;
        }
    }
    else if (barco == 5)
    {
        if (player == P1)
        {
            TiposBarcosP1[4]--;
        }
        else if (player == P2)
        {
            TiposBarcosP2[4]--;
        }
    }
}

void shootcannons(int row, int col, string player)
{
    if (player == P1)
    {
        if (AreaJuegoP2[row][col] == "O")
        {
            AreaJuegoP2[row][col] = {"X"};
        }else{
            AreaJuegoP2[row][col] = "x";
        }
    }
    else if (player == P2)
    {
        if (AreaJuegoP1[row][col] == "O")
        {
            AreaJuegoP1[row][col] = {"X"};
        }
        else{
            AreaJuegoP2[row][col] = "x";
        }
    }
}

bool novalidshoot(int row, int col, string turn)
{
    if (row >= 10 || col >= 10 || col < 0 || row < 0)
    {
        return true;
    }
    if (turn==P1){
        if (AreaJuegoP2[row][col]=="X")
        {
            return true;
        }
    }else if (turn == P2){
        if (AreaJuegoP1[row][col]=="X")
        {
            return true;
        }
    }
    return false;
}

bool NoWinner(string player)
{
    if (player == P1)
    {
        for (int row = 0; row < 9; row++)
        {
            for (int col = 0; col < 9; col++)
            {
                if (AreaJuegoP2[row][col] == "O")
                {
                    return true;
                }
            }
        }
    }
    else if (player == P2)
    {
        for (int row = 0; row < 9; row++)
        {
            for (int col = 0; col < 9; col++)
            {
                if (AreaJuegoP1[row][col] == "O")
                {
                    return true;
                }
            }
        }
    }
    return false;
}

int LettertoNumber(char Letter)
{ // Transform letter
    if (Letter == 'A' || Letter == 'a')
    {
        return 0;
    }
    if (Letter == 'B' || Letter == 'b')
    {
        return 1;
    }
    if (Letter == 'C' || Letter == 'c')
    {
        return 2;
    }
    if (Letter == 'D' || Letter == 'd')
    {
        return 3;
    }
    if (Letter == 'E' || Letter == 'e')
    {
        return 4;
    }
    if (Letter == 'F' || Letter == 'f')
    {
        return 5;
    }
    if (Letter == 'G' || Letter == 'g')
    {
        return 6;
    }
    if (Letter == 'H' || Letter == 'h')
    {
        return 7;
    }
    if (Letter == 'I' || Letter == 'i')
    {
        return 8;
    }
    if (Letter == 'J' || Letter == 'j')
    {
        return 9;
    }
    else
    {
        return -1;
    }
}

void Printshipinventory(string player){
    cout << "You have:\n";
    if (player==P1)
    {
    for (int i = 0; i < 5; i++)
    {
        cout << TipoBarco[i] << " [" << TiposBarcosP1[i] << "]" << "\n";
    }
    }
    if (player==P2)
    {
    for (int i = 0; i < 5; i++)
    {
        cout << TipoBarco[i] << " [" << TiposBarcosP2[i] << "]" << "\n";
    }
    }

    cout << "Left";
}

