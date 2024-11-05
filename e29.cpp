#include <iostream>
using namespace std;

class Queue {
  public:
    int Q[10], max, rear, front;
    
    Queue() {
      rear = -1;
      front = -1;
      max = 10;
    }
    
    int isFull() {
      if(rear == (max-1)) {
        return 1;
      }
      else {
        return 0;
      }
    }
    
    int isEmpty() {
      if(rear == front) {
        return 1;
      }
      else {
        return 0;
      }
    }
    
    void enqueue() {
      if(isFull() == 1) {
        cout << "\nQueue is full. Insertion of job not possible." << endl;
      }
      else {
        if(front == -1) {
          front++;
        }

        rear++;
        cout << "\nEnter job." << endl;
        cin >> Q[rear];
        cout << "Job added." << endl;
      }
      
      cout << "\nModified job queue :" << endl;
      for(int i=0; i<(rear+1); i++) {
        cout << Q[i] << " ";
      }
    }
    
    void dequeue() {
      if(isEmpty() == 1) {
        cout << "\nQueue is empty. Deletion of job not possible." << endl;
      }
      else {
        int x = Q[front];
        front++;
        cout << "Job deleted." << endl;
      }
      
      cout << "\nModified queue :" << endl;
      for(int i=front; i<(rear+1); i++) {
        cout << Q[i] << " ";
      } 
    }
};

int main() {
  int a, ch;
  Queue obj;
  
  cout << "\n\nMENU\n" << endl;
  cout << "1. Add job" << endl;
  cout << "2. Delete job" << endl;
  cout << "\nEND\n" << endl;
  
  a = 1;
  while(a==1) {
    cout << "\nEnter your choice: ";
    cin >> ch;
    
    switch(ch) {
      case 1:
        	obj.enqueue();
        	break;
      case 2:
        	obj.dequeue();
        	break;
      default:
        	cout << "\nInvalid choice. Please try again." << endl;
        	break;  
    }
    
    string ans;
    cout << "\nDo you want to choose again? (enter yes/no)" << endl;
    cin >> ans;
    if(ans == "yes") {
      a = 1;
    }
    else {
      a = 0;
      cout << "\nThank you!" << endl;
    }
  }
}
