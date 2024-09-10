var fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';
let input = fs.readFileSync(filePath).toString().trim().split('\n');
input = input[0].split(' ').map((item) => +item);
var a = parseInt(input[0]);
var b = parseInt(input[1]);
console.log(a+b);