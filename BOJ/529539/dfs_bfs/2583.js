// 2025.02.18 풀이
// [DFS] 영역 구하기
// https://www.acmicpc.net/problem/2583

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
	const [yLen, xLen, k] = input.shift().split(" ").map(Number);
	// 전체 영역을 0으로 초기화하고 직사각형이 있는 영역에 1을 저장
	const graph = Array.from(Array(yLen), () => Array(xLen).fill(0));
	input.forEach((el) => {
		const [x1, y1, x2, y2] = el.split(" ").map(Number);
		for (let y = yLen - y2; y < yLen - y1; y++)
			for (let x = x1; x < x2; x++) graph[y][x] = 1;
	});
	// 4방향 탐색을 위한 이동 벡터
	const dx = [0, 1, 0, -1];
	const dy = [1, 0, -1, 0];
	// 탐색 여부 저장
	const visited = Array.from(Array(yLen), () => Array(xLen).fill(false));
	// 현재 탐색 중인 영역, 즉 직사각형의 넓이를 세기 위해 사용
	let area = 0;
	function dfs(y, x) {
		area++;
		visited[y][x] = true;
		for (let i = 0; i < 4; i++) {
			const ny = y + dy[i];
			const nx = x + dx[i];
			if (nx >= 0 && nx < xLen && ny >= 0 && ny < yLen)
				if (!graph[ny][nx] && !visited[ny][nx]) dfs(ny, nx);
		}
	}
	const answer = [];
	// 모든 좌표에 대해 탐색
	for (let i = 0; i < yLen; i++) {
		for (let j = 0; j < xLen; j++) {
			area = 0; // 영역 넓이 초기화
			// 직사각형이면서 아직 탐색하지 않은 영역에 대해
			if (!visited[i][j] && !graph[i][j]) {
				dfs(i, j); // 깊이우선탐색 진행 (연결 컴포넌트를 모두 탐색하며 size 계산)
				answer.push(area); // DFS 진행 후 영역 넓이 저장
			}
		}
	}
	console.log(answer.length);
	console.log(answer.sort((a, b) => a - b).join(" "));
}
