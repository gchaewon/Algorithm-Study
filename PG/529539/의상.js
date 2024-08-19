// 2024.08.16 풀이
// 의상
// https://school.programmers.co.kr/learn/courses/30/lessons/42578

const clothes = [
	["yellow_hat", "headgear"],
	["blue_sunglasses", "eyewear"],
	["green_turban", "headgear"],
];

function solution(clothes) {
	let result = 1;
	let category = {}; // 옷의 종류와 가짓수를 저장할 객체
	// clothes 배열을 순회하며 인덱스 1번의 종류 이름을 프로퍼티, 가짓수를 값으로 저장
	// 이미 저장된 종류라면 이전 값에 +1, 존재하지 않았다면 0에 +1
	clothes.forEach((v) => (category[v[1]] = (category[v[1]] || 0) + 1));
	// category 객체를 순회하며 각 가짓수에 1을 더한 경우의 수 누적곱
	// 1을 더하는 이유는 입지 않는 경우까지 포함하여 경우의 수를 고려한 것
	for (let v in category) result *= category[v] + 1;
	return result - 1; // 모두 입지 않는 경우 1가지 제외
}

console.log(solution(clothes));
