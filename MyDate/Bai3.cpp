#include<iostream>
using namespace std;

class MyDate{
	private:
		int ngay, thang, nam;
	public:
		MyDate();
		void nhap();
		void xuat();
		int getNgay(){
			return ngay;
		}
		int getThang(){
			return thang;
		}
		int getNam(){
			return nam;
		}
		friend bool operator>=(MyDate a, MyDate b);
};

MyDate::MyDate(){}
void MyDate::nhap(){
	cout<<"Nhap ngay: ";
	cin>>ngay;
	cout<<"Nhap thang(1-12): ";
	cin>>thang;
	cout<<"Nhap nam: ";
	cin>>nam;
	if(ngay < 0){
	cout<<"Ngay ko duoc nho hon 0";
	return;	
	}else if(ngay > 31){
		this->thang +1;
	}else if(ngay > 30){
		this->thang+1;
	}else if(thang > 12){
		this->nam+1;
	}else if(ngay > 29){
		this->thang+1;
	}else if(ngay > 28){
		this->thang+1;
	}else{
		return;
	}
}

void MyDate::xuat(){
	cout<<"MyDate: "<<ngay<<" - "<<thang<<" - "<<nam<<endl;
}

bool operator>=(MyDate a, MyDate b){
	if(a.getNam() > b.getNam()) return true;
	if(a.getThang() < b.getNam()) return false;
	if(a.getThang() > b.getThang()) return true;
	if(a.getThang()<b.getThang()) return false;
	return a.getNgay() >= b.getNgay();
 
}
int main(){
	int n;
	cout<<"Nhap so n: ";
	cin>>n;
	MyDate B[n];
	MyDate max;
	for(int i=0; i<n; i++){
		cout<<"Nhap MyDate["<<i<<"]: ";
		B[i].nhap();
	}
	max = B[0];
	for(int i=1; i<n; i++){
			if(B[i]>= max) {
				max = B[i];
			}	
	}
	cout<<"MyDate lon nhat: ";
	max.xuat();
	return 0;
}
