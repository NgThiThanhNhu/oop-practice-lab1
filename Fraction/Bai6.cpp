#include<iostream>
using namespace std;

class PS{
	private:
		int tu, mau;
	public:
		PS();
		void nhap();
		void xuat();
		bool operator>(PS a);
};

PS::PS(){
}

void PS::nhap(){
	cout<<"Nhap tu: ";
	cin>>tu;
	cout<<"Nhap mau: ";
	cin>>mau;
	if(mau==0){
		cout<<"mau so khong duoc bang 0";
		mau == 1;
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

bool PS::operator>(PS a){
	return this->tu * a.mau > a.tu * this->mau;
}

int main(){
	int n;
	cout<<"Nhap n: ";
	cin>>n;
	PS b[n];
	for(int i=0; i<n; i++){
		cout<<"\nNhap phan so thu "<<i<<endl;
		b[i].nhap();
	}
	
	cout<<"\nDanh sach phan so duoc sap xep tang dan"<<endl;
	for(int i=0; i<n-1; i++){
		for(int j=i+1; j<n; j++){
			if(b[i]>b[j]){
				PS temp = b[i];
				b[i] = b[j];
				b[j] = temp;
			}
		}
	}
	for(int i=0; i<n; i++){
		cout<<"\nPhan so thu "<<i<<endl;
		b[i].xuat();
		cout<<endl;
	}
}
