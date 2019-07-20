#include<bits/stdc++.h>
using namespace std;

void updateLazy(int *tree, int *lazy, int start, int end, int left, int right, int treeNode, int value){

     if(start > end)
          return;

     if(lazy[treeNode] != 0){
          tree[treeNode] += lazy[treeNode];

          if(start != end){
               lazy[2*treeNode] += lazy[treeNode];
               lazy[2*treeNode + 1] += lazy[treeNode];
          }

          lazy[treeNode] = 0;
     }

     if(end < left || start > right)
          return;

     if(start >= left && end <= right){
          tree[treeNode] += value;

          if(start != end){
               lazy[2*treeNode] += value;
               lazy[2*treeNode + 1] += value;
          }
          return;
     }

     int mid = (start + end)/2;
     updateLazy(tree,lazy,start,mid,left,right,2*treeNode,value);
     updateLazy(tree,lazy,mid + 1,end,left,right,2*treeNode+1,value);
     tree[treeNode] = min(tree[2*treeNode], tree[2*treeNode+1]);
}

void buildTree(int *arr, int *tree, int treeNode, int start, int end){

     if(start == end){
          tree[treeNode] = arr[start];
          return;
     }

     int mid = (start + end)/2;
     buildTree(arr,tree,2*treeNode,start,mid);
     buildTree(arr,tree,2*treeNode+1,mid+1,end);
     tree[treeNode] = min(tree[2*treeNode], tree[2*treeNode + 1]);
}

int main(){
     int arr[] = {1,3,-2,4};
     int *tree = new int[12]();
     buildTree(arr,tree,1,0,3);

     int *lazy = new int[12]();

     updateLazy(tree,lazy,0,3,0,3,1,3);
     updateLazy(tree,lazy,0,3,0,1,1,2);

     for(int i = 0; i < 12; i++)
          std::cout << tree[i] << '\n';
          std::cout << "/* message */" << '\n';
     for(int i = 0; i < 12; i++)
          std::cout << lazy[i] << '\n';

     delete[] tree;
     delete[] lazy;
}
