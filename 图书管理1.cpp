#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <fstream>
using namespace std;
struct book {  string bookname; };
struct student { string studentname; };
static int bookamount = 0;
static int studentamount = 0;
string input;

struct book list[999];
struct student studentcar[999];
////////////////函数书写 
void checkout() {
	int flag = 1;
	cout << "请输入书本名称: ";
	cin >> input;
	for (int i = 1; i <= bookamount; i++)
		if (list[i].bookname == input) { 
		 cout << "找到该书。\n"; 
		 flag = 0;
		 }
	if (flag == 1) cout << "该书不存在。\n"; 
}  
void giveback() {
	int flag = 1;
	struct student temp;
cout << "请输入书本名称: ";
cin >> input;
bookamount++;
list[bookamount].bookname = input;
cout << "请输入还书人的姓名: ";
cin >> input;
for (int i = 1; i <= studentamount; i++) 
if (studentcar[i].studentname == input) {
	temp = studentcar[i];
	studentcar[i] = studentcar[studentamount];
	studentcar[studentamount] = temp;
	studentcar[studentamount].studentname = "";
	flag = 0;
	studentamount--;
}
if (flag == 0) cout << "您已归还该书。\n";
}
int borrow() {
	int flag = 1;
	struct book temp;
	if (bookamount == 0) { cout << "无书目可借！\n"; return 0;}
	cout << "请输入书本名称: ";
	cin >> input;
	for (int i = 1; i <= bookamount; i++)
     	if (list[i].bookname == input) {
			temp = list[i];
			list[i] = list[bookamount];
			list[bookamount] = temp;
			list[bookamount].bookname = "";
			flag = 0;
			studentamount++;
			cout << "请输入借书人的姓名: ";
			cin >> input;
			studentcar[studentamount].studentname = input;
		}
		if (flag == 0) cout << "借书成功。\n";
		else cout << "找不到该书。\n";
}
void add() {
		bookamount++;
	cout << "请输入书本名称: ";
	cin >> list[bookamount].bookname;
	cout << "增添书本成功。\n";
}
int cancel() { 
	struct book temp;
	int flag = 1;
	if (bookamount == 0) { cout << "无书目可删！\n"; return 0;}
	cout << "请输入书本名称: ";
	cin >> input;
	for (int i = 1; i <= bookamount; i++)
		if ( list[i].bookname == input) {
			temp = list[i];
			list[i] = list[bookamount];
			list[bookamount] = temp;
			list[bookamount].bookname = "";
			flag = 0;
		}
		if (flag == 0) cout << "该书已删除。\n";
		else cout << "找不到该书。\n";
	bookamount--;
	return 0;
}
////////////////函数书写 
int main() {
	cout << "欢迎使用图书管理系统.\n";
	int a = 0; 
while(1) {
	cout << "增添书本请按1，删除请按2，借阅请按3，归还请按4， 查找请按5， 退出请按6。" << endl;
	cin >> a;
	if (6 == a) break;
	if (5 == a) checkout();
	if (a == 4) giveback();
    if (a == 3) borrow();
    if (a == 2) cancel();
    if (a == 1) add();
}
cout << "感谢您的使用，再见！";
	return 0;
}
