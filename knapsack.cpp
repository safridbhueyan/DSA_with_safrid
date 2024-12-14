#include <iostream>

using namespace std;

int main(){
    int n, capacity;
    cin >> n >> capacity;

    int weight[n+1], profit[n+1];
    for(int i=1;i<=n;i++)
        cin >> weight[i];

    for(int i=1;i<=n;i++)
        cin >> profit[i];

    int dp[n+1][capacity+1];

    for(int i=0;i<=n;i++){
        for(int j=0;j<=capacity;j++){
            if(i==0)
                dp[i][j] = 0;
            else if(j < weight[i])
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-weight[i]]+profit[i]);
        }
    }

    cout << dp[n][capacity];
}