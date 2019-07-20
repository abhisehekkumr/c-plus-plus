#include<bits/stdc++.h>
using namespace std;

struct Node{
     int max;
     int smax;
};

void buildTree(int *arr, Node *tree, int treeNode, int start, int end){

     if(start == end){
          tree[treeNode].max = arr[start];
          tree[treeNode].smax = INT_MIN;
          return;
     }

     int mid = (start + end)/2;
     buildTree(arr, tree, 2*treeNode, start, mid);
     buildTree(arr, tree, 2*treeNode + 1, mid+1, end);
     Node left = tree[2*treeNode];
     Node right = tree[2*treeNode + 1];

     tree[treeNode].max = max(left.max, right.max);
     tree[treeNode].smax = min( max(left.max, right.smax), max(left.smax, right.max));
}

void update(int *arr, Node *tree, int treeNode, int start, int end, int index, int value){

     if(start == end){
          arr[index] = value;
          tree[treeNode].max = value;
          tree[treeNode].smax = INT_MIN;
          return;
     }

     int mid = (start + end)/2;

     if(index > mid)
          update(arr,tree,2*treeNode+1, mid + 1, end, index, value);
     else
          update(arr,tree,2*treeNode,start,mid, index, value);

     Node left = tree[2*treeNode];
     Node right = tree[2*treeNode + 1];

     tree[treeNode].max = max(left.max, right.max);
     tree[treeNode].smax = min( max(left.max, right.smax), max(left.smax, right.max));
}



Node query(Node *tree, int treeNode, int start, int end, int left, int right,Node extra){

     if(end < left || start > right)
          return extra;

     if(start >= left && end <= right)
          return tree[treeNode];

     int mid = (start + end)/2;
     Node left1 = query(tree,2*treeNode, start, mid, left,right,extra);
     Node right1 = query(tree, 2*treeNode+1, mid + 1, end, left,right,extra);

     int global_max = max(left1.max, right1.max);
     int global_min = min( max(left1.max, right1.smax), max(left1.smax, right1.max));
     Node node;
     node.max = global_max;
     node.smax = global_min;
     return node;
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
     Node extra;
     extra.max = INT_MIN;
     extra.smax = INT_MIN;
     for(int i = 0; i < q; i++){
          char c;
          int left,right;

          cin >> c >> left >> right;

          if(c == 'Q'){
               Node node = query(tree,1,0,n-1,left-1,right-1,extra);
               std::cout << node.max + node.smax << '\n';
          }else
               update(arr,tree,1,0,n-1,left-1,right);
     }

     delete[] arr;
     delete[] tree;
}
