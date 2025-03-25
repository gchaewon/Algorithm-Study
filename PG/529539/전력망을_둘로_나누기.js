// 2025.03.19 풀이
// 전력망을 둘로 나누기
// https://school.programmers.co.kr/learn/courses/30/lessons/86971

// 알고리즘 : 완탐 + DFS(연결 컴포넌트)

const n = 9;
const wires = [
	[1, 3],
	[2, 3],
	[3, 4],
	[4, 5],
	[4, 6],
	[4, 7],
	[7, 8],
	[7, 9],
];

function solution(n, wires) {
	const map = Array.from(Array(n + 1), () => []);
	wires.forEach((v) => {
		map[v[0]].push(v[1]);
		map[v[1]].push(v[0]);
	});
	let visited = new Array(n + 1).fill(false);
	// 어떤 노드에 대해 연결된 모든 노드 탐색 후 전체 노드 개수를 반환하는 함수
	function dfs(node, cnt) {
		visited[node] = true;
		// 현재 노드에 연결된 모든 노드에 대해
		for (let i = 0; i < map[node].length; i++)
			// 이 연결된 노드에 아직 방문하지 않았다면 방문, cnt 증가
			if (!visited[map[node][i]]) cnt = dfs(map[node][i], cnt + 1);
		return cnt;
	}
	let ans = Infinity; // 최솟값 업데이트할 변수
	// 모든 전선에 대해 끊고 두 전력망의 크기 차이 중 최솟값 찾기 (완탐)
	for (let i = 0; i < wires.length; i++) {
		visited = visited.map((_) => false); // 초기화
		// 현재 전선에 연결된 두 노드를 방문한 것을 처리하여 전선 끊기
		// 연결 리스트 초기화 시 시간 복잡도 크기 때문에 visited를 조작하여 구현
		visited[wires[i][0]] = true;
		visited[wires[i][1]] = true;
		// 두 노드에 대해 dfs 수행한 전체 연결 컴포넌트 노드 수의 차이를 계산하여 최솟값만 업데이트
		ans = Math.min(ans, Math.abs(dfs(wires[i][0], 0) - dfs(wires[i][1], 0)));
	}
	return ans;
}

console.log(solution(n, wires));
