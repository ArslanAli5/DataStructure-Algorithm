/******************************************************************************

Doubly Circular LINKED LIST implementation in C++
Name: Arslan Ali
Roll NO: SP19-BCS-103
Section: A
Assignment: 02

*******************************************************************************/

#include <iostream>
using namespace std;
template<class T>
class Node
{
	private:
		T data;
		Node* next;
		Node* prev;
	public:
		Node(T d)
		{
			data = d;
			next = NULL;
			prev = NULL;
		}
        void setData(T d)
        {
            data = d;
        }
        void setNext(Node* n)
        {
            next = n;
        }

        T getData()
        {
            return data;
        }
        Node* getNext()
        {
            return next;
        }
        void setPrev(Node* p)
        {
            prev = p;
        }
        Node* getPrev()
        {
            return prev;
        }

};

template <class T1>
class DEDL_List

{
    public:
        Node<T1>* head;
        Node<T1>* tail;
    public:
        // DEDL_List consturctor
        DEDL_List()
        {
            head=NULL;
            tail=NULL;
        }
        void addStart(T1 V)
        {
            Node<T1> *newNode = new Node<T1>(V);
            // If the list is empty
            if(head==NULL)
            {
                // Attaching head & tail to newNode
                head = newNode;
                tail = newNode;
                // Setting the newNode Previous & Next to pointer of NewNode
                head->setNext(head);
                head->setPrev(head);
            }
            // If there list is not empty
            else
            {
                // setting up previous and next of newNode
                newNode->setNext(head);
                newNode->setPrev(tail);
                // Update next and previous pointers of start and last

                tail->setNext(newNode);
                head->setPrev(newNode);

                //Update start pointer
                head = newNode;
            }
        }

        void addEnd(T1 V)
        {
            Node<T1> *newNode = new Node<T1>(V);
            if(head==NULL)
            {
                // Attaching head & tail to newNode
                head = newNode;
                tail = newNode;
                // Setting the newNode Previous & Next to pointer of NewNode
                head->setNext(head);
                head->setPrev(head);
            }
            else
            {
                // Setting tail to NewNodw
                tail->setNext(newNode);
                // Update next and previous pointers of newNode
                newNode->setPrev(tail);
                newNode->setNext(head);
                // Changing newNode head
                head->setPrev(newNode);
                tail = newNode;
            }
        }

        T1 removeStart()
        {
            Node<T1> *temp = head;
            // If the list is empty
            if (head == NULL)
            {
                return NULL;
            }
            // There is only one node
            else if (temp->getNext() == head)
            {
                head = NULL;
                tail = NULL;
                T1 data = temp->getData();
                free(temp);
                return data;
            }
            // If list has more than one node,
            else
            {
                head =head->getNext();

                head->setPrev(tail);

                tail->setNext(head);
                T1 data = temp->getData();
                free(temp);
                return data;
            }

        }

        T1 removeEnd()
        {
            Node<T1> *temp = tail;
            // If the list is empty
            if (head == NULL)
            {
                return NULL;
            }
            // If there is one node
            else if (temp->getPrev() == head)
            {
                head = NULL;
                tail = NULL;
                T1 data = temp->getData();
                free(temp);
                return data;
            }
            // check if it is the last node
            else
            {
                tail = tail->getPrev();

                tail->setNext(head);

                head->setPrev(tail);
                T1 data = temp->getData();
                free(temp);
                return data;
            }
        }

        T1 removeSecondLast()
        {
            Node<T1> *temp = tail; //,pre_1=NULL;
            Node<T1> *pre_1 = NULL;
            if (head == NULL)
            {
                return NULL;
            }
            else if (tail == head)
            {
                cout<<"There is only one node!"<<endl;
                return NULL;
            }
            else if (temp->getPrev() == head)
            {

                temp = head;

                head =head->getNext();

                head->setPrev(tail);

                tail->setNext(head);

                T1 data = temp->getData();
                free(temp);
                return data;


            }
            else
            {
                temp = temp->getPrev();
                pre_1 = temp->getPrev();
                pre_1->setNext(tail);
                tail->setPrev(pre_1);

                T1 data = temp->getData();
                free(temp);
                return data;
            }


        }

        void display()
        {
            Node<T1> *temp = head;

            cout<<"\nTraversal in forward direction \n";
            while (temp->getNext() != head)
            {
                cout<< temp->getData()<<" ";
                temp = temp->getNext();
            }
            cout<< temp->getData()<<" ";

            cout<<"\nTraversal in reverse direction \n";
            Node<T1> *last = head->getPrev();
            temp = last;
            while (temp->getPrev() != last)
            {
                cout<< temp->getData()<<" ";
                temp = temp->getPrev();
            }
            cout<<temp->getData()<<" "<<endl;
    }

};

class DEQUE_string
{
private:
    DEDL_List<string> data;
    int Size;
public:
    DEQUE_string()
    {
        this->Size = 0;
    }
     void enqueue_front(string s1)
    {
        data.addStart(s1);
        this->Size++;
    }

    void enqueue_back(string s1)
    {
        data.addEnd(s1);
        this->Size++;
    }

    string dequeue_front()
    {
        this->Size--;
        return data.removeStart();
    }

    string dequeue_back()
    {
        this->Size--;
        return data.removeEnd();
    }
    string peek_front()
    {
        return data.head->getData();
    }
    string peek_back()
    {
        return data.tail->getData();
    }
    int getSize()
    {
        return this->Size;
    }

};
int main()
{
    DEDL_List<string> l1;

    l1.addEnd("A");

    l1.addEnd("B");

    l1.addEnd("C");

    l1.addStart("D");

    l1.addStart("F");

    l1.display();
    DEQUE_string s1;
    s1.enqueue_front("First");
    s1.enqueue_front("Second");
    s1.enqueue_front("Third");
    s1.enqueue_back("One");
    s1.enqueue_back("Two");
    s1.enqueue_back("Three");
    s1.dequeue_back();
    s1.dequeue_front();
    cout<<"Peek Front: "<<s1.peek_front()<<endl;
    cout<<"Peek Back: "<<s1.peek_back()<<endl;
    cout<<"Size of Que: "<<s1.getSize()<<endl;

    return 0;
}
