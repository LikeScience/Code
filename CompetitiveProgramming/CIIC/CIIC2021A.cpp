#include <iostream>
#include <vector>

using namespace std;

int N;
vector<vector<int> > m;

int dp(int S, int x) {
    if (x == 2) {
        int f = -1, s = -1, int i = 0;
        while(1) {
            if (f == -1 && S%2) {
                f = i;
            } else if (s == -1 && S%2) {
                s = i;
                break;
            }
            S >> 1; i++;
        }
        return m[f][s];
    }
    int y = 1 << (N-1), b, i = N-1;
    while(1) {
        if (y & S) {
            b = i;
            break;
        }
        i--; y >> 1;
    }
    int y = 1, mx = 0;
    for (int i = 0; i <= N-2; i++) {
        if (y & S) {
            
        }

        y << 1;
    }   

}

int main() {
    cin >> N;
    m.assign(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> m[i][j];
        }
    }
    cout << dp((1<<N)-1, N);
}