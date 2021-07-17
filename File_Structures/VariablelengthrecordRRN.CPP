#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string.h>

using namespace std;

class student
{
    public: char fname[20],lname[20],usn[12],sem[5],branch[5];
};

student s[100],t;
char buffer[45],temp1[20],temp2[20];
int count=0,i;
fstream fp;

void pack(student p)
{
    //open file in append mode
    fp.open("hello.txt",ios::out|ios::app);
    //pack all fields of object delimited by |
    strcpy(buffer,p.fname);
    strcat(buffer,"|");
    strcat(buffer,p.lname);
    strcat(buffer,"|");
    strcat(buffer,p.usn);
    strcat(buffer,"|");
    strcat(buffer,p.sem);
    strcat(buffer,"|");
    strcat(buffer,p.branch);
    strcat(buffer,"|");
    fp<<count<<"|"<<buffer<<endl;
    fp.close();

    
}

void write()
{
    cout<<"Enter the fname:"<<endl;
    cin>>t.fname;
    cout<<"Enter the lname:"<<endl;
    cin>>t.lname;
    cout<<"Enter the usn:"<<endl;
    cin>>t.usn;
    cout<<"Enter the sem:"<<endl;
    cin>>t.sem;
    cout<<"Enter the branch:"<<endl;
    cin>>t.branch;
    pack(t);
}

void search()
{
    cout<<"enter the RRN\n";
    cin>>temp1;
    fp.open("hello.txt",ios::in);
    for(int i=0;i<count;i++)
    {
        fp.getline(buffer,100);
        sscanf(buffer,"%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|",temp2,s[i].fname,s[i].lname,s[i].usn,s[i].sem,s[i].branch);
        if (strcmp(temp1,temp2)==0)
        {
            cout<<"Record found\n"<<"fname\tlname\tusn\tsem\tbranch\n"<<s[i].fname<<"\t"<<s[i].lname<<"\t"<<s[i].usn<<"\t"<<s[i].sem<<"\t"<<s[i].branch<<endl;
            break;
        }
        
    }
    if(i==count)
    cout<<"Record not found";
    fp.close();
}

int main()
{
    int c;
    fp.open("hello.txt",ios::out);
    fp.close();
    while(1)
    {
        cout<<"\n1.Write\n2.Search\n3.Exit\nEnter Your Choice\n";
        cin>>c;
        switch(c)
        {
            case 1:count++;write();break;
            case 2:search();break;
            default:exit(0);
        }
    }
}