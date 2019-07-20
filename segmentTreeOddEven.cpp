#include<bits/stdc++.h>
using namespace std;

struct Node{
     int odd;
     int even;
};

void buildTree(int *arr, Node *tree, int treeNode, int start, int end){

     if(start == end){
          if(arr[start]%2){
               //std::cout << arr[start] << ' ' << "odd" << endl;
               tree[treeNode].odd = 1;
               tree[treeNode].even = 0;
               return;
          }

          //std::cout << arr[start] << ' ' << "even" << endl;
          tree[treeNode].odd = 0;
          tree[treeNode].even = 1;
          return;
     }

     int mid = (start + end)/2;
     buildTree(arr,tree,2*treeNode,start,mid);
     buildTree(arr,tree,2*treeNode+1,mid+1,end);

     tree[treeNode].odd = tree[2*treeNode].odd + tree[2*treeNode + 1].odd;
     tree[treeNode].even = tree[2*treeNode].even + tree[2*treeNode + 1].even;
}

void update(int *arr, Node *tree, int treeNode, int start, int end, int index, int value){

     if(start == end){
          arr[index] = value;
          if(value%2){
               tree[treeNode].odd = 1;
               tree[treeNode].even = 0;
               return;
          }

          tree[treeNode].odd = 0;
          tree[treeNode].even = 1;
          return;
     }

     int mid = (start + end)/2;

     if(index > mid)
          update(arr,tree,2*treeNode + 1, mid +1, end, index, value);
     else
          update(arr,tree,2*treeNode, start, mid, index, value);

     tree[treeNode].odd = tree[2*treeNode].odd + tree[2*treeNode + 1].odd;
     tree[treeNode].even = tree[2*treeNode].even + tree[2*treeNode + 1].even;
}

Node query(Node *tree, int treeNode, int start, int end, int left, int right, Node extra){

     if(end < left || start > right)
          return extra;

     if(start >= left && end <= right)
          return tree[treeNode];

     int mid = (start + end)/2;

     Node left_node = query(tree,2*treeNode,start,mid,left,right,extra);
     Node right_node = query(tree,2*treeNode+1,mid + 1,end,left,right,extra);
     Node result;
     result.odd = left_node.odd + right_node.odd;
     result.even = left_node.even + right_node.even;
     return result;
}

int main(){
     int n;
     cin >> n;

     int *arr = new int[n];
     for(int i = 0; i < n; i++)
          cin >> arr[i];

     Node *tree = new Node[4*n];
     buildTree(arr,tree,1,0,n-1);




     int Q;
     cin >> Q;
     Node extra;
     extra.odd = 0;
     extra.even = 0;
     for(int i = 0; i < Q; i++){
          int q,left,right;
          cin >> q >> left >> right;

          if(q == 0)
               update(arr,tree,1,0,n-1,left-1,right);
          else{
               Node node = query(tree,1,0,n-1,left-1,right-1,extra);

               if(q%2)
                    std::cout << node.even << '\n';
               else
                    std::cout << node.odd << '\n';
          }
     }


     delete[] arr;
     delete[] tree;
     return 0;
}
