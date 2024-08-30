#include <iostream>
using namespace std;

void printBoard(char one, char two, char three, char four, char five, char six, char seven, char eight, char nine) {
    cout << "Board: " << endl;
    cout << "[" << one << "] [" << two << "] [" << three << "]\n[" << four << "] [" << five << "] [" << six << "]\n[" << seven << "] [" << eight << "] [" << nine << "]" << endl;
}

bool checkWin(char one, char two, char three, char four, char five, char six, char seven, char eight, char nine) {
    if ((one == two && two == three) ||
        (four == five && five == six) ||
        (seven == eight && eight == nine) ||
        (one == four && four == seven) ||
        (two == five && five == eight) ||
        (three == six && six == nine) ||
        (one == five && five == nine) ||
        (three == five && five == seven)) {
        return true;
    }
    return false;
}

int main() {
    char one = '1', two = '2', three = '3', four = '4', five = '5', six = '6', seven = '7', eight = '8', nine = '9';
    int place;
    char currentPlayer = 'X';
    bool playing = true;

    cout << "X goes first." << endl;
    printBoard(one, two, three, four, five, six, seven, eight, nine);

    while (playing) {
        cout << "Player " << currentPlayer << ", where would you like to go? ";
        cin >> place;

        switch (place) {
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
                cout << "Invalid move. Try again." << endl;
                break;
        }

        printBoard(one, two, three, four, five, six, seven, eight, nine);

        if (checkWin(one, two, three, four, five, six, seven, eight, nine)) {
            cout << "Player " << currentPlayer << " wins!" << endl;
            playing = false;
        } else if (one != '1' && two != '2' && three != '3' && four != '4' && five != '5' && six != '6' && seven != '7' && eight != '8' && nine != '9') {
            cout << "It's a draw!" << endl;
            playing = false;
        } else {
            // Switch player
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
    }

    return 0;
}
