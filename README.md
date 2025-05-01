====== DS Assignment-2 (Hotel management system) ======

#include <iostream>
#include <string>
using namespace std;

class order_customer {
public:
    int ordernumber;
    string customerName;
    string dish;
    order_customer* next;

    order_customer(int number, const string& name, const string& item) {
        ordernumber = number;
        customerName = name;
        dish = item;
        next = nullptr;
    }
};
class orderQueue {
private:
    order_customer* front;
    order_customer* rear;
    int totalServed;

public:
    orderQueue() {
        front = rear = nullptr;
        totalServed = 0;
    }

    void addOrder() {
        int number;
        string name, item;

        cout << "Please enter the order number: " << endl;
        cin >> number;
        cout << "Enter customer name: " << endl;
        cin >> name;
        cout << "Enter the dish: " << endl;
        cin >> item;

        order_customer* neworder = new order_customer(number, name, item);

        if (rear == nullptr) {
            front = rear = neworder;
        } else {
            rear->next = neworder;
            rear = neworder;
        }

        cout << "Your order has been successfully placed." << endl;
    }

void serveOrder() {
        if (front == nullptr) {
            cout << "No orders to serve." << endl;
            return;
        }

        order_customer* temp = front;
        cout << "Serving order number: " << temp->ordernumber
             << ", Customer: " << temp->customerName
             << ", Dish: " << temp->dish << endl;

        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        }

        delete temp;
        totalServed++;
    }
