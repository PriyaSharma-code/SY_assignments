
#include<bits/stdc++.h> 
using namespace std; 


int prec(char c) 
{ 
	if(c == '^') 
	return 3; 
	else if(c == '*' || c == '/') 
	return 2; 
	else if(c == '+' || c == '-') 
	return 1; 
	else
	return -1; 
} 


void infixToPostfix(string s) 
{ 
	std::stack<char> st; 
	st.push('N'); 
	int l = s.length(); 
	string ns; 
	for(int i = 0; i < l; i++) 
	{ 
		
		// If the scanned character is 
		// an operand, add it to output string. 
		if((s[i] >= 'a' && s[i] <= 'z') || 
		(s[i] >= 'A' && s[i] <= 'Z')) 
		ns+=s[i]; 

		// If the scanned character is an 
		// ‘(‘, push it to the stack. 
		else if(s[i] == '(') 
		
		st.push('('); 
		
		// If the scanned character is an ‘)’, 
		// pop and to output string from the stack 
		// until an ‘(‘ is encountered. 
		else if(s[i] == ')') 
		{ 
			while(st.top() != 'N' && st.top() != '(') 
			{ 
				char c = st.top(); 
				st.pop(); 
			ns += c; 
			} 
			if(st.top() == '(') 
			{ 
				char c = st.top(); 
				st.pop(); 
			} 
		} 
		
		//If an operator is scanned 
		else{ 
			while(st.top() != 'N' && prec(s[i]) <= 
								prec(st.top())) 
			{ 
				char c = st.top(); 
				st.pop(); 
				ns += c; 
			} 
			st.push(s[i]); 
		} 

	} 
	
	// Pop all the remaining elements from the stack 
	while(st.top() != 'N') 
	{ 
		char c = st.top(); 
		st.pop(); 
		ns += c; 
	} 
	
	cout << ns << endl; 

} 

int main() 
{ 
	string exp[100];
        cin.getline(exp);
	infixToPostfix(exp); 
	return 0; 
} 


// C++ program to evaluate value of a postfix expression 
#include <iostream> 
#include <string.h> 

using namespace std; 

// Stack type 
struct Stack 
{ 
	int top; 
	unsigned capacity; 
	int* array; 
}; 
 
struct Stack* createStack( unsigned capacity ) 
{ 
	struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack)); 

	if (!stack) return NULL; 

	stack->top = -1; 
	stack->capacity = capacity; 
	stack->array = (int*) malloc(stack->capacity * sizeof(int)); 

	if (!stack->array) return NULL; 

	return stack; 
} 

int isEmpty(struct Stack* stack) 
{ 
	return stack->top == -1 ; 
} 

char peek(struct Stack* stack) 
{ 
	return stack->array[stack->top]; 
} 

char pop(struct Stack* stack) 
{ 
	if (!isEmpty(stack)) 
		return stack->array[stack->top--] ; 
	return '$'; 
} 

void push(struct Stack* stack, char op) 
{ 
	stack->array[++stack->top] = op; 
} 


 
int evaluatePostfix(char* exp) 
{ 
	// Create a stack of capacity equal to expression size 
	struct Stack* stack = createStack(strlen(exp)); 
	int i; 

	// See if stack was created successfully 
	if (!stack) return -1; 

	// Scan all characters one by one 
	for (i = 0; exp[i]; ++i) 
	{ 
		// If the scanned character is an operand (number here), 
		// push it to the stack. 
		if (isdigit(exp[i])) 
			push(stack, exp[i] - '0'); 

		// If the scanned character is an operator, pop two 
		// elements from stack apply the operator 
		else
		{ 
			int val1 = pop(stack); 
			int val2 = pop(stack); 
			switch (exp[i]) 
			{ 
			case '+': push(stack, val2 + val1); break; 
			case '-': push(stack, val2 - val1); break; 
			case '*': push(stack, val2 * val1); break; 
			case '/': push(stack, val2/val1); break; 
			} 
		} 
	} 
	return pop(stack); 
} 


int main() 
{ 
	char exp[100];
        cin.getline(exp);
	cout<<"postfix evaluation: "<< evaluatePostfix(exp); 
	return 0; 
} 


// CPP program to find infix for 
// a given postfix. 
#include <bits/stdc++.h> 
using namespace std; 

bool isOperand(char x) 
{ 
return (x >= 'a' && x <= 'z') || 
		(x >= 'A' && x <= 'Z'); 
} 

string getInfix(string exp) 
{ 
	stack<string> s; 

	for (int i=0; exp[i]!='\0'; i++) 
	{ 
		// Push operands 
		if (isOperand(exp[i])) 
		{ 
		string op(1, exp[i]); 
		s.push(op); 
		} 
 
		else
		{ 
			string op1 = s.top(); 
			s.pop(); 
			string op2 = s.top(); 
			s.pop(); 
			s.push("(" + op2 + exp[i] + 
				op1 + ")"); 
		}
      }
	return s.top(); 
} 


int main() 
{ 
	string exp = "ab*c+"; 
	cout << getInfix(exp); 
	return 0; 
} 



#include <bits/stdc++.h> 
using namespace std; 
  
bool isOperator(char c) 
{ 
    return (!isalpha(c) && !isdigit(c)); 
} 
  
int getPriority(char C) 
{ 
    if (C == '-' || C == '+') 
        return 1; 
    else if (C == '*' || C == '/') 
        return 2; 
    else if (C == '^') 
        return 3; 
    return 0; 
} 
  
string infixToPostfix(string infix) 
{ 
    infix = '(' + infix + ')'; 
    int l = infix.size(); 
    stack<char> char_stack; 
    string output; 
  
    for (int i = 0; i < l; i++) { 
  
        // If the scanned character is an  

        if (isalpha(infix[i]) || isdigit(infix[i])) 
            output += infix[i]; 

        else if (infix[i] == '(') 
            char_stack.push('('); 
  
        else if (infix[i] == ')') { 
  
            while (char_stack.top() != '(') { 
                output += char_stack.top(); 
                char_stack.pop(); 
            } 
  
            // Remove '(' from the stack 
            char_stack.pop();  
        } 
  
        // Operator found  
        else { 
              
            if (isOperator(char_stack.top())) { 
                while (getPriority(infix[i]) 
                   <= getPriority(char_stack.top())) { 
                    output += char_stack.top(); 
                    char_stack.pop(); 
                } 
  
                // Push current Operator on stack 
                char_stack.push(infix[i]); 
            } 
        } 
    } 
    return output; 
} 
  
string infixToPrefix(string infix) 
{ 

    int l = infix.size(); 
  
    reverse(infix.begin(), infix.end()); 
  
    for (int i = 0; i < l; i++) { 
  
        if (infix[i] == '(') { 
            infix[i] = ')'; 
            i++; 
        } 
        else if (infix[i] == ')') { 
            infix[i] = '('; 
            i++; 
        } 
    } 
  
    string prefix = infixToPostfix(infix); 
  
    // Reverse postfix 
    reverse(prefix.begin(), prefix.end()); 
  
    return prefix; 
} 
  
int main() 
{ 
    string s[100];
    cin.getline(s);
    cout << infixToPrefix(s) << std::endl; 
    return 0; 
}
