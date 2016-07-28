#include <stdio.h>

int DATA[] = {18, 4, 8, 2, 16, 5, 3, 12};
const int idNum = sizeof DATA / sizeof DATA[0];

int bubble_sort(int *data);
void list_view(int *data);

/* バブルソート */
int bubble_sort(int *data) {
	int tmp;
  for (int j=1;j<idNum-1;j++) {
	  for (int i=0;i<idNum-j;i++) {
	    if (data[i] > data[i+1]) {
			  tmp = data[i];
			  data[i] = data[i+1];
			  data[i+1] = tmp;
		  }
	  }
  }
	return 0;
}

/* 配列の中身を表示する */
void list_view(int *data) {

	printf("%d", data[0]);
	for (int i=1; i<idNum; i++) {
    printf(", %d", data[i]);
	}
	printf("\n");

}

int main () {
	
	printf("元のデータ:\n");
	list_view(DATA);
	printf("\n");
	
	printf("要素数:%d\n", idNum);	

	printf("そーとなう\n");
	bubble_sort(DATA);
	
	printf("\n");

	list_view(DATA);

	return 0;
}
