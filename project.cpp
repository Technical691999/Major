#include<fstream>
#include<iostream>
#include<string.h>
#include<windows.h>
#include<conio.h>
using namespace std;
class employee
{

public:
    int empid;
    char name[50];
    char lastname[20];
    char post[20];
    float salary;
    void accept()
    {

        cout<<endl<<"enter employee id  ";
        cin>>  empid;
        cout<<endl<<"enter name  ";
        cin>>name;
        cout<<endl<<"enter lastname  ";
        cin>>  lastname;
        cout<<endl<<"enter post";
        cin>>  post;
        cout<<endl<<"enter salary  ";
        cin>>  salary;
    }
    void display()
    {

        cout<<endl<<"empid  "<<empid;
        cout<<endl<<"name  "<<name;
        cout<<endl<<"lastname  "<<lastname;
        cout<<endl<<"post  "<<post;
        cout<<endl<<"salary  "<<salary;
    }
    };
    employee obj;     //global object

    class salary
    {
    public:
        char month[50];
        char year[4];
        int x,f=0;
        float salary;
        void accept()
        {

            cout<<"enter empid to dispense salary";
            cin>>x;
            fstream rd;
            rd.open("d:\\salaryproject\\employeedata.txt",ios::in);
            rd.seekg(0,ios::end);
            int n=rd.tellg();
            n=n/sizeof(obj);
            rd.seekg(0,ios::beg);
            for(int i=1;i<=n;i++)
            {

                rd.read((char*)&obj,sizeof(obj));
                if(x==obj.empid)
                {
                    f=1;
                    break;
                }
            }

                if (f==1)
                {
            obj.display();
            cout<<'\n';
            cout<<endl<<"salary given to employee  ";
            cin>>salary;
            cout<<endl<<"Month-";
            cin>>month;
            cout<<endl<<"year-";
            cin>>year;
                }
                else
                {
                    cout<<'\n';
                    cout<<endl<<"out of data";
                }

        }
        void display()
        {
            cout<<endl<<"Employee id is "<<x;
            cout<<endl<<"Salary given is "<<salary;
            cout<<endl<<"Month is "<<month;
            cout<<endl<<"Year is "<<year;

        }};
    salary a;    //global object

    void addemployee()
    {
        obj.accept();
        fstream wr;
        wr.open("d:\\salaryproject\\employeedata.txt",ios::app);
        wr.write((char*)&obj,sizeof(obj));
        cout<<endl<<"data is written to file";
    }
    void showallemployee()
    {

        fstream rd;
        rd.open("d:\\salaryproject\\employeedata.txt",ios::in);
        rd.seekg(0,ios::end);
        int n=rd.tellg();
        n=n/sizeof(obj);
        rd.seekg(0,ios::beg);
        for(int i=1;i<=n;i++)
        {

            rd.read((char*)&obj,sizeof(obj));
            obj.display();
            cout<<'\n';
            cout<<"----------------------------";
        }
    }


    void searchbyempid()
    {
        int sr;
        cout<<"enter id to be searched";
        cin>>sr;
        fstream rd;
        rd.open("d:\\salaryproject\\employeedata.txt",ios::in);
        rd.seekg(0,ios::end);
        int n=rd.tellg();
        n=n/sizeof(obj);
        rd.seekg(0,ios::beg);
        for( int i=1;i<=n;i++)
        {

            rd.read((char*)&obj,sizeof(obj));
            if(obj.empid==sr)
            {

                obj.display();

                cout<<endl<<"--------------------------";
            }
        }
    }
    void searchbyname()
    {
        fstream rd;
        int x,f=0;
        char a[50];
        cout<<"enter name to be searched";
        cin>>a;
        rd.open("d:\\salaryproject\\employeedata.txt",ios::in);
        rd.seekg(0,ios::end);
        int n=rd.tellg();
        n=n/sizeof(obj);
        rd.seekg(0,ios::beg);
        for (int i=1;i<=n;i++)
        {

            rd.read((char*)&obj,sizeof(obj));
            x=stricmp(a,obj.name);
            if(x==0)
               {
                   obj.display();
                   cout<<endl<<"-------------------------------------------------";
               }
                       }



    }
    void searchbypost()
    {

        fstream rd;
        char a[50];
        int x;
        cout<<"Enter post to be searched";
        cin>>a;
        rd.open("d:\\salaryproject\\employeedata.txt",ios::in);
        rd.seekg(0,ios::end);
       int n=rd.tellg();
        n=n/sizeof(obj);
        rd.seekg(0,ios::beg);
        for (int i=1;i<=n;i++)
        {
            rd.read((char*)&obj,sizeof(obj));
            x=stricmp(a,obj.post);
            if(x==0)
            {
                obj.display();
            }
        }
    }
    void removeemployee()
    {
        fstream rd,wr;
        rd.open("d:\\salaryproject\\employeedata.txt",ios::in);
        wr.open("d:\\salaryproject\\temp.txt",ios::out);
        int x;
        cout<<"enter employee id to be removed";
        cin>>x;
        rd.seekg(0,ios::end);
        int n=rd.tellg();
        n=n/sizeof(obj);
        rd.seekg(0,ios::beg);
        for  (int i=1;i<=n;i++)
        {

            rd.read((char*)&obj,sizeof(obj));
            if(obj.empid==x)
            {

                cout<<endl<<"employee is removed";
            }
            else
            {
                wr.write((char*)&obj,sizeof(obj));
            }
        }
            rd.close();
            wr.close();
            remove("d:\\salaryproject\\employeedata.txt");
            rename("d:\\salaryproject\\temp.txt","d:\\salaryproject\\employeedata.txt");
    }
    void updateemployee()
    {
        fstream rd,wr;
        rd.open("d:\\salaryproject\\employeedata.txt",ios::in);
        wr.open("d:\\salaryproject\\temp.txt",ios::out);
        int x;
        cout<<"enter employee id to be update  ";
        cin>>x;
        rd.seekg(0,ios::end);
        int n=rd.tellg();
        n=n/sizeof(obj);
        rd.seekg(0,ios::beg);
        for  (int i=1;i<=n;i++)
        {

            rd.read((char*)&obj,sizeof(obj));
            if(x==obj.empid)
            {
                obj.display();
                cout<<'\n';
                cout<<endl<<"Enter New Data";
                cout<<'\n';
                obj.accept();
                wr.write((char*)&obj,sizeof(obj));

            }
            else
            {
                wr.write((char*)&obj,sizeof(obj));
            }
        }
            rd.close();
            wr.close();
            remove("d:\\salaryproject\\employeedata.txt");
            rename("d:\\salaryproject\\temp.txt","d:\\salaryproject\\employeedata.txt");
            cout<<endl<<"Employee updated";
    }
    void salarydispensed()
    {

        a.accept();
        fstream wr;
        wr.open("d:\\salaryproject\\salary.txt",ios::app);
        wr.write((char*)&a,sizeof(obj));
        cout<<endl<<"salary dispensed  ";


    }
    void searchsalarybyempid()
    {
        int x;
        cout<<"enter empid to be searched for salary  ";
        cin>>x;
        fstream rd;
        rd.open("d:\\salaryproject\\employeedata.txt",ios::in);
        rd.seekg(0,ios::end);
        int n=rd.tellg();
        n=n/sizeof(obj);
        rd.seekg(0,ios::beg);
        for ( int i=1;i<=n;i++)
        {
            rd.read((char*)&obj,sizeof(obj));
            if(x==obj.empid)
            {
            obj.display();
            }
            }
    }
    void searchbymonth()
    {
        char b[50];
        int x;
        cout<<"enter month to be searched";
        cin>>b;
        fstream rd;
        rd.open("d:\\salaryproject\\salary.txt",ios::in);
        rd.seekg(0,ios::end);
        int n=rd.tellg();
        n=n/sizeof(obj);
        rd.seekg(0,ios::beg);
        for(int i=1;i<=n;i++)
        {
            rd.read((char*)&a,sizeof(obj));
            x=stricmp(a.month,b);
            if(x==0)
            {
                a.display();
            }

        }
    }

int main()
{               char p[6]={'s','a','u','r','a','v'};
                char ch,u[30];
                int i=0,yy=0;
                cout<<"                      Enter Password      ";
                for(int z=3;z>=1;z--)
                {
            cout<<endl<<"you have "<<z<<" "<<"Chances To enter password:";
                while(1)
                {
                                ch=getch();
                                if(ch==13)
                                {
                                cout<<"*";
                                break;
                                }
                                else
                                {
                                u[i]=ch;
                                i++;
                                }
                }
                if(i==6)
                {
                      break;
                }
                }
                if(i==6)
                {
                for(int c=0;c<=(i-1);c++)
                {
                if(p[c]==u[c])
                {
                yy++;
                }
                }
                }
                else
                {
                cout<<endl<<"wrong password";
                }
                if(yy==6)
                {
  int e=0;
  while(e!=1)
  {

      cout<<endl<<"                             ";
      cout<<endl<<"Enter 1 to Addemployee";
      cout<<'\n';
      cout<<endl<<"Enter 2 to show All Employee";
      cout<<'\n';
      cout<<endl<<"Enter 3 to Search Employee";
      cout<<'\n';
      cout<<endl<<"Enter 4 to Remove Employee";
      cout<<'\n';
      cout<<endl<<"Enter 5 to Update Employee";
      cout<<'\n';
      cout<<endl<<"Enter 6 to dispense salary";
      cout<<'\n';
      cout<<endl<<"Enter 7 to Search Employee salary by Month";
      cout<<'\n';
      cout<<endl<<"Enter 8 to  Search Employee Salary by Employee ID";
      cout<<'\n';
      cout<<endl<<"Enter 9 to Exit";
      int choice ;
      cin>>choice;
      switch(choice)
      {

      case 1:
        {

            addemployee();
            break;
        }
      case 2:
        {

            showallemployee();
            break;
        }
      case 3:
        {
            int f ;
            f=0;
            while(f!=1)
            {
    cout<<endl<<" Enter 11 to Search Employee by Employee ID";
    cout<<'\n';
    cout<<endl<<" Enter 12  to Search Employee by Employee Name";
    cout<<'\n';
    cout<<endl<<" Enter 13 to Search Employee by Employee Post";
    cout<<'\n';
    cout<<endl<<" Enter 14 to Exit";
    cout<<'\n';
            int choice;
            cin>>choice;
            switch(choice)
            {
            case 11:
                {
         searchbyempid();
         break;
                }

            case 12:
                {

            searchbyname();
            break;
        }
            case 13:
          {

            searchbypost();
            break;

        }
             case 14:
        {
            f=1;
            break;
        }
            }
            }
            break;
            }
           case 4:
        {
            removeemployee();
            break;
        }
      case 5:
        {

            updateemployee();
            break;
        }
      case 6:
        {

            salarydispensed();
            break;
        }
      case 7:
        {
            searchbymonth();
            break;
        }
      case 8:
        {
            searchsalarybyempid();
            break;
        }
      case 9:
        {

            e=1;
            break;
        }
            }

  }
                }
}



