#include<bits/stdc++.h>
using namespace std;

void builTree(int *arr, int *tree, int start, int end, int treeNode){

     if(start == end){
          tree[treeNode] = arr[start];
          return;
     }

     int mid = (start + end)/2;
     builTree(arr,tree,start,mid,2*treeNode);
     builTree(arr,tree,mid + 1, end, 2*treeNode + 1);

     tree[treeNode] = tree[2*treeNode] + tree[2*treeNode + 1];
}

void updateTree(int *arr, int *tree, int start, int end, int treeNode, int index, int value){

     if(start == end){
          arr[index] = value;
          tree[treeNode] = value;
          return;
     }

     int mid = (start + end)/2;

     if(index > mid)
          updateTree(arr,tree,mid + 1, end, 2*treeNode + 1, index, value);
     else
          updateTree(arr,tree,start,mid, 2*treeNode, index, value);
     tree[treeNode] = tree[2*treeNode] + tree[2*treeNode + 1];
}

int query(int *tree, int start, int end, int treeNode, int left, int right){

     if(start > right || end < left)
          return 0;

     if(start >= left && end <= right)
          return tree[treeNode];

     int mid = (start + end)/2;
     int ans1 = query(tree,start,mid,2*treeNode,left,right);
     int ans2 = query(tree,mid + 1,end,2*treeNode + 1,left,right);
     return ans1 + ans2;
}

int main(){
     int n;
     cin >> n;

     int arr[n];
     for(int i = 0; i < n; i++)
          cin >> arr[i];

     // always take size of tree to be 4*n
     int *tree = new int[4*n];


     builTree(arr,tree,0,n-1,1);
     updateTree(arr,tree,0,n-1,1,2,10);
     for(int i = 1; i < 2*n; i++)
          std::cout << tree[i] << '\n';
     std::cout << query(tree,0,n-1,1,2,4) << '\n';
}
