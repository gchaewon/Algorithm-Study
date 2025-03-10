// 2025.03.09 풀이
// [백트래킹] 치킨 배달
// https://www.acmicpc.net/problem/15686

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
	const [n, m] = input.shift().split(" ").map(Number);
	const chicken = [],
		house = [];
	input.forEach((line, i) =>
		line.split(" ").map((el, j) => {
			if (+el === 2) chicken.push([i, j]);
			else if (+el === 1) house.push([i, j]);
		})
	);
	// 전체 치킨집 중 사용할 m개의 치킨집만 저장할 배열
	const usedChicken = [];
	// 최소가 되는 치킨거리를 업데이트할 변수
	let answer = Infinity;
	// m개의 치킨집을 선택하는 조합의 경우를 재귀함수+백트래킹으로 완탐
	function recursion(currIdx) {
		// m개의 치킨집을 모두 조합했다면
		if (usedChicken.length === m) {
			// 도시의 치킨거리 합을 완탐으로 구하기 (최대 100*13)
			let sum = 0;
			// 모든 집에 대해
			house.forEach(([y, x]) => {
				let dist = Infinity;
				usedChicken.forEach(([cy, cx], idx) => {
					// 사용된 치킨집과 현재 집의 거리 계산하여 최소인 경우에만 업데이트
					dist = Math.min(dist, Math.abs(x - cx) + Math.abs(y - cy));
				});
				// 가장 가까운 치킨거리를 도시 치킨거리에 합산
				sum += dist;
			});
			// 기존에 저장된 값과 비교하여 최소인 경우 업데이트
			answer = Math.min(answer, sum);
			// console.log("-update", answer);
			return;
		}
		// 0번부터 시작하여 모든 조합에 대해 탐색하므로 1씩 증가하는 반복문으로 조합
		for (let i = currIdx; i < chicken.length; i++) {
			usedChicken.push(chicken[i]);
			// console.log(currIdx, i, usedChicken);
			recursion(i + 1);
			// 조합이 끝나 return 되어 재귀 호출이 끝났다면 직전에 사용한 치킨집 없애서 원복
			usedChicken.pop();
			// 다음 반복문에서 +1한 인덱스의 치킨집을 넣은 조합으로 탐색 계속
		}
	}
	// 0번 치킨집부터 재귀 호출 시작
	recursion(0);
	console.log(answer);
}
