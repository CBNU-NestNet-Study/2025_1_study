#include <iostream>
using namespace std;

int arr[1206][1206];
int main(){

    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    int n, m;
    int sum = 0;

    cin >> n >> m;

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            int input;
            cin >> input;
            arr[i][j] = arr[i - 1][j] + arr[i][j-1] + input - arr[i-1][j-1];
        }
    }

    int x1, y1, x2, y2;
    
   for (int i = 0; i < m;i++){
        int result = 0;
        cin >> x1 >> y1 >> x2 >> y2;
        result = arr[x2][y2] - arr[x1 - 1][y2] - arr[x2][y1 - 1] + arr[x1 - 1][y1 - 1]; 
 
        cout << result << '\n';
    }
}