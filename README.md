DS Assignment-2 (Hotell management system)
#include <iostream>
#include <string>
using namespace std;

class order_customer{
    public:
        int ordernumber;
        string customerName;
        string dish;
        order_customer* next;
    order_customer(int number,const string& name, const string&item ) {
        ordernumber = number;
        customerName = name;
        dish = item;
        next = nullptr
    }
};


class orderQueue{
    private:
        order_customer* front;
        order_customer* rear;
        int totalServed;

    public:
        orderQueue(){
            front = rear = nullptr;
            totalServed = 0;
        }
    
    void addOrder(){
        
    };
}
