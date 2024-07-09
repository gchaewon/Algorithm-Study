// 2024.07.04 풀이
// N으로 표현
// https://school.programmers.co.kr/learn/courses/30/lessons/42895

const N = 5;
const number = 12;

function solution(N, number) {
	// 사용 횟수는 8 이하이므로 길이 9의 배열 생성
	// 이때 사칙연산으로 만들 수 있는 숫자 조합을 중복 없이 저장하기 위해 빈 집합을 요소로 추가
	// (fill 0을 하는 이유는 비어있지 않아야 map 순회하며 집합으로 대치 가능하기 때문)
	const dp = new Array(9).fill(0).map((el) => new Set());
	// 가능한 최소 사용 횟수 1~8에 대해 dp 계산 반복
	for (let i = 1; i < 9; i++) {
		// 1. concat 하여 만들 수 있는 숫자
		// N을 i번 반복한 수를 집합에 추가 (e.g., 9/99/999)
		dp[i].add("1".repeat(i) * N);
		// 2. 만든 숫자에 대해 가능한 모든 사칙연산 수행
		for (let j = 1; j < i; j++) {
			// 중첩 반복문으로 i에 대해 가능한 모든 j와 i-j 조합으로 사칙연산 수행
			for (const arg1 of dp[j]) {
				for (const arg2 of dp[i - j]) {
					dp[i].add(arg1 + arg2);
					dp[i].add(arg1 - arg2);
					dp[i].add(arg1 * arg2);
					dp[i].add((arg1 / arg2) >> 0); // 소수점 제거 (floor)
				}
			}
		}
		// 계산한 dp 중에 만들어야 하는 타겟 숫자가 존재하면 해당 연산 횟수 반환 후 반복 종료
		if (dp[i].has(number)) return i;
		// 없었다면 다음 반복 횟수인 ++i로 dp 계산 계속
	}
	// 8보다 크면 -1 반환
	return -1;
}

console.log(solution(N, number));
