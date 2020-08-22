#include <iostream>
#include <string>
using namespace std;
template <class T>
class Stack_List
{
private:
	struct Node
	{
		T value;
		Node* next;
	};
	Node* head;
	int size;
public:
	Stack_List() :size(0), head(nullptr)
	{	}
	void Push(T num)
	{
		Node* newElem = new Node;
		newElem->value = num;
		newElem->next = nullptr;

		if (head == nullptr)
		{
			head = newElem;
		}
		else
		{
			Node* current = head;
			while (current->next != nullptr)
			{
				current = current->next;
			}
			current->next = newElem;
		}
		this->size = size + 1;
	}
	void Pop()
	{
		if (head == nullptr)
		{
			return;
		}
		if (head->next == nullptr)
		{
			delete head;
			head = nullptr;
		}
		else
		{
			Node* current = head;
			while (current->next->next != nullptr)
			{
				current = current->next;
			}
			delete current->next;
			current->next = nullptr;
		}
		this->size = size - 1;
	}
	void Peek() const
	{
		Node* current = head;
		int count = 0;
		while (current != nullptr)
		{
			if (count + 1 == size)
			{
				cout <<"Result peek: "<< current->value << "  ";
			}
			count++;
			current = current->next;
		}
		cout << endl;
	}
	void Print() const
	{
		Node* current = head;
		int h = 0;
		while (current != nullptr)
		{
			if (h + 1 == size)
			{
				cout << current->value << "  ";
			}
			else
			{
				cout << current->value << ", ";
			}
			h++;
			current = current->next;
		}
		cout << "\nSize: " << size << endl;
	}
	bool IsEmpty() const
	{
		return head == nullptr;
	}
	~Stack_List()
	{
		while (!IsEmpty())
		{
			Pop();
		}
	}
};


int main()
{
	Stack_List<int> s1;
	s1.Push(32);
	s1.Push(52);
	s1.Push(312);
	s1.Push(33);
	s1.Print();
	s1.Pop();
	s1.Print();
	cout << endl;
	s1.Peek();

	system("pause");
	return 0;
}