// 2025.02.13 풀이
// [수학] 곱셈
// https://www.acmicpc.net/problem/1629

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
	// JS Number 최댓값 = 2^53 - 1, BigInt 사용 필수
	const [a, b, c] = input[0].split(" ").map(BigInt);
	// b가 짝수 : a^b = a^(b/2) * a^(b/2)
	// b가 홀수 : a^b = a^(b/2) * a^(b/2 + 1) = a^(b/2) * a^(b/2) * a
	// 분할 정복으로 거듭제곱을 지수법칙을 사용해 나누어 재귀 호출로 계산
	// 이때 매번 재귀 호출을 수행하지 않고 한 번만 호출해 그 값을 저장하여 사용
	let k; // 메모이제이션할 변수
	// 0, 1, 2 등 일반 Number와 연산/비교 시 변환 필요
	function power(b) {
		if (b === BigInt(0)) return 1;
		if (b === BigInt(1)) return a % c;
		k = power(b / BigInt(2)) % c;
		if (b % BigInt(2) === BigInt(0)) return (k * k) % c;
		else return (((k * k) % c) * a) % c;
	}
	console.log(power(b).toString());
}
