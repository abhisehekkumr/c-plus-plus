#include<bits/stdc++.h>
using namespace std;

void buildTree(int *arr, int *tree, int treeNode, int start, int end){

     if(start == end){
          tree[treeNode] = arr[start];
          return;
     }

     int mid = (start + end)/2;
     buildTree(arr,tree,2*treeNode,start,mid);
     buildTree(arr,tree,2*treeNode+1,mid+1,end);
     int bits = end-mid;
     int mul = pow(2,bits);
     tree[treeNode] = (mul*tree[2*treeNode] + tree[2*treeNode+1])%3;
}

void updateTree(int *arr, int *tree, int treeNode, int start, int end, int index){

     if(start == end){
          arr[start] = 1;
          tree[treeNode] = 1;
          return;
     }

     int mid = (start + end)/2;

     if(index > mid)
          updateTree(arr,tree,2*treeNode+1,mid+1,end,index);
     else
          updateTree(arr,tree,2*treeNode,start,mid,index);

     int bits = end - mid;
     int mul = pow(2,bits);
     tree[treeNode] = (mul*tree[2*treeNode] + tree[2*treeNode+1])%3;
}

int query(int *tree, int treeNode, int start, int end, int left, int right){

     if(start > right || end < left)
          return 0;

     if(start >= left && end <= right){
          int bits = right-end;
          int mul = pow(2,bits);
          return (tree[treeNode]*mul)%3;
     }

     int mid = (start + end)/2;
     int left_child = query(tree,2*treeNode,start,mid,left,right);
     int right_child = query(tree,2*treeNode+1,mid+1,end,left,right);
     return (left_child + right_child)%3;
}

int main(){
     int n;
     cin >> n;
     int *arr = new int[n];
     for(int i = 0; i < n; i++)
          cin >> arr[i];

     int *tree = new int[4*n]();

     int q;
     cin >> q;
     for(int i = 0; i < q; i++){
          int t;
          cin >> t;

          if(t == 0){
               int left,right;
               int result = query(tree,1,0,n-1,left-1,right-1);
               std::cout << result << '\n';
          }
          else{
               int index;
               cin >> index;
               updateTree(arr,tree,1,0,n-1,index);
          }
     }

     delete[] arr;
     delete[] tree;
     return 0;
}
