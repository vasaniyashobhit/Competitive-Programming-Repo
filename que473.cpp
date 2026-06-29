#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to hold the function coefficients and original index
struct Parabola
{
    long long a, b, c;
    int id;

    // Custom comparator to sort topologically:
    // Descending by 'a', then descending by 'c'
    bool operator<(const Parabola &other) const
    {
        if (a != other.a)
            return a > other.a;
        if (c != other.c)
            return c > other.c;
        return b > other.b;
    }
};

// Function to check if Parabola F strictly dominates Parabola G
bool dominates(const Parabola &F, const Parabola &G)
{
    if (F.a == G.a)
    {
        // If 'a' is the same, 'b' must be equal and F must be shifted higher than G
        return (F.b == G.b) && (F.c > G.c);
    }

    if (F.a > G.a)
    {
        long long da = F.a - G.a;
        long long db = F.b - G.b;
        long long dc = F.c - G.c;

        // Discriminant must be strictly less than 0
        // db^2 - 4*da*dc < 0
        // Standard 64-bit integer (long long) is sufficient here as max value is ~1.6 * 10^13
        return db * db < 4LL * da * dc;
    }

    // F.a < G.a is impossible for F to dominate G
    return false;
}

void solve()
{
    int n;
    cin >> n;

    vector<Parabola> p(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> p[i].a >> p[i].b >> p[i].c;
        p[i].id = i;
    }

    // Step 1: Sort the parabolas to establish a valid topological order
    sort(p.begin(), p.end());

    // Step 2: LIS-style DP to find longest chain ending at function i
    vector<int> dp_in(n, 1);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            if (dominates(p[j], p[i]))
            {
                dp_in[i] = max(dp_in[i], dp_in[j] + 1);
            }
        }
    }

    // Step 3: LIS-style DP to find longest chain starting at function i
    vector<int> dp_out(n, 1);
    for (int i = n - 1; i >= 0; --i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            if (dominates(p[i], p[j]))
            {
                dp_out[i] = max(dp_out[i], dp_out[j] + 1);
            }
        }
    }

    // Step 4: Map the results back to their original indices
    vector<int> ans(n);
    for (int i = 0; i < n; ++i)
    {
        // -1 because the current parabola is counted in both dp_in and dp_out
        ans[p[i].id] = dp_in[i] + dp_out[i] - 1;
    }

    // Output the results
    for (int i = 0; i < n; ++i)
    {
        cout << ans[i] << (i == n - 1 ? "" : " ");
    }
    cout << "\n";
}

int main()
{
    // Fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (cin >> t)
    {
        while (t--)
        {
            solve();
        }
    }

    return 0;
}