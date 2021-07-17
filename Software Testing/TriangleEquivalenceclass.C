//EQUIVALENCE CLASS PARTITIONING
//WITH RESPECT TO BOUNDARY VALUE Analysis
//THIS PROGRAM WAS DONE BY VIMAL
//USN 1CR18IS171 BY VS CODE
#include<stdio.h>
int main()
{
    int a,b,c,c1,c2,c3;
    char istriangle;
    do
    {
        printf("Enter the three integers which are sides of triangle");
        scanf("%d%d%d",&a,&b,&c);
        printf("\na=%d\nb=%d\nc=%d\n",a,b,c);
        c1=a>=1&& a<=10;
        c2=b>=1&& b<=10;
        c3=c>=1&& c<=10;
        if(c1==0)
        printf("the range of a is not permisible and a is out of range\n");
        if(c2==0)
        printf("the range of b is not permissible and b is out of range\n");
        if(c3==0)
        printf("the range of c is not permissible and c is out of range\n");
    } while (!(c1&&c2&&c3));
    if((a<b+c)&&(b<a+c)&&(c<a+b))
    istriangle='y';
    else
    istriangle='n';
    if(istriangle=='y')
    {
        if((a==b)&&(b==c))
        printf("It is a equilateral triangle");
        else if ((a!=b)&&(b!=c)&&(a!=c))
        printf("it is a scalene triangle");
        else 
        printf("it is an isoceles triangle");
    }
    else
    printf("can't form a triangle");
    return 0;
}