#include <stdio.h>
#include<stdlib.h>
#include<string.h>
void printarray(int a[],int n){
    for(int i=0;i<n;i++)
       printf("%d\n",a[i]);
}
int main()
{
    int arr[10];
    memset(arr,0,sizeof(arr));
      printarray(arr,10);
    return 0;
}
