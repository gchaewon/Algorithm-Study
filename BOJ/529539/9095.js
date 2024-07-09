// 2024.07.05 풀이
// [DP] 1, 2, 3 더하기
// https://www.acmicpc.net/problem/9095

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
	const T = +input.shift();
	const arr = input.map(Number);
	// dp 초기화 - 1: 1 / 2: 1+1, 2 / 3: 1+2, 2+1, 1+1+1, 3
	let dp = [0, 1, 2, 4];
	// 4부터는 기존 연산에 추가로 수를 더하는 방식으로 증가함
	// 4: 1+3 / 1+1+2, 2+2 / 1+2+1, 2+1+1, 1+1+1+1, 3+1
	// => 1 횟수 + 2 횟수 + 3 횟수
	// 5는 1을 만들었던 연산으로는 4를 더할 수 없기에 사용 불가
	// 즉 직전 3개 연산의 횟수만 더하면 됨
	for (
		let i = 4;
		i <= Math.max(...arr);
		i++ // 케이스 중 가장 큰 숫자까지만 dp 계산 진행
	)
		dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1];
	// 각 케이스에 대해 dp에 저장된 횟수 출력
	arr.forEach((n) => console.log(dp[n]));
}
