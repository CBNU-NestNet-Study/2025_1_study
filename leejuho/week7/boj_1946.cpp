#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;
        vector<pair<int, int>> applicants(N);

        for (int i = 0; i < N; ++i) {
            cin >> applicants[i].first >> applicants[i].second;
        }

     
        sort(applicants.begin(), applicants.end());

        int count = 1; 
        int bestInterview = applicants[0].second;

        for (int i = 1; i < N; ++i) {
            if (applicants[i].second < bestInterview) {
                count++;
                bestInterview = applicants[i].second;
            }
        }

        cout << count << '\n';
    }

    return 0;
}
