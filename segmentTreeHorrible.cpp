#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
#define ll long long
ll tree[1000000],lazy[1000000],n;


void update(ll node,ll start,ll end,ll l,ll r,ll val)
{

      if(lazy[node]!=0)
      {
            tree[node]+=lazy[node]*(end-start+1);
            if(start!=end)
            {
                  lazy[node*2]+=lazy[node];
                  lazy[node*2+1]+=lazy[node];
            }
            lazy[node]=0;
      }
      if(start>r||end<l||start>end)
      return;
      if(start>=l&&end<=r)
      {

            tree[node]+=val*(end-start+1);
            if(start!=end)
            {
            lazy[node*2]+=val;
            lazy[(node*2)+1]+=val;
            }
            return;
      }
      ll mid=(start+end)/2;
      update(node*2,start,mid,l,r,val);
      update(node*2+1,mid+1,end,l,r,val);
      tree[node]=tree[node*2]+tree[(node*2)+1];


      }
ll query(ll node,ll start,ll end,ll l,ll r)
{
      if(start>end||start>r||end<l)
      return 0;
      if(lazy[node]!=0)
      {
            tree[node]+=lazy[node]*(end-start+1);
            if(start!=end)
            {
                  lazy[node*2]+=lazy[node];
                  lazy[(node*2)+1]+=lazy[node];
            }
            lazy[node]=0;
      }

      if(start>=l&&end<=r)
      {

            return tree[node];
      }
      ll mid=(start+end)/2;
      ll a=query(2*node,start,mid,l,r);
      ll b=query(2*node+1,mid+1,end,l,r);
      return a+b;
}
int main() {
ll int i,j,k,t,r,u,v,p,q,c,l,val;
cin>>t;
for(i=0;i<t;i++)
{
      cin>>n>>c;
      r=n*2;
    memset(lazy, 0, sizeof lazy);
    memset(tree,0,sizeof tree);
      r--;
      for(j=0;j<c;j++)
      {
            cin>>l;
            if(l==0)
            {
                 cin>>p>>q>>val;
                 update(1,0,n-1,p-1,q-1,val);

            }
            else
            {
                  cin>>p>>q;

                  ll ansi=query(1,0,n-1,p-1,q-1);
                  cout<<ansi<<endl;

            }
      }


}
    return 0;
}
