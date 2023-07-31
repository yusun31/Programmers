#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size());

    // 중복 제거
    sort(report.begin(), report.end());
    report.erase(unique(report.begin(), report.end()), report.end());

    map<int, vector<string>> temp_name; // 임시 저장
    vector<int> count(id_list.size()); // 신고 횟수 count
    for (int i = 0; i < report.size(); i++) {
        string str1 = report[i].substr(0, report[i].find(" "));
        string str2 = report[i].substr(report[i].find(" ") + 1, report[i].size());
        for (int j = 0; j < id_list.size(); j++) {
            if (str2 == id_list[j]) {
                count[j]++;
                temp_name[j].push_back(str1);
            }
        }
    }

    map<int, vector<int>> name; // index : 신고당한 사람, vector : 신고자
    for (int i = 0; i < id_list.size(); i++) {
        for (int j = 0; j < temp_name[i].size(); j++) {
            for (int m = 0; m < id_list.size(); m++) {
                if (temp_name[i][j] == id_list[m]) {
                    name[i].push_back(m);
                }
            }
        }
    }


    for (int i = 0; i < id_list.size(); i++) {
        for (int j = 0; j < name[i].size(); j++) {
            if (count[i] >= k) {
                answer[name[i][j]]++;
            }
        }
    }

    return answer;
}