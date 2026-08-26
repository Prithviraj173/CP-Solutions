#include<bits/stdc++.h>
using namespace std;
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
#define vout(A) for(int i = 0; i < A.size(); i++) {cout << A[i] << " ";} cout << endl;
#define ll long long
#define ull unsigned long long
#define yes cout <<"YES"<<endl;
#define no cout <<"NO"<<endl;
#define inc(a) sort(a.begin(), a.end());
#define rev(a) sort(a.rbegin(), a.rend());
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) ((a * b) / gcd(a, b))
#define f(i,s,e) for(int i = s; i < e; i++)
const int MOD = 1e9 + 7;
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

void solve() {
    vector<ll> arr(5);
    for(int i = 0; i < 5; i++) cin >> arr[i];
    vector<vector<ll>> dp(arr[0] + 1, vector<ll>(arr[1] + 1, 1e9));
    dp[0][0] = 0;
    for(int i = 0; i <= arr[0]; i++) {
        for(int j = 0; j <= arr[1]; j++) {
            if(dp[i][j] == 1e9) continue;
            if(i + 1 <= arr[0]) dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + arr[2]);
            if(i + 2 <= arr[0]) dp[i + 2][j] = min(dp[i + 2][j], dp[i][j] + arr[2]);
            if(j + 1 <= arr[1]) dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + arr[3]);
            if(j + 2 <= arr[1]) dp[i][j + 2] = min(dp[i][j + 2], dp[i][j] + arr[3]);
            if(i + 1 <= arr[0] && j + 1 <= arr[1]) dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + arr[4]);
        }
    }
    cout << dp[arr[0]][arr[1]] << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}