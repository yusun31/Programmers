#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer(commands.size());

    for (int i = 0; i < commands.size(); i++) {
        int cnt = commands[i][1] - commands[i][0] + 1;
        vector<int> tmp(cnt);
        for (int j = commands[i][0] - 1; j < commands[i][1]; j++) {
            int k = 0;
            tmp[k] = array[j];
            sort(tmp.begin(), tmp.end());
        }
        answer[i] = tmp[commands[i][2] - 1];
    }


    return answer;
}