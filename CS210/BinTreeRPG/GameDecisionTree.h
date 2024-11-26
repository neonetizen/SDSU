#ifndef GAMEDECISIONTREE_H
#define GAMEDECISIONTREE_H

#include <unordered_map>
#include <fstream>
#include <sstream>
#include <iostream>
#include <limits>
#include <chrono>
#include <thread>
#include <regex>
#include "Node.h"
#include "Story.h"

template <typename T>
class GameDecisionTree {
private:
    Node<T>* root;
    unordered_map<int, Node<T>*> nodeMap;
    const string RESET = "\033[0m";
    const string RED = "\033[91m";
    const string GREEN = "\033[92m";
    const string BLUE = "\033[94m";

public:
    GameDecisionTree() : root(nullptr) {}

    string handleNewlines(const string& str) {
        string result = str;
        string::size_type pos = 0;
        while ((pos = result.find("\\n", pos)) != string::npos) {
            result.replace(pos, 2, "\n");
            pos += 1;
        }
        return result;
    }

    // Function to load story data from a text file and build the binary tree
    void loadStoryFromFile(const string& filename, char delimiter) {
        ifstream fFile(filename);

        if(!fFile.is_open()) {
            cout << "Unable to read " << filename << "\n";
            return;
        }

        string sLine;
        while(getline(fFile, sLine)) {

            stringstream ss(sLine);
            string desc, lOpt, rOpt;
            int num, leftNum, rightNum;

            ss >> num >> delimiter;
            getline(ss, desc, delimiter);
            ss >> leftNum >> delimiter;
            ss >> rightNum >> delimiter;
            getline(ss, lOpt, delimiter);
            getline(ss, rOpt, delimiter);

            desc = handleNewlines(desc);

            Node<T>* newNode = new Node<T>(Story(desc.substr(1, desc.length()-2), num, leftNum, rightNum, lOpt, rOpt));
            nodeMap.emplace(num, newNode);
        }

        for (auto& pair : nodeMap) {
            Node<Story>* currentNode = pair.second;

            if (currentNode->data.eventNumber == 1)
                root = currentNode;

            int left_event = currentNode->data.leftEventNumber;
            if (left_event > 0 && nodeMap.count(left_event))
                currentNode->left = nodeMap.at(left_event);

            int right_event = currentNode->data.rightEventNumber;
            if (right_event > 0 && nodeMap.count(right_event))
                currentNode->right = nodeMap.at(right_event);
        }

        fFile.close();
    }

    inline string colorText(const string& text, const string& color) {
        return color + text + RESET;
    }

    void typeLine(const string& line, int minDelay = 10, int maxDelay = 15) {
        srand(time(nullptr));
        for (char c : line) {
            cout << c << flush;
            int delay = minDelay + rand() % (maxDelay-minDelay);
            this_thread::sleep_for(chrono::milliseconds(delay*3));
        }
        cout << endl;
    }

    void slowLine(const string& line, bool typed=true, int time=10) {
        if (typed)
            this_thread::sleep_for(chrono::milliseconds(line.length()*11));
        else
            this_thread::sleep_for(chrono::milliseconds(time));
        cout << line << endl;
    }

    void loseScreen(string& desc) {
        for (int _=0; _<3; _++) {
            cout << RED <<
                "     _______________\n"
                    "    /               \\\n"
                    "   /  MIND BREACHED  \\\n"
                    "  /                   \\\n"
                    "  |   XXXX     XXXX   |\n"
                    "  |   XXXX     XXXX   |\n"
                    "  |   XXX       XXX   |\n"
                    "  |         X         |\n"
                    "  \\__      XXX     __/\n"
                    "    |\\     XXX     /|\n"
                    "    | |           | |\n"
                    "    | I I I I I I I |\n"
                    "    |  I I I I I I  |\n"
                    "     \\_           _/\n"
                    "      \\_         _/\n"
                    "        \\_______/\n";
            cout.flush();
            this_thread::sleep_for(chrono::milliseconds(500));
            cout <<
                "     _______________\n"
                "    /               \\\n"
                "   /  MIND BREACHED  \\\n"
                "  /                   \\\n"
                "  |   XXXX     XXXX   |\n"
                "  |   XXXX     XXXX   |\n"
                "  |   XXX       XXX   |\n"
                "  |         X         |\n"
                "  \\__      XXX     __/\n"
                "    |\\     XXX     /|\n"
                "    | |           | |\n"
                "    | I I I I I I I |\n"
                "    |  I         I  |\n"
                "    |  I I I I I I  |\n"
                "     \\_           _/\n"
                "      \\_         _/\n"
                "        \\_______/\n";
            cout.flush();
            this_thread::sleep_for(chrono::milliseconds(500));
        }
        cout <<
            "     _______________\n"
            "    /               \\\n"
            "   /  MIND BREACHED  \\\n"
            "  /                   \\\n"
            "  |   XXXX     XXXX   |\n"
            "  |   XXXX     XXXX   |\n"
            "  |   XXX       XXX   |\n"
            "  |         X         |\n"
            "  \\__      XXX     __/\n"
            "    |\\     XXX     /|\n"
            "    | |           | |\n"
            "    | I I I I I I I |\n"
            "    |  I I I I I I  |\n"
            "     \\_           _/\n"
            "      \\_         _/\n"
            "        \\_______/\n";
        cout << RESET;
        cout << desc;
        cout << "\nPlease press Enter to end game..." << endl;
        string io;
        cin.ignore();
        getline(cin, io);
    }

    // Function to start the game and traverse the tree based on user input
    void playGame() {
        Node<T>* currentNode = root;
        string skull =
                "     _______________\n"
                "    /               \\\n"
                "   /   MIND BREACH   \\\n"
                "  /                   \\\n"
                "  |   XXXX     XXXX   |\n"
                "  |   XXXX     XXXX   |\n"
                "  |   XXX       XXX   |\n"
                "  |         X         |\n"
                "  \\__      XXX     __/\n"
                "    |\\     XXX     /|\n"
                "    | |           | |\n"
                "    | I I I I I I I |\n"
                "    |  I I I I I I  |\n"
                "     \\_           _/\n"
                "      \\_         _/\n"
                "        \\_______/\n";
        cout << colorText(skull, GREEN);
        cout << "\nPlease press Enter to continue..." << endl;
        string io;
        getline(cin, io);

        string decision;
        bool first = true;
        bool home = true;
        bool terminal = false;

        do {

            if (currentNode->data.description[0] == '[') {
                if (first) {
                    slowLine(colorText("[Server]: New client connected: 176.112.39.140", GREEN), false, 1500);
                    first = false;
                }

                terminal = true;
                if (currentNode->data.leftEventNumber == -2 && currentNode->data.rightEventNumber == -2) {
                    loseScreen(currentNode->data.description);
                    return;
                }
                if (currentNode->data.leftEventNumber == -3 && currentNode->data.rightEventNumber == -3) {
                    cout << skull;
                    cout << currentNode->data.description;
                    cout << "\nPlease press Enter to end game..." << endl;
                    cin.ignore();
                    getline(cin, io);
                    return;
                }
                slowLine(colorText(currentNode->data.description, GREEN));
                slowLine(colorText(currentNode->data.leftOption, BLUE), false, 2000);
                if (currentNode->right)
                    cout << colorText(currentNode->data.rightOption, BLUE) << endl;

            } else {
                terminal = false;
                if (currentNode->data.leftEventNumber == -2 && currentNode->data.rightEventNumber == -2) {
                    loseScreen(currentNode->data.description);
                    return;
                }
                if (currentNode->data.leftEventNumber == -3 && currentNode->data.rightEventNumber == -3) {
                    cout << skull;
                    cout << currentNode->data.description;
                    cout << "\nPlease press Enter to end game..." << endl;
                    cin.ignore();
                    getline(cin, io);
                    return;
                }

                slowLine(currentNode->data.description, false, 1000);
                slowLine(colorText(currentNode->data.leftOption, BLUE), false, 2000);
                if (currentNode->right)
                    cout << colorText(currentNode->data.rightOption, BLUE) << endl;
            }

            cout << " \033[33m";
            cin >> decision;
            cout << RESET;

            if (decision == "quit" || decision == "exit" || decision == "-1") {
                return;
            }
            if (decision == "1") {
                if (terminal) {
                    if (currentNode->data.description[1] == 'S') {
                        if (currentNode->data.eventNumber == 33 || currentNode->data.eventNumber == 39)
                             home = false;
                        if (home)
                            cout << colorText("[home /]", GREEN);
                        else
                            cout << colorText("[NEUTECH00 /]", GREEN);
                    } else {
                        cout << colorText(" >> ", GREEN);
                    }
                    typeLine(colorText(currentNode->data.leftOption.substr(4, currentNode->data.leftOption.length()-1), GREEN));
                }
                    currentNode = currentNode->left;

            } else if (decision == "2") {
                if (terminal) {
                    if (currentNode->data.description[1] == 'S') {
                        if (currentNode->data.eventNumber == 33 || currentNode->data.eventNumber == 39)
                            home = false;
                        if (home)
                            cout << colorText("[home /] ", GREEN);
                        else
                            cout << colorText("[NEUTECH00 /] ", GREEN);
                    } else {
                        cout << colorText(" >> ", GREEN);
                    }
                    typeLine(colorText(currentNode->data.rightOption.substr(4, currentNode->data.rightOption.length()-1), GREEN));
                }
                if (currentNode->right)
                    currentNode = currentNode->right;

            } else {
                if (terminal) {
                    slowLine(colorText("[176.112.39.140]: What? Reply to me with 1 or 2", GREEN));
                    cout << endl;
                } else {
                    cout << colorText("Enter 1 or 2 for an action", RED) << endl;
                }
            }

        } while(true);
    }
};

#endif // GAMEDECISIONTREE_H
