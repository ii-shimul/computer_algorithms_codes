#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int List[n];
    for (int i = 0; i < n; i++) {
        cin >> List[i];
    }
    int LIS[n];
    for (int i = 0; i < n; i++) {
        LIS[i] = 1;
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (List[i] > List[j]) {
                LIS[i] = max(LIS[i], 1 + LIS[j]);
            }
        }
    }

    int mx = INT_MIN;
    for (int i = 0; i < n; i++) {
        cout << LIS[i] << " ";
        if (LIS[i] > mx)mx = LIS[i];
    }
    cout << endl << mx << endl;



}
