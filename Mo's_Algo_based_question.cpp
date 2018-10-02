#include<bits/stdc++.h>
using namespace std;
typedef int ll;
ll cnt[1000500];
long long current_ans;
ll block_size;
ll a[200500];
pair< pair<int, int>, int> queries[200500];
ll ans[200500];
inline void add(int num)
    {
      current_ans-=cnt[num]*cnt[num]*num;
        cnt[num]++;
        current_ans+=cnt[num]*cnt[num]*num;

    }
inline void remoove(int num)
    {
       current_ans-=cnt[num]*cnt[num]*num;
        cnt[num]--;
        current_ans+=cnt[num]*cnt[num]*num;

    }
bool mo_cmp(const pair<pair<ll,ll>,ll > &a,const pair<pair<ll,ll>,ll > &b)
{
    ll left=a.first.first/block_size;
    ll right=b.first.first/block_size;
    if(left!=right)
    return left<right;

    return a.first.second<b.first.second;
}
int main(){
    ll n,q;
    ios::sync_with_stdio(false);
    cin>>n>>q;
    block_size=sqrt(n);
    memset(cnt,0,sizeof(cnt));
    current_ans=0;

    ll i;
    for(i=0;i<n;++i)
    {
        cin>>a[i];
    }
    for(i=0;i<q;++i)
    {
    cin >> queries[i].first.first >> queries[i].first.second;
        queries[i].second = i;
    }
    sort(queries,queries+q,mo_cmp);
    ll mo_left=0,mo_right=-1;

    for(i=0;i<q;++i)
    {
        ll li,ri,ind;
        li=queries[i].first.first-1;
        ri=queries[i].first.second-1;
        ind=queries[i].second;
       // cout<<li<<" "<<ri<<" "<<ind<<endl;
        while(mo_right<ri)
        {  mo_right++;
            add(a[mo_right]);
        }
        while(mo_right>ri)
        {
            remoove(a[mo_right]);
            mo_right--;
        }
         while(mo_left<li)
        {
            remoove(a[mo_left]);
            mo_left++;
        }
        while(mo_left>li)
        { mo_left--;
           add(a[mo_left]);
        }

        ans[ind]=current_ans;

    }
    for(i=0;i<q;++i)
    cout<<ans[i]<<"\n";

   return 0;
}
