// 程式名稱：reverse_and_sqrt

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

// 反轉一個數字
int reverse(int num) {
    int result = num % 10;
    while (num /= 10) {
        result = result * 10 + num % 10;
    }
    return result;
}

int main() {
    int a, b;
    while (cin >> a >> b and a != -1 and b != -1) {
        // 計算 a - b 的平方根
        float ans = sqrt(reverse(a - b));

        // 如果平方根是非正常數，則輸出錯誤資訊
        if (!isnormal(ans)) {
            cout << "Error\n";
        } else {
            // 輸出平方根，保留兩位小數
            cout << fixed << setprecision(2) << ans << endl;
        }
    }

    return 0;
}
