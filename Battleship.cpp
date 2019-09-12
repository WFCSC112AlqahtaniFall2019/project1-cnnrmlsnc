/* CONNOR MILEUSNIC
 * Project 1
 * CSC 112
 * Vector based 3x3 battleship game
 * */
#include <vector>
#include <iostream>
#include <ctime>
using namespace std;

int main() {
    //declare starting variables
    srand(time(0)); //seed
    int numGuess = 0;
    int row= 3;
    int col= 3;
    int guessRow;
    int guessCol;
    bool win = false;

    //generate random numbers, assign to ship position
    int shipRow = ((rand() % 3));
    int shipCol = ((rand() % 3));

    //creates board
    vector<vector<int>> board;
    board.resize(row,vector<int>(col,-1));

    board[shipRow][shipCol] = 1;

//prints starting board

    for (int i=0; i<row; i++) {
        for (int j=0; j<col; j++) {
            if (board[i][j] == -1 || 1 ) {  //prints ? for all present values on board, -1 (blank) and 1 (hidden ship)
                cout << " ? ";
            }
            if (j < col - 1) {
                cout << "|";
            }
        }
        cout << endl;
        if (i < row - 1) {

            cout << endl;
        }
    }




    cout<<endl<<"BATTLESHIP"<<endl;


    while(!win) {

        //get input, loops until game is won. counts guesses
        cout <<"Guess the position of the ship by inputting the row and column at which you think it is located."<<endl;
        cin >> guessRow;
        cin >> guessCol;
        numGuess++;

        //catches invalid inputs
        if(guessRow < 1 || guessRow > 3 || guessCol < 1 || guessRow > 3) {
            cout << "FATAL INPUT ERROR. NUMBER OUT OF BOUNDS (must be between 1 and 3)";
            cout<<endl;
            exit (EXIT_FAILURE);
        }


        //catches same spot from being guessed again.
        if(board[guessRow - 1][guessCol - 1] == 0){
            cout << "FATAL INPUT ERROR. REPEAT GUESS" << endl;
            exit (EXIT_FAILURE);
        }

        //updates board
        board[guessRow - 1][guessCol - 1]++;


        //prints board and determines win condition
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (board[i][j] == 2) {  //index of 2 means a hit ship

                    cout << " ! ";
                    win = true;
                }


                else if (board[i][j] == 0) { //index of 0 corresponds to a miss

                    cout << " X ";
                }

                else {
                    cout << " ? ";
                }

                if (j < col - 1) {


                    cout << "|";
                }


            }
            cout << endl;
            if (i < row - 1) {
                cout << endl;
            }
        }

    }


    cout <<endl<< "GAME OVER"<<endl;
    cout<< "It took you "<<numGuess << " guesses." << endl;





    return 0;
}