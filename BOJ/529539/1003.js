// 2024.07.02 풀이
// [DP] 피보나치 함수
// https://www.acmicpc.net/problem/1003

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

function fibonacci(n) {
	if (n == 0) {
		console.log("0");
		return 0;
	} else if (n == 1) {
		console.log("1");
		return 1;
	} else {
		return fibonacci(n - 1) + fibonacci(n - 2);
	}
}

function solution(input) {
	input.slice(1).forEach((n) => {
		// fibonacci(n); // 테스트
		const dp = new Array(n + 1).fill([0, 0]);
		dp[0] = [1, 0];
		dp[1] = [0, 1];
		// 점화식 dp[n] = dp[n-1] + dp[n-2]를 2차원 배열로
		for (let i = 2; i <= n; i++)
			dp[i] = [dp[i - 1][0] + dp[i - 2][0], dp[i - 1][1] + dp[i - 2][1]];
		console.log(dp[n].join(" "));
	});
}
