// LRU CACHE MISS
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int size,n,a[10000],i,j,k,l,c=0,z=0,flag,dc,ind;
    scanf("%d %d",&size,&n);
    int buf[size],dl[100];
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++)
    {
        flag=0;
        for(j=0;j<z;j++)
        {
            if(a[i]==buf[j])
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            c++;
            buf[z]=a[i];
            z++;
            if(c==size)
            {
                ind=i+1;
                break;
            }
        }
    }
for(i=ind;i<n;i++)
{
    //PRINTING THE BUFFER PERIODICALLY
    // printf("[");
    //     for(k=0;k<size;k++)
    //     {
    //         printf("%d ",buf[k]);
    //     }
    //     printf("]\n");
    flag=0;
    for(j=0;j<z;j++)
    {
        if(a[i]==buf[j])
        {
            flag=1;
            break;
        }
    }
    if(flag==1)
    {
        continue;
    }
    else
    {
        for(k=0;k<size;k++)
        {
            dl[k]=buf[k];
        }
        dc=0;
        for(j=i-1;j>=0;j--)
        {
            for(k=0;k<size;k++)
            {
                if(dl[k]==a[j])
                {
                    dl[k]=-1;
                    dc++;
                    break;
                }
            }
            if(dc==(size-1))
            {
                break;
            }
        }
        for(k=0;k<size;k++)
        {
            if(dl[k]!=-1)
            {
                buf[k]=a[i];
                c++;
                break;
            }
        }
        
    }
    
}
printf("CACHE MISS COUNT= %d",c);
    
}
