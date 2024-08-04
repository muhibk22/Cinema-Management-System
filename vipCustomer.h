#ifndef VIPCUSTOMER_H 
#define VIPCUSTOMER_H 

#include "RegularCustomer.cpp"

class VIPCustomer : public Customer {
private:
    static int count;
    int loyaltyPoints;
    float discount;
    int membershipID;

    static void readFile(vector <VIPCustomer> &customers);
    bool saveToFile();

public:
    VIPCustomer();
    VIPCustomer(const string& name, int age, const string& contactInfo, int loyaltyPoints, float discount, int membershipID);

    // Getter and setter methods
    void setLoyaltyPoints(int loyaltyPoints);
    void setDiscount(float discount);
    void setMembershipID(int membershipID);

    int getLoyaltyPoints() const;
    float getDiscount() const;
    int getMembershipID() const;
    static int getCount();

    // Methods
    void addCustomer() override;
    void selectCustomer() override;
    float calculateDiscount() override;
    static void viewCustomer(Customer* customers, int size);
    static void searchCustomer(Customer* customers, int size);
    static void readFile(Customer* customers, int& index);

    friend ostream &operator<<(ostream& output, const VIPCustomer& c);
    VIPCustomer operator+(int points);
};

#endif 
