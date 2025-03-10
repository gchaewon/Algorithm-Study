// 2025.03.09 풀이
// [재귀_분할정복] 완전 이진 트리
// https://www.acmicpc.net/problem/9934

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
	const height = +input.shift();
	const tree = [...Array(height)].map(() => []);
	const nodes = input[0].split(" ");
	// 중위 순회이므로 중간에 위치한 값이 부모 노드
	function recursion(subtree, level) {
		// 트리의 높이까지 모두 탐색 완료 시 종료
		if (level === height) return;
		// 현재 서브트리의 중간 값이 부모 노드이므로 트리의 해당 레벨에 푸시
		const mid = Math.floor(subtree.length / 2);
		tree[level].push(subtree[mid]);
		// 부모 노드를 기준으로 왼쪽 서브트리와 오른쪽 서브트리에 대해 재귀 호출
		recursion(subtree.slice(0, mid), level + 1);
		recursion(subtree.slice(mid + 1, subtree.length), level + 1);
	}
	// 전체 트리, 루트 노드부터 재귀 호출 시작
	recursion(nodes, 0);
	console.log(tree.map((level) => level.join(" ")).join("\n"));
}
