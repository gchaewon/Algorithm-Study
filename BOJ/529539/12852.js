// 2024.07.03 풀이
// [DP] 1로 만들기 2
// https://www.acmicpc.net/problem/12852

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
	const n = +input[0];
	// 1. top-down (494956KB 2064ms - 비효율적)
	// 2차원 배열 첫번째 요소에 연산 횟수, 두번째 요소에 연산 과정 배열 저장
	// 인덱스 0 사용 x, 연산 횟수가 각각 1은 0번, 2 & 3은 1번
	let dp = [0, [0, [1]], [1, [2, 1]], [1, [3, 1]]];
	// 4부터 차례대로 dp 배열 계산
	for (let i = 4; i <= n; i++) {
		// 단순 뺴기 1 연산 먼저 계산하여 저장
		// 직전 연산 횟수 + 1, 현재 숫자와 이전 dp 연산 결과 배열 잇기
		dp[i] = [dp[i - 1][0] + 1, [i, ...dp[i - 1][1]]];
		// 여부에 따라 (i // 3)의 계산 수 + 1 값과 원래 값 중 작은 값을 택하는 방식
		// 3으로 나누어 떨어지면서 해당 방법이 더 횟수가 적다면
		// 즉, 3으로 나눈 수에 대한 dp에 저장된 횟수 + 1 (나누기 3) 값이
		// 위에서 계산한 기존 방법 (빼기 1) 보다 작다면 선택
		if (i % 3 === 0 && dp[i / 3][0] + 1 < dp[i][0]) {
			// 이 방법이 더 연산 횟수가 적으므로 dp 업데이트
			dp[i] = [dp[i / 3][0] + 1, [i, ...dp[i / 3][1]]];
		}
		// 2로 나누어 떨어질 때도 위와 마찬가지
		if (i % 2 === 0 && dp[i / 2][0] + 1 < dp[i][0]) {
			dp[i] = [dp[i / 2][0] + 1, [i, ...dp[i / 2][1]]];
		}
	}
	console.log(dp[n][0]);
	console.log(dp[n][1].join(" "));

	// 2. bottom-up (64924KB 288ms)
	let DP = new Array(n + 1).fill(0);
	function f(n) {
		// console.log(n, DP);
		if (DP[n] != 0) return DP[n];
		if (n === 1) return 0;
		let answer = Infinity;
		if (n % 3 === 0) {
			answer = Math.min(answer, f(Math.floor(n / 3)) + 1);
		}
		if (n % 2 === 0) {
			answer = Math.min(answer, f(Math.floor(n / 2)) + 1);
		}
		answer = Math.min(answer, f(n - 1) + 1);
		DP[n] = answer;
		return answer;
	}
	f(n);
	console.log(DP[n]); // 최소 연산 횟수
	// 구한 최소 연산 횟수와 n으로 실제 연산 수행하여 출력 생성
	let result = DP[n];
	let curr = n;
	let answer = ""; // 과정을 저장할 문자열
	while (curr >= 1) {
		answer += `${curr} `; // 문자열에 현재 숫자 추가
		if (curr === 1) break; // 1인 경우 예외 처리
		result--; // 연산 1번 수행한 것으로 차감
		if (DP[curr - 1] === result) curr--; // 직전 dp와 같다면 빼기 1 연산
		else if (curr % 2 === 0 && DP[Math.floor(curr / 2)] === result)
			curr = Math.floor(curr / 2); // 2로 나눈 숫자의 dp와 같다면 나누기 2 연산
		else if (curr % 3 === 0 && DP[Math.floor(curr / 3)] === result)
			curr = Math.floor(curr / 3); // 3으로 나눈 숫자의 dp와 같다면 나누기 3 연산
	}
	console.log(answer.slice(0, -1)); // 마지막 공백 제거
}
