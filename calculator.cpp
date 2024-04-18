#include<iostream>

using namespace std;

int main() {
	int x,y;
	char operation;
	cout << "Calculator\nEnter number 1: ";
	cin >> x;
	cout << "\nEnter number 2: ";
	cin >> y;

	do {
		cout << "\nChoose operation from (+,-,/,*)";
		cin >> operation;
	} while(operation != '+' && operation != '-' && operation != '*' && operation != '/');

	switch(operation) {
		case '+':
			cout << x+y;
			break;
		case '-':
			cout << x-y;
			break;
		case '*':
			cout << x*y;
			break;
		case '/':
			cout << x/y;
	}
}