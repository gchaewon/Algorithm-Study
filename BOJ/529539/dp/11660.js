// 2025.02.12 풀이
// [DP] 구간 합 구하기 5
// https://www.acmicpc.net/problem/11660

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
	const [n, m] = input.shift().split(" ").map(Number);
	// 누적합을 저장할 dp 배열 선언
	const dp = Array.from(Array(n + 1), () => new Array(n + 1).fill(0));
	// 배열 순회하며 누적합 저장
	for (let i = 1; i <= n; i++) {
		const row = input.shift().split(" ").map(Number); // row = input[i - 1]
		for (let j = 1; j <= n; j++) {
			// row[j - 1] === input[i - 1][j - 1]
			dp[i][j] = row[j - 1] + dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - 1];
		}
	}
	input.forEach((line) => {
		const [x1, y1, x2, y2] = line.split(" ").map(Number);
		console.log(
			dp[x2][y2] - dp[x1 - 1][y2] - dp[x2][y1 - 1] + dp[x1 - 1][y1 - 1]
		);
	});
}
