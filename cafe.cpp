#include <iostream>
using namespace std;
int n,k,u,offset,front,back;
bool c[1000001] = {0,}, Fstate, Bstate;
int main() {
    cin >> n >> k;
    for(int i=0; i<k; i++) {
        cin >> u;
        if(!c[u]) {
            c[u] = 1;
            Fstate = 1;
            Bstate = 1;
            offset = 1;
            while(Fstate||Bstate) {
                if(Fstate) {
                    front = u-offset;
                    if(front < 1) front = front + n;
                    if(c[front]) Fstate = 0;
                }
                if(Bstate) {
                    back = u+offset;
                    if(back > n) back = back - n;
                    if(c[back]) Bstate = 0;
                }
                offset++;
            }
            cout << u << " " << front << " " << back << "\n";
        }
        else c[u] = 0;
    }
}