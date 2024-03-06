#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void input(int* n, int **a){
	printf("Moi nhap n: ");
	scanf("%d", n);
	*a = (int*)malloc((*n + 1)*(*n + 1)*sizeof(int));
	for(int i = 1; i <= *n; i++){
		for(int j = 1; j <= *n; j++){
			printf("Moi nhap a[%d][%d]: ", i, j);
			scanf("%d", *a + (i - 1)*(*n) + j);
		}
	}
}

void output(int n,int* a){
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			printf("%d ", *(a + (i - 1)*(n) + j));
		}
		printf("\n");
	}
}

float tbcCheoChinh(int n,int* a){
	float sum = 0;
	for(int i = 1; i <= n; i++){
		sum += *(a + (i-1)*n + i);
	}
	return sum/n;
}

int chanMaxTrenCheoChinh(int n,int *a){
	int max = -1;
	for(int i = 1; i <= n; i++){
		for(int j = i + 1; j <= n; j++){
			max = ((*(a + (i-1)*n + j) > max && *(a + (i-1)*n + j) % 2 == 0) ? *(a + (i-1)*n + j) : max);
		}
	}
	return max;
}

bool kiemTraMaTranTamGiacDuoi(int n,int* a){
	for(int i = 1; i <= n; i++){
		for(int j = i + 1; j <= n; j++){
			if(*(a + (i-1)*n + j) != 0) return false;
		}
	}
	return true;
}

int main(){
	int n;
	int *p;
	input(&n, &p);
	output(n, p);
	// b
	printf("Trung binh cong tren duong cheo chinh la: %.2f \n", tbcCheoChinh(n,p));
	// c
	int x = chanMaxTrenCheoChinh(n,p);
	if(x == -1) printf("Khong co phan tu chan \n");
	else printf("Phan tu chan lon nhat tren duong cheo chinh la %d \n", x);
	// d
	if(kiemTraMaTranTamGiacDuoi(n,p)) printf("La ma tran duong cheo duoi \n");
	else printf("Khong phai la ma tran duong cheo duoi \n");
}
/*
1 2 3
4 5 6
7 8 9

(i-1)*n + j
*/
