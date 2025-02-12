// 2024.09.26 풀이
// 크레인 인형뽑기 게임
// https://school.programmers.co.kr/learn/courses/30/lessons/64061

const board = [
	[0, 0, 0, 0, 0],
	[0, 0, 1, 0, 3],
	[0, 2, 5, 0, 1],
	[4, 2, 4, 4, 2],
	[3, 5, 1, 3, 1],
];
const moves = [1, 5, 3, 5, 1, 2, 1, 4];

function solution(board, moves) {
	let answer = 0;
	const lanes = Array.from({ length: board.length }, () => new Array());
	board.forEach((line) =>
		line.forEach((el, idx) => {
			if (el) {
				lanes[idx].push(el);
			}
		})
	);
	const stack = [];
	moves.forEach((lane) => {
		const curr = lanes[lane - 1].shift();
		if (curr) {
			if (stack.at(-1) === curr) {
				stack.pop();
				answer += 2;
			} else stack.push(curr);
		}
	});
	return answer;
}

console.log(solution(board, moves));
