const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let input, res;
let change = 0;

rl.on('line', (line) => {
  
  input = parseInt(line);
  res = 1000 - input;
  
  change += Math.floor(res / 500);
  res %= 500;

  change += Math.floor(res / 100);
  res %= 100;

  change += Math.floor(res / 50);
  res %= 50;

  change += Math.floor(res / 10);
  res %= 10;

  change += Math.floor(res / 5);
  res %= 5;

  change += Math.floor(res / 1);
  rl.close();

}).on('close', () => {
  console.log(change);
  process.exit();
});
