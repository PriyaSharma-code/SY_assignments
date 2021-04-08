#include<iostream>
using namespace std;
class Complex
{
private:
    double real, imag;
public:
    void setComplex();
    void printComplex();

    Complex operator +(Complex cc);

};
Complex Complex ::operator +(Complex cc)
{
    Complex temp;
    temp.real = real + cc.real;
    temp.imag = imag + cc.imag;
    return temp;
}
void Complex::setComplex()
{
    cout << "\nEnter the real part : ";
    cin >> real;
    cout << "\nEnter the imaginary part : ";
    cin >> imag;

}
void Complex::printComplex()
{
    cout << real << "+" << imag << "i";
}
int main()
{
    Complex c1, c2, c3;
    cout << "\n\nEnter the first complex number";
    c1.setComplex();
    cout << "\n\nEnter the second complex number";
    c2.setComplex();
    cout << "\n\nEntered complex no is as follows";
    cout << "\n Complex No.1:";
    c1.printComplex();
    cout << "\n Complex No.2:";
    c2.printComplex();
    cout << "\n\nAddition of two complex number is ";
    c3 = c1 + c2;
    c3.printComplex();
    return 0;
}
