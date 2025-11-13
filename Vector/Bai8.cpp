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
		vector &operator=(const vector &a);
		friend vector operator*(float k, vector a);
};

vector::vector(){
	n = 0;
	v = NULL;
}

vector::vector(const vector &a){
	this->n = a.n;
	this->v = new float[n];
	for(int i=0; i<n; i++){
		v[i]= a.v[i];
	}
}

vector::~vector(){
	if(v!=NULL){
		delete[] v;	
	}
}

void vector::nhap(){
	cout<<"\nNhap so phan tu n: ";
	cin>>n;
	v = new float[n];
	for(int i=0; i<n; i++){
		cout<<"v["<<i<<"] = ";
		cin>>v[i];
		cout<<endl;
	}
}

void vector::xuat(){
	cout<<"(";
	for(int i=0; i<n; i++){
		cout<<v[i];
		if(i<n-1){
			cout<<",";
		}
	}
	cout<<")";
	cout<<endl;
}

vector &vector::operator=(const vector &a){
	if(this != &a){
		delete[] v;
		n = a.n;
		v = new float[n];
		for(int i=0; i<n; i++){
			v[i]=a.v[i];
		}
	}
	return *this;
}

vector operator*(float k, vector a){
	vector kq;
	kq.n = a.n;
	kq.v = new float[kq.n];
	for(int i=0; i<kq.n; i++){
		kq.v[i] = k * a.v[i];
	}
	return kq;
}

int main(){
	vector a, kq;
	float k;
	cout<<"Nhap so k: ";
	cin>>k;
	cout<<endl;
	cout<<"Nhap vector a: ";
	a.nhap();
	a.xuat();
	cout<<endl;
	
	kq = k * a;
	cout<<"Phep nhan vector va k: ";
	kq.xuat();
	cout<<endl;
	
}
