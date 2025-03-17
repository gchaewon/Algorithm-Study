// 2025.03.17 풀이
// [백트래킹] 사다리 조작
// https://www.acmicpc.net/problem/15684

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
	const [n, m, h] = input.shift().split(" ").map(Number);
	const graph = Array.from(Array(h + 1), () => Array(n + 1).fill(0));
	input.map((line) => {
		const [y, x] = line.split(" ");
		graph[y][x] = 1;
	});
	let ladCnt = 0;
	let ans = Infinity;
	function recursion(currH, currN, num) {
		// 지정한 사다리 개수만큼 다 놓았다면
		if (num === ladCnt) {
			// 각 세로선에 대해 탐색하여 돌아올 수 있는지 검사
			for (let col = 1; col < n + 1; col++) {
				let start = col;
				for (let row = 1; row < h + 1; row++) {
					if (graph[row][start]) start++;
					else if (graph[row][start - 1]) start--;
				}
				// 하나라도 돌아올 수 없다면 불가능
				if (start !== col) return;
			}
			// 모든 세로선이 조건을 만족한다면 찾은 사다리 개수가 최솟값일때 업데이트
			ans = Math.min(ans, num);
			return;
		}
		// 만약 다음 높이에 대해 탐색한다면 세로선 번호는 1번으로 초기화하여 탐색
		// 그렇지 않고 매개변수로 받은 같은 높이 내에서 탐색 중일 때는
		// 세로선 번호도 매개변수로 받아온 이후로만 탐색하여 불필요한 중복 탐색 줄이기
		for (let i = currH; i < h + 1; i++, currN = 1)
			for (let j = currN; j < n; j++) {
				if (graph[i][j - 1] || graph[i][j] || graph[i][j + 1]) continue;
				graph[i][j] = 1;
				recursion(i, j, num + 1);
				graph[i][j] = 0;
			}
	}
	// 최소로 사다리를 놓으며 조건을 만족할 수 있는지 0~3번 수행
	for (let i = 0; i <= 3; i++) {
		ladCnt = i;
		recursion(1, 1, 0);
		if (ans !== Infinity) break;
	}
	// 만족하는 최솟값이 있었다면 출력, 없으면 -1 출력
	console.log(ans === Infinity ? -1 : ans);
}
