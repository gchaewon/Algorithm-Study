#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(int N, int number)
{

    set<int> dp[8];

    int only_n = 0;
    for (int i = 0; i < 8; i++)
    {
        only_n = 10 * only_n + N;
        dp[i].insert(only_n);
    }
    // dp[i] = dp[i - 1] + dp[i - j - 1]
    for (int i = 1; i < 8; i++)
    {
        for (int j = 0; j < i; j++)
        {
            for (int a : dp[j])
            {
                for (int b : dp[i - j - 1])
                {
                    dp[i].insert(a + b);
                    dp[i].insert(a - b);
                    dp[i].insert(a * b);
                    if (b != 0)
                        dp[i].insert(a / b);
                }
            }
        }
    }

    int answer = -1;

    for (int i = 0; i < 8; i++)
    {
        if (dp[i].count(number))
        {
            answer = i + 1;
            break;
        }
    }

    return answer;
}