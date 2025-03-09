// 2025.03.09 풀이
// 표 병합
// https://school.programmers.co.kr/learn/courses/30/lessons/150366

// 알고리즘 : Union Find 또는 크기 제한이 50이므로 완탐+구현도 가능

const commands = [
	"UPDATE 1 1 a",
	"UPDATE 1 2 b",
	"UPDATE 2 1 c",
	"UPDATE 2 2 d",
	"MERGE 1 1 1 2",
	"MERGE 2 2 2 1",
	"MERGE 2 1 1 1",
	"PRINT 1 1",
	"UNMERGE 2 2",
	"PRINT 1 1",
];

function solution(commands) {
	let answer = [];
	// 각 셀의 값을 저장할 배열
	const cells = [...Array(51)].map((_) => Array(51).fill(""));
	// 현재 셀의 부모 셀을 저장할 배열, 초기 상태는 모두 부모가 자기자신
	const parent = [...Array(51)].map((_, i) =>
		[...Array(51)].map((_, j) => [i, j])
	);
	for (const currCom of commands) {
		const [com, ...rest] = currCom.split(" ");
		switch (com) {
			case "UPDATE":
				if (rest.length === 3) update(rest);
				else replace(rest);
				break;
			case "MERGE":
				merge(rest);
				break;
			case "UNMERGE":
				unmerge(rest);
				break;
			case "PRINT":
				// 출력할 셀의 부모 셀을 찾고 값이 있다면 그 값을, 없다면 EMPTY 출력
				const [r, c] = find(rest);
				answer.push(cells[r][c] || "EMPTY");
				break;
		}
	}
	// console.log(parent.map((line) => line.slice(0, 5)).slice(0, 5));
	return answer;

	/* 경로 압축 사용하기 때문에 부모를 찾을 때 find([i, j]) === parent[i, j]
    find 함수 없이 모든 곳에서 parent[i, j]를 사용하면
    t.c.21 실행시간 3328.91ms -> 1831.30ms로 단축 가능 */

	// 부모 좌표를 찾는 함수
	function find(cell) {
		const [r, c] = cell;
		// 부모가 자기자신이면, 즉 더이상 부모가 없으면 그대로 리턴
		if ([r, c].toString() === parent[r][c].toString())
			return [parseInt(r), parseInt(c)];
		// 아니라면 더는 부모가 없을때까지 재귀 호출
		// 경로 압축 사용하여 루트 부모 노드 값만 사용
		parent[r][c] = find(parent[r][c]);
		return parent[r][c];
	}
	// 두 셀을 합치는 함수
	function merge(cell) {
		const [r1, c1, r2, c2] = cell;
		const [pr1, pc1] = find([r1, c1]); // 병합의 기준이 되는 셀
		const [pr2, pc2] = find([r2, c2]); // 병합될 셀
		// 두 셀이 이미 같은 셀일 경우 무시
		if ([pr1, pc1].toString() === [pr2, pc2].toString()) return;
		for (let i = 0; i < 51; i++)
			for (let j = 0; j < 51; j++) {
				// 병합 시에도 경로 압축 사용, 기준 셀로 하위의 모든 셀의 부모 변경
				// 병합될 셀을 부모로 가지는 모든 셀(자신 포함)의 부모를 기준 셀로 변경
				if ([pr2, pc2].toString() === find([i, j]).toString())
					parent[i][j] = [pr1, pc1];
				// 기준 셀의 값으로 병합될 셀의 값 변경
				if ([pr1, pc1].toString() === find([i, j]).toString())
					cells[i][j] = cells[pr1][pc1] || cells[pr2][pc2];
			}
	}
	// 두 셀을 병합 해제하는 함수
	function unmerge(cell) {
		const [r, c] = cell;
		const [pr, pc] = find([r, c]);
		const value = cells[pr][pc];
		for (let i = 0; i < 51; i++)
			for (let j = 0; j < 51; j++)
				// 병합 해제하고자 하는 셀의 부모 좌표와 부모 좌표가 같은 모든 셀에 대해
				if ([pr, pc].toString() === find([i, j]).toString()) {
					// 값 및 부모 좌표 초기화
					cells[i][j] = "";
					parent[i][j] = [i, j];
				}
		cells[r][c] = value;
	}
	// 값을 업데이트하는 함수 1 - 특정 셀의 값 갱신
	function update(cell) {
		const [r, c, value] = cell;
		const [pr, pc] = find([r, c]);
		// 모든 셀을 순회하며
		for (let i = 0; i < 51; i++)
			for (let j = 0; j < 51; j++)
				// 바꾸고자 하는 셀의 부모 좌표와 부모 좌표가 같은 모든 셀에 대해
				if ([pr, pc].toString() === find([i, j]).toString()) {
					// 업데이트 수행
					cells[i][j] = value;
				}
	}
	// 값을 업데이트하는 함수 2 - 특정 값의 셀 갱신
	function replace(values) {
		const [from, to] = values;
		// 모든 셀을 순회하며
		for (let i = 0; i < 51; i++)
			for (let j = 0; j < 51; j++)
				// 변경 대상 값을 가진 모든 셀을 업데이트
				if (cells[i][j] === from) cells[i][j] = to;
	}
}

console.log(solution(commands));
