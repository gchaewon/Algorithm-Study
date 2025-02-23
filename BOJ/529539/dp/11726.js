// 2024.07.01 풀이
// [DP] 2×n 타일링
// https://www.acmicpc.net/problem/11726

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
	const n = +input[0];
	// 규칙 사진 https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2FxHh7e%2FbtrYzFcMV8G%2FJfiAVqinzyZIR4Tl4KE40k%2Fimg.png
	// 점화식 dp[n] = dp[n-1] + dp[n-2]
	const dp = new Array(n + 1).fill(0); // 인덱스 1부터 사용
	dp[1] = 1;
	dp[2] = 2;
	for (let i = 3; i <= n; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;
	}
	console.log(dp[n]);
}
