// VIMAL KHATRI 1CR18IS171-COPYRIGHTED CODE
#include<stdio.h>
int main()
{
    int locks,stocks,barrels,tlocks,tstocks,tbarrels;
    float lprice,sprice,bprice,lsales,ssales,bsales,sales,comm;
    lprice=45.0;
    sprice=30.0;
    bprice=25.0;
    tlocks=0;
    tstocks=0;
    tbarrels=0;
    printf("Enter the no of locks and to exit from the loop enter -1\n ");          scanf("%d",&locks);
    while(locks!=-1) {
        printf("enter the nos of stocks and nos of barrels\n");         scanf("%d%d",&stocks,&barrels);
        tlocks=tlocks+locks;
        tstocks=tstocks+stocks;
        tbarrels=tbarrels+barrels;
        printf("Enter the no of locks and to exit from the loop enter -1\n ");      scanf("%d",&locks);
    }
    printf("total locks that LUCI had=%d\n",tlocks);
    printf("total stocks that LUCI had=%d\n",tstocks);
    printf("total barrels that LUCI had=%d\n",tbarrels);
    lsales=lprice*tlocks;
    ssales=sprice*tstocks;
    bsales=bprice*tbarrels;
    sales=lsales+ssales+bsales;
    printf("the total sales done by LUCI =%f\n",sales);
    if(sales>1800.0)
    {
        comm=0.1*1000;
        comm=comm+(0.15*800);
        comm=comm+0.20*(sales-1800);        }
    else if (sales>1000)
    {
        comm=0.1*1000;
        comm=comm+0.15*(sales-1000);        }
    else
    comm=0.1*1000;
    printf("the total commission =%f",comm);
        
}