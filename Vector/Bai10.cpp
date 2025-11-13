#include<iostream>
using namespace std;

class vector{
	private:
		int n;
		float *v;
	public:
		vector();
		vector(int _n);
		void nhap();
		void xuat();
		vector(const vector &a);
		~vector();
		vector &operator=(const vector &a);
		bool kiemtra(vector a);
		friend vector operator+(vector a, vector b);
};

vector::vector(){
	n =0;
	v = NULL;
}

vector::vector(int _n){
	this->n = _n;
	v = new float[n];
}

vector::vector(const vector &a){
	n = a.n;
	v = new float[n];
	for(int i=0; i<n; i++){
		this->v[i] = a.v[i];
	}
}

vector::~vector(){
	if(this!=NULL){
		delete[] v;
	}
}

void vector::nhap(){
	cout<<"Nhap n: ";
	cin>>n;
	v = new float[n];
	for(int i=0; i<n; i++){
		cout<<"Nhap v["<<i<<"] = ";
		cin>>v[i];
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
}

vector &vector::operator=(const vector &a){
	if(this != &a){
		this->n = a.n;
	    v = new float[n];
	    for(int i=0; i<n; i++){
		    this->v[i] = a.v[i];
	}
	}
	return *this;
}

bool vector::kiemtra(vector a){
	return this->n == a.n;
}

vector operator+(vector a, vector b){
	vector kq;
	if(a.n != b.n){
		cout<<"\nHai vector co kich thuoc khong bang nhau";
	}else{
		kq.n = a.n;
		kq.v = new float[kq.n];
		for(int i=0; i<kq.n; i++){
			kq.v[i] = a.v[i] + b.v[i];
		}
		return kq;
	}
}

int main(){
	vector a, b, c;
	cout<<"\nNhap vetcor a: ";
	a.nhap();
	cout<<"\nNhap vetcor b: ";
	b.nhap();
	
	cout<<"\nXuat hai vector a va b"<<endl;
	a.xuat();
	b.xuat();
	
	if(a.kiemtra(b)){
		cout<<"\nHai vector co cung kich thuoc"<<endl;
		c = a + b;
		cout<<"\nKet qua a + b = ";
		c.xuat();
		cout<<endl;
	}else{
		cout<<"Hai vector khong cung kich thuoc, khong cong duoc"<<endl;
	}
	
}
