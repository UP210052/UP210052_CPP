#include <iostream>
#include <unistd.h>
//#include <vistas.h>

using namespace std;

string AreaGameP1[10][10] = {{"-", "-", "-", "-", "-", "-", "-", "-", "-", "-"}, {"-", "-", "-", "-", "-", "-", "-", "-", "-", "-"}, {"-", "-", "-", "-", "-", "-", "-", "-", "-", "-"}, {"-", "-", "-", "-", "-", "-", "-", "-", "-", "-"}, {"-", "-", "-", "-", "-", "-", "-", "-", "-", "-"}, {"-", "-", "-", "-", "-", "-", "-", "-", "-", "-"}, {"-", "-", "-", "-", "-", "-", "-", "-", "-", "-"}, {"-", "-", "-", "-", "-", "-", "-", "-", "-", "-"}, {"-", "-", "-", "-", "-", "-", "-", "-", "-", "-"}, {"-", "-", "-", "-", "-", "-", "-", "-", "-", "-"}};
string AreaGameP2[10][10] = {{"-", "-", "-", "-", "-", "-", "-", "-", "-", "-"}, {"-", "-", "-", "-", "-", "-", "-", "-", "-", "-"}, {"-", "-", "-", "-", "-", "-", "-", "-", "-", "-"}, {"-", "-", "-", "-", "-", "-", "-", "-", "-", "-"}, {"-", "-", "-", "-", "-", "-", "-", "-", "-", "-"}, {"-", "-", "-", "-", "-", "-", "-", "-", "-", "-"}, {"-", "-", "-", "-", "-", "-", "-", "-", "-", "-"}, {"-", "-", "-", "-", "-", "-", "-", "-", "-", "-"}, {"-", "-", "-", "-", "-", "-", "-", "-", "-", "-"}, {"-", "-", "-", "-", "-", "-", "-", "-", "-", "-"}};
int TypesBoatsP1[5] = {3, 2, 1, 1, 1};
int TypesBoatsP2[5] = {3, 2, 1, 1, 1};
string TypeBoat[5] = {"Submarine", "Destroyer", "Cruiser", "Battleship", "Carrier"};
string Player1A[14][23] = {
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

string Player2A[14][23] = {
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
char column;

void gotoxy(int, int);
void showMessageStart();
void showDrawing();
void makeBoardNaval(string, string);
void printMenuBoats(string);
void showDrawing2();
void showMessageWinner(string);

void putBoats();
void putBoatsPC();
void shootBoats();
void shootBoatsPC();
bool invalidplay(int, int, int, int, string);
void buildships(int, int, int, int, string);
void actualizarInventarioBarcos(int, string);
void shootcannons(int, int, string);
bool novalidshoot(int, int, string);
bool NoWinner(string);
int LettertoNumber(char);
int AIShipPlacement(string);

int main()
{
    int gamemode;

    showMessageStart();
    gotoxy(66, 27);
    cin >> gamemode;

    if (gamemode == 1)
    {
        system("clear");
        showDrawing();
        gotoxy(58, 17);
        cout << "WELCOME TO BATTLESHIP";
        putBoatsPC();
        shootBoatsPC();
    }
    else if (gamemode == 2)
    {
        system("clear");
        showDrawing();
        gotoxy(58, 17);
        cout << "WELCOME TO BATTLESHIP";
        putBoats();
        shootBoats();
    }
    else if (gamemode == 3)
    {
        system("clear");
        gotoxy(58, 5);
        cout << "THANKS FOR PLAYING";
    }
    else
    {
        gotoxy(64, 29);
        cout << "INCORRECT!!!";
    }
    return 0;
}

// Frontend
void gotoxy(int x, int y)
{
    cout << "\033[" << y << ";" << x << "f";
}

void showMessageStart()
{
    showDrawing();
    gotoxy(58, 20);
    cout << "WELCOME TO BATTLESHIP";
    gotoxy(66, 24);
    cout << "Press: " << endl;
    gotoxy(66, 25);
    cout << "1. Play 1 player" << endl;
    gotoxy(66, 26);
    cout << "2. Play multiplayer" << endl;
    gotoxy(66, 26);
    cout << "3. Exit" << endl;
}

void showDrawing2()
{
    system("clear");
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

void showDrawing()
{
    system("clear");
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

void makeBoardNaval(string player, string mode)
{
    int x = 0, y = 0;

    for (int rowJ = 0; rowJ <= 9; rowJ++)
    {
        for (int colJ = 0; colJ <= 9; colJ++)
        {
            Player1A[rowJ + 3][2 * colJ + 2] = ' ' + AreaGameP1[rowJ][colJ] + ' ';
        }
    }
    for (int rowJ = 0; rowJ <= 9; rowJ++)
    {
        for (int colJ = 0; colJ <= 9; colJ++)
        {
            Player2A[rowJ + 3][2 * colJ + 2] = ' ' + AreaGameP2[rowJ][colJ] + ' ';
        }
    }

    for (int row = 0; row < 14; row++)
    {

        cout << endl;
        if (player == P1)
        {
            if (mode == ADDBOATS)
            {
                gotoxy(55, 20 + row);
            }
            if (mode == NOBOATS)
            {
                gotoxy(2, 5 + row);
            }
            for (int col = 0; col < 23; col++)
            {
                if (mode == ADDBOATS)
                {
                    cout << Player1A[row][col];
                }
                else if (mode == NOBOATS)
                {
                    if (Player1A[row][col] == " O ")
                    {
                        cout<< " - ";
                    }
                    else
                    {
                        cout << Player1A[row][col];
                    }
                }
            }
        }
        else
        {
            if (mode == ADDBOATS)
            {
                gotoxy(55, 20 + row);
            }
            if (mode == NOBOATS)
            {
                gotoxy(2, 23 + row);
            }
            for (int col = 0; col < 23; col++)
            {
                if (mode == ADDBOATS)
                {
                    cout << Player2A[row][col];
                }
                else if (mode == NOBOATS)
                {

                    if (Player2A[row][col] == " O ")
                    {
                        cout << " - ";
                    }
                    else
                    {
                        cout << Player2A[row][col];
                    }
                }
            }
        }
    }
}

void printMenuBoats(string turnplayer)
{

    gotoxy(5, 19);
    cout << "Submarine [1 Position] (";
    if (turnplayer == P1)
    {
        cout << TypesBoatsP1[0];
    }
    else if (turnplayer == P2)
    {
        cout << TypesBoatsP2[0];
    }
    cout << " Submariene)" << endl;

    gotoxy(5, 20);
    cout << "Destroyer [2 Positions] (";
    if (turnplayer == P1)
    {
        cout << TypesBoatsP1[1];
    }
    else if (turnplayer == P2)
    {
        cout << TypesBoatsP2[1];
    }
    cout << " Destroyers)" << endl;

    gotoxy(5, 21);
    cout << "Cruiser  [3 Positions] (";
    if (turnplayer == P1)
    {
        cout << TypesBoatsP1[2];
    }
    else if (turnplayer == P2)
    {
        cout << TypesBoatsP2[2];
    }
    cout << " Crusier)" << endl;

    gotoxy(5, 22);
    cout << "Battleship [4 Positions] (";
    if (turnplayer == P1)
    {
        cout << TypesBoatsP1[3];
    }
    else if (turnplayer == P2)
    {
        cout << TypesBoatsP2[3];
    }
    cout << " Battleship)" << endl;

    gotoxy(5, 23);
    cout << "Carrier [5 Positions] (";
    if (turnplayer == P1)
    {
        cout << TypesBoatsP1[4];
    }
    else if (turnplayer == P2)
    {
        cout << TypesBoatsP2[4];
    }
    cout << " Carrier)" << endl;
    cout << "\n";
}

void showMessageWinner(string player)
{
    system("clear");
    showDrawing2();
    gotoxy(30, 3);
    cout << "Player 1";
    cout << "\n";
    makeBoardNaval(P1, NOBOATS);
    cout << "\n";
    cout << "\n";
    gotoxy(30, 21);
    cout << "Player 2";
    makeBoardNaval(P2, NOBOATS);
    cout << "\n";
    cout << "The Winner is: " << player << endl;
}

// Backend
void putBoats()
{
    int typeofBoat;
    bool invalidmove;
    int address;
    string currentturn;
    bool valid;

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
        system("clear");
        showDrawing();
        printMenuBoats(currentturn);
        gotoxy(0, 26);
        cout << "Its " << currentturn << " turn, select your move\n";
        makeBoardNaval(currentturn, ADDBOATS);
        gotoxy(0, 28);
        cout << "Shipsize:";
        cin >> typeofBoat;
        cout << "\n";
        gotoxy(0, 29);
        cout << "Top - 1" << endl;
        cout << "Down - 2" << endl;
        cout << "Left - 3" << endl;
        cout << "Right - 4" << endl;
        cout << "Direction: ";
        cin >> address;
        cout << "\n";
        cout << "Row(FILA):";
        cin >> row;
        cout << "Col(COLUMNA):";
        cin >> column;
        col = LettertoNumber(column);
        invalidmove = invalidplay(row, col, typeofBoat, address, currentturn);
        if (invalidmove == true)
        {
            cout << "Invalidmove" << endl;
            cout << "\n";
            sleep(3);
            system("clear");
        }
        else if (invalidmove == false)
        {
            player++;
            buildships(row, col, typeofBoat, address, currentturn);
            actualizarInventarioBarcos(typeofBoat, currentturn);
            system("clear");
        }
    } while (player <= 16);
}

void putBoatsPC()
{
    int typeofBoat;
    bool invalidmove;
    int address;
    string currentturn;
    bool valid;
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
        if (currentturn == P1)
        {
            system("clear");
            showDrawing();
            printMenuBoats(currentturn);
            gotoxy(0, 26);
            cout << "Its " << currentturn << " turn, select your move\n";
            makeBoardNaval(currentturn, ADDBOATS);
            gotoxy(0, 28);
            cout << "Shipsize:";
            cin >> typeofBoat;
            cout << "\n";
            gotoxy(0, 29);
            cout << "Top - 1" << endl;
            cout << "Down - 2" << endl;
            cout << "Left - 3" << endl;
            cout << "Right - 4" << endl;
            cout << "Direction: ";
            cin >> address;
            cout << "\n";
            cout << "Row(FILA):";
            cin >> row;
            cout << "Col(COLUMNA):";
            cin >> column;
            col = LettertoNumber(column);
            invalidmove = invalidplay(row, col, typeofBoat, address, currentturn);
            if (invalidmove == true)
            {
                cout << "Invalidmove" << endl;
                cout << "\n";
                sleep(3);
                system("clear");
            }
            else if (invalidmove == false)
            {
                player++;
                buildships(row, col, typeofBoat, address, currentturn);
                actualizarInventarioBarcos(typeofBoat, currentturn);
                system("clear");
            }
        }
        else if (currentturn == P2) // AI Actions
        {
            typeofBoat = AIShipPlacement("Shipsize");
            row = AIShipPlacement("Row");
            col = AIShipPlacement("Col");
            address = AIShipPlacement("Direction");
            invalidmove = invalidplay(row, col, typeofBoat, address, currentturn);
            if (invalidmove == true)
            {
            }
            else if (invalidmove == false)
            {
                player++;
                buildships(row, col, typeofBoat, address, currentturn);
                actualizarInventarioBarcos(typeofBoat, currentturn);
                system("clear");
                showDrawing();
                printMenuBoats(currentturn);
                gotoxy(0, 26);
                cout << "Its " << currentturn << " turn, select your move\n";
                makeBoardNaval(currentturn, ADDBOATS);
                gotoxy(0, 28);
            }
        }

    } while (player <= 16);
}

void shootBoats()
{
    player = 1;
    bool invalidshoot;
    bool noWinnerYet = false;
    string currentturn;
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
        system("clear");
        showDrawing2();
        gotoxy(30, 3);
        cout << "Player 1";
        cout << "\n";
        makeBoardNaval(P1, NOBOATS);
        cout << "\n";
        cout << "\n";
        gotoxy(30, 21);
        cout << "Player 2";
        makeBoardNaval(P2, NOBOATS);
        cout << "\n";

        gotoxy(90, 19);
        cout << "Its " << currentturn << " turn, select your move\n";
        gotoxy(90, 21);
        cout << "Row(NUMBER): ";
        cin >> row;
        gotoxy(90, 22);
        cout << "Column(LETTER): ";
        cin >> column;
        col = LettertoNumber(column);
        invalidshoot = novalidshoot(row, col, currentturn);

        if (invalidshoot == false)
        {
            shootcannons(row, col, currentturn);
            noWinnerYet = NoWinner(currentturn);
            player++;
        }
        else
        {
            gotoxy(90, 24);
            cout << "Invalid shoot\n";
            noWinnerYet = NoWinner(currentturn);
            sleep(3);
        }
    } while (noWinnerYet == true);
    showMessageWinner(currentturn);
}

void shootBoatsPC()
{
    bool invalidshoot;
    bool noWinnerYet = false;
    string currentturn;
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
            system("clear");
            showDrawing2();
            gotoxy(30, 3);
            cout << "Player 1";
            cout << "\n";
            makeBoardNaval(P1, NOBOATS);
            cout << "\n";
            cout << "\n";
            gotoxy(30, 21);
            cout << "Player 2";
            makeBoardNaval(P2, NOBOATS);
            cout << "\n";
            if (currentturn == P1)
            {
                gotoxy(90, 19);
                cout << "Its " << currentturn << " turn, select your move\n";
                gotoxy(90, 21);
                cout << "Row(NUMBER): ";
                cin >> row;
                gotoxy(90, 22);
                cout << "Column(LETTER): ";
                cin >> column;
                col = LettertoNumber(column);
            }
            else if (currentturn == P2) // AI Actions
            {
                row = AIShipPlacement("Row");
                col = AIShipPlacement("Col");
            }
            invalidshoot = novalidshoot(row, col, currentturn);
            if (invalidshoot == false)
            {
                shootcannons(row, col, currentturn);
                noWinnerYet = NoWinner(currentturn);
                player++;
            }
            else
            {
                gotoxy(90, 24);
                cout << "Invalid shoot\n";
                noWinnerYet = NoWinner(currentturn);
                sleep(3);
            }
        } while (noWinnerYet == true);
    showMessageWinner(currentturn);
}

bool invalidplay(int row, int col, int boat, int address, string player)
{
    if (player == P1)
    {
        if (TypesBoatsP1[boat - 1] == 0)
        {
            return true;
        }
    }
    else if (player == P2)
    {
        if (TypesBoatsP2[boat - 1] == 0)
        {
            return true;
        }
    }
    if (row >= 10 || col >= 10 || col < 0 || row < 0)
    {
        return true;
    }

    else if (address < 1 || address > 4)
    {
        return true;
    }

    if (address == 1) // Top
    {
        int counter = 0;
        int row1 = row;
        if (row < (boat - 1))
        {
            return true;
        }
        while (counter < boat)
        {
            if (player == P1)
            {
                if (AreaGameP1[row1][col] == "O")
                {
                    return true;
                }
            }
            else if (player == P2)
            {
                if (AreaGameP2[row1][col] == "O")
                {
                    return true;
                }
            }
            row1--;
            counter++;
        }
    }
    if (address == 2) // Down
    {
        int counter = 0;
        int row1 = row;
        if ((row + boat) > 10)
        {
            return true;
        }
        while (counter < boat)
        {
            if (player == P1)
            {
                if (AreaGameP1[row1][col] == "O")
                {
                    return true;
                }
            }
            else if (player == P2)
            {
                if (AreaGameP2[row1][col] == "O")
                {
                    return true;
                }
            }
            row1++;
            counter++;
        }
    }
    if (address == 3) // Left
    {
        int counter = 0;
        int col1 = col;
        if ((col - boat) < -1)
        {
            return true;
        }
        while (counter < boat)
        {
            if (player == P1)
            {
                if (AreaGameP1[row][col1] == "O")
                {
                    return true;
                }
            }
            else if (player == P2)
            {
                if (AreaGameP2[row][col1] == "O")
                {
                    return true;
                }
            }
            col1--;
            counter++;
        }
    }
    if (address == 4) // Right
    {
        int counter = 0;
        int col1 = col;
        if ((col + boat) > 10)
        {
            return true;
        }

        while (counter < boat)
        {
            if (player == P1)
            {
                if (AreaGameP1[row][col1] == "O")
                {
                    return true;
                }
            }
            else if (player == P2)
            {
                if (AreaGameP2[row][col1] == "O")
                {
                    return true;
                }
            }
            col1++;
            counter++;
        }
    }
    return false;
}

void buildships(int row, int col, int boat, int address, string player)
{
    if (address == 1) // Top
    {
        int counter = 0;
        int row1 = row;
        while (counter < boat)
        {
            if (player == P1)
            {
                AreaGameP1[row1][col] = {'O'};
            }
            else if (player == P2)
            {
                AreaGameP2[row1][col] = {'O'};
            }
            row1--;
            counter++;
        }
    }
    if (address == 2) // Down
    {
        int counter = 0;
        int row1 = row;
        while (counter < boat)
        {
            if (player == P1)
            {
                AreaGameP1[row1][col] = {'O'};
            }
            else if (player == P2)
            {
                AreaGameP2[row1][col] = {'O'};
            }
            row1++;
            counter++;
        }
    }
    if (address == 3) // Left
    {
        int counter = 0;
        int col1 = col;
        while (counter < boat)
        {
            if (player == P1)
            {
                AreaGameP1[row][col1] = {'O'};
            }
            else if (player == P2)
            {
                AreaGameP2[row][col1] = {'O'};
            }
            col1--;
            counter++;
        }
    }
    if (address == 4) // Right
    {
        int counter = 0;
        int col1 = col;
        while (counter < boat)
        {
            if (player == P1)
            {
                AreaGameP1[row][col1] = {'O'};
            }
            else if (player == P2)
            {
                AreaGameP2[row][col1] = {'O'};
            }
            col1++;
            counter++;
        }
    }
}

void actualizarInventarioBarcos(int boat, string player)
{
    if (boat == 1)
    {
        if (player == P1)
        {
            TypesBoatsP1[0]--;
        }
        else if (player == P2)
        {
            TypesBoatsP2[0]--;
        }
    }
    else if (boat == 2)
    {
        if (player == P1)
        {
            TypesBoatsP1[1]--;
        }
        else if (player == P2)
        {
            TypesBoatsP2[1]--;
        }
    }
    else if (boat == 3)
    {
        if (player == P1)
        {
            TypesBoatsP1[2]--;
        }
        else if (player == P2)
        {
            TypesBoatsP2[2]--;
        }
    }
    else if (boat == 4)
    {
        if (player == P1)
        {
            TypesBoatsP1[3]--;
        }
        else if (player == P2)
        {
            TypesBoatsP2[3]--;
        }
    }
    else if (boat == 5)
    {
        if (player == P1)
        {
            TypesBoatsP1[4]--;
        }
        else if (player == P2)
        {
            TypesBoatsP2[4]--;
        }
    }
}

void shootcannons(int row, int col, string player)
{
    if (player == P1)
    {
        if (AreaGameP2[row][col] == "O")
        {
            AreaGameP2[row][col] = {"X"};
        }
        else
        {
            AreaGameP2[row][col] = "x";
        }
    }
    else if (player == P2)
    {
        if (AreaGameP1[row][col] == "O")
        {
            AreaGameP1[row][col] = {"X"};
        }
        else
        {
            AreaGameP1[row][col] = "x";
        }
    }
}

bool novalidshoot(int row, int col, string turn)
{
    if (row >= 10 || col >= 10 || col < 0 || row < 0)
    {
        return true;
    }
    if (turn == P1)
    {
        if (AreaGameP2[row][col] == "X")
        {
            return true;
        }
    }
    else if (turn == P2)
    {
        if (AreaGameP1[row][col] == "X")
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
                if (AreaGameP2[row][col] == "O")
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
                if (AreaGameP1[row][col] == "O")
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

int AIShipPlacement(string Action)
{
    if (Action == "Shipsize")
    {
        int number = (rand() % 5) + 1;
        return number;
    }

    if (Action == "Row")
    {
        int number = (rand() % 9);
        return number;
    }
    if (Action == "Col")
    {
        int number = (rand() % 9);
        return number;
    }
    if (Action == "Direction")
    {
        int number = (rand() % 4) + 1;
        return number;
    }
    return -1;
}
