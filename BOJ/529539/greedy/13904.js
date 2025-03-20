// 2025.03.20 풀이
// [그리디] 과제
// https://www.acmicpc.net/problem/13904

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
	let lastDay = 0;
	const arr = input
		.map((v) =>
			v.split(" ").map((el, idx) => {
				// 날짜인 경우 (인덱스 0) 최댓값으로 업데이트
				if (idx === 0) lastDay = Math.max(lastDay, el);
				return +el;
			})
		)
		.sort((a, b) => b[1] - a[1]); // 점수가 큰 것부터 내림차순 정렬
	const visited = new Array(n).fill(false); // 현재 과제 선택 여부를 저장할 배열
	let ans = 0; // 점수를 합산할 변수
	// 마지막 날짜부터 1일까지 반복
	// 점수가 높은 순으로 정렬했으므로 그리디로 수행 가능한 첫번째 과제 바로 선택
	// 거꾸로 마지막 날부터 선택해야 과제를 가장 많이 수행할 수 있음
	for (let day = lastDay; day >= 1; day--) {
		// 모든 과제에 대해
		for (let i = 0; i < n; i++) {
			// 아직 선택하지 않았고 마감일이 남아있어 수행 가능하다면
			if (!visited[i] && arr[i][0] >= day) {
				// 점수 누적, 방문 처리, 다음 날로 넘어감
				ans += arr[i][1];
				visited[i] = true;
				break;
			}
		}
	}
	console.log(ans);
}
