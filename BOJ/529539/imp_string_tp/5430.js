// 2025.02.14 풀이
// [문자열] AC
// https://www.acmicpc.net/problem/5430

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
	const t = +input.shift();
	for (let i = 0; i < t; i++) {
		const command = input.shift().split("");
		const n = +input.shift();
		const arrString = input.shift();
		const arr =
			n === 0
				? []
				: arrString
						.slice(1, arrString.length - 1)
						.split(",")
						.map(Number);
		// R 연산마다 매번 reverse 진행 시 시간 초과 발생
		// -> 불리언 값을 바꿔가며 연산 방향을 변경하는 방식으로 접근
		// false = 정방향, 왼쪽 시작, shift (기존 연산)
		// true = 역방향, 오른쪽 시작, pop (리버스 연산)
		let reverse = false;
		// 수행 결과가 []인 경우와 에러인 경우 구별하기 위해 필요
		let error = false;
		for (let j = 0; j < command.length; j++) {
			const com = command[j];
			if (com === "R") reverse = !reverse;
			else {
				if (arr.length) {
					if (reverse) arr.pop();
					else arr.shift();
				} else {
					// 빈 배열에서 D 연산 시 에러 발생 후 반복문 종료
					error = true;
					break;
				}
			}
		}
		reverse && arr.reverse(); // dir에 따라 마지막으로 방향 전환
		console.log(error ? "error" : `[${arr.join(",")}]`);
	}
}
