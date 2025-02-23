// 2025.02.22 풀이
// [DP_그래프] 파이프 옮기기 1
// https://www.acmicpc.net/problem/17070

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
	const graph = input.map((line) => line.split(" ").map(Number));
	// dp[y][x][dir] (dir 0 →, 1 ↓, 2 ↘)
	const dp = Array.from({ length: n }, () =>
		Array.from({ length: n }, () => Array(3).fill(0))
	);
	// 초기 (0,1) 위치에서 → 방향 경우의 수 1가지
	dp[0][1][0] = 1;
	// 시작 위치부터 마지막 (n-1,n-1)까지 모든 위치에 대해 반복
	for (let y = 0; y < n; y++) {
		for (let x = 1; x < n; x++) {
			// 벽이 있는 경우 건너뛰고 탐색 계속
			if (graph[y][x] === 1) continue;
			// dir 0 (→ 방향) : 왼쪽(x-1)에서 온 경우 중 →, ↘ 두 경우를 더하여 저장
			if (x > 0) dp[y][x][0] += dp[y][x - 1][0] + dp[y][x - 1][2];
			// dir 1 (↓ 방향) : 위(y-1)에서 온 경우 중 ↓, ↘ 두 경우를 더하여 저장
			if (y > 0) dp[y][x][1] += dp[y - 1][x][1] + dp[y - 1][x][2];
			// dir 2 (↘ 방향) : 대각선 왼쪽위(y-1,x-1)에서 온 모든 방향에 대한 경우를 더하여 저장
			// 이때 근처 두 위치에 대한 벽 검사, 이동 가능했던 경우라면 반영
			if (x > 0 && y > 0)
				if (graph[y - 1][x] === 0 && graph[y][x - 1] === 0)
					dp[y][x][2] +=
						dp[y - 1][x - 1][0] + dp[y - 1][x - 1][1] + dp[y - 1][x - 1][2];
		}
	}
	// (n-1,n-1) 위치에 있는 모든 방향의 경우의 수 합산
	console.log(dp[n - 1][n - 1].reduce((acc, curr) => acc + curr, 0));
}

/* [첫 접근 - BFS 풀이] js로는 시간 초과 발생, cpp로는 통과
function solution(input) {
	const n = +input.shift();
	const graph = input.map((line) => line.split(" ").map(Number));
	// 순서대로 →, ↓, ↘ (y,x)
	const dy = [0, 1, 1];
	const dx = [1, 0, 1];
	let answer = 0; // 방법 개수 저장
	function bfs() {
		// 파이프 시작점은 (0,1) 도착점은 (n-1,n-1)
		// → 방향에서 항상 시작, 파이프 오른쪽 또는 아래쪽만 기준으로 탐색
		const queue = [[[0, 1], 0]];
		while (queue.length) {
			const [[y, x], dir] = queue.shift();
			// 도착한 경우 방법을 찾았으므로 카운트 증가 후 탐색 계속
			if (x === n - 1 && y === n - 1) {
				answer++;
				continue;
			}
			// dir 0 →, 1 ↓, 2 ↘ 각 경우에 대해
			// 0, 1의 경우 (1) 방향 유지 (2) 대각선 으로 이동 가능
			// 2의 경우 모든 방향으로 이동 가능하므로
			// 이동 가능한 방향을 iter 배열로 묶어 반복 탐색 진행
			const iter = dir === 0 ? [0, 2] : dir === 1 ? [1, 2] : [0, 1, 2];
			iter.forEach((nd) => {
				const [ny, nx] = [y + dy[nd], x + dx[nd]];
				// 다음 이동하려는 위치가 범위를 벗어나지 않고 벽이 없으면
				if (nx >= 0 && ny >= 0 && nx < n && ny < n && !graph[ny][nx])
					if (
						nd === 0 ||
						nd === 1 ||
						// 대각선 방향의 경우 추가적으로 주변 2 공간에도 벽이 없으면
						(nd === 2 && !graph[y + 1][x] && !graph[y][x + 1])
					)
						queue.push([[ny, nx], nd]); // 큐에 추가
			});
		}
		return answer;
	}
	console.log(bfs());
} */
