//#include <iostream>
//#include <string>
//using namespace std;
//
//template<typename T>
//struct node
//{
//	T value;
//	node* next;
//
//	node(const T& value)
//	{
//		this->value = value;
//		this->next = nullptr;
//	}
//};
//
//template<typename T>
//struct bucket
//{
//public:
//
//	node<T>* head;
//	node<T>* tail;
//
//	bucket()
//	{
//		head = nullptr;
//		tail = nullptr;
//	}
//
//	bool isInSet(const T& value)
//	{
//		if (isEmpty()) return false;
//
//		node<T>* currentNode = head;
//		while (currentNode && currentNode->value != value) currentNode = currentNode->next;
//		if (currentNode && currentNode->value == value) return true;
//		return false;
//	}
//
//	T get(const T& value)
//	{
//		if (isEmpty()) return false;
//
//		node<T>* currentNode = head;
//		while (currentNode && currentNode->value != value) currentNode = currentNode->next;
//		if (currentNode && currentNode->value == value) return currentNode->value;
//		throw runtime_error("Value not found");
//	}
//
//	void push(const T& value)
//	{
//		node<T>* newNode = new node<T>(value);
//		if (isEmpty())
//		{
//			head = newNode;
//			tail = newNode;
//			return;
//		}
//		tail->next = newNode;
//		tail = newNode;
//	}
//
//	void remove(const T& value)
//	{
//		if (isEmpty()) return;
//		
//		if (head->value == value)
//		{
//			node<T>* temp = head;
//			head = head->next;
//			delete temp;
//
//			if (head == nullptr) tail = nullptr;
//			return;
//		}
//
//		node<T>* prev = head;
//		node<T>* current = head->next;
//
//		while (current)
//		{
//			if (current->value == value)
//			{
//				prev->next = current->next;
//				if (current == tail) tail = prev;
//				delete current;
//				return;
//			}
//			prev = current;
//			current = current->next;
//		}
//	}
//
//	void print()
//	{
//		if (isEmpty()) return;
//
//		node<T>* current = head;
//		while (current)
//		{
//			cout << "[ " << current->value << " ] ";
//			current = current->next;
//		}
//	}
//
//
//
//	bool isEmpty()
//	{
//		return head == nullptr;
//	}
//};
//
//
//template<typename T>
//struct set
//{
//private:
//
//	int memoryCapacity;
//	int currentSize;
//	bucket<T>* arr;
//
//	int hash(const std::string& value) const
//	{
//		int hash = 5381;
//		for (char c : value)
//		{
//			hash = ((hash << 5) + hash) + c;
//		}
//		return hash % memoryCapacity;
//	}
//
//public:
//
//	set()
//	{
//		arr = new bucket<T>[10];
//		memoryCapacity = 1;
//		currentSize = 0;
//	}
//
//	set(int sizeVal)
//	{
//		arr = new bucket<T>[sizeVal];
//		memoryCapacity = sizeVal;
//		currentSize = 0;
//	}
//
//	~set()
//	{
//		delete[] arr;
//	}
//
//	void SPUSH(const T& value)
//	{
//		int index = hash(value);
//		if (arr[index].isInSet(value)) return;
//		else
//		{
//			arr[index].push(value);
//			currentSize++;
//		}
//	}
//
//	void SDEL(const T& value)
//	{
//		int index = hash(value);
//		if (!arr[index].isInSet(value)) return;
//		arr[index].remove(value);
//		currentSize--;
//		
//	}
//
//	int size()
//	{
//		return currentSize;
//	}
//
//	bool check(const T& value) const
//	{
//		int index = hash(value);
//		return arr[index].isInSet(value);
//	}
//
//	void print()
//	{
//		for (int i = 0; i < memoryCapacity; i++)
//		{
//			if (!arr[i].isEmpty())
//			{
//				arr[i].print();
//				cout << " ";
//			}
//		}
//	}
//
//	friend void compareGenes(const set<string>& firstChain, const set<string>& secondChain);
//};
//
//
//set<string> divideGenes(const string& geneChain)
//{
//	set<string> genes(10);
//	for (int i = 0; i < geneChain.size() - 1; i++)
//	{
//		if (65 <= geneChain[i] && geneChain[i] <= 90)
//		{
//			if (65 <= geneChain[i+1] && geneChain[i+1] <= 90)
//			{
//				genes.SPUSH(string(1,geneChain[i]) + string(1,geneChain[i + 1]));
//			}
//			else
//			{
//				cout << "Broken gene detected" << endl;
//				exit(0);
//			}
//		}
//		else
//		{
//			cout << "Broken gene detected" << endl;
//			exit(0);
//		}
//		
//	}
//	return genes;
//}
//
//
//void compareGenes(const set<string>& firstChain, const set<string>& secondChain)
//{
//	int matches = 0;
//
//	for (int i = 0; i < firstChain.memoryCapacity; i++)
//	{
//		if (!firstChain.arr[i].isEmpty())
//		{
//			node<string>* current = firstChain.arr[i].head;
//			while (current)
//			{
//				if (secondChain.check(current->value))
//				{
//					matches++;
//				}
//				current = current->next;
//			}
//		}
//	}
//	cout << "Число совпадающих уникальных генов: " << matches << endl;
//}
//
//
//int main()
//{
//	setlocale(LC_ALL, "RU");
//	set<string> test1 = divideGenes("ABBACAB");
//	set<string> test2 = divideGenes("BCABB");
//	
//	compareGenes(test1, test2);
//
//	return 0;
//}