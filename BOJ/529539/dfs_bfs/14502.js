// 2025.02.18 풀이
// [DFS_BFS] 연구소
// https://www.acmicpc.net/problem/14502

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
	let graph = input.map((line) => line.split(" ").map(Number));
	// 4방향 탐색을 위한 이동 벡터
	const dx = [0, 1, 0, -1];
	const dy = [1, 0, -1, 0];
	// 너비우선탐색으로 현재 그래프에 대해 바이러스를 모두 전염시킴
	function bfs(graph) {
		let queue = []; // 큐를 이용하여 구현
		// 모든 영역에 대해 2인, 즉 바이러스에 감염된 영역을 큐에 저장
		for (let i = 0; i < yLen; i++)
			for (let j = 0; j < xLen; j++) {
				if (graph[i][j] === 2) queue.push([i, j]);
			}
		// 큐에 저장된 모든 영역에 대해 반복
		while (queue.length) {
			const [y, x] = queue.shift();
			// 바이러스에 전염된 영역을 기준으로 4방향 모두 탐색
			for (let i = 0; i < 4; i++) {
				const [ny, nx] = [y + dy[i], x + dx[i]];
				// 범위를 벗어나지 않았고 벽이 없는 영역이라면
				if (
					nx >= 0 &&
					nx < xLen &&
					ny >= 0 &&
					ny < yLen &&
					graph[ny][nx] === 0
				) {
					// 감염시키고 현재 영역 큐에 저장
					graph[ny][nx] = 2;
					queue.push([ny, nx]);
				}
			}
		}
		// 감염되지 않은 안전영역의 크기를 저장
		let count = 0;
		// 모든 영역에 대해 반복
		for (let i = 0; i < yLen; i++)
			for (let j = 0; j < xLen; j++) {
				// 감염 확산 후 0이라면 크기 증가
				if (graph[i][j] === 0) count++;
			}
		return count;
	}
	// 최대 안전영역의 크기를 저장
	let answer = 0;
	// 깊이우선탐색으로 벽을 3개 세우는 모든 경우에 대한 탐색
	function dfs(wall) {
		// 벽을 3개 다 세웠다면
		if (wall === 3) {
			// 벽을 3개 세운 새로운 그래프를 복사하여 불변성 유지
			// (bfs로 바이러스 전염 시 그래프가 변경됨)
			let newGraph = graph.map((el) => [...el]);
			// 바이러스를 전염시키고 계산한 안전영역 크기와
			// 저장된 기존 안전영역의 크기를 비교하여 더 큰 경우에만 업데이트
			answer = Math.max(answer, bfs(newGraph));
		} else {
			// 모든 영역에 대해 반복
			for (let i = 0; i < yLen; i++) {
				for (let j = 0; j < xLen; j++) {
					// 벽을 세울 수 있는 공간이면
					if (graph[i][j] === 0) {
						// 벽을 세우고 벽의 개수를 증가시켜 다음 순회에 전달
						graph[i][j] = 1;
						dfs(wall + 1);
						// 변경된 그래프만 재귀호출에서 사용되고 다시 원복
						graph[i][j] = 0;
					}
				}
			}
		}
	}
	// 벽이 하나도 없는 초기 상태부터 깊이우선탐색 시작
	dfs(0);
	// 업데이트된 안전영역의 최댓값 출력
	console.log(answer);
}
