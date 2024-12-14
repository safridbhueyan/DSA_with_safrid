#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int coin[n];
    for(int i=0;i<n;i++)
        cin >> coin[i];

    int change;
    cin >> change;
    long long dp[change+1] = {0};
    dp[0] = 1;

    for(int j=0;j<n;j++){
        for(int i=coin[j];i<=change;i++)
            dp[i] += dp[i-coin[j]];
    }

    cout << dp[change];
}