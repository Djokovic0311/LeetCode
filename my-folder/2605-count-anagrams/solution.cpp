class Solution
{
public:
#define ll long long
    const int mod = 1e9 + 7;

    vector<ll> fact, invfact;

    ll binpow(ll a, ll b, ll p)
    {
        ll res = 1;
        a %= p;
        while (b)
        {
            if (b & 1)
                res = (res * a) % p;
            a = (a * a) % p;
            b >>= 1;
        }
        return res;
    }

    void precompute()
    {
        ll n = 100000;

        fact.resize(n + 1);
        invfact.resize(n + 1);

        fact[0] = 1;
        for (int i = 1; i <= n; ++i)
            fact[i] = (fact[i - 1] * i) % mod;

        invfact[n] = binpow(fact[n], mod - 2, mod);
        for (int i = n - 1; i >= 0; --i)
            invfact[i] = (invfact[i + 1] * (i + 1)) % mod; // computing all factorial inverses in O(N)
    }

    int countAnagrams(string s)
    {
        precompute();
        vector<string> S;
        stringstream ss(s);
        string SS;
        while (ss >> SS)
            S.push_back(SS); // Getting all words from the main string ( we can do normal for loop also)
        int ans = 1;
        for (auto x : S)
        {
            ans = (ans * fact[x.size()]) % mod;
            map<char, int> mp;
            for (auto y : x)
                mp[y]++;
            for (auto counts : mp)
                ans = (ans * invfact[counts.second]) % mod;

        }

        return ans;
    }
};
