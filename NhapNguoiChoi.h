#include<iostream>
#include<string.h>

using namespace std;


void InputNamePlayer(char x[]){
	do{

		cout << "Please enter your name \t";
		fflush(stdin);
		
		gets(x);
	} while (x == NULL || x == "32");

}

