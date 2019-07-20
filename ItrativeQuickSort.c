#include<stdio.h>

void swap(int *i, int *j){
  int temp = *i;
  *i = *j;
  *j = temp;
}

int partition(int array[], int lower_index,int higher_index){
  int pivot = array[higher_index];
  int i = (lower_index-1);

  for(int j=lower_index;j<=higher_index-1;j++){
    if(array[j]<=pivot){
      i++;
      swap(&array[i],&array[j]);
    }
  }
  swap(&array[i+1],&array[higher_index]);
  return (i+1);
}

/*int partition (int arr[], int lower_index, int higher_index)
{
    int pivot = arr[higher_index];
    int i = (lower_index - 1);
    for (int j = l; j <= higher_index- 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap (&arr[i], &arr[j]);
        }
    }
    swap (&arr[i + 1], &arr[higher_index]);
    return (i + 1);
}*/

void quickSort(int array[],int lower_index,int higher_index){
  if(lower_index<higher_index){
    int pivot = partition(array,lower_index,higher_index);
    quickSort(array,lower_index,pivot-1);
    quickSort(array,pivot+1,higher_index);
  }
}

int main(){
  int n;
  scanf("%d",&n);

  int array[n];
  for(int i=0;i<n;i++)
    scanf("%d",&array[i]);

  quickSort(array,0,n-1);

  for(int i=0;i<n;i++)
    printf("%d\n",array[i]);
  //printf("\n");
}
