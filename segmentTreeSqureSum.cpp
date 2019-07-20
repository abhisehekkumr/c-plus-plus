#include<bits/stdc++.h>
using namespace std;

struct treeNode{
     int squre;
     int sum;
};

struct lazyNode{
     int value;
     int type;
};

void buildTree(int *arr, treeNode *tree, int treeIndex, int start,int end){

     if(start == end){
          tree[treeIndex].sum = arr[start];
          tree[treeIndex].squre = arr[start]*arr[start];
          return;
     }

     int mid = (start + end)/2;
     buildTree(arr,tree,2*treeIndex,start,mid);
     buildTree(arr,tree,2*treeIndex+1,mid+1,end);
     tree[treeIndex].squre = tree[2*treeIndex].squre + tree[2*treeIndex + 1].squre;
     tree[treeIndex].sum = tree[2*treeIndex].sum + tree[2*treeIndex + 1].sum;
}

void updateLazy(treeNode *tree, lazyNode *lazy, int start, int end, int left, int right, int treeIndex, int value, int type){

     if(start > end)
          return;

     if(lazy[treeIndex] != 0){
          tree[treeIndex] += lazy[treeIndex];

          if(start != end){
               lazy[2*treeIndex] += lazy[treeIndex]
               lazy[2*treeIndex + 1] += lazy[treeIndex]
          }
          lazy[treeIndex] = 0;
     }

     if(end < left || start > right)
          return;

     if(start >= left && end <= right){
          tree[treeIndex] += value;

          if(start != end){
               lazy[2*treeIndex] += value;
               lazy[2*treeIndex+1] += value;
          }
          return;
     }

     int mid = (start + end)/2;
     updateLazy(tree,lazy,start,mid,left,right,2*treeIndex,value);
     updateLazy(tree,lazy,mid + 1,end,left,right,2*treeIndex+1,value);
     tree[treeNode] = min(tree[2*treeIndex], tree[2*treeIndex+1]);

}

int main(){
     int n;
     cin >> n;
     int *arr = new int[n];
     for(int i = 0; i < n; i++)
          cin >> arr[i];


     treeNode *tree = new treeNode[4*n]();
     lazyNode *lazy = new lazyNode[4*n]();
     buildTree(arr,tree,1,0,n-1);

     delete[] arr;
     delete[] tree;
     delete[] lazy;
}
