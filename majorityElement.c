#include<stdio.h>

void merge(int arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
    /* create temp arrays */
    int L[n1], R[n2]; 
  
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
  
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = l; // Initial index of merged subarray 
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    /* Copy the remaining elements of L[], if there 
       are any */
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    /* Copy the remaining elements of R[], if there 
       are any */
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
  
/* l is for left index and r is right index of the 
   sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r) 
{ 
    if (l < r) 
    { 
        // Same as (l+r)/2, but avoids overflow for 
        // large l and h 
        int m = l+(r-l)/2; 
  
        // Sort first and second halves 
        mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r); 
  
        merge(arr, l, m, r); 
    } 
} 
  
 
  

int main() 
{ 
    int t;
    scanf("%d",&t);

    while(t--){
        int n;
        scanf("%d",&n);

        int arr[n];

        for(int i=0; i<n ;i++)
            scanf("%d",&arr[i]);
        mergeSort(arr, 0, n - 1);



        int max = 0, elemennt = 0,count = 0;

        int index=0,i;
        
        for(int i; i<n-1; i++){
            if(arr[i] == arr[i + 1])
                count++;
            else if(i > 0 && arr[i] == arr[i-1]){
                if(max < count){
                    max = count;
                    elemennt = arr[i];
                    count = 0;
                }
            }else{

                if(max < count){
                    max = count;
                    elemennt = arr[i];
                    count = 0;
                }

                count = 0;

            }

          
        }

          if(i == n-1 && arr[i-1] == arr[i]){
                count++;

                if(max < count){
                    max = count;
                    elemennt = arr[i];
                    count = 0;
                }
            }

        if(max > (int)n/2)
            printf("%d\n",elemennt);
        else
            printf("-1\n");
    }
} 


// 1 2 1 2 0 1 0 1 2