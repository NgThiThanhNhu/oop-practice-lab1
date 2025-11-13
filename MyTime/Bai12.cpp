#include<iostream>
using namespace std;

class MyTime{
	private:
		int gio, phut, giay;
	public:
		MyTime();
		void nhap();
		void xuat();
		friend bool operator>=(MyTime a, MyTime b);
};

MyTime::MyTime(){}
void MyTime::nhap(){
	cout<<"Nhap so gio: ";
	cin>>gio;
	cout<<"Nhap so phut: ";
	cin>>phut;
	cout<<"Nhap so giay: ";
	cin>>giay;
	if(gio<0 || phut<0 ||giay<0){
		cout<<"Gio, phut, giay khong duoc be hon 0";
		return;
	}
}

void MyTime::xuat(){
	cout<<"MyTime: "<<gio<<" : "<<phut<<" : "<<giay<<endl;
}

bool operator>=(MyTime a, MyTime b){
	if(a.gio>b.gio) return true;
	if(a.gio<b.gio) return false;
	if(a.phut > b.phut) return true;
	if(a.phut < b.phut) return false;
	return a.giay >= b.giay;
}

int main(){
	int n;
	cout<<"Nhap so n: ";
	cin>>n;
	MyTime A[n];
	cout<<"\nNhap mang du lieu"<<endl;
	for(int i=0; i<n; i++){
		cout<<"Nhap phan tu thu "<<i<<endl;
		A[i].nhap();
		cout<<endl;
	}
	MyTime min = A[0], max = A[0];
	for(int i=0; i<n; i++){
		if(A[i]>=max){
			max = A[i];
		}
		if(!(A[i]>=min)){
			min = A[i];
		}
	}
	cout<<"Phan tu lon nhat: ";
	max.xuat();
	cout<<endl;
	cout<<"Phan tu nho nhat: ";
	min.xuat();
	cout<<endl;
}

