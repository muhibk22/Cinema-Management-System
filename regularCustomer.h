#ifndef REGULARCUSTOMER_H
#define REGULARCUSTOMER_H

#include "Customer.h"

class RegularCustomer : public Customer {
private:
   static int count;
   int id;

public:
    RegularCustomer();
    RegularCustomer(const int id, const string& name, int age, const string& contactInfo);

    // Getter and setter method
    void setCount(int count);
    int getCount() const;

    // Methods
    void addCustomer() override;
    static void viewCustomer(Customer* customers, int size);
    static void searchCustomer(Customer* c, int index);
    bool saveToFile() override;
    static void readFile(Customer *customers, int &index);
    //stream operator overloading
    friend ostream &operator<<(ostream& output, const RegularCustomer& c);

};

#endif
