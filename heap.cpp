#include<bits/stdc++.h>
using namespace std;

struct heap {

     int length;
     int capacity;
     int *arr;
};

// intializing new heap element and add array of length n
struct heap *createHeap(int capacity){
     struct heap *hp = new heap;
     hp->capacity = capacity;
     hp->length = 0;
     hp->arr = new int[capacity];
     return hp;
}

void swap_element(int *a, int *b){
     int temp = *a;
     *a = *b;
     *b = temp;
}

void heapify(struct heap *hp, int index){

     int smallest = index;
     int left_child = 2*smallest + 1;
     int right_child = 2*smallest + 2;

     if(left_child < hp->length && hp->arr[smallest] > hp->arr[left_child])
          smallest = left_child;
     else if(right_child < hp->length && hp->arr[right_child]  < hp->arr[smallest])
          smallest = right_child;

     if(smallest != index){
          swap_element(&hp->arr[smallest], &hp->arr[index]);
          heapify(hp, smallest);
     }
}

bool stop_heap(struct heap *hp){
     return hp->length == 1;
}

// get min element as firsr element from heap and replace the min element by last element
// decreasing the length of heap array and heapify the heap again

// basically delete first element which will also be the smallest
int extractMin(struct heap *hp){
     int temp = hp->arr[0];
     hp->arr[0] = hp->arr[hp->length - 1];
     hp->length = hp->length - 1;
     heapify(hp, 0);
     return temp;
}

void insert(struct heap *hp, int element){
     hp->length = hp->length + 1;
     int i = hp->length - 1;
     while(i && (element < hp->arr[(i-1)/2])){
          hp->arr[i] = hp->arr[(i-1)/2];
          i = (i-1)/2;
     }

     hp->arr[i] = element;
}

struct heap *buildHeap(int arr[] , int size){
     struct heap *hp = createHeap(size);
     hp->length = size;

     for(int i = 0; i < size; i++)
          hp->arr[i] = arr[i];

     int n = hp->length - 1;
     int i ;

     for(i = (n - 1)/2; i >= 0; --i)
          heapify(hp,i);
          return hp;
}

int main(){

     int t;
     cin >> t;

     while(t--){

          int n;
          cin >> n;

          int arr[n];

          for(int i = 0; i < n; i++)
               cin >> arr[i];

          struct heap *hp = buildHeap(arr,n);
          long long cost = 0;

          while(!stop_heap(hp)){
               int i = extractMin(hp);
               int j = extractMin(hp);
               cost += i + j;
               insert(hp,i + j);
          }

          std::cout << cost << '\n';
     }

}
