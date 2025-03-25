// 2025.03.17 풀이
// [BFS] 보물섬
// https://www.acmicpc.net/problem/2589

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
	const [row, col] = input.shift().split(" ").map(Number);
	const map = input.map((line) => line.split(""));
	const dx = [1, 0, -1, 0];
	const dy = [0, 1, 0, -1];
	function bfs(y, x) {
		const visited = Array.from(Array(row), () => Array(col).fill(0));
		const queue = [[y, x]];
		visited[y][x] = 1;
		let maxDist = 0;
		while (queue.length) {
			const [y, x] = queue.shift();
			for (let i = 0; i < 4; i++) {
				const [ny, nx] = [y + dy[i], x + dx[i]];
				if (ny >= 0 && nx >= 0 && ny < row && nx < col)
					if (visited[ny][nx] === 0 && map[ny][nx] === "L") {
						visited[ny][nx] = visited[y][x] + 1;
						maxDist = Math.max(maxDist, visited[ny][nx]);
						queue.push([ny, nx]);
					}
			}
		}
		return maxDist;
	}
	// 최대 길이를 구해야하므로 모든 가능한 정점에 대해 BFS+완탐
	let answer = 0;
	for (let i = 0; i < row; i++)
		for (let j = 0; j < col; j++) {
			if (map[i][j] === "L") answer = Math.max(answer, bfs(i, j));
		}
	console.log(answer - 1);
}
