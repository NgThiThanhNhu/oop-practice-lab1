#include<iostream>
using namespace std;
class student{
	private:
		string hoten;
		float dk1, dk2, dtbcn;
	public:
		student();
		void nhap();
		void xuat();
		bool kiemtraDTBCN();
		float getDTBCN(){
			return dtbcn;
		}
		void setDTBCN(float dk1, float dk2){
			dtbcn = (dk1+2*dk2)/3;
		}
};

student::student(){
}
void student::nhap(){
	cout<<"HoTen: ";
	cin.ignore();
	getline(cin, hoten);
	cout<<"Diem ki 1: ";
	cin>>dk1;
	cout<<"Diem ki 2: ";
	cin>>dk2;
	setDTBCN(dk1, dk2);
}

void student::xuat(){
	cout<<"HoTen: "<<hoten<<" || "<<"Diem ki 1: "<<dk1<<" || "<<"Diem ki 2: "<<dk2<<" || "<<"Diem trung binh ca nam: "<<dtbcn<<endl;
}

bool student::kiemtraDTBCN(){
	this->dtbcn = (this->dk1 + 2*this->dk2)/3;
	if(this->dtbcn >= 5){
		return true;
	}else{
		return false;
	}
}

int main(){
	int n;
	cout<<"Nhap n: ";
	cin>>n;
	student a[n];
	for(int i=0; i<n; i++){
		cout<<"Phan tu thu "<<i;
		a[i].nhap();
		cout<<endl;
	}
	cout<<"\nDanh sach cac hoc sinh co diem trung binh ca nam >= 5"<<endl;
	for(int i=0; i<n; i++){
		if(a[i].getDTBCN() >= 5){
			cout<<"Phan tu thu "<<i;
			a[i].xuat();
			cout<<endl;
		}
	}
}
