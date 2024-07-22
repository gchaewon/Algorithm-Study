// 2024.07.18 풀이
// 등굣길
// https://school.programmers.co.kr/learn/courses/30/lessons/42898

const m = 4;
const n = 3;
const puddles = [[2, 2]];

function solution(m, n, puddles) {
	// m = 열, n = 행, 패딩 1 추가
	const dp = Array(n + 1)
		.fill()
		.map((_) => new Array(m + 1).fill(0));
	// 물이 잠긴 지역은 -1 저장
	for (const [x, y] of puddles) dp[y][x] = -1;
	dp[1][1] = 1; // 시작점
	// 모든 좌표에 대해 반복
	// 오른쪽/아래쪽만 이동 가능하므로 단순 +1 순회로 계산
	for (let i = 1; i <= n; i++) {
		for (let j = 1; j <= m; j++) {
			if (i === 1 && j === 1) continue; // 시작점 스킵
			// 만약 갈 수 없는 곳이 아니라면
			if (dp[i][j] !== -1)
				dp[i][j] =
					// 왼쪽 칸을 지날 수 없었다면 0, 있었다면 이전까지의 경로 개수
					((dp[i - 1][j] === -1 ? 0 : dp[i - 1][j]) +
						// + 위쪽 칸을 지날 수 없었다면 0, 있었다면 이전까지의 경로 개수 더하기
						(dp[i][j - 1] === -1 ? 0 : dp[i][j - 1])) %
					1000000007; // 나머지만 저장하여 효율성 개선
		}
	}
	return dp[n][m];
}

console.log(solution(m, n, puddles));
