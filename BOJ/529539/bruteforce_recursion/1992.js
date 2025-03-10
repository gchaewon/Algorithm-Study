// 2025.02.17 풀이
// [재귀_분할정복] 쿼드트리
// https://www.acmicpc.net/problem/1992

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
	const n = +input.shift();
	const screen = input.map((line) => line.split("").map(Number));
	const arr = [];
	function recursion(n, x, y) {
		let total = 0;
		for (let i = 0; i < n; i++)
			for (let j = 0; j < n; j++) {
				// 받아온 시작 좌표에서부터 현재 섹션의 모든 요소의 합 계산
				// 현재 섹션의 길이 n을 새로 받아오기 때문에 범위 초과 X
				total += screen[y + j][x + i];
			}
		// 현재 섹션의 모든 요소의 합이 0이면
		if (total === 0) arr.push("0");
		// 현재 섹션의 모든 요소의 합이 n^2, 즉 모두 1이면
		else if (total === n * n) arr.push("1");
		else {
			// 0 또는 1 하나로 압축되지 않으면
			n /= 2; // 크기를 절반으로 줄여 탐색 재귀 호출
			arr.push("("); // 섹션이 나누어질 경우에만 괄호 추가
			recursion(n, x, y); // 왼쪽 위 섹션
			recursion(n, x + n, y); // 오른쪽 위 섹션
			recursion(n, x, y + n); // 왼쪽 아래 섹션
			recursion(n, x + n, y + n); // 오른쪽 아래 섹션
			arr.push(")");
		}
	}
	recursion(n, 0, 0);
	console.log(arr.join(""));
}
