#include<iostream>
#include<conio.h>
#include<string.h>
#include<Windows.h>


using namespace std;


void TaoBanCoMoi(char b[33][49]){
	int dem = 6, tam =0;
	for (int i = 0; i < 33; i++){
		tam +=dem;
		
		for (int j = 0; j < 49; j++){

			
			b[i][j] = ' ';
			if (j == 6 || j==12 || j == 18 || j== 24 || j == 30 || j == 36 || j== 42 ){
				b[i][j] = '|';
				
			}
			if (i == 4 || i == 8 || i == 12 || i == 16 || i == 20 || i == 24 || i == 28){
				b[i][j] = '-';
			}
			if (i == 0 || i == 32){
				b[i][j] = '-';
			}
			if (j == 0 || j == 48){
				b[i][j] = '|';
			}
			
		}
		
	}

	
	
	for (int i = 0; i < 33; i++){
		for (int j = 0; j < 49; j++){
			cout << b[i][j];
		}
		cout << endl;
	}
}