/*
Date: 28/10/2022
Author: Héctor Iván Ramírez Jaime.
Email: up210052@alumnos.upa.edu.mx
Description: Make a program to play cat
*/

// Libraries used in the program.
#include <iostream>
#include <stdalign.h>
#include <time.h>

// Use of namespace to avoid std::
using namespace std;

void hacertablero();
int seleccionarJugada();
bool comprobarJugada(int, string);
/*
Function to check the move on the indicated board
Params: jugada numerical value from 1 - 9.
        tablero is the type of board to play on 
Return: True if the slot is occupied.
        False if the slot is not occupied.
*/
void colocarJugada(int, string, string);
/*
Function to place the move on the indicated board
Params: jugada valor numérico del 1 - 9
        tablero is the type of board to play on
        jugador is the type of player
*/
bool ganar(string);
/*
Function to check if that move wins the game on the indicated board.
Params: tablero is the type of board to play on
Return: true si ya gano.
        false si todavia no gana.
*/
int obtenerJugadaPC();
/*
Function to obtain the play of the PC 
Return: jugada numerical value from 1 - 9.
*/
void clonarMatriz();
/*
Function to clone the areaJuego array in areaJuegoPC
*/
int obtenerMejorJugadade(string);
/*
Function to get the best play of the indicated player
Params: jugador is the type of player
Return: jugada numerical value from 1 - 9.
*/

// Declaration of global variables.
char estructuraGato[6][11];
char areaJuego[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
char areaJuegoPC[3][3];
int turnoJugador = 1;
int row, col;
const string PC = "Maquina";
const string HUMANO = "Humano";
const string TABLERO = "Real";
const string TABLEROIMAG = "Imaginario";

int main()
{
    //Declaration of variables
    bool gameover = false;
    int jugada;
    bool casillaOcupada = true;
    int modo;
    //Ask the user which game mode he is going to play
    cout << "Tic tac toe \n";
    cout << "1 Singleplayer \n";
    cout << "2 Multiplayer \n";
    cout << "Which mode are you going to play (number)? \n";
    cin >> modo;
    // If 1 is set, enter 1 player mode
    if (modo == 1)
    {
        do
        {
            system("clear");
            if (turnoJugador % 2 == !0)
            {
                do
                {
                    hacertablero();
                    jugada = seleccionarJugada();
                    casillaOcupada = comprobarJugada(jugada, TABLERO);
                    if (casillaOcupada == true)
                    {
                        system("clear");
                        cout << "Trye again \n";
                    }
                } while (casillaOcupada == true);
                colocarJugada(jugada, TABLERO, HUMANO);
                gameover = ganar(TABLERO);
            }
            else
            {
                hacertablero();
                jugada = obtenerJugadaPC();
                colocarJugada(jugada, TABLERO, PC);
                gameover = ganar(TABLERO);
            }
        } while (gameover == false and turnoJugador < 10);
        system("clear");
        hacertablero();
    }
    // If you enter 2, you enter 2 player mode.
    else if (modo == 2)
    {
        do
        {
            system("clear");
            do
            {
                hacertablero();
                jugada = seleccionarJugada();
                casillaOcupada = comprobarJugada(jugada, TABLERO);
                if (casillaOcupada == true)
                {
                    system("clear");
                    cout << "Trye again \n";
                }
            } while (casillaOcupada == true);
            colocarJugada(jugada, TABLERO, HUMANO);
            gameover = ganar(TABLERO);
        } while (gameover == false and turnoJugador < 10);
        system("clear");
        hacertablero();
    }
    else
    {
        cout << "Gamer over";
    }

    if (gameover == true)
    {
        if (turnoJugador % 2 == 0)
        {
            cout << "Player 1 won" << endl;
        }
        else
        {
            if (modo == 1)
            {
                cout << "PC won";
            }
            else
            {
                cout << "Player 2 won" << endl;
            }
        }
    }
    else if (gameover == false and turnoJugador >= 9)
    {
        cout << "Tie" << endl;
    }
    return 0;
}

void hacertablero()
{
    row = 0;
    col = 0;
    for (int row1 = 0; row1 < 6; row1++)
    {
        for (int col1 = 0; col1 < 11; col1++)
        {
            if (col1 == 3 || col1 == 7)
            {
                estructuraGato[row1][col1] = '|';
            }
            else if (row1 == 1 || row1 == 3)
            {
                estructuraGato[row1][col1] = '_';
            }
            else if (row1 != 5 && (col1 == 1 || col1 == 5 || col1 == 9))
            {
                estructuraGato[row1][col1] = areaJuego[row][col];
                col++;
                if (col == 3)
                {
                    col = 0;
                    row++;
                }
            }
            else
            {
                estructuraGato[row1][col1] = ' ';
            }
        }
    }
    for (int row1 = 0; row1 < 6; row1++)
    {
        for (int col1 = 0; col1 < 11; col1++)
        {
            if (estructuraGato[row1][col1] == 'X')
            {
                cout << "\033[0;31m" << estructuraGato[row1][col1] << "\033[0m";
            }
            else if (estructuraGato[row1][col1] == 'O')
            {
                cout << "\033[0;32m" << estructuraGato[row1][col1] << "\033[0m";
            }
            else
            {
                cout << estructuraGato[row1][col1];
            }
        }
        cout << endl;
    }
}

int seleccionarJugada()
{
    int jugada1;
    do
    {
        cout << "Give  me your move: ";
        cin >> jugada1;
    } while (jugada1 > 9 && jugada1 < 0);
    return jugada1;
}

bool comprobarJugada(int jugada, string tablero)
{
    bool casillaOcupada = false;
    int fila = 0, columna = 0;
    for (int numjuada = 1; numjuada < 10; numjuada++)
    {
        if (jugada == numjuada)
        {
            row = fila;
            col = columna;
            break;
        }
        else
        {
            columna++;
            if (columna == 3)
            {
                columna = 0;
                fila++;
            }
        }
    }
    if (tablero == TABLERO)
    {
        if (areaJuego[row][col] == 'O' || areaJuego[row][col] == 'X')
        {
            casillaOcupada = true;
        }
    }
    else if (tablero == TABLEROIMAG)
    {
        if (areaJuegoPC[row][col] == 'O' || areaJuegoPC[row][col] == 'X')
        {
            casillaOcupada = true;
        }
    }
    return casillaOcupada;
}

void colocarJugada(int jugada, string tablero, string Jugador)
{
    char valorJugada;
    if (turnoJugador % 2 == 0)
    {
        valorJugada = 'X';
    }
    else
    {
        valorJugada = 'O';
    }
    int fila = 0, columna = 0;
    for (int numjuada = 1; numjuada < 10; numjuada++)
    {
        if (jugada == numjuada)
        {
            if (tablero == TABLERO)
            {
                areaJuego[fila][columna] = valorJugada;
                break;
            }
            else if (tablero == TABLEROIMAG)
            {
                if (Jugador == HUMANO)
                {
                    valorJugada = 'O';
                }
                else if (Jugador == PC)
                {
                    valorJugada = 'X';
                }
                areaJuegoPC[fila][columna] = valorJugada;
                break;
            }
        }
        else
        {
            columna++;
            if (columna == 3)
            {
                columna = 0;
                fila++;
            }
        }
    }
    if (tablero == TABLERO){
        turnoJugador++;
    }
}

bool ganar(string tablero)
{
    bool ganar = false;
    for (int posicion = 0; posicion < 3; posicion++)
    {
        if (tablero == TABLERO)
        {
            if (areaJuego[posicion][0] == areaJuego[posicion][1] && areaJuego[posicion][posicion] == areaJuego[posicion][2] && areaJuego[posicion][1] == areaJuego[posicion][2])
            {
                ganar = true;
                break;
            }
            if (areaJuego[0][posicion] == areaJuego[1][posicion] && areaJuego[0][posicion] == areaJuego[2][posicion] && areaJuego[1][posicion] == areaJuego[2][posicion])
            {
                ganar = true;
                break;
            }
        }
        else if (tablero == TABLEROIMAG)
        {
            if (areaJuegoPC[posicion][0] == areaJuegoPC[posicion][1] && areaJuegoPC[posicion][posicion] == areaJuegoPC[posicion][2] && areaJuegoPC[posicion][1] == areaJuegoPC[posicion][2])
            {
                ganar = true;
                break;
            }
            if (areaJuegoPC[0][posicion] == areaJuegoPC[1][posicion] && areaJuegoPC[0][posicion] == areaJuegoPC[2][posicion] && areaJuegoPC[1][posicion] == areaJuegoPC[2][posicion])
            {
                ganar = true;
                break;
            }
        }
    }
    if (tablero == TABLERO)
    {
        if (areaJuego[0][0] == areaJuego[1][1] && areaJuego[0][0] == areaJuego[2][2] && areaJuego[1][1] == areaJuego[2][2]) 
        {
            ganar = true;
        }
        else if (areaJuego[2][0] == areaJuego[1][1] && areaJuego[2][0] == areaJuego[0][2] && areaJuego[0][2] == areaJuego[1][1])
        {
            ganar = true;
        }
    } 
    else if (tablero == TABLEROIMAG)
    {
        if (areaJuegoPC[0][0] == areaJuegoPC[1][1] && areaJuegoPC[0][0] == areaJuegoPC[2][2] && areaJuegoPC[1][1] == areaJuegoPC[2][2])
        {
            ganar = true;
        }
        else if (areaJuegoPC[2][0] == areaJuegoPC[1][1] && areaJuegoPC[2][0] == areaJuegoPC[0][2] && areaJuegoPC[0][2] == areaJuegoPC[1][1])
        {
            ganar = true;
        }
    }
    return ganar;
}

int obtenerJugadaPC()
{
    bool casillaOcupada = false;
    int jugada;
    srand(time(NULL));
    jugada = obtenerMejorJugadade(PC);
    if (jugada != -1)
    {
        return jugada;
    }
    jugada = obtenerMejorJugadade(HUMANO);
    if (jugada != -1)
    {
        return jugada;
    }
    do
    {
        jugada= 1 + rand() % 9;
        casillaOcupada= comprobarJugada (jugada,TABLERO);
    }while (casillaOcupada == true);
    return jugada;
}

void clonarMatriz(){
    for (int fila = 0; fila < 3; fila++)
    {
        for (int columna = 0; columna < 3; columna++)
        {
            areaJuegoPC[fila][columna] = areaJuego[fila][columna];
        }
    }
}

int obtenerMejorJugadade(string jugador)
{
    bool casillaOcupada = false;
    bool gameover = false;
    int jugada = 0;
    clonarMatriz();
    if (jugador == PC)
    {
        do
        {
            jugada++;
            casillaOcupada=comprobarJugada(jugada, TABLEROIMAG);
            if (casillaOcupada == false){
                colocarJugada(jugada, TABLEROIMAG, PC);
                gameover = ganar(TABLEROIMAG);
            }
            clonarMatriz();
        } while (jugada <= 9 && gameover == false);
    } 
    else if (jugador == HUMANO)
    {
        do
        {
            jugada++;
            casillaOcupada=comprobarJugada(jugada, TABLEROIMAG);
            if (casillaOcupada== false){
                colocarJugada(jugada, TABLEROIMAG, HUMANO);
                gameover = ganar(TABLEROIMAG);
            }
            clonarMatriz();
        } while (jugada <= 9 && gameover == false);
    }
    if (jugada >= 10){
        jugada= -1;
    }
    return jugada;
}