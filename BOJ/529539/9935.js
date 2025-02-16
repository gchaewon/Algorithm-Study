// 2025.02.16 풀이
// [문자열_스택] 문자열 폭발
// https://www.acmicpc.net/problem/9935

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
	const [str, bomb] = [input[0].split(""), input[1]];
	let tmp = [];
	for (const char of str) {
		tmp.push(char);
		// 탐색 중인 범위의 길이가 폭발 문자열보다 짧은 경우 생략
		if (tmp.length < bomb.length) continue;
		// 배열의 뒤에서부터 가장 최근에 탐색한 위치에서부터 폭발 문자열만큼의 길이를 비교
		if (tmp.slice(-bomb.length).join("") === bomb) {
			// O(n)인 splice보다 더 빨리 O(1)의 속도로
			// 배열의 뒤에서부터 길이를 줄여 요소 삭제 가능
			tmp.length -= bomb.length;
		}
		/* 참고) 처음 접근했던 방식 (메모리 초과)
        tmp = [...tmp.slice(0, idx), ...tmp.slice(idx + bomb.length)];
        위와 같이 새로운 배열을 복사, 재할당하면
        최악의 경우 매 반복마다 최대 제한 크기의 배열이 할당됨 (n^2)
        -> 스택을 이용하여 탐색 중인 범위만 고려하면 n만으로도 수행 가능
        배열에 대한 slice 연산은 최대한 줄여 시간복잡도를 O(n)에 가깝게 유지 */
	}
	console.log(tmp.length ? tmp.join("") : "FRULA");
}
