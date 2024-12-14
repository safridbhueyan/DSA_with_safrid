#include <iostream>
#include <vector>
using namespace std;

int fibonacci(int n, vector<int>& memo) {
    if (n <= 1)
        return n;
    if (memo[n] != -1)
        return memo[n]; // Return cached result

    memo[n] = fibonacci(n - 1, memo) + fibonacci(n - 2, memo); // Compute and store result
    return memo[n];
}

int main() {
    int n;
    cin >> n;

    vector<int> memo(n + 1, -1); // Initialize memoization table with -1
    cout << "Fibonacci(" << n << ") = " << fibonacci(n, memo) << endl;

    return 0;
}
