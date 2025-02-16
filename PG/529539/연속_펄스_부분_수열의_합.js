// 2025.02.15 풀이
// 연속 펄스 부분 수열의 합
// https://school.programmers.co.kr/learn/courses/30/lessons/161988

const sequence = [2, 3, -6, 1, 3, -1, 2, 4];

function solution(sequence) {
	const n = sequence.length;
	// 어떤 수를 사용했는지는 고려 사항 X, 누적합만을 dp를 이용해 저장
	let dp = Array.from(Array(n), () => new Array(2).fill(0));
	// 1 또는 -1로 시작하는 펄스 2가지 경우의 연산에 각각 사용하기 위해
	// 기존 값은 인덱스 0, 부호를 반전한 값은 인덱스 1에 2차원 배열로 함께 저장
	dp[0] = [sequence[0], -sequence[0]];
	// 연속 수열만 고려하므로 앞에서부터 차례대로 끊어 구하면 됨
	for (let i = 1; i < n; i++) {
		// 인덱스 [i-1, i, i+1] 기준으로
		// dp[i][0]은 [-1, 1, -1] / dp[i][1]은 [1, -1, 1] 펄스와 곱한 누적합
		// 최댓값을 만들기 위해서는 양수만을 더해야 한다는 점을 이용하여
		// 이전 값이 양수인 경우 합산에 채택
		// 음수인 경우 더하지 않고(0으로 취급) 누적합은 현재 값부터 새로 시작
		dp[i][0] = Math.max(dp[i - 1][1], 0) + sequence[i];
		dp[i][1] = Math.max(dp[i - 1][0], 0) - sequence[i]; // + (-1 * seq[i])
	}
	// 최종적으로 dp에 저장된 가장 큰 값이 곧 최대 누적합이 됨
	// dp에 있는 모든 요소 중 최댓값 찾아서 반환
	let answer = -Infinity; // 또는 Number.MIN_SAFE_INTEGER
	for (let i = 0; i < n; i++) {
		answer = Math.max(answer, dp[i][0], dp[i][1]);
	}
	return answer;
	/* 참고) dp 내부 배열의 두 수 비교 후 전체 dp에 대해 Math.max 호출하면
    ...dp의 인자 개수 = dp의 길이 n = sequence 최대 길이 50만으로
    실행 환경에 따라 콜 스택 사이즈 초과 에러 발생 가능성 높음
    -> 따라서 max의 경우 음의 무한대, min의 경우 양의 무한대를 저장한 값을
    함께 비교하며 업데이트하여 인자 개수를 줄여 사용 가능함
    시간 복잡도 : 3개의 인자 비교 O(3) * n번 반복 = O(n) */
}

console.log(solution(sequence));
