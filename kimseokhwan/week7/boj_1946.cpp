#include <iostream>
#include <algorithm>
using namespace std;

int main(){

    int t;
    int n;
    cin>>t;
    int *count_array=new int[t];
    int max_second=0;
    int count=0;
    
    for(int i=0;i<t;i++){
        cin>>n;
        pair<int,int> *score=new pair<int,int>[n];
        for(int k=0;k<n;k++){
            cin>>score[k].first>>score[k].second;
        }
        sort(score,score+n);

        count=0;
        max_second=score[0].second;
        for(int j=0;j<n;j++){
            if(score[j].second<=max_second){
                count++;
                max_second=score[j].second;
            }
        }
        count_array[i]=count;
    }

    for(int i=0;i<t;i++){
        cout<<count_array[i]<<endl;
    }

    return 0;
}
