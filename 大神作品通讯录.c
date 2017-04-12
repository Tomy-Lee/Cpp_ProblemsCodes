
#include<fstream>
#include<string>
#include<cstring>
#include<conio.h>
#include<iostream>
#include<Windows.h>
//#include<windows.h>
using namespace std;
string ID;//具有唯一性
class Person
{
protected:
    string No; //学号
    string Age;//年龄
    string QQ;//QQ号码
    char Name[20]; //姓名
    char Sex[10];  //性别
    string Tel; //电话号码
    char domitory[25];//宿舍
    char canteen[25];//最喜欢的食堂
    char sports[100];//最喜欢的运动
    char subject[50];//最喜欢的科目
    Person *next;
public:
    Person(string ID,char *Name,char*Sex,string Age,string Tel,char*domitory,string QQ,char*canteen,char*sports,char*subject)
    {
        strcpy(this->Name,Name);
        strcpy(this->Sex,Sex);
        this->QQ=QQ;
        strcpy(this->domitory,domitory);
        strcpy(this->canteen,canteen);
        strcpy(this->sports,sports);
        strcpy(this->subject,subject);
        this->Tel=Tel;
        this->No=ID;
        this->Age=Age;
    }
    friend class Manage;
};
class Manage
{
private:
    Person *person;
public:
    Manage()
    {
        person=0;
        Load();
    }
    ~Manage()
    {
        Person *p;
        p=person;
        while(p)
        {
            p=p->next;
            delete person;
            person=p;
        }
        person=0;
    }
    void Find(char Name[20]);//按姓名查找
    void Find(string ID);//按编号查找
    void Add(); //添加加信息
    void Delete(); //删除信息
    void Modify(string ID); //修改信息
    void Query(); //查询信息
    void TJ(); //清除文件信息
    void Save(); //保存数据
    void Load(); //读入数据
    void Look();//预览
    void DesTory();
    void Output(Person *p)
    {
        cout<<"\t\t【    学号    】："<<p->No<<endl;
        cout<<"\t\t【    姓名    】："<<p->Name<<endl;
        cout<<"\t\t【    性别    】："<<p->Sex<<endl;
        cout<<"\t\t【    年龄    】："<<p->Age<<endl;
        cout<<"\t\t【  联系电话  】："<<p->Tel<<endl;
        cout<<"\t\t【   QQ号码   】："<<p->QQ<<endl;
        cout<<"\t\t【  宿舍地址  】："<<p->domitory<<endl;
        cout<<"\t\t【最喜欢的饭堂】："<<p->canteen<<endl;
        cout<<"\t\t【最喜欢的科目】："<<p->subject<<endl;
        cout<<"\t\t【最喜欢的运动】："<<p->sports<<endl;
        cout<<endl;
    }
};
void Manage::Add()
{
    system("cls");
    Person *p,*p2; //新结点指针
    string No,Age,Tel,QQ;
    char Name[20],Sex[10],domitory[25],canteen[25],sports[100],subject[50];
    char c;
    cout<<"\n\t   ◆ 新增学生通讯录 ◆\n";
    cout<<"================================================"<<endl;
    //输入学生信息
    cout<<"输入学号:        \t";
    cin>>No;
    cout<<endl;
    {
        Person *p1;
        p1=person;
        while(p1)
        {
            if(p1->No==No)
            {
                break;
            }
            else
            {
                p1=p1->next;
            }
        }
        if(p1!=NULL)
        {
            cout<<"该学号已存在,是否修改该学生信息(Y/N) "<<endl;
            cin>>c;
            if(toupper(c)=='Y')
            {
                cout<<"该学生信息为:"<<endl;
                Find(No);
                cout<<endl;
                Modify(No);
                return ;
            }
            else
                return ;
        }
    }
    cout<<"输入姓名:        \t";
    cin>>Name;
    cout<<endl;
    cout<<"输入性别:        \t";
    cin>>Sex;
    cout<<endl;
    cout<<"输入年龄:        \t";
    cin>>Age;
    cout<<endl;
    cout<<"输入QQ号码:      \t";
    cin>>Tel;
    cout<<endl;
    cout<<"输入宿舍地址:    \t";
    cin>>domitory;
    cout<<endl;
    cout<<"输入最喜欢的饭堂:\t";
    cin>>canteen;
    cout<<endl;
    cout<<"输入最喜欢的科目:\t";
    cin>>subject;
    cout<<endl;
    cout<<"输入最喜欢的体育运动:\t";
    cin>>sports;
    cout<<endl;
    p=new Person(No,Name,Sex,Age,Tel,domitory,QQ,canteen,sports,subject);
    p->next=0;
    //学生结点加入链表
    if(person) //若已经存在结点
    {
        p2=person;
        while(p2->next) //查找尾结点
        {
            p2=p2->next;
        }
        p2->next=p; //连接
    }
    else //若不存在结点(表空)
    {
        person=p; //连接
    }
    system("cls");
    cout<<"\t\t\t【联系人已成功添加】\n"<<endl;
    cout<<"\t\t是否继续添加联系人？(Y/N)  "<<endl;
    cin>>c;
    if(toupper(c)=='Y')
            {
                Add();
                return ;
            }
    else
        return ;
}
void Manage::Delete() //删除人员
{
    system("cls");
    char c;
    string No;
    cout<<"\n\t◆ 删除信息 ◆\n";
    cout<<"===================================================";
    cout<<"输入要删除的学生ID:\t";
    cin>>No;
    cout<<endl;
    //查找要删除的结点
    Person *p1,*p2;
    p1=person;
    while(p1)
    {
        if(p1->No==No)
            break;
        else
        {
            p2=p1;
            p1=p1->next;
        }
    }
    //删除结点
    if(p1!=NULL)//若找到结点，则删除
    {
        cout<<"所要删除的学生的信息如下:\n"<<endl;
        Output(p1);
        cout<<"确定是否删除(Y/N): ";
        cin>>c;
        if(toupper(c)!='Y')
            return;
    //  system("pause");
        if(p1==person) //若要删除的结点是第一个结点
        {
            person=p1->next;
            delete p1;
        }
        else //若要删除的结点是后续结点
        {
            p2->next=p1->next;
            delete p1;
        }
        cout<<"\t\t【联系人已成功删除】\n";
        cout<<"是否继续删除(Y/N)  "<<endl;
        cin>>c;
        if(toupper(c)=='Y')
            {
                Delete();
                return ;
            }
        else
            return ;
    }
    else //未找到结点
        cout<<"\n\t\tOops！系统未能找到该同学\n";
    getch();//等待按下任意键继续
}
void Manage::Modify(string ID)
{
    Person *p1;
    char c;
    p1=person;
    while(p1)
    {
        if(p1->No==ID)
            break;
        else
        {
            p1=p1->next;
        }
    }
    if(p1!=NULL)//若找到结点
    {
        system("cls");
        cout<<"所要修改的学生的信息如下:\n"<<endl;
        Output(p1);
        do
        {
            cout<<"1.修改姓名       2.修改性别       3 修改年龄\n"<<endl;
            cout<<"4.修改电话号码   5.修改宿舍地址   6.修改QQ号码\n"<<endl;
            cout<<"7.修改最喜欢饭堂 8.修改最喜欢运动 9.修改最喜欢科目\n"<<endl;
            cout<<"0.退出修改\n"<<endl;
            cout<<"请选择(0-9)要修改的信息:\n"<<endl;
            cin>>c;
            if(c!='0')
            cout<<"请输入新的信息:  ";
            switch(c)
            {
            case '1': cin>>p1->Name; break;
            case '2': cin>>p1->Sex; break;
            case '3': cin>>p1->Age; break;
            case '4': cin>>p1->Tel; break;
            case '5': cin>>p1->domitory; break;
            case '6': cin>>p1->QQ; break;
            case '7': cin>>p1->canteen; break;
            case '8': cin>>p1->sports; break;
            case '9': cin>>p1->subject; break;
            default: break;
            }
        }while(c!='0');
            system("cls");
            cout<<"\t  【联系人已成功修改】\n"<<endl;
    cout<<"是否继续修改(Y/N):  "<<endl;
    cin>>c;
    if(toupper(c)=='Y')
    {
        cout<<"请输入要修改人员的ID:  ";
        cin>>ID;
        cout<<endl;
        Modify(ID);
        return ;
    }
    else
        return ;
    }
    else //未找到结点
        cout<<"未找到该学生!\n";
    getch();//暂停(会等待你按下任意键，再继续执行下面的语句；)
}
void Manage::Save() //数据写入到文件
{
    ofstream fPerson("Person.txt",ios::out);
    char c;
    cout<<"\n【将要保存数据,是否继续?】[Y/N]:";
    cin>>c;
    if(toupper(c)!='Y')
        return;
    Person *p=person;
    while(p)
    {
        fPerson<<p->No<<" "<<p->Name<<" "<<p->Sex<<" "<<p->Age<<" "<<p->Tel<<" "<<p->domitory<<" "<<p->QQ<<" "<<p->canteen<<" "<<p->sports<<" "<<p->subject<<endl;
        p=p->next;
    }
    fPerson.close();
    cout<<"\n【已成功保存数据】\n";
    system("pause");
}
void Manage::Load() //数据读入
{
    ifstream fPerson;
    Person *p=person;
    string No,Age,Tel,QQ;
    char Name[20],Sex[10],domitory[25],canteen[25],sports[100],subject[50];
    fPerson.open("person.txt",ios::in);
    fPerson>>No>>Name>>Sex>>Age>>Tel>>domitory>>QQ>>canteen>>sports>>subject;

    while(fPerson.good())//文件打开成功时
    {
        p=new Person(No,Name,Sex,Age,Tel,domitory,QQ,canteen,sports,subject);
        p->next=0;
        //结点加入链表
        if(person) //若已经存在结点
        {
            Person *p2;
            p2=person;
            while(p2->next) //查找尾结点
            {
                p2=p2->next;
            }
            p2->next=p; //连接
        }
        else //若不存在结点(表空)
        {
            person=p; //连接
        }
        fPerson>>No>>Name>>Sex>>Age>>Tel>>domitory>>QQ>>canteen>>sports>>subject;
    }
    fPerson.close();
}
void Manage::Find(string ID)
{
    Person *p1;
    p1=person;
    while(p1)
    {
        if(p1->No==ID)
            break;
        else
        {
            p1=p1->next;
        }
    }
    if(p1!=NULL)
    {
        Output(p1);
    }
    else
        cout<<"\n\t\tOops！系统未能找到该同学\n"<<endl;
}

void Manage::Find(char Name[20])
{
    Person *p1;
    int count=0;
    p1=person;
    while(p1)
    {
        if(strcmp(p1->Name,Name)==0)
        {
            count++;
            Output(p1);
        }
            p1=p1->next;
    }
    if(count)
    {
        cout<<"\t●查询结果如下：●"<<endl;
        cout<<"\n系统共为您找到了 "<<count<<" 个名字为 ★"<<Name<<"★ 的同学\n"<<endl;
    }
    else
        cout<<"\n\t\tOops！系统未能找到该同学\n"<<endl;
}
void Manage::Query()
{
    char c;
    string ID,Tel,QQ;
    char Name[20];
    do{
        cout<<"1.按学号查找 2.按名字查找 3.按电话号码查找 4.按QQ查找 5.退出查找"<<endl;
        cin>>c;
    //  system("cls");
        cout<<endl;
        switch(c)
        {
        case '1': {
            cout<<"输入学号 ID:  ";
            cin>>ID;
            Find(ID);
                  }; break;
        case '2': {
            cout<<"输入姓名 Name:  ";
            cin>>Name;
            Find(Name);
                  }; break;
        case '3': {
            cout<<"输入电话号码 Tel:"<<endl;
            cin>>Tel;
            Find(Tel);
            };break;
        case '4': {
            cout<<"输入QQ号码 QQ:"<<endl;
            cin>>QQ;
            Find(QQ);
            };break;
        case '5':break;
        default:  cout<<"Oops! 输入有误 请重新输入...\n"<<endl;
        }
    }while(c!='1'&&c!='2'&&c!='3'&&c!='4'&&c!='5');
    cout<<"\t\t\t   【查找成功】\n"<<endl;
    cout<<"是否继续查找？(Y/N)  "<<endl;
    cin>>c;
    if(toupper(c)=='Y')
            {
                Query();
                return ;
            }
    else
        return ;
        system("pause");
}
void Manage::Look()
{
        //设置字体颜色
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY |
            FOREGROUND_RED | FOREGROUND_BLUE);
    system("cls");
    Person *p1;
    int count=0;
    char c;
    p1=person;
    while(p1)
    {
        cout<<"学号: "<<p1->No<<"\t姓名: "<<p1->Name<<endl;
        count++;
            p1=p1->next;
    }
    if(count!=0)
    {
        cout<<"\n\t【预览信息加载成功！】 \n"<<endl;
        cout<<"是否查询详细信息？(Y/N): ";
        cin>>c;
            if(toupper(c)=='Y')
            {
                Query();
                return;
            }
            else
                return ;
    }
    else
    {
        cout<<"Oops! 尚未创建通讯录，是否现在创建？(Y/N)"<<endl;
        cin>>c;
            if(toupper(c)=='Y')
            {
                Add();
                return;
            }
            else
                return ;
    }
}
void Manage::DesTory()
{   //设置字体为红色
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY |
            FOREGROUND_RED);
    char c;
    system("cls");
    cout<<"\n\t\t\t ◆清除信息◆ \n"<<endl;
    cout<<"=============================================================="<<endl;
    cout<<"\t\t\t   ※警告※\n\n\t清除通讯录信息会导致所有已保存的信息完全丢失!!!\n"<<endl;
    cout<<"★是否决定清除所有通讯录信息？★(Y/N):  "<<endl;
    cin>>c;
            if(toupper(c)!='Y')
                return;
    cout<<"★您确认要清楚所有通讯录信息吗？★(Y/N)"<<endl;
    cin>>c;
    if(toupper(c)!='Y')
                return;
    else
    {
        Person *p;
        p=person;
        while(p)
        {
            p=p->next;
            delete person;
            person=p;
        }
        person=0;
    //  ofstream fPerson("person.txt");
    //  fPerson.close();
    }
    system("pause");
}
void Manage::TJ()
{
    Person *p1;
    int count=0,Boy=0,Girl=0;
    p1=person;
    while(p1)
    {
        count++;
        if(strcmp(p1->Sex,"男")==0)
        Boy++;
        if(strcmp(p1->Sex,"女")==0)
            Girl++;
        p1=p1->next;
    }
    cout<<"通讯录内共有 "<<count<<"人\n"<<endl;
    cout<<"男生:  "<<Boy<<"人"<<endl<<"女生:  "<<Girl<<"人"<<"\n"<<endl;
    system("pause");
}
int main(void)
{
    Manage m;
    int c;
    do
    {
          //设置字体为绿色
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY |
            FOREGROUND_GREEN);
        system("cls");
        cout<<"                              ★  通讯录系统  ★                                "<<endl;
        cout<<"============================================================================="<<endl;
        cout<<"  (￣3￣)│ 【  1.新增通讯录   】│   ◢◣       ◢◣。      ◢◣    ☆圣★"<<endl;
        cout<<"         │                      │  ◢★◣     ◢★◣。    ◢★◣   ★诞☆"<<endl;
        cout<<"  (╯_╰)│ 【  2.删除名单     】│ ◢■■◣   ◢■■◣。  ◢■■◣  ☆节★"<<endl;
        cout<<"         │                      │◢■■■◣ ◢■■■◣。◢■■■◣ ★快☆"<<endl;
        cout<<"  (⊙_⊙)│ 【  3.修改名单     】│︸︸||︸︸ ︸︸||︸︸  ︸︸||︸︸ ☆乐★"<<endl;
        cout<<"         │                      │"<<endl;
        cout<<"  ( -﹏-)│ 【  4.查询详细信息 】││＼＿＿╭╭╭╭╭＿＿／│"<<endl;
        cout<<"         │                      ││　　　　　　　　　　　│ "<<endl;
        cout<<"  (∩_∩)│ 【  5.保存数据     】││　　　　　　　　　　　│  ╭─────╮"<<endl;
        cout<<"         │                      ││　　　　　　　　　　　│ │ 欢迎使用通 │"<<endl;
        cout<<"  (≧o≦)│ 【  6.预览信息     】││　≧　　　　　　　≦　│＜  讯录,请按数│"<<endl;
        cout<<"         │                      ││　≡　╰┬┬┬╯　≡　│ │ 字提示操作!│"<<endl;
        cout<<"  (〒_〒)│ 【  7.清空名单     】││　　　　╰─╯　　　　│ ╰──────╯"<<endl;
        cout<<"         │                      │╰──┬Ｏ───Ｏ┬──╯"<<endl;
        cout<<"  (→_→)│ 【  8.人数统计     】│      │    ╬    │"<<endl;
        cout<<"         │                      │      ╰┬───┬╯  ──Made by George.S"<<endl;
        cout<<"  (ㄒoㄒ)│ 【  0.退出系统     】│                           SYSU-CS-Class2"<<endl;
        cout<<"============================================================================="<<endl;
        cout<<"请输入相应数字选择(1-8): ";
        cin>>c;
        switch(c)
        {
        case 1: m.Add(); break;
        case 2: m.Delete();break;
        case 3: {
            system("cls");
            cout<<"请输入要修改人员的ID:  ";
            cin>>ID;
            cout<<endl;
            m.Modify(ID);
                  };break;
        case 4: {
            system("cls");
            m.Query();
                  }; break;
        case 5: m.Save(); break;
        case 6: m.Look(); break;
        case 7: m.DesTory(); break;
        case 8: m.TJ(); break;
        default: break;
        }
    }while(c!=0);
    char s;
    cout<<"\n【是否要保存您的所有操作？】(Y/N):  "<<endl;
    cin>>s;
    if(toupper(s)=='Y')
        m.Save();
    return 0;
}
