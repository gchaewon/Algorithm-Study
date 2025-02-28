// 2025.02.28 풀이
// n + 1 카드게임
// https://school.programmers.co.kr/learn/courses/30/lessons/258707

const coin = 6;
const cards = [1, 6, 2, 5, 3, 4];

function solution(coin, cards) {
	const n = cards.length;
	let arr = cards.splice(0, n / 3);
	// 뽑은 카드를 저장해둘 배열, 카드 사용 여부를 라운드마다 바로 정하지 않고
	// 저장해두었다가 미래에 한번에 판단 + coin 지불도 그때 진행
	let keep = [];
	let round = 0;
	// 동전을 가장 적게 사용하는 방법을 우선적으로 찾아서 라운드 진행
	// 0 - 이미 갖고있는 arr 2장 사용
	// 1 - arr 1 + keep 1
	// 2 - keep 2
	// n+1을 만들 수 없거나, 카드를 다 썼다면 종료
	while (cards.length) {
		// 2장의 카드를 뽑아 일단 keep에 저장
		const curr = cards.splice(0, 2);
		curr.forEach((el) => keep.push(el));
		// 현재 라운드에서 합이 n+1이 되는 숫자쌍을 찾아 저장할 변수
		let pair = undefined;
		// 1. coin 0개를 소모하여 만드는 방법
		for (const num of arr)
			if (arr.includes(n + 1 - num)) {
				pair = [num, n + 1 - num];
				break;
			}
		if (pair) {
			arr = arr.filter((el) => !pair.includes(el));
			// console.log(0, arr, pair, keep);
			round++;
			continue;
		}
		// 2. coin 1개를 소모하여 만드는 방법
		pair = undefined; // 같은 변수 사용하므로 초기화
		for (const num of keep)
			if (arr.includes(n + 1 - num)) {
				pair = [num, n + 1 - num];
				break;
			}
		if (pair && coin) {
			const [kNum, aNum] = pair;
			keep = keep.filter((el) => el !== kNum);
			arr = arr.filter((el) => el !== aNum);
			coin--;
			// console.log(1, arr, pair, keep);
			round++;
			continue;
		}
		// 3. coin 2개를 소모하여 만드는 방법
		pair = undefined;
		for (const num of keep)
			if (keep.includes(n + 1 - num)) {
				pair = [num, n + 1 - num];
				break;
			}
		if (pair && coin >= 2) {
			keep = keep.filter((el) => !pair.includes(el));
			coin -= 2;
			// console.log(2, arr, pair, keep);
			round++;
			continue;
		}
		// 4. 모든 경우를 만족하지 못해 라운드 종료
		break;
	}
	return round + 1;
	/* 문제 조건 자체가 카드를 낼 수 없는 경우 종료
    즉 처음으로 실패한 라운드를 의미하므로 마지막 라운드에 대해 +1 해줘야 함
	이때 반복문 내에서 맨 처음 줄이나 break 윗줄에 round++를 추가하면
	반례 존재 : 6, [1, 6 / 2, 5, 3, 4] 기댓값 3 결과 2
	위와 같이 카드를 남기지 않고 모두 바로 사용하는 경우
	코드 실행 순서는 코인을 적게 사용하는 [1,6]부터 소모하지만
    실제로는 [2,5] [3,4] [1,6] 순서대로 사용되므로
    마지막 유효한 라운드에 도달하기 전 카드가 전부 소모되어 반복문 종료됨
    때문에 이런 엣지케이스를 커버하기 위해 반복문 내에서는 카드를 낼 수 있었던 라운드만 증가시키고
    반복문 바깥에서 마지막 종료 라운드에 대한 처리를 해야함 */
}

console.log(solution(coin, cards));
