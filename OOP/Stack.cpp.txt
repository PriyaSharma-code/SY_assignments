//Stack using class template, Last In First Out
#include<iostream>
using namespace std;
template <class T>
class stack
{
	T data[20];
	int top;
public:
	stack()
	{
		top = -1;
	}
	void push(T elem)
	{
		top++;
		data[top] = elem;
		cout <<"["<< elem << " added"<<"]";
	}
	T pop()
	{
		T temp;
		temp = data[top];
		top--;
		cout << "["<<" Top popped"<<"]";
		return(temp);
	}
	void display()
	{
		int i;
		cout << "\nTOP--->";
		for (i = top; i >= 0; i--)
		{
			cout << data[i] << "\n";
			cout << "       ";
		}
	}
};
 void main()
{
	stack <int> s;
	int ele;
	s.push(23);
	cout << "\n Stack contents are: ";
	s.display();
	s.push(89);
	cout << "\n Stack contents are: ";
	s.display();
	s.push(78);
	cout << "\n Stack contents are: ";
	s.display();
	s.pop();
	cout << "\n Stack contents are: ";
	s.display();
	s.pop();
	cout << "\n Stack contents are: ";
	s.display();
	stack <char> s1;
	s1.push('A');
	cout << "\n Stack contents are: ";
	s1.display();
	s1.push('B');
	cout << "\n Stack contents are: ";
	s1.display();
	s1.pop();
	cout << "\n Stack contents are: ";
	s1.display();
}
