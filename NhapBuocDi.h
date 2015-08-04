#include<iostream>
using namespace std;

struct DESTINATION{
	int x,  y;
};

void NhapDichDen(DESTINATION &dich_den){
	do{
		fflush(stdin);
		cin.clear();
		cout << "Please enter the destination row  \t";
		cin >> dich_den.x;
		dich_den.x -= 1;
		cout << "Please enter the destination column  \t";
		cin >> dich_den.y;
		dich_den.y -= 1;

	} while (dich_den.x <0 || dich_den.x >7 || dich_den.y < 0 || dich_den.y >7);
}

void NhapDichDenAI(DESTINATION &toado, int x, int y) {
	if (x < 0 || x > 7 || y < 0 || y > 7) {
		cout << "Toa do khong hop le";
		return;
	}

	toado.x = x;
	toado.y = y;
}
