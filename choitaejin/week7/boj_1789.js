const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let input;
let cnt = 0;

rl.on('line', (line) => {
  
  input = parseInt(line);
  let i = 1;
  let sum = 0;

  while (sum <= input) {
    sum += i;
    cnt++;
    i++;
  }

  if (sum > input) cnt--;

  rl.close();

}).on('close', () => {
  console.log(cnt);
  process.exit();
});
