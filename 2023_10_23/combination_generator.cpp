#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <bitset>

using namespace std;

struct Combination {
    int m; // 選擇數
    vector<string> items; // 選擇的物品

    Combination(int m, vector<string> items) : m(m), items(items) {}

    // 比較兩個組合，選擇數較少或選擇物品順序較前面的組合較小
    bool operator<(const Combination& other) const {
        if (m != other.m) {
            return m < other.m;
        } else {
            return items < other.items;
        }
    }
};

// 產生所有可能的組合
void generate_combinations(const vector<string>& items, int m) {
    // 宣告全域變數 i，用來記錄選擇狀態
    int i = 0;

    // 計算物品總數
    int n = items.size();

    // 宣告一個 vector 來儲存所有可能的組合
    vector<Combination> combinations;

    // 遍歷所有選擇狀態
    for (i = 0; i < (1 << n); ++i) {
        // 宣告一個 vector 來儲存每個選擇狀態下的物品
        vector<string> selected;

        // 遍歷每個選擇狀態下的物品
        for (int j = 0; j < n; ++j) {
            // 如果該物品被選擇
            if (i & (1 << j)) {
                // 將該物品加入 selected
                selected.push_back(items[j]);
            }
        }

        // 將 selected 加入 combinations
        combinations.push_back(Combination(selected.size(), selected));
    }

    // 將 combinations 依照選擇數和物品順序排序
    sort(combinations.begin(), combinations.end());

    // 輸出所有可能的組合
    for (const auto& combination : combinations) {
        // 如果組合是空的
        if (combination.items.empty()) {
            // 輸出 "empty"
            cout << "empty" << endl;
        } else {
            // 輸出組合中的物品
            for (const string& item : combination.items) {
                cout << item;
                if (combination.items.size() - 1 > i) {
                    cout << " ";
                }
            }
            // 換行
            cout << endl;
        }
    }
}

// 主函式
int main() {
    // 不斷地輸入一組資料，直到輸入資料的 m 小於等於 0 時結束程式
    while (true) {
        // 輸入 m
        int m;
        cin >> m;

        // 如果 m 小於等於 0，結束程式
        if (m <= 0) {
            break;
        }

        // 宣告一個 vector 來儲存物品名稱
        vector<string> item_names;

        // 輸入 m 個物品名稱
        for (int i = 0; i < m; ++i) {
            // 輸入一個物品名稱
            string item_name;
            cin >> item_name;

            // 將物品名稱加入 item_names
            item_names.push_back(item_name);
        }

        // 排序 item_names
        sort(item_names.begin(), item_names.end());

        // 產生所有可能的組合
        generate_combinations(item_names, m);
    }

    return 0;
}
