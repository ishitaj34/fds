/*A double-ended queue (deque) is a linear list in which additions and deletions may be
made at either end. Obtain a data representation mapping a deque into a onedimensional array. Write C++ program to simulate deque with functions to add and
delete elements from either end of the deque.*/


#include <iostream>
#define size 5
using namespace std;
class queue
{
    int f = -1, r = -1;
    int q[size];

public:
    int isfull()
    {
        return (r >= size-1) ? 1 : 0;
    }
    int isempty()
    {
        return (f == -1) ? 1 : 0;
    }
    void add_front(int x)
    {
        if (f == -1)
        {
            f++;
            r++;
            q[r] = x;
        }
        else if (f != 0)
        {
            f--;
            q[f] = x;
        }
        else
        {
            cout << "Queue is overflow..." << endl;
        }
    }
    void add_rear(int x)
    {
        if (isfull() == 1)
        {
            cout << "Queue is overflow " << endl;
        }
        else
        {
            if (f == -1)
            {
                f++;
            }
            r++;
            q[r] = x;
        }
    }
    void del_front()
    {
        if (isempty() == 1)
        {
            cout << "Queue is underflow " << endl;
        }
        else
        {
            if (f == r)
            {
                cout << q[f] << " Deleted " << endl;
                f = r = -1;
            }
            else
            {
                cout << q[f] << " Deleted " << endl;
                f++;
            }
        }
    }
    void del_rear()
    {
        if (isempty() == 1)
        {
            cout << "Queue is underflow " << endl;
        }
        else
        {
            if (f == r)
            {
                cout << q[r] << " Deleted " << endl;
                f = r = -1;
            }
            else
            {
                cout << q[r] << " Deleted " << endl;
                r--;
            }
        }
    }
    void display()
    {
        if (isempty() == 1)
        {
            cout << "Queue is underflow ";
        }
        else
        {
            for (int i = f; i <= r; i++)
            {
                cout << q[i] << " ";
            }
            cout << endl;
        }
    }
};
int main()
{
    queue o;
    int ch;
    int x;
    char ch1;
    do
    {
        cout<<endl;
        cout << "1)Add front\n2)Add rear\n3)Del front\n4)Del rear\n5)Display" << endl;
        cout << "Enter choice : ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "Enter value : ";
            cin >> x;
            o.add_front(x);
            break;
        case 2:
            cout << "Enter value : ";
            cin >> x;
            o.add_rear(x);
            break;
        case 3:
            o.del_front();
            break;
        case 4:
            o.del_rear();
            break;
        case 5:
            o.display();
            break;
        default:
            cout << "Enter valid choice : ";
            break;
        }
        cout << "Do you want to continue (y/n) : ";
        cin >> ch1;
    } while (ch1 == 'y');
}
