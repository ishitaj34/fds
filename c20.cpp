/* The ticket booking system of Cinemax theater has to be implemented using C++ program.
There are 10 rows and 7 seats in each row. Doubly circular linked list has to be maintained
to keep track of free seats at rows. Assume some random booking to start with. Use array to store
pointers (Head pointer) to each row. On demand:
a) The list of available seats is to be displayed
b) The seats are to be booked
c) The booking can be cancelled */

#include <iostream>
#include <stdlib.h>
using namespace std;

/* 'node' is a class that represents a node in a doubly circular linked list for the Cinemax theater program.
next: a pointer to the next node in the linked list.
prev: a pointer to the previous node in the linked list.
seat: an integer representing the seat number.
status: an integer(0 or 1) representing the status of the seat(booked/not booked).
id: a string representing the ID associated with the booked seat. */
class node { 
    public:
        node *next;
        node *prev;
        int seat, status;
        string id;
};

/* 'cinemax' is a class that represents the Cinemax theater.
head: a pointer to the first node in the doubly circular linked list.
tail: a pointer to the last node in the doubly circular linked list.
temp: a temporary pointer used in various methods. */
class cinemax {
    public:
        node *head, *tail, *temp;

        cinemax() {
            head = NULL;
        }

        void create_list();
        void display();
        void book();
        void cancel();
        void avail();
};

// To create a DCLL representing seats(nodes) in the theatre, where each node stores the seat information.
void cinemax :: create_list() {
    // To initialise the variables and create the first node of the DCLL.
    int i = 1;
    temp = new node;
    temp->seat = 1;
    temp->status = 0;
    temp->id = "null";
    tail = head = temp;

    // To create the other sixty-nine nodes(p) and initialise them.
    for(int i = 2; i <= 70; i++) {
        node *p;
        p = new node;
        p->seat = i;
        p->status = 0;
        p->id = "null";

        tail->next = p; // Sets the next pointer of the current tail to p.
        p->prev = tail; // Sets the prev pointer of p to the current tail.
        tail = p; // To update tail to be the new node p.
        tail->next = head; // To set the next pointer of tail to head, creating a circular link.
        head->prev = tail; // To set the prev pointer of head to tail, completing the circular link.
    }
}

// To display the status of seats.
void cinemax :: display() {
    int r = 1; // row counter
    node *temp; // To create a temporary pointer.
    temp = head; // To initalise temp to head to traverse the LL.
    int count = 0;

    cout << "\n------------------------------------------------------------------------------------\n";
    cout << "\t\t\t\tScreen this way\t\t\t";
    cout << "\n------------------------------------------------------------------------------------\n";
    
    // To iterate through each node in the LL until one full cycle of the CLL is completed.
    while(temp->next != head) { // Loop will run till the 69th node only, and break when temp = 70th seat.
        // To display seat numbers
        if(temp->seat/10 == 0) {
            cout << "S0" << temp->seat << " :"; // For seats 1-9
        }
        else {
            cout << "S" << temp->seat << " :"; // For seats 10-70
        }

        // To display status of the seats
        if(temp->status == 0) {
            cout << "|___| "; // Unbooked seat
        }
        else {
            cout << "|_B_| "; // Booked seat
        }

        count++; // To count number of seats

        // To start displaying on the next line when there are 7 seats in 1 row.
        if(count%7 == 0) {
            cout << endl;
            r++;
        }

        temp = temp->next; // To move to the next node in the LL.
    }

    // To avoid line break after loop and print information of the last seat.
    cout << "S" << temp->seat << " :";
    if(temp->status == 0) {
        cout << "|___| ";
    }
    else {
        cout << "|_B_| ";
    }

    //cout << "\nNo. of rows: " << r << endl;
}

// To book a seat in the movie theatre.
void cinemax :: book() { 
    int x;
    string y;

    /* 'label' and 'goto' are keywords in C++ that are used together to create a labeled statement and 
    perform an unconditional jump in the code. */
    label: // An identifier which provides target location referred to by the goto statement.
        cout << "\nEnter seat number to be booked: ";
        cin >> x;
        cout << "Enter your ID number: ";
        cin >> y;

    if(x<1 || x>70) {
        cout << "\nInvalid choice. Please enter a correct seat number(1-70) to book.";
        /* goto is a control flow statement that transfers the program's control to the labelled statement. 
        It is often used for creating loops or handling error conditions. Use is discouraged. */
        goto label; 
    }

    node *temp;
    temp = head;

    while(temp->seat != x) { // To traverse LL until desired seat number is reached and stored in temp.
    temp = temp->next;
    }

    if(temp->status == 1) {
        cout << "\nSeat already booked!" << endl;
    }
    else {
        temp->status = 1;
        temp->id = y;
        cout << "Seat " << x << " booked!\n";
    }
}

// To cancel a booking.
void cinemax :: cancel() {
    int x;
    string y;

    /* A labeled loop(label1) is used for input validation. The user is prompted to enter the seat number 
    and ID. If the entered seat number is not in the valid range(1-70), an error message is displayed, and 
    the user is prompted to enter a correct seat number. The program then jumps back to the label1 
    using goto to repeat the input process until a valid seat number is provided. */
    label1:
        cout << "\nEnter seat number to cancel booking: ";
        cin >> x;
        cout << "Enter your ID number: ";
        cin >> y;

    if(x<1 || x>70) {
        cout << "\nEnter the correct seat number(1-70) to cancel booking.";
        goto label1;
    }

    node *temp;
    temp = new node;
    temp = head;

    while(temp->seat != x) {
        temp = temp->next;
    }

    if(temp->status == 0) {
        cout << "\nSeat not booked yet!" << endl;
    }
    else {
        if(temp->id == y) { // To check if ID entered corresponds to the booked seat information.
            temp->status = 0;
            cout << "Booking cancelled!" << endl;
        }
        else {
            cout << "\nInvalid user ID. Seat cannot be cancelled." << endl;
        }
    }
}

// To view available seats.
void cinemax :: avail() {
    int r = 1;
    node *temp;
    temp = head;
    int count = 0;

    cout << "\n------------------------------------------------------------------------------------\n";
    cout << "\t\t\t\tScreen this way\t\t\t";
    cout << "\n------------------------------------------------------------------------------------\n";

    while(temp->next != head) {
        if(temp->seat/10 == 0) {
            cout << "S0" << temp->seat << " :";
        }
        else {
            cout << "S" << temp->seat << " :";
        }

        if(temp->status == 0) {
            cout << "|___| ";
        }
        else if(temp->status == 1) {
            cout << "|_N_| ";
        }

        count++;

        if(count%7 == 0) {
            cout << endl;
        }

        temp = temp->next;
    }

    // For the last node.
    cout << "S" << temp->seat << " :";
    if(temp->status == 0) {
        cout << "|___| ";
    }
    else if(temp->status == 1) {
        cout << "|_N_| ";
    }
}

int main() { 
    cinemax obj;
    obj.create_list();

    int ch;
    char c = 'y';

    cout << "\nWelcome to Cinemax Movies. Please select one of the following options:" << endl;
    cout << "1. Current seat status" << endl;
    cout << "2. Book seat" << endl;
    cout << "3. Available seats" << endl;
    cout << "4. Cancel seat" << endl;

    while(c=='y') { 
        cout << "\nEnter your choice: ";
        cin >> ch;

        switch(ch) {
            case 1:
                obj.display();

                cout << "\n************************************************************************************\n";
                cout << "\t\t\t\tCINEMAX MOVIE THEATRE\t\t\t";
                cout << "\n************************************************************************************\n";

                break;

            case 2: 
                obj.book();
                break;

            case 3:
                obj.avail();
                break;

            case 4: 
                obj.cancel();
                break;

            default: 
                cout << "\nInvalid choice." << endl;
        }

        cout << "\nWould you like to perform any other operation(enter y/n): ";
        cin >> c;
    }

    return 0;
}
