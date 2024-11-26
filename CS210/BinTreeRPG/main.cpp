#ifdef _WIN32
#include <windows.h>
#endif
#include <iostream>
#include <string>

#include "GameDecisionTree.h"

using namespace std;

int main() {
    GameDecisionTree<Story> myGame;

    string filename = "story.txt";  // Specify the input file
    char delimiter = '|';            //  '|' is the delimiter, change this to ',' if you choose

    // Load the story data from the file
    myGame.loadStoryFromFile(filename, delimiter);
    #ifdef _WIN32
    DWORD con_mode;
    GetConsoleMode(GetStdHandle(STD_OUTPUT_HANDLE), &con_mode);
    con_mode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(GetStdHandle(STD_OUTPUT_HANDLE), con_mode);
    #endif

    // Start the game
    myGame.playGame();

    return 0;
}