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
typedef pair<pair<int, int>, int> PII;
bool marked[10001];
vector<pair<int, int>> adj[10001];
int prim(int x)
{
    priority_queue<PII, vector<PII>, greater<PII>> Q;
    int y;
    int minimumCost = 0;
    pair<pair<int, int>, int> p;
    Q.push({{0, x}, x});
    while (!Q.empty())
    {
        // Select the edge with minimum weight
        p = Q.top();
        Q.pop();
        x = p.ff.second;

        // Checking for cycle
        if (marked[x] == true)
            continue;
        cout << p.ss << " " << x << " " << p.ff.ff << endl;
        minimumCost += p.first.ff;
        marked[x] = true;
        for (int i = 0; i < adj[x].size(); i++)
        {
            y = adj[x][i].second;
            if (marked[y] == false)
            {
                Q.push({adj[x][i], x});
            }
        }
    }
    return minimumCost;
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
    int nodes, edges, x, y, w;
    int minimumCost;
    cin >> nodes >> edges;
    rep(i, 0, edges)
    {
        cin >> x >> y >> w;
        adj[x].pb({w, y});
        adj[y].pb({w, x});
    }
    // Selecting 1 as the starting node
    minimumCost = prim(0);
    cout << minimumCost << endl;
    return 0;
}