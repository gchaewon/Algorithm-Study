// 2024.07.05 풀이
// [DP] 구간 합 구하기 4
// https://www.acmicpc.net/problem/11659

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
	const [n, m] = input.shift().split(" ").map(Number);
	const arr = input.shift().split(" ").map(Number);
	let dp = new Array(m + 1).fill(0);
	// 나열된 n개의 숫자 배열에 대해 dp에 순서대로 누적합 저장
	arr.forEach((n, i) => {
		dp[i + 1] = dp[i] + n;
	});
	// 각 i와 j에 대한 합산 출력
	input.forEach((ij) => {
		const [i, j] = ij.split(" ").map(Number);
		// j까지의 누적합에서 i-1까지의 누적합을 뺀 값이 i부터 j까지의 합
		console.log(dp[j] - dp[i - 1]);
	});
}
