#include  <stdio.h>

#define M 100 /* データ範囲の最大値 */

void Bucket_Sort(int data[], int outdata[], int);
void print_data(int data[]);

int main()
{
  int array[M], out[M],  num, i;

  printf("Enter How many Numbers :");
  scanf("%d", &num);

  printf("Enter the %d elements to be sorted : \n" ,num);
  for(i = 0; i < num; i++)
	    scanf("%d", &array[i]);

  printf("\n The array of elements before sorting : \n");
	print_data(array);

  printf("\n The array of elements after sorting : \n");
  Bucket_Sort(array, out, num);
	
	print_data(out);

  return 0;
}

void Bucket_Sort(int data[], int outdata[], int n)
{
	int i, pivot = 0;
	int arraynum = sizeof data / sizeof data[0];
//	int arraynum = n;
	int count[M+1];

	for (i=0; i<M; i++)
	{
    count[i] = 0;
	}

	for (i=0;i<arraynum;i++) 
	{
		count[data[i]]++;
	}

	for (i=0;i<M;i++)
	{
    while(count[i]>0)
		{
      outdata[pivot] = count[i];
			pivot++;
	    count[i]--;
		}
	}


}

void print_data (int data[])
{
	int i;
	int dataNum = sizeof data / sizeof data[0];
	printf("%d",data[0]);
  for(i = 1; i < dataNum; i++)
	{
    printf(",%d", data[i]);
	}		
	printf("\n");
}
