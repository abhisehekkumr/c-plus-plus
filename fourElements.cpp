#include <bits/stdc++.h>

using namespace std;

int A[1000001]={0};

struct P
{
    int a, b;
};

struct compare
{
    bool operator()(P p1, P p2)
    {
        return (A[p1.a]+A[p1.b] < A[p2.a]+A[p2.b]);
    }
};

bool matchingIndex(int i, int j, int k, int l)
{
    //since j is looping from (i+1) to (n), the pairs in a given element of the vector(g, h) will never be equal
    return (i != j && i != k && i != l && j != k && j != l && k != l);
}

bool four(int n, int num)
{
    vector<P> v;

    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            P temp;
            temp.a = i;
            temp.b = j;

            v.push_back(temp);
        }
    }

    sort(v.begin(), v.end(), compare());

    int l=0, r=v.size()-1;

    while(l < r)
    {
        int e = v[l].a, f = v[l].b, g = v[r].a, h = v[r].b;

        int sum = A[e] + A[f] + A[g] + A[h];

        if(sum == num && matchingIndex(v[l].a,v[l].b,v[r].a, v[r].b))
        return 1;

        if(sum<num)
        l++;
        else
        r--;
    }
    return 0;
}

int main()
 {
	//code
	int t;
	cin>>t;

	while(t--)
	{
	    int n;
	    cin>>n;

	    for(int i=0;i<n;i++)
	    cin>>A[i];

	    int num;
	    cin>>num;

	    cout<<four(n, num)<<endl;
	}
	return 0;
}
