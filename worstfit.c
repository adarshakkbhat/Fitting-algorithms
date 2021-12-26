#include<stdio.h>
int main()
{
    int b[10],m[10],n,p,i,j,maxb,maxpos,notalloted[10],count=0,alloted[10]={0};
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
    printf("P%d ",notalloted[i]);
}