#include <iostream>
using namespace std;

#define MAX 100

class Stack {
private:
    int arr[MAX];
    int top;

public:
    Stack() {
        top = -1;
    }

    void push(int x) {
        if (top >= MAX - 1) {
            cout << "Stack Overflow!\n";
        } else {
            arr[++top] = x;
            cout << x << " pushed to stack.\n";
        }
    }

    void pop() {
        if (top < 0) {
            cout << "Stack Underflow!\n";
        } else {
            cout << arr[top--] << " popped from stack.\n";
        }
    }

    void peek() {
        if (top < 0) {
            cout << "Stack is empty!\n";
        } else {
            cout << "Top element is: " << arr[top] << endl;
        }
    }

    void display() {
        if (top < 0) {
            cout << "Stack is empty!\n";
        } else {
            cout << "Stack elements are:\n";
            for (int i = top; i >= 0; i--) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Stack s;
    int choice, value;

    do {
        cout << "\n*** Stack Menu ***\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                s.push(value);
                break;
            case 2:
                s.pop();
                break;
            case 3:
                s.peek();
                break;
            case 4:
                s.display();
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 5);

    return 0;
}
