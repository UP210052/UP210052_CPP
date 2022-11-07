/*
Date: 28/10/2022
Author: Héctor Iván Ramírez Jaime.
Email: up210052@alumnos.upa.edu.mx
Description: Realizar un programa para juagar al gato
*/

// Library for input and output management.
#include <iostream>

// Use of namespace to avoid std::
using namespace std;
void hacertablero();
int seleccionarJugada();
bool comprobarjugada(int);
void colocarjugada(int);
bool ganar();

char estructuragato[6][11];
char areaJuego[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
int turnojugador = 1;
int row, col;

int main()
{
    
    bool gameover = false;
    int jugada;
    bool casillaOcupada = true;
    do
    {
        system ("clear");
        hacertablero();
        do
        {
            jugada = seleccionarJugada();
            casillaOcupada = comprobarjugada(jugada);
            if (casillaOcupada == true)
            {
                cout << "Trye again \n";
            }
        } while (casillaOcupada == true);
        colocarjugada(jugada);
        gameover = ganar();
    } while (gameover == false and turnojugador < 10);
    system ("clear");
    hacertablero();
    if (gameover == true)
    {
        if ((turnojugador - 1) % 2 == 0)
        {
            cout << "Player 2 won" << endl;
        }
        else
        {
            cout << "Player 1 won" << endl;
        }
    }
    else
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
                estructuragato[row1][col1] = '|';
            }
            else if (row1 == 1 || row1 == 3)
            {
                estructuragato[row1][col1] = '_';
            }
            else if (row1 != 5 && (col1 == 1 || col1 == 5 || col1 == 9))
            {
                estructuragato[row1][col1] = areaJuego[row][col];
                col++;
                if (col == 3)
                {
                    col = 0;
                    row++;
                }
            }
            else
            {
                estructuragato[row1][col1] = ' ';
            }
        }
    }
    for (int row1 = 0; row1 < 6; row1++)
    {
        for (int col1 = 0; col1 < 11; col1++)
        {
            if (estructuragato[row1][col1] == 'X')
            {
                cout << "\033[0;31m" << estructuragato[row1][col1] << "\033[0m";
            }
            else if (estructuragato[row1][col1] == 'O')
            {
                cout << "\033[0;32m" << estructuragato[row1][col1] << "\033[0m";
            }
            else
            {
                cout << estructuragato[row1][col1];
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

bool comprobarjugada(int jugada)
{
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
    if (areaJuego[row][col] == 'O' || areaJuego[row][col] == 'X')
    {
        return true;
    }
    else
    {
        return false;
    }
}

void colocarjugada(int jugada)
{
    char valorJugada;
    if (turnojugador % 2 == 0)
    {
        valorJugada = 'X';
    }
    else
    {
        valorJugada = 'O';
    }
   int fila=0, columna=0;
   for (int numjuada = 1; numjuada < 10; numjuada++)
    {
        if (jugada == numjuada)
        {
            areaJuego[fila][columna]=valorJugada;
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
    turnojugador++;
}

bool ganar()
{
    bool ganar = false;
    for (int posicion = 0; posicion < 3; posicion++)
    {
        if (areaJuego[posicion][0] == areaJuego[posicion][1] && areaJuego[posicion][posicion] == areaJuego[posicion][2])
        {
            ganar = true;
            break;
        }
        if (areaJuego[0][posicion] == areaJuego[1][posicion] && areaJuego[0][posicion] == areaJuego[2][posicion])
        {
            ganar = true;
            break;
        }
    }
    if (areaJuego[0][0] == areaJuego[1][1] && areaJuego[0][0] == areaJuego[2][2])
    {
        ganar = true;
    }
    else if (areaJuego[2][0] == areaJuego[1][1] && areaJuego[2][0] == areaJuego[0][2])
    {
        ganar = true;
    }
    return ganar;
}