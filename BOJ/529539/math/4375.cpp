#include <iostream>

using namespace std;

int main()
{
    int n;
    while (cin >> n)
    {
        int k = 1, answer = 1;
        while (1)
        {
            if (k % n == 0)
                break;
            else
            {
                k = k * 10 + 1;
                k %= n;
                answer++;
            }
        }
        cout << answer << "\n";
    }
}