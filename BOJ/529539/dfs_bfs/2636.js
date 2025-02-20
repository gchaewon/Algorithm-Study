// 2025.02.19 풀이
// [BFS] 치즈
// https://www.acmicpc.net/problem/2636

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
	let visited = Array.from(Array(yLen), () => Array(xLen).fill(0));
	// 4방향 탐색을 위한 이동 벡터
	const dx = [0, 1, 0, -1];
	const dy = [1, 0, -1, 0];
	// 시간대별 치즈 영역의 크기 저장
	const cheese = [];
	// 현재 시간의 녹지 않은 치즈 영역의 크기를 업데이트, cheese에 저장
	let currCheese = 0;
	let arr = input.map((line) =>
		line.split(" ").map((el) => {
			if (+el === 1) currCheese++;
			return +el;
		})
	);
	cheese.push(currCheese); // cheese[0]은 초기 치즈의 크기
	// 너비우선탐색으로 공기(0)인 경우를 모두 탐색, 치즈를 만난 경우 녹임
	function bfs() {
		// 시간대별로 방문 여부 배열 초기화 필요
		visited = visited.map((el) => Array(el.length).fill(0));
		// 큐를 이용하여 구현, 항상 공기인 (0,0)에서부터 공기 탐색 시작
		const queue = [[0, 0]];
		visited[0][0] = 1;
		while (queue.length) {
			const [y, x] = queue.shift();
			for (let i = 0; i < 4; i++) {
				const [ny, nx] = [y + dy[i], x + dx[i]];
				if (nx >= 0 && nx < xLen && ny >= 0 && ny < yLen)
					if (!visited[ny][nx]) {
						visited[ny][nx] = 1;
						// 공기(0,0)에서 시작하므로 arr[y][x]는 항상 0
						// 다음 인접 탐색 지역이 치즈인 경우 녹이고 큐에 있는 다음 영역 탐색
						if (arr[ny][nx] === 1) {
							arr[ny][nx] = 0;
							currCheese--;
						} else {
							// 다음 인접 탐색 지역이 공기인 경우 큐에 추가하여 탐색 계속
							queue.push([ny, nx]);
						}
					}
			}
		}
		// 현재 시점에 남은 치즈 영역의 크기 저장
		cheese.push(currCheese);
	}
	let time = 0;
	// 모든 치즈가 녹을 때까지 반복
	while (currCheese > 0) {
		time++;
		bfs();
	}
	console.log(time);
	console.log(cheese.at(-2));
}
