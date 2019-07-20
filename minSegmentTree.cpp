#include<bits/stdc++.h>
using namespace std;

void buildTree(int *arr, int *tree, int start, int end, int treeNode){

     if(start == end){
          tree[treeNode] = arr[start];
          return;
     }

     int mid = (start + end)/2;
     buildTree(arr,tree,start,mid,2*treeNode);
     buildTree(arr,tree,mid + 1,end,2*treeNode + 1);
     tree[treeNode] = min(tree[2*treeNode], tree[2*treeNode + 1]);
}

void update(int *arr, int *tree, int start, int end, int treeNode, int index, int value){

     if(start == end){
          arr[index] = value;
          tree[treeNode] = value;
          return;
     }

     int mid = (start + end)/2;
     if(index > mid)
          update(arr,tree,mid + 1,end,2*treeNode + 1,index,value);
     else
          update(arr,tree,start,mid,2*treeNode,index,value);
     tree[treeNode] = min(tree[2*treeNode], tree[2*treeNode + 1]);
}

int query(int *tree, int start, int end, int treeNode, int left, int right){

     if(end < left || start > right)
          return INT_MAX;

     if(end <= right && start >= left)
          return tree[treeNode];

     int mid = (start + end)/2;
     int ans1 = query(tree,start,mid, 2*treeNode,left,right);
     int ans2 = query(tree,mid+1,end, 2*treeNode+1,left,right);
     return min(ans1,ans2);
}

int main() {

	int n,q;
    cin >> n >> q;

    int arr[n + 1];
    for(int i = 0; i < n; i++)
        cin >> arr[i];


    int *tree = new int[4*n];
    buildTree(arr,tree,0,n-1,1);


    for(int i = 0; i < q; i++){
        char c;
        int left,right;

        cin >> c >> left >> right;

        if(c == 'q')
            cout << query(tree,0,n-1,1,left-1,right-1) << endl;
        else
            update(arr,tree,0,n-1,1,left-1,right);
    }
}
