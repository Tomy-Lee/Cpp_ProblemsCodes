#include<iostream> 
#include<iomanip>
#include<windows.h>
#include <conio.h> 
void back();//返回开始菜单
void out();//输出信息
int w=1; //用于记录学生人数,全局变量


class Data//日期类
{public:
    double Year,Month,Day;
    Data()
    {  Year=0;Month=0;Day=0;   }
};


class student //学生类
{
public: 
char name[10]; //姓名
char sex[5]; //性别
char jiguan[10]; //籍贯
int num,age;//学号,年龄
char adr[30];//住址
Data year;
friend class Data;//date作为student的友元                                 //定义一个日期类
void operator=(student s); //=重载
int operator == (student s);//==重载
}stu[100]; 

int main() 
{
system("cls");//清屏 DOC调用
system("color f4"); //颜色 同样是调用doc
int i;
void comp(); 
void input(); 
void find();
void alt() ;
void del(); 
void exit();
void show();




cout<<setw(53)<<"欢迎进入学生管理系统！"<<endl; 
cout<<setw(55)<<"1 添加学生信息 2 查询学生信息"<<endl<<endl; 
cout<<setw(55)<<"3 删除学生信息 4 修改学生信息"<<endl<<endl; 
cout<<setw(55)<<"5 比较学生信息 6 显示学生信息"<<endl<<endl;
cout<<setw(45)<<"0 推出系统"<<endl;

cout<<"请选择："; 
cin>>i;
if(i>6||i<0) 
{
    cout<<"输入有误！"<<endl;
    back();
} 
switch(i)
{ 
case 1:input();break; 
case 2:find();break; 
case 3:del();break; 
case 4:alt();break;
case 5:comp();break;
case 6:show();break;
case 0:exit();break;
default:cout<<"你的输入有误!\n";
return 0; 
}
} 



void input() //添加学生
{
system("color 84"); //颜色 同样是调用doc
system("cls");//清屏
int n; 
cout<<"请输入要添加的学生个数：\n"; 
cin>>n;
if(n>=100||n<=0) 
{cout<<"输入有误！<<endl";
main(); }

else
{ 
for(;n>0;w++,n--) 
    {
     cout<<"请输入姓名、性别、籍贯，年龄，学号，住址："<<endl; 
     cin>>stu[w].name>>stu[w].sex>>stu[w].jiguan>>stu[w].age >>stu[w].num>>stu[w].adr ; 
     cout<<"请输入该生生日（年 月 日）"<<endl;
     cin>>stu[w].year.Year;
     cin>>stu[w].year.Month;
     cin>>stu[w].year.Day;
    } 

   out();
}
  cout<<"添加完毕2秒后返回"<<endl;
  Sleep(2000); //延时2秒 
  main();
} 


void find() //按学号查找学生
{
system("color f4"); //颜色 同样是调用doc
system("cls");
int i,id,j=0;//j是用以记录是否有信息被找到 
cout<<"请输入你要查找学生的学号："; 
cin>>id;
for(i=1;i<w;i++)
if(stu[i].num ==id) 
{
    cout<<i<<"   "<<stu[i].name<<" "<<stu[i].sex<<" "<<stu[i].jiguan<<" "<<stu[i].age<<" "<<stu[i].num<<" "<<stu[i].year.Year<<" "<<stu[i].year.Month<<" "<<stu[i].year.Day<<stu[i].adr<<endl;
    j++;
}
if(j==0)
cout<<"没有你要查找的信息";
back();
} 


void del()//删除指定学号学生信息 
{
system("color f4"); //颜色 同样是调用doc
int i,a,y=0;
char x;
cout<<"请输入要删除的学生学号"; 
cin>>a;
for(i=1;i<w;i++)
  if(stu[i].num==a)
  {
     cout<<"该生情况："<<endl;
    cout<<i<<"   "<<stu[i].name<<"   "<<stu[i].sex<<"    "<<stu[i].jiguan<<"   "<<stu[i].age<<"   "<<stu[i].num<<"  "<<stu[i].year.Year<<" "<<stu[i].year.Month<<" "<<stu[i].year.Day<<"   "<<stu[i].adr<<endl;
    cout<<"是否确认删除？（Y/N）"<<endl;
    cin>>x;
    if(x=='Y'||x=='y')
    {
    y++;
    for(;i<w-1;i++) 
    stu[i]=stu[i+1];
    w--;//每删除一个对总是减少一个
    }
  }


if(y==0)
   {
    cout<<"该学生不存在！"<<endl;
    back();
   }
else
   {
    cout<<"删除后的信息为："<<endl;
    out();
    back();
   } 
}

void alt()//修改指定学号学生 
{
   system("color f4"); //颜色 同样是调用doc
   int id,y=0;
   char x;
   cout<<"请输入要修改学生的学号："; 
   cin>>id;
  for(int i=1;i<w;i++)
   if(stu[i].num ==id)
   {
    cout<<"该生情况："<<endl;
    cout<<i<<"   "<<stu[i].name<<"   "<<stu[i].sex<<"    "<<stu[i].jiguan<<"   "<<stu[i].age<<"   "<<stu[i].num<<"  "<<stu[i].year.Year<<" "<<stu[i].year.Month<<" "<<stu[i].year.Day<<"   "<<stu[i].adr<<endl;
    cout<<"是否确认修改？（Y/N）"<<endl;
    cin>>x;
if(x=='Y'||x=='y')
    {
     y++;
     cout<<"请输入姓名、性别、籍贯，年龄，学号，住址："<<endl; 
     cin>>stu[i].name>>stu[i].sex>>stu[i].jiguan>>stu[i].age >>stu[i].num>>stu[i].adr ; 
     cout<<"请输入该生生日（年 月 日）"<<endl;
     cin>>stu[i].year.Year;
     cin>>stu[i].year.Month;
     cin>>stu[i].year.Day;
    }
else
    {
    cout<<"2秒后返回"<<endl;
    Sleep(2000);  
    main();
    }
   }
if(y==0)
   {
     cout<<"                                该学生不存在！";
     back();
   }
else
   {
     cout<<"修改后的信息为："<<endl;
     out();
     back();
   }
} 


void student::operator =(student stu)//对=运算符重载函数的实现
{
    num=stu.num;
    for(int i=0;i<9;i++)
    name[i]=stu.name[i];
    for(i=0;i<4;i++)
    sex[i]=stu.sex[i];  
    age=stu.age;
    for(i=0;i<9;i++)
    jiguan[i]=stu.jiguan[i] ;
    for(i=0;i<29;i++)
    adr[i]=stu.adr[i] ;
    year.Year=stu.year.Year ;
    year.Month  =stu.year.Month  ;
    year.Day  =stu.year.Day ;
}

int student::operator == (student stu)//对==运算符重载函数的实现
{
    if(*name==*stu.name && *sex==*stu.sex &&  age==stu.age && *jiguan==*stu.jiguan && *adr==*stu.adr&&year.Year ==stu.year.Year&&year.Month ==stu.year.Month&&year.Day ==stu.year.Day )
        return 1;
    else
        return 0;
    
}
void comp()//学生信息对比
{
system("color f4"); //颜色 同样是调用doc
system("cls");
int i;
int num1,num2;
cout<<"请输入要比较的两个同学的学号"<<endl;
cin>>num1>>num2;
for(i=1;i<w;i++)
if(stu[i].num ==num1)
num1=i;
for(i=1;i<w;i++)
if(stu[i].num==num2)
num2=i;

    if(stu[num1]==stu[num2])
            cout<<"这两个学生是相同的"<<endl;
    else
cout<<"                                这两个学生不同"<<endl; 
back();
}


void show()//显示
{
out();
back();
}

void exit()//退出 
{
exit(0);
}

void back()//返回
{
cout<<"                                按任意键返回！"<<endl;
getch();
main();
}

void out()//输出
{
int i;
cout<<"    姓名   性别  籍贯  年龄  学号     生日     住址"<<endl;
for(i=1;i<w;i++)
cout<<i<<"   "<<stu[i].name<<"   "<<stu[i].sex<<"    "<<stu[i].jiguan<<"   "<<stu[i].age<<"   "<<stu[i].num<<"  "<<stu[i].year.Year<<" "<<stu[i].year.Month<<" "<<stu[i].year.Day<<"   "<<stu[i].adr<<endl;
} 
