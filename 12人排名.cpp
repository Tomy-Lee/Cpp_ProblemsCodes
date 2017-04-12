#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

struct Paiming {
	string name;
	int score;
};

Paiming a[12];
int main() {
	int fenshu[12];
	for(int i = 0; i < 12; i++) {
		cin >> a[i].name;
		cin >> a[i].score;
		fenshu[i] = a[i].score;
	}
	sort(fenshu, fenshu+12);
	for(int i = 11; i >= 6; i--) {
		for(int j = 0; j < 12; j++) {
			if(a[j].score == fenshu[i]) cout<<a[j].name<<"£¬";
		}	
	}
	return 0;
}
