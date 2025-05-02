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

void PendingOrders() {
        if (front == nullptr) {
            cout << "No pending orders." << endl;
            return;
        }

        cout << "Pending Orders:" << endl;
        order_customer* current = front;
        while (current != nullptr) {
            cout << "Order ID: " << current->ordernumber
                 << ", Customer: " << current->customerName
                 << ", Item: " << current->dish << "." << endl;
            current = current->next;
        }
    }

    void TotalServed() {
        cout << "Total Orders Served: " << totalServed << endl;
    }

void DisplayMenu() {
        cout << endl;
        cout << "Menu:" << endl;

        cout << "Starters:" << endl;
        cout << "Samosa (2 pcs) ₹60 - Crispy pastry filled with spiced potatoes and peas." << endl;
        cout << "Paneer Tikka ₹180 - Grilled cottage cheese cubes marinated in yogurt and spices." << endl;
        cout << "Chicken Pakora ₹200 - Deep-fried chicken fritters with a chickpea flour coating." << endl;
        cout << endl;

        cout << "Main Course:" << endl;
        cout << "Butter Chicken ₹280 - Tender chicken in a creamy tomato gravy." << endl;
        cout << "Palak Paneer ₹240 - Cottage cheese in a mildly spiced spinach sauce." << endl;
        cout << "Chole Bhature ₹150 - Spicy chickpeas served with deep-fried fluffy bread." << endl;
        cout << endl;

        cout << "Rice & Breads:" << endl;
        cout << "Jeera Rice ₹120 - Basmati rice flavored with cumin." << endl;
        cout << "Chicken Biryani ₹250 - Aromatic rice cooked with spiced chicken." << endl;
        cout << "Garlic Naan ₹50 - Tandoor-baked flatbread with garlic topping." << endl;
        cout << endl;

        cout << "Desserts:" << endl;
        cout << "Gulab Jamun (2 pcs) ₹60 - Sweet milk-solid dumplings soaked in rose-flavored syrup." << endl;
        cout << "Kheer ₹80 - Traditional Indian rice pudding with cardamom and nuts." << endl;
        cout << endl;

        cout << "Beverages:" << endl;
        cout << "Masala Chai ₹30 - Spiced Indian tea brewed with milk." << endl;
        cout << "Sweet Lassi ₹50 - Refreshing yogurt-based drink." << endl;
        cout << endl;
    }
};

int main() {
    orderQueue queue;
    int choice;

    do {
        cout << endl;
        cout << "Restaurant Order Management System" << endl;
        cout << "1. Display Menu" << endl;
        cout << "2. Add New Order" << endl;
        cout << "3. Serve Order" << endl;
        cout << "4. Display Pending Orders" << endl;
        cout << "5. Display Total Orders Served" << endl;
        cout << "6. Exit " << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                queue.DisplayMenu();
                break;
            case 2:
                queue.addOrder();
                break;
            case 3:
                queue.serveOrder();
                break;
            case 4:
                queue.PendingOrders();
                break;
            case 5:
                queue.TotalServed();
                break;
            case 6:
                cout << "Exiting, Thank You for choosing us!" << endl;
                break;
            default:
                cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != 6);

    return 0;
}













        
        
        
