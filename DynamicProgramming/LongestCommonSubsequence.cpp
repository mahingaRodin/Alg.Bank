#include<iostream>
using namespace std;

//here is the implementation of the lcs dynamic programming algorithm 

int lcs(string str1, string str2) {
    int n = str1.size();
    int m = str2.size();

    //create the dynamic programming table
    int dp[101][101] = {0}; // assuming the max size of the string is < 100

    //fill the table
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
           if(i==0 || j==0) {
               dp[i][j] = 0; //base case: empty string comparison
           } else if(str1[i-1] == str2[j-1]) {
               dp[i][j] = dp[i - 1][j - 1] + 1; // character matches
           } else {
            //take the best option
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
           }
        }
    }

    return dp[n][m]; // the length of the lcs
}


int main() {
    string str1, str2;

    cout << "Enter the first string: ";
    cin >> str1;
    cout << endl;

    cout << "Enter the second string: ";
    cin >> str2;
    cout << endl;

    cout << "the lcs of the two strings is " << lcs(str1, str2) << endl;
    return 0;
}