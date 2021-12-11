#include <iostream>

using namespace std;

template<typename T>
class List {

private:
	template<typename T>
	class Node {
	public:
		T data;
		Node* pNext;
		Node* pPrevious;
		Node(T data = T(), Node* pNext = nullptr, Node* pPrevious = nullptr) {
			this->data = data;
			this->pNext = pNext;
			this->pPrevious = pPrevious;
		}
	};

public:
	Node<T>* head;
	Node<T>* tail;
	int size;
	List();
	~List();
	int GetSize() { return size; }
	//void push_back(T data);
	void push_front(T data);
	void RemoveAt(const int index);
	T& operator[](const int index);
};

template<typename T>
List<T>::List()
{
	head = nullptr;
	tail = nullptr;
	size = 0;
}

template<typename T>
List<T>::~List()
{
}

template<typename T>
void List<T>::push_front(T data)
{
	if (head == nullptr) {
		head = new Node<T>(data);
		tail = head;
	}
	else {
		Node<T>* currentF = head;

		while (currentF->pNext != nullptr) {
			currentF = currentF->pNext;
		}
		currentF->pPrevious = currentF;
		currentF->pNext = new Node<T>(data);
		tail = currentF->pNext;
	}
	size++;
}

template<typename T>
void List<T>::RemoveAt(const int index)
{
	if (index == 0) {
		head = head->pNext;
		tail = tail->pPrevious;
	}
	else {
		Node<T>* currentF = head;
		for (int i = 0; i < index - 1; ++i) {
			currentF = currentF->pNext;
	}
		Node<T>* toDelete = currentF->pNext;
		currentF->pNext = toDelete->pNext;
		currentF->pPrevious = toDelete->pPrevious;
	}
	size--;
}

template<typename T>
T& List<T>::operator[](const int index)
{
	int count = 0;
	Node<T>* currentF = head;
	while (currentF->pNext != nullptr) {
		if (count == index) {
			return currentF->data;
		}
		currentF = currentF->pNext;
		count++;
	}
}

int main() {
	List<int> lst;
	lst.push_front(10);
	lst.push_front(20);
	lst.push_front(30);

	for (int i = 0; i < lst.GetSize(); i++)
	{
		cout << lst[i] << ' ';
	}
	
	return 0;
}
