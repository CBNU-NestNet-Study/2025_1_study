#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;  // 테스트 케이스 수 입력

    while (t--) {
        int n;
        cin >> n;  // 지원자 수 입력
        pair<int,int> score[100000];


        for (int i = 0; i < n; i++) {
            cin >> score[i].first >> score[i].second;
        }
        sort(score, score + n);

        int cnt = 1;                   
        int min = score[0].second;  

        for (int i = 1; i < n; i++) {         
            if (score[i].second < min) {
                cnt++;
                min = score[i].second;  
            }
        }

        cout << cnt << '\n';
    }

    return 0;
}
