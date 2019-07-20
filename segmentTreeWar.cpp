#include<bits/stdc++.h>
using namespace std;

struct Node{
     int A;
     int B;
     int index;
};

void buildTree(Node *arr, Node *tree, int treeNode, int start, int end){

     if(start == end){
          tree[treeNode].A = arr[start].A;
          tree[treeNode].B = arr[start].B;
          tree[treeNode].index = start;

          //std::cout << tree[treeNode].A << " " << tree[treeNode].B  << " " << tree[treeNode].index  << '\n';
          return;
     }

     int mid = (start + end)/2;
     buildTree(arr, tree, 2*treeNode, start, mid);
     buildTree(arr, tree, 2*treeNode+1, mid + 1, end);

     Node left1 = tree[2*treeNode];
     Node right1 = tree[2*treeNode + 1];

     if(left1.A == right1.B){

          if(left1.B < right1.B)
               tree[treeNode] = left1;
          else if(left1.B > right1.B)
               tree[treeNode] = right1;
          else{

               if(left1.index < right1.index)
                    tree[treeNode] = left1;
               else
                    tree[treeNode] = right1;
          }
          return;
     }

     if(left1.A > right1.A)
          tree[treeNode] = left1;
     else
          tree[treeNode] = right1;
}

Node query(Node *tree, int treeNode, int start, int end, int left, int right, Node extra){

     if(end < left || start > right)
          return extra;

     if(start >= left && end <= right)
          return tree[treeNode];

     int mid = (start + end)/2;
     Node left1 = query(tree,2*treeNode, start, mid, left,right,extra);
     Node right1 = query(tree,2*treeNode+1, mid+1, end, left,right,extra);

     Node node;

     if(left1.A == right1.B){

          if(left1.B < right1.B)
               node = left1;
          else if(left1.B > right1.B)
               node = right1;
          else{

               if(left1.index < right1.index)
                    node = left1;
               else
                    node = right1;
          }
          return node;
     }

     if(left1.A > right1.A)
          node = left1;
     else
          node = right1;
     return node;
}

int main(){

     int n;
     cin >> n;

     Node *war = new Node[n];
     for(int i = 0; i < n; i++)
          cin >> war[i].A;

     for(int i = 0; i < n; i++)
          cin >> war[i].B;

     Node *tree = new Node[4*n];

     int Q;
     cin >> Q;

     Node extra;
     extra.A = INT_MIN;
     extra.B = INT_MAX;
     buildTree(war,tree,1,0,n-1);

     for(int i = 0; i < Q; i++){
          int left,right;
          cin >> left >> right;

          Node node = query(tree,1,0,n-1,left-1,right-1,extra);
          std::cout << node.index + 1<< '\n'; //<< " " << node.A << " " << node.B << '\n';
     }

     delete[] tree;
     delete[] war;
     return 0;
}
