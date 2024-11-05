#include <iostream>
using namespace std;

class Parenthesis {
	public:
		char arr[100];
		string exp;
		int n, max, top;
		
		Parenthesis() {
			top = -1;
		}
		
		void read() {
			cout << "Enter the expression." << endl;
			cin >> exp;
			
			n = exp.size();
		}
		
		int isFull() {
			max = sizeof(arr);
			if(top == (max-1)) {
				return 1;
			}
			else {
				return 0;
			}
		}
		
		int isEmpty() {
			if(top == -1) {
				return 1;
			}
			else {
				return 0;
			}
		}
		
		void push(char element) {
			if(isFull() == 0) {
				top++;
				arr[top] = element;
			}
		}
		
		char pop() {
			if(isEmpty() == 0) {
				top--;
				return arr[top+1];
			}
		}
							
		char check() {

			for (char ch : exp) {
        		if (ch == '(' || ch == '{' || ch == '[') {
            		push(ch);
        		} 
				else if (ch == ')' || ch == '}' || ch == ']') {
            		if (isEmpty() || (ch == ')' && pop() != '(') || 
					(ch == '}' && pop() != '{') || (ch == ']' && pop() != '['))
					{
                		cout << "Unbalanced." << endl;
						return 'U';
            		}
					pop();
        		}
    		}

			if(isEmpty() == 1) {
				cout << "Balanced." << endl;
				return 'B';
			}
			else
			{
            	cout << "Unbalanced." << endl;
				return 'U';
            }
		}
};

int main() {
	Parenthesis obj;
	obj.read();
	obj.check();
}			
