// 2025.02.18 풀이
// [DFS] 트리
// https://www.acmicpc.net/problem/1068

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
	const d = +input.pop();
	let tree = Array.from(Array(n), () => []);
	let root = 0;
	input[0].split(" ").forEach((parent, idx) => {
		// 루트 노드 따로 저장
		if (+parent === -1) {
			root = idx;
		} else {
			// 부모 또는 나 자신이 삭제할 노드이면 저장 X
			if (+parent === d || idx === d) return;
			else tree[parent].push(idx);
		}
	});
	// 삭제할 노드가 루트 노드면 0 출력하고 종료
	if (root === d) {
		console.log(0);
		return;
	}
	let count = 0;
	function dfs(now) {
		// 자식 노드의 개수가 0개면 리프 노드이므로 개수 증가하고 탐색 종료
		if (tree[now].length === 0) {
			count++;
			return;
		}
		// 자식 노드가 있으면 모든 자식 노드에 대해 깊이우선탐색 진행
		tree[now].forEach((child) => dfs(child));
	}
	dfs(root);
	console.log(count);
}
