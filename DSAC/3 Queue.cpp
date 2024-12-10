#include <iostream>
#define SIZE 3

using namespace std;

class Queue {
private:
    int items[SIZE], front, rear;

public:
    Queue()
    {
        front = -1;
        rear = -1;
    }
    bool isFull()
    {
        if (front == 0 && rear == SIZE - 1)

        {
            return true;
        }
        if (front == rear + 1)
        {
            return true;
        }
        return false;
    }

    bool isEmpty()
    {
        if (front == -1)
            return true;
        else
            return false;
    }

    void enQueue(int element)
    {
        if (isFull())
        {
            cout << "Queue is full";

        }
        else
        {
            if (front == -1)
                front = 0;
            rear = (rear + 1) % SIZE;
            items[rear] = element;
            cout << endl<< "Inserted " <<element << endl;
        }
    }

    int deQueue()
    {
        int element; 
        if (isEmpty())
        {
              return -1;
        }
        else
        {
            element = items[front];  ///11 12 13
            if (front == rear)
            {
                front = -1;
                rear = -1;
            }
            else
            {
                front = (front + 1) % SIZE;   //0+1%3=1  1+1%3=2
            }
            return (element);
        }
    }

    void display()
    {

        int i;
        if (isEmpty())
        {
            cout << endl<< "Empty Queue" << endl;
        }
        else
        {
            cout << "\n Front -> " << front<<endl;

            cout << "\nItems -> ";

            if(front==rear)
                cout << "\t"<<items[front];
            else
            {
                for (i = front; i != rear; i = (i + 1) % SIZE)
                            {

                                cout << "\t"<<items[i];
                            }
                cout << "\t"<<items[i];
            }
            cout <<endl<< "\n Rear -> " << rear<<endl<<endl;
        }
    }
};

int main()
{
    Queue q;
    int ch;
    int ele,r;
do
{
    cout<<"\n------------------menu--------";
    cout<<"\n1.enqueue\n2.dequeue\n3.display";
    cout<<"\n Enter choice";
     cin>>ch;


        switch(ch)
        {
        case 1:
            cout<<"\nEnter the element for enqueue";
            cin>>ele;
            q.enQueue(ele);
           break;
        case 2:
            r=q.deQueue();
            if(r==-1)
                cout<<"\n Queue empty";
            else
            cout<<"\n dequeue element"<<r;
            break ;
        case 3:
           cout<<"\n Queue elements are";
             q.display();
             break;


          }
        }while(ch!=4);

    return 0;

}

