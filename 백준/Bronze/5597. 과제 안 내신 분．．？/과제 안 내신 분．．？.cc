#include <iostream>
#include <vector>

using namespace std;

const int STUDENT_NUM = 30;

int main() {
    vector<bool> students(STUDENT_NUM + 1);
    
    for (int i = 0; i < 28; i++) {
        int student;
        cin >> student;
        students[student] = true;
    }
    
    int cnt = 0;
    for (int i = 1; i <= STUDENT_NUM; i++) {
        if (!students[i]) {
            cnt++;
            cout << i << "\n";
        }
        
        if (cnt == 2) {
            break;
        }
    }

    return 0;
}