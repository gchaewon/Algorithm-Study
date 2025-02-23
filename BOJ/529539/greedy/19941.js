// 2024.09.27 풀이
// [그리디] 햄버거 분배
// https://www.acmicpc.net/problem/19941

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
	const [n, k] = input[0].split(" ").map(Number);
	let table = input[1].split("");
	let answer = 0;
	for (let i = 0; i < n; i++) {
		if (table[i] === "P") {
			const start = i - 1 - k;
			const end = i - 1 + k;
			for (let j = start; j <= end; j++) {
				if (table[j] === "H") {
					answer++;
					table[j] = "D";
					break;
				}
			}
		}
	}
	console.log(answer);
}
