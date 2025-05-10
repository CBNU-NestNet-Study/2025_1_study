#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> v = {0,1};
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        v.push_back(v[i] + v[i+1]);
    }
    cout << v[n];
    return 0;
}