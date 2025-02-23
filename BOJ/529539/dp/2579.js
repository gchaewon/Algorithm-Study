// 2024.07.02 풀이
// [DP] 계단 오르기
// https://www.acmicpc.net/problem/2579

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
	const arr = input.map(Number);
	const n = arr[0];
	const dp = new Array(n + 1).fill(0);
	dp[1] = arr[1];
	dp[2] = arr[1] + arr[2];
	dp[3] = Math.max(arr[1], arr[2]) + arr[3]; // 1+3 or 2+3
	// 점화식 dp[n] = max(dp[n-3] + arr[n-1] + arr[n], dp[n-2] + arr[n])
	// n의 계단이 있을 때 마지막 계단을 필수로 밟으면서,
	// n-1을 밟으려면 3연속 되지 않도록 n-3을 밟았던 경우와
	// n-2를 밟고 바로 n을 밟는 경우 중 큰 수를 고름
	for (let i = 4; i <= n; i++)
		dp[i] = Math.max(dp[i - 3] + arr[i - 1] + arr[i], dp[i - 2] + arr[i]);
	console.log(dp[n]);
}
