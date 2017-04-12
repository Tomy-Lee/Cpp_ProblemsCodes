# include <iostream>
# include <string> 
using namespace std;

int main() {
	int s[13][100] = {0};
	int n;
	cin >> n;
	int count[13] = {0};
	while (n--) {
           int key;
           cin >> key;
           int rem = key % 13;
           s[rem][count[rem]++] = key;
	}
	int end;
	cin >> end;
	for(int i = 0; i<13; i++) {
		if(count[i] == 0)  cout << i<<"#NULL"<<endl;
		else {
			cout << i << "#";
			for(int j = 0; j < count[i] - 1; j++) {
                 cout << s[i][j] << " ";
			}
			cout << s[i][count[i]-1] << endl;
		}
	}
	return 0;
}
