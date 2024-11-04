#pragma once
#include <iostream>
#include <cstdint>
using namespace std;

template <typename K, typename V>
struct Node 
{
    K key;
    V value;
    Node* next;

    Node(const K& key, const V& value) 
    {
        this->key = key;
        this->value = value;
        next = nullptr;
    }
};

template <typename K, typename V>
struct Hashtable 
{
private:

    Node<K, V>** table; // An array of pointers to the beginning of the chains
    int size;

    int hashfunction(const K& key)
    {
        uint32_t hash = 5381; // Обработка для строк
        

        if constexpr (is_same<K, string>::value)
        {
            for (char c : key) {
                hash = ((hash << 5) + hash) + c;
            }
        }
        else if constexpr (is_same<K, char>::value)
        {
            // Обработка для одиночного символа
            hash = key; // Простой хеш для символа
        }
        return hash % size;
    }

public:

    Hashtable(int size)
    {
        this->size = size;
        table = new Node<K, V>* [size];

        for (int i = 0; i < size; i++) 
        {
            table[i] = nullptr;
        }
    }

    ~Hashtable()
    {
        for (int i = 0; i < size; i++)
        {
            Node<K, V>* current = table[i];

            while (current != nullptr)
            {
                Node<K, V>* prev = current;
                current = current->next;
                delete prev;
            }
        }
        delete[] table;
    }

    void add(const K& key, const V& value) 
    {
        int index = hashfunction(key);
        Node<K, V>* current = table[index];


        // Проходим по цепочке, чтобы найти существующий ключ
        while (current != nullptr) 
        {
            if (current->key == key) 
            {
                current->value = value; // Обновляем значение, если ключ уже существует
                return;
            }
            current = current->next;
        }

        // Если ключ не найден, создаем новый узел и добавляем его в начало цепочки
        Node<K, V>* new_node = new Node<K, V>(key, value);
        new_node->next = table[index];
        table[index] = new_node;
    }

    string get(const K& key) 
    {
        int index = hashfunction(key);
        Node<K, V>* current = table[index];

        while (current != nullptr) 
        {
            if (current->key == key) 
            {
                return current->value;
            }
            current = current->next;
        }

        throw runtime_error("The key was not found");
    }

    void remove(const K& key)
    {
        int index = hashfunction(key);
        Node<K, V>* current = table[index];
        Node<K, V>* prev = nullptr;

        while (current != nullptr) // We go through the chain and look for an item to delete
        {
            if (current->key == key)
            {
                if (prev == nullptr)
                {
                    table[index] = current->next; // If the first in the chain
                }
                else
                {
                    prev->next = current->next;
                }
                delete current;
                return;
            }
            prev = current;
            current = current->next;
        }
        throw runtime_error("The key was not found");
    }

    void print() {
        for (int i = 0; i < size; ++i)
        {
            cout << i << ": ";
            Node<K, V>* current = table[i];
            if (current != nullptr)
            {
                while (current != nullptr)
                {
                    cout << "[" << current->key << ": " << current->value << "]";
                    current = current->next;
                    if (current != nullptr)
                    {
                        cout << " -> ";
                    }
                }
            }
            cout << "\n";
        }
    }

    V& operator[](const K& key) {
        int index = hashfunction(key);
        Node<K, V>* current = table[index];


        while (current != nullptr) {
            if (current->key == key) {
                return current->value;
            }
            current = current->next;
        }

        // Если ключ не найден, добавляем его с нулевым значением
        add(key, V{});
        return table[index]->value;
    }

    void search_line_and_size(string& longestKey, int& longestValue) 
    {
        longestKey.clear();
        longestValue = 0;

        for (int i = 0; i < size; i++) 
        {
            Node<K, V>* current = table[i];
            while (current != nullptr) 
            {
                if (current->key.length() > longestKey.length()) 
                {
                    longestKey = current->key;
                    longestValue = current->value;
                }
                current = current->next;
            }
        }
    }


};