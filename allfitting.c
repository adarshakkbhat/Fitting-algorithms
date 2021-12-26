#include<stdio.h>
int tempb[10],tempm[10];
void temp(int b[],int n,int m[],int p);
void display(int alloted[],int n,int notalloted[],int count);
void worstfit(int b[],int n,int m[],int p);
void bestfit(int b[],int n,int m[],int p);
void firstfit(int b[],int n,int m[],int p);
int main()
{
    int b[10],m[10],n,p,i;
    printf("Enter the number of blocks\n");
    scanf("%d",&n);
    printf("Enter the number of processes\n");
    scanf("%d",&p);
    printf("Enter block sizes\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&b[i]);
    }
    printf("Enter memory requirments\n");
    for(i=0;i<p;i++)
    {
        scanf("%d",&m[i]);
    }
    printf("First Fit\n");
    temp(b,n,m,p);
    firstfit(tempb,n,tempm,p);
    printf("Bestfit\n");
    temp(b,n,m,p);
    bestfit(tempb,n,tempm,p);
    printf("Worstfit\n");
    temp(b,n,m,p);
    worstfit(tempb,n,tempm,p);
    return 0;
}
void temp(int b[],int n,int m[],int p)
{
    int i;
    for(i=0;i<n;i++)
    tempb[i]=b[i];
    for(i=0;i<p;i++)
    tempm[i]=m[i];
}
void worstfit(int b[],int n,int m[],int p)
{
    int i,j,maxb=0,maxpos=9,alloted[10]={0},notalloted[10],count=0;
    for(i=0;i<p;i++)
    {
        maxb=0;
        maxpos=9;
        for(j=0;j<n;j++)
        {
            if(b[j]>0&&b[j]>maxb&&b[j]>=m[i])
            {
                maxb=b[j];
                maxpos=j;
            }
        }
        if(maxb==0)
        {notalloted[count]=i+1;count++;}
        else
        {
            alloted[maxpos]=i+1;
            b[maxpos]=0;
        }
    }
    display(alloted,n,notalloted,count);
}
void bestfit(int b[],int n,int m[],int p)
{
    int i,j,minb=0,minpos=9,alloted[10]={0},notalloted[10],count=0;
    for(i=0;i<p;i++)
    {
        minb=9999;
        minpos=9;
        for(j=0;j<n;j++)
        {
            if(b[j]>0&&b[j]<minb&&b[j]>=m[i])
            {
                minb=b[j];
                minpos=j;
            }
        }
        if(minb==9999)
        {notalloted[count]=i+1;count++;}
        else
        {
            alloted[minpos]=i+1;
            b[minpos]=0;
        }
    }
    display(alloted,n,notalloted,count);
}
void firstfit(int b[],int n,int m[],int p)
{
    int i,j,alloted[10]={0},notalloted[10],count=0,flag;
    for(i=0;i<p;i++)
    {
        for(j=0;j<n;j++)
        {
            flag=0;
            if(b[j]>=m[i])
            {
                alloted[j]=i+1;
                b[j]=0;
                flag=1;
                break;
            }
        }
        if(flag==0)
        {notalloted[count]=i+1;count++;}
    }
    display(alloted,n,notalloted,count);
}
void display(int alloted[],int n,int notalloted[],int count)
{
    int i;
    for(i=0;i<n;i++)
    printf("B%d\t",i+1);
    printf("\n");
    for(i=0;i<n;i++)
    {
        if(alloted[i]!=0)
        printf("P%d\t",alloted[i]);
        else
        printf("--\t");
    }
    printf("\nProcesses not alloted are ");
    for(i=0;i<count;i++)
    printf("%d ",notalloted[i]);
    printf("\n");
}