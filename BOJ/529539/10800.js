// 2025.02.15 풀이
// [누적합] 컬러볼
// https://www.acmicpc.net/problem/10800

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
	const n = input.shift();
	// 각 경우에 대해 따로 구하면 n^2으로 시간 초과 -> 정렬 후 누적합으로 풀이
	const arr = input
		.map((line, idx) => [...line.split(" ").map(Number), idx])
		.sort((a, b) => a[1] - b[1] || a[0] - b[0]);
	// 조건부 누적합 : 색깔이 다름 && 크기가 작음 = 전체 누적합 - 같은 색깔 - 같은 크기
	let sum = 0;
	let C = {},
		S = {};
	let answer = new Array(+n).fill(0); // 정렬로 인해 달라진 인덱스 때문에 필요
	for (let i = 0; i < n; i++) {
		const [color, size, idx] = arr[i];
		sum += size;
		C[color] ? (C[color] += size) : (C[color] = size);
		S[size] ? (S[size] += size) : (S[size] = size);
		// 색깔과 크기까지 완전히 동일한 경우에 대한 처리 필요 -> 직전 값 대입
		if (i !== 0 && color === arr[i - 1][0] && size === arr[i - 1][1])
			answer[idx] = answer[arr[i - 1][2]];
		// C와 S에 중복 포함되어 2번 제외된 나 자신의 크기를 한번 더해야함
		else answer[idx] = sum - C[color] - S[size] + size;
	}
	// 시간 초과 방지 위해 console.log 대신 stdout.write 사용
	process.stdout.write(answer.join("\n"));
}
