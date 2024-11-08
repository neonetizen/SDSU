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
            int i = pair.first;
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

    // Function to start the game and traverse the tree based on user input
    void playGame() {
        string decision;
        do {

        } while(decision != "quit" || decision != "exit" || decision != "q");
    }
};

#endif // GAMEDECISIONTREE_H
