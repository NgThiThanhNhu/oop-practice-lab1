#include<iostream>
using namespace std;

class PS{
	private:
		int tu, mau;
	public:
		PS();
		void nhap();
		void hienthi();
		bool operator ==(PS a);
};

PS::PS(){
}
void PS::nhap(){
	cout<<"Tu: ";
	cin>>tu;
	cout<<"Mau: ";
	cin>>mau;
	if(mau==0){
		cout<<"Mau so khong bang 0";
		mau = 1;
	}
}

void PS::hienthi(){
	if(mau==1){
		cout<<"Phan so: "<<tu<<endl;
	}else if(mau==-1){
		cout<<"Phan so: "<<-tu<<endl;
	}else{
		cout<<"Phan so: "<<tu<<"/"<<mau<<endl;
	}
}

bool PS::operator ==(PS a){
	return this->tu * a.mau == a.tu * this->mau;
}

int main(){
	int n;
	cout<<"Nhap n: ";
	cin>>n;
	PS b[n], x;
	for(int i=0; i<n; i++){
		cout<<"Nhap phan tu thu"<<i<<endl;
		b[i].nhap();
	}
	cout<<"\nNhap phan so muon tim"<<endl;
	x.nhap();
	for(int i=0; i<n; i++){
		if(b[i]==x){
			cout<<"Phan so X ton tai trong mang"<<endl;
			break;
		}
	}
}
