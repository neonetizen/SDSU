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
            auto* currNode = headNode;
            while(currNode->nextNode != headNode) {
                currNode = currNode->nextNode;
            }
            newNode->nextNode = headNode;
            headNode = newNode;
            currNode->nextNode = headNode;

        }
        cout << "Inserted "; data.print(); cout << " at head" << endl;
    }

    void insertAtTail(T data) {
        if (headNode == nullptr) {
            headNode = new Node<T>(data);
            headNode->nextNode = headNode;
        } else {
            auto* currNode = headNode;
            // traverses list until 1 before end is reached
            while (currNode->nextNode != headNode) {
                currNode = currNode->nextNode;
            }
            currNode->nextNode = new Node<T>(data);
            currNode->nextNode->nextNode = headNode;
        }
    }

    void insertAtPosition(T data, const int position) {
        if (position < 0) {
            cout << "Please enter a positive position" << endl;
        } else if (position == 0) {
            insertAtHead(data);
        } else if (headNode == nullptr) {
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
            cout << "Inserted "; data.print(); cout << " at position " << position << endl;
        }
    }

    void deleteAtHead() {
        if (headNode == nullptr) {
            cout << "Empty List" << endl;
        } else {
            auto* currNode = headNode;
            if (currNode->nextNode == headNode) {
                headNode->nextNode = nullptr;
                headNode = nullptr;
            } else {
                while (currNode->nextNode != headNode) {
                    currNode = currNode->nextNode;
                }
                Node<T>* toDelete = headNode;
                headNode = headNode->nextNode;
                currNode->nextNode = headNode;
                cout << "Deleted "; toDelete->data.print(); cout << " from head." << endl;
                delete toDelete;
            }
        }
    }

    void deleteAtTail() {
        if (headNode == nullptr) {
            cout << "Empty List" << endl;
        } else {
            auto* currNode = headNode;
            if (currNode->nextNode == headNode) {
                headNode->nextNode = nullptr;
                headNode = nullptr;
            } else {
                while (currNode->nextNode->nextNode != headNode) {
                    currNode = currNode->nextNode;
                }
                Node<T>* toDelete = currNode->nextNode;
                currNode->nextNode = headNode;
                cout << "Deleted "; toDelete->data.print(); cout << " from tail." << endl;
                delete toDelete;
            }
        }
    }

    void deleteAtPosition(const int position) {
        if (position < 0) {
            cout << "Please enter a positive position" << endl;
        } else if (position == 0) {
            deleteAtHead();
        } else if (headNode == nullptr) {
            cout << "Empty List" << endl;
        } else {
            /* check list length, if less than position, position is invalid, if position and length are equal,
             * the deletion is at the end */
            const int length = this->countNodes();
            if (position == length) {
                deleteAtTail();
                return;
            }
            if (position > length) {
                cout << "Invalid deletion at position " << position << endl;
                return;
            }

            auto* currNode = headNode;
            for (int i = 0; i < position-1; i++) {
                currNode = currNode->nextNode;
            }
            Node<T>* toDelete = currNode->nextNode;
            currNode->nextNode = currNode->nextNode->nextNode;
            cout << "Deleted "; toDelete->data.print(); cout << " from position " << position << endl;
            delete toDelete;
        }
    }

    bool search(T value) {
        if (headNode == nullptr) {
            cout << "Empty List" << endl;
        } else {
            auto *currNode = headNode;
            do {
                if (currNode->data.isEqual(value)) {
                    return true;
                }
                    currNode = currNode->nextNode;
            } while (currNode != headNode);
        }
        return false;
    }

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
            cout << endl;
        }
    }

    // Optional basic
    void reverseCList() {}

    void sortCLList() {}

    void printHeadNode() {}

    void printLastNode() {}

    void isListEmpty() {}

    int countNodes() {
        if (headNode == nullptr) {
            return 0;
        }
        auto* currNode = headNode->nextNode;
        int count = 1;
        while (currNode != headNode) {
            currNode = currNode->nextNode;
            count++;
        }
        return count;
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

    list.insertAtPosition(MonopolyBoard("a", "a", 1, 1), 0);

    list.deleteAtHead();

    list.deleteAtTail();

    list.deleteAtPosition(3);

    list.printList();

    // Optional basic
    list.reverseCList();
    list.sortCLList();
    list.printHeadNode();
    list.printLastNode();
    list.isListEmpty();
    cout << list.countNodes() << " node(s) in the list.";

    // Optional advanced
    list.convertCLList();
    list.updateNodeValue();
    list.displaySpecificColorNode();
    list.mergeCLList();

    return 0;
}