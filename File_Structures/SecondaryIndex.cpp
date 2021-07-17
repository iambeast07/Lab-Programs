//VIMAL KHATRI COPYRIGHTED CODE
//Program 6
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string.h>

using namespace std;
class student{
	public: char usn[12],fname[20],lname[20],sem[5],branch[5];
};

student t,s[20];
fstream fd,fd2,fds;
int k,c=0;
char buffer1[50],buffer2[50],buffer3[40],temprrn[5],tempusn[12],keyusn[20],keyfname[20],tempfname[20];

void pack(student t){
	fd.open("stu.txt",ios::out | ios::app);
	fd2.open("index.txt",ios::out | ios::app);
	fds.open("secind.txt",ios::out | ios::app);

	strcpy(buffer1,t.usn);	
	strcat(buffer1,"|");
	strcat(buffer1,t.fname);
	strcat(buffer1,"|");
	strcat(buffer1,t.lname);
	strcat(buffer1,"|");
	strcat(buffer1,t.sem);
	strcat(buffer1,"|");
	strcat(buffer1,t.branch);
	strcat(buffer1,"|");
	int x=strlen(buffer1);
	for(int i=0; i<70-x; i++)	
		strcat(buffer1,"*");
	fd<<c<<"|"<<buffer1<<endl;
	fd.close();
	fd2<<t.usn<<"|"<<c<<"|"<<endl;
	fd2.close();
	fds<<t.fname<<"|"<<t.usn<<"|"<<endl;
	fds.close();
}


void write(){
	cout<<"enter the student usn:";
	cin>>t.usn;

	cout<<"enter the student first name:";
	cin>>t.fname;
	
	cout<<"enter the student last name:";
	cin>>t.lname;
	
	cout<<"enter the student sem:";
	cin>>t.sem;
	
	cout<<"enter the student branch:";
	cin>>t.branch;

	pack(t);
}

void unpack(){
	fd.open("stu.txt",ios::in);
	for(int i=0; i<c; i++){
		fd.getline(buffer1,100);
		sscanf(buffer2,"%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|",s[i].usn,s[i].fname,s[i].lname,s[i].sem,s[i].branch);
	}
	fd.close();
}


void search(){
	int flag=0,flag1;
	cout<<"enter the fname to search:"<<endl;
	cin>>keyfname;

	
	fds.open("secind.txt",ios::in);
	fd.open("stu.txt",ios::in);
	fd2.open("index.txt",ios::in);

	for(int l=0; l<c; l++){
		fds.getline(buffer3,40);
		sscanf(buffer3,"%[^|]|%[^|]|",tempfname,keyusn);
		if(strcmp(tempfname,keyfname) == 0){
				flag = 1;
			for(k=0; k<c; k++){
				flag1=0;
				fd2.getline(buffer1,30);
				sscanf(buffer1,"%[^|]|%[^|]|",tempusn,temprrn);
				if(!strcmp(keyusn,tempusn)){
					flag1 = 1;
					cout<<"record  found\n";
					int rrn=atoi(temprrn);
					cout<<"rrn of usn is found:"<<rrn<<endl;
					fd.seekg((rrn-1)*73,ios::beg);
					fd.getline(buffer2,100);
					sscanf(buffer2,"%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|",temprrn,t.usn,t.fname,t.lname,t.sem,t.branch);
					cout<<"\n usn:"<<t.usn<<"\t fname:"<<t.fname<<"\t lname:"<<t.lname<<"\t sem:"<<t.sem<<"\t branch:"<<t.branch<<endl;
				break;
			}
		}
	}
	if(flag1 == 1)
		break;
}
	if(flag == 0 || flag1 ==0)
		cout<<"record not found";
		fd.close();
		fd2.close();
		fds.close();

}
void deleter(){
	if(k==c)
		return;
	fd.open("stu.txt",ios::in);
	for(int j=0; j<c; j++){
		fd.getline(buffer1,100);
		sscanf(buffer1,"%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|",temprrn,s[j].usn,s[j].fname,s[j].lname,s[j].sem,s[j].branch);
	}
	fd.close();
	remove("std.txt");
	remove("index.txt");
	remove("secind.txt");
	fd.open("stu.txt",ios::out);
	fd2.open("index.txt",ios::out);
	fds.open("secind.txt",ios::out);
	fd.close();
	fd2.close();
	fds.close();
	int oldcount=c;
	c=0;
	for(int j=0; j<oldcount; j++){
		if(j!=k){
			c++;
			pack(s[j]);
		}
	}
}


int main(){
	int ch;
	fd.open("stu.txt",ios::out);
	fd.close();
	fd2.open("index.txt",ios::out);
	fd2.close();
	fds.open("secind.txt",ios::out);
	fds.close();

	while(1){
		cout<<"\n 1:pack \t 2:search \t 3:delete  \t 4:exit"<<endl;
		cout<<"enter your choice: \n";
		cin>>ch;
		switch(ch){
			case 1: c++;
					write();
					break;
			case 2: unpack();
					search();
					break;
			case 3: search();
					deleter();
					break;
			case 4: exit(0);
	
			default : cout<<"invalid choice"<<endl;
		}
	}
		
}