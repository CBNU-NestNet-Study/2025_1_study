#include <iostream>
using namespace std;


int get_max(int *score,int last_idx,int *memoization);


int main(){
int n;
cin>>n;
int *score=new int[n];
for(int i=0;i<n;i++){
    cin>>score[i];
}
int *memoization=new int[n];

for(int i=0;i<n;i++){
    memoization[i]=-1;
}

memoization[1]=score[0]+score[1];
memoization[2]=score[0]+score[2]>score[1]+score[2]?(score[0]+score[2]):(score[1]+score[2]);

int max=get_max(score,n-1,memoization);
cout<<max;
delete []score;
delete []memoization;
return 0;


}



int get_max(int *score,int last_idx,int *memoization){

if(memoization[last_idx]!=-1){
    return memoization[last_idx];
}

if(last_idx==0){
    return memoization[0]=score[0];
;
}
if(last_idx==1){
    return memoization[1]=score[0]+score[1];
}
if(last_idx==2){
    return memoization[2]=score[0]+score[2]>score[1]+score[2]?(score[0]+score[2]):(score[1]+score[2]);
}

int selection_1=score[last_idx]+get_max(score,last_idx-2,memoization);
int selection_2=score[last_idx]+score[last_idx-1]+get_max(score,last_idx-3,memoization);

return memoization[last_idx]=selection_1>=selection_2?selection_1:selection_2;





}