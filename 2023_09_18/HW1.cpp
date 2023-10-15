#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int reverse(int num) {
    int result = num % 10;
    while(num /= 10) {
        result = result * 10 + num % 10;
    }
    return result;
}

int main() {
    int a, b;
    while(cin >> a >> b and a != -1 and b != -1) {
		float ans = sqrt(reverse(a - b));
        if(isnormal(ans)) printf("%.2f\n", ans);
        else printf("Error\n");
    }
    return 0;
}