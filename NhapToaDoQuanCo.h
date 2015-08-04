#include<iostream>
typedef int MATRAN[8][8];

using namespace std;

struct TOADO{
	int x, y;
};


void NhapToaDoQuanCo(TOADO &toado){
	do{
		fflush(stdin);
		cin.clear();
		
		cout << "Please enter the current row  \t";
		cin >> toado.x;
		toado.x -= 1;

		cout << "Please enter the current column \t";
		cin >> toado.y;
		toado.y -= 1;
	} while (toado.x <0 || toado.x >7 || toado.y < 0 || toado.y >7 );
	
}



// test
void NhapToaDoQuanCoAI(TOADO &toado, int x, int y) {
	if (x < 0 || x > 7 || y < 0 || y > 7) {
		cout << "Toa do khong hop le";
		return;
	}

	toado.x = x;
	toado.y = y;
}

struct QUANCO {
	TOADO vitri;
	int mauQuan; // 1 : quan trang, -1 : quan den
	int banChat; // 1 : chot, 2: xe, 3: ma, 4: tuong, 5: Hau, 6: Vua
};

int layBieuTuongQuanCo(QUANCO quanCo) {
	return quanCo.mauQuan * quanCo.banChat;
}

void datQuanCo(MATRAN banCo, QUANCO quanCo) {
	banCo[quanCo.vitri.x][quanCo.vitri.y] = layBieuTuongQuanCo(quanCo);
}


void SetQuan(MATRAN a, QUANCO quanCo){
	a[quanCo.vitri.x][quanCo.vitri.y] = layBieuTuongQuanCo(quanCo);
}


bool kiemTraBoTest(MATRAN banCo, MATRAN banCoMau) {
	for (int i = 0; i < 8; i++){
		for (int j = 0; j < 8; j++) {
			if (banCo[i][j] != banCoMau[i][j]) {
				cout << "Ban co mau khac ban co o vi tri " << i << ", " << j << endl;
				cout << "Gia tri khac nhau : " << banCo[i][j] << " khac " << banCoMau[i][j];
				return false;
			}
		}
	}

	return true;
}

void TaoMaTranBanCo(MATRAN a){
	for (int i = 0; i < 8; i++){
		for (int j = 0; j < 8; j++)
		{
			a[i][j] = 0;
		}
	}
}

void taoTrangThai1(MATRAN banCoMau) {
	QUANCO a2, b2, c2, d2, e2, f2, g2, h2, ra1, nb1, bc1, qd1, ke1, bf1, ng1, rh1;
	QUANCO a7, b7, c7, d7, e7, f7, g7, h7, ra8, nb8, bc8, qd8, ke8, bf8, ng8, rh8;

	a2 = { { 6, 0 }, 1, 1 };
	b2 = { { 6, 1 }, 1, 1 };
	c2 = { { 6, 2 }, 1, 1 };
	d2 = { { 6, 3 }, 1, 1 };
	e2 = { { 6, 4 }, 1, 1 };
	f2 = { { 6, 5 }, 1, 1 };
	g2 = { { 6, 6 }, 1, 1 };
	h2 = { { 6, 7 }, 1, 1 };

	ra1 = { { 7, 0 }, 1, 2 };
	nb1 = { { 7, 1 }, 1, 3 };
	bc1 = { { 7, 2 }, 1, 4 };
	qd1 = { { 7, 3 }, 1, 5 };
	ke1 = { { 7, 4 }, 1, 6 };
	bf1 = { { 7, 5 }, 1, 4 };
	ng1 = { { 7, 6 }, 1, 3 };
	rh1 = { { 7, 7 }, 1, 2 };

	a7 = { { 1, 0 }, -1, 1 };
	b7 = { { 1, 1 }, -1, 1 };
	c7 = { { 1, 2 }, -1, 1 };
	d7 = { { 1, 3 }, -1, 1 };
	e7 = { { 1, 4 }, -1, 1 };
	f7 = { { 1, 5 }, -1, 1 };
	g7 = { { 1, 6 }, -1, 1 };
	h7 = { { 1, 7 }, -1, 1 };

	ra8 = { { 0, 0 }, -1, 2 };
	nb8 = { { 0, 1 }, -1, 3 };
	bc8 = { { 0, 2 }, -1, 4 };
	qd8 = { { 0, 3 }, -1, 5 };
	ke8 = { { 0, 4 }, -1, 6 };
	bf8 = { { 0, 5 }, -1, 4 };
	ng8 = { { 0, 6 }, -1, 3 };
	rh8 = { { 0, 7 }, -1, 2 };

	QUANCO danhSach[] = { a2, b2, c2, d2, e2, f2, g2, h2,
						ra1, nb1, bc1, qd1, ke1, bf1, ng1, rh1,
						a7, b7, c7, d7, e7, f7, g7, h7, 
						ra8, nb8, bc8, qd8, ke8, bf8, ng8, rh8 };
	TaoMaTranBanCo(banCoMau);

	for (int i = 0; i < 32; i++) {
		datQuanCo(banCoMau, danhSach[i]);
	}
}

void taoTrangThai2(MATRAN banCoMau) {
	QUANCO a2, b2, c2, d2, e2, f2, g2, h2, ra1, nb1, bc1, qd1, ke1, bf1, ng1, rh1;
	QUANCO a7, b7, c7, d7, e7, f7, g7, h7, ra8, nb8, bc8, qd8, ke8, bf8, ng8, rh8;

	a2 = { { 6, 0 }, 1, 1 };
	b2 = { { 6, 1 }, 1, 1 };
	c2 = { { 6, 2 }, 1, 1 };
	d2 = { { 6, 3 }, 1, 1 };
	e2 = { { 4, 4 }, 1, 1 };
	f2 = { { 6, 5 }, 1, 1 };
	g2 = { { 6, 6 }, 1, 1 };
	h2 = { { 6, 7 }, 1, 1 };

	ra1 = { { 7, 0 }, 1, 2 };
	nb1 = { { 7, 1 }, 1, 3 };
	bc1 = { { 7, 2 }, 1, 4 };
	qd1 = { { 7, 3 }, 1, 5 };
	ke1 = { { 7, 4 }, 1, 6 };
	bf1 = { { 7, 5 }, 1, 4 };
	ng1 = { { 7, 6 }, 1, 3 };
	rh1 = { { 7, 7 }, 1, 2 };

	a7 = { { 1, 0 }, -1, 1 };
	b7 = { { 1, 1 }, -1, 1 };
	c7 = { { 1, 2 }, -1, 1 };
	d7 = { { 1, 3 }, -1, 1 };
	e7 = { { 1, 4 }, -1, 1 };
	f7 = { { 1, 5 }, -1, 1 };
	g7 = { { 1, 6 }, -1, 1 };
	h7 = { { 1, 7 }, -1, 1 };

	ra8 = { { 0, 0 }, -1, 2 };
	nb8 = { { 0, 1 }, -1, 3 };
	bc8 = { { 0, 2 }, -1, 4 };
	qd8 = { { 0, 3 }, -1, 5 };
	ke8 = { { 0, 4 }, -1, 6 };
	bf8 = { { 0, 5 }, -1, 4 };
	ng8 = { { 0, 6 }, -1, 3 };
	rh8 = { { 0, 7 }, -1, 2 };

	QUANCO danhSach[] = { a2, b2, c2, d2, e2, f2, g2, h2,
		ra1, nb1, bc1, qd1, ke1, bf1, ng1, rh1,
		a7, b7, c7, d7, e7, f7, g7, h7,
		ra8, nb8, bc8, qd8, ke8, bf8, ng8, rh8 };
	TaoMaTranBanCo(banCoMau);

	for (int i = 0; i < 32; i++) {
		datQuanCo(banCoMau, danhSach[i]);
	}
}

void taoTrangThai3(MATRAN banCoMau) {
	QUANCO a2, b2, c2, d2, e2, f2, g2, h2, ra1, nb1, bc1, qd1, ke1, bf1, ng1, rh1;
	QUANCO a7, b7, c7, d7, e7, f7, g7, h7, ra8, nb8, bc8, qd8, ke8, bf8, ng8, rh8;

	a2 = { { 6, 0 }, 1, 1 };
	b2 = { { 6, 1 }, 1, 1 };
	c2 = { { 6, 2 }, 1, 1 };
	d2 = { { 6, 3 }, 1, 1 };
	e2 = { { 4, 4 }, 1, 1 };
	f2 = { { 6, 5 }, 1, 1 };
	g2 = { { 6, 6 }, 1, 1 };
	h2 = { { 6, 7 }, 1, 1 };

	ra1 = { { 7, 0 }, 1, 2 };
	nb1 = { { 7, 1 }, 1, 3 };
	bc1 = { { 7, 2 }, 1, 4 };
	qd1 = { { 7, 3 }, 1, 5 };
	ke1 = { { 7, 4 }, 1, 6 };
	bf1 = { { 7, 5 }, 1, 4 };
	ng1 = { { 7, 6 }, 1, 3 };
	rh1 = { { 7, 7 }, 1, 2 };

	a7 = { { 1, 0 }, -1, 1 };
	b7 = { { 1, 1 }, -1, 1 };
	c7 = { { 1, 2 }, -1, 1 };
	d7 = { { 1, 3 }, -1, 1 };
	e7 = { { 3, 4 }, -1, 1 };
	f7 = { { 1, 5 }, -1, 1 };
	g7 = { { 1, 6 }, -1, 1 };
	h7 = { { 1, 7 }, -1, 1 };

	ra8 = { { 0, 0 }, -1, 2 };
	nb8 = { { 0, 1 }, -1, 3 };
	bc8 = { { 0, 2 }, -1, 4 };
	qd8 = { { 0, 3 }, -1, 5 };
	ke8 = { { 0, 4 }, -1, 6 };
	bf8 = { { 0, 5 }, -1, 4 };
	ng8 = { { 0, 6 }, -1, 3 };
	rh8 = { { 0, 7 }, -1, 2 };

	QUANCO danhSach[] = { a2, b2, c2, d2, e2, f2, g2, h2,
		ra1, nb1, bc1, qd1, ke1, bf1, ng1, rh1,
		a7, b7, c7, d7, e7, f7, g7, h7,
		ra8, nb8, bc8, qd8, ke8, bf8, ng8, rh8 };
	TaoMaTranBanCo(banCoMau);

	for (int i = 0; i < 32; i++) {
		datQuanCo(banCoMau, danhSach[i]);
	}
}
void taoTrangThai4(MATRAN banCoMau) {
	QUANCO a2, b2, c2, d2, e2, f2, g2, h2, ra1, nb1, bc1, qd1, ke1, bf1, ng1, rh1;
	QUANCO a7, b7, c7, d7, e7, f7, g7, h7, ra8, nb8, bc8, qd8, ke8, bf8, ng8, rh8;

	a2 = { { 6, 0 }, 1, 1 };
	b2 = { { 6, 1 }, 1, 1 };
	c2 = { { 6, 2 }, 1, 1 };
	d2 = { { 6, 3 }, 1, 1 };
	e2 = { { 4, 4 }, 1, 1 };
	f2 = { { 6, 5 }, 1, 1 };
	g2 = { { 6, 6 }, 1, 1 };
	h2 = { { 6, 7 }, 1, 1 };

	ra1 = { { 7, 0 }, 1, 2 };
	nb1 = { { 7, 1 }, 1, 3 };
	bc1 = { { 7, 2 }, 1, 4 };
	qd1 = { { 7, 3 }, 1, 5 };
	ke1 = { { 7, 4 }, 1, 6 };
	bf1 = { { 7, 5 }, 1, 4 };
	ng1 = { { 5, 5 }, 1, 3 };
	rh1 = { { 7, 7 }, 1, 2 };

	a7 = { { 1, 0 }, -1, 1 };
	b7 = { { 1, 1 }, -1, 1 };
	c7 = { { 1, 2 }, -1, 1 };
	d7 = { { 1, 3 }, -1, 1 };
	e7 = { { 3, 4 }, -1, 1 };
	f7 = { { 1, 5 }, -1, 1 };
	g7 = { { 1, 6 }, -1, 1 };
	h7 = { { 1, 7 }, -1, 1 };

	ra8 = { { 0, 0 }, -1, 2 };
	nb8 = { { 0, 1 }, -1, 3 };
	bc8 = { { 0, 2 }, -1, 4 };
	qd8 = { { 0, 3 }, -1, 5 };
	ke8 = { { 0, 4 }, -1, 6 };
	bf8 = { { 0, 5 }, -1, 4 };
	ng8 = { { 0, 6 }, -1, 3 };
	rh8 = { { 0, 7 }, -1, 2 };

	QUANCO danhSach[] = { a2, b2, c2, d2, e2, f2, g2, h2,
		ra1, nb1, bc1, qd1, ke1, bf1, ng1, rh1,
		a7, b7, c7, d7, e7, f7, g7, h7,
		ra8, nb8, bc8, qd8, ke8, bf8, ng8, rh8 };
	TaoMaTranBanCo(banCoMau);

	for (int i = 0; i < 32; i++) {
		datQuanCo(banCoMau, danhSach[i]);
	}
}


void taoTrangThai5(MATRAN banCoMau) {
	QUANCO a2, b2, c2, d2, e2, f2, g2, h2, ra1, nb1, bc1, qd1, ke1, bf1, ng1, rh1;
	QUANCO a7, b7, c7, d7, e7, f7, g7, h7, ra8, nb8, bc8, qd8, ke8, bf8, ng8, rh8;

	a2 = { { 6, 0 }, 1, 1 };
	b2 = { { 6, 1 }, 1, 1 };
	c2 = { { 6, 2 }, 1, 1 };
	d2 = { { 6, 3 }, 1, 1 };
	e2 = { { 4, 4 }, 1, 1 };
	f2 = { { 6, 5 }, 1, 1 };
	g2 = { { 6, 6 }, 1, 1 };
	h2 = { { 6, 7 }, 1, 1 };

	ra1 = { { 7, 0 }, 1, 2 };
	nb1 = { { 7, 1 }, 1, 3 };
	bc1 = { { 7, 2 }, 1, 4 };
	qd1 = { { 7, 3 }, 1, 5 };
	ke1 = { { 7, 4 }, 1, 6 };
	bf1 = { { 7, 5 }, 1, 4 };
	ng1 = { { 5, 5 }, 1, 3 };
	rh1 = { { 7, 7 }, 1, 2 };

	a7 = { { 1, 0 }, -1, 1 };
	b7 = { { 1, 1 }, -1, 1 };
	c7 = { { 1, 2 }, -1, 1 };
	d7 = { { 2, 3 }, -1, 1 };
	e7 = { { 3, 4 }, -1, 1 };
	f7 = { { 1, 5 }, -1, 1 };
	g7 = { { 1, 6 }, -1, 1 };
	h7 = { { 1, 7 }, -1, 1 };

	ra8 = { { 0, 0 }, -1, 2 };
	nb8 = { { 0, 1 }, -1, 3 };
	bc8 = { { 0, 2 }, -1, 4 };
	qd8 = { { 0, 3 }, -1, 5 };
	ke8 = { { 0, 4 }, -1, 6 };
	bf8 = { { 0, 5 }, -1, 4 };
	ng8 = { { 0, 6 }, -1, 3 };
	rh8 = { { 0, 7 }, -1, 2 };

	QUANCO danhSach[] = { a2, b2, c2, d2, e2, f2, g2, h2,
		ra1, nb1, bc1, qd1, ke1, bf1, ng1, rh1,
		a7, b7, c7, d7, e7, f7, g7, h7,
		ra8, nb8, bc8, qd8, ke8, bf8, ng8, rh8 };
	TaoMaTranBanCo(banCoMau);

	for (int i = 0; i < 32; i++) {
		datQuanCo(banCoMau, danhSach[i]);
	}
}


void taoTrangThai6(MATRAN banCoMau) {
	QUANCO a2, b2, c2, d2, e2, f2, g2, h2, ra1, nb1, bc1, qd1, ke1, bf1, ng1, rh1;
	QUANCO a7, b7, c7, d7, e7, f7, g7, h7, ra8, nb8, bc8, qd8, ke8, bf8, ng8, rh8;

	a2 = { { 6, 0 }, 1, 1 };
	b2 = { { 6, 1 }, 1, 1 };
	c2 = { { 6, 2 }, 1, 1 };
	d2 = { { 4, 3 }, 1, 1 };
	e2 = { { 4, 4 }, 1, 1 };
	f2 = { { 6, 5 }, 1, 1 };
	g2 = { { 6, 6 }, 1, 1 };
	h2 = { { 6, 7 }, 1, 1 };

	ra1 = { { 7, 0 }, 1, 2 };
	nb1 = { { 7, 1 }, 1, 3 };
	bc1 = { { 7, 2 }, 1, 4 };
	qd1 = { { 7, 3 }, 1, 5 };
	ke1 = { { 7, 4 }, 1, 6 };
	bf1 = { { 7, 5 }, 1, 4 };
	ng1 = { { 5, 5 }, 1, 3 };
	rh1 = { { 7, 7 }, 1, 2 };

	a7 = { { 1, 0 }, -1, 1 };
	b7 = { { 1, 1 }, -1, 1 };
	c7 = { { 1, 2 }, -1, 1 };
	d7 = { { 2, 3 }, -1, 1 };
	e7 = { { 3, 4 }, -1, 1 };
	f7 = { { 1, 5 }, -1, 1 };
	g7 = { { 1, 6 }, -1, 1 };
	h7 = { { 1, 7 }, -1, 1 };

	ra8 = { { 0, 0 }, -1, 2 };
	nb8 = { { 0, 1 }, -1, 3 };
	bc8 = { { 0, 2 }, -1, 4 };
	qd8 = { { 0, 3 }, -1, 5 };
	ke8 = { { 0, 4 }, -1, 6 };
	bf8 = { { 0, 5 }, -1, 4 };
	ng8 = { { 0, 6 }, -1, 3 };
	rh8 = { { 0, 7 }, -1, 2 };

	QUANCO danhSach[] = { a2, b2, c2, d2, e2, f2, g2, h2,
		ra1, nb1, bc1, qd1, ke1, bf1, ng1, rh1,
		a7, b7, c7, d7, e7, f7, g7, h7,
		ra8, nb8, bc8, qd8, ke8, bf8, ng8, rh8 };
	TaoMaTranBanCo(banCoMau);

	for (int i = 0; i < 32; i++) {
		datQuanCo(banCoMau, danhSach[i]);
	}
}


void taoTrangThai7(MATRAN banCoMau) {
	QUANCO a2, b2, c2, d2, e2, f2, g2, h2, ra1, nb1, bc1, qd1, ke1, bf1, ng1, rh1;
	QUANCO a7, b7, c7, d7, e7, f7, g7, h7, ra8, nb8, bc8, qd8, ke8, bf8, ng8, rh8;

	a2 = { { 6, 0 }, 1, 1 };
	b2 = { { 6, 1 }, 1, 1 };
	c2 = { { 6, 2 }, 1, 1 };
	d2 = { { 4, 3 }, 1, 1 };
	e2 = { { 4, 4 }, 1, 1 };
	f2 = { { 6, 5 }, 1, 1 };
	g2 = { { 6, 6 }, 1, 1 };
	h2 = { { 6, 7 }, 1, 1 };

	ra1 = { { 7, 0 }, 1, 2 };
	nb1 = { { 7, 1 }, 1, 3 };
	bc1 = { { 7, 2 }, 1, 4 };
	qd1 = { { 7, 3 }, 1, 5 };
	ke1 = { { 7, 4 }, 1, 6 };
	bf1 = { { 7, 5 }, 1, 4 };
	ng1 = { { 5, 5 }, 1, 3 };
	rh1 = { { 7, 7 }, 1, 2 };

	a7 = { { 1, 0 }, -1, 1 };
	b7 = { { 1, 1 }, -1, 1 };
	c7 = { { 1, 2 }, -1, 1 };
	d7 = { { 2, 3 }, -1, 1 };
	e7 = { { 3, 4 }, -1, 1 };
	f7 = { { 1, 5 }, -1, 1 };
	g7 = { { 1, 6 }, -1, 1 };
	h7 = { { 1, 7 }, -1, 1 };

	ra8 = { { 0, 0 }, -1, 2 };
	nb8 = { { 0, 1 }, -1, 3 };
	bc8 = { { 4, 6 }, -1, 4 };
	qd8 = { { 0, 3 }, -1, 5 };
	ke8 = { { 0, 4 }, -1, 6 };
	bf8 = { { 0, 5 }, -1, 4 };
	ng8 = { { 0, 6 }, -1, 3 };
	rh8 = { { 0, 7 }, -1, 2 };

	QUANCO danhSach[] = { a2, b2, c2, d2, e2, f2, g2, h2,
		ra1, nb1, bc1, qd1, ke1, bf1, ng1, rh1,
		a7, b7, c7, d7, e7, f7, g7, h7,
		ra8, nb8, bc8, qd8, ke8, bf8, ng8, rh8 };
	TaoMaTranBanCo(banCoMau);

	for (int i = 0; i < 32; i++) {
		datQuanCo(banCoMau, danhSach[i]);
	}
}




void taoTrangThai8(MATRAN banCoMau) {
	QUANCO a2, b2, c2, d2, e2, f2, g2, h2, ra1, nb1, bc1, qd1, ke1, bf1, ng1, rh1;
	QUANCO a7, b7, c7, d7, e7, f7, g7, h7, ra8, nb8, bc8, qd8, ke8, bf8, ng8, rh8;

	a2 = { { 6, 0 }, 1, 1 };
	b2 = { { 6, 1 }, 1, 1 };
	c2 = { { 6, 2 }, 1, 1 };
	d2 = { { 3, 4 }, 1, 1 };
	e2 = { { 4, 4 }, 1, 1 };
	f2 = { { 6, 5 }, 1, 1 };
	g2 = { { 6, 6 }, 1, 1 };
	h2 = { { 6, 7 }, 1, 1 };

	ra1 = { { 7, 0 }, 1, 2 };
	nb1 = { { 7, 1 }, 1, 3 };
	bc1 = { { 7, 2 }, 1, 4 };
	qd1 = { { 7, 3 }, 1, 5 };
	ke1 = { { 7, 4 }, 1, 6 };
	bf1 = { { 7, 5 }, 1, 4 };
	ng1 = { { 5, 5 }, 1, 3 };
	rh1 = { { 7, 7 }, 1, 2 };

	a7 = { { 1, 0 }, -1, 1 };
	b7 = { { 1, 1 }, -1, 1 };
	c7 = { { 1, 2 }, -1, 1 };
	d7 = { { 2, 3 }, -1, 1 };
	//e7 = { { 3, 4 }, -1, 1 };
	f7 = { { 1, 5 }, -1, 1 };
	g7 = { { 1, 6 }, -1, 1 };
	h7 = { { 1, 7 }, -1, 1 };

	ra8 = { { 0, 0 }, -1, 2 };
	nb8 = { { 0, 1 }, -1, 3 };
	bc8 = { { 4, 6 }, -1, 4 };
	qd8 = { { 0, 3 }, -1, 5 };
	ke8 = { { 0, 4 }, -1, 6 };
	bf8 = { { 0, 5 }, -1, 4 };
	ng8 = { { 0, 6 }, -1, 3 };
	rh8 = { { 0, 7 }, -1, 2 };

	QUANCO danhSach[] = { a2, b2, c2, d2, e2, f2, g2, h2,
		ra1, nb1, bc1, qd1, ke1, bf1, ng1, rh1,
		a7, b7, c7, d7, f7, g7, h7,
		ra8, nb8, bc8, qd8, ke8, bf8, ng8, rh8 };
	TaoMaTranBanCo(banCoMau);

	for (int i = 0; i < 32; i++) {
		datQuanCo(banCoMau, danhSach[i]);
	}
}
void taoTrangThai9(MATRAN banCoMau) {
	QUANCO a2, b2, c2, d2, e2, f2, g2, h2, ra1, nb1, bc1, qd1, ke1, bf1, ng1, rh1;
	QUANCO a7, b7, c7, d7, e7, f7, g7, h7, ra8, nb8, bc8, qd8, ke8, bf8, ng8, rh8;

	a2 = { { 6, 0 }, 1, 1 };
	b2 = { { 6, 1 }, 1, 1 };
	c2 = { { 6, 2 }, 1, 1 };
	d2 = { { 3, 4 }, 1, 1 };
	e2 = { { 4, 4 }, 1, 1 };
	f2 = { { 6, 5 }, 1, 1 };
	g2 = { { 6, 6 }, 1, 1 };
	h2 = { { 6, 7 }, 1, 1 };

	ra1 = { { 7, 0 }, 1, 2 };
	nb1 = { { 7, 1 }, 1, 3 };
	bc1 = { { 7, 2 }, 1, 4 };
	qd1 = { { 7, 3 }, 1, 5 };
	ke1 = { { 7, 4 }, 1, 6 };
	bf1 = { { 7, 5 }, 1, 4 };
	//ng1 = { { 5, 5 }, 1, 3 };
	rh1 = { { 7, 7 }, 1, 2 };

	a7 = { { 1, 0 }, -1, 1 };
	b7 = { { 1, 1 }, -1, 1 };
	c7 = { { 1, 2 }, -1, 1 };
	d7 = { { 2, 3 }, -1, 1 };
	//e7 = { { 3, 4 }, -1, 1 };
	f7 = { { 1, 5 }, -1, 1 };
	g7 = { { 1, 6 }, -1, 1 };
	h7 = { { 1, 7 }, -1, 1 };

	ra8 = { { 0, 0 }, -1, 2 };
	nb8 = { { 0, 1 }, -1, 3 };
	bc8 = { { 5, 5 }, -1, 4 };
	qd8 = { { 0, 3 }, -1, 5 };
	ke8 = { { 0, 4 }, -1, 6 };
	bf8 = { { 0, 5 }, -1, 4 };
	ng8 = { { 0, 6 }, -1, 3 };
	rh8 = { { 0, 7 }, -1, 2 };

	QUANCO danhSach[] = { a2, b2, c2, d2, e2, f2, g2, h2,
		ra1, nb1, bc1, qd1, ke1, bf1, rh1,
		a7, b7, c7, d7, f7, g7, h7,
		ra8, nb8, bc8, qd8, ke8, bf8, ng8, rh8 };
	TaoMaTranBanCo(banCoMau);

	for (int i = 0; i < 32; i++) {
		datQuanCo(banCoMau, danhSach[i]);
	}
}