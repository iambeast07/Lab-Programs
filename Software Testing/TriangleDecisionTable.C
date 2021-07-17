//THIS PROGRAM WAS DONE BY VIMAL
//USN 1CR18IS171 USING VS CODE
//DECISION BASED APPROACH
#include<stdio.h>
int main()
{
    int a,b,c;
    char istriangle;
    printf("Enter the three sides of the triangle");
    scanf("%d%d%d",&a,&b,&c);
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