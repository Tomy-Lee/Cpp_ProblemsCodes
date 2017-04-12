/*检查输入字符串中的括号是否匹配。括号包括：{, }, (, ), [, ].
 

输入格式
第一行是一整数，即测试样例个数n.
以下n行，每一行是一个长度不超过100个字符的字符串。
 

输出格式
第一行是一整数，即测试样例个数n.
以下n行，每一行是一个长度不超过100的字符串。
 

样例输入
 将样例输入复制到剪贴板 
4
a
2-[(1+2)*2]
(a+b])
([a+b)]

样例输出
Yes
Yes
No
No
*/
#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isMatch(string input) {
    stack<char> contain;
    for (int i = 0; i < input.size(); ++i) {
        if (input[i] == '[' || input[i] == '{' || input[i] == '(') {
            contain.push(input[i]);
        }
        if (input[i] == ']') {
            if (!contain.empty() && contain.top() == '[') {
                contain.pop();
            } else {
                return false;                
            }
        }
        if (input[i] == '}') {
            if (!contain.empty() && contain.top() == '{') {
                contain.pop();
            } else {
                return false;                
            }
        }
        if (input[i] == ')') {
            if (!contain.empty() && contain.top() == '(') {
                contain.pop();
            } else {
                return false;                
            }
        }
    }
    return contain.size() == 0;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    while (n--) {
        string input;
        cin >> input;
        if (isMatch(input)) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    return 0;
}                                 


