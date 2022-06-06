#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;

    for (int i = 0; i < sizes.size(); i++) {
        if (sizes[i][0] > sizes[i][1])
            swap(sizes[i][0], sizes[i][1]);
    }

    int max_a = 0, max_b = 0;
    for (int i = 0; i < sizes.size(); i++) {
        if (max_a < sizes[i][0]) max_a = sizes[i][0];
        if (max_b < sizes[i][1]) max_b = sizes[i][1];
    }

    answer = max_a * max_b;

    return answer;
}