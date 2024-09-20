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
    void insertAtHead(T data) {
        auto* newNode = new Node<T>(data);
        if (headNode == nullptr) {
            headNode = new Node<T>(data);
            headNode->nextNode = headNode;
        } else {
            auto* tailNode = headNode;
            while(tailNode->nextNode != headNode) {
                tailNode = tailNode->nextNode;
            }
            newNode->nextNode = headNode;
            headNode = newNode;
            tailNode->nextNode = headNode;
        }
    }

    void insertAtTail(T data) {
        if (headNode == nullptr) {
            headNode = new Node<T>(data);
            headNode->nextNode = headNode;
        } else {
            Node<T>* tailNode = headNode;
            while (tailNode->nextNode != headNode) {
                tailNode = tailNode->nextNode;
            }
            tailNode->nextNode = new Node<T>(data);
            tailNode->nextNode->nextNode = headNode;
        }
    }

    void insertAtPosition(MonopolyBoard(data), const int position) {
        if (position < 0) {
            cout << "Please enter a positive position" << endl;
            return;
        }
        if (position == 0) {
            insertAtHead(data);
            return;
        }
        if (headNode == nullptr) {
            headNode = new Node<T>(data);
            headNode->nextNode = headNode;
        } else {
            auto* currNode = headNode;
            for (int i = 0; i < position-1; i++) {
                currNode = currNode->nextNode;
                if (currNode == headNode && currNode->nextNode != headNode) {
                    cout << "Invalid insertion at position " << position << endl;
                    return;
                }
            }
            Node<T>* tempNode = currNode->nextNode;
            currNode->nextNode = new Node<T>(data);
            currNode->nextNode->nextNode = tempNode;
        }
    }

    /* TODO: fix deleteAtHead */
    void deleteAtHead() {
        if (headNode == nullptr) {
            cout << "Empty List" << endl;
        } else {
            Node<T>* currNode = headNode;
            if (currNode->nextNode == headNode) {
                delete headNode;
            } else {
                while (currNode->nextNode != headNode) {
                    currNode = currNode->nextNode;
                }
                Node<T>* toDelete = headNode;
                headNode = headNode->nextNode;
                currNode->nextNode = headNode;
                delete toDelete;
            }
        }
    }

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

    //list.insertAtTail(MonopolyBoard("Baltic Avenue","Brown",60,4));

    //list.insertAtPosition(MonopolyBoard("a", "a", 1, 1), 0);

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