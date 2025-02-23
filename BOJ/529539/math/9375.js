// 2025.02.14 풀이
// [수학] 패션왕 신해빈
// https://www.acmicpc.net/problem/9375

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
	const k = +input.shift();
	for (let i = 0; i < k; i++) {
		const n = +input.shift();
		let clothes = {}; // { type: 개수 }
		for (let j = 0; j < n; j++) {
			const [name, type] = input.shift().split(" ");
			clothes[type] ? clothes[type]++ : (clothes[type] = 1);
		}
		// 객체를 1차원 배열로 변형
		const arr = Object.values(clothes);
		// 종류가 하나뿐이면 해당 의상 개수만 출력
		if (arr.length === 1) console.log(arr[0]);
		else
			console.log(
				arr.reduce((acc, curr) => {
					// 현재 종류의 의상이 여러 개면 그 중 하나를 선택하거나(가짓수) 모두 입지 않는다(+1) n+1의 경우의 수를 곱함
					if (curr > 1) return acc * (curr + 1);
					// 현재 종류의 가짓수가 1이면 입는다/입지 않는다 2가지 경우의 수만 곱함
					else return acc * 2;
				}, 1) - 1 // 모두 입지 않은 경우의 수 1 제외
			);
	}
}
