#include <string>
#include <iostream>
using namespace std;

void lower(string& str) {
    for (int i = 0; i < str.length(); i++) {
        int id = str[i] - '0';
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + 32;
        }
    }
}

string length_check(string& str) {
    if (str.length() >= 16 || str.length() <= 2) {
        string temp = "";
        if (str.length() >= 16) {
            for (int i = 0; i < 14; i++) {
                temp += str[i];
            }
            if (str[14] != '.') {
                temp += str[14];
            }
        }

        if (str.length() <= 2) {
            for (int i = 0; i < str.length(); i++) {
                temp += str[i];
            }
            for (int i = 0; i < 3 - str.length(); i++) {
                temp += str[str.length() - 1];
            }
        }

        return temp;
    }
    else {
        return str;
    }
}

string remove_dot(string& str) {
    string temp = "";
    if (str.length() != 0) {
        if (str[0] == '.') {
            for (int i = 1; i < str.length() - 1; i++) {
                temp += str[i];
            }
        }
        else {
            for (int i = 0; i < str.length() - 1; i++) {
                temp += str[i];
            }
        }
        if (str[str.length() - 1] != '.') {
            temp += str[str.length() - 1];
        }
    }
    else {
        temp += "a";
    }

    return temp;
}

string replace_dot(string& str) {
    string temp = "";
    int count = 0;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '.') {
            count++;
        }
        else {
            if (count >= 1) {
                temp += ".";
                temp += str[i];
                count = 0;
            }
            else {
                temp += str[i];
            }
        }
    }

    return temp;
}

string remove(string& str) {
    string temp = "";
    for (int i = 0; i < str.length(); i++) {
        int id = str[i] - '0';
        if ((id >= 49 && id <= 74) || id == -3 || id == -2 || id == 47 || (id >= 0 && id < 10)) {
            temp += str[i];
        }
        else {
            temp += "";
        }
    }

    return temp;
}

string solution(string new_id) {
    string answer = "";

    lower(new_id);
    answer = remove(new_id);
    answer = replace_dot(answer);
    answer = remove_dot(answer);
    answer = length_check(answer);

    return answer;
}