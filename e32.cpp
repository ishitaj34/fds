#include <iostream>
using namespace std;

class Pizza {
    public:
        int q[5], max, rear, front;

        Pizza() {
            rear = -1;
            front = -1;
            max = 5;
        }

        int isFull() {
            if(front == ((rear+1)%max))
                return 1;
            else
                return 0;
        }

        int isEmpty() {
            if(front == rear)
                return 1;
            else
                return 0;
        }

        void enqueue() {
            if(isFull() == 1)
                cout << "\nRestaurant has reached maximum capacity. Cannot accept more orders." << endl;
            else {
                if(front == -1) {
                    front = 0;
                    rear = 0;
                }
                else {
                    rear = (rear+1)%max;
                }

                cout << "Enter order number: ";
                cin >> q[rear];
                cout << "\nOrder accepted." << endl;
            }
        }

        void dequeue() {
            int n, x;
            if(isEmpty() == 1) {
                cout << "\nAll orders are complete." << endl;
                front = -1;
                rear = -1;
            }
            else {
                /*if(front == rear) {
                    front = -1;
                    rear = -1;
                }
                else {*/
                    cout << "\nEnter number of pizzas bought: ";
                    cin >> n;
                    cout << "Amount to be paid: " << 100*n << " rupees" << endl;

                    for(int i=0; i<n; i++) {
                        x = q[front];
                        front = (front+1)%max;
                    }
                    cout << "\nOrder completed." << endl;
                }
            }

        void display() {
            cout << "\nPending orders: " << endl;
            for(int i = front; i<=rear; i++) {
                cout << q[i] << " ";
            }
        }
};

int main() {
    int a, ch;
    char c;

    Pizza obj;
    cout << "\n\n* MENU *\n" << endl;
    cout << "1. Add order" << endl;
    cout << "2. Mark order complete" << endl;
    cout << "\n";

    a = 1;
    while(a==1) {
        cout << "\nEnter choice: ";
        cin >> ch;

        if(ch==1) {
            obj.enqueue();
            obj.display();
        }
        else if(ch==2) {
            obj.dequeue();
            obj.display();
        }

        cout << "\nEnter again (y/n)";
        cin >> c;
        if(c=='y')
            a = 1;
        else
            a = 0;

    }
}
