// 2025.02.24 풀이
// [백트래킹] 부등호
// https://www.acmicpc.net/problem/2529

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
	const n = +input[0];
	const arr = input[1].split(" ");
	// 0~9까지 숫자의 사용 여부를 저장할 배열
	const used = new Array(10).fill(false);
	// 배치할 숫자를 순서대로 저장할 배열
	const stack = [];
	// 최댓값과 최솟값만 저장하기 위해 비교하여 업데이트
	let maxNum = "0";
	let minNum = "9876543210";
	// 재귀를 통해 구현
	function recursion() {
		// 모든 숫자를 다 채워 완성한 경우
		if (stack.length === n + 1) {
			// 숫자를 이어 문자열로 만들고
			const numStr = stack.join("");
			// 최댓값 또는 최솟값과 비교하여 업데이트가 필요하면 수행
			if (maxNum < numStr) maxNum = numStr;
			if (minNum > numStr) minNum = numStr;
			// 탐색 종료
			return;
		}
		// 0~9까지 숫자에 대해 반복
		for (let i = 0; i <= 9; i++) {
			// 이미 사용된 숫자라면 탐색을 멈추고 다음 탐색 진행
			if (used[i]) continue;
			// 다음으로 사용할 부등호 추출
			const sign = arr[stack.length - 1];
			// 현재 숫자와 직전에 사용한 숫자의 대소 관계와 추출한 부등호가 일치하지 않으면
			if (
				(sign === ">" && stack.at(-1) < i) ||
				(sign === "<" && stack.at(-1) > i)
			)
				continue; // 현재 숫자에 대한 탐색을 멈추고 다음 탐색 진행
			// 위 조건식을 통과하여 부등호를 만족하는 경우 해당 숫자 사용
			used[i] = true;
			stack.push(i);
			recursion();
			// 다음 탐색을 위해 원복 필수
			stack.pop();
			used[i] = false;
		}
	}
	// 첫번째 숫자 지정하여 스택에 넣고 재귀 함수 호출
	for (let i = 0; i <= 9; i++) {
		used[i] = true;
		stack.push(i);
		recursion();
		stack.pop();
		used[i] = false;
	}
	console.log(maxNum);
	console.log(minNum);
}
