#include<stdlib.h>
#include<stdio.h>

int size;
char *arr;

int powThree(int N){
    if(N>0)
        return powThree(N-1)*3;
    return 1;
}
void check(int size, int start){
    if (size ==1) return;
    for (int i =  start-1 - size/3; i > start-1 - size/3*2; i--)
        arr[i] = ' ';
    check(size/3,start- size/3*2);
    check(size/3,start);
}

int main(){
    int N;
 
    while (scanf("%d",&N)!=EOF)
    {
        size = powThree(N);
        arr = (char*)malloc(sizeof(char)*(size+1));
        
        for (int i = 0; i < size; i++)
            arr[i] = '-';
       
        check(size,size);
        for (int i = 0; i < size; i++)
            printf("%c",arr[i]);
        printf("\n");
    }
}
