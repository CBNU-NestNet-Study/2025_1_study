#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main(){
    long n; 
    cin >> n; 
    long sum = 0; 
    int i =1;
    int count =0; 
    while(1){
        if((sum + i)>n) break;
        sum += i;
        i++;
        count++;
    }
    cout << count << "\n";
}