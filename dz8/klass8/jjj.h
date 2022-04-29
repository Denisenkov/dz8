#ifndef JJJ_H
#define JJJ_H
#include <iostream>
#include <iomanip>
using namespace std;
class stud {
	char** x;
	int b[3];
	
public:
	stud() {
		x = new char* [3];
		b[0] = 0;
		b[1] = 0;
		b[2] = 0;
		for (int i = 0; i < 3; i++) {

			
			x[i] = new char[1];
			
			
		}
	};
	stud(int) {
		x = new char* [3];
		for (int i = 0; i < 3; i++) {

			b[i] = rand() % 6;
			x[i] = new char[b[i]];
			for (int j = 0; j < b[i]; j++) {
				x[i][j] = rand() % 25 + 65;
				cout << x[i][j];
			}
			cout << " ";
		}
	};
	stud(stud const &d) {
		x = new char* [3];
		
		for (int i = 0; i < 3; i++) {
			b[i] = d.b[i];
			x[i] = new char[b[i]];
			for (int j = 0; j < b[i]; j++) x[i][j] = d.x[i][j];
		}
		cout << "cop\n";
	};
	~stud() {
		for (int i = 0; i < 3; i++) {
			delete[] x[i];
		}
		cout << "destr\n";
	};
	stud operator=(stud d) {
		
		
		for (int i = 0; i < 3; i++) {
			b[i] = d.b[i];
			for (int j = 0; j < b[i]; j++) x[i][j] = d.x[i][j];
		}
		return *this;
	}
	friend std::istream& operator>>(std::istream& in, stud& a) {

		cout << "Vvedite FIO studenta\n";
		
		for (int i = 0; i < 3; i++) {
			string y;
			in >> y;
			a.b[i] = y.size();
			a.x[i] = new char[a.b[i]];
			for (int j = 0; j < a.b[i]; j++) a.x[i][j] = y[j];
		}
		return in;
	}
	friend std::ostream& operator<<(std::ostream& out, const stud& a) {
		cout <<"FIO : ";
		for (int i = 0; i < 3; i++) {
			
			for (int j = 0; j < a.b[i]; j++) cout<<a.x[i][j] ;
			cout << " ";
		}
		return out;
	}

};
class comp {
	double r;
	double m;
public:
	comp(double a, double b) :r(a), m(b) {
		cout << "constr\n";
	}
	comp() {
		r = 0;
		m = 0;
		cout << "constr\n";
	}
	comp(const comp& d) {
		r = d.r;
		m = d.m;
		cout << "copy\n";
	}
	~comp() {
		cout << "destr\n";
	}
	comp operator+(const comp  a) {
		return comp(r + a.r, m + a.m);
	}
	comp operator-(const comp  a) {
		return comp(r - a.r, m - a.m);
	}
	comp operator*(const comp  a) {
		return comp(r * a.r - m * a.m, r * a.m + m * a.r);
	}
	comp operator*(double a) {
		return comp(r * a, m * a);
	}
	comp operator/(double a) {
		return comp(r / a, m / a);
	}
	comp operator/(const comp a) {
		double d;
		d = a.r * a.r + a.m * a.m;
		return comp((r * a.r + m * a.m) / d, (-r * a.m + m * a.r) / d);
	}


	friend std::istream& operator>>(std::istream& in, comp& a) {

		cout << "vvedite real i im chasti chisla z\n";
		in >> a.r;
		in >> a.m;
		return in;
	}
	friend std::ostream& operator<<(std::ostream& out, const comp& a) {
		cout << a.r << setw(6);
		if (a.m >= 0) cout << "+" << a.m << "i\n";
		if (a.m < 0) cout << a.m << "i\n";
		return out;
	}
};

#endif
