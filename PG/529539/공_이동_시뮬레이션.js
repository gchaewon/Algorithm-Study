// 2024.07.12 풀이
// 공 이동 시뮬레이션
// https://school.programmers.co.kr/learn/courses/30/lessons/87391

const n = 2,
	m = 2,
	x = 0,
	y = 0;
const queries = [
	[2, 1],
	[0, 1],
	[1, 1],
	[0, 1],
	[2, 1],
];

function solution(n, m, x, y, queries) {
	// 쿼리의 방향 종류
	const LEFT = 0,
		RIGHT = 1,
		UP = 2,
		DOWN = 3;
	// 시작점의 범위를 지정하는 4개의 꼭짓점 좌표 변수
	let startX = y,
		endX = y;
	let startY = x,
		endY = x;
	// 명령을 역순으로 추적하여 시작 지점으로 유도
	for (let i = queries.length - 1; i >= 0; i--) {
		const [direction, distance] = queries[i];
		// 각 명령어 방향에 대해
		if (direction === LEFT) {
			// 왼쪽 범위 끝이 벽이 아니라면 이동만큼 범위를 우측으로 조정
			if (startX !== 0) startX += distance;
			// 좌측 이동의 반대만큼 범위를 우측으로 조정
			endX += distance;
			// 만약 범위 밖이라면 벽에 부딪힌 n-1 상태로 둠
			if (endX > m - 1) endX = m - 1;
		} else if (direction === RIGHT) {
			// 우측 이동의 반대만큼 범위를 좌측으로 조정
			startX -= distance;
			// 만약 범위 밖이라면 벽에 부딪힌 0 상태로 둠
			if (startX < 0) startX = 0;
			// 우측 범위 끝이 벽이 아니라면 이동만큼 범위를 좌측으로 조정
			if (endX !== m - 1) endX -= distance;
		} else if (direction === UP) {
			// 위쪽 범위 끝이 벽이 아니라면 이동만큼 범위를 아래로 조정
			if (startY !== 0) startY += distance;
			// 위쪽 이동의 반대만큼 범위를 아래로 조정
			endY += distance;
			// 만약 범위 밖이라면 벽에 부딪힌 n-1 상태로 둠
			if (endY > n - 1) endY = n - 1;
		} else if (direction === DOWN) {
			// 아래 이동의 반대만큼 범위를 위로 조정
			startY -= distance;
			// 만약 범위 밖이라면 벽에 부딪힌 0 상태로 둠
			if (startY < 0) startY = 0;
			// 아래쪽 범위 끝이 벽이 아니라면 이동만큼 범위를 위로 조정
			if (endY !== n - 1) endY -= distance;
		}
		// 시작점 범위가 벽을 벗어났거나, 범위가 1 미만인 경우
		if (
			startY > n - 1 ||
			endY < 0 ||
			startX > m - 1 ||
			endX < 0 ||
			startY > endY ||
			startX > endX
		) {
			// 가능한 시작점이 없으므로 0을 반환하며 종료
			return 0;
		}
	}
	// 시작점 범위의 가로 길이와 세로 길이를 곱한 값이 가능한 점의 개수
	return BigInt(endY - startY + 1) * BigInt(endX - startX + 1);
}

console.log(solution(n, m, x, y, queries));
