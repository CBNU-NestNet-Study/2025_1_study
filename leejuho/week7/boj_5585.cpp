#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main(){
    int n; 
    cin >> n; 
    vector<int> coins= {500, 100, 50, 10 ,5, 1}; 
    int change =1000-n; 
    int count = 0; 
    for(int coin : coins){
        count += change / coin; 
        change %= coin; 
    }
    cout << count <<"\n";
}
