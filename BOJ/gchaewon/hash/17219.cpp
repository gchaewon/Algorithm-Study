#include <iostream>
#include <map>
using namespace std;

int main() {
    int n, m;
    string site, name;
    map<string, string> address;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> site >> name;
        address[site] = name;
    }

    for (int i = 0; i < m; i++) {
        cin >> site;
        cout << address[site] << "\n";
    }

    return 0;
}