#include<stdio.h>

//Ö±½Ó²åÈëÅÅÐòËã·¨----´ø¡°ÉÚ±ø¡±·¨
#define MAXSIZE 10
/*int main()
{
	int arr[MAXSIZE + 1] = { 0,3,5,6,7,12,48,69,13,2,11 };
	for (int i = 2; i < MAXSIZE + 1; i++)
	{
		if (arr[i - 1] < arr[i])
		{

		}
		else
		{
			arr[0] = arr[i];
			int j;
			for ( j = i - 1; arr[0] < arr[j]; j--)
			{
				arr[j + 1] = arr[j];
			}
			arr[j + 1] = arr[0];
		}
	}
	for (int i = 1; i < MAXSIZE+1; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}*/
//ÕÛ°ë²åÈëÅÅÐò
//int main()
//{
//	int arr[MAXSIZE + 1] = { 0,3,5,6,7,12,48,69,13,2,11 };
//	for (int i = 2; i < MAXSIZE + 1; i++)
//	{
//		if (arr[i - 1] < arr[i])
//		{
//		}
//		else
//		{
//			arr[0] = arr[i];
//			//ÕÛ°ë²åÈë
//			int j = i - 1;
//			int right = j;
//			int left = 1;
//			int mid;
//			while (left <= right)
//			{
//				mid = (left + right) / 2;
//				if (arr[0] < arr[mid])
//				{
//					right = mid - 1;
//				}
//				else if (arr[0] > arr[mid])
//				{
//					left = mid + 1;
//				}
//
//			}
//			for ( j = i-1; j>=right+1 ;  j--)
//			{
//				arr[j + 1] = arr[j];
//			}
//			arr[right+1] = arr[0];
//		}
//	}
//	for (int i = 1; i < MAXSIZE + 1; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}
//#include <stdio.h>
//void shellSort(int arr[], int n) {
//	int gap, i, j, temp;
//	for (gap = n / 2; gap > 0; gap /= 2) {
//		for (i = gap; i < n; i++) {
//			temp = arr[i];
//			for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
//				arr[j] = arr[j - gap];
//			}
//			arr[j] = temp;
//		}
//	}
//}
//int main() {
//	int arr[] = { 12,37,54,2,3,52,15,36,78,45,96,18,26};
//	int n = sizeof(arr) / sizeof(arr[0]);
//
//	shellSort(arr, n);
//
//	for (int i = 0; i < n; i++) {
//		printf("%d ", arr[i]);
//	}
//
//	return 0;
//}

//Ã°ÅÝÅÅÐò
//void bubble_sort(int arr[],int sz)
//{
//	int tmp; 
//	int flag;
//	for (int i = 0; i < sz-1; i++)
//	{
//		 flag = 0;
//		for (int j = 0; j <sz-1-i; j++)
//		{
//			if (arr[j]>arr[j+1])
//			{
//				tmp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = tmp;
//				flag = 1;
//			}
//		}
//		if (flag==0)
//		{
//			return;
//		}
//	}
//}
//int main()
//{
//	int arr[] = { 12,5,4,8,65,36 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	bubble_sort(arr, sz);
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//
//
//	return 0;
//}

//¿ìËÙÅÅÐò

//int find_mid(int arr[],int left,int right)
//{
//	arr[0] = arr[left];
//	arr[left] = 0;
//	while (left<right)
//	{
//		while (arr[right]>=arr[0])
//		{
//			right--;
//		}
//		arr[left] = arr[right];
//		arr[right] = 0;
//		while (arr[left]<=arr[0])
//		{
//			left++;
//		}
//		arr[right] = arr[left];
//		arr[left] = 0;
//	}
//	arr[left] = arr[0];
//	arr[0] = 0;
//	return left;
//}
//int find_mid(int arr[], int left, int right) {
//
//	int pivot = arr[left];
//
//	while (left < right) {
//		while (arr[right] >= pivot && left < right) {
//			right--;
//		}
//		arr[left] = arr[right];
//
//		while (arr[left] <= pivot && left < right) {
//			left++;
//		}
//		arr[right] = arr[left];
//	}
//	arr[left] = pivot;
//	return left;
//}
//void QS_sort(int arr[],int left,int right)
//{
//	int mid_location;
//	if (left<right)
//	{
//		mid_location = find_mid(arr,left,right);
//		QS_sort(arr,left, mid_location-1);
//		QS_sort(arr, mid_location+1,right);
//	}
//}
//
//int main()
//{
//	int arr[] = {0,12,5,4,8,65,36,52,45,15,34};
//
//	int left = 1;
//	int right = sizeof(arr) / sizeof(arr[0])-1;
//
//	QS_sort(arr, left, right);
//
//	for (int i = 1; i < sizeof(arr)/ sizeof(arr[0]); i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}

//¼òµ¥¿ìËÙÅÅÐò

//void easy_sort(int arr[],int sz)
//{
//	for (int i = 0; i < sz-1; i++)
//	{
//		int tmp;
//		int min = i;
//		for (int j = i+1; j < sz; j++)
//		{
//			if (arr[min]>arr[j])
//			{
//				min = j;
//			}
//		}
//		tmp = arr[i];
//		arr[i] = arr[min];
//		arr[min] = tmp;
//	}
//}
//int main()
//{
//	int arr[] = { 15,45,65,25,36,47,9,3,12 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	easy_sort(arr, sz);
//
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}

//Ò»Î¬¶ÑÅÅÐò




int main()
{





	return 0;
}