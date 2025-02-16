// 2025.02.14 풀이
// 이중우선순위큐
// https://school.programmers.co.kr/learn/courses/30/lessons/42628

const operations = [
	"I -45",
	"I 653",
	"D 1",
	"I -642",
	"I 45",
	"I 97",
	"D 1",
	"D -1",
	"I 333",
];

function solution(operations) {
	const dq = [];
	operations.forEach((el) => {
		const [op, num] = el.split(" ");
		if (op === "D" && dq.length) {
			num === "1" ? dq.pop() : dq.shift();
		} else if (op === "I") {
			dq.push(parseInt(num));
			dq.sort((a, b) => a - b);
		}
	});
	return dq.length ? [dq[dq.length - 1], dq[0]] : [0, 0];
}

console.log(solution(operations));
