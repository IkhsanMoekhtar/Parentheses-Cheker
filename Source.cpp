#include <iostream>
#include <string>
#include <conio.h>
#include <stack>
#include <stdio.h>

using namespace std;

void wait() {
	int input;
	cout << "\n\nEnter any key to exit the program" << endl;
	input = getch();
	if (input == 13) {
		system("cls");
	}
	
}


//Program Tugas Strukdat Problem set no.1 b,c
bool isbalance(string expr)
{
	stack<char> opr;
	for (int i = 0; i < expr.length(); i++) {
		if (expr[i] == '(' || expr[i] == '['|| expr[i] == '{'|| expr[i] == '/' && expr[i+1]=='*') {

			opr.push(expr[i]);
		}
		 if ((opr.top() == '(' && expr[i] == ')')
			 ||(opr.top() == '['&& expr[i] == ']') 
			 ||(opr.top()=='{' && expr[i] == '}'))
			 //untuk checker /* saya tidak punya solusi
			 //||(opr.top() == '/' && (expr[i] == '*' && expr[i + 1] == '/')))
			
		 {
			if (opr.empty()) {
				switch (expr[i]) {
				case ')':
				{
					cout << "invalid input cause '(' was not found\n" << endl;
					break;
				}
				case ']':
				{
					cout << "invalid input cause '[' was not found\n" << endl;
					break;
				}
				case '}':
				{
					cout << "invalid input cause '{' was not found\n" << endl;
					break;
				}
				case '*' && '/':
					cout << "invalid input cause '/*' was not found\n" << endl;
					break;
				
				default:
					break;
			  }


				return false;
			}else{
				opr.pop();
			}
		}			
	}
		

	if (opr.empty()) {

		return true;
	}
	else
	{
		cout << "INVALID INPUT. Please try again\n" << endl;
	}
	return false;
}


int main()
{
	string expr;
	cin >> expr;

	if (isbalance(expr)) {
		cout << "Balanced";
	}
	else {

		cout << "Not Balanced";
	}

	wait();
	return 0;
}