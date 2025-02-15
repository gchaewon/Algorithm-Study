// 2025.02.15 풀이
// [투포인터] 부분합
// https://www.acmicpc.net/problem/1806

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
	const [n, target] = input[0].split(" ").map(Number);
	const arr = input[1].split(" ").map(Number);
	let left = 0,
		right = 0;
	let sum = arr[0];
	let len = n + 1; // 길이는 n보다 길어질 수 없으므로 최댓값 저장
	// 초기 상태는 두 포인터 모두 idx 0, sum = arr[0]만 포함
	while (left <= right && right < n) {
		if (sum < target) {
			// sum을 증가시키기 위해 오른쪽 포인터 이동 후 해당 값 합산
			sum += arr[++right];
			/* 참고) 전위연산자 때문에 반복문 종료 전 right가 n이 되어 범위를 벗어나
            arr[n] = undefined가 더해지기 때문에 sum이 NaN이 됨
            right를 먼저 증가시킨 이후 검사하여 break 할 수도 있지만 필수는 X */
		} else {
			// 문제 조건이 '이상'이므로 sum이 더 큰 경우에도 부분합을 찾은(==) 것과 동일
			// 만족하는 부분합이므로 길이를 업데이트, 단 최솟값으로만
			len = Math.min(len, right - left + 1);
			// 최소 길이를 찾기 위해 왼쪽 포인터 값 제외 후 포인터 이동
			sum -= arr[left++];
			/* 이때 오른쪽 포인터를 감소시키는 것을 고려하지 않는 이유는
            애초에 둘다 0에서부터 오른쪽 방향으로 움직이며 탐색했기 때문에
            왼쪽 방향으로는 이미 탐색이 완료된 경우임을 알 수 있음 */
		}
	}
	// len이 업데이트 되지 않았다면 부분합을 찾을 수 없었던 것임으로 0 반환
	console.log(len === n + 1 ? 0 : len);
}
