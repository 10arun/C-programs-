
#include <stdio.h>
#include<stdlib.h>
#define Max 3 
void insert(int [],int*,int*,FILE*);
void del(int [] ,int*,int*);
void display(int [] ,int,int);
int main()
{
    int q[Max];
    int r=-1,f=0,cnt=0;
    int ch;
    FILE* fp=fopen("data.txt","r");
      if(fp==0)
       {
           printf("File not found");
           return;
       }
    while(1)
    {
        printf("1 insert\n 2 del\n 3 display\n" );
        printf("Enter the choice\n");
        fscanf(fp,"%d",&ch);
        switch(ch)
        {
            case 1: insert(q,&r,&cnt,fp);
                    break;
            case 2: del(q,&f,&cnt);
                    break;
            case 3: display(q,f,cnt);
                   break;
            case 4: exit(0);       
        }
        
    }
    
    return 0;
}
void insert(int q[],int* r,int* cnt,FILE* fp)
{
    int ele;
    if((*cnt)==0)
      {
          printf("Queue overflow\n");
          return;
      }
      *r=(*r+1)%Max;
      printf("Ente the element ele\n ");
      fscanf(fp,"%d",&ele);
      q[*r]=ele;
      (*cnt)++;
}
void del(int q[],int* f,int* cnt)
{
    if((*cnt)==0)
    {
        printf("Queue Underflow");
        return;
    }
    printf("Element deleted from circular Queue\n",q[(*f)]);
    (*f)=((*f)+1)%Max;
    (*cnt)--;
}
void display(int q[],int f,int cnt)
{
    int i,j;
    if(cnt==0)
    {
        printf("Circular Queueis empty\n");
        return;
    }
    printf("Contents of Circular Queue\n");
    for(i=f,j=0;j<cnt;j++)
    {
        printf("%d %d\n",i,q[i]);
        i=(i+1)%Max;
    }
}

/*****data.txt*******/
/*
1
20
1 
30
1 
40
3 
4 
*/



