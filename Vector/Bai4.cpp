#include<iostream>
using namespace std;

class vector{
	private:
		int n;
		float *v;
	public:
		vector();
		vector(const vector &a);
		~vector();
		void nhap();
		void xuat();
		int getn(){
			return n;
		}
		void setn(int _n){
			n = _n;
		}
		float getvalue(int i) const;
		void setvalue(int i, float val);
		vector operator=(vector b);
		friend vector operator+(vector b, vector c);
};

vector::vector(){}
vector::vector(const vector &a){
	this->n = a.n;
	this->v = new float[n];
	for(int i=0; i<n; i++){
		this->v[i] = a.v[i];
	}
}
vector::~vector(){
	delete[] v;
}
float vector::getvalue(int i) const {
	if(i>=0 && i<n){
		return v[i];
	}else{
		cout<<"Chi so khong hop le";
		return 0;
	}
}
void vector::setvalue(int i, float val){
	if(i>=0 && i<n){
		v[i] = val;
	}else{
		cout<<"Chi so khong hop le";
	}
}

void vector::nhap(){
	cout<<"Nhap so phan tu n: ";
	cin>>n;
	v = new float[n];
	for(int i=0; i<n; i++){
		cout<<"v["<<i<<"] = ";
		cin>>v[i];
	}
}
void vector::xuat(){
	cout<<"(";
	for(int i=0; i<n; i++){
		cout<<v[i];
		if(i<n-1) cout<<",";
	}
	cout<<")"<<endl;
}

vector vector::operator=(vector b){
	this->n = b.n;
	v = new float[n];
	for(int i=0; i<n; i++){
		v[i] = b.v[i];
	}
	return *this;
}

vector operator+(vector b, vector c){
	if(b.getn() != c.getn()) {
		cout<<"Hai vector khong bang nhau";
	}else{
		vector cong;
		cong.n = b.n;
		cong.v = new float[cong.n];
		for(int i=0; i<cong.getn(); i++){
			cong.v[i] = b.v[i] + c.v[i];
		}
		return cong;
	}
}

int main(){
	vector a, b, c;
	cout<<"Nhap vector a: ";
	a.nhap();
	cout<<"Nhap vector b:";
	b.nhap();
	
	cout<<"Xuat vector a: ";
	a.xuat();
	cout<<"Xuat vector b:";
	b.xuat();
	
	c = a+b;
	cout<<"Tong 2 vector: ";
	c.xuat();
	return 0;
}
