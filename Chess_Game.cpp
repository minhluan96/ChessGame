#include <iostream>
#include<ctime>
#include<stdlib.h>
#include "conio.h"
#include <string>
#include<Windows.h>
#include "Gotoxy.h"
#include "NhapBuocDi.h"
#include "NhapNguoiChoi.h"
#include "NhapToaDoQuanCo.h"
#include "math.h"
#include"TaoBanCo.h"
//#include"GanQuanVaoBanCo.h"

MATRAN a;

using namespace std;

bool IS_TEST = false;
int GiaTriQuanCo[16] = { 1, 1, 1, 1, 1, 1, 1, 1, 2, 3, 4, 5, 6, 4, 3, 2 }; // Vi tri ban dau cua cac quan co trong ma tran
char b[33][49]; // tao ban co tren interface

void XuatMaTranBanCo(MATRAN a)
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			cout << a[i][j] << "\t";
		}
		cout << endl;
	}

	cout << endl;
}

void GanGiaTri(MATRAN a, int GiaTriQuanCo[])
{
	int k = 0;
	for (int i = 1; i >=0; i--)
	{
		for (int j = 0; j < 8; j++)
		{
			a[i][j] = GiaTriQuanCo[k++]* (-1);
		}
	}

	k = 0;
	for (int i = 6; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			a[i][j] = GiaTriQuanCo[k++];
		}
	}

}

int XacDinhQuanCo(MATRAN a, TOADO toado){
	if (a[toado.x][toado.y] > 0){
		switch (a[toado.x][toado.y])
		{
		case 1:
			return 1;
			break;
		case 2:
			return 2;
			break;
		case 3:
			return 3;
			break;
		case 4:
			return 4;
			break;
		case 5:
			return 5;
			break;
		case 6:
			return 6;
			break;
		}
	}
	else{
		switch (a[toado.x][toado.y])
		{
		case -1:
			return -1;
			break;
		case -2:
			return -2;
			break;
		case -3:
			return -3;
			break;
		case -4:
			return -4;
			break;
		case -5:
			return -5;
			break;
		case -6:
			return -6;
			break;
		case 0:
			return 0;
			break;
		}
	}
}
bool KtraOGiua(MATRAN a, TOADO toado, DESTINATION dich_den){
	for (int i = toado.x + 1; i < dich_den.x; i++){
		for (int j = toado.y + 1; j < dich_den.y; j++){
			if (a[i][j] != 0){ // nếu trên đường di chuyển tồn tại một ô không trống 
				return false;
			}
		}
	}
	return true;
}



bool KiemTraDiemDen(MATRAN a, DESTINATION dich_den, TOADO toado){
	bool kt = false;

	if (a[dich_den.x][dich_den.y] == 0){ // nếu đích đến là một ô trống
		return true;
	}

	if (a[toado.x][toado.y]*a[dich_den.x][dich_den.y] <0){  // nếu là quân khác màu
		return true;
	}
	return false;
	
	
}

bool QuanXe(MATRAN a, TOADO toado, DESTINATION dich_den){
	if (toado.x == dich_den.x || toado.y == dich_den.y){
		
		if (toado.x == dich_den.x){
			if (dich_den.y > toado.y){
				for (int i = toado.y + 1; i < dich_den.y; i++){
					if (a[toado.x][i] != 0){
						return false;
					}
				}
				return true;
			}
			if (dich_den.y < toado.y){
				for (int i = toado.y - 1; i > dich_den.y; i--){
					if (a[toado.x][i] != 0){
						return false;
					}
				}
				return true;

			}
		}
		if (toado.y == dich_den.y){
			if (dich_den.x > toado.x){
				for (int i = toado.x + 1; i < dich_den.x; i++){
					if (a[i][toado.y] != 0){
						return false;
					}
				}
				return true;
			}
			if (dich_den.x < toado.x){
				for (int i = toado.x - 1; i > dich_den.x; i--){
					if (a[i][toado.y] != 0){
						return false;
					}
				}
				return true;
			}

		}
	}
	return false;
}


bool QuanTuong(MATRAN a, TOADO toado, DESTINATION dich_den){
	if (dich_den.x == toado.x || dich_den.y == toado.y){
		return false;
	}
	for (int k = 1; k < 8; k++){
		if (toado.x + k == dich_den.x  && toado.y + k == dich_den.y){
			for (int j = 1; j < k; j++){
				if (a[toado.x + j][toado.y + j] != 0){
					return false;
				}
			}
			return true;
		}
		if (toado.x - k == dich_den.x  && toado.y + k == dich_den.y){
			for (int j = 1; j < k; j++){
				if (a[toado.x - j][toado.y + j] != 0){
					return false;
				}
			}
			return true;
		}
		if (toado.x + k == dich_den.x  && toado.y - k == dich_den.y){
			for (int j = 1; j < k; j++){
				if (a[toado.x + j][toado.y - j] != 0){
					return false;
				}
			}
			return true;
		}
		if (toado.x - k == dich_den.x  && toado.y - k == dich_den.y){
			for (int j = 1; j < k; j++){
				if (a[toado.x - j][toado.y - j] != 0){
					return false;
				}
			}
			return true;
		}
	}
}

bool QuanVua(MATRAN a, TOADO toado, DESTINATION dich_den){


	for (int i = toado.x - 1; i <= toado.x + 1; i++){
		for (int j = toado.y - 1; j <= toado.y + 1; j++){
			if (dich_den.x == i && dich_den.y == j){
				return true;
			}
		}
	}

	return false;
}
bool QuanHau(MATRAN a, TOADO toado, DESTINATION dich_den){
	if (QuanTuong(a, toado, dich_den) == true){
		return true;
	}
	if (QuanXe(a, toado, dich_den) == true){
		return true;
	}
	return false;
}


bool QuanMa(MATRAN a, TOADO toado, DESTINATION dich_den){

	// Xet xem toa do den co nam trong ma tran 5 x 5 tam la toa do hien tai hay khongs
	if ((dich_den.x >= toado.x - 2) && (dich_den.x <= toado.x + 2) && (dich_den.y >= toado.y - 2) && (dich_den.y <= toado.y + 2)) {

		// Toa do diem den nam trong ma tran 5x5. Xet xem toa do diem den co nam cung hang/cot voi toa do hien tai khong
		if ((toado.x - 2 == dich_den.x  && toado.y - 1 == dich_den.y) || (toado.x - 2 == dich_den.x && toado.y + 1 == dich_den.y)){
			return true;
		}
		if ((toado.x - 1 == dich_den.x  && toado.y - 2 == dich_den.y) || (toado.x - 1 == dich_den.x && toado.y + 2 == dich_den.y)){
			return true;
		}
		if ((toado.x + 1 == dich_den.x  && toado.y - 2 == dich_den.y) || (toado.x + 1 == dich_den.x && toado.y + 2 == dich_den.y)){
			return true;
		}
		if ((toado.x + 2 == dich_den.x  && toado.y - 1 == dich_den.y) || (toado.x + 2 == dich_den.x && toado.y + 1 == dich_den.y)){
			return true;
		}
	}
	return false;
}

bool QuanTotDuoi(MATRAN a, TOADO toado, DESTINATION dich_den){
	if (dich_den.x >= toado.x || dich_den.x < toado.x - 2 || abs(dich_den.y - toado.y) > 1) {
		return false;
	}
	// Xac dinh chot di 1 o
	if (toado.x == dich_den.x + 1 && toado.y == dich_den.y) {
		if (a[dich_den.x][dich_den.y] == 0) {
			return true;
		}

		return false;
	}

	// Xac dinh chot di 2 o
	if (toado.x == 6){
	if (toado.x == dich_den.x + 2 && toado.y == dich_den.y && a[toado.x][toado.y] > 0) {
		// Truong hop co quan chan
		
			if (a[dich_den.x][dich_den.y] != 0 || a[dich_den.x + 1][dich_den.y] != 0) {
				return false;
			}

			return true;
		}
	}
	// Xac dinh chot an cheo trai
	if ((toado.x - 1 == dich_den.x) && (toado.y - 1 == dich_den.y)){
		if (a[dich_den.x][dich_den.y] * a[toado.x][toado.y] <0){
			return true;
		}
		return false;
	}
	// Xac dinh chot an cheo phai
	if ((toado.x - 1 == dich_den.x) && (toado.y +1 == dich_den.y)){
		if (a[dich_den.x][dich_den.y] * a[toado.x][toado.y] <0){
			return true;
		}
		return false;
	}


}
bool QuanTotTren(MATRAN a, TOADO toado, DESTINATION dich_den) {
	if (dich_den.x <= toado.x || dich_den.x > toado.x + 2 || abs(dich_den.y - toado.y) > 1) {
		return false;
	} 
	// Xac dinh chot di 1 o
	if (toado.x == dich_den.x - 1 && toado.y == dich_den.y) {
		if (a[dich_den.x][dich_den.y] == 0) {
		
			return true;
			
		}
		return false;
	} // 

	// Xac dinh chot di 2 o
	if (toado.x == 1){
		if (toado.x == dich_den.x - 2 && toado.y == dich_den.y && a[toado.x][toado.y] < 0) {
			// Truong hop co quan chan


			if (a[dich_den.x][dich_den.y] != 0 || a[dich_den.x - 1][dich_den.y] != 0) {
				return false;
			}
			return true;

		}
	}
	// Xac dinh chot an cheo trai
	if ((toado.x + 1 == dich_den.x) && (toado.y - 1 == dich_den.y)){
		if (a[dich_den.x][dich_den.y] * a[toado.x][toado.y] <0){
			return true;
		}
		return false;
	}
	// Xac dinh chot an cheo phai
	if ((toado.x + 1 == dich_den.x) && (toado.y + 1 == dich_den.y)){
		if (a[dich_den.x][dich_den.y] * a[toado.x][toado.y] <0){
			
			return true;
		}
		return false;
	}

}

bool KtraPhongChot(MATRAN a, TOADO toado, DESTINATION dich_den){
	if ((a[toado.x][toado.y] == 1 && dich_den.x == 0) || (a[toado.x][toado.y] == -1 && dich_den.x == 7)){
		return true;
	}
	return false;

}

void PhongChotAI(MATRAN a,TOADO toado,DESTINATION dich_den){
	int randomai;
	randomai = 2 + rand() % (5 - 2 + 1);
	if (toado.x == 7 && a[toado.x][toado.y] == -1){
		if (a[toado.x][toado.y] < 0){
			a[dich_den.x][dich_den.y] = randomai *-1;
			a[toado.x][toado.y] = 0;
		}
	}
}
void PhongChot(MATRAN a, TOADO toado, DESTINATION dich_den){
	int n = 0;
	int tam = 0;
	if (KtraPhongChot(a, toado, dich_den) == true){
		do{
			fflush(stdin);
			cin.clear();
			gotoxy(0, 50+tam);
			cout << "UPGRADE PAWN !!!" << endl;
			gotoxy(0, 53 + tam);
			cout << "Select one chessman your pawn want to become" << endl;
			gotoxy(0, 56 + tam);
			cout << " 2. Rock \t 3. Knight \t 4.Bishop \t 5.Queen" << endl;
			cin >> n;
			tam += 3;
		} while (n <2 || n >5);
		if (a[toado.x][toado.y] > 0){
			a[dich_den.x][dich_den.y] = n;
			a[toado.x][toado.y] = 0;
		}
		if (a[toado.x][toado.y] < 0){
			a[dich_den.x][dich_den.y] = n*-1;
			a[toado.x][toado.y] = 0;
		}

	}


}


void KTraQuanAn(MATRAN a, TOADO toado, DESTINATION dich_den){
	//printf("Function KTraQuanAn called with toa do %d %d, dich den %d %d \n", toado.x, toado.y, dich_den.x, dich_den.y);
	cout << endl;
	
	if (XacDinhQuanCo(a, toado) == 2 || XacDinhQuanCo(a, toado) == -2){
		if (QuanXe(a, toado, dich_den) == true && KiemTraDiemDen(a, dich_den, toado) == true && KtraOGiua(a,toado,dich_den) == true){
			cout << "Rook move " << endl;
			a[dich_den.x][dich_den.y] = a[toado.x][toado.y];
			a[toado.x][toado.y] = 0;
		}
	}
	if (XacDinhQuanCo(a, toado) == 5 || XacDinhQuanCo(a, toado) == -5){
		if (QuanHau(a, toado, dich_den) == true && KiemTraDiemDen(a, dich_den, toado) == true && KtraOGiua(a, toado, dich_den) == true){
			cout << "Qeen move " << endl;
			a[dich_den.x][dich_den.y] = a[toado.x][toado.y];
			a[toado.x][toado.y] = 0;
		}
	}
	if (XacDinhQuanCo(a, toado) == 3 || XacDinhQuanCo(a, toado) == -3){
		if (QuanMa(a, toado, dich_den) == true && KiemTraDiemDen(a, dich_den, toado) == true && KtraOGiua(a, toado, dich_den) == true){
			cout << "Knight move " << endl;
			a[dich_den.x][dich_den.y] = a[toado.x][toado.y];
			a[toado.x][toado.y] = 0;
		}
	}
	if (XacDinhQuanCo(a, toado) == 6 || XacDinhQuanCo(a, toado) == -6){
		if (QuanVua(a, toado, dich_den) == true && KiemTraDiemDen(a, dich_den, toado) == true && KtraOGiua(a, toado, dich_den) == true){
			cout << "King move " << endl;
			a[dich_den.x][dich_den.y] = a[toado.x][toado.y];
			a[toado.x][toado.y] = 0;
		}
	}
	if (XacDinhQuanCo(a, toado) == 4 || XacDinhQuanCo(a, toado) == -4){
		if (QuanTuong(a, toado, dich_den) == true && KiemTraDiemDen(a, dich_den, toado) == true && KtraOGiua(a, toado, dich_den) == true){
			cout << "Bishop move " << endl;
			a[dich_den.x][dich_den.y] = a[toado.x][toado.y];
			a[toado.x][toado.y] = 0;
		}
	}
	if (XacDinhQuanCo(a, toado) == -1){
		
		if (QuanTotTren(a, toado, dich_den) == true && KiemTraDiemDen(a, dich_den, toado) == true && KtraOGiua(a, toado, dich_den) == true){
			if (a[toado.x][toado.y] == -1 && dich_den.x == 7){
				PhongChot(a, toado, dich_den);
			}
			else{
				cout << "Pawn move " << endl;
				a[dich_den.x][dich_den.y] = a[toado.x][toado.y];
				a[toado.x][toado.y] = 0;
			}
		}
	}
	if (XacDinhQuanCo(a, toado) == 1){
		
		if (QuanTotDuoi(a, toado, dich_den) == true && KiemTraDiemDen(a, dich_den, toado) == true && KtraOGiua(a, toado, dich_den) == true){
			if (a[toado.x][toado.y] == 1 && dich_den.x == 0){
				PhongChot(a, toado, dich_den);
			}
			else{
				cout << "Pawn move " << endl;
				a[dich_den.x][dich_den.y] = a[toado.x][toado.y];
				a[toado.x][toado.y] = 0;
			}
		}
	}
	//printf("End function KTraQuanAn");
	cout << endl;
}

int KetThuc(MATRAN a, TOADO toado){
	int dem_am = 0, dem_duong =0;
	for (int i = 0; i < 8; i++){
		for (int j = 0; j < 8; j++){
			if (a[i][j] == 6){
				dem_duong++;
			}
			if (a[i][j] == -6){
				dem_am++;
			}
		}
	}
	if (dem_am == 0){
		return -1;
	}
	if (dem_duong == 0){
		return 1;
	}
	
}


void GanLenBanCo(MATRAN a){
	for (int i = 0; i < 8; i++){
		for (int j = 0; j < 8; j++){
			gotoxy(6 * j + 2, 4 * i + 2);
			if (a[i][j] < 0){
				
				TextColor(10);
			}
			
			if (a[i][j] > 0){
				TextColor(12);
			}
			
			switch (a[i][j]){
			case 1:
			case -1:
				cout << "CHOT";
				break;

			case 2:
			case -2:
				cout << "XE";
				break;
			case 3:
			case -3:
				cout << "MA";
				break;
			case 4:
			case -4:
				cout << "TUOG";
				break;
			case 5:
			case -5:
				cout << "HAU";
				break;
			case 6:
			case -6:
				cout << "VUA";
				break;
			}
		}
	}

}

void TaoSo(MATRAN a){
	int k = 1;
	for (int i = 0; i < 49; i++){
		if (i == 3){
			gotoxy(i, 0);
			cout << k;
		}
		if (i % 7 == 0 && i < 45 && i > 3){
			k++;
			gotoxy(i, 0);
			cout << k;
		}
		if (i == 45){
			k++;
			gotoxy(i, 0);
			cout << k;
		}
	}
}





bool KTraVuaTren(MATRAN a){
	bool kt = true;
	for (int i = 0; i < 8; i++){
		for (int j = 0; j < 8; j++){
			if (a[i][j] != -6){
				kt = false;
			}
			else{
				kt = true;
				return kt;
			}
		}
	}
	return kt;
}

bool KTraVuaDuoi(MATRAN a){
	bool kt = true;
	for (int i = 0; i < 8; i++){
		for (int j = 0; j < 8; j++){
			if (a[i][j] != 6){
				kt = false;
			}
			else{
				kt = true;
				return kt;
			}
		}
	}
	return kt;
}

void DocQuanCo(MATRAN a, TOADO toado, DESTINATION dich_den){
	switch (a[toado.x][toado.y]){
	case 1: case -1:
		cout << "CHOT";
		break;
	
	case 2: case -2:
		cout << "XE";
		break;
	case 3: case -3:
		cout << "MA";
		break;
	case 4: case -4:
		cout << "TUONG";
		break;
	case 5: case -5:
		cout << "HAU";
		break;
	case 6: case -6:
		cout << "VUA";
		break;


	}
}
void DuDoanDuongDi(MATRAN a, TOADO toado){
	for (int i = 0; i < 8; i++){
		for (int j = 0; j < 8; j++){
			switch (a[toado.x][toado.y])
			{
			cout << "xet quan co di den vi tri \t(" << i + 1 << "," << j + 1 << ")" << endl;
			case 1:
				
				if ((QuanTotDuoi(a, toado, { i, j }) == true && KiemTraDiemDen(a, { i, j }, toado) == true) && KtraOGiua(a, toado, { i, j }) == true){
					cout << "Possible moves " << endl << " (" << i +1<< ", " << j+1 << ")" << endl;
				}
				break;
			case -1:
				if (QuanTotTren(a, toado, { i, j }) == true && KiemTraDiemDen(a, { i, j }, toado) == true && KtraOGiua(a, toado, { i, j }) == true){
					cout << "Possible moves" << endl << " (" << i +1<< ", " << j +1<< ")" << endl;
				}
				break;
			case 2:
			case -2:
				if ((QuanXe(a, toado, { i, j }) == true && KiemTraDiemDen(a, { i, j }, toado) == true) && KtraOGiua(a, toado, { i, j }) == true){
					cout << "Possible moves" << endl << " (" << i +1<< ", " << j+1 << ")" << endl;
				}
				break;
			case 3: case -3:
				if ((QuanMa(a, toado, { i, j }) == true && KiemTraDiemDen(a, { i, j }, toado) == true) && KtraOGiua(a, toado, { i, j }) == true){
					cout << "Possible moves" << endl << " (" << i +1<< ", " << j +1<< ")" << endl;
				}
				break;
			case 4: case -4:
				if ((QuanTuong(a, toado, { i, j }) == true && KiemTraDiemDen(a, { i, j }, toado) == true) && KtraOGiua(a, toado, { i, j }) == true){
					cout << "Possible moves" << endl << " (" << i +1<< ", " << j +1<< ")" << endl;
				}
				break;
			case 5: case -5:
				if ((QuanHau(a, toado, { i, j }) == true && KiemTraDiemDen(a, { i, j }, toado) == true) && KtraOGiua(a, toado, { i, j }) == true){
					cout << "Possible moves" << endl << " (" << i +1<< ", " << j +1<< ")" << endl;
				}
				break;
			case 6: case -6:
				if ((QuanVua(a, toado, { i, j }) == true && KiemTraDiemDen(a, { i, j }, toado) == true)){
					cout << "Possible moves" << endl << " (" << i +1<< ", " << j+1 << ")" << endl;
				}
				break;

			default:
				cout << "No moves" << endl;
				return;
				break;
			}



		}
	}

}

//che do AI

void AImode(MATRAN a){
	int ai;
	int aix, aiy;
	
	do{
		aix = 0 + rand() % (7 - 0 + 1);
	
		aiy = 0 + rand() % (7 - 0 + 1);
	} while (a[aix][aiy] >= 0 );
	
	
	
	
	for (int i = 0; i < 8; i++){
		for (int j = 0; j < 8; j++){
				switch (a[aix][aiy])
				{

				case -1:
					PhongChotAI(a, { aix, aiy }, { i, j });
					gotoxy(0, 38);
					cout << "COMPUTER CHOOSE PAWN" << endl;
					if (QuanTotTren(a, { aix, aiy }, { i, j }) == true && KiemTraDiemDen(a, { i, j }, { aix, aiy }) == true && KtraOGiua(a, { aix, aiy }, { i, j }) == true){
						a[i][j] = a[aix][aiy];
						a[aix][aiy] = 0;
					}

					break;
				case -2:
					gotoxy(0, 38);
					cout << "COMPUTER CHOOSE ROOK" << endl;
					if (QuanXe(a, { aix, aiy }, { i, j }) == true && KiemTraDiemDen(a, { i, j }, { aix, aiy }) == true && KtraOGiua(a, { aix, aiy }, { i, j }) == true){
						a[i][j] = a[aix][aiy];
						a[aix][aiy] = 0;
					}

					break;
				case -3:
					gotoxy(0, 38);
					cout << "COMPUTER CHOOSE KNIGHT" << endl;
					if (QuanMa(a, { aix, aiy }, { i, j }) == true && KiemTraDiemDen(a, { i, j }, { aix, aiy }) == true && KtraOGiua(a, { aix, aiy }, { i, j }) == true){
						a[i][j] = a[aix][aiy];
						a[aix][aiy] = 0;
					}

					break;
				case -4:
					gotoxy(0, 38);
					cout << "COMPUTER CHOOSE BISHOP" << endl;
					if (QuanTuong(a, { aix, aiy }, { i, j }) == true && KiemTraDiemDen(a, { i, j }, { aix, aiy }) == true && KtraOGiua(a, { aix, aiy }, { i, j }) == true){
						a[i][j] = a[aix][aiy];
						a[aix][aiy] = 0;
					}

					break;
				case -5:
					gotoxy(0, 38);
					cout << "COMPUTER CHOOSE QUEEN" << endl;
					if (QuanHau(a, { aix, aiy }, { i, j }) == true && KiemTraDiemDen(a, { i, j }, { aix, aiy }) == true && KtraOGiua(a, { aix, aiy }, { i, j }) == true){
						a[i][j] = a[aix][aiy];
						a[aix][aiy] = 0;
					}

					break;
				case -6:
					gotoxy(0, 38);
					cout << "COMPUTER CHOOSE KING" << endl;
					if (QuanVua(a, { aix, aiy }, { i, j }) == true && KiemTraDiemDen(a, { i, j }, { aix, aiy }) == true && KtraOGiua(a, { aix, aiy }, { i, j }) == true){
						a[i][j] = a[aix][aiy];
						a[aix][aiy] = 0;
					}

					break;

				default:
					break;
					
				}
			
		}
	}
}



void GhiFile(MATRAN a){
	int n = 8;
	FILE *f = fopen("GameData.txt", "wt");
	if (f == NULL){
		cout << "can't open this file" << endl;
		return;
	}
	fprintf(f, "%d \n %d \n", n, n);
	for (int i = 0; i < 8; i++){
		for (int j = 0; j < 8; j++){
			fprintf(f, "%d \t", a[i][j]);
		}

	}
	fclose(f);
}
void InsertNumb(){

	int dem = 2;
	for (int i = 1; i <= 8; i++){
		gotoxy(50, dem);
		cout << i;
		dem += 4;
	}
	dem = 2;
	for (int i = 1; i <= 8; i++){
		gotoxy(dem, 34);
		cout << i;
		dem += 6;
	}
}

void DocFile(MATRAN a){
	int n = 8;
	FILE *f = fopen("GameData.txt", "rt");
	if (f == NULL){
		cout << "can't open this file" << endl;
		return;
	}
	fscanf(f, "%d \n %d \n", &n ,&n);
	for (int i = 0; i < 8; i++){
		for (int j = 0; j < 8; j++){
			fscanf(f, "%d \t", &a[i][j]);
		}
	}
	fclose(f);
}



void PlayerVersusPlayer(MATRAN a, char player1[], char player2[]){
	system("cls");
	gotoxy(20, 10);
	InputNamePlayer(player1);
	gotoxy(20, 12);
	InputNamePlayer(player2);
	system("cls");
	TOADO toado;

	DESTINATION dich_den;
	int cont;
	int temp = 0;
	TaoMaTranBanCo(a);
	GanGiaTri(a, GiaTriQuanCo);
	do{
		fflush(stdin);
		cin.clear();
		gotoxy(10, 10 + temp);
		cout << "continue last game? \t 1. yes \t 2. no \t \t";
		cin >> cont;
		temp += 3;
	} while (cont <1 || cont > 2);

	if (cont == 1){
		DocFile(a);
	}
	else{
		GhiFile(a);
	}


	system("cls");
	int tam = 0;


	do{

		system("cls");
		TextColor(15);
		TaoBanCoMoi(b);
		GanLenBanCo(a);
		TextColor(11);
		InsertNumb();
		TextColor(14);
		gotoxy(58, 4);
		cout << "player 2: \t" << player2;
		gotoxy(58, 30);
		cout <<"player 1: \t" << player1;


		gotoxy(0, 38);
		TextColor(15);

		if (tam % 2 != 0){
			do{

				TextColor(15);
				NhapToaDoQuanCo(toado);
				DuDoanDuongDi(a, toado);
				if (a[toado.x][toado.y] > 0){


					cout << "PLEASE CHOOSE AGAIN!!!" << endl;


					Sleep(400);
					system("cls");

					TaoBanCoMoi(b);
					GanLenBanCo(a);
					TextColor(11);
					InsertNumb();
					TextColor(14);
					gotoxy(58, 4);
					cout << "player 2: \t" << player2;
					gotoxy(58, 30);
					cout << "player 1: \t" << player1;
					gotoxy(0, 38);

				}


			} while (a[toado.x][toado.y] > 0);
		}
		else{
			do{

				TextColor(15);
				NhapToaDoQuanCo(toado);
				DuDoanDuongDi(a, toado);
				if (a[toado.x][toado.y] < 0){
					cout << "PLEASE CHOOSE AGAIN!!!" << endl;

					Sleep(400);
					system("cls");
					TaoBanCoMoi(b);
					GanLenBanCo(a);
					TextColor(11);
					InsertNumb();
					TextColor(14);
					gotoxy(58, 4);
					cout << "player 2: \t" << player2;
					gotoxy(58, 30);
					cout << "player 1: \t" << player1;
					gotoxy(0, 38);
				}

			} while (a[toado.x][toado.y] < 0);
		}

		NhapDichDen(dich_den);
		KTraQuanAn(a, toado, dich_den);

		if (KTraVuaDuoi(a) == false){
			system("cls");
			gotoxy(10, 10);
			TextColor(14);
			cout << "CONGRATULATION!!!! PLAYER 2 WON" << endl;
			Sleep(1000);
			break;
		}
		if (KTraVuaTren(a) == false){
			system("cls");
			gotoxy(10, 10);
			TextColor(14);
			cout << "CONGRATULATION!!!!	PLAYER 1 WON" << endl;
			Sleep(1000);
			break;
		}


		cout << "Press any key to continue \t Press Esc to exit and save" << endl;
		tam++;

		if (getch() == 27){
			GhiFile(a);
		}
	} while (getch() != 27);


}


void ComvsPlayer(MATRAN a, char player1[]){
	int cont = 0;
	TOADO toado;
	srand(time(0));
	DESTINATION dich_den;
	
	int tam = 0;
	system("cls");
	gotoxy(20, 10);
	InputNamePlayer(player1);
	system("cls");
	TaoMaTranBanCo(a);
	GanGiaTri(a, GiaTriQuanCo);
	int temp = 0;
	do{
		fflush(stdin);
		cin.clear();
		gotoxy(10, 10 + temp);
		cout << "continue last game? \t 1. yes \t 2. no \t \t";
		cin >> cont;
		temp += 3;
	} while (cont <1 || cont > 2);
	if (cont == 1){
		DocFile(a);
	}
	else{
		GhiFile(a);
	}

	do{
		system("cls");
		TextColor(15);
		TaoBanCoMoi(b);
		GanLenBanCo(a);
		TextColor(11);
		InsertNumb();
		TextColor(14);
		gotoxy(58, 4);
		cout << "player 2: \t" << "COMPUTER";
		gotoxy(58, 30);
		cout << "player 1: \t" << player1;



		gotoxy(0, 38);
		TextColor(15);
		if (tam % 2 != 0){
			AImode(a);
		}
		else{
			do{
				TextColor(15);
				NhapToaDoQuanCo(toado);
				DuDoanDuongDi(a, toado);
				if (a[toado.x][toado.y] < 0){
					cout << "PLEASE CHOOSE AGAIN!!!" << endl;

					Sleep(400);
					system("cls");
					TaoBanCoMoi(b);
					GanLenBanCo(a);
					TextColor(11);
					InsertNumb();
					TextColor(14);
					gotoxy(58, 4);
					cout << "player 2: \t" << "COMPUTER";
					gotoxy(58, 30);
					cout << "player 1: \t" << player1;
					gotoxy(0, 38);
				}

			} while (a[toado.x][toado.y] < 0);
			NhapDichDen(dich_den);
			KTraQuanAn(a, toado, dich_den);
		}



		if (KTraVuaDuoi(a) == false){
			system("cls");
			gotoxy(10, 10);
			TextColor(14);
			cout << "COMPUTER WIN!!!" << endl;
			Sleep(1000);
			break;
		}
		if (KTraVuaTren(a) == false){
			system("cls");
			gotoxy(10, 10);
			TextColor(14);
			cout << "CONGRATULATION!!!!	PLAYER 1 WON" << endl;
			Sleep(1000);
			break;
		}


		cout << "Press any key to continue \t Press Esc to exit and save" << endl;
		tam++;
		if (getch() == 27){
			GhiFile(a);
		}
	} while (getch() != 27);
}

void NhapMenu(int &opt){
	int tam = 0;
	do{
		fflush(stdin);
		cin.clear();
		gotoxy(20, 10 + tam);
		cout << "1. Player vs Player" << endl;
		gotoxy(20, 12+tam);
		cout << "2. Player vs Com" << endl;
		gotoxy(20, 14+ tam);
		cout << "Your option is? \t";
		cin >> opt;
		tam += 10;
	} while (opt < 1 || opt  >2);
	
}
void LoadGame(){
	
	for (int i = 0; i <= 100; i+=5){
		gotoxy(5, 5);
		TextColor(11);
	
		cout << "\t \t \t " << "<||>  *---CHESS GAME---*  <||>" << endl;
		gotoxy(10, 10);
		TextColor(15);
		cout << "Loading Game =.................................... " << i << "%";
		Sleep(15);
		gotoxy(10, 15);
		TextColor(14);
		cout << "...updating plugins.... please wait ...." << endl;
		system("cls");


		gotoxy(5, 5);
		TextColor(11);
		cout << "\t \t \t " << "<||>  *---CHESS GAME---*  <||>" << endl;
		gotoxy(10, 10);
		TextColor(15);
		cout << "Loading Game ============......................... " << i << "%";
		Sleep(15);
		gotoxy(10, 15);
		TextColor(14);
		cout << "...updating plugins.... please wait ...." << endl;
		system("cls");

		gotoxy(5, 5);
		TextColor(11);
		cout << "\t \t \t " << "<||>  *---CHESS GAME---*  <||>" << endl;
		gotoxy(10, 10);
		TextColor(15);
		cout << "Loading Game ================================..... " << i << "%";
		Sleep(15);
		gotoxy(10, 15);
		TextColor(14);
		cout << "...updating plugins.... please wait ...." << endl;
		system("cls");

		gotoxy(5, 5);
		TextColor(11);
		cout << "\t \t \t " << "<||>  *---CHESS GAME---*  <||>" << endl;
		gotoxy(10, 10);
		TextColor(15);
		cout << "Loading Game ===================================== " << i << "%";
		Sleep(15);
		gotoxy(10, 15);
		TextColor(14);
		cout << "...updating plugins.... please wait ...." << endl;


	}
	

	gotoxy(40, 35);
	TextColor(10);
	cout << "Products by Etersoft Technologies" << endl;
	gotoxy(40, 37);
	TextColor(15);
	cout << "Contact: infinite.luan@gmail.com" << endl;
	TextColor(15);
	gotoxy(3, 50);
	TextColor(253);
	cout << "Work best in resolution 90 x 52" << endl;
	TextColor(15);
	Sleep(4000);
	system("cls");

}



void main(){
	MATRAN a;
	int opt;
	
	char player1[100], player2[100];

	/*if (IS_TEST) {
		testQuanMa(a);
		testQuanChot(a);
		getch();
		return;
	}*/

	LoadGame();
	NhapMenu(opt);

	if (opt == 1){
		PlayerVersusPlayer(a, player1, player2);
	}
	else{
		ComvsPlayer(a, player1);
	}

	system("pause");
}

