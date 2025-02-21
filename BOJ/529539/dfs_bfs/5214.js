// 2025.02.21 풀이
// [BFS] 환승
// https://www.acmicpc.net/problem/5214

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
	const [n, k, m] = input.shift().split(" ").map(Number);
	// 역의 개수가 많기 때문에 입력을 인접행렬이나 인접리스트로 표현하려고 하면 시간 초과 발생
	// 1~n번 역에 각각 연결된 하이퍼튜브 인덱스 저장
	const station = Array.from(Array(n + 1), () => []);
	// 하이퍼튜브가 연결하는 모든 역을 저장 (string)
	const hypertube = input.map((line, idx) => {
		const arr = line.split(" ").map(Number);
		arr.forEach((el) => station[el].push(idx));
		return arr;
	});
	let visited = new Array(n + 1).fill(0);
	// 최단거리를 구하므로 너비우선탐색 사용
	function bfs() {
		// 1번 역부터 n번 역까지 탐색 진행 예정
		const queue = [1];
		visited[1] = 1;
		while (queue.length) {
			const currSt = queue.shift();
			// 현재 탐색 중인 역에 연결된 모든 역에 대해
			station[currSt].forEach((id) =>
				hypertube[id].forEach((nextSt) => {
					// 아직 방문하지 않은 역이면 (하이퍼튜브에는 자기 자신도 포함되므로 조건 추가 필요)
					if (nextSt !== currSt && !visited[nextSt]) {
						// 방문 표시 + 최단거리 기록하고 큐에 저장하여 탐색 계속
						visited[nextSt] = visited[currSt] + 1;
						queue.push(nextSt);
					}
				})
			);
		}
		// 도달할 수 없어 0으로 남아있다면 -1 반환
		return visited[n] ? visited[n] : -1;
	}
	console.log(bfs());
}
