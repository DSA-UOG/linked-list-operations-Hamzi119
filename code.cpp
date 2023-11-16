#include <iostream>

class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    void insertAtN(int value, int position) {
        Node* newNode = new Node(value);
        if (position == 1) {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node* temp = head;
        for (int i = 1; i < position - 1 && temp; ++i) {
            temp = temp->next;
        }

        if (!temp) {
            std::cout << "Invalid position." << std::endl;
            return;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    void deleteFromBeginning() {
        if (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        } else {
            std::cout << "List is empty." << std::endl;
        }
    }

    void deleteFromEnd() {
        if (!head) {
            std::cout << "List is empty." << std::endl;
            return;
        }

        if (!head->next) {
            delete head;
            head = nullptr;
            return;
        }

        Node* temp = head;
        while (temp->next->next) {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = nullptr;
    }

    void deleteFromN(int position) {
        if (!head) {
            std::cout << "List is empty." << std::endl;
            return;
        }

        if (position == 1) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* temp = head;
        for (int i = 1; i < position - 1 && temp; ++i) {
            temp = temp->next;
        }

        if (!temp || !temp->next) {
            std::cout << "Invalid position." << std::endl;
            return;
        }

        Node* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
    }

    void search(int value) {
        Node* temp = head;
        int position = 1;

        while (temp) {
            if (temp->data == value) {
                std::cout << "Value " << value << " found at position " << position << "." << std::endl;
                return;
            }

            temp = temp->next;
            ++position;
        }

        std::cout << "Value " << value << " not found in the list." << std::endl;
    }

    void updateAtN(int value, int position) {
        Node* temp = head;
        for (int i = 1; i < position && temp; ++i) {
            temp = temp->next;
        }

        if (!temp) {
            std::cout << "Invalid position." << std::endl;
            return;
        }

        temp->data = value;
    }

    void display() {
        Node* temp = head;
        while (temp) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    LinkedList list;
    list.insertAtBeginning(5);
    list.insertAtBeginning(3);
    list.insertAtN(4, 2);
    list.insertAtN(8, 4);
    list.display();

    list.search(3);
    list.updateAtN(10, 3);
    list.display();

    list.deleteFromBeginning();
    list.deleteFromEnd();
    list.deleteFromN(2);
    list.display();

    return 0;
}

