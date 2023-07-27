#include <string>
#include <vector>
using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";

    vector<vector<int>> location(4, vector<int>(3));
    int temp = 1;
    for (int i = 0; i < location.size() - 1; i++) {
        for (int j = 0; j < location[i].size(); j++) {
            location[i][j] = temp++;
        }
    }
    location[3][0] = 10, location[3][2] = 11;
    int loc_left = 10, loc_right = 11;

    for (int i = 0; i < numbers.size(); i++) {
        if (numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7) {
            loc_left = numbers[i];
            answer += "L";
        }
        else if (numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9) {
            loc_right = numbers[i];
            answer += "R";
        }
        else {
            int left_row = 0, left_col = 0, right_row = 0, right_col = 0, num_row = 0, num_col = 0;
            for (int j = 0; j < location.size(); j++) {
                for (int k = 0; k < location[j].size(); k++) {
                    if (loc_left == location[j][k]) {
                        left_row = j;
                        left_col = k;
                    }
                    if (loc_right == location[j][k]) {
                        right_row = j;
                        right_col = k;
                    }
                    if (numbers[i] == location[j][k]) {
                        num_row = j;
                        num_col = k;
                    }
                }
            }
            int dis_left = 0, dis_right = 0;
            dis_left = abs(num_row - left_row) + abs(num_col - left_col);
            dis_right = abs(num_row - right_row) + abs(num_col - right_col);
            if (dis_left < dis_right) {
                loc_left = numbers[i];
                answer += "L";
            }
            else if (dis_left > dis_right) {
                loc_right = numbers[i];
                answer += "R";
            }
            else {
                if (hand == "right") {
                    loc_right = numbers[i];
                    answer += "R";
                }
                else {
                    loc_left = numbers[i];
                    answer += "L";
                }
            }
        }
    }

    return answer;
}