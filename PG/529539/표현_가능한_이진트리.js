// 2025.03.01 풀이
// 표현 가능한 이진트리
// https://school.programmers.co.kr/learn/courses/30/lessons/150367

// 알고리즘 : 분할정복

const numbers = [5, 42, 128];

function draw(str) {
	// 1) 길이가 1인 트리는 루트 노드만 있으므로 그릴 수 있는 트리
	// 2) 부모 노드가 0이고 자식 노드들도 모두 0이면 그릴 수 있는 트리
	if (str.length === 1 || !str.includes("1")) return 1;
	const midIdx = Math.floor(str.length / 2); // 부모 노드
	const leftStr = str.slice(0, midIdx); // 왼쪽 자식 트리
	const rightStr = str.slice(midIdx + 1); // 오른쪽 자식 트리
	// 부모 노드가 0이지만 자식 트리에 1이 있으면 불가능
	if (str[midIdx] === "0" && (leftStr.includes("1") || rightStr.includes("1")))
		return 0;
	// 부모 노드가 1이고, 양쪽 서브트리도 가능하다면 1
	if (str[midIdx] === "1") return draw(leftStr) && draw(rightStr) ? 1 : 0;
}

function solution(numbers) {
	const answer = [];
	numbers.forEach((num) => {
		let string = num.toString(2);
		// 1. 이진수 문자열을 포화 이진트리로 만들기
		// 포화 이진트리의 노드 수인 가장 가까운 2^k - 1이 될때까지 0 추가
		let n = 1; // n = 2^k
		// 원래 이진수 길이보다 큰 첫번째 2^k - 1을 찾으면 반복문 종료
		while (n - 1 < string.length) n *= 2;
		// 길이가 2^k - 1이 될때까지 문자열의 앞에 0을 추가
		while (string.length < n - 1) string = "0" + string;
		// 2. 만든 포화 이진트리를 분할정복하며 트리를 그릴 수 있는지 검사
		answer.push(draw(string));
	});
	return answer;
}

console.log(solution(numbers));
