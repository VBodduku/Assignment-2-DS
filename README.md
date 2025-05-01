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
