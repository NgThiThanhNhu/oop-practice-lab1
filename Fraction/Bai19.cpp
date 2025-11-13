#include<iostream>
using namespace std;

class ps{
	private:
		int tu, mau;
	public:
		ps();
		void nhap();
		void xuat();
		bool operator>=(ps a);
};

ps::ps(){
}

void ps::nhap(){
	cout<<"\nNhap tu: ";
	cin>>tu;
	cout<<"\nNhap mau: ";
	cin>>mau;
	if(mau == 0){
		cout<<"Mau khong the bang 0";
		mau = 1;
	}
}

void ps::xuat(){
	if(mau == 1){
		cout<<"Phan so: "<<tu<<endl;
	}else if(mau==-1){
		cout<<"Phan so: "<<-tu<<endl;
	}else{
		cout<<"\nPhan so: "<<tu<<"/"<<mau<<endl;
	}
}

bool ps::operator>=(ps a){
	return (this->tu * a.mau) >= (a.tu * this->mau);
}

int main(){
	int n;
	cout<<"Nhap n: ";
	cin>>n;
	ps b[n];
	for(int i=0; i<n; i++){
		cout<<"Phan tu thu "<<i<<endl;
		b[i].nhap();
	}
	ps max = b[0];
	for(int i=1; i<n; i++){
		if(b[i]>=max){
			max = b[i];
		}
	}
	cout<<"Phan so lon nhat: ";
	max.xuat();
	cout<<endl;
}
