#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

unordered_map<string, vector<int>> combs; // {정보, {점수}}

vector<string> tokenizer(string s) {
    string temp = "";
    vector<string> tokens;

    for (auto c : s) {
        if (c == ' ') {
            if (temp != "and") {
                tokens.push_back(temp);
            }
            temp.clear();
            continue;
        }
        temp += c;
    }
    tokens.push_back(temp);
    return tokens;
}

void saveInfo(string s) {
    vector<string> langs = {"-"};
    vector<string> positions = {"-"};
    vector<string> careers = {"-"};
    vector<string> foods = {"-"};
    int score = 0;

    vector<string> tokens = tokenizer(s);

    langs.push_back(tokens[0]);
    positions.push_back(tokens[1]);
    careers.push_back(tokens[2]);
    foods.push_back(tokens[3]);
    score = stoi(tokens[4]);

    vector<string> comb;
    string temp = "";

    for (auto l : langs) {
        comb.push_back(l);

        for (auto p : positions) {
            comb.push_back(p);

            for (auto c : careers) {
                comb.push_back(c);

                for (auto f : foods) {
                    comb.push_back(f);

                    for (auto s : comb) {
                        temp += s;
                    }

                    combs[temp].push_back(score);
                    temp.clear();
                    comb.pop_back();
                }
                comb.pop_back();
            }
            comb.pop_back();
        }
        comb.pop_back();
    }
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;

    for (auto i : info) {
        saveInfo(i);
    }

    for (auto &comb : combs) {
        sort(comb.second.begin(), comb.second.end());
    }

    for (auto q : query) {
        vector<string> tokens = tokenizer(q);
        int score = stoi(tokens[4]);
        string str = "";
        for (int i = 0; i < tokens.size() - 1; i++) {
            str += tokens[i];
        }

        int cnt = combs[str].end() -
                  lower_bound(combs[str].begin(), combs[str].end(), score);
        answer.push_back(cnt);
    }

    return answer;
}