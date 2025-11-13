#include<iostream>
using namespace std;

class mydate{
	private:
		int ngay, thang, nam;
	public:
		mydate();
		void nhap();
		void xuat();
		bool operator>(mydate a);
};

mydate::mydate(){
}

bool kiemTraNamNhuan(int y){
	return (y % 400 == 0) || (y % 4 == 0 && y % 100 != 0);
}

int soNgayTrongThang(int m, int y){
	switch(m){
		case 1: case 3: case 5: case 7: case 8: case 10: case 12:
			return 31;
		case 4: case 6: case 9: case 11:
			return 30;
		case 2:
			return kiemTraNamNhuan(y) ? 29 : 28;
		default:
			return 0;
	}
	
}

void mydate::nhap(){
	bool hople = false;
	do{
		cout<<"Nhap ngay: ";
	    cin>>ngay;
		cout<<"Nhap thang: ";
		cin>>thang;
		cout<<"Nhap nam: ";
		cin>>nam;
		
		int maxNgay = soNgayTrongThang(thang, nam);
		
		if(nam<1){
			cout<<"Nam khong hop le!"<<endl;
		}else if(thang < 1 || thang >12){
			cout<<"Thang khong hop le!"<<endl;
		}else if(ngay < 1 || ngay > maxNgay){
			cout<<"Ngay khong hop le!"<<endl;
		}else{
			hople = true;
		}
		
		if(!hople){
			cout<<"Vui long nhap lai!"<<endl;
		}
	}while(!hople);
}

void mydate::xuat(){
	cout<<"\nMyDate: "<<ngay<<" - "<<thang<<" - "<<nam<<endl;
}

bool mydate::operator>(mydate a){
	if(this->nam > a.nam) return true;
	if(this->nam < a.nam) return false;
	if(this->thang > a.thang) return true;
	if(this->thang < a.thang) return false;
	return this->ngay > a.ngay;
}

int main(){
	int n;
	cout<<"Nhap n: ";
	cin>>n;
	mydate b[n];
	for(int i=0; i<n; i++){
		cout<<"\nNhap phan tu thu "<<i<<endl;
		b[i].nhap();
		cout<<endl;
	}
	cout<<"\nDanh sach ngay vua nhap"<<endl;
	for(int i=0; i<n; i++){
		cout<<"\nMyDate "<<i<<endl;
		b[i].xuat();
		cout<<endl;
	}
	
	for(int i=0; i<n-1; i++){
		for(int j=i+1; j<n; j++){
			if(b[i] > b[j]){
				mydate temp = b[i];
				b[i] = b[j];
				b[j] = temp;
			}
		}
	}
	cout<<"\nDanh sach sau khi sap xep ngay tang dan"<<endl;
	for(int i=0; i<n; i++){
		cout<<"MyDate "<<i<<endl;
		b[i].xuat();
		cout<<endl;
	}
}
