#pragma once

#include <iostream>
#include <string>
using namespace std;

template <typename T>
struct Stack 
{
private:

    struct Node 
    {
        T person;
        Node* next;

        Node(T person)
        {
            this->person = person;
            next = nullptr;
        }
    };

    Node* head;

public:

    Stack()
    {
        head = nullptr;
    }


    ~Stack()
    {
        while (head != nullptr)
        {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }


    bool is_empty()
    {
        return head == nullptr;
    }


    void push(T name)
    {
        Node* new_node = new Node(name);
        new_node->next = head;
        head = new_node;
    }


    T pop()
    {
        if (is_empty())
        {
            throw runtime_error("Stack is empty");
        }
        else
        {
            Node* new_head = head->next;
            delete head;
            head = new_head;
        }
    }


    T top()
    {
        if (is_empty())
        {
            throw runtime_error("Stack is empty");
        }
        return head->person;
    }


    void print()
    {
        Node* current = head;
        while (current != nullptr)
        {
            cout << current->person << " ";
            current = current->next;
        }
        cout << "\n";
    }


};