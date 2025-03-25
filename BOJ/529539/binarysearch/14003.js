// 2025.03.20 풀이
// [이분탐색_LIS] 가장 긴 증가하는 부분 수열 5
// https://www.acmicpc.net/problem/14003

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
	const n = +input[0];
	const arr = input[1].split(" ").map(Number);
	const lis = [arr[0]]; // 오름차순을 유지하며 lis 후보를 저장할 배열
	const log = [[0, arr[0]]]; // 출력 역추적을 위해 [LIS 인덱스, 요소 값]을 저장할 배열
	for (let i = 1; i < n; i++) {
		// lis의 최댓값보다 현재 요소가 크면 맨뒤에 추가
		if (lis[lis.length - 1] < arr[i]) {
			lis.push(arr[i]);
			log.push([lis.length - 1, arr[i]]);
		} else {
			// 그렇지 않다면 lis 배열에 추가, 최적의 위치를 이분탐색(lower bound)으로 찾음
			// 기존 값(lis[idx])을 더 작은 값(arr[i])으로 대체해야 하므로
			// 타켓 값(arr[i])보다 크거나 같은 값 중 최소인 가장 왼쪽 값을 갱신해야함
			let left = 0;
			let right = lis.length;
			let mid;
			while (left < right) {
				mid = Math.floor((left + right) / 2);
				if (lis[mid] < arr[i]) left = mid + 1;
				else right = mid;
			}
			// lis 후보들을 작은 값으로 유지하여 더 긴 lis를 만들 수 있는 가능성을 높임
			lis[right] = arr[i];
			log.push([right, arr[i]]);
		}
	}
	console.log(lis.length);
	// 역추적 출력 로직
	const result = [];
	// log를 뒤에서부터 탐색하며 lis의 마지막부터 역추적해야 로그에 덮어씌워진 가장 최근 값만 선택 가능
	let idx = lis.length - 1;
	for (let i = n - 1; i >= 0; i--) {
		if (log[i][0] === idx) {
			result.push(log[i][1]);
			idx--;
		}
	}
	console.log(result.reverse().join(" "));
}
