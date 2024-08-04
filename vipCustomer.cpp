#include "vipCustomer.h"

int VIPCustomer::count = 0;

VIPCustomer::VIPCustomer() : loyaltyPoints(0), discount(0.0), membershipID(0) {}

VIPCustomer::VIPCustomer(const string& name, int age, const string& contactInfo, int loyaltyPoints, float discount, int membershipID)
    : Customer(name, age, contactInfo), loyaltyPoints(loyaltyPoints), discount(discount), membershipID(membershipID) {}

void VIPCustomer::setLoyaltyPoints(int loyaltyPoints) {
    this->loyaltyPoints = loyaltyPoints;
}

int VIPCustomer::getLoyaltyPoints() const {
    return loyaltyPoints;
}

void VIPCustomer::setDiscount(float discount) {
    this->discount = discount;
}

float VIPCustomer::getDiscount() const {
    return discount;
}

void VIPCustomer::setMembershipID(int membershipID) {
    this->membershipID = membershipID;
}

int VIPCustomer::getMembershipID() const {
    return membershipID;
}

void VIPCustomer::addCustomer() {
    cout << "Enter membership ID: ";
    cin >> membershipID;
    cin.ignore();
    cout << "Enter customer name: ";
    getline(cin, name);
    
    cout << "Enter customer age: ";
    cin >> age;
    cin.ignore();
    cout << "Enter contact information: ";
    getline(cin, contactInfo);
    cout << "Enter loyalty points: ";
    cin >> loyaltyPoints;
    discount=calculateDiscount();
    count++;
    if (!saveToFile()){
        cout<<"Failed to store record to file."<<endl;
    }
}

float VIPCustomer:: calculateDiscount() {
        float discount;
        if (loyaltyPoints>=5000){
            discount=0.5;
        }
        else if (loyaltyPoints >= 1000) {
            discount = 0.2; 
        } else if (loyaltyPoints >= 500) {
            discount = 0.15; 
        } else if (loyaltyPoints >= 100) {
            discount = 0.1; 
        } else {
            discount = 0.05; 
        }
        return discount;
}

void VIPCustomer::selectCustomer(){
    vector<VIPCustomer> c;
    VIPCustomer::readFile(c);
    int id;
    while (true){
    cout<<"Enter the membership ID of customer: ";
    cin>>id;
    for (int i=0; i<c.size(); i++){
        if (id==c[i].membershipID){
            this->membershipID=c[i].membershipID;
            this->name=c[i].name;
            this->age=c[i].age;
            this->contactInfo=c[i].contactInfo;
            this->loyaltyPoints=c[i].loyaltyPoints;
            this->discount=c[i].discount;
            return;
        }
    }
    cout<<"No customer with membership ID \""<<id<<"\" found. ";
    }
    
}

void VIPCustomer::viewCustomer(Customer* customers, int size) {
    if (size == 0) {
        cout << "No VIP customers to display." << endl;
        return;
    }

    cout << "List of VIP Customers:" << endl;
    cout<<setw(15)<<left<<"Membership ID"<<setw(20) << "Name"<<setw(20)<<left<<"Age"<<setw(20)<<left<<"Contact Info"<<setw(15)<<left<<"Loyalty Points"<<" Discount\n"<<endl;

    for (int i = 0; i < size; i++) {
        cout << static_cast<VIPCustomer*>(customers)[i] << endl; 
    }
    cout << "VIP customers in record: " << count << endl;
}

void VIPCustomer::searchCustomer(Customer* customers, int size) {
    bool found=false;
    int search;
    cout<<"Enter the membership id of VIP customer you want to search: ";
    cin>>search;

    for (int i=0; i<size; i++){
        
        if (search==static_cast<VIPCustomer*>(customers)[i].membershipID){
            cout<<setw(15)<<left<<"Membership ID"<<setw(20) << "Name"<<setw(20)<<left<<"Age"<<setw(20)<<left<<"Contact Info"<<setw(15)<<left<<"Loyalty Points"<<" Discount";
            cout<<"VIP Customer Details: "<<static_cast<VIPCustomer*>(customers)[i];
            found=true;
            break;
        }
    }
    if (!found){
        cout<<"No customer having the Membership ID \""<<search<<"\" found. "<<endl;
    }
}

bool VIPCustomer::saveToFile() {
    ofstream fout;
    try{
        fout.open("vipCustomers.txt",ios::app);
        if (fout.fail()){
            throw runtime_error("Error opening vipCustomers.txt for writing");
        }
    }
    catch(runtime_error &e){
        cout<<e.what()<<endl;
        return false;
    }
    fout << membershipID <<endl<< name<<endl<< age <<endl << contactInfo <<endl<< loyaltyPoints<<endl<< discount << endl;
    fout.close();
    cout << "VIP customer saved to file successfully." << endl;
    return true;
}

void VIPCustomer::readFile(vector <VIPCustomer> &customers){
    ifstream fin;
    try{
        fin.open("vipCustomers.txt");
        if (fin.fail()){
            throw runtime_error("Error opening vipCustomers.txt for reading");
        }
    }
    catch(runtime_error &e){
        cout<<e.what()<<endl;
        return;
    }
    VIPCustomer c;
    while (fin >> c.membershipID ) {
        fin.ignore();
        getline(fin,c.name);
        fin >> c.age;
        fin.ignore();
        getline(fin, c.contactInfo);
        fin >> c.loyaltyPoints >> c.discount;
        fin.ignore(); 
        customers.push_back(c);
        count++;
    }
    fin.close();
    cout << "VIP customers read from file successfully." << endl;
}

void VIPCustomer::readFile(Customer* customers, int& index) {
    ifstream fin;
    try{
        fin.open("vipCustomers.txt");
        if (fin.fail()){
            throw runtime_error("Error opening vipCustomers.txt for reading");
        }
    }
    catch(runtime_error &e){
        cout<<e.what()<<endl;
        return;
    }
    while (fin >> static_cast<VIPCustomer*>(customers)[index].membershipID ) {
        fin.ignore();
        getline(fin,static_cast<VIPCustomer*>(customers)[index].name);
        fin >> static_cast<VIPCustomer*>(customers)[index].age;
        fin.ignore();

        getline(fin, static_cast<VIPCustomer*>(customers)[index].contactInfo);
        fin >> static_cast<VIPCustomer*>(customers)[index].loyaltyPoints >> static_cast<VIPCustomer*>(customers)[index].discount;
        fin.ignore(); 

        index++;
        count++;
    }
    fin.close();
    cout << "VIP customers read from file successfully." << endl;
}


ostream& operator<<(ostream& output, const VIPCustomer& customer) {
    output<<setw(15)<<left<<customer.membershipID<<setw(20) << customer.name<<setw(20)<<left<<customer.age<<setw(20)<<left<<customer.contactInfo<<setw(15)<<left<<customer.loyaltyPoints<<customer.discount;
    return output;
}

VIPCustomer VIPCustomer::operator+(int points){
    VIPCustomer c;
    c.membershipID=this->membershipID;
    c.name=this->name;
    c.age=this->age;
    c.contactInfo=this->contactInfo;
    c.loyaltyPoints=this->loyaltyPoints;
    c.loyaltyPoints+=points;
    c.discount=c.calculateDiscount();
    return c;
}