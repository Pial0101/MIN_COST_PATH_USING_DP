#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll dp_code(vector<vector<ll>>& arr, ll n, ll m) {
    vector<vector<ll>> dp(n, vector<ll>(m,INT_MAX));
    dp[n-1][m-1] = arr[n-1][m-1];

    for (ll i = n-1; i >= 0; --i) {
        for (ll j = m-1; j >= 0; --j) {
            if (i < n-1) {
                dp[i][j] = min(dp[i][j], dp[i+1][j] + arr[i][j]);
            }
            if (j < m-1) {
                dp[i][j] = min(dp[i][j], dp[i][j+1] + arr[i][j]);
            }
        }
    }

    return dp[0][0];
}

void solve() {
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> arr(n, vector<ll>(m));
    
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < m; ++j) {
            cin >> arr[i][j];
        }
    }

    ll result = dp_code(arr, n, m);
    cout << result << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
