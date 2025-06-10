const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let t;
let lineCnt = 0;
let newbi = [];
let test = 0;
let n = 0;
let internCnt = 0;
let res = [];

rl.on('line', (line) => {
    if (lineCnt == 0) {
        t = parseInt(line);
        lineCnt++;
    }
    else {
        if (internCnt == 0) {
            n = parseInt(line);
            newbi = [];
            internCnt++;
        }
        else {
            let [first, second] = line.split(' ').map(Number);
            newbi.push([first, second]);
            internCnt++;
            
            if (internCnt > n) {
                newbi.sort((a, b) => a[0] - b[0]);
                
                let cnt = 1;
                let minInterview = newbi[0][1];
                
                for (let i = 1; i < n; i++) {
                    if (newbi[i][1] < minInterview) {
                        cnt++;
                        minInterview = newbi[i][1];
                    }
                }
                
                res.push(cnt);
                test++;
                internCnt = 0;
                
                if (test == t) {
                    rl.close();
                }
            }
        }
    }
}).on('close', () => {
  res.forEach(result => console.log(result));
  process.exit();
});