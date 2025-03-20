// 2025.03.20 풀이
// 입국심사
// https://school.programmers.co.kr/learn/courses/30/lessons/43238

// 알고리즘 : 이분탐색
// 최댓값(10^18)을 계산할 수 있으므로 알맞은 값 이분 탐색으로 구하기

const n = 6;
const times = [7, 10];

function solution(n, times) {
	times.sort((a, b) => a - b);
	// 소요 시간의 최댓값은 인원수 n * 최대 소요 시간 (정렬했으므로 끝값)
	// 모든 사람이 완료할 수 있는 시간의 최솟값을 lower bound 이분 탐색으로 구하기
	let left = 0,
		right = times[times.length - 1] * n; // 또는 그냥 1e18로도 가능
	while (left < right) {
		// 모든 사람이 완료할 수 있는 최소 시간을 의미
		const mid = Math.floor((left + right) / 2);
		let sum = 0;
		// 현재 시간(mid)까지 모든 검사대별 심사 완료 가능한 인원수 합산
		// 전체 소요 시간 mid / 한 사람당 소요 시간 times[i] 내림
		for (let i = 0; i < times.length; i++) sum += Math.floor(mid / times[i]);
		// 타겟 값인 n명보다 작으면 더 많은 시간이 필요하므로 하한선 증가
		if (sum < n) left = mid + 1;
		// 타겟 값인 n명보다 크거나 같으면 최솟값을 찾기 위해 상한선 감소
		else right = mid;
	}
	// left와 right가 교차되어 최적의 값을 찾았다면 리턴
	return right;
}

console.log(solution(input));
