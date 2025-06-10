#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);  // 입출력 속도 향상
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<pair<int, int>> applicants(N);  // {서류, 면접}

        for (int i = 0; i < N; ++i) {
            cin >> applicants[i].first >> applicants[i].second;
        }

        // 서류 성적 기준 오름차순 정렬
        sort(applicants.begin(), applicants.end());

        int result = 1;  // 첫 번째 지원자는 무조건 뽑힘
        int bestInterview = applicants[0].second;

        for (int i = 1; i < N; ++i) {
            //  면접 성적이 이전보다 더 좋으면 선발
            if (applicants[i].second < bestInterview) {
                result++;
                bestInterview = applicants[i].second;  // 기준 갱신
            }
        }

        cout << result << '\n';
    }

    return 0;
}
