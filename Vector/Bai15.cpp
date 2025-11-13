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
		void hienthi();
		vector operator=(vector a);
		friend vector operator+(vector a, vector b);
};

vector::vector(){
}

vector::vector(const vector &a){
	this->n = a.n;
	this->v = new float[n];
	for(int i=0; i<a.n; i++){
		this->v[i] = a.v[i];
	}
}

vector::~vector(){
	delete[] v;
}

void vector::nhap(){
	cout<<"Nhap n: ";
	cin>>n;
	this->v = new float[n];
	for(int i=0; i<n; i++){
		cout<<"V["<<i<<"] =";
		cin>>v[i];
	}
}

void vector::hienthi(){
	cout<<"(";
	for(int i=0; i<n; i++){
		cout<<v[i];
		if(i<n-1){
			cout<<",";
		}
	}
	cout<<")"<<endl;
}

vector operator+(vector a, vector b){
	if(a.n != b.n) {
		cout<<"Hai vector kich thuoc khong bang nhau";
	}else{
	    vector kq;
		kq.n = a.n;
		kq.v = new float[kq.n];
		for(int i=0; i<kq.n; i++){
			kq.v[i] = a.v[i] + b.v[i];
		}
		return kq;
	}
	
}

int main(){
	vector c, d;
	cout<<"Nhap c: ";
	c.nhap();
	cout<<"Nhap d: ";
	d.nhap();
	vector e = c + d;
	cout<<"Cong hai vector c + d = ";
	e.hienthi();
	cout<<endl;
	
}
