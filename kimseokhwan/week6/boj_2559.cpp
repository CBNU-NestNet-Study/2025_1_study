#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin>>n>>k;

    int *array=new int[n];

    for (int i=0;i<n;i++) {
        cin>>array[i];
    }

    int sum=0;
    for (int i=0;i<k;i++) {
        sum+=array[i];
    }

    int max_sum=sum;

    for (int i=k;i<n;i++) {
        sum=sum+array[i]-array[i-k];
        if (sum>max_sum) {
            max_sum = sum;
        }
    }

    cout<<max_sum;
    delete []array;
    return 0;
}
