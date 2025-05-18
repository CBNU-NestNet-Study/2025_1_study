const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let lineCnt = 0;
let n;
let arr = [];

rl.on('line', (line) => {
    if (lineCnt == 0) {
        n = parseInt(line);
        lineCnt++;
    }
    else if (lineCnt == 1) {
        arr = line.split(' ').map((num) => parseInt(num));
        rl.close();
    }
}).on('close', () => {
    let dp = new Array(n).fill(1);

    for (let i = 0; i < n; i++) {
        for (let j = 0; j < i; j++) {
            if (arr[j] < arr[i]) {
                dp[i] = Math.max(dp[i], dp[j] + 1);
            }
        }
    }
    
    console.log(Math.max(...dp));
    process.exit();
});