#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<stdbool.h>

int main(){

    FILE *primes;
 
    unsigned long long limit=10000000000;
    unsigned long long count=limit-2;

    bool *arr = calloc(limit,1);
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    for(unsigned long long i = 2;i<limit;i++)arr[i]=true;

    for(unsigned long long i=2;i<=sqrt(limit);i++){ 

        if(arr[i]==false)continue;
        
        for(unsigned long long j=i*i;j<limit;j+=i){
            if(arr[j]!=false){
                arr[j]=false;
                count--;
            }
        }
    }

    primes=fopen("Prime.txt","w");

    for(unsigned long long i=2;i<limit;i++){
        if(arr[i]==true){
            fprintf(primes,"%d\n",i);
        }
    }
    printf("NUMBER = %lld",count);

    fclose(primes);
    free(arr);
}
