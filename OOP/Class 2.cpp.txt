#include<iostream>
#include<string>
using namespace std;
class student
{
private:
    int i;
    string name;
    int rollno;
    string classs;
    string div;
    string dob;
    string an;
    char bloodgroup[5];
    string address;
    string number;
public:
    void input()
    {

        cout << "ENTER YOUR NAME   " << endl;
        getline(cin, name);
        cout << "ENTER ROLL NO.  " << endl;
        cin >> rollno;
        cin.ignore();
        cout << "ENTER YOUR CLASS $ COURSE" << endl;
        getline(cin, classs);
        cout << "ENTER DIVISION   " << endl;
        getline(cin, div);
        cout << "ENTER YOUR DOB    " << endl;
        getline(cin, dob);
        cout << "ENTER YOUR AADHAR NO.   " << endl;
        cin >> an;
        cin.ignore();
        cout << "ENTER YOUR BLOOD GROUP   " << endl;
        cin.getline(bloodgroup, 5);
        cout << "ENTER YOUR ADDRESS   " << endl;
        getline(cin, address);
        cout << "LASTLY, ENTER YOUR MOBILE NUMBER " << endl;
        cin >> number;
    }

    void display()
    {
        cout << "\n\n\n\n";
        cout << "Your info is as  \n" << endl;
        cout << "Your name is  " << name << endl;
        cout << "Your rollno. is  " << rollno << endl;
        cout << "Your course is  " << classs << endl;
        cout << "Your division is  " << div << endl;
        cout << "Your date of birth is   " << dob << endl;
        cout << "Your aadhar no. is   " << an << endl;
        cout << "Your bloodgroup is   " << bloodgroup << endl;
        cout << "Your address is   " << address << endl;
        cout << "Your contact number is   " << number << endl;
    }
    student() //default constructor
    {
        cout << "This is default constructor"<<endl;
        classs = " SYCSE";
    }
    student(int rn)  //parameterized constructor
    {
        cout << "This is parameterized constructor"<<endl;
        rollno = rn;
      
    }
    student(student &s)  //copy constructor
    {
        div = s.div;
        address = s.address;
        number = s.number;

    }
    ~student() //destructor
    {
        cout << "This is destructor"<<endl;
    }
    void print()
    {
        cout << "Copy constructor working"<<endl;
        cout << "Division :"<<div<<endl;
        cout << "Address :" << address << endl;
        cout << "Contact no :"<<number<<endl;
    }
    void show()
    {
        cout << "Parameterized constructor"<<endl;
        cout << "Roll no:"<<rollno<<endl;
    }
};
int main()
{
    void input();
    void display();
    student s1,s2;
    s1.input();
    s1.display();
    s2.show();
    student s3(s1);
    s3.print();
    return 1;
}
