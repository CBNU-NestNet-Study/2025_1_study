#include <iostream>
using namespace std;

int main(){
    int cnt = 0;
    long long s;
    long long sum = 0;
    int next = 1;
    
    cin >> s;

    while(sum + next <= s){
        sum += next;
        next++;
        cnt++;
    }
    
    cout << cnt;
    
    return 0;
}