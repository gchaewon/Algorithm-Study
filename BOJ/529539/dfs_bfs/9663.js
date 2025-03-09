// 2025.03.09 풀이
// [백트래킹_DFS] N-Queen
// https://www.acmicpc.net/problem/9663

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
	const n = +input[0];
	const queens = []; // 퀸을 놓은 좌표를 저장할 배열
	function check(row, col) {
		for (const [qRow, qCol] of queens) {
			// 행 또는 열이 같으면 놓을 수 없음
			if (row === qRow || col === qCol) return false;
			// 같은 대각선 상에 있다면 놓을 수 없음
			if (Math.abs(row - qRow) === Math.abs(col - qCol)) return false;
		}
		return true;
	}
	let count = 0; // 방법의 수를 저장할 변수
	function dfs(row) {
		// console.log("depth:", row);
		// n행에 대해 탐색 성공했다면 n개의 퀸을 놓는 방법을 찾은 것
		// 0 ~ n-1로 탐색하므로 row = n이 호출되었다면 queens에 n개의 퀸 존재
		if (row === n) {
			count++;
			// console.log("- found", count);
		}
		// 현재 행에서 모든 열에 대해 탐색
		// 즉 (0, 0)부터 시작하여 이후 올 수 있는 퀸을 행별로 탐색 진행
		// 탐색이 끝났다면 (0, 1)을 넣고 같은 과정 반복
		for (let col = 0; col < n; col++) {
			// 퀸을 놓을 수 없는 좌표라면 건너뜀
			if (!check(row, col)) {
				// row = n일때는 모든 열에서 놓을 수 없기 때문에 다 지나가짐
				// console.log("skip", row, col);
				continue;
			}
			// 놓을 수 있는 좌표라면 놓고 다음 행에서 탐색 계속
			queens.push([row, col]);
			// console.log("push", row, col, queens);
			dfs(row + 1);
			// continue만 실행되어 재귀 호출 끝난 경우
			// 즉, 현재 depth(row, col)에 대한 dfs 탐색이 끝난 경우
			// 다음 열(row, col+1) 탐색 전 원복 필요
			queens.pop();
			// console.log("pop", queens);
		}
	}
	// 한 행에 하나의 퀸만 놓을 수 있으므로 0행에 대해서만 모든 열에 대해 각각 dfs 탐색
	dfs(0);
	console.log(count);
}
