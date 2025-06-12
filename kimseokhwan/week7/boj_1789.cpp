#include <iostream>
using namespace std;

int main(){
long long s;
cin>>s;
int n=0;

while(s>0){
    n++;
    s-=n;

}

if(s<0){
    n--;
}
cout<<n;
return 0;

}