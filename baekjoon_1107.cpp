#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <deque>
#include <iomanip>
#define CUR_CHANNEL 100

using namespace std;

void input_data(int* goal, int* n_broken, vector<bool>& button);
int countPressed(int goal, vector<bool>& button);
int findMinMove(int goal, vector<bool>& button);

int main(){
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL);
    int goal, n_broken;
    vector<bool> button(10, true);
    input_data(&goal, &n_broken, button);
    cout << findMinMove(goal, button) << "\n";
    return 0;
}

void input_data(int* goal, int* n_broken, vector<bool>& button) {
    cin >> *goal;
    cin >> *n_broken;
    for(int i = 0; i < *n_broken; i++) {
        int brokenBtn;
        cin >> brokenBtn;
        button[brokenBtn] = false;
    }
}

int countPressed(int goal, vector<bool>& button) {
    if(!goal) {
        if(button[0]) return 1;
        else          return 0;
    }
    int cnt = 0;
    while(goal > 0) {
        if(!button[goal % 10]) return 0;
        cnt++;
        goal /= 10;
    }
    return cnt;
}

int findMinMove(int goal, vector<bool>& button) {
    int minMove = abs(goal - CUR_CHANNEL);
    for(int i = 0; i < 1000000; i++) {
        int cntPressed = countPressed(i, button);
        if(cntPressed) {
            int move = abs(i - goal) + cntPressed;
            minMove = minMove < move ? minMove : move;
        }
    }
    return minMove;
}
