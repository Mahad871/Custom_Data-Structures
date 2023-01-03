//Mahad Saleem // I210475@nu.edu.pk
template <class X>
struct QNode
{
	X data;
	QNode<X>* next;
};
template <class X>
class Queue
{

private:

public:
	QNode<X>* front;
	QNode<X>* rear;
	int size = 0;
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
		QNode<X>* temp = new QNode<X>;
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
		QNode<X>* temp = new QNode<X>;
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
		QNode<X>* temp = new QNode<X>;
		temp = front;
		return temp->data;
	}

	bool search(X d)
	{
		if (empty())
			return false;
		QNode<X>* temp = new QNode<X>;
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
		QNode<X>* temp = new QNode<X>;
		temp = front;
		do
		{
			cout << temp->data << " ";
			temp = temp->next;
		} while (temp);
		cout << endl;
	}
};