// 2025.03.20 풀이
// [이분탐색_LIS] 가장 긴 증가하는 부분 수열 2
// https://www.acmicpc.net/problem/12015

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
	// arr에서 target 값이 들어가야할 최적의 위치(가장 왼쪽) 인덱스 리턴 (lower bound)
	function binarySearch(arr, target) {
		let start = 0;
		let end = arr.length;
		while (start < end) {
			let mid = Math.floor((start + end) / 2);
			if (arr[mid] < target) start = mid + 1;
			else end = mid;
		}
		return end;
	}
	const lis = [arr[0]]; // 오름차순을 유지하며 lis 후보를 저장할 배열
	for (let i = 1; i < n; i++) {
		// lis의 최댓값보다 현재 요소가 크면 맨뒤에 추가
		if (lis[lis.length - 1] < arr[i]) lis.push(arr[i]);
		else {
			// 그렇지 않다면 lis 배열에 추가, 최적의 위치를 이분탐색으로 찾음
			// 기존 값(lis[idx])을 더 작은 값(arr[i])으로 대체해야 하므로
			// 타켓 값(arr[i])보다 크거나 같은 값 중 최소인 가장 왼쪽 값을 갱신해야함
			let idx = binarySearch(lis, arr[i]);
			lis[idx] = arr[i];
			// lis 후보들을 작은 값으로 유지하여 더 긴 lis를 만들 수 있는 가능성을 높임
		}
	}
	console.log(lis.length);
}
