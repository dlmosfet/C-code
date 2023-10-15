#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int main() {
    char a[10] = {' '};
    char b[10] = {' '};
    
    while (cin >> a >> b) {
        if (strcmp(a, "bye") == 0 || strcmp(b, "bye") == 0) {
            break;
        }

        int len = max(strlen(a), strlen(b));
        for (int i = 0; i < len; i++) {
            char char_a = (i >= strlen(a)) ? 0 : a[i];
            char char_b = (i >= strlen(b)) ? 0 : b[i];
            cout << int(char_a) - int(char_b) << ' ';
        }
        cout << endl;
    }

    return 0;
}
