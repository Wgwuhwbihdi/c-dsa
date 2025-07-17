#include <iostream>
using namespace std;

#define SIZE 5

class CircularQueue
{
private:
    int queue[SIZE];
    int front, rear;

public:
    CircularQueue()
    {
        front = -1;
        rear = -1;
    }

    bool isFull()
    {
        return (front == (rear + 1) % SIZE);
    }

    bool isEmpty()
    {
        return (front == -1);
    }

    void enqueue(int value)
    {
        if (isFull())
        {
            cout << "Queue is Full (Overflow)!\n";
        }
        else
        {
            if (isEmpty())
            {
                front = 0;
            }
            rear = (rear + 1) % SIZE;
            queue[rear] = value;
            cout << value << " enqueued to the queue.\n";
        }
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty (Underflow)!\n";
        }
        else
        {
            cout << queue[front] << " dequeued from the queue.\n";
            if (front == rear)
            {
                front = rear = -1; // Queue is now empty
            }
            else
            {
                front = (front + 1) % SIZE;
            }
        }
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is empty!\n";
        }
        else
        {
            cout << "Queue elements: ";
            int i = front;
            while (true)
            {
                cout << queue[i] << " ";
                if (i == rear)
                    break;
                i = (i + 1) % SIZE;
            }
            cout << endl;
        }
    }
};

int main()
{
    CircularQueue cq;
    int choice, value;

    do
    {
        cout << "\n--- Circular Queue Menu ---\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to enqueue: ";
            cin >> value;
            cq.enqueue(value);
            break;
        case 2:
            cq.dequeue();
            break;
        case 3:
            cq.display();
            break;
        case 4:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 4);

    return 0;
}
