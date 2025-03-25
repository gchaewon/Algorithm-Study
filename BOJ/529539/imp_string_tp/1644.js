// 2025.03.20 풀이
// [투포인터] 소수의 연속합
// https://www.acmicpc.net/problem/1644

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
	// 에라토스테네스의 체로 n 이하 모든 소수 구하기
	const primes = [];
	// 0, 1은 false, 2~n번 인덱스는 true인 배열
	const check = new Array(n + 1).fill(true).fill(false, 0, 2);
	// i를 2 ~ 루트 n까지 반복
	for (let i = 2; i * i <= n; i++)
		// 아직 걸러지지 않은 수 중 n보다 작은 모든 i의 배수 거르기
		if (check[i]) for (let j = i * i; j <= n; j += i) check[j] = false;
	// 걸러지고 남은 소수만 저장
	for (let i = 2; i <= n; i++) if (check[i]) primes.push(i);
	// 투포인터로 연속된 소수의 구간합 구하기
	let sum = 0, // 구간합 합산할 변수
		cnt = 0; // n과 일치하는 구간합을 찾은 개수를 셀 변수
	// 왼, 오 포인터 모두 0에서 시작하여 오른쪽 포인터를 늘리고
	// 목표 값보다 커지는 순간 왼쪽 포인터를 옮기며 줄여서 일치 시도
	let left = 0;
	for (let right = 0; right < primes.length; right++) {
		sum += primes[right];
		while (sum > n) {
			sum -= primes[left];
			left++;
		}
		if (sum === n) cnt++;
	}
	console.log(cnt);
}
