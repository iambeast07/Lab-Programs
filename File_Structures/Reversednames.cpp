#include<iostream>
#include<fstream>
#include<cstring>

using namespace std;

char* strrev(char *str)
{
    int i=strlen(str)-1, j=0;
    char ch;
    while(i>j)
    {
        ch=str[i];
        str[i]=str[j];
        str[j]=ch;
        i--;
        j++;
    }
    return str;
}
int main()
{
    int n;
    char temp[20];
    fstream fp1,fp2;
    fp1.open("names.txt",ios::out);
    cout<<"enter the number of names to be read"<<endl;
    cin>>n;
    cout<<"enter names one per line:"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>temp;
        fp1<<temp<<endl;

    }
    fp1.close();
    fp1.open("names.txt",ios::in);
    fp2.open("revnames.txt",ios::out);
    cout<<"the reversed names:"<<endl;
    for(int i=0; i<n; i++)
    {
        fp1>>temp;
        fp2<<strrev(temp)<<endl;
        cout<<temp<<endl;
    }
    fp1.close();
    fp2.close();

}