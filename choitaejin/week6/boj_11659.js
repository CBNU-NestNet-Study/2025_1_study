const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let lineCnt = 0;
let n, m;
let arr = [];
let prefixSum = [];

rl.on('line', (line) => {
    let num;
    if (lineCnt == 0) {
        num = line.split(' ').map(Number);
        n = num[0];
        m = num[1];
        lineCnt++;
    }
    else if (lineCnt == 1) {
        arr = line.split(' ').map(Number);

        prefixSum[0] = 0;
        for (let i = 1; i <= n; i++) {
            prefixSum[i] = prefixSum[i-1] + arr[i-1];
        }
        lineCnt++;
    }
    else if (lineCnt >= 2 && lineCnt < m+2) {
        let ij = line.split(' ').map(Number);
        let i = ij[0];
        let j = ij[1];
        
        console.log(prefixSum[j] - prefixSum[i-1])
        lineCnt++;
    }
    else {
        rl.close();
    }
}).on('close', () => {

    process.exit();
});