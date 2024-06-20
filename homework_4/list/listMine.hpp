#ifndef LIST_HPP
# define LIST_HPP

#include <iostream>

template<typename T>
class Node {
public:
    T data;
    Node* next;

    Node(T val) : data(val), next(nullptr) {}
};

template<typename T>
class LinkedList {
private:
    Node<T>* head;

public:
    LinkedList() : head(nullptr) {}

    void append(T val) {
        Node<T>* newNode = new Node<T>(val);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node<T>* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void remove(T val) {
        if (head == nullptr) {
            std::cout << "List is empty, cannot remove." << std::endl;
            return;
        }

        if (head->data == val) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node<T>* temp = head;
        while (temp->next != nullptr && temp->next->data != val) {
            temp = temp->next;
        }

        if (temp->next == nullptr) {
            std::cout << "Value not found in the list." << std::endl;
        } else {
            Node<T>* nodeToDelete = temp->next;
            temp->next = temp->next->next;
            delete nodeToDelete;
        }
    }

    void display() {
        if (head == nullptr) {
            std::cout << "List is empty." << std::endl;
            return;
        }

        Node<T>* temp = head;
        while (temp != nullptr) {
            std::cout << temp->data << " -> ";
            temp = temp->next;
        }
        std::cout << "null" << std::endl;
    }

    ~LinkedList() {
        Node<T>* temp;
        while (head != nullptr) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

#endif