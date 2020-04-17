#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<cmath>
#include<deque>
#include<vector>
#include<queue>
#include<string>
#include<cstring>
#include<map>
#include<stack>
#include<set>
#include<stdio.h>
using namespace std;
void GetNext(char s2[], int next[])
{
    int len = strlen(s2);
    int i = 0, j = -1;
    next[0] = -1;
    while (i < len)
    {
        if (j == -1 || s2[i] == s2[j])
        {
            i++;
            j++;
            next[i] = j;
        }
        else
        {
            j = next[j];
        }
    }
}
int kmp(char s1[], char s2[], int next[])
{
    int lens1 = strlen(s1);
    int lens2 = strlen(s2);
    int i = 0, j = 0;
    while (i < lens1 && j < lens2)
    {
        if (j == -1 || s1[i] == s2[j])
        {
            i++;
            j++;
        }
        else
        {
            j = next[j];
        }
    }
    if (j == lens2)
    {
        return i - j + 1;
    }
    else
    {
        return -1;
    }
}
int main()
{
    int next[15] = {0};
    char s1[100], s2[100];
    cin >> s1 >> s2;
    GetNext(s2, next);
    cout << kmp(s1, s2, next);
    return 0;
}
