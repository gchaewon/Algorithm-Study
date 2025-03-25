// 2025.03.19 풀이
// [DFS_백트래킹] 알파벳
// https://www.acmicpc.net/problem/1987

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
	const graph = input.map((line) => line.split(""));
	// 알파벳 사용 시 true를 저장할 객체, 시작점 알파벳 사용한 것으로 표시
	// 따로 좌표별 visited 배열은 사용하지 않고 알파벳만 고려해도 이미 지나온 위치 방문 X
	const alphabet = {};
	alphabet[graph[0][0]] = true;
	const dy = [1, 0, -1, 0];
	const dx = [0, 1, 0, -1];
	let ans = 0; // 최장거리 저장
	// 가장 멀리까지 도달할 수 있는 정점 탐색이므로 DFS, 매개변수 cnt로 거리 카운트
	function dfs(y, x, cnt) {
		ans = Math.max(ans, cnt); // 최댓값일 때만 업데이트
		for (let i = 0; i < 4; i++) {
			const [ny, nx] = [y + dy[i], x + dx[i]];
			// 범위 내에 있고 아직 사용한 적 없는 알파벳이라면
			if (nx >= 0 && nx < c && ny >= 0 && ny < r && !alphabet[graph[ny][nx]]) {
				// 사용하고 탐색 계속
				alphabet[graph[ny][nx]] = true;
				dfs(ny, nx, cnt + 1);
				// 위 경로에 대한 탐색 종료 후 원복 필요
				alphabet[graph[ny][nx]] = false;
			}
		}
	}
	dfs(0, 0, 1);
	console.log(ans);
}
