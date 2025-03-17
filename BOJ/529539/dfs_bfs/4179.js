// 2025.03.17 풀이
// [BFS] 불!
// https://www.acmicpc.net/problem/4179

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
	const [r, c] = input.shift().split(" ").map(Number);
	let startPos = []; // 시작 위치 (1개)
	// 탈출을 위해 사용할 방문 배열, -1로 초기화
	const visited = Array.from(Array(r), () => Array(c).fill(-1));
	const firePos = []; // 처음 불이 난 위치 (0개 이상)
	// 불이 어느 시간대에 번졌는지 그 시간을 기록할 그래프, Infinity로 초기화
	const fireMap = Array.from(Array(r), () => Array(c).fill(Infinity));
	const graph = input.map((line, i) => {
		const arr = line.split("");
		arr.forEach((el, j) => {
			if (el === "F") {
				firePos.push([i, j]);
				fireMap[i][j] = 0; // 불이 난 초기 시점 0으로 설정
			} else if (el === "J") {
				startPos = [i, j];
				visited[i][j] = 0; // 시작 위치는 초기 시점 0으로 설정
			}
		});
		return arr;
	});
	const [sy, sx] = startPos;
	// 예외 처리
	if (sy === 0 || sy === r - 1 || sx === 0 || sx === c - 1) {
		console.log(1);
		return;
	}
	const dx = [0, 1, 0, -1];
	const dy = [1, 0, -1, 0];
	// 불에 대해 1번째 BFS 수행, 큐 새로 선언하지 않고 firePos 배열을 큐처럼 사용
	while (firePos.length) {
		const [y, x] = firePos.shift();
		for (let i = 0; i < 4; i++) {
			const [ny, nx] = [y + dy[i], x + dx[i]];
			// 범위 내에 있고, 벽이 아니고, 아직 방문하지 않은 곳(Infinity)이면
			if (ny >= 0 && nx >= 0 && ny < r && nx < c)
				if (graph[ny][nx] !== "#" && fireMap[ny][nx] === Infinity) {
					fireMap[ny][nx] = fireMap[y][x] + 1;
					firePos.push([ny, nx]);
				}
		}
	}
	let ans = Infinity; // 최소 시간을 카운트할 변수
	// 탈출 최단 경로에 대해 2번째 BFS 수행
	const queue = [startPos]; // 큐 선언하고 시작 위치 넣기
	while (queue.length > 0) {
		const [y, x] = queue.shift();
		for (let i = 0; i < 4; i++) {
			// 현재 위치 (y,x) 기준 다음으로 살펴볼 좌표와 시간대
			const [ny, nx] = [y + dy[i], x + dx[i]];
			const nextTime = visited[y][x] + 1;
			// 다음 방문 위치가 범위(미로) 밖이라면
			if (ny < 0 || nx < 0 || ny >= r || nx >= c) {
				// 찾은 시간과 기존 값을 비교하여 최솟값으로 업데이트
				ans = Math.min(ans, nextTime);
				continue; // 다른 방향도 탐색 필요
			}
			// 다음 방문 위치가 범위 내에 있지만 벽이거나, 불이거나, 이미 방문한 곳이거나,
			// 불이 번진 시점이 다음 방문할 시점보다 같거나 이전이라면 방문 불가
			if (
				graph[ny][nx] === "#" ||
				graph[ny][nx] === "F" ||
				visited[ny][nx] !== -1 ||
				fireMap[ny][nx] <= nextTime
			)
				continue;
			// 위 조건을 모두 통과하여 다음 위치로 방문 가능하다면 이동
			visited[ny][nx] = nextTime;
			queue.push([ny, nx]);
		}
	}
	// 경로를 발견하지 못했다면 불가능 출력
	console.log(ans === Infinity ? "IMPOSSIBLE" : ans);
}
