#include <string>
#include <vector>
using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;

    vector<vector<int>> binary1(n, vector<int>(n));
    vector<vector<int>> binary2(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = n - 1; j >= 0; j--) {
            if (arr1[i] % 2 == 1) {
                binary1[i][j] = 1;
            }
            arr1[i] = arr1[i] / 2;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = n - 1; j >= 0; j--) {
            if (arr2[i] % 2 == 1) {
                binary2[i][j] = 1;
            }
            arr2[i] = arr2[i] / 2;
        }
    }

    string temp = "";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (binary1[i][j] == 1 || binary2[i][j] == 1) {
                temp += "#";
            }
            else {
                temp += " ";
            }
        }
        answer.push_back(temp);
        temp = "";
    }

    return answer;
}