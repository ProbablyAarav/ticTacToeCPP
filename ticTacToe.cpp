#include <iostream>
using namespace std;

void printBoard(char one, char two, char three, char four, char five, char six, char seven, char eight, char nine) { //prints the board to the screen
    cout << "Board: " << endl;
    cout << "[" << one << "] [" << two << "] [" << three << "]\n[" << four << "] [" << five << "] [" << six << "]\n[" << seven << "] [" << eight << "] [" << nine << "]" << endl;
}

bool checkWin(char one, char two, char three, char four, char five, char six, char seven, char eight, char nine) { //checks if a player has won so far
    if ((one == two && two == three) ||
        (four == five && five == six) ||
        (seven == eight && eight == nine) ||
        (one == four && four == seven) ||
        (two == five && five == eight) ||
        (three == six && six == nine) ||
        (one == five && five == nine) ||
        (three == five && five == seven)) { //different logics to win (horizontal, vertical, diagonal, any direction)
        return true;
    }
    return false;
}

int main() {
    char one = '1', two = '2', three = '3', four = '4', five = '5', six = '6', seven = '7', eight = '8', nine = '9'; //setting variables for the board
    int place;
    char currentPlayer = 'X'; //tracking who's turn it it
    bool playing = true; //tracking if the game is still running

    cout << "X goes first." << endl;
    printBoard(one, two, three, four, five, six, seven, eight, nine); //prints the board

    while (playing) {
        cout << "Player " << currentPlayer << ", where would you like to go? ";
        cin >> place;

        switch (place) { //Places the player's X or O wherever they want to place it
            case 1: one = currentPlayer; break;
            case 2: two = currentPlayer; break;
            case 3: three = currentPlayer; break;
            case 4: four = currentPlayer; break;
            case 5: five = currentPlayer; break;
            case 6: six = currentPlayer; break;
            case 7: seven = currentPlayer; break;
            case 8: eight = currentPlayer; break;
            case 9: nine = currentPlayer; break;
            default:
                cout << "Invalid move. Try again." << endl; //handles invalid moves
                break;
        }

        printBoard(one, two, three, four, five, six, seven, eight, nine); //prints the updated board

        if (checkWin(one, two, three, four, five, six, seven, eight, nine)) { //checks for win after each move
            cout << "Player " << currentPlayer << " wins!" << endl; //prints who won
            playing = false; //ends game
        } else if (one != '1' && two != '2' && three != '3' && four != '4' && five != '5' && six != '6' && seven != '7' && eight != '8' && nine != '9') { //checks for tie
            cout << "It's a draw!" << endl; //States the tie
            playing = false; //ends game
        } else {
            //Swtiches play after turn
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
    }

    return 0;
}
