#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cctype>
#include<cstdlib>
#include<algorithm>
#include<bitset>
#include<vector>
#include<list>
#include<deque>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<cmath>
#include<sstream>
#include<fstream>
#include<iomanip>
#include<ctime>
#include<complex>
#include<functional>
#include<climits>
#include<cassert>
#include<iterator>
#include<unordered_map>
#include<unordered_set>
//#include<quadmath.h>
using namespace std;
namespace test{
    void end_test(){
		int val;
		if (cin >> val){
			exit(1);
		}
	}
	void range_test(int t, int l, int r){
		if (t < l || r < t){
			exit(1);
		}
	}
}
#define MOD 3LL
#define MAX 100002
int n;
int q;
char s[MAX];
int a[MAX];
struct st{
	bool flag;
	long long int val;
	int rang;
	st(){
		flag = false;
		val = 0;
		rang = 0;
	}
};
long long int p2[MAX];
st seg[MAX*4];
void update(int b){
	if (seg[b].flag){
		seg[b].val = p2[seg[b].rang] + MOD - 1LL;
		seg[b].val %= MOD;
		if (b * 2 + 1 < MAX * 4){
			seg[b * 2 + 1].flag = true;
		}
		if (b * 2 + 2 < MAX * 4){
			seg[b * 2 + 2].flag = true;
		}
		seg[b].flag = false;
	}
}
inline void init(int b, int l, int r){
	seg[b].rang = r - l;
	if (l + 1 == r){
		seg[b].val = a[l];
		return;
	}
	init(b * 2 + 1, l, (l + r) >> 1);
	init(b * 2 + 2, (l + r) >> 1, r);
	seg[b].val = seg[b * 2 + 1].val*p2[seg[b * 2 + 2].rang] + seg[b * 2 + 2].val;
	seg[b].val %= MOD;
}
inline void add(int b, int l, int r, int ll, int rr){
	update(b);
	if (rr <= l || r <= ll){
		return;
	}
	if (ll <= l&&r <= rr){
		seg[b].flag = true;
		update(b);
		return;
	}
	add(b * 2 + 1, l, (l + r) >> 1, ll, rr);
	add(b * 2 + 2, (l + r) >> 1, r, ll, rr);
	seg[b].val = seg[b * 2 + 1].val*p2[seg[b*2+2].rang] + seg[b * 2 + 2].val;
	seg[b].val %= MOD;
}
st emp;
inline st qq(int b, int l, int r, int ll, int rr){
	update(b);
	if (rr <= l || r <= ll){
		return emp;
	}
	if (ll <= l&&r <= rr){
		return seg[b];
	}
	st k=qq(b * 2 + 1, l, (l + r) >> 1, ll, rr);
	st k2=qq(b * 2 + 2, (l + r) >> 1, r, ll, rr);
	k.rang += k2.rang;
	k.val *= p2[k2.rang];
	k.val += k2.val;
	k.val %= MOD;
	return k;
}
int main(){
	scanf("%d", &n);
	scanf("%s", s);
	test::range_test(n,1,100000);
	for (int i = 0; i < n; i++){
		a[i] = s[i] - '0';
		test::range_test(a[i],0,1);
	}
	p2[0] = 1LL;
	for (int i = 1; i < MAX; i++){
		p2[i] = p2[i - 1];
		p2[i] *= 2LL;
		if (p2[i] >= MOD){
			p2[i] %= MOD;
		}
	}
	init(0, 0, n);
	int q;
	scanf("%d", &q);
	while (q--){
		int ty;
		int a;
		int b;
		scanf("%d", &ty);
		test::range_test(ty,0,1);
		if (ty == 0){
			scanf("%d%d", &a, &b);
			if(a>b){
				return 1;
			}
			test::range_test(a,0,n-1);
			test::range_test(b,0,n-1);
			st ans = qq(0, 0, n, a, b + 1);
			printf("%lld\n", ans.val);
		}
		else{
			scanf("%d", &a);
			test::range_test(a,0,n-1);
			add(0, 0, n, a, a + 1);
		}
	}
	return 0;
}
