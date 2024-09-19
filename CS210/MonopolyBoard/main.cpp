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

    MonopolyBoard() : value(0), rent(0) {}

    MonopolyBoard(const string &propertyName, const string &propertyColor,  int value,  int rent) {
        this->propertyName = propertyName;
        this->propertyColor = propertyColor;
        this->value = value;
        this->rent = rent;
    }

    bool isEqual(const MonopolyBoard& other) const {
        if (this->propertyName != other.propertyName) {return false;}
        if (this->propertyColor != other.propertyColor) {return false;}
        if (this->value != other.value) {return false;}
        if (this->rent != other.rent) {return false;}
        return true;
    }

    void print() const {
        cout << "(" << this->propertyName << "," << this->propertyColor << ","
             << this->value << "," << this->rent << ")";
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
    void insertAtHead(MonopolyBoard(data)) {
        auto* newNode = new Node<T>(data);
        if (headNode == nullptr) {
            headNode = new Node<T>(data);
            headNode->nextNode = nullptr;
        } else {
            newNode->nextNode = headNode;
            headNode = newNode;
        }
    }

    void insertAtTail(MonopolyBoard(data)) {
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

    void insertAtPosition(MonopolyBoard(data), int position) {
        auto* newNode = new Node<T>(data);
        if (headNode == nullptr) {
            headNode = newNode;
            headNode->nextNode = nullptr;
        } else if (position == 0) {
            newNode->nextNode = headNode;
            headNode = newNode;
        } else {
            auto* currNode = headNode;
            for (int i = 0; i < position; i++) {
                currNode = currNode->nextNode;
            }
            newNode->nextNode = currNode->nextNode;
        }
    }
    void deleteAtHead() {}
    void deleteAtTail() {}
    void deleteAtPosition() {}
    void search(T value) {}
    void printList() {
        Node<T>* currNode = headNode;
        if (currNode == nullptr) {
            cout << "Empty List" << endl;
        } else {
            do {
                currNode->data.print();
                currNode = currNode->nextNode;
                if (currNode != headNode) {
                    cout << "->";
                }
            } while (currNode != headNode);
        }
    }

    // Optional basic
    void reverseCList() {}

    void sortCLList() {}

    void printHeadNode() {}

    void printLastNode() {}

    void isListEmpty() {}

    void countNodes() {
        Node<T>* currNode = headNode;

    }

    // Optional advanced
    void convertCLList() {}
    void updateNodeValue() {}
    void displaySpecificColorNode() {}
    void mergeCLList() {}

};

// Main function to demonstrate the LinkedList class
int main() {
    CircularLinkedList<MonopolyBoard> list;

    list.insertAtHead(MonopolyBoard("Mediterranean Avenue", "Brown", 60, 2));

    list.insertAtTail(MonopolyBoard("Baltic Avenue","Brown",60,4));

    list.insertAtPosition();

    list.deleteAtHead();

    list.deleteAtTail();

    list.deleteAtPosition();

    list.printList();

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