#include <iostream>
#include <string>

using namespace std;

// Структура узла бинарного дерева
struct Node {
   int data;        // Данные, хранящиеся в узле
   Node* left;      // Левый потомок
   Node* right;     // Правый потомок

   // Конструктор для создания узла
   Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Класс для работы с бинарным деревом поиска
class BinarySearchTree {
private:
   Node* root;  // Корень дерева

   // Вспомогательная функция для вставки элемента в дерево (рекурсивно)
   Node* insert(Node* node, int val) {
       if (node == nullptr) {
           return new Node(val);
       }
       if (val < node->data) {
           node->left = insert(node->left, val);  // Вставка в левое поддерево
       }
       else if (val > node->data) {
           node->right = insert(node->right, val); // Вставка в правое поддерево
       }
       return node;
   }

   // Вспомогательная функция для красивого вывода дерева
   void printTree(Node* node, string indent, bool last) {
       if (node != nullptr) {
           cout << indent;

           if (last) {
               cout << "+-- ";  // Для последнего узла в поддереве
               indent += "    ";  // Добавляем отступы для следующего уровня
           }
           else {
               cout << "|-- ";  // Для промежуточных узлов
               indent += "|   ";  // Добавляем вертикальную линию для выравнивания
           }

           cout << node->data << endl;

           // Сначала выводим правое поддерево, потом левое
           printTree(node->right, indent, false);  // Правое поддерево
           printTree(node->left, indent, true);    // Левое поддерево
       }
   }

public:
   // Конструктор, инициализирующий корень дерева как пустой
   BinarySearchTree() : root(nullptr) {}

   // Функция для вставки элемента в дерево
   void insert(int val) {
       root = insert(root, val);
   }

   // Функция для вывода дерева в красивом формате
   void printTree() {
       printTree(root, "", true);
   }
};

int main() 
{

   BinarySearchTree tree;

   tree.insert(8);
   tree.insert(5);
   tree.insert(2);
   tree.insert(7);
   tree.insert(6);
   tree.insert(12);
   tree.insert(16);
   tree.insert(13);
   tree.insert(20);

   cout << "Tree structure:" << endl;
   tree.printTree();  // Красивый вывод дерева

   return 0;
}
