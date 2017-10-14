/*题目大意：给一个非负正数N，计算N的每一位相加的和，然后输出和的每一位的英文读音～

分析：1.求出每一位相加的和sum 2.将sum的每一位提取出来输出对应的英文读音～ */ 
#include <iostream>
#include <vector>
using namespace std;
int main() {
    string s[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    string a;
    cin >> a;
    int sum = 0;
    for(int i = 0; i < a.length(); i++) {
        sum += (a[i] - '0');
    }
    vector<int> v;
    while(sum != 0) {
        v.push_back(sum % 10);
        sum = sum / 10;
    }
    int len = v.size();
    if(len == 0) { // if sum == 0 print zero else print s[v[len - 1]] 否则会段错误
        cout << s[0];
    } else {
        cout << s[v[len - 1]];
    }
    for(int i = len - 2; i >= 0; i--) {
        cout << " " << s[v[i]];
    }
    return 0;
}
