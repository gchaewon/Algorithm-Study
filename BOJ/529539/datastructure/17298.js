// 2025.02.20 풀이
// [스택] 오큰수
// https://www.acmicpc.net/problem/17298

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
	const arr = input[1].split(" ").map(Number);
	const answer = new Array(n).fill(-1);
	// 정방향 + 이중 for문 사용 시 최악의 경우 O(n^2)으로 시간 초과 발생
	// -> 역방향 + 스택을 사용하면 모든 요소에 대해 한번만 push/pop하여 O(n)
	let stack = [];
	// 뒤에서부터 순회, 탐색할 대상보다 큰 수만 남기면서 반복
	for (let i = n - 1; i >= 0; i--) {
		// 현재 수보다 작은 수는 스택에서 제거하여 오큰수 후보만 스택에 남김
		while (stack.length && stack[stack.length - 1] <= arr[i]) {
			stack.pop();
		}
		// 스택이 비어있지 않다면 가장 위에 있는 수가 오큰수
		// 업데이트 되지 않았다면 초기값 -1 유지됨
		if (stack.length) answer[i] = stack[stack.length - 1];
		// 현재 숫자를 스택에 추가
		stack.push(arr[i]);
	}
	console.log(answer.join(" "));
}
