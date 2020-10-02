#include<bits/stdc++.h>
using namespace std;

//MACROS
#define ll long long
#define f(i,a,b) for(i=a;i<b;i++)
#define MOD 1000000007
#define pb push_back
#define mp make_pair
#define INF (int)1e9
#define deb(x) cout << '>' << #x << " : " << x << endl;
#define cjam(t,x) cout << "Case #" << t << " : " << x << endl;
#define newl cout<<endl;
#define print(x) for(auto y:x) cout<<y<<' '; newl;
//MACROS

// DECIMAL TO BINARY CONVERSION
string toBinary(ll n)
{
    string r;
    while(n!=0) {r=(n%2==0 ?"0":"1")+r; n/=2;}
    return r;
}

// SEGMENT TREE
struct segtree
{
    int size;
    vector<ll> sums;

    void init(int n)
    {
        size = 1;
        while(size<n) size*=2;
        sums.assign(2*size, 0LL);

    }

    void set(int i, int v, int x, int lx, int rx)
    {
        if(rx-lx == 1) sums[x] = v;

        else
        {
            int m = (lx+rx)/2;

            if(i<m)
            {
                set(i, v, 2*x+1, lx, m);
            }
            else
            {
                set(i, v, 2*x+2, m, rx);
            }
            sums[x] = sums[2*x+1] + sums[2*x+2];
        }
        
    }

    void set(int i, int v)
    {
        set(i ,v, 0, 0, size);
    }


    ll sum(ll l, ll r, ll x, ll lx, ll rx)
    {
        if(l>=rx || r<=lx) return(0);
        if(l<=lx && r>=rx) return(sums[x]);

        ll m = (lx+rx)/2;

        ll s1 = sum(l, r, 2*x+1, lx, m);
        ll s2 = sum(l, r, 2*x+2, m, rx);

        return(s1+s2);
    }

    ll sum(ll l, ll r)
    {
        return(sum(l, r, 0, 0, size)); 
    }
    
};


//GRAPH
struct graph
{
    bool vis[100000];
    vector<ll> adj[100000];

    void edge(int a, int b)
    {
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    void dfs(ll s)
    {
        int i;
        vis[s] = 1;
        cout<<s<<' ';
        f(i,0,adj[s].size())
        {
            if(vis[adj[s][i]] == 0)
                dfs(adj[s][i]);
        }
    }
};


//BINARY SEARCH
ll bsearch(ll arr[], ll n, ll x)
{
    ll l=0, h=n-1;
    while(l<=h)
    {
        ll m = (l+h)/2;
        if(arr[m]==x)
        {
            return(m);
        }
        else if(arr[m]<x)
        {
            l = m+1;
        }
        else
        {
            h = m-1;
        }
    }
    return(-1);
}

//nCr in Constant Time
ll const mod = 1e9+7;
ll power(ll a, ll b)
{
    ll res = 1;
    while(b)
    {
        if(b&1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        b /= 2;
    }
    return res;
}

ll inverse(ll x){
    return power(x,mod-2);
}

ll const N = 1e6+55;
ll fact[N], ifact[N];

void precompute()
{
    fact[0] = 1;
    for(ll i=1; i<N; i++)
        fact[i] = (fact[i-1] * i) % mod;
    
    ifact[N-1] = inverse(fact[N-1]);
    for(ll i=N-2; i>=0; i--)
        ifact[i] = ((i+1) * ifact[i+1]) % mod;
}

ll ncr(ll n, ll r)
{
    if(r<0 or r>n) return 0;
    if(n == r) return 1;

    ll res = (fact[n] * ifact[n-r]) % mod;
    res = (res * ifact[r]) % mod;
    return res;
}


//////////////////////////
///////DRIVER CODE////////
//////////////////////////

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r", stdin);
    freopen("output.txt","w", stdout);
    #endif

    ll x,y,n,m,q,tt,t,i,j;

    cin>>tt;
    t=tt;
    while(tt--)
    {
        cin>>n;
        std::vector<ll> v;

        f(i,0,n)
        {
            cin>>x;
            v.pb(x);
        }
    }

}