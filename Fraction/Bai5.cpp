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
		PS operator+(PS a);
		PS operator-(PS a);
		PS operator*(PS a);
		PS operator/(PS a);
};

PS::PS(){
	tu =0;
	mau =1;
}

void PS::nhap(){
	cout<<"Nhap tu: ";
	cin>>tu;
	cout<<"Nhap mau: ";
	cin>>mau;
	if(mau==0){
		cout<<"mau ko duoc = 0";
		mau =1;
	}
}

void PS::xuat(){
	if(mau==1){
		cout<<"Phan so: "<<tu<<endl;
	}else if(mau==-1){
		cout<<"Phan so: "<<-tu<<endl;
	}else{
		cout<<"Phan so: "<<tu<<"/"<<mau<<endl;
	}
}

int UCLN(int a, int b){
	if(b==0) return a;
	return UCLN(b, a%b);
}

void PS::rutgon(){
	if(mau<0){
		tu = -tu;
		mau = -mau;
	}
	int u = UCLN(tu, mau);
	if(tu!=0){
		tu/=u;
		mau/=u;
	}
}

PS PS::operator+(PS a){
	PS kq;
	kq.tu = this->tu * a.mau + a.tu * this->mau;
	kq.mau = a.mau*this->mau;
	kq.rutgon();
	return kq;
}
PS PS::operator-(PS a){
	PS kq;
	kq.tu = this->tu * a.mau - a.tu * this->mau;
	kq.mau = a.mau*this->mau;
	kq.rutgon();
	return kq;
}
PS PS::operator*(PS a){
	PS kq;
	kq.tu = this->tu * a.tu;
	kq.mau = this->mau * a.mau;
	kq.rutgon();
	return kq;
}
PS PS::operator/(PS a){
	PS kq;
	kq.tu = this->tu * a.mau;
	kq.mau = this->mau * a.tu;
	if(mau==0){
		cout<<"Loi phan so co mau bang 0";
		kq.mau = 1;
		kq.tu=0;
	}
	kq.rutgon();
	return kq;
}

int main(){
	int n;
	cout<<"Nhap tong so phan so: ";
	cin>>n;
	PS a[n], tong;
	for(int i=0; i<n; i++){
		cout<<"Phan so ["<<i<<"] = ";
		a[i].nhap();
		cout<<endl;
	}
	tong = a[0];
	for(int i=1;i<n;i++){
		tong = tong + a[i];
	}
	cout<<"tong la: ";
	tong.xuat();
}
