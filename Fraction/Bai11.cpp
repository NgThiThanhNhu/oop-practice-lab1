#include<iostream>
using namespace std;

class PS{
	private:
		int tu, mau;
	public:
		PS();
		void nhap();
		void xuat();
		void rutgon();
		friend int UCLN(int a, int b);
};

PS::PS(){
	tu = 0;
	mau = 1;
}

void PS::nhap(){
	cout<<"Nhap tu: ";
	cin>>tu;
	cout<<"Nhap mau: ";
	cin>>mau;
	if(mau==0){
		cout<<"Mau khong duoc phep bang 0"<<endl;
		mau = 1;
	}
}

void PS::xuat(){
	if(mau == 1){
		cout<<"Phan so: "<<tu<<endl;
	}else if(mau == -1){
		cout<<"Phan so: "<<-tu<<endl;
	}else{
		cout<<"Phan so: "<<tu<<"/"<<mau<<endl;
	}
}

int UCLN(int a, int b){
	if(a<0) a = -a;
	if(b< 0) b= -b;
	while(b!=0){
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

void PS::rutgon(){
	int uc = UCLN(tu, mau);
	tu /= uc; 
	mau /= uc;
	if(mau < 0){
		tu = -tu;
		mau = -mau;	
	}
}

int main(){
	int n;
	cout<<"Nhap n: ";
	cin>>n;
	PS ps[n];
	cout<<"\nNhap Danh sach phan so"<<endl;
	for(int i=0; i<n; i++){
		cout<<"\nPhan so thu "<<i<<endl;
		ps[i].nhap();
	}
	cout<<"\nDanh sach phan so da rut gon"<<endl;
	for(int i=0; i<n; i++){
		cout<<"Phan so "<<i<<endl;
		ps[i].rutgon();
		ps[i].xuat();
		cout<<endl;
	}
}
