/*
Date: 28/10/2022
Author: Héctor Iván Ramírez Jaime.
Email: up210052@alumnos.upa.edu.mx
Description: Programa de matrices
*/

// Library for input and output management.
#include <iostream>

// Use of namespace to avoid std::
using namespace std;
int main()
{
    int conjunto[5][5];
    for (int row = 0; row < 5; row++)
    {
        for (int col = 0; col < 5; col++)
        {
            cout << "Valor en [" << row << "][" << col << "]";
            cin >> conjunto[row][col];
        }
    }
    for (int row = 0; row < 5; row++)
    {
        for (int col = 0; col < 5; col++)
        {
            cout << conjunto[row][col]<< "\t";
        }
        cout << endl;
    }

    return 0;
}