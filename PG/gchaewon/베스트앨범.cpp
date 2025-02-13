#include <bits/stdc++.h>
using namespace std;

bool cmp1(pair<int, int> &a, pair<int, int> &b) {
    if (a.second == b.second) {
        return a.first < b.first; // 고유 번호 오름차순
    }
    return a.second > b.second; // 재생 횟수 내림차순
}

bool cmp2(pair<string, int> &a, pair<string, int> &b) {
    return a.second > b.second; // 재생 횟수 합 내림차순
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> ans;
    map<string, vector<pair<int, int>>> m1; // 장르별 (고유번호, 재생횟수) 저장
    map<string, int> m2;                    // 장르별 재생횟수 합 저장

    // 장르별 음악 저장, 재생횟수 합 저장
    for (int i = 0; i < genres.size(); i++) {
        string genre = genres[i];
        int play = plays[i];
        if (m1.find(genre) != m1.end()) {
            m1[genre].push_back({i, play});
            m2[genre] += play;
        } else {
            m1.insert({genre, {{i, play}}});
            m2.insert({genre, play});
        }
    }

    // 장르별 재생횟수 합 내림차순으로 정렬
    vector<pair<string, int>> temp(m2.begin(), m2.end());
    sort(temp.begin(), temp.end(), cmp2);

    for (auto t : temp) {
        string genre = t.first;
        vector<pair<int, int>> songs = m1[genre];
        // 장르 내 정렬
        sort(songs.begin(), songs.end(), cmp1);

        // 2번째 곡까지 추가
        for (int i = 0; i < songs.size() && i < 2; i++) {
            ans.push_back(songs[i].first);
        }
    }
    return ans;
}