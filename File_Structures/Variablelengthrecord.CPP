#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
//coded by VIMAL KHATRI
//1CR18IS171
using namespace std;

class student
{
    public: char fname[20],lname[20],usn[12],sem[5],branch[5];
};
student t,s[20];
int count=0,i;
fstream fp;

char buffer[100],temp[20];
void pack(student p)
{
    //open file in append mode
    fp.open("lab3.txt",ios::out|ios::app);
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
    fp<<buffer<<endl;
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

void unpack()
{
    fp.open("lab3.txt",ios::in);
    for(i=0;i<count;i++)
    {
        fp.getline(buffer,100);
        sscanf(buffer,"%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|",
        s[i].fname,s[i].lname,s[i].usn,s[i].sem,s[i].branch);
    }
    fp.close();

}

void display()
{
    if (count==0)
    {
        cout<<"\n NO RECORDS";
    }
    cout<<"\n Students records are:"<<endl;
    cout<<"fname\tlname\tusn\tsem\tbranch\n";
    for(i=0 ;i<count;i++)
    cout<<s[i].fname<<"\t"<<s[i].lname<<"\t"
    <<s[i].usn<<"\t"<<s[i].sem<<"\t"<<s[i].branch<<endl;

}

void search()
{
    cout<<"Enter the usn\n";
    cin>>temp;
    for(i=0;i<count;i++)
    if(!strcmp(s[i].usn,temp))
    {
        cout<<"Record found\n"<<s[i].fname<<"\t"
        <<s[i].lname<<"\t"<<s[i].usn<<"\t"
        <<s[i].sem<<"\t"<<s[i].branch<<endl;
        break;
    }
    if(i==count)
    cout<<"Record not found";
}

void modify()
{
    if(i==count)
    return;
    cout<<"Enter new values\nEnter the fname:"<<endl;
    cin>>s[i].fname;
    cout<<"Enter the lname:"<<endl;
    cin>>s[i].lname;
    cout<<"Enter the usn:"<<endl;
    cin>>s[i].usn;
    cout<<"Enter the sem:"<<endl;
    cin>>s[i].sem;
    cout<<"Enter the branch:"<<endl;
    cin>>s[i].branch;
    fp.close();
    remove("lab3.txt");
    fp.open("lab3.txt",ios::out);
    fp.close();
    for(int j=0;j<count;j++)
    pack(s[j]);

}

int main()
{
    int ch;
    fp.open("lab3.txt",ios::out);
    fp.close();
    while(1)
    {
        cout<<" \n1.pack\t2.Unpack\t3.Search\t4.Modify\t5.Exit\n";
        cout<<" Enter your choice:"<<endl;
        cin>>ch;
        switch(ch)
        {
            case 1:count++;write();break;
            case 2:unpack();display();break;
            case 3:unpack();search();break;
            case 4:unpack();search();modify();break;
            default:exit(0);
        }
    }
}