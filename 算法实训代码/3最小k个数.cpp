#include <stdio.h>
#include <stdlib.h>
#define swap(a,b,t) (t=a,a=b,b=t)

void heap_sort_one(int* array, int father_index, int array_len)
{
    int child_index=0;
    int temp=0;

    for(child_index=father_index*2; child_index<=array_len; child_index=child_index*2)
    {
 
        if(child_index+1<=array_len && array[child_index]<array[child_index+1])
            child_index++;

        if(child_index<=array_len && array[father_index]<array[child_index])
        {
            swap(array[father_index],array[child_index],temp);
            father_index = child_index; 
        }
    }
}

void heap_sort_topK(int* array, int array_len, int k)
{
    int i;
    int temp=0;


    for(i=k/2; i>=1; i--) 
        heap_sort_one(array,i,k); 



    for(i=array_len-k; i<=array_len; i++)
    {
        if(array[i]<array[1])
        {
            swap(array[i],array[1],temp);
            heap_sort_one(array,1,k);
        }
    }
    printf("\n");
    for(i=1; i<=k; i++)
        printf("%d ",array[i]);
}
int main()
{
    int i=0;
    int array1[11]={1,5,4,9,7,4,8,3,11,2};
    for(i=1; i<11; i++)
        printf("%d ",array1[i]);
    printf("\n序列中最小的4个数为：");
    heap_sort_topK(array1,10,4);
    return 0;

} 
