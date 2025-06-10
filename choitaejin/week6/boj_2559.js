const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let lineCnt = 0;
let n, k;
let arr = [];

rl.on('line', (line) => {
    if (lineCnt == 0) {
      const nk = line.split(' ').map(Number);
      n = nk[0];
      k = nk[1];
      lineCnt++;
    }
    else if (lineCnt == 1) {
      arr = line.split(' ').map(Number);

      let windowSum = 0;
      for (let i = 0; i < k; i++) {
          windowSum += arr[i];
      }
      let maxSum = windowSum;

      for (let i = k; i < n; i++) {
          windowSum = windowSum - arr[i-k] + arr[i];
          maxSum = Math.max(windowSum, maxSum);
      }
      console.log(maxSum);

      rl.close();
    }

}).on('close', () => {

    process.exit();
});
