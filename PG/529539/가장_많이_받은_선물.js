// 2024.09.27 풀이
// 가장 많이 받은 선물
// https://school.programmers.co.kr/learn/courses/30/lessons/258712

const friends = ["joy", "brad", "alessandro", "conan", "david"];
const gifts = [
	"alessandro brad",
	"alessandro joy",
	"alessandro conan",
	"david alessandro",
	"alessandro david",
];

function solution(friends, gifts) {
	const n = friends.length;
	// 이름에 따른 인덱스를 저장할 객체
	const index = {};
	friends.forEach((name, idx) => {
		index[name] = idx;
	});
	// 두 사람이 서로 선물을 주고 받은 횟수를 저장할 2차원 배열
	const record = Array.from(Array(n), () => Array(n).fill(0));
	// 선물 기록 저장 및 선물 지수 계산
	const giftPoints = new Array(n).fill(0);
	gifts.forEach((gift) => {
		const [giver, taker] = gift.split(" ");
		record[index[giver]][index[taker]]++;
		giftPoints[index[giver]]++;
		giftPoints[index[taker]]--;
	});
	// 다음 달 받게 될 선물 계산
	const points = new Array(n).fill(0);
	for (let i = 0; i < n; i++) {
		for (let j = 0; j < n; j++) {
			// i가 준 횟수가 더 많으면 i가 받음
			if (record[i][j] > record[j][i]) {
				points[i]++;
			} else if (record[i][j] === record[j][i]) {
				// 주고 받은 횟수가 같은 경우 선물 지수가 더 큰 쪽이 받음
				if (giftPoints[i] > giftPoints[j]) {
					points[i]++;
				}
			}
		}
	}
	// 최대 선물 개수를 출력
	return Math.max(...points);
}

console.log(solution(friends, gifts));
