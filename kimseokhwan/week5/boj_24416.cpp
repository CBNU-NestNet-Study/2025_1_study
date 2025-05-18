#include <iostream>
using namespace std;

int count_1=0;
int count_2=0;

int fib(int n);
int fibonnaci(int *array,int n);


int main(){
int n;
cin>>n;
int *array=new int[n];
int a,b;
a=fib(n);
b=fibonnaci(array,n);
cout<<count_1<<" "<<count_2<<endl;

delete [] array;

    return 0;
}




int fib(int n){
if(n==1||n==2)
{
    count_1++;
    return 1;
}
else{
    return fib(n-1)+fib(n-2);
}



}



int fibonnaci(int *array,int n){
    array[0]=array[1]=1;
    for(int i=2;i<n;i++){
        array[i]=array[i-1]+array[i-2];
        count_2++;
    }
    return array[n];
}