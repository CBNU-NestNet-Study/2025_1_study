const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let score = [];
let lineCnt = 0;
let n;

rl.on('line', (line) => {
    if (lineCnt === 0) {
        n = parseInt(line);
        lineCnt++;
    }
    else if (lineCnt <= n) {
        score.push(parseInt(line));
        lineCnt++;
        if(lineCnt > n) {
            rl.close();
        }
    }

}).on('close', () => { // [i][j] = i는 밟은 계단 수 - 1, j는 연속해서 밟은 계단 수 - 1
    let dp = Array(n).fill().map(() => [0, 0]);
    dp[0][0] = score[0]; // 첫 번째 계단 밟은 경우
    dp[0][1] = 0; // 첫번째 계단을 밟았는데 2개 연속해서 밟은 경우는 없으니까
    
    if (n > 1) {
        dp[1][0] = score[1]; // 첫 번째 계단 밟고 두번째
        dp[1][1] = score[0] + score[1]; // 두 번째 계단을 밟을 때 첫번째 밟고 두번째 연속으로 밟은 경우

        for (let i = 2; i < n; i++) {
            dp[i][0] = Math.max(dp[i-2][0], dp[i-2][1]) + score[i];
            dp[i][1] = dp[i-1][0] + score[i];
        }
    }

    console.log(Math.max(dp[n-1][0], dp[n-1][1]));

    process.exit();
});