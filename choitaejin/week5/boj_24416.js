const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

function fib(n) {
    if (n == 1 || n == 2) {
        return 1;
    }
    else {
        return (fib(n - 1) + fib(n - 2));
        cnt++;
    }

    return cnt;
}

function fibonacci(n) {
    let f = new Array(n + 1).fill(0);
    f[1] = f[2] = 1;
    for (let i = 3; i <= n; i++) {
        f[i] = f[i - 1] + f[i - 2];
        cnt++;
    }
    
    return cnt;
}

let input;
let cnt = 0;

rl.on('line', (line) => {
    input = parseInt(line);
    rl.close();
}).on('close', () => {
    const res = [fib(input), fibonacci(input)].join(' ');

    console.log(res);

    process.exit();
});