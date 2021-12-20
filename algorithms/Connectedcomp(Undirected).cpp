#include <bits/stdc++.h>
using namespace std;
// ----------------------R00TDADA------------------------------
#define rep(i, a, b) for (__typeof((b)) i = (a); i < (b); i++)
#define nrep(i, a, b) for (__typeof((b)) i = (a); i > (b); i--)
#define all(a) (a).begin(), (a).end()
#define ff first
#define ss second
#define ppi pair<int, int>
#define pppi pair<ppi, int>
#define vi vector<int>
#define vii vector<ppi>
#define viii vector<pppi>
#define vs vector<string>
#define pb push_back
#define bitcount __builtin_popcount //count no's of ones in a set bit
#define prq priority_queue
#define mp make_pair
#define mem(x, val) memset((x), (val), sizeof(x));
#define sz(x) (int)x.size()
#define M_PI 3.14159265358979323846
#define rootdada                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
#define test  \
    int t;    \
    cin >> t; \
    while (t--)
#define int long long
#define M 1000000007
vector<int> adj[10001];
int vis[10001];
vector<int> comp;
void dfs(int src)
{
    vis[src] = 1;
    comp.pb(src);
    for (int i = 0; i < adj[src].size(); i++)
    {
        if (vis[adj[src][i]] == 0)
        {
            vis[adj[src][i]] = 1;
            dfs(adj[src][i]);
        }
    }
}
void findcomp(int n)
{
    rep(i, 0, n)
        vis[i] = 0;
    rep(i, 0, n)
    {
        if (!vis[i])
        {
            comp.clear();
            dfs(i);
            rep(i, 0, comp.size())
                    cout
                << comp[i] << " ";
            cout << endl;
        }
    }
}
signed main()
{
    rootdada;
#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    rep(i, 0, m)
    {
        int x, y;
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    findcomp(n);
}