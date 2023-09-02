#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
// sang do  --> 12
// sang aqua --> 11
// sang xanh la --> 10
// sang vang --> 14
// trang --> 7

void SET_COLOR(int color)
{
	WORD wColor;
     

     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
     CONSOLE_SCREEN_BUFFER_INFO csbi;
     if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {
          wColor = (csbi.wAttributes & 0xF0) + (color & 0x0F);
          SetConsoleTextAttribute(hStdOut, wColor);
     }
}

void khoi_tao(){
	SET_COLOR(11);
	cout << "Hay chon mot so : " ;
	cout << "       0 : Bua        1 : Keo        2 : Bao";
	cout << endl << endl;
}

string kiem_tra(int nguoi_chon, int may_chon){
	if(nguoi_chon == may_chon){
		return "draw";
	}
	if(nguoi_chon == 0){
		if(may_chon == 2){
			return "may";
		}else{
			return "nguoi";
		}
	}
   	if(nguoi_chon == 1){
	    if(may_chon == 0){
	    	return "may";
		}else
		{
			return "nguoi";
			}
		}
	if(nguoi_chon == 2){
		if(may_chon == 1){
			return "may";
		}else
		{
			return "nguoi";
		}
	}
}

int Ran(int l, int r){
	return l + rand() % (r - l + 1);
}

int diem_nguoi = 0, diem_may = 0;
string type[3] = {"Bua", "Keo", "Bao"};

int main()
{
	srand(time(NULL));
	SET_COLOR(14);
	cout << " Hom nay ta se choi mot tro keo bua bao :)" << endl << endl;
	SET_COLOR(12);
	cout << " Luat choi rat don gian : + Ban nhap so luot choi" << endl;
	cout << "                         + Nhap ki hieu bat ki ( Keo, Bua, Bao)" << endl;
	cout << "                         + Nguoi may se choi voi ban tuong ung voi so luot choi :))" << endl;
	cout << "                         + Cuoi cung la ket qua :)" << endl;
	SET_COLOR(14);
	cout << " Chuc ban choi vui ve :))" << endl << endl;
	cout << " Ban hay nhap so luot choi tuong ung : ";
	int Luot_choi;
	SET_COLOR(11);
	string Xu_Ly; 
	SET_COLOR(10);
	getline(cin, Xu_Ly);
	
    while(true){
    	int cnt = 0;
    	for(int i = 0 ; i < Xu_Ly.size() ; i++){
    		if('0' <= Xu_Ly[i] && Xu_Ly[i] <= '9'){
    			continue;
			}else
			{
				cnt++;
			}
		}
		if(cnt > 0){
			SET_COLOR(4);
			cout << " Bi loi !!!" << endl;
			cout << " Hay nhap lai so tuong ung : ";
			SET_COLOR(10);
			getline(cin, Xu_Ly);
			cout << endl;
		}else
		{
			Luot_choi = stoi(Xu_Ly);
			if(Luot_choi == 1){
				SET_COLOR(4);
				cout << " Bi loi !!!" << endl;
		    	cout << " Hay nhap lai so tuong ung : ";
		    	SET_COLOR(10);
		    	getline(cin, Xu_Ly);
		    	cout << endl;
			}else
			{
				cout << endl;
				break;
			}
		}
	}
	
	while(Luot_choi--){
		khoi_tao();
		int may_chon = Ran(0, 2);
		cout << "----> ";
		SET_COLOR(10);
		string fake_choose; getline(cin, fake_choose);
		cout << endl;
	    int nguoi_chon;
	    while(true){
	    	if(fake_choose.size() != 1){
	    		SET_COLOR(4);
	    	    cout << " Du lieu khong hop le !!!" << endl;
				cout << " Hay nhap lai so tuong ung : ";
				SET_COLOR(10);
				getline(cin, fake_choose);
				cout << endl;
			}else
			{
				if('0' <= fake_choose[0] && fake_choose[0] <= '2'){
					nguoi_chon = fake_choose[0] - 48;
					break;
				}else
				{
					SET_COLOR(4);
					cout << " Du lieu khong hop le !!!" << endl;
					cout << " Hay nhap lai so tuong ung : ";
					SET_COLOR(10);
					getline(cin, fake_choose);
					cout << endl;
				}
			}
		}
		string ket_qua = kiem_tra(nguoi_chon, may_chon);
		SET_COLOR(14);
		cout << " Ban chon : " << type[nguoi_chon] << endl;
		cout << " May chon : " << type[may_chon] << endl;
		if(ket_qua == "draw"){
			cout << "----- > Ca hai hue nhau :)" << endl << endl;
			diem_nguoi++;
			diem_may++;
		}
		if(ket_qua == "may"){
			diem_may++;
			cout << "----- > May +1 point" << endl << endl;
		}
		if(ket_qua == "nguoi"){
			diem_nguoi++;
			cout << "----- > Nguoi +1 point" << endl << endl;
		}
	}
	
	SET_COLOR(12);
	cout << " Diem cua Ban la : " << diem_nguoi << endl;
	cout << " Diem cua May la : " << diem_may << endl;
	cout << endl;
	if(diem_nguoi == diem_may){
		cout << " ---- > Ca hai da hue nhau :)";
	}
	if(diem_nguoi > diem_may){
		cout << " ---- > Ban da chien thang :)";
	}
	if(diem_may > diem_nguoi){
		cout << " ---- > Nguoi may da chien thang :)";
	}
	SET_COLOR(7);
	return 0;
}
