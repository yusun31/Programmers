#include <iostream>
#include <vector>
using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer(2);

    int c = 0;
    int cnt = 0;
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            if (lottos[i] == win_nums[j]) {
                cnt++;
            }
        }
        if (lottos[i] == 0) {
            c++;
        }
    }

    int k = cnt + c;
    for (int i = 1; i <= 6; i++) {
        if (k == i) {
            answer[0] = 6 - k + 1;
        }
        else if (k == 0) {
            answer[0] = 6;
        }
        if (cnt == i) {
            answer[1] = 6 - cnt + 1;
        }
        else if (cnt == 0) {
            answer[1] = 6;
        }
    }
    return answer;
}