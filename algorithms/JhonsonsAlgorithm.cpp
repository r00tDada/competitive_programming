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
#define INF INT_MAX
vector<pair<int, int>> adj[1001];
int dist[1001][1001];
int parent[1001][1001];
vector<int> v[10001];
typedef pair<int, int> iPair;
vector<int> dijkstra(int V, int src, vector<int> h)
{
    priority_queue<iPair, vector<iPair>, greater<iPair>> pq;
    vector<int> d(V, INF);
    pq.push(make_pair(0, src));
    d[src] = 0;
    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        for (auto x : adj[u])
        {
            int v = x.first;
            int weight = x.second;
            if (d[v] > d[u] + weight)
            {
                d[v] = d[u] + weight;
                pq.push(make_pair(d[v], v));
            }
        }
    }
    // printf("Vertex Distance from Source %d\n", src);
    // for (int i = 0; i < V; i++)
    //     printf("%d \t\t %d\n", i, d[i]);
    return d;
}

void printsolution(int vertices)
{
    rep(i, 0, vertices)
    {
        rep(j, 0, vertices)
        {
            cout << dist[i][j] << " ";
        }
        cout << endl;
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

    int vertices, edges;
    cin >> vertices >> edges;
    rep(i, 0, edges)
    {
        int x, y, w;
        cin >> x >> y >> w;
        v[i].pb(x);
        v[i].pb(y);
        v[i].pb(w);
    }
    rep(i, 0, vertices)
    {
        v[edges + i].pb(vertices);
        v[edges + i].pb(i);
        v[edges + i].pb(0);
    }
    // rep(i, 0, edges + vertices)
    // {
    //     cout << v[i][0] << " " << v[i][1] << " " << v[i][2] << endl;
    // }

    // h->bellamford distance
    vector<int> h(vertices + 1, 0);
    h[vertices] = 0;
    for (int i = 0; i < vertices + 1; i++)
    {
        int flg = 0;
        int j = 0;
        while (v[j].size() != 0)
        {
            if (h[v[j][0]] + v[j][2] < h[v[j][1]])
            {
                h[v[j][1]] = h[v[j][0]] + v[j][2];
                flg = 1;
            }
            j++;
        }
        if (flg == 0)
            break;
    }
    // rep(i, 0, vertices)
    //         cout
    //     << h[i] << " ";
    rep(i, 0, vertices)
    {
        v[edges + i].pop_back();
        v[edges + i].pop_back();
        v[edges + i].pop_back();
    }
    rep(i, 0, edges)
    {
        v[i][2] = v[i][2] + h[v[i][0]] - h[v[i][1]];
        // cout << v[i][0] << " " << v[i][1] << " " << v[i][2] << endl;
    }
    //Dijkstra is applied
    rep(i, 0, edges)
    {
        int x = v[i][0];
        int y = v[i][1];
        int z = v[i][2];
        adj[x].push_back(make_pair(y, z));
    }
    rep(i, 0, vertices)
    {
        vector<int> distance = dijkstra(vertices, i, h);
        rep(j, 0, vertices)
            dist[i][j] = distance[j];
    }
    rep(i, 0, vertices)
    {
        rep(j, 0, vertices)
        {
            dist[i][j] = dist[i][j] + h[j] - h[i];
        }
    }
    printsolution(vertices);
    return 0;
}

/// Johnson's algorithm for all pair shortest paths in sparse graphs
/// Complexity: O(N * M) + O(N * M * log(N))
