#include "regularCustomer.h"

int RegularCustomer::count = 0;

RegularCustomer::RegularCustomer() {}

RegularCustomer::RegularCustomer(const int id, const string& name, int age, const string& contactInfo)
    : Customer(name, age, contactInfo), id(id) {}


void RegularCustomer::setCount(int count) {
    RegularCustomer::count = count;
}

int RegularCustomer::getCount() const {
    return count;
}

void RegularCustomer::addCustomer(){

    cout << "Enter customer name: ";
    getline(cin, name);
    
    cout << "Enter customer age: ";
    cin >> age;
    cin.ignore();
    
    cout << "Enter contact information: ";
    getline(cin, contactInfo);
    count++;
    if (!saveToFile()){
        cout<<"Failed to save customer to file"<<endl;
    }
}

void RegularCustomer::viewCustomer(Customer* customers, int size) {
    if (size == 0) {
        cout << "No regular customers to display." << endl;
        return;
    }

    cout << "List of Customers:" << endl;
    cout << "----------------" << endl;

    for (int i = 0; i < size; i++) {
        cout << static_cast<RegularCustomer*>(customers)[i] << endl; 
        cout<<"----------------" << endl;
    }
    cout << "Regular customers in record: " << count << endl;
}

void RegularCustomer::searchCustomer(Customer* c, int index) {
    bool found=false;
    string searchTerm;
    cout<<"Enter name of regular customer you want to search: ";
    getline(cin,searchTerm);

    for (int i=0; i<index; i++){
    string searchName=static_cast<RegularCustomer*>(c)[i].name;
    for (int j=0; j<searchName.length(); j++){
        searchName[j]=tolower(searchName[j]);
    }
    for (int j=0; j<searchTerm.length(); j++){
        searchTerm[j]=tolower(searchTerm[j]);
    }
    if (searchTerm==searchName){
        cout<<"Customer Details: "<<"\nID: "<<static_cast<RegularCustomer*>(c)[i].id<<"\nName: "<<static_cast<RegularCustomer*>(c)[i].name<<"\nAge: "<<static_cast<RegularCustomer*>(c)[i].age<<"\nContact Info: "<<static_cast<RegularCustomer*>(c)[i].contactInfo<<endl;
        found=true;
        break;
    }
    }
    if (!found){
        cout<<"No customer matching the name \""<<searchTerm<<"\" found. "<<endl;
    }

}

bool RegularCustomer::saveToFile() {
    ofstream fout;
    try{
    fout.open("regularCustomers.txt",ios::app);
    if (fout.fail()){
        throw runtime_error("Error opening regularCustomers.txt for writing");
    }
    }
    catch(runtime_error &e){
        cout<<e.what()<<endl;
        return false;
    }
    fout<<id<<endl;
    fout<<name<<endl;
    fout<<age<<endl;
    fout<<contactInfo<<endl;
    fout.close();
    cout << "Regular customer saved to file successfully." << endl;
    return true;
}

void RegularCustomer::readFile(Customer *c, int &index) {
    ifstream fin;
    try{
    fin.open("regularCustomers.txt");
    if (fin.fail()){
        throw runtime_error("Error opening regularCustomers.txt for reading");
    }
    }
    catch(runtime_error &e){
        cout<<e.what()<<endl;
        return;
    }
    while (fin>>static_cast<RegularCustomer*>(c)[index].id ) {
        fin.get();
        getline(fin,static_cast<RegularCustomer*>(c)[index].name);
        fin>>static_cast<RegularCustomer*>(c)[index].age;
        fin.get();
        getline(fin,static_cast<RegularCustomer*>(c)[index].contactInfo);
        index++;
        count++;
    }
    fin.close();
    cout << "Regular customers read from file successfully." << endl;
}

ostream& operator<<(ostream& output, const RegularCustomer& customer) {
    output<<"ID: "<<customer.id<<endl;
    output <<"Name: " << customer.name << endl;
    output <<"Age: " << customer.age << endl;
    output <<"Contact Info: " << customer.contactInfo << endl;
    return output;
}
