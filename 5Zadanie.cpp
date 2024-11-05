#include <iostream>
#include <string>
using namespace std;


struct Node 
{
    int data;        
    Node* left;      
    Node* right;     

    
    Node(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};


class BinarySearchTree 
{
private:
    Node* root;  

    
    Node* insert(Node* node, int val) 
    {
        if (node == nullptr) 
        {
            return new Node(val);
        }
        if (val < node->data) 
        {
            node->left = insert(node->left, val);
        }
        else if (val > node->data) 
        {
            node->right = insert(node->right, val);
        }
        return node;
    }

    
    Node* removeNode(Node* node, int val) 
    {
        if (node == nullptr) return nullptr;

        if (val < node->data) 
        {
            node->left = removeNode(node->left, val);
        } 
        else if (val > node->data) 
        {
            node->right = removeNode(node->right, val);
        } 
        else 
        {
            if (node->left == nullptr && node->right == nullptr) //лист
            {
                delete node; 
                return nullptr;
            }
            else if (node->left == nullptr) //один дочерний узел (правый)
            {
                Node* temp = node->right;  
                delete node;
                return temp;
            } 
            else if (node->right == nullptr) //один дочерний узел (левый)
            {
                Node* temp = node->left;
                delete node;
                return temp;
            } 
            else //два дочерних узла
            {
                Node* minNode = findMin(node->right);
                node->data = minNode->data;
                node->right = removeNode(node->right, minNode->data);
            }
        }
        return node;
    }

    
    Node* findMin(Node* node) 
    {
        while (node->left != nullptr) 
        {
            node = node->left;
        }
        return node;
    }

    
    void printTree(Node* node, string indent, bool last) 
    {
        if (node != nullptr) 
        {
            cout << indent;

            if (last) 
            {
                cout << "+-- ";  
                indent += "    ";  
            }
            else 
            {
                cout << "|-- ";
                indent += "|   "; 
            }

            cout << node->data << endl;

            
            printTree(node->right, indent, false);  
            printTree(node->left, indent, true);    
        }
    }

public:
    
    BinarySearchTree()
    {
        root = nullptr;
    }

    
    void insert(int val) 
    {
        root = insert(root, val);
    }

    
    void remove(int val) 
    {
        root = removeNode(root, val);
    }

    void printTree() 
    {
        printTree(root, "", true);
    }
};

int main() 
{
    BinarySearchTree tree;
    int choice, value;

    do 
    {
        cout << "\nМеню:\n";
        cout << "1. Вставить элемент\n";
        cout << "2. Удалить элемент\n";
        cout << "3. Вывести дерево\n";
        cout << "4. Выйти\n";
        cout << "Выберите действие: ";
        cin >> choice;

        switch (choice) 
        {
            case 1:
                cout << "Введите значение для вставки: ";
                cin >> value;
                tree.insert(value);
                cout << "Элемент " << value << " добавлен.\n";
                break;
            case 2:
                cout << "Введите значение для удаления: ";
                cin >> value;
                tree.remove(value);
                cout << "Элемент " << value << " удален.\n";
                break;
            case 3:
                cout << "Структура дерева:\n";
                tree.printTree();
                break;
            case 4:
                cout << "Выход из программы.\n";
                break;
            default:
                cout << "Неверный ввод. Попробуйте снова.\n";
        }
    } 
    while (choice != 4);

    return 0;
}
