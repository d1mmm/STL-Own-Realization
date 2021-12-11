#include <iostream>

using namespace std;

template<typename T>
class ForwardList {

private:
	template<typename T>
	class Node {
	public:
		T data;
		Node* pNext;
		Node(T data = T(), Node* pNext = nullptr) {
			this->data = data;
			this->pNext = pNext;
		}
	};

public:
	Node<T>* head;
	int size;
	ForwardList();
	~ForwardList();
	int GetSize() { return size; }
	void push_back(T data);
	void pop_back();
	void push_front(T data);
	void pop_front();
	T& operator[](const int index);
	void removeAt(const int index);
	int FindMax();
};

template<typename T>
ForwardList<T>::ForwardList()
{
	head = nullptr;
	size = 0;
}

template<typename T>
ForwardList<T>::~ForwardList()
{
	while (size)
	{
		pop_front();
	}
}

template<typename T>
void ForwardList<T>::push_back(T data)
{
	if (head == nullptr) {
		head = new Node<T>(data);
	}
	else {
		Node<T>* current = head;
		while (current->pNext != nullptr) {
			current = current->pNext;
		}
		current->pNext = new Node<T>(data);
	}
	size++;
}

template<typename T>
void ForwardList<T>::pop_back()
{
	Node<T>* current = head;
	while (current->pNext != nullptr) {
		current = current->pNext;
	}
	current->pNext = current->pNext;
	size--;
}

template<typename T>
void ForwardList<T>::push_front(T data)
{
	head = new Node<T>(data, head);
	size++;
}

template<typename T>
void ForwardList<T>::pop_front()
{
	head = head->pNext;
	size--;
}

template<typename T>
T& ForwardList<T>::operator[](const int index)
{
	int count = 0;
	Node<T>* current = head;
	while (current->pNext != nullptr) {
		if (count == index) {
			return current->data;
		}
		current = current->pNext;
		count++;
	}
}

template<typename T>
void ForwardList<T>::removeAt(const int index)
{
	int count = 0;

	if (index == 0) {
		head = head->pNext;
	}
	else {
		Node<T>* previous = head;
		for (int i = 0; i < index - 1; ++i) {
			previous = previous->pNext;
		}
		Node<T>* toDelete = previous->pNext;
		previous->pNext = toDelete->pNext;
	}
	size--;
}

template<typename T>
int ForwardList<T>::FindMax()
{
	int max = head->data;
	Node<T>* current = head;

	for (int i = 0; i < size; ++i)
	{
		if (max < current->data) {
			max = current->data;
		}
		current = current->pNext;
	}
	return max;
}



int main() {
	ForwardList<int> lst;
	lst.push_back(10);
	lst.push_back(40);
	lst.push_back(70);
	lst.push_back(30);

	
	for (int i = 0; i < lst.GetSize(); i++)
	{
		cout << lst[i] << ' ';
	}
	cout << lst.FindMax();

	return 0;
}