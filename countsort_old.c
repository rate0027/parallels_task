#include <stdio.h>
#include "mpi.h"

/* キーは0からMまでの範囲の整数 */
#define  M   100

void counting_sort(int a[], int b[], int n);
void print_data(int data[], int length);

/* ソートするデータ */
int src_data[] = {8,4,10,3,8,5,13,3,11,55,44,44};
#define N sizeof(src_data) / sizeof(src_data[0]) /* 要素素 */

/* 作業用配列 */
int work_data[N-1];

/* キーの分布を数え上げるための配列 */
int count[M+1], reccount[M+1];

int  myid, numprocs;


int main(int argc, char **argv)
{
  
  MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
	MPI_Comm_rank(MPI_COMM_WORLD, &myid);

	if (myid == 0)
	{
	  printf("unsorted:\n");
	  print_data(src_data, N);
	}

	int i;
  /* カウンタをすべて0にする */
  for (i = 0; i <= M; i++)
	{
    count[i] = 0; 
	  reccount[i] = 0;
	}

	
	/* counting sort */
	counting_sort(src_data, work_data, N);
	
  if (myid==0)
	{
    printf("sorted:\n");
    print_data(work_data, N);
	}
	
	MPI_Finalize();
  return 0;
}

/* 大きさnの配列aを分布数え上げソートによって整列する。
 *  *    結果は配列bに得られる */
void counting_sort(int a[], int b[], int n)
{
	int x, low, high, i;

	/* データをブロードキャスト */
	MPI_Bcast(a, n, MPI_INT, 0, MPI_COMM_WORLD);
	MPI_Bcast(count, n, MPI_INT, 0, MPI_COMM_WORLD);

	/* 1プロセスあたりの処理数 */
	x = n / numprocs; 
	/* 処理範囲を計算 
	 * @low  : 下限
	 * @high : 上限*/
	low = myid * x; 
	high = low + x;

  /* キーを数え上げる */
  for (i = low; i < high; i++)
    count[a[i]]++;

  MPI_Reduce(&count, &reccount, M, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
	
	
	if (myid == 0)
	{
	  /* 数え上げたキーの累積度数分布を求める */
    for (i = 0; i < M; i++) {
      reccount[i+1] += reccount[i];
    }

    /* 度数分布に従ってデータを配列aから配列bにコピーする */
    for (i = n - 1; i >= 0; i--) {
      b[--reccount[a[i]]] = a[i];
    }
	}

}

void print_data(int data[], int length)
{
  int i;
	printf("%d",data[0]);
  for (i = 1; i < length; i++) {
    printf(", %d", data[i]);
  }
	printf("\n");
}
