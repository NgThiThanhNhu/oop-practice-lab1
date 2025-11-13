#include<iostream>
using namespace std;

class mydate{
	private:
		int ngay, thang, nam;
	public:
		mydate();
		void nhap();
		void xuat();
		bool operator==(mydate a);
};

mydate::mydate(){
}
void mydate::nhap(){
	cout<<"Ngay: ";
	cin>>ngay;
	cout<<"Thang: ";
	cin>>thang;
	cout<<"Nam: ";
	cin>>nam;
}

void mydate::xuat(){
	cout<<"MyDate: "<<ngay<<" - "<<thang<<" - "<<nam<<endl;
}

bool mydate::operator==(mydate a){
	if(this->nam == a.nam) return true;
	if(!(this->nam == a.nam)) return false;
	if(this->thang == a.thang) return true;
	if(!(this->thang == a.thang)) return false;
	return this->ngay == a.ngay;
}

int main(){
	int n;
	cout<<"Nhap so n: ";
	cin>>n;
	mydate b[n], x;
	for(int i=0; i<n; i++){
		cout<<"Phan tu thu "<<i<<endl;
		b[i].nhap();
	}
	cout<<"Nhap doi tuong x"<<endl;
	x.nhap();
	for(int i=0; i<n; i++){
		if(b[i] == x){
			cout<<"Doi tuong x co trong mang"<<endl;
			break;
		}else{
			cout<<"Doi tuong x khong co trong mang"<<endl;
			break;
		}
	}
}
