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
        hacertablero();
        do
        {
            jugada = seleccionarJugada();
            casillaOcupada = comprobarjugada(jugada);
            if (casillaOcupada == true)
            {
                cout << "Otra vez \n";
            }
        } while (casillaOcupada == true);
        colocarjugada(jugada);
    } while (gameover == false);
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
                cout << estructuragato[row1][col1];
            }
            else if (estructuragato[row1][col1] == 'O')
            {
                cout << estructuragato[row1][col1];
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
        cout << "Dame tu jugada: ";
        cin >> jugada1;
    } while (jugada1 > 9 && jugada1 < 0);
    return jugada1;
}

bool comprobarjugada(int jugada)
{
    if (jugada == 1)
    {
        row = 0;
        col = 0;
    }
    else if (jugada == 2)
    {
        row = 0;
        col = 1;
    }
    else if (jugada == 3)
    {
        row = 0;
        col = 2;
    }
    else if (jugada == 4)
    {
        row = 1;
        col = 0;
    }
    else if (jugada == 5)
    {
        row = 1;
        col = 1;
    }
    else if (jugada == 6)
    {
        row = 1;
        col = 2;
    }
    else if (jugada == 7)
    {
        row = 2;
        col = 0;
    }
    else if (jugada == 8)
    {
        row = 2;
        col = 1;
    }
    else if (jugada == 9)
    {
        row = 2;
        col = 2;
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

    if (jugada == 1)
    {
        areaJuego[0][0] = valorJugada;
    }
    else if (jugada == 2)
    {
        areaJuego[0][1] = valorJugada;
    }
    else if (jugada == 3)
    {
        areaJuego[0][2] = valorJugada;
    }
    else if (jugada == 4)
    {
        areaJuego[1][0] = valorJugada;
    }
    else if (jugada == 5)
    {
        areaJuego[1][1] = valorJugada;
    }
    else if (jugada == 6)
    {
        areaJuego[1][2] = valorJugada;
    }
    else if (jugada == 7)
    {
        areaJuego[2][0] = valorJugada;
    }
    else if (jugada == 8)
    {
        areaJuego[2][1] = valorJugada;
    }
    else if (jugada == 9)
    {
        areaJuego[2][2] = valorJugada;
    }
    turnojugador++;
}