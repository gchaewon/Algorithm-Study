#include <iostream>

using namespace std;

int main() {
    string str;
    string reversed = "";
    cin >> str;

    for (int i = str.length() - 1; i >= 0; i--) {
        reversed += str[i];
    }

    if (str == reversed) {
        cout << 1;
    } else {
        cout << 0;
    }
    return 0;
}