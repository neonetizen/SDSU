#ifndef GAMEDECISIONTREE_H
#define GAMEDECISIONTREE_H

#include <unordered_map>
#include <fstream>
#include <sstream>
#include <iostream>
#include "Node.h"
#include "Story.h"

template <typename T>
class GameDecisionTree {
private:
    Node<T>* root;
    unordered_map<int, Node<T>*> nodeMap;

public:
    GameDecisionTree() : root(nullptr) {}

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
            string desc;
            int num, leftNum, rightNum;

            ss >> num >> delimiter;
            getline(ss, desc, delimiter);
            ss >> leftNum >> delimiter;
            ss >> rightNum >> delimiter;;

            Node<T>* newNode = new Node<T>(Story(desc.substr(1, desc.length()-2), num, leftNum, rightNum));
            nodeMap.emplace(num, newNode);
        }

        for (auto& pair : nodeMap) {
            if (pair.first == 1) {
                root = pair.second;
            }
            
        }

        fFile.close();
    }

    // Function to start the game and traverse the tree based on user input
    void playGame() {
        cout << root->data.description << "\n";
    }
};

#endif // GAMEDECISIONTREE_H
