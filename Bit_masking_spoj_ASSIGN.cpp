#include <iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<climits>
#define M 21
#define endl "\n"
#define debug(x) cout << x << endl
using namespace std;
    
// void recSolve(int a[M][M], int n, bool vis[], int top)
// {
//     if(top == n)
//         ans++;
    
//     //bool liked = false;
//     long long int ans = 0;
//     for(int i = 0; i < n; ++i)
//     {
//         if(vis[i] || a[top][i] == 0)
//             continue;
        
//         vis[i] = true;
//         recSolve(a, n, vis, top+1);
//         vis[i] = false;
//     }

// }

int count_set_bits(int n)
{
    int set = 0;
    while(n > 0)
    {   if(n & 1)
            set += 1;
        n >>= 1;
    }
    return set;
}

long long int bitmask_dp(int a[M][M], int n)
{   int N = 1 << n;
    long long int dp[N];

    for(int i = 0; i< N; ++i)
        dp[i] = 0;
    dp[0] = 1;
    for(int mask = 0; mask < N; ++mask)
    {
        int x = count_set_bits(mask);
        long long int ans = 0;
        for(int j = 0; j < n; ++j)
        {
            if(!(mask & (1 << j)) && a[x][j])
            {
                dp[mask | (1 << j)] +=  dp[mask]; //dp[mask | (1 << j)]  
            }
        }
         
    }
    return dp[N - 1];
}

void solve(int a[M][M], int n)
{
    // bool vis[M];
    // ans = 0;
    // for(int i = 0; i< M; ++i)
    //     vis[i] = false;
    // recSolve( a, n, vis, 0);
    long long int ans;
    ans = bitmask_dp(a, n);
    cout << ans << endl;
}

int main()
{
   int c;
   cin >> c;
   int a[M][M];
   while(c--)
   {
       int n;
       cin >> n;
       for(int i =0; i <n; ++i)
       {
           for(int j = 0;j < n ; ++j)
            cin >> a[i][j];
       }
       solve(a, n);
   }
    return 0;
}
