// 2025.03.01 풀이
// 도넛과 막대 그래프
// https://school.programmers.co.kr/learn/courses/30/lessons/258711

const edges = [
	[2, 3],
	[4, 3],
	[1, 1],
	[2, 1],
];

function solution(edges) {
	// 노드: [진입 차수, 진출 차수] 구조의 map 생성
	const graph = edges.reduce((map, key) => {
		// key[0] -> key[1] 이므로 0에 등장하면 outDeg++, 1에 등장하면 inDeg++
		if (!map.has(key[0])) map.set(key[0], [0, 1]);
		else {
			const [inDeg, outDeg] = map.get(key[0]);
			map.set(key[0], [inDeg, outDeg + 1]);
		}
		if (!map.has(key[1])) map.set(key[1], [1, 0]);
		else {
			const [inDeg, outDeg] = map.get(key[1]);
			map.set(key[1], [inDeg + 1, outDeg]);
		}
		return map;
	}, new Map());
	// 각 그래프 개수를 셀 배열
	let answer = new Array(4).fill(0);
	for (const [key, io] of graph) {
		const [inDeg, outDeg] = io;
		// 1. 루트 노드 : 진입 차수 0, 진출 차수 2 이상인 노드
		if (inDeg === 0 && outDeg >= 2) answer[0] = key;
		// 2. 막대 : 더이상 그래프를 탐색할 수 없는 진출 차수 0 노드 존재
		else if (outDeg === 0) answer[2]++;
		// 3. 8자 : 중앙 노드가 진입 차수, 진출 차수 모두 2 이상
		else if (inDeg >= 2 && outDeg >= 2) answer[3]++;
	}
	// 4. 도넛 : 탐색을 시작한 노드로 돌아옴
	// 차수로는 판별 불가능하지만, 루트 노드가 모든 그래프와 연결되어 있다는 조건 존재
	// = 루트 노드의 진출 차수에서 나머지 모든 그래프 개수를 빼면 됨
	answer[1] = graph.get(answer[0])[1] - answer[2] - answer[3];
	return answer;
}

console.log(solution(edges));
