#include <cmath>
#include <iostream>
#include <iomanip> 
using namespace std;

int main() {
    float frac, whole;
	int T; cin >> T;
	cout << setiosflags(ios::uppercase);
	cout << setw(0xf) << internal;
	while(T--) {
		double A; cin >> A;
		double B; cin >> B;
		double C; cin >> C;

        cout << left << showbase << nouppercase << hex << (long long)A << endl;
        cout << setprecision(2) << setw(15) << right << showpos << fixed << setfill('_') << B << endl;
        cout << setprecision(9) << noshowpos << uppercase << scientific << C << endl;


	}
	return 0;

}