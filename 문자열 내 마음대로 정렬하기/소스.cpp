#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer(strings.size());

    int size = strings.size();
    sort(strings.begin(), strings.end());
    vector<char> temp(size);
    for (int i = 0; i < size; i++) {
        temp[i] = strings[i][n];
    }
    sort(temp.begin(), temp.end());
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < strings.size(); j++) {
            if (temp[i] == strings[j][n]) {
                answer[i] = strings[j];
                strings[j].swap(strings.back());
                strings.pop_back();
                sort(strings.begin(), strings.end());
                break;
            }
        }
    }


    return answer;
}