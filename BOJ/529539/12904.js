// 2025.02.16 풀이
// [문자열_그리디] A와 B
// https://www.acmicpc.net/problem/12904

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
	const [s, t] = input;
	let tmp = t.split("");
	// 두 단어의 길이 차이만큼만 연산 반복
	for (let i = 0; i < t.length - s.length; i++) {
		// 두 연산 모두 뒤에 추가하는 작업을 공통 포함하므로 반대로 역연산하여
		// 맨뒤 요소를 제거하고 B의 경우 뒤집으며 돌아가기
		if (tmp.at(-1) === "A") tmp.pop();
		else if (tmp.at(-1) === "B") {
			tmp.pop();
			tmp.reverse();
		}
	}
	// 단순 그리디로 수행한 결과가 동일하면 수행 가능, 다르면 달성 불가능
	console.log(tmp.join("") === s ? 1 : 0);
}
