#include<iostream>
using namespace std;

class PS{
	private:
		int tu, mau;
	public:
		PS();
		void nhap();
		void xuat();
		friend bool operator>=(PS a, PS b);
		void rutgon();
};

PS::PS(){
}

void PS::nhap(){
	cout<<"Nhap tu: ";
	cin>>tu;
	cout<<"Nhap mau: ";
	cin>>mau;
	if(mau==0){
		cout<<"Mau so khong duoc bang 0";
		mau=1;
	}
}

void PS::xuat(){
	if(mau==1){
		cout<<"\nPhan so: "<<tu<<endl;
	}else if(mau==-1){
		cout<<"\nPhan so: "<<-tu<<endl;
	}else{
		cout<<"\nPhan so: "<<tu<<"/"<<mau<<endl;
    }
}

bool operator>=(PS a, PS b){
	return a.tu * b.mau >= b.tu * a.mau;
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
	if(u!=0){
		tu /= u;
		mau /= u;
	}
}

int main(){
	int n;
	cout<<"Nhap n: ";
	cin>>n;
	PS b[n], min, max;
	for(int i=0; i<n; i++){
		cout<<"\nPhan so thu "<<i<<endl;
		b[i].nhap();
		b[i].rutgon();
	}
	min = b[0];
	max = b[0];
	for(int i=1; i<n; i++){
		if(b[i]>= max) max = b[i];
		if(!(b[i]>= min)) min = b[i];
	}
	cout<<"\nPhan so lon nhat = ";
	max.xuat();
	cout<<endl;
	cout<<"\nPhan so nho nhat = ";
	min.xuat();
	cout<<endl;
}
