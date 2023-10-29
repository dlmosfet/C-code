#include <iostream> // 包含標準輸入輸出庫
#include <algorithm> // 包含算法庫
#include <cstring> // 包含字串庫

using namespace std; // 使用 std 命名空間

int main() {
    char a[10] = {' '}; // 宣告一個長度為 10 的字串陣列 a
    char b[10] = {' '}; // 宣告一個長度為 10 的字串陣列 b

    while (cin >> a >> b) { // 讀取兩個字串 a 和 b
        if (strcmp(a, "bye") == 0 || strcmp(b, "bye") == 0) { // 如果 a 或 b 等於 "bye"，則跳出迴圈
            break;
        }

        int len = max(strlen(a), strlen(b)); // 計算 a 和 b 的最大長度

        for (int i = 0; i < len; i++) { // 遍歷 a 和 b 的所有字元
            char char_a = (i >= strlen(a)) ? 0 : a[i]; // 如果 i 大於或等於 a 的長度，則將 char_a 設為 0，否則將 char_a 設為 a[i]
            char char_b = (i >= strlen(b)) ? 0 : b[i]; // 如果 i 大於或等於 b 的長度，則將 char_b 設為 0，否則將 char_b 設為 b[i]

            cout << int(char_a) - int(char_b) << ' '; // 輸出 char_a 和 char_b 的差值，並跟隨一個空格
        }

        cout << endl; // 換行
    }

    return 0;
}
