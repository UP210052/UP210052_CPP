#include <iostream>

using namespace std;

char AreaJuegoP1[10][10]={{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}};
char AreaJuegoP2[10][10]={{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}};
const string P1 = "Player 1";
const string P2 = "Player 2";
int col, row;

void makeboard();

void logicbattleship();
void buildships();
void putships(string, int, int);
int selectplay(char, int);
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
    placeOccupied = checkplay (1, 2, 2);
    cout << placeOccupied;
    //putships();
    //repetir las hasta poner todos los barcos por cada jugador
    return 0;
}

void tableronaval()
{

}

void logicanaval()
{

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

int menuBarcos(){
    /*
    1 Submarine [1] (3)
    2 Destroyer [2] (2)
    3 Cruiser  [3]
    4 Battleship 
    5 Carrier
    */
}