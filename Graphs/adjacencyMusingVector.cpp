#include<iostream>
#include<vector>

using namespace std;

int main() {
    int n, e;
    cin >> n >> e;
    vector<vector<int>> matrix(n, vector<int>(n, 0));
    for (int i = 0; i <= e; i++) {
        int fv, sv;
        cin >> fv >> sv;
        matrix[fv][sv] = 1;
        matrix[sv][fv] = 1;
    }
    return 0;
}