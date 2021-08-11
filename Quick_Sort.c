#include <stdio.h>
#include <stdlib.h>

void QuickSort(int *Array,int first, int last){
   int left = 0, right = 0, pivot = 0, temp = 0;

   if(first < last)
   {
      pivot = first;
      left = first;
      right = last;

      while(left < right)
      {
         while(Array[left] <= Array[pivot] && left<last)
         {
            left++;
         }
         while(Array[right] > Array[pivot])
         {
            right--;
         }
         if(left < right)
         {
            temp = Array[left];
            Array[left] = Array[right];
            Array[right] = temp;
         }
      }

      temp = Array[pivot];
      Array[pivot] = Array[right];
      Array[right] = temp;
      quicksort(Array,first,right-1);
      quicksort(Array,right+1,last);

   }
}

int main (int argc, char* argv[])
{
    int *Array = NULL;
    int Size_Array = 0;
    printf("Size of array= ");
    scanf("%d", &Size_Array);
    Array = malloc(Size_Array* sizeof(int));
    for(int i = 0; i < Size_Array; ++i)
    {
        printf("block[%d]= ", i);
        scanf("%d", &Array[i]);
    }
    printf("\n");
    QuickSort(Array,0,Size_Array-1);
    for(int i = 0; i < Size_Array; ++i)
    {
        printf("%d \t", Array[i]);
    }
    
    free(Array);
    return 0;
}
