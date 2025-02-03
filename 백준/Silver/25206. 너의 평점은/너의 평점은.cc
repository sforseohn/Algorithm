#include <iostream>
#include <map>



using namespace std;

const int SUBJECT_CNT = 20;

int main() {
    string subject, grade;
    float score;
    
    map<string, float> grade_map;
    grade_map["A+"] = 4.5;
    grade_map["A0"] = 4.0;
    grade_map["B+"] = 3.5;
    grade_map["B0"] = 3.0;
    grade_map["C+"] = 2.5;
    grade_map["C0"] = 2.0;
    grade_map["D+"] = 1.5;
    grade_map["D0"] = 1.0;
    grade_map["F"] = 0.0;

    float ans = 0;
    int score_cnt = 0;
    for (int i = 0; i < SUBJECT_CNT; i++) {
        cin >> subject >> score >> grade;
        if (grade != "P") {
            ans += score * grade_map[grade];
            score_cnt += score;
        }
    }
    
    cout << ans / score_cnt;

    return 0;
}