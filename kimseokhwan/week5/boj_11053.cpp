#include <iostream>
using namespace std;
void count(int *array,int *length,int size);

int main(){
int n=0;
cin>>n;
int *array=new int[n];
int *length=new int[n];

for(int i=0;i<n;i++){
    cin>>array[i];
    length[i]=1;
}

count(array,length,n);

int max_idx=0;
for(int i=0;i<n;i++){
    if(length[max_idx]<length[i]){
        max_idx=i;
    }
}

cout<<length[max_idx];

delete []array;
delete []length;

return 0;

}



void count(int *array,int *length,int size){
for(int i=0;i<size;i++){
    for(int j=0;j<i;j++){
        if(array[i]>array[j]){
            length[i]=max(length[i],length[j]+1);
        }
    }
}
}

