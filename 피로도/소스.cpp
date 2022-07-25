#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;

    vector<int> size(dungeons.size());
    for (int i = 0; i < size.size(); i++) {
        size[i] = i;
    }

    //     vector<vector<int>> vec;
    //     do {
    //         vec.push_back(size);
    //     } while (next_permutation(size.begin(), size.end()));

    //     for (int i = 0; i < vec.size(); i++) {
    //         for (int j = 0; j < vec[i].size(); j++) {
    //             cout << vec[i][j] << " ";
    //         }
    //         cout << endl;
    //     }

    do {
        int ans = 0;
        int k2 = k;
        for (int i = 0; i < size.size(); i++) {
            if (k2 >= dungeons[size[i]][0]) {
                k2 -= dungeons[size[i]][1];
                ans++;
            }
        }
        if (ans > answer) answer = ans;
    } while (next_permutation(size.begin(), size.end()));

    return answer;
}