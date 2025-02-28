// 2025.02.28 풀이
// 산 모양 타일링
// https://school.programmers.co.kr/learn/courses/30/lessons/258705

const n = 4;
const tops = [1, 1, 0, 1];

function solution(n, tops) {
	const MOD = 10007;
	const dp1 = new Array(n).fill(0);
	const dp2 = new Array(n).fill(0);
	dp1[0] = 1; // tops 값과 상관없이 모두 1가지
	dp2[0] = 2 + tops[0]; // tops가 0이면 2가지, 1이면 3가지
	for (let i = 0; i < n - 1; i++) {
		dp1[i + 1] = (dp1[i] + dp2[i]) % MOD;
		dp2[i + 1] =
			(dp1[i] * (1 + tops[i + 1]) + dp2[i] * (2 + tops[i + 1])) % MOD;
	}
	return (dp1[n - 1] + dp2[n - 1]) % MOD;
}

console.log(solution(n, tops));
