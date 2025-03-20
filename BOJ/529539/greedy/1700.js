// 2025.03.20 풀이
// [그리디] 멀티탭 스케줄링
// https://www.acmicpc.net/problem/1700

const fs = require("fs");
const readline = require("readline");
const rl = readline.createInterface(
	process.platform === "linux"
		? { input: process.stdin, output: process.stdout }
		: { input: fs.createReadStream("./input.txt"), output: null }
);
let input = [];
rl.on("line", function (line) {
	input.push(line);
}).on("close", function () {
	solution(input);
	process.exit();
});

function solution(input) {
	const [[n, k], arr] = input.map((v) => v.split(" ").map(Number));
	// 사용하는 가전보다 멀티탭 개수가 더 많으면 뽑지 않아도 되므로 바로 0 리턴 후 종료
	if (n >= k) {
		console.log(0);
		return;
	}
	let cnt = 0;
	let used = []; // 사용 중인 번호를 저장할 배열
	// 그리디 + 조건별 분기 + 선택 기준 (= 가장 먼곳에 등장)
	for (let i = 0; i < k; i++) {
		// 이미 사용 중이라면 동작 필요 X
		if (used.includes(arr[i])) continue;
		// 사용할 자리가 남아있다면 사용
		if (used.length < n) used.push(arr[i]);
		else {
			// 자리가 없다면 하나 제거하고 사용해야함
			cnt++; // 콘센트를 빼는 동작 카운트 증가
			let maxIdx = -1; // 가장 나중에 사용되는 기기의 인덱스를 찾아 저장
			let targetNum = 0; // 삭제할 번호 (요소) 저장
			used.forEach((v) => {
				// 사용 중인 배열에서 각 요소 v가 현재 시점(i) 이후로
				// 처음 다시 등장하는 시점(j)를 찾아 nextIdx에 저장
				let nextIdx = Infinity;
				for (let j = i + 1; j < k; j++) {
					if (arr[j] === v) {
						nextIdx = j;
						break;
					}
				}
				// 찾은 인덱스가 더 나중이라면 큰 값으로 업데이트
				if (maxIdx < nextIdx) {
					maxIdx = nextIdx;
					targetNum = v;
				}
			});
			// 찾은 요소를 제외하고 현재 번호를 넣고 다음 번호에 대해 반복
			used = used.filter((el) => el !== targetNum);
			used.push(arr[i]);
		}
	}
	console.log(cnt);
}
