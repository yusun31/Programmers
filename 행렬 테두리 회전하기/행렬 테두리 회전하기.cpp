#include <vector>
#include <queue>
using namespace std;

void rotate(vector<vector<int>>& arr, queue<int> q, vector<vector<int>>& queries, int i) {
    vector<vector<int>> temp = arr;

    for (int j = queries[i][1] + 1; j <= queries[i][3]; j++) {
        temp[queries[i][0]][j] = q.front();
        q.pop();
    }
    for (int j = queries[i][0] + 1; j <= queries[i][2]; j++) {
        temp[j][queries[i][3]] = q.front();
        q.pop();
    }
    for (int j = queries[i][3] - 1; j >= queries[i][1]; j--) {
        temp[queries[i][2]][j] = q.front();
        q.pop();
    }
    for (int j = queries[i][2] - 1; j >= queries[i][0]; j--) {
        temp[j][queries[i][1]] = q.front();
        q.pop();
    }

    arr = temp;
}

int pick_up(vector<vector<int>>& arr, int i, vector<vector<int>>& queries) {
    queue<int> q;

    int answer = 10000;

    for (int j = queries[i][1]; j <= queries[i][3]; j++) {
        q.push(arr[queries[i][0]][j]);
        answer = min(answer, arr[queries[i][0]][j]);
    }
    for (int j = queries[i][0] + 1; j <= queries[i][2]; j++) {
        q.push(arr[j][queries[i][3]]);
        answer = min(answer, arr[j][queries[i][3]]);
    }
    for (int j = queries[i][3] - 1; j >= queries[i][1]; j--) {
        q.push(arr[queries[i][2]][j]);
        answer = min(answer, arr[queries[i][2]][j]);
    }
    for (int j = queries[i][2] - 1; j > queries[i][0]; j--) {
        q.push(arr[j][queries[i][1]]);
        answer = min(answer, arr[j][queries[i][1]]);
    }

    rotate(arr, q, queries, i);

    return answer;
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;

    vector<vector<int>> arr(rows + 1, vector<int>(columns + 1));

    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= columns; j++) {
            arr[i][j] = (i - 1) * columns + j;
        }
    }

    for (int i = 0; i < queries.size(); i++) {
        answer.push_back(pick_up(arr, i, queries));
    }

    return answer;
}