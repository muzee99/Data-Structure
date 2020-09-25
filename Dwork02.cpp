#include <iostream>
using namespace std;
int K, d, turn=0;
int X[51], Y[51], sec[2]={0, }, ward[2]={1,-1}, T;
pair<int, int> c[2];
int dir[4][2] = { {1,0}, {-1,0}, {0,1}, {0,-1} };
int makeDir(int cur, int next) {
    if(!(X[cur]-X[next])) {
        if(Y[next]-Y[cur]>0) return 2;
        else return 3;
    }
    else {
        if(X[next]-X[cur]>0) return 0;
        else return 1;
    }
}
void moving(int t) {
    for(int i=0; i<t; i++) {
        for(int j=0; j<2; j++) {
            if(ward[j]==-1 && !sec[j]) sec[j] = K;
            int section = sec[j];
            int direction = makeDir(section, section+ward[j]);
            c[j].first += dir[direction][0];
            c[j].second += dir[direction][1];
            if(c[j].first == X[section+ward[j]] && c[j].second == Y[section+ward[j]]) sec[j] += ward[j];
        }
    }
}
int main() {
    cin >> K;
    for(int i=0; i<K; i++) {
        cin >> X[i] >> Y[i];
        if(i!=0) {
            turn += abs(X[i-1]-X[i]);
            turn += abs(Y[i-1]-Y[i]);
            if(i==K/2-1) d = turn;
        }
    }
    turn += abs(X[0]-X[K-1]);
    turn += abs(Y[0]-Y[K-1]);
    X[K] = X[0];
    Y[K] = Y[0];
    sec[1] = K/2-1;
    c[0] = make_pair(X[sec[0]], Y[sec[0]]);
    c[1] = make_pair(X[sec[1]], Y[sec[1]]);
    cin >> T;
    T = T%turn;
    if(T<=d/2) moving(T);
    else if(T<=d) moving(d-T);
    else {
        ward[0] = -1;
        ward[1] = 1;
        if(T<=(turn-d)/2+d) moving(T-d);
        else moving(turn-T);
    }
    cout << c[0].first << " " << c[0].second << "\n";
    cout << c[1].first << " " << c[1].second << "\n";
    return 0;
}