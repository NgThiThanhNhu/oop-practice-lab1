#include<iostream>
using namespace std;
class complex{
	private:
		int a, b;
	public:
		complex();
		void nhap();
		void xuat();
		complex operator=(complex a);
		complex operator+(complex a);
};

complex::complex(){
}

void complex::nhap(){
	cout<<"Nhap phan thuc: ";
	cin>>a;
	cout<<"Nhap phan ao: ";
	cin>>b;
}

void complex::xuat(){
	if(b>0){
		cout<<"So phuc: "<<a<<" + "<<b<<"i"<<endl;
	}else if(b<0){
		cout<<"So phuc: "<<a<<"  "<<b<<"i"<<endl;
	}else{
		cout<<"So phuc: "<<a<<endl;
	}
}

complex complex::operator+(complex a){
	complex kq; 
	kq.a = this->a + a.a;
	kq.b = this->b + a.b;
	return kq;
}

complex complex::operator=(complex a){
	this->a = a.a;
	this->b = a.b;
	return *this;
}

int main(){
	int n;
	cout<<"Nhap n: ";
	cin>>n;
	complex b[n], tong;
	for(int i=0; i<n; i++){
		cout<<"Phan tu thu "<<i<<endl;
		b[i].nhap();
	}
	tong = b[0];
	for(int i=1; i<n; i++){
		tong = tong + b[i];
	}
	cout<<"\nTong mang so phuc: ";
	tong.xuat();
}
