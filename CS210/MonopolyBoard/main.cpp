#include <iostream>
#include <string>
#include <utility>

using namespace std;

struct Property {
    string propertyName;
    string propertyColor;
    int value;
    int rent;
};

// Data class to store a string and an integer
class MonopolyBoard {
public:
    string propertyName;
    string propertyColor;
    int value;
    int rent;

    MonopolyBoard(const string &propertyName, const string &propertyColor,  int value,  int rent) {
        this->propertyName = propertyName;
        this->propertyColor = propertyColor;
        this->value = value;
        this->rent = rent;
    }

    bool isEqual(const MonopolyBoard& other) {
        if (this->propertyName != other.propertyName) {return false;}
        if (this->propertyColor != other.propertyColor) {return false;}
        if (this->value != other.value) {return false;}
        if (this->rent != other.rent) {return false;}
    }

    void print() {
        cout << "(" << this->propertyName << "," << this->propertyColor << ","
             << this->value << "," << this->rent << ")" << endl;
    }
};

// Template Node class
template <typename T> class Node {
public:
    T data;
    Node* nextNode;

    Node(T value) {
        data = value;
        nextNode = nullptr;
    }
};

// Template LinkedList class
template <typename T> class CircularLinkedList {
private:
    Node<T>* headNode;
public:
    CircularLinkedList() {
        headNode = nullptr;
    }

    // Mandatory tasks
    void insertAtHead(Node<T> data) {
        if (headNode == nullptr) {
            headNode = new Node<T>(data);
            headNode->nextNode = nullptr;
        } else {
            Node<T>* currNode = headNode;
            while (currNode->nextNode != nullptr) {
                currNode = currNode->nextNode;
            }
            currNode->nextNode = new Node<T>(data);
            currNode->nextNode->nextNode = nullptr;
        }
    }
    void insertAtTail() {}
    void insertAtPosition() {}
    void deleteAtHead() {}
    void deleteAtTail() {}
    void deleteAtPosition() {}
    void search(T value) {}
    void printList() {}

    // Optional basic
    void reverseCList() {}
    void sortCLList() {}
    void printHeadNode() {}
    void printLastNode() {}
    void isListEmpty() {}
    void countNodes() {}

    // Optional advanced
    void convertCLList() {}
    void updateNodeValue() {}
    void displaySpecificColorNode() {}
    void mergeCLList() {}

};

// Main function to demonstrate the LinkedList class
int main() {
    CircularLinkedList<MonopolyBoard> list;

    list.insertAtHead(MonopolyBoard("place", "blue", 10, 5));

    list.insertAtTail();

    list.insertAtPosition();

    list.deleteAtHead();

    list.deleteAtTail();

    list.deleteAtPosition();

    // Optional basic
    list.reverseCList();
    list.sortCLList();
    list.printHeadNode();
    list.printLastNode();
    list.isListEmpty();
    list.countNodes();

    // Optional advanced
    list.convertCLList();
    list.updateNodeValue();
    list.displaySpecificColorNode();
    list.mergeCLList();

    return 0;
}