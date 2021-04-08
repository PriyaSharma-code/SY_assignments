//stack using STL
#include<iostream>
#include<vector>
using namespace std;
class stack
{
	vector<int>S;
	vector<int>::iterator itr;
public:
	void push(int ele)
	{
		S.push_back(ele);
	}
	void pop()
	{

		cout << "\nPoped value is : ";
		itr = S.end();
		itr--;
		cout << *itr << "\n";
		S.pop_back();
	}
	void display()
	{
		cout << "\n";
		for (itr = S.begin(); itr != S.end(); itr++)
			cout << *itr << "\t";
	}
};
int main()
{
	stack st;
	char ch;
	int ele,n;
	do {
		cout << "\nMENU:";
		cout << "\n1. Push";
		cout << "\n2. Pop";
		cout << "\n3. Display";
		cin >> n;
		switch(n)
		{
		case 1:
			cout << "\nEnter an element: ";
			cin >> ele;
			st.push(ele);
			break;
		case 2:
			st.pop();
			break;
		case 3:
			st.display();

		}
		
		cout << "Do you want to continue? (y/n): ";
		cin >> ch;
	} while (ch == 'y' || ch=='Y');
	//st.push(34);
    //st.push(90);
    //st.pop();
	//st.display();
}
