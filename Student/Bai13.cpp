#include<iostream>
using namespace std;

class student{
	private:
		string hoten;
		float dtbk1, dtbk2, dtbcn;
	public:
		student();
		void nhap();
		void hienthi();
		void setDTBCN(float dtbk1, float dtbk2){
			float _dtbcn = (dtbk1 + 2*dtbk2)/3;
			dtbcn = _dtbcn;
		}
		float getDTBCN(){
			return dtbcn;
		}
		bool operator>(student a);
};

student::student(){
}
void student::nhap(){
	cout<<"Nhap ho va ten: ";
	cin.ignore();
	getline(cin, hoten);
	cout<<"Nhap diem trung binh ki 1: ";
	cin>>dtbk1;
	cout<<"Nhap diem trung binh ki 2: ";
	cin>>dtbk2;
	setDTBCN(dtbk1, dtbk2);
}

void student::hienthi(){
	cout<<"HoTen: "<<hoten<<" || " << "DTBK1: "<<dtbk1<<" || "<<"DTBK2: "<<dtbk2<<" || "<<"DTBCN: "<<dtbcn<<endl;
}

bool student::operator>(student a){
	return this->dtbcn > a.dtbcn;
}

int main(){
	int n;
	cout<<"Nhap so n: ";
	cin>>n;
	student b[n];
	for(int i=0; i<n; i++){
		cout<<"Nhap phan tu thu "<<i<<endl;
		b[i].nhap();
		cout<<endl;
	}
	for(int i=0; i<n-1; i++){
		for(int j=i+1; j<n; j++){
			if(!(b[i]>b[j])){
				student temp = b[i];
				b[i]=b[j];
				b[j]=temp;
			}
		}
	}
	cout<<"\nDanh sach sau khi sap xep giam dan theo diem trung binh nam "<<endl;
	for(int i=0; i<n; i++){
		b[i].hienthi();
		cout<<endl;
	}
}
