// 2025.02.13 풀이
// [수학] 1
// https://www.acmicpc.net/problem/4375

const fs = require("fs");
const readline = require("readline");
const rl = readline.createInterface(
	process.platform === "linux"
		? { input: process.stdin, output: process.stdout }
		: { input: fs.createReadStream("./input.txt"), output: null }
);
let input = [];
rl.on("line", function (line) {
	input.push(line);
}).on("close", function () {
	solution(input);
	process.exit();
});

function solution(input) {
	input.forEach((n) => {
		let k = 1;
		let answer = 1;
		while (1) {
			if (k % +n === 0) break;
			else {
				k = k * 10 + 1;
				k %= +n; // 시간 초과 방지를 위해 모듈러 연산 수행
				answer++; // 자릿수는 따로 카운트
			}
		}
		console.log(answer);
	});
}
