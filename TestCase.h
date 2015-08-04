#include<iostream>
#include"NhapBuocDi.h"
#include"NhapToaDoQuanCo.h"

using namespace std;

bool kiemTraNuocDiMa(MATRAN a, TOADO viTri, DESTINATION diemDen, bool ketQuaMongDoi, string tenBoTest) {
	bool ketqua = QuanMa(a, viTri, diemDen);
	if (ketqua == ketQuaMongDoi) {
		cout << "Test " << tenBoTest << " passed" << endl;
		return true;
	}
	else {
		cout << "Test " << tenBoTest << " failed" << endl;
		return false;
	}
}

bool kiemTraNuocDiTotDuoi(MATRAN a, TOADO viTri, DESTINATION diemDen, bool ketQuaMongDoi, string tenBoTest) {
	bool ketqua = QuanTotDuoi(a, viTri, diemDen);
	if (ketqua == ketQuaMongDoi) {
		cout << "Test " << tenBoTest << " passed" << endl;
		return true;
	}
	else {
		cout << "Test " << tenBoTest << " failed" << endl;
		return false;
	}
}

void testQuanChot(MATRAN a) {
	if (kiemTraNuocDiTotDuoi(a, TOADO{ 6, 0 }, DESTINATION{ 4, 0 }, true, "quan tot duoi phai di duoc 2 o tu vi tri dau tien")) {
		cout << "Kiem tra tot duoi that bai" << endl;
	}

	if (kiemTraNuocDiTotDuoi(a, TOADO{ 6, 0 }, DESTINATION{ 5, 0 }, true, "quan tot duoi phai di duoc 1 o tu vi tri dau tien")) {
		cout << "Kiem tra tot duoi that bai" << endl;
	}

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (i == 4 && j == 0) continue;
			if (i == 5 && j == 0) continue;

			string thongBao = "quan tot duoi o vi tri 7 1 khong duoc di den vi tri da chon";
			if (!kiemTraNuocDiTotDuoi(a, TOADO{ 6, 0 }, DESTINATION{ i, j }, false, thongBao)) {
				cout << "quan tot duoi o vi tri 7 1 khong duoc di den vi tri " << i << "," << j << endl;
				cout << "Kiem tra tot duoi that bai" << endl;
			}
		}
	}
}




void testQuanMa(MATRAN a) {
	if (
		kiemTraNuocDiMa(a, TOADO{ 2, 3 }, DESTINATION{ 5, 1 }, false, "quan ma khong di duoc ngoai ma tran 5 x 5") &&
		kiemTraNuocDiMa(a, TOADO{ 2, 3 }, DESTINATION{ 1, 4 }, false, "quan ma khong di duoc tren duong cheo") &&
		kiemTraNuocDiMa(a, TOADO{ 2, 3 }, DESTINATION{ 2, 1 }, false, "quan ma  khong di duoc cung hang") &&
		kiemTraNuocDiMa(a, TOADO{ 2, 3 }, DESTINATION{ 1, 5 }, true, "quan ma  di chu L") &&
		kiemTraNuocDiMa(a, TOADO{ 1, 1 }, DESTINATION{ -1, 2 }, false, "quan ma  khong di duoc cung hang")) {
		cout << "Test Ma thanh cong!!";
	}
	else {
		cout << "Test Ma that bai~~";
	}
}

void Test(){

	MATRAN banCoMau;
	TOADO toado;
	DESTINATION dichDen;
	int GiaTriQuanCo[16] = { 1, 1, 1, 1, 1, 1, 1, 1, 2, 3, 4, 5, 6, 4, 3, 2 };
	TaoMaTranBanCo(a);
	GanGiaTri(a, GiaTriQuanCo);
	XuatMaTranBanCo(a);
	cout << "so sanh " << endl;
	taoTrangThai1(banCoMau);
	XuatMaTranBanCo(banCoMau);

	if (!kiemTraBoTest(a, banCoMau)) {
		cout << "ERROR: Bo test 1 khong giong ban co mau" << endl;
	}
	else {
		cout << "Test 1 passed!";
	}

	NhapToaDoQuanCoAI(toado, 6, 4);
	NhapDichDenAI(dichDen, 4, 4);
	KTraQuanAn(a, toado, dichDen);
	XuatMaTranBanCo(a);
	taoTrangThai2(banCoMau);
	if (kiemTraBoTest(a, banCoMau) == false) {
		cout << "ERROR: Bo test 2 khong giong ban co mau" << endl;
	}
	else {
		cout << "Test 2 passed!";
	}

	NhapToaDoQuanCoAI(toado, 1, 4);
	NhapDichDenAI(dichDen, 3, 4);
	KTraQuanAn(a, toado, dichDen);
	XuatMaTranBanCo(a);
	cout << "so sanh " << endl;
	taoTrangThai3(banCoMau);
	XuatMaTranBanCo(banCoMau);
	if (kiemTraBoTest(a, banCoMau) == false) {
		cout << "ERROR: Bo test 2 khong giong ban co mau" << endl;
	}
	else {
		cout << "Test 3 passed!";
	}

	NhapToaDoQuanCoAI(toado, 7, 6);
	NhapDichDenAI(dichDen, 5, 5);
	KTraQuanAn(a, toado, dichDen);
	XuatMaTranBanCo(a);
	cout << "so sanh " << endl;
	taoTrangThai4(banCoMau);
	XuatMaTranBanCo(banCoMau);
	if (kiemTraBoTest(a, banCoMau) == false) {
		cout << "ERROR: Bo test 2 khong giong ban co mau" << endl;
	}
	else {
		cout << "Test 4 passed!";
	}


	NhapToaDoQuanCoAI(toado, 1, 3);
	NhapDichDenAI(dichDen, 2, 3);
	KTraQuanAn(a, toado, dichDen);
	XuatMaTranBanCo(a);
	cout << "so sanh " << endl;
	taoTrangThai5(banCoMau);
	XuatMaTranBanCo(banCoMau);
	if (kiemTraBoTest(a, banCoMau) == false) {
		cout << "ERROR: Bo test 2 khong giong ban co mau" << endl;
	}
	else {
		cout << "Test 5 passed!";
	}


	NhapToaDoQuanCoAI(toado, 6, 3);
	NhapDichDenAI(dichDen, 4, 3);
	KTraQuanAn(a, toado, dichDen);
	XuatMaTranBanCo(a);
	cout << "so sanh " << endl;
	taoTrangThai6(banCoMau);
	XuatMaTranBanCo(banCoMau);
	if (kiemTraBoTest(a, banCoMau) == false) {
		cout << "ERROR: Bo test 2 khong giong ban co mau" << endl;
	}
	else {
		cout << "Test 6 passed!";
	}


	NhapToaDoQuanCoAI(toado, 0, 2);
	NhapDichDenAI(dichDen, 4, 6);
	KTraQuanAn(a, toado, dichDen);
	XuatMaTranBanCo(a);
	cout << "so sanh " << endl;
	taoTrangThai7(banCoMau);
	XuatMaTranBanCo(banCoMau);
	if (kiemTraBoTest(a, banCoMau) == false) {
		cout << "ERROR: Bo test 2 khong giong ban co mau" << endl;
	}
	else {
		cout << "Test 7 passed!";
	}


	NhapToaDoQuanCoAI(toado, 4, 3);
	NhapDichDenAI(dichDen, 3, 4);
	KTraQuanAn(a, toado, dichDen);
	XuatMaTranBanCo(a);
	cout << "so sanh " << endl;
	taoTrangThai8(banCoMau);
	XuatMaTranBanCo(banCoMau);
	if (kiemTraBoTest(a, banCoMau) == false) {
		cout << "ERROR: Bo test 2 khong giong ban co mau" << endl;
	}
	else {
		cout << "Test 8 passed!";
	}


	NhapToaDoQuanCoAI(toado, 4, 6);
	NhapDichDenAI(dichDen, 5, 5);
	KTraQuanAn(a, toado, dichDen);
	XuatMaTranBanCo(a);
	cout << "so sanh " << endl;
	taoTrangThai9(banCoMau);
	XuatMaTranBanCo(banCoMau);
	if (kiemTraBoTest(a, banCoMau) == false) {
		cout << "ERROR: Bo test 2 khong giong ban co mau" << endl;
	}
	else {
		cout << "Test 9 passed!";
	}
}
