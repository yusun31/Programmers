#include <iostream>
#include <string>
#include <vector>
using namespace std;

string solution(int n) {
    string watermelon = "����";
    string answer = "";
    int count = 0;
    for (int i = 1; i <= n / 2; i++) {
        answer += watermelon;
    }
    if (n % 2 != 0) {
        answer += "��";
    }

    return answer;
}

int main()
{
    int n;

    cin >> n;

    string answer = solution(n);

    cout << answer << endl;

    return 0;
}