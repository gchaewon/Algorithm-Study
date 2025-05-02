#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int n, m;
    string site, name;
    unordered_map<string, string> address;
    cin >> n >> m;

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (int i = 0; i < n; i++) {
        cin >> site >> name;
        address.insert({site, name});
    }

    for (int i = 0; i < m; i++) {
        cin >> site;
        cout << address[site] << "\n";
    }

    return 0;
}