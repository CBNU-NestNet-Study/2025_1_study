const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout,
});

let n, m;
let lineCnt = 0;
let arr = [];
let arrIdx = 0;
let cmd = [];
let cmdIdx = 0;
let prefix = [];

rl.on('line', (line) => {
    if (lineCnt == 0) {
        const temp = line.split(' ').map(Number);
        n = temp[0];
        m = temp[1];

        arr = Array(n).fill().map(() => Array(n).fill(0));
        cmd = Array(m).fill().map(() => Array(4).fill(0));
        prefix = Array(n+1).fill().map(() => Array(n+1).fill(0));

        lineCnt++;
    }
    else if (lineCnt > 0 && lineCnt < n+1) {
        arr[arrIdx] = line.split(' ').map(Number);
        arrIdx++;
        lineCnt++;
    }
    else if (lineCnt > n && lineCnt <= n + m) {
        cmd[cmdIdx] = line.split(' ').map(Number);
        cmdIdx++;
        lineCnt++;
    }
    else rl.close();
});
rl.on('close', () => {
    for (let i = 1; i <=n; i++) {
        for (let j = 1; j <= n; j++) {
            prefix[i][j] = prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1] + arr[i-1][j-1];
        }
    }

    for (let k = 0; k < m; k++) {
        let x1 = cmd[k][0];
        let y1 = cmd[k][1];
        let x2 = cmd[k][2];
        let y2 = cmd[k][3];

        const result = prefix[x2][y2]           
                      - prefix[x1-1][y2]         
                      - prefix[x2][y1-1]         
                      + prefix[x1-1][y1-1];     

       console.log(result);
    }

    process.exit();
});