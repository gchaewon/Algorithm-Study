// 2024.07.02 풀이
// [DP] RGB거리
// https://www.acmicpc.net/problem/1149

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
	const n = +input.shift();
	const arr = input.map((line) => line.split(" ").map(Number));
	const dp = Array.from(Array(n), () => Array(3).fill(0));
	// 0번 인덱스 초기화
	dp[0] = arr[0];
	for (let i = 1; i < n; i++)
		// i-1이 선택한 색상이 아닌 나머지 두 색상 중 최솟값 선택하여 누적합
		for (let j = 0; j < 3; j++)
			dp[i][j] =
				Math.min(dp[i - 1][(j + 1) % 3], dp[i - 1][(j + 2) % 3]) + arr[i][j];
	// 마지막 행의 누적합 중 최솟값
	console.log(Math.min(...dp[Number(n - 1)]));
}
