// 2025.02.28 풀이
// 주사위 고르기
// https://school.programmers.co.kr/learn/courses/30/lessons/258709

// 알고리즘 : 재귀 조합 + 재귀 완탐 + 해시맵 (+ 이진탐색)
// +) 조합에 DFS도 사용 가능

const dice = [
	[40, 41, 42, 43, 44, 45],
	[43, 43, 42, 42, 41, 41],
	[1, 1, 80, 80, 80, 80],
	[70, 70, 1, 1, 70, 70],
];

// arr 배열에서 n개의 요소로 이루어진 모든 조합을 반환하는 함수
// (정해진 구현 방식 존재, 재귀 호출 사용)
function comb(arr, n) {
	// 1개의 요소로만 이루어진 조합은 모든 요소를 각각 배열로 묶은 것
	if (n === 1) return arr.map((el) => [el]);
	// 2개 이상일때
	const ret = [];
	arr.forEach((curr, idx) => {
		// 현재 값보다 뒤에 있는 나머지 요소들에 대해
		const rest = arr.slice(idx + 1);
		// curr를 제외한 n-1개 요소들의 조합 구하기
		const combinations = comb(rest, n - 1);
		// curr와 구해온 조합을 연결하여 반환할 조합 배열에 추가
		ret.push(...combinations.map((el) => [curr, ...el]));
	});
	return ret;
}

// 주사위들을 굴려 나올 수 있는 모든 합산값을 map 자료형에 저장하는 함수 (재귀 완탐)
// 중복되는 값을 제거하고 key: 합산 값, value: 등장 횟수 형식으로 관리
// 재귀 호출이므로 sum을 인자에서 누적시켜 더하고, 주사위 번호인 currNum을 증가시키며 탐색
function roll(dice, map, currNum, sum) {
	// 마지막 번호의 주사위라면
	if (currNum === dice.length) {
		// map에 이미 현재 sum이 있다면 기존값+1, 아니면 1을 저장
		map.set(sum, (map.get(sum) || 0) + 1);
		return;
	}
	// 모든 주사위에 대해
	for (let i = 0; i < 6; i++) {
		// dice 배열 내 모든 번호에 대해 6면 중 하나의 숫자를 골라 sum에 누적합
		// 6^dice.length 번 호출되며 모든 경우에 대한 완전탐색
		roll(dice, map, currNum + 1, sum + dice[currNum][i]);
	}
}

function solution(dice) {
	// 1. 주사위를 고르는 모든 조합 구하기

	// 각 주사위의 번호를 매기기 위한 배열 (0 ~ n-1)
	const diceNum = [...Array(dice.length)].map((_, i) => i);
	const combinations = comb(diceNum, dice.length / 2);

	// 2. 구한 모든 조합에 대해 최대 승리 횟수 찾기

	// 매 조합 반복 후 업데이트할 변수
	let bestComb = [];
	let maxWinCnt = 0;

	for (const currComb of combinations) {
		// 사용하는 주사위 숫자를 이용해 6면 숫자를 요소로 가지는 주사위 배열 가져오기
		const aDice = currComb.map((el) => dice[el]);
		// a와 매칭되는 b 조합을 계산 (a가 사용하지 않는 주사위만 사용)
		const bDice = diceNum
			.filter((num) => !currComb.includes(num))
			.map((el) => dice[el]);

		// 주사위를 굴려 가능한 모든 합산 값 구하여 map에 저장
		const aMap = new Map();
		const bMap = new Map();
		roll(aDice, aMap, 0, 0);
		roll(bDice, bMap, 0, 0);

		// 각각 a, b 주사위를 굴려 나온 합산들의 가능한 모든 조합에 대해
		// a가 이기는 경우에만 그 경우의 수를 누적시켜
		// 현재 a, b 주사위 조합에서 나올 수 있는 모든 승리 횟수 계산
		let currWinCnt = 0; // 현재 조합의 모든 승리 횟수를 누적하여 합산할 변수

		// (1) 이진탐색 시 O(logm)
		// (2) 단순 이중반복문 시 O(m^2) (이때 m은 6^n, n = dice.length)
		// 효율은 (1) > (2), 구현의 단순 정도는 (1) < (2)
		// (map 사용 시 둘다 통과하므로 2 추천)

		// [1 이진탐색] (upperBound 함수는 맨 아래에 선언함)
		// bMap을 정렬된 배열로 변환
		const bSums = [...bMap.keys()].sort((a, b) => a - b);
		// b의 누적합 배열
		const bPrefixSum = bSums.reduce((acc, curr) => {
			acc.push(
				acc.length > 0 ? acc[acc.length - 1] + bMap.get(curr) : bMap.get(curr)
			);
			return acc;
		}, []);
		// 모든 a의 합산값 조합에 대해
		for (const [aSum, aCnt] of aMap) {
			// b의 가능한 합산 값들 중 현재 a 주사위의 합산보다 처음으로 큰 값이 등장하는 인덱스 반환
			let idx = upperBound(bSums, aSum);
			// 찾았다면 해당 인덱스 이전까지의 누적합(=aSum보다 작은 모든 값을 더한 값)과
			// aCnt를 곱한 경우의수를 합산에 포함
			// (정렬 후 누적합을 계산했기 때문에 b의 승리 횟수 합산은 O(1)로 계산 가능)
			if (idx > 0) currWinCnt += aCnt * bPrefixSum[idx - 1];
		}

		// [2 완전탐색]
		// 모든 a, b의 합산값 조합에 대해 등장 횟수를 곱하여 경우의수 계산
		// for (const [aSum, aCnt] of aMap)
		// 	for (const [bSum, bCnt] of bMap)
		// 		if (aSum > bSum) currWinCnt += aCnt * bCnt;

		// 이전에 구했던 조합의 최대 승리 횟수보다 크다면 조합 업데이트
		if (currWinCnt > maxWinCnt) {
			maxWinCnt = currWinCnt;
			bestComb = currComb;
		}
	}
	// 주사위 번호를 0 ~ n-1로 매겼으므로 1을 더하여 반환
	return bestComb.map((el) => el + 1);
}

console.log(solution(dice));

/* +) 완탐으로 구현해도 Map을 사용하기 때문에 시간 초과는 안나지만
만약 Map을 사용하지 않고 모든 합산을 중복 포함 배열로 구했다면 이진탐색 사용 필수 */

// 이진 탐색 함수, arr에서 target보다 큰 첫번째 값의 인덱스 반환 (없다면 0)
function upperBound(arr, target) {
	let left = 0,
		right = arr.length;
	while (left < right) {
		let mid = Math.floor((left + right) / 2);
		// mid 값이 목표 값보다 작으면 오른쪽 구간 탐색 = 왼쪽 끝을 mid+1로
		if (arr[mid] < target) left = mid + 1;
		// mid 값이 목표 값보다 크면 왼쪽 구간 탐색 = 오른쪽 끝을 mid로
		else right = mid;
	}
	// left = mid + 1을 하므로 left가 target보다 큰 첫번째 값을 가르킴
	return left;
}
