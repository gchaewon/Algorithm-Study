// 2024.09.25 풀이
// [그리디] ATM
// https://www.acmicpc.net/problem/11399

const fs = require("fs");
const path = "./input.txt";

const readline = require("readline");
const rl = readline.createInterface({
	// input: process.stdin,
	input: fs.createReadStream(path),
	output: process.stdout,
});

let input = [];

rl.on("line", function (line) {
	input.push(line);
}).on("close", function () {
	solution(input);
	process.exit();
});

function solution(input) {
	const arr = input[1].split(" ").map(Number);
	const sum = arr;
	arr
		.sort((a, b) => a - b)
		.reduce((acc, curr) => {
			sum.push(acc);
			return acc + curr;
		}, 0);
	console.log(sum.reduce((acc, curr) => acc + curr, 0));
}
