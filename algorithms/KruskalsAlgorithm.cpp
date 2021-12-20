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

int parent[100001], siize[100001];

int find_set(int v)
{
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void make_set(int v)
{
    parent[v] = v;
    siize[v] = 1;
}

void union_sets(int a, int b)
{
    a = find_set(a);
    b = find_set(b);
    if (a != b)
    {
        if (siize[a] < siize[b])
            swap(a, b);
        parent[b] = a;
        siize[a] += siize[b];
    }
}
//Minimum Cost Spanning Tree
int kruskal(set<pair<int, pair<int, int>>> p, int edges)
{
    int x, y;
    int cost, minimumCost = 0;
    for (auto it : p)
    {
        // Selecting edges one by one in increasing order from the beginning
        x = it.second.first;
        y = it.second.second;
        cost = it.first;
        // Check if the selected edge is creating a cycle or not
        if (find_set(x) != find_set(y))
        {
            // cout << x << " " << y << " " << cost << endl;
            minimumCost += cost;
            union_sets(x, y);
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
    int x, y, nodes, edges;
    int weight, cost, minimumCost;
    cin >> nodes >> edges;
    for (int i = 0; i < nodes; i++)
        make_set(i);
    set<pair<int, pair<int, int>>> p;
    for (int i = 0; i < edges; ++i)
    {
        cin >> x >> y >> weight;
        p.insert(make_pair(weight, make_pair(x, y)));
    }
    // Sort the edges in the ascending order
    // sort(p, p + edges);
    minimumCost = kruskal(p, edges);
    cout << minimumCost << endl;
}