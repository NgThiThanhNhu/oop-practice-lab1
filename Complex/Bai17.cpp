#include<iostream>
using namespace std;

class complex{
	private:
		int a, b;
	public:
		complex();
		void nhap();
		void xuat();
		bool operator==(complex a);
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

bool complex::operator==(complex a){
	return (this->a == a.a)&& (this->b == a.b);
}

int main(){
	int n;
	cout<<"Nhap so n: ";
	cin>>n;
	complex b[n], x;
	for(int i=0; i<n; i++){
		cout<<"Phan tu thu "<<i<<endl;
		b[i].nhap();
	}
	cout<<"\nNhap so X de tim kiem trong mang"<<endl;
	x.nhap();
	for(int i=0; i<n; i++){
		if(b[i]==x){
			cout<<"X co trong mang";
			break;
		}
	}
}
