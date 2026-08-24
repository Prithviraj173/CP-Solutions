#include<bits/stdc++.h>
using namespace std;
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
#define vout(A) for(int i = 0; i < A.size(); i++) { cout << A[i] << " "; } cout << endl;
#define ll long long
#define ull unsigned long long
#define yes cout <<"YES"<<endl;
#define no cout <<"NO"<<endl;
#define inc(a) sort(a.begin(), a.end());
#define rev(a) sort(a.begin(), a.end());
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) ((a * b) / gcd(a, b))
#define f(i,s,e) for( int i=s;i<e;i++)
const int MOD = 1e9 + 7;
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

void solve() {
    string s,p;
    cin >> s >> p;
    ll n = s.length(), m = p.length();
    ll freq1[26] = {0}, freq2[26] = {0};
    for(char c : p) freq1[c - 'a']++;
    for(int i = 0; i < m; i++) freq2[s[i] - 'a']++;
    bool flag = false;
    for(int i = 0; i <= n - m; i++) {
        bool cur = true;
        for(int j = 0; j < 26; j++) {
            if(freq1[j] != freq2[j]) {
                cur = false;
                break;
            }
        }
        if(cur) {
            cout << i << " ";
            flag = true;
        }
        if(i + m < n) {
            freq2[s[i] - 'a']--, freq2[s[i + m] - 'a']++;
        }
    }
    if(!flag) cout << -1 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}