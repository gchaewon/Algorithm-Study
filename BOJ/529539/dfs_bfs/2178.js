// 2025.02.20 풀이
// [BFS] 미로 탐색
// https://www.acmicpc.net/problem/2178

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
	const [yLen, xLen] = input.shift().split(" ").map(Number);
	const arr = input.map((line) => line.split("").map(Number));
	let visited = Array.from(Array(yLen), () => Array(xLen).fill(0));
	const dx = [0, 1, 0, -1];
	const dy = [1, 0, -1, 0];
	// 최단거리를 구해야 하므로 너비우선탐색으로 탐색
	function bfs() {
		const queue = [[0, 0]];
		// 시작 지점도 거리에 포함
		visited[0][0] = 1;
		while (queue.length) {
			const [y, x] = queue.shift();
			for (let i = 0; i < 4; i++) {
				const [ny, nx] = [y + dy[i], x + dx[i]];
				if (nx >= 0 && nx < xLen && ny >= 0 && ny < yLen)
					if (!visited[ny][nx] && arr[ny][nx]) {
						// 이전 지점까지의 거리에 1을 더하여 저장
						visited[ny][nx] = visited[y][x] + 1;
						// 다음 지점 탐색을 위해 큐에 저장
						queue.push([ny, nx]);
					}
			}
		}
		/* bfs 종료 후 visited(n,m)에 저장된 값이 최단거리를 보장하는 이유
        : 경로가 여러 개여도 처음 (n,m)에 도착 후 그 거리를 visited에 저장한 후로는
        visited(n,m)이 0이 아니기 때문에 큐에 추가되지 않기 때문
        따로 break 할 필요 없이 큐에 남아있는 지점이 없으면 종료됨  */
		return visited[yLen - 1][xLen - 1];
	}
	console.log(bfs());
}
