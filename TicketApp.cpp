#include <iostream>
#include <string>
using namespace std;

class node {
public:
    int val;
    string name;
    int numberofticket;
    int price;
    string address;
    node* next;

    node(int data, string n, int num, int p, string addy) {
        val = data;
        name = n;
        numberofticket = num;
        price = p;
        address = addy;
        next = NULL;
    }
};

void storeTicketInfo(node*& head, int val, string name, int numberofticket, int price, string address) {
    node* new_node = new node(val, name, numberofticket, price, address);
    new_node->next = head;
    head = new_node;
}

void display(node* head) {
    node* temp = head;
    while (temp != NULL) {
        cout << "- - - - - - - - - - - - - - - - - " << endl;
        cout << "- - - - - - - - - - - - - - - - - " << endl;
        cout << "Ticket number: " << temp->val << "\n" << "Name of purchaser: " << temp->name << "\n" << "Ticket quantity: " << temp->numberofticket << "\n" << "Total price: " << temp->price << "\n" << "Address of purchaser: " << temp->address << "\n\n" << endl;
        temp = temp->next;
    }
}

node* linearSearch(node* head, int value) {
    node* current = head;
    while (current != NULL) {
        if (current->val == value) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

int main() {
    node* head = NULL;
    string p, add;
    int h, t, pc, i = 1;

    int option, option2;
    node* matchedNode = NULL;

    do {
        cout << "Welcome to the ticket purchase App" << endl;
        cout << "1) Buy ticket\n2) My Ticket\n3) Ticket availability\n4) Exit" << endl;
        cin >> option;
        switch (option) {
            case 1:
                cout << "Enter your Name: ";
                cin >> p;
                cout << "How many tickets you want to purchase: ";
                cin >> h;
                cout << "Enter your Address: ";
                cin >> add;
                pc = h * 100;
                cout << "Your total ticket price is: " << pc << endl;

                storeTicketInfo(head, i, p, h, pc, add);
                display(head);
                i++;

                cout << endl;

                do {
                    cout << "- - - - - - - - - - - - - - - - - " << endl;
                    cout << "- - - - - - - - - - - - - - - - - " << endl;
                    cout << "1) Buy more tickets!" << endl;
                    cout << "2) Back to homepage!" << endl;
                    cin >> option2;
                    switch (option2) {
                        case 1:
                            cout << "Enter your Name: ";
                            cin >> p;
                            cout << "How many tickets you want to purchase: ";
                            cin >> h;
                            cout << "Enter your Address: ";
                            cin >> add;
                            pc = h * 100;
                            cout << "Your total ticket price is: " << pc << endl;

                            storeTicketInfo(head, i, p, h, pc, add);
                            display(head);
                            i++;
                            break;
                        case 2:
                            break;
                    }
                } while (option2 != 2);
                break;
            case 2:
                cout << "What is your ticket number: ";
                cin >> t;

                matchedNode = linearSearch(head, t);
                if (matchedNode == NULL) {
                    cout << "Ticket not found!" << endl;
                } else {
                    cout << "Here is your Ticket" << endl;
                    cout << "****************" << endl;
                    cout << "Ticket number: " << matchedNode->val << endl;
                    cout << "Name of purchaser: " << matchedNode->name << endl;
                    cout << "Ticket quantity: " << matchedNode->numberofticket << endl;
                    cout << "Total price: " << matchedNode->price << endl;
                    cout << "Address of purchaser: " << matchedNode->address << endl;
                    cout << "****************" << endl;
                }
                break;
            case 3:
                cout << "Write down the ticket number to check if the ticket available or not!:  ";
                cin >> t;
                matchedNode = linearSearch(head, t);
                if (matchedNode == NULL) {
                    cout << "Ticket available" << endl;
                } else {
                    cout << "Ticket not available" << endl;
                }
                break;
            case 4:
                break;
            default:
                cout << "Choose the right option" << endl;
                break;
        }
    } while (option != 4);

    return 0;
}
