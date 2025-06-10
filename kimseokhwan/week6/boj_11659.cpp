#include <iostream>
using namespace std;

void PrefixSum(int *temp_sum, int *array, int n);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin>>n>>m;
    int *array = new int[n];
    int *temp_sum = new int[n];

    for(int i=0;i<n;i++) {
        cin>>array[i];
    }

    PrefixSum(temp_sum, array, n);

    for (int k = 0; k < m; k++) {
        int i, j;
        cin>>i>>j;
        if (i==1){
            cout<<temp_sum[j-1]<<'\n';
        }
        else{
            cout<<temp_sum[j-1]-temp_sum[i-2]<<'\n';
        }
    }

    delete[] array;
    delete[] temp_sum;
    return 0;
}

void PrefixSum(int *temp_sum, int *array, int n) {
    temp_sum[0] = array[0];
    for (int i=1;i<n;i++) {
        temp_sum[i]=temp_sum[i-1]+array[i];
    }
}
