#include <stdio.h>


int main(){
    int n;
    scanf("%d",&n);
    int factorial;
    for(int i=1;i<=n;i++){
        factorial=factorial*i;
    }
    printf("factorial:%d\n",factorial);
}