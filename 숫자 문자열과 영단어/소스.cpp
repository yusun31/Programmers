#include <iostream>
#include <string>
#include <map>
using namespace std;

int solution(string s) {
    int answer = 0;

    map<int, string> mapset;
    mapset.insert(make_pair(0, "zero"));
    mapset.insert(make_pair(1, "one"));
    mapset.insert(make_pair(2, "two"));
    mapset.insert(make_pair(3, "three"));
    mapset.insert(make_pair(4, "four"));
    mapset.insert(make_pair(5, "five"));
    mapset.insert(make_pair(6, "six"));
    mapset.insert(make_pair(7, "seven"));
    mapset.insert(make_pair(8, "eight"));
    mapset.insert(make_pair(9, "nine"));

    string str = "";
    string temp = "";
    for (int i = 0; i < s.length(); i++) {
        if (s[i] - '0' <= 9) {
            str += to_string(s[i] - '0');
        }
        else {
            temp += s[i];
        }
        for (int j = 0; j < mapset.size(); j++) {
            if (temp == mapset[j]) {
                str += to_string(j);
                temp = "";
            }
        }
    }

    answer = stoi(str);

    return answer;
}