#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

class Customer {
protected:
    string name;
    int age;
    string contactInfo;

public:
    Customer() : age(0) {}

    Customer(const string& name, int age, const string& contactInfo)
        : name(name), age(age), contactInfo(contactInfo) {}


    void setName(const string& name) {
        this->name = name;
    }

    void setAge(int age) {
        this->age = age;
    }

    void setContactInfo(const string& contactInfo) {
        this->contactInfo = contactInfo;
    }

    string getName() const {
        return name;
    }

    int getAge() const {
        return age;
    }

    string getContactInfo() const {
        return contactInfo;
    }

    virtual void addCustomer() = 0;

    virtual bool saveToFile() {
        ofstream fout;
        try {
            fout.open("Customer.txt", ios::app);
            if (fout.fail()) {
                throw runtime_error("Error opening file");
            }
            fout << "Name: " << name << "\nAge: " << age << "\nContact Info: " << contactInfo << endl;
        }
        catch (runtime_error& e) {
            cout << e.what() << endl;
            return false;
        }
        fout.close();
        return true;
    }
    string getCustomer(){
        string line="";
        line+="Name: "+name+"\nAge: "+to_string(age)+"\nContact: "+contactInfo;
        return line;
    }
    virtual void selectCustomer(){}
    virtual float calculateDiscount(){}
};