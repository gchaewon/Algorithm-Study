// 2025.02.19 풀이
// [DFS] 안전 영역
// https://www.acmicpc.net/problem/2468

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
	const arr = input.map((el) => el.split(" ").map(Number));
	let visited = Array.from(Array(n), () => Array(n).fill(0));
	// 4방향 탐색을 위한 이동 벡터
	const dx = [0, 1, 0, -1];
	const dy = [1, 0, -1, 0];
	// 가장 높은 지역이 잠기는 경우까지만 계산하면 됨
	const maxHeight = Math.max(...[].concat(...arr));
	// 깊이우선탐색으로 안전 영역 (연결 컴포넌트) 탐색
	function dfs(y, x) {
		visited[y][x] = 1;
		for (let i = 0; i < 4; i++) {
			const [ny, nx] = [y + dy[i], x + dx[i]];
			if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[ny][nx])
				dfs(ny, nx);
		}
	}

	// 최대가 되는 안전 영역 개수 저장, 비가 오지 않으면 안전 영역은 전체 1
	let answer = 1;
	for (let rain = 0; rain <= maxHeight; rain++) {
		// 메모리 절약을 위해 외부에서 선언하고 같은 배열을 사용하므로
		// 매 경우마다 배열을 초기화 해야함
		for (let i = 0; i < n; i++) {
			for (let j = 0; j < n; j++) {
				// 물에 잠긴 지역은 방문할 필요가 없으므로 1 저장
				if (arr[i][j] <= rain) visited[i][j] = 1;
				else visited[i][j] = 0; // 안전 영역은 0
			}
		}
		// 안전 영역의 개수를 저장
		let safeArea = 0;
		for (let i = 0; i < n; i++) {
			for (let j = 0; j < n; j++) {
				if (!visited[i][j]) {
					safeArea++;
					dfs(i, j);
				}
			}
		}
		answer = Math.max(answer, safeArea);
	}
	console.log(answer);
}
