#include<iostream>
#include<string>
using namespace std;

int main() {
	int n;
	cin >> n;
	while(n--) {
		int classamount, neiamount;
		cin >> classamount >> neiamount;
		int classnumber[100]={0};
		int classdistance[100]={0};
		int neinumber[1000]={0};
		for(int i=0; i < classamount; i++) {
			cin >> classnumber[i];
		}
		for(int j=0; j < neiamount; j++) {
			cin >> neinumber[j];
		}
		for(int k=0; k < classamount; k++) {
			for(int q = 0; q < neiamount; q++) {
				if(classnumber[k] == neinumber[q]) {
					classdistance[k]= 50*q;
					break;
				}
			}
			cout << classdistance[k]<<endl;
		}
	}
	return 0;
}
