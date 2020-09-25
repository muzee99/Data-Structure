#include <iostream>
using namespace std;
long long bm[64];
long long tm[64] = {0,};
bool bitmap[64][64];
int main() {
    for(int i=0; i<64; i++) {
        cin >> bm[i];
        long long bit = bm[i];
        for(int j=63; j>=0; j--) {
            bitmap[j][i] = bit&0x1;
            bit = bit>>1;
        }
    }
    for(int i=0; i<64; i++) {
        for(int j=0; j<64; j++) {
            tm[i] = tm[i] << 1;
            tm[i] = tm[i]|bitmap[i][j];
        }
        cout << tm[i] << "\n";
    }
}