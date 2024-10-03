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

    explicit Node(T value) {
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

    void insertAtPosition(T data, int position) {
        const int index = position - 1;
        if (index < 0) {
            cout << "Please enter a positive position" << endl;
        } else if (index== 0) {
            insertAtHead(data);
        } else if (headNode == nullptr) {
            headNode = new Node<T>(data);
            headNode->nextNode = headNode;
        } else {
            auto* currNode = headNode;
            for (int i = 0; i < index-1; i++) {
                currNode = currNode->nextNode;
                if (currNode == headNode && currNode->nextNode != headNode) {
                    return;
                }
            }
            Node<T>* tempNode = currNode->nextNode;
            currNode->nextNode = new Node<T>(data);
            currNode->nextNode->nextNode = tempNode;
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
                delete toDelete;
            }
        }
    }

    void deleteAtPosition(int position) {
        const int index = position -= 1;
        if (index < 0) {
            cout << "Please enter a positive position" << endl;
        } else if (index == 0) {
            deleteAtHead();
        } else if (headNode == nullptr) {
            cout << "Empty List" << endl;
        } else {
            /* check list length, if less than position, position is invalid, if position and length are equal,
             * the deletion is at the end */
            const int length = this->countNodes();
            if (index == length) {
                deleteAtTail();
                return;
            }
            if (index> length) {
                cout << "Invalid deletion at position " << position << endl;
                return;
            }

            auto* currNode = headNode;
            for (int i = 0; i < index-1; i++) {
                currNode = currNode->nextNode;
            }
            Node<T>* toDelete = currNode->nextNode;
            currNode->nextNode = currNode->nextNode->nextNode;
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
            cout << "\nList: ";
            do {
                currNode->data.print();
                currNode = currNode->nextNode;
                if (currNode != headNode) {
                    cout << "->";
                }
            } while (currNode != headNode);
            cout << endl << endl;
        }
    }

    // Optional basic
    void reverseCList() {
        const int length = this->countNodes();
        auto* prevNode = headNode;
        while (prevNode->nextNode != headNode) {
            prevNode = prevNode->nextNode;
        }
        auto* currNode = headNode;
        for (int _=0; _<length; _++) {
            auto* nextNode = currNode->nextNode;
            currNode->nextNode = prevNode;
            prevNode = currNode;
            currNode = nextNode;
        }
        headNode = prevNode;
    }

    void sortCLList() {
        int length = this->countNodes();
        bool swapped = false;
        do {
            swapped = false;
            auto* currNode = headNode;
            for (int i=1; i<length; i++) {
                auto* nextNode = currNode->nextNode;
                if (currNode->data.propertyName.compare(nextNode->data.propertyName) > 0) {
                    swap(currNode->data, nextNode->data);
                    swapped = true;
                }
                currNode = nextNode;
            }
        } while (swapped);
    }

    void printHeadNode() {
        if (headNode == nullptr) {
            cout << "Empty List" << endl;
        } else {
            cout << "Head Node: "; headNode->data.print(); cout << endl;
        }
    }

    void printLastNode() {
        if (headNode == nullptr) {
            cout << "Empty List" << endl;
        } else {
            auto* currNode = headNode;
            while (currNode->nextNode != headNode) {
                currNode = currNode->nextNode;
            }
            cout << "Last Node: "; currNode->data.print(); cout << endl;
        }
    }

    bool isListEmpty() {
        const bool isEmpty = headNode == nullptr;
        isEmpty ? cout << "Empty List" << endl : cout << "List is not empty" << endl;
        return isEmpty;
    }

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
    void convertCLList() {
        if (headNode!= nullptr) {
            auto* tailNode = headNode;
            while (tailNode->nextNode != headNode && tailNode->nextNode != nullptr) {
                tailNode = tailNode->nextNode;
            }
            if (tailNode->nextNode == headNode) {
                tailNode->nextNode = nullptr;
            } else {
                tailNode->nextNode = headNode;
            }
        }
    }

    void updateNodeValue(const int position, T data) {
        if (position < 0) {
            cout << "Please enter a positive position" << endl;
        } else if (headNode == nullptr) {
                cout << "Empty List" << endl;
        } else {

            auto* currNode = headNode;
            for (int i = 0; i < position-1; i++) {
                currNode = currNode->nextNode;
                if (currNode == headNode && currNode->nextNode != headNode) {
                    cout << "Invalid insertion at position " << position << endl;
                    return;
                }
            }
            currNode->data = data;
        }
    }

    void displaySpecificColorNode(string color) {
        auto* currNode = headNode;
        int count = 0;
        cout << "Displaying: " << color << endl;
        for (int _=0; _<this->countNodes(); _++) {
            if (currNode->data.propertyColor == color) {
                if (count != 0) {
                  cout << ", ";
                }
                currNode->data.print(); cout << "";
                count ++;
            }

            currNode = currNode->nextNode;
        }
    }

    void mergeCLList(CircularLinkedList<T> list) {
        if (headNode == nullptr) {
            headNode = list.headNode;
        } else {
            auto* tailNode = headNode;
            while (tailNode->nextNode != headNode) {
                tailNode = tailNode->nextNode;
            }
            auto* listTailNode = list.headNode;
            while (listTailNode->nextNode != list.headNode) {
                listTailNode = listTailNode->nextNode;
            }
            tailNode->nextNode = list.headNode;
            listTailNode->nextNode = headNode;
        }
    }

};

// Main function to demonstrate the LinkedList class
int main() {
    CircularLinkedList<MonopolyBoard> list;

    list.insertAtHead(MonopolyBoard("Baltic Avenue", "Brown", 60, 2));
    cout << "~~ Inserted Baltic Avenue at head" << endl;

    list.insertAtTail(MonopolyBoard("Connecticut Avenue","Light Blue",120,8));
    cout << "~~ Inserted Connecticut Avenue at tail" << endl;

    list.insertAtPosition(MonopolyBoard("Mediterranean Avenue", "Brown", 60, 2), 1);
    cout << "~~ Inserted Mediterranean Avenue at position 2" << endl << endl;

    cout << "~~ Current list"; list.printList();

    // Generating a fuller board, last 3 nodes in the code will be deleted
    list.insertAtHead(MonopolyBoard("Go", "Green", 0, 0));
    list.insertAtHead(MonopolyBoard("Somewhere awesome", "ahhhh", 60, 50));
    list.insertAtTail(MonopolyBoard("OP place", "augh", 10000, 100));
    list.insertAtPosition(MonopolyBoard("Filler place", "Meow", 1337, 69), 4);
    cout << "~~ Added filler places for delete demonstration";
    list.printList();

    list.deleteAtHead();
    cout << "~~ Deleted \"Somewhere awesome\" from head" << endl;

    list.deleteAtTail();
    cout << "~~ Deleted \"OP place\" from tail" << endl;

    list.deleteAtPosition(3);
    cout << "~~ Deleted \"Filler place\" from position 3" << endl << endl;

    cout << "~~ New list"; list.printList();

    // Optional basic
    list.reverseCList();
    cout << "~~ Reversed"; list.printList();
    cout << "~~ Sorted"; list.sortCLList();
    list.printList();
    cout << "~~ Printing head and last node:" << endl;
    list.printHeadNode();
    list.printLastNode();
    cout << endl << "~~ Checking isListEmpty()" << endl;
    list.isListEmpty();

    cout << endl << "~~ Checking countNodes()" << endl;
    cout << list.countNodes() << " node(s) in the list" << endl << endl;

    // Optional advanced
    cout << "~~ Converting list to a Linked List" << endl;
    list.convertCLList();
    cout << "~~ Converting back to a Circular List" << endl << endl;
    list.convertCLList();
    //converting back because my circular functions rely on it being circular, but check the code, it works!

    list.updateNodeValue(0, MonopolyBoard("Balloon Place","Light Blue",100,4));
    cout << "~~ Updated Baltic Avenue to Balloon Place"; list.printList();

    list.displaySpecificColorNode("Light Blue");
    cout << endl << endl;

    CircularLinkedList<MonopolyBoard> newList;
    newList.insertAtHead(MonopolyBoard("Park Place", "Dark Blue", 80, 3));
    newList.insertAtTail(MonopolyBoard("Boardwalk", "Dark Blue", 200, 8));
    cout << "~~ List to merge"; newList.printList();
    list.mergeCLList(newList);
    cout << "~~ Main list after merging"; list.printList();
    return 0;
}