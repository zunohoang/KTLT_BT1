#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void input(int* n, int **p){
	printf("Moi nhap n: ");
	scanf("%d", n);
	*p = (int*)malloc(*n * sizeof(int));
	for(int i = 0; i < *n; i++){
		printf("Moi nhap a[%d]: ", i);
		scanf("%d", (*p + i));
	}	
}

void output(int n, int *p){
	printf("Day vua nhap la: ");
	for(int i = 0; i < n; i++){
		printf("%d ", *(p + i));
	}
	printf("\n");
}

bool divOk(int a, int b){
	if(a % b == 0) return true;
	return false;
}

int countResult(int n, int* p, int k){
	if(*(p + 0) == k) return -1;
	int cnt = 0;
	for(int i = 0; i < n; i++){
		if(divOk(*(p + i), *(p + 0))){
			cnt++;
		}
	}
	return cnt;
}

int* findMax(int n, int* p){
	int max1 = 0;
	int key1 = 0;
	int max2 = 0;
	int key2 = 0;
	int max3 = 0;
	int key3 = 0;
	for(int i = 0; i < n; i++){
		if(*(p + i) > max1){
			key1 = i;
			max1 = *(p + i);
		}
	}
	for(int i = 0; i < n; i++){
		if(*(p + i) > max2 && i != key1){
			key2 = i;
			max2 = *(p + i);
		}
	}
	for(int i = 0; i < n; i++){
		if(*(p + i) > max3 && i != key1 && i != key2){
			key3 = i;
			max3 = *(p + i);
		}
	}
	int* res = (int*)malloc(3 * sizeof(int));
	*(res) = max1;
	*(res + 1) = max2;
	*(res + 2) = max3;
	return res;
}

int* findMaxSum(int n, int* p){
	int sumMax = 0;
	int start = 0;
	int end = 0;
	int* preSum = (int*)malloc(n * sizeof(int));
	*preSum = *(p + 0);
	for(int i = 1; i < n; i++) *(preSum + i) = *(preSum + i - 1) + *(p + i);
	for(int i = 2; i < n; i++){
		if(sumMax < *(preSum + i) - *(preSum + i - 3)){
			sumMax = *(preSum + i) - *(preSum + i - 3);
			start = i - 2;
			end = i;
		}
	}
	int* res = (int*)malloc(3 * sizeof(int));
	*res = *(p + start);
	*(res + 1) = *(p + start + 1);
	*(res + 2) = *(p + start + 2);
	return res;
}

int findMinD(int n, int* p){
	for(int i = 0; i < n; i++){
		if(*(p + i) % 2 == 0){
			int min = *(p + i);
			for(int j = 0; j < n; j++){
				min = ((min > *(p + j) && *(p + j) % 2 == 0) ? *(p + j) : min);
			}	
			return min;
		}
	}
	return -1;
}

int main(){
	int n;
	int *p;
	input(&n, &p);
	output(n, p);
	// b
	int x = countResult(n, p, 0);
	if(x == -1) printf("Phan tu dau tien la %d \n", 0);
	else printf("So phan tu chia het cho %d la %d \n", *(p + 0) , x);
	// c
	int* res = findMax(n, p);
	printf("3 phan tu lon nhat vua nhap la: %d, %d, %d\n", *(res), *(res + 1), *(res + 2));
	free(res); 
	// d
	int* resSum = findMaxSum(n, p);
	printf("3 phan tu lien tiep tao tong max la: %d, %d, %d\n", *resSum, *(resSum + 1), *(resSum + 2));
	free(resSum);
	// d
	int resUp = findMinD(n, p);
	if(resUp == -1) printf("Khong co phan tu duong nao \n");
	else printf("Phan tu duong nho nhat la %d \n", *(p + resUp));
	free(p);
}
