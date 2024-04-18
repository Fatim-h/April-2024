#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <time.h>
using namespace std;

int generatenum(){
	int x;
	x = rand();
	return x;
}

bool guess(){
	bool y = 0;
	int guess, num;
	num = generatenum();
	while(!y){
		cout << "\nEnter your guess for the random number: ";
		cin >> guess;
		if(guess > num){
			cout << "\nToo High!";
		} else if (guess < num){
			cout << "\nToo Low!";
		} else {
			cout << "\n\nJust Right!Ending game";
			y = 1;
		}
	}
	return 0;
}

int main(){
	guess();
}