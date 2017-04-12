#include <iostream>
#include<string>  
using namespace std;  
  
int main() {   
    int n;
    cin >> n;
    while(n--) {
    	string s1,s2;  
        cin >> s1 >> s2;
        int i = 0, mark = 0;
        int length = s1.size();  
        while (i < length) {  
            if (s1[i] == s2[0]) {  
                for (int k = i,j = 0;j < s2.size();k++,j++) {  
                    if(s1[k%length] != s2[j]) {  
                        mark = 0;         //mark为0则说明不存在包含关系  
                        break;  
                    }  
                    mark = 1;   //循环进行到末尾，说明存在包含关系  
               }  
           }  
               i++;  
        }  
        if (mark == 0) {  
            cout << "False" << endl;    
        }  
        else {  
            cout << "True" << endl;   
        }  
    }
   return 0; 
}  
