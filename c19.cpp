/* Department of Computer Engineering has student's club named 'Pinnacle Club'. Students of second, third 
and final year of department can be granted membership on request. Similarly one may cancel the membership 
of club. First node is reserved for president of club and last node is reserved for secretary of club. 
Write C++ program to maintain club member‘s information using singly linked list. Store student PRN and Name. 
Write functions to:
a) Add and delete the members as well as president or even secretary.
b) Compute total number of members of club
c) Display members
d) Two linked lists exists for two divisions. Concatenate two lists. */ 

#include <iostream>
using namespace std;

// To define a node of a linked list.
class node {
    public:
        int prn;
        string name;
        node *next;

        // Default constructor to initialise values.
        node() {
            prn = 0;
            name = " ";
            next = NULL;
        }

        // To assign value of parameter(eg. prn) to data member(eg. prn) of current object('this' points to current object).
        node(int prn, string name) {
            this->prn = prn;
            this->name = name;
            this->next = NULL;
        }
};

class list {
    public:
        node *head, *temp;

        list() {
            head = NULL;
        }

        node* create(int val, string n);
        void insertBeg();
        void insertEnd();
        void insertMid();
        void deleteBeg();
        void deleteEnd();
        void deleteMid();
        void countMembers();
        void display();
        void concatenate(node *head1, node *head2);
};

// To create a LL consisting of a single node.
node* list :: create(int val, string n) {
    temp = new node;

    if(temp == NULL) {
        cout << "\nMemory allocation failed." << endl;
        return 0;
    }
    else {
        temp->prn = val;
        temp->name = n;
        temp->next = NULL;
        return temp;
    }
}

// To add president of club to the LL.
void list :: insertBeg() {
    int val;
    string n;

    cout << "\nEnter PRN of the student: ";
    cin >> val;
    cout << "Enter name of the student: ";
    cin >> n;

    //node *t = head; // To create a temporary pointer for traversing LL.
    temp = create(val, n); // Calls function to create one node.

    if(head == NULL) { // To check if LL is empty.
        head = temp; // If empty, new node is assigned to head.
        head->next = NULL;
    }
    else { 
        temp->next = head; // If not empty, set next of new node to point to current head.
        head = temp; // Make the new node the new head of the LL.
    }

    cout << "\nWe have a new President." << endl;
}

// To add secretary of club to the LL.
void list :: insertEnd() {
    int val;
    string n;

    cout << "\nEnter PRN of the student: ";
    cin >> val;
    cout << "Enter name of the student: ";
    cin >> n;

    node *t = head; // To create a temporary pointer for traversing LL.
    temp = create(val, n); // Calls function to create one node.

    if(head == NULL) { // To check if LL is empty.
        head = temp; // If empty, new node is assigned to head.
        head->next = NULL;
    }
    else { 
        // If not empty, traverse till end of LL.
        while(t->next != NULL) {
            t = t->next;
        }
        t->next = temp; // Set next of last node to new node.
        temp->next = NULL; // Set next of new last node to null to indicate end of singly LL.
        cout << "\nInformation of secretary inserted at the last node.\n" << endl;
    }
}

// To add members of the club to the LL.
void list :: insertMid() {
    int val, pos;
    string n;

    cout << "\nEnter PRN of the student: ";
    cin >> val;
    cout << "Enter name of the student: ";
    cin >> n;
    cout << "Enter position to add student: ";
    cin >> pos;

    node *member = create(val, n); // Calls function to create a new node.
    temp = head;

    if(pos <= 0) {
        cout << "\nInvalid position. Member not added." << endl;
    } 
    else if(head == NULL) {
        cout << "\nList is empty. Member not added." << endl;
    }
    else {
        for(int i = 1; i < pos - 1; i++) {
            temp = temp->next;
        }

        if(temp == NULL) {
            cout << "\nInvalid position. Member not added." << endl;
        }
        else {
            /* 'next' pointer of the new member node is assigned the value of the next pointer of the 
            current temp node. Links new node(member) to the node that was originally at position 'pos'. */
            member->next = temp->next;
            /* The 'next' pointer of the current temp node is assigned value of the member node.
            It inserts the new member node into LL at position pos. It makes the member node the successor 
            of the current temp node. */
            temp->next = member;
            cout << "\nMember added at position " << pos << "." << endl;

            /* Before insertion: temp  temp->next
               After insertion : temp  member      temp->next/member->next */
        }
    }
}

// To delete president of club from LL.
void list :: deleteBeg() {
    if(head == NULL) {
        cout << "\nList is empty. President cannot be deleted." << endl;
    }
    else {
        temp = head; // temp stores current head.
        head = head->next; // head stores data of second node, therefore, new head = second node.
        delete temp; // og head is deleted.

        cout << "\nPresident deleted." << endl;
    }
}

// To delete secretary of club from LL.
void list :: deleteEnd() {
    if(head == NULL) {
        cout << "\nList is empty. Secretary cannot be deleted." << endl;
    }
    else {
        /* Two pointers 'prev' and 'current' are used to traverse the list until current points to the last 
        node, and prev points to the second last node. */
        node *prev = NULL;
        node *current = head;

        while(current->next != NULL) {
            prev = current;
            current = current->next;
        }

        // If there is only one node in the LL.
        if (prev == NULL) {
            delete head;
            head = NULL;
        } 
        /* The next pointer of prev is set to NULL, disconnecting the last node from the list. The last 
        node(current) is then deleted. */
        else {
            prev->next = NULL;
            delete current;
        }

        cout << "\nSecretary deleted." << endl;
    }
}

// To delete members of club from LL using PRN.
void list :: deleteMid() {
    if(head == NULL) {
        cout << "\nList is empty. Club member cannot be deleted." << endl;
    }
    else {
        node *prev = NULL;
        node *current = head; // To traverse LL.

        int val;
        cout << "\nEnter PRN of member to be deleted: ";
        cin >> val;

        // Till current stores data of student whose PRN is specified.
        while(current != NULL && current->prn != val) {
            prev = current;
            current = current->next;
        }

        if(current == NULL) { // If not found.
            cout << "\nInvalid PRN. Member not found." << endl;
        } 
        else {
            if (prev == NULL) { // If node to be deleted is the first node.
                head = current->next; // Points to second node, removing data of first node from head.
            } 
            else {
                prev->next = current->next; // Skips current node and points to next node.
            }

            delete current;
            cout << "\nClub member deleted." << endl;
        }
    }
}   

// To compute total number of members in the club.
void list :: countMembers() {
    int count = 0;
    temp = head;

    while(temp != NULL) {
        count++;
        temp = temp->next; // Moves to next node after each iteration till end of LL.
    }

    cout << "\nTotal members part of the Pinnacle Club are " << count << "." << endl;
}

// To display members of the club.
void list :: display() {
    if(head == NULL) {
        cout << "\nList is empty." << endl;
    }
    else {
        temp = head;
        cout << "\n* Members of the Pinnacle Club *" << endl;
        while(temp != NULL) {
            cout << "\nPRN : " << temp->prn << endl;
            cout << "Name : " << temp->name << endl;
            temp = temp->next;
        }
    }
}

// To concatenate two linked lists
void list :: concatenate(node *head1, node *head2) {
    temp = head1;

    if(head1 == NULL) { // If first list is empty, return head of the second list.
        head = head2;
    }
    else if(head2 == NULL) {
        head = head1;
    }
    else {
        while(temp->next != NULL) { // To traverse first LL to find its last node.
            temp = temp->next;
        }

        temp->next = head2; // Append second LL to first LL.

        head = head1; // To return head of the concatenated linked list.
    }
}


int main() {
    int a, b, ch1, ch2;
    char ans1, ans2;
    
    cout << "\nWelcome to the Pinnacle Club. Choose from the following to perform an operation:\n" << endl;
    cout << "1. Appoint new president" << endl;
    cout << "2. Appoint new secretary" << endl;
    cout << "3. Add a new member" << endl;
    cout << "4. Remove president" << endl;
    cout << "5. Remove secretary" << endl;
    cout << "6. Remove club members" << endl;
    cout << "7. View number of members part of the club" << endl;
    cout << "8. View members of the club" << endl;
    cout << "9. To make another list for another division" << endl;
    cout << "10. To concatenate two lists" << endl;

    list div1, div2;

    a = 1;
    while(a == 1) {
        cout << "\nEnter your choice: ";
        cin >> ch1;

        switch(ch1) {
            case 1:
                div1.insertBeg();
                break;

            case 2:
                div1.insertEnd();
                break;

            case 3:
                div1.insertMid();
                break;

            case 4:
                div1.deleteBeg();
                break;

            case 5:
                div1.deleteEnd();
                break;
            
            case 6:
                div1.deleteMid();
                break;

            case 7:
                div1.countMembers();
                break;

            case 8:
                div1.display();
                break;

            case 9:
                b = 1;
                while(b == 1) {
                    cout << "\nEnter your choice for second list (1-6): ";
                    cin >> ch2;

                    switch(ch2) {
                        case 1:
                            div2.insertBeg();
                            break;

                        case 2:
                            div2.insertEnd();
                            break;

                        case 3:
                            div2.insertMid();
                            break;

                        case 4:
                            div2.deleteBeg();
                            break;

                        case 5:
                            div2.deleteEnd();
                            break;
            
                        case 6:
                            div2.deleteMid();
                            break;

                        case 7:
                            div2.countMembers();
                            break;

                        case 8:
                            div2.display();
                            break;

                        default:
                            cout << "\nInvalid choice." << endl;
                            break;
                    }

                    cout << "\nWould you like to choose again? (enter y/n): ";
                    cin >> ans2;
                    if(ans2 == 'y') {
                        b = 1;
                    }
                    else {
                        b = 0;
                        cout << "\nList for division 2 created!";
                    }
                }
                break;
            
            case 10:
                div1.concatenate(div1.head, div2.head);
                cout << "\nLists concatenated successfully." << endl;
                div1.display();
                break;

            default:
                cout << "\nInvalid choice." << endl;
                break;
        }

        cout << "\nWould you like to choose again? (enter y/n): ";
        cin >> ans1;
        if(ans1 == 'y') {
            a = 1;
        }
        else {
            a = 0;
            cout << "\nThank you!" << endl;
        }
    }
}
