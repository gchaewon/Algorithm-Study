// 2025.02.16 풀이
// 베스트앨범
// https://school.programmers.co.kr/learn/courses/30/lessons/42579

const genres = ["classic", "pop", "classic", "classic", "pop"];
const plays = [500, 600, 150, 800, 2500];

function solution(genres, plays) {
	let answer = [];
	const dic = {};
	const count = genres.reduce((hash, currGenre, i) => {
		// hash = acc, 이전까지의 plays를 합산 중인 Map (장르 => sum of plays)
		// currGenre = curr, 순회 중인 genres 배열의 요소
		// dic의 구조는 { 장르: [ [i, plays], ... ] }
		dic[currGenre]
			? dic[currGenre].push([i, plays[i]])
			: (dic[currGenre] = [[i, plays[i]]]);
		return hash.set(
			currGenre,
			hash.get(currGenre) ? hash.get(currGenre) + plays[i] : plays[i]
		);
	}, new Map());
	// key => value 구조의 Map을 [key, value] 배열로 스프레드
	[...count]
		.sort((a, b) => b[1] - a[1]) // 장르 총 재생 수 정렬
		.forEach(
			(el) =>
				dic[el[0]] // 각 장르별 [i, plays] 배열에 대해
					.sort((c, d) => d[1] - c[1]) // 각 노래 재생 수 정렬
					.slice(0, 2) // 2개만 선택
					.forEach((el) => answer.push(el[0])) // 고유 번호만 정답 배열에 push
		);
	return answer;
}

console.log(solution(genres, plays));
