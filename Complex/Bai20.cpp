#include<iostream>
using namespace std;

class complex{
	private:
		int a,b;
	public:
		complex();
		void nhap();
		void xuat();
		complex(const complex &a);
		complex operator +(complex a);
		complex operator-(complex a);
};

complex::complex(){
}
void complex::nhap(){
	cout<<"Nhap so thuc: ";
	cin>>a;
	cout<<"Nhap phan ao: ";
	cin>>b;
}

void complex::xuat(){
	if(b>0){
		cout<<"So phuc: "<<a<<" + "<<b<<"i"<<endl;
	}else if(b<0){
		cout<<"So phuc: "<<a<<" "<<b<<"i"<<endl;
	}else{
		cout<<"So phuc: "<<a<<endl;
	}
}

complex complex::operator +(complex a){
	complex kq;
	kq.a = this->a + a.a;
	kq.b = this->b + a.b;
	return kq;
}

complex complex::operator-(complex a){
	complex kq;
	kq.a = this->a - a.a;
	kq.b = this->b - a.b;
	return kq;
}

complex::complex(const complex &a){
	this->a = a.a;
	this->b = a.b; 
}

int main(){
	complex c, d;
	cout<<"Nhap c "<<endl;
	c.nhap();
	cout<<"Nhap d "<<endl;
	d.nhap();
	
	cout<<"Xuat c "<<endl;
	c.xuat();
	cout<<"Xuat d "<<endl;
	d.xuat();
	
	complex e = c + d;
	cout<<"c + d = ";
	e.xuat();
	complex f = c - d;
	cout<<"c - d = ";
	f.xuat();
}
