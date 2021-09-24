#include <iostream>
#include <iomanip> 
using namespace std;

int main() {
	int T; cin >> T;
	cout << setiosflags(ios::uppercase);
	cout << setw(0xf) << internal;
	while(T--) {
		double A; cin >> A;
		double B; cin >> B;
		double C; cin >> C;

		/* Enter your code here */
        printf("%#llx\n",(long long)A);
        //////////////////////////
		long long x = B, k=0;
		while(x/=10)	k++;
		k=10-k;
		while(k-->0)	printf("_");
        printf("%+.2lf\n",B);
        //////////////////////////
        printf("%.9E\n",C);

	}
	return 0;

}