#include<iostream>
#include<iomanip>  
#include<vector>  
#include<algorithm>  
#include<iterator>  
#include<utility>
using namespace std;  

typedef pair<int, int> P; 
 
struct node  {  
    int adress;  
    int data;  
    int next;  
    node(int a, int b, int c) :adress(a), data(b), next(c){};  
};  
vector<P> coll(100000); 
vector<node> vec;  

int main()  {  
    int adress, data, next, n, k, first;  
    while (cin>>first>>n>>k,!cin.eof())  {  
        int num = n;  
        while (n--)  {   
			cin >>adress>>data>>next; 
            P p;  
            p.first = data;  
            p.second = next;  
            coll[adress] = p;  
        }  
        int index = first;  
        int cnt(0);
        while (index != -1)  {  
            cnt++;  
            vec.push_back(node(index, coll[index].first, coll[index].second));  
            index = coll[index].second;  
        }  
        int t = cnt / k;  
        for (int i = 0; i < t; i++)  
            std::reverse(vec.begin() + i*k, vec.begin() + (i + 1)*k);  
        for (int i = 0; i < vec.size()-1;i++)  {  
			cout <<setfill('0')<< setw(5) <<  vec[i].adress<<" "<< vec[i].data <<" "<< setw(5) << vec[i + 1].adress << endl;
        }  
		cout << setfill('0')<<setw(5) <<  vec[vec.size() - 1].adress<<" "<< vec[vec.size() - 1].data<< " " << "-1" << endl;       
    }  
    return 0;  
}  
