#include <iostream>
#include <string>
#include <sstream>
using namespace std;


class Product
{
    private:
        int id;
        string name;
        string category;
        double price;
        int quantity; 

    public:
        Product(int id = 0, string name =" ", string category=" ", double price = 0, int quantity= 0)
        {
            this->id=id;
            this->name=name;
            this->category=category;
            this->price=price;
            this->quantity=quantity;
        }

        int getID() const{
            return id;
        }

        void setID(int id){
            this->id=id;
        }

        string getName() const{
            return name;
        }

        void setName(string name){
            this->name=name;
        }

        string getCategory() const{
            return category;
        }

        void setCategory(string category){
            this->category=category;
        }

        double getPrice() const{
            return price;
        }

        void setPrice(double price){
            this->price=price;
        }

        int getQuantity() const{
            return quantity;
        }

        void setQuantity(int quantity){
            this->quantity=quantity;
        }

};

class Inventory{
    private:
        Product products[100]; //array for storage
            int currentProduct; 

    public:
        Inventory(){
            currentProduct = 0;
        }

        public:
        //add product function
            void addProduct(int id, string name, string category, double price, int quantity){
                if(currentProduct < 100){
                    products[currentProduct] = Product(id, name, category,price,quantity);
                        currentProduct++;
                            cout<<"Product Added successfully"<<endl;  
                }

                else{
                    cout<<"Inventory is full"<<endl;
                }
            }

    //remove product function            
    void removeProduct(int id) {
        bool found = false;
        for (int i = 0; i < currentProduct; i++) {
            if (products[i].getID() == id) {
                found = true;
                for (int j = i; j < currentProduct - 1; j++) {
                    products[j] = products[j + 1];
                }
                currentProduct--;
                cout << "Product with ID " << id << " has been removed from the system." << endl;
                break;
            }
        }

        if (!found) {
            cout << "Product with ID " << id << " was not found." << endl;
        }
    }

    // Display all products
    void displayProducts() {
        if (currentProduct == 0) {
            cout << "No products in inventory." << endl;
        } else {
            cout << "ID\tName\tCategory\tPrice\tQuantity" << endl;
            for (int i = 0; i < currentProduct; i++) {
                cout << products[i].getID() << "\t" << products[i].getName() << "\t" << products[i].getCategory() << "\t"
                     << products[i].getPrice() << "\t" << products[i].getQuantity() << endl;
            }
        }
    }
  


//ID search function

    void searchProduct(int id){

        bool found = false;

        for(int i = 0; i < currentProduct; i++){

            found = true;
                cout<<"Product Found"<<endl;
                cout<<"ID: "<< products[i].getID()<<endl;
                cout<<"Name: "<< products[i].getName()<<endl;
                cout<<"Category: "<< products[i].getCategory()<<endl;
                cout<<"Price: "<< products[i].getPrice()<<endl;
                cout<<"Quantity: "<< products[i].getQuantity()<<endl;
                break;

        }
            if(!found){
                cout<<"Product with ID"<<id<<"was not found."<<endl;
            }
    }

    //bubble sort because im lazy to think

    void bubblesort(string criteria, string order){
        
        bool swapped;

            for(int i = 0; i < currentProduct - 1; i++){
                swapped=false;

                for(int j = 0; j < currentProduct - 1; j++){
                   
                    // sort by quantity
                    if(criteria == "quantity"){

                        if( (order == "ascending" && products[j].getQuantity() > products[j + 1].getQuantity() )  ||
                        (order == "descending" && products[j].getQuantity() < products[j + 1].getQuantity() ) )
                    
                    {
                         swap(products[j], products[j + 1]);
                         swapped = true;
                    }
                             
                    }
           
            //sorting by price 
            else if(criteria == "price"){

                if( (order == "ascending" && products[j].getPrice() > products[j + 1].getPrice()) || 
                (order =="descending" && products[j].getPrice() < products[j + 1].getPrice() ) )

            {
                swap(products[j], products[j + 1]);
                swapped = true;
            }

            }

        }
            if(!swapped)
                 break;
    }
        cout<<"Products sorted by "<<criteria<<"in "<<order<<"order. "<<endl;


    }

    //almost forgot the update product function 
    
    void updateproduct(int id){
        
        bool found = false;
            for(int i = 0; i < currentProduct; i++){
                if(products[i].getID()== id){

                    found = true;
                    
                    cout<<"Product found!"<<endl;
                    cout<<"ID: "<<products[i].getID()<<endl;
                    cout<<"Name: "<<products[i].getName()<<endl;
                    cout<<"Category: "<<products[i].getCategory()<<endl;
                    cout<<"Price: "<<products[i].getPrice()<<endl;
                    cout<<"Quantity: "<<products[i].getQuantity()<<endl;

                    cout<<"Enter 'Price' to update the price or 'Quantity' to update the quantity: ";
                        string field;
                            cin>>field;

                        if (field == "price"){
                            
                            double newPrice;
                                cout<<newPrice;
                            double oldPrice = products[i].getPrice();
                                products[i].setPrice(newPrice);
                            cout<<"Price of product "<<products[i].getName()<<" updated from "<<oldPrice<<" to "<<newPrice<<endl;
                        }
                        
                        else if(field == "quantity"){
                            
                            int newQuantity;
                                cout<<"Enter new quantity: ";
                                    cin>>newQuantity;
                            int oldQuantity = products[i].getQuantity();
                                cout<<"Quantity of product "<<products[i].getName()<<" updated from "<<oldQuantity<<" to "<<newQuantity<<endl;                               
                        }

                         else{
                                    cout<<"Invlaid field. Only 'Price' and 'Quantity' "<<endl;
                        }
                        break;
                }
            }

            if(!found){
                cout<<"Product with ID "<<id<<" not found! "<<endl;
            }

    }
        //display items by category
        void displaycategory(string category){
            bool found = false;
                cout<<"Products in category: "<<category<<endl;
                cout<<"ID\tName\tCategory\tPrice\tQuantity"<<endl;

                for (int i = 0; i < currentProduct; i++){
                    
                    if(products[i].getCategory() == category){
                        found == true;
                            cout<<products[i].getID()<<"\t"<<products[i].getName()
                            <<"\t"<<products[i].getCategory()<<"\t"<<products[i].getPrice()
                            <<"\t"<<products[i].getQuantity()<<endl;
                    }
                }

            if (!found){
                cout<<"No products found in the category: "<<category<<endl;
            }
        }

    //display low stock items
    
     void displayLowStock(int threshold)
    {
        bool found = false;
        cout << "Products with stock lower than " << threshold << ":" << endl;
        cout << "ID\tName\tCategory\tPrice\tQuantity" << endl;

        for (int i = 0; i < currentProduct; i++)
        {
            if (products[i].getQuantity() < threshold)
            {
                found = true;
                cout << products[i].getID() << "\t" << products[i].getName() << "\t" << products[i].getCategory() << "\t"
                     << products[i].getPrice() << "\t" << products[i].getQuantity() << endl;
            }
        }

        if (!found)
        {
            cout << "No products found with stock lower than " << threshold << endl;
        }
    }



};


    void showMenu() {
        cout << "\nInventory Management System Menu" << endl;
        cout << "1. Add a Product" << endl;
        cout << "2. Remove a Product" << endl;
        cout << "3. Display all Products" << endl;
        cout << "4. Search Product by ID" << endl;
        cout << "5. Update a Product" << endl;
        cout << "6. Sort Products (by quantity or price)" << endl;
        cout << "7. Display Products by Category" << endl;
        cout << "8. Display Low Stock Products" << endl;
        cout << "9. Exit" << endl;
        cout << "Choose an option: "<<endl;
}



int main(){

    Inventory inventory;
    int choice;

    do {
        showMenu();
        cin>>choice;

        switch (choice) {
            case 1: {
                // Add a product
                int id, quantity;
                string name, category;
                double price;
                
                cout << "Enter product ID: ";
                cin >> id;
                cout << "Enter product name: ";
                cin.ignore();  // To ignore newline character from previous input
                getline(cin, name);
                cout << "Enter product category: ";
                getline(cin, category);
                cout << "Enter product price: ";
                cin >> price;
                cout << "Enter product quantity: ";
                cin >> quantity;

                inventory.addProduct(id, name, category, price, quantity);
                break;
            }
            case 2: {
                // Remove a product
                int id;
                cout << "Enter the product ID to remove: ";
                cin >> id;
                inventory.removeProduct(id);
                break;
            }
            case 3: {
                // Display all products
                inventory.displayProducts();
                break;
            }
            case 4: {
                // Search product by ID
                int id;
                cout << "Enter product ID to search: ";
                cin >> id;
                inventory.searchProduct(id);
                break;
            }
            case 5: {
                // Update a product
                int id;
                cout << "Enter product ID to update: ";
                cin >> id;
                inventory.updateproduct(id);
                break;
            }
            case 6: {
                // Sort products
                string criteria, order;
                cout << "Enter sorting criteria (price/quantity): ";
                cin >> criteria;
                cout << "Enter sorting order (ascending/descending): ";
                cin >> order;
                inventory.bubblesort(criteria, order);
                break;
            }
            case 7: {
                // Display products by category
                string category;
                cout << "Enter category to display products: ";
                cin.ignore();
                getline(cin, category);
                inventory.displaycategory(category);
                break;
            }
            case 8: {
                // Display low stock items
                int threshold;
                cout << "Enter the stock threshold: ";
                cin >> threshold;
                inventory.displayLowStock(threshold);
                break;
            }
            case 9: {
                // Exit the program
                cout << "Exiting the program..." << endl;
                break;
            }
            default:
                cout << "Invalid option. Please try again." << endl;
        }
    } while (choice != 9);

    return 0;
}