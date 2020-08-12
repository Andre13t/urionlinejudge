#include <iostream>
#include <iomanip>
using namespace std;
 
int main() {
 
	long double raio, n = 3.14159;
	cin >> raio;
	cout << fixed << setprecision(4);
	cout << "A=" << n * (raio * raio) << endl;
	return 0;
}