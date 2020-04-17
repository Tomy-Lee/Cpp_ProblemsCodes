#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

//已知 2^0 ~ 2^64 具体值
string yz[] = { "1","2","4","8","16","32","64","128","256","512","1024",
"2048","4096","8192","16384","32768","65536","131072","262144","524288","1048576",
"2097152","4194304","8388608","16777216","33554432","67108864","134217728","268435456",
"536870912","1073741824","2147483648","4294967296","8589934592","17179869184","34359738368",
"68719476736","137438953472","274877906944","549755813888","1099511627776","2199023255552",
"4398046511104","8796093022208","17592186044416","35184372088832","70368744177664","140737488355328",
"281474976710656","562949953421312","1125899906842624","2251799813685248","4503599627370496",
"9007199254740992","18014398509481984","36028797018963968","72057594037927936","144115188075855872",
"288230376151711744","576460752303423488","1152921504606846976","2305843009213693952",
"4611686018427387904","9223372036854775808","18446744073709551616" };

string cheng(string a, char b) {//A *B, 用 B 的每一位 b 乘 A
	string theReturn = "";
	int na = a.length();
	
	int c = 0;// c 为满十进一中的进数
	for (int i = na - 1; i >= 0; i--) {
		theReturn += ((c + (a[i] - '0')*(b - '0')) % 10 + '0');
		c = (c + (a[i] - '0')*(b - '0')) / 10;
	}
	
	if (c)
		theReturn += (c + '0');
		
	reverse(theReturn.begin(), theReturn.end());
	return theReturn;
}

string *tem = new string[201]; int nb;// tem 用来存储 B 的每一位乘 A 的结果
string jia() {//将每一位乘 A 的结果进行加和操作
	int n = tem[0].length();
	
	for (int i = 1; i < nb; i++)//前位补零
		while (tem[i].length() != n)
			tem[i] = "0" + tem[i];
			
	int c = 0, sum;
	string theReturn = "";
	for (int i = n - 1; i >= 0; i--) {
		sum = 0;
		for (int j = 0; j < nb; j++)//小学乘法中的对应一列加和
			sum += (tem[j][i] - '0');
			
		theReturn += ((c + sum) % 10 + '0');
		c = (c + sum) / 10;
	}
	
	if (c) {//此时 c 可能为两位数
		string sc = to_string(c);
		reverse(sc.begin(), sc.end());
		theReturn += sc;
	}
	
	reverse(theReturn.begin(), theReturn.end());
	return theReturn;
}
int main(){
	int n; cin >> n;
	
	if (n <= 64) {//已知
		cout << yz[n] << endl;
		//system("pause");
		return 0;
	}
	
	string a, b; 
	a = yz[64]; b = yz[n - 64];
	int na = a.length(); nb = b.length();
	
	for (int i = nb - 1; i >= 0; i--)
		tem[i] = cheng(a, b[i]);
		
	for (int i = nb - 1; i >= 0; i--)//乘的结果后位补零，方便进行加和操作
		for (int j = 0; j < nb - 1 - i; j++)
			tem[i] += "0";
			
	string result = jia();
	cout << result << endl;
	//system("pause");
}
