//Mahad Saleem // I210475@nu.edu.pk

template <class X>
struct Node
{
	X data;
	Node<X>* next;
};
template <class X>
class Queue
{

private:

public:
	Node<X>* front;
	Node<X>* rear;
	int size=0;
	Queue()
	{
		front = NULL;
		rear = NULL;
	}
	bool empty()
	{
		if (front == NULL && rear == NULL)
		{
			return true;
		}
		return false;
	}

	void Enqueue(X value)
	{
		Node<X>* temp = new Node<X>;
		temp->data = value;

		if (empty())
		{
			rear = temp;
			front = temp;
			temp->next = NULL;
		}
		else
		{
			rear->next = temp;
			temp->next = NULL;
			rear = temp;
		}
		size++;
	}
	void Dequeue()
	{
		if (empty())
			return;
		Node<X>* temp = new Node<X>;
		temp = front;
		if (front->next != NULL)
		{
			front = front->next;
		}
		else
		{
			front = NULL;
			rear = NULL;
		}
		delete temp;
		temp = NULL;
		size--;

	}
	X retFront()
	{
		Node<X>* temp = new Node<X>;
		temp = front;
		return temp->data;
	}

	bool search(X d)
	{
		if (empty())
			return false;
		Node<X>* temp = new Node<X>;
		temp = front;
		do
		{
			if (temp->data == d)
				return true;
			temp = temp->next;
		} while (temp);

		return false;
	}
	void print()
	{
		if (empty())
			return;
		Node<X>* temp = new Node<X>;
		temp = front;
		do
		{
			cout << temp->data << " ";
			temp = temp->next;
		} while (temp);
		cout << endl;
	}
};