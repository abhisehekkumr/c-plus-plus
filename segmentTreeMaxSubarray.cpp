#include<bits/stdc++.h>
#define inf 0x3f3f
using namespace std;

struct Node{
     int prifix;
     int suffix;
     int total;
     int maxSum;

     Node(){
          prifix = -inf;
          suffix = -inf;
          total = -inf;
          maxSum = -inf;
     }
};

Node merge(Node left_child, Node right_child){
     Node parent;
     parent.prifix = max(left_child.prifix, left_child.total + right_child.prifix);
     parent.suffix = max(right_child.suffix, right_child.total + left_child.suffix);
     parent.total = left_child.total + right_child.total;
     parent.maxSum = max({ left_child.maxSum,
                           right_child.maxSum,
                           left_child.suffix + right_child.prifix,
                           left_child.total + right_child.prifix,
                           left_child.suffix + right_child.total
                      });
     return parent;
}


void buildTree(int *arr, Node *tree, int treeNode, int start, int end){

     if(start == end){
          tree[treeNode].prifix = arr[start];
          tree[treeNode].suffix = arr[start];
          tree[treeNode].total = arr[start];
          tree[treeNode].maxSum = arr[start];
          return;
     }

     int mid = (start + end)/2;
     buildTree(arr,tree,2*treeNode,start,mid);
     buildTree(arr,tree,2*treeNode+1,mid+1,end);
     tree[treeNode] = merge(tree[2*treeNode],tree[2*treeNode+1]);
}

Node query(Node *tree, int treeNode, int start, int end, int left, int right){

     if(end < left || start > right){
          Node extra;
          return extra;
     }

     if(start >= left && end <= right)
          return tree[treeNode];

     int mid = (start + end)/2;
     Node left_child = query(tree,2*treeNode,start,mid,left,right);
     Node right_child = query(tree,2*treeNode+1,mid+1,end,left,right);
     Node parent = merge(left_child,right_child);
     return parent;
}

int main(){
     int n;
     cin >> n;
     int *arr = new int[n];
     for(int i = 0; i < n; i++)
          cin >> arr[i];

     Node *tree = new Node[4*n];
     buildTree(arr,tree,1,0,n-1);

     int q;
     cin >> q;

     for(int i = 0; i < q; i++){

          int left,right;
          cin >> left >> right;
          Node node = query(tree,1,0,n-1,left-1,right-1);
          std::cout << node.maxSum << '\n';
     }

     delete[] arr;
     delete[] tree;
     return 0;
}
