// 2024.09.26 풀이
// [구현] 팰린드롬 만들기
// https://www.acmicpc.net/problem/1213

const fs = require("fs");
const path = "./input.txt";

const readline = require("readline");
const rl = readline.createInterface({
	// input: process.stdin,
	input: fs.createReadStream(path),
	output: process.stdout,
});

let input = [];

rl.on("line", function (line) {
	input.push(line);
}).on("close", function () {
	solution(input);
	process.exit();
});

function solution(input) {
	const arr = [];
	input[0]
		.split("")
		.sort()
		.map((el) => {
			// 각 문자의 아스키코드를 인덱스로 하여 빈도수 저장
			const x = el.charCodeAt();
			arr[x] = arr[x] ? arr[x] + 1 : 1;
		});
	// 만약 홀수 번 등장하는 문자가 2개 이상이라면
	if (arr.filter((el) => el % 2 != 0).length > 1)
		console.log("I'm Sorry Hansoo");
	else {
		let [front, middle] = [[], ""];
		arr.map((el, idx) => {
			if (el) {
				let cnt = el;
				// 등장한 문자라면 아스키코드를 문자로 원복
				const char = String.fromCharCode(idx);
				// 홀수 번 등장했다면 중앙에 넣음
				if (cnt % 2 != 0) {
					middle = char;
					cnt--;
				}
				while (cnt > 0) {
					front.push(char);
					cnt -= 2;
				}
			}
		});
		console.log(front.join("") + middle + front.reverse().join(""));
	}
}
