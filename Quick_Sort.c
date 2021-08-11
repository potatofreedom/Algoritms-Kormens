#include <stdio.h>
#include <stdlib.h>

void quicksort(int block[],int first, int last){
   int left, right, pivot, temp;

   if(first < last)
   {
      pivot = first;
      left = first;
      right = last;

      while(left < right)
      {
         while(block[left] <= block[pivot] && left<last)
            left++;
         while(block[right] > block[pivot])
            right--;
         if(left < right){
            temp = block[left];
            block[left] = block[right];
            block[right] = temp;
         }
      }

      temp = block[pivot];
      block[pivot] = block[right];
      block[right] = temp;
      quicksort(block,first,right-1);
      quicksort(block,right+1,last);

   }
}

int main (int argc, char* argv[])
{
    int *block;
    int n;
    printf("Size of array= ");
    scanf("%d", &n);
    block = malloc(n* sizeof(int));
    for(int i = 0; i < n; ++i)
    {
        printf("block[%d]= ", i);
        scanf("%d", &block[i]);
    }
    printf("\n");
    quicksort(block,0,n-1);
    for(int i = 0; i < n; ++i)
    {
        printf("%d \t", block[i]);
    }
    
    free(block);
    return 0;
}

