// 2025.03.20 풀이
// 징검다리 건너기
// https://school.programmers.co.kr/learn/courses/30/lessons/64062

// 알고리즘 : 이분탐색
// 결과에 최소/최대가 정해져 있고 그 사이 적정값을 찾아야 함, 최대 2억 -> 이분탐색

const stones = [7, 2, 8, 7, 2, 5, 9];
const k = 3;

function solution(stones, k) {
	let left = 0,
		right = 200000000;
	// 최대 인원 lower bound 이분탐색으로 구하기
	while (left < right) {
		// 건너갈 수 있는 최대 인원을 의미
		const mid = Math.floor((left + right) / 2);
		let jump = 0; // 연속되는 0 이하의 사용이 끝난 돌 개수, 즉 점프한 돌 수 저장
		let flag = true; // 건널 수 없어 반복문 종료된 경우 false
		for (const item of stones) {
			// 각 징검다리에서 mid만큼 사용 횟수를 뺐을 때 0보다 작거나 같다면 점프
			// 중간에 하나라도 밟을 수 있는 돌이 있다면 연속 X이므로 0으로 초기화
			jump = item - mid <= 0 ? jump + 1 : 0;
			// k개의 연속되는 0 이하의 돌이 발생했다면
			if (jump === k) {
				flag = false;
				break;
			}
			// 끝까지 건널 수 있었다면 flag는 true
		}
		// 현재 인원수에서 모두 건널 수 있었으므로 인원수 증가 (하한선 증가)
		if (flag) left = mid + 1;
		// 현재 인원수에서 건널 수 없는 경우가 있었으므로 인원수 감소 (상한선 감소)
		else right = mid;
	}
	return right;
}

console.log(solution(stones, k));
