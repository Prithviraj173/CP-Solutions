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
    ll p,r,c;
    cin >> p >> r >> c;
    vector<vector<double>> dp(r + 2, vector<double>(r + 2, 0.0));
    dp[0][0] = p;
    for(ll i = 0; i <= r; i++) {
        for(ll j = 0; j <= i; j++) {
            if(dp[i][j] > 1.0) {
                double cur = (dp[i][j] - 1.0) / 2.0;
                dp[i + 1][j] += cur, dp[i + 1][j + 1] += cur;
            }
        }
    }
    double ans = min(1.0, dp[r][c]);
    cout << fixed << setprecision(5) << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}