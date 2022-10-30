
#include <stdio.h>

void exch(int* a,int* b){
int t = *a;
*a = *b;
*b =t;
}
//int a[10] = {2,7,6,1,8,3,0,5,9,4};
//2,0,6,1,8,3,7,5,9,4
//2,0,3,1,8,6,7,5,9,4
int partition_2(int* a,int l,int r){

int i = l-1;
int j = r;
int cur = a[r];

for(;;){
    while (a[++i]<cur);
    while (a[--j]>=cur);
    if(i>=j)break;
    exch(a+i,a+j);
}
exch(a+i,a+r);
return i;
}

void printf_array(const int a[],const int lenth){

    for(int i=0;i<lenth;i++){
    printf("%d ",*(a+i));
}

printf("\n");
}

int partition(int a[], int l, int r){
int i = l-1; 
int j =r ;
int v = a[r];
for(;;)
{
while(a[++i]<v);
while(v<a[--j])if(i==j)break;
if(i>=j)break;
exch(a+i,a+j);
printf_array(a,10);
}
exch(a+i,a+r);
printf_array(a,10);
return i;	

}


void quick_sort(int a[],int l, int r){


if (r<=l)return;
int i = partition_2(a,l,r);
quick_sort(a,l,i-1);
quick_sort(a,i,r);

}

int main(){
    
int a[10] = {2,7,6,1,8,3,0,5,9,11};
printf_array(a,10);


quick_sort(a,0,9);

printf_array(a,10);

}