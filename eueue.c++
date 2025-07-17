#include <iostream>
using namespace std;

const int MAX_SIZE = 20;

class Queue {
  int arr[MAX_SIZE];
  int front, rear;
public:
  Queue() : front(-1), rear(-1) {}

  bool isEmpty() const { return front == -1; }
  bool isFull() const { return rear == MAX_SIZE - 1; }
  int size() const {
    if (isEmpty()) return 0;
    return rear - front + 1;
  }

  void enqueue(int x) {
    if (isFull()) {
      cout << "Queue overflow!\n";
      return;
    }
    if (isEmpty()) front = 0;
    arr[++rear] = x;
    cout << x << " enqueued.\n";
  }

  void dequeue() {
    if (isEmpty()) {
      cout << "Queue underflow!\n";
      return;
    }
    int x = arr[front++];
    cout << x << " dequeued.\n";
    if (front > rear) front = rear = -1;
  }

  void display() const {
    if (isEmpty()) {
      cout << "Queue is empty.\n";
      return;
    }
    cout << "Queue contents: ";
    for (int i = front; i <= rear; i++) cout << arr[i] << ' ';
    cout << "\n";
  }
};

int main() {
  Queue q;
  int choice, val;
  do {
    cout << "\n--- Queue Menu ---\n"
         << "1. Enqueue\n"
         << "2. Dequeue\n"
         << "3. Display\n"
         << "4. Count elements\n"
         << "5. Check if empty\n"
         << "6. Exit\n"
         << "Enter choice: ";
    cin >> choice;

    switch (choice) {
      case 1:
        cout << "Enter value to enqueue: ";
        cin >> val;
        q.enqueue(val);
        break;
      case 2:
        q.dequeue();
        break;
      case 3:
        q.display();
        break;
      case 4:
        cout << "Number of elements: " << q.size() << "\n";
        break;
      case 5:
        cout << (q.isEmpty() ? "Queue is empty\n" : "Queue is not empty\n");
        break;
      case 6:
        cout << "Bye!\n";
        break;
      default:
        cout << "Invalid choice. Try again.\n";
    }
  } while (choice != 6);

  return 0;
}
