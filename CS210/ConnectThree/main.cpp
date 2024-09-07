#include <iostream>
#include <vector>
using namespace std;
class ConnectThree {
public:
    /* Constructor*/
    ConnectThree(){
        /* Initialize defaults here */
    }
    /* This is your game board*/

    vector<vector<char>> gameBoard

    {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'}
    };
    /* This prints your game board*/
    void printGameBoard()
    {
        for (int i = 0; i < gameBoard.size(); i++)
        {
            for (int j = 0; j < gameBoard[i].size(); j++)
            {
                cout << gameBoard[i][j] << " ";
            }
            cout << endl;
        }
    }
    /* This method modifes the game board*/
    void modifyGameBoard(char player, int position)
    {
        /*write code to modify the game board here*/
        gameBoard[position / 3][position % 3] = player;
    }

    vector<char> getValidMoves() const {
        vector<char> validMoves;

        /* Finds the valid moves by going top down, then left to right on the board */
        for (int i = 0; i < gameBoard.size(); i++) {
            char cLowestMove = NULL;
            for (int j = 0; j < gameBoard[i].size(); j++) {
                if (gameBoard[j][i] != 'X' && gameBoard[j][i] != 'O') { cLowestMove = gameBoard[j][i]; }
            }
            if (cLowestMove != NULL) { validMoves.push_back(cLowestMove); }
        }
        return validMoves;
    }

    bool winCheck(char player) const {
        for (int i = 0; i < 3; i++) {
            /* Checks rows and columns in a single loop */
            if (gameBoard[i][0] == player && gameBoard[i][1] == player && gameBoard[i][2] == player) {
                return true;
            }
            if (gameBoard[0][i] == player && gameBoard[1][i] == player && gameBoard[2][i] == player) {
                return true;
            }
        }
        /* Checks diagonals */
        if (gameBoard[0][0] == player && gameBoard[1][1] == player && gameBoard[2][2] == player) {
            return true;
        }
        if (gameBoard[0][2] == player && gameBoard[1][1] == player && gameBoard[2][0] == player) {
            return true;
        }
        return false;
    }
};

int main() {
    /* Initialize board and important variables/setup */
    ConnectThree board;
    char player = 'X';
    int rounds = 0;
    cout << "Connect 3:" << endl;
    board.printGameBoard();

    while(true) {
        char choice;
        vector<char> validMoves = board.getValidMoves();

        cout << "Player " << player << " please make a choice: ";
        cin >> choice;

        /* Checks if user-input is in pool of valid moves */
        if (choice == validMoves[0] || choice == validMoves[1] || choice == validMoves[2]) {
            const int iChoice = choice - '1';

            board.modifyGameBoard(player, iChoice);
            board.printGameBoard();
            rounds ++;
            cout << rounds << endl;

            /* Win is only possible at or after round 5 */
            if (rounds >= 5) {
                if (board.winCheck(player)) {
                    cout << "Player " << player << " wins!" << endl;
                    return 0;
                }
            }

            /* Any additional move past the 9th is impossible */
            if (rounds > 8) {
                cout << "The game ends in a draw!" << endl;
                return 0;
            }
            /* Efficiently switches player */
            player = player == 'X' ? 'O' : 'X';

        } else {
            cout << "Invalid choice" << endl;
        }
    }
}