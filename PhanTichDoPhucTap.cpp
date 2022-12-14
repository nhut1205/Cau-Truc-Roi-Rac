//#include <stdio.h>
//#include <conio.h>
//#define Max 100
//
//void nhapMang(int a[Max], int n)
//{
//	for (int i = 0; i < n; i++)
//	{
//		scanf_s("%d", &a[i]);
//	}
//}
//
//void xuatMang(int a[Max], int n)
//{
//	for (int i = 0; i < n; i++)
//	{
//		printf("%d ", a[i]);
//	}
//}
//
//int TKT(int a[Max], int n, int k)
//{
//	for (int i = 0; i < n; i++)
//	{
//		if (a[i] == k)
//		{
//			return k;
//		}
//	}
//	return -1;
//}
//
//int TKTT(int a[Max], int n, int k)
//{
//	for (int i = 0; i < n; i++)
//	{
//		if (a[i] == k)
//		{
//			return i;
//		}
//	}
//	return -1;
//}
//
//int tinhDoPT(int a[Max], int n, int k)
//{
//	int doPhucTap = 0;
//	for (int i = 0; i < n; i++)
//	{
//		if (a[i] == k)
//		{
//			doPhucTap = (i + 1) * 1;
//			return i;
//		}
//	}
//	doPhucTap = n * 1;
//	return -1;
//}
//
//void BubbleSort(int a[], int n)
//{
//	for (int i = 0; i < n - 1; i++){
//		for (int j = n - 1; j > i; j--){
//			if (a[j - 1] > a[j])
//			{
//				int t = a[j - 1];
//				a[j - 1] = a[j];
//				a[j] = t;
//			}
//		}
//	}
//}
//
//void doPhucTapBubbleSort(int a[], int n)
//{
//	int o1 = 0, o2 = 0, o = 0;
//	int sll = 0;
//	for (int i = 0; i < n - 1; i++){
//		for (int j = n - 1; j > i; j--){
//			if (a[j - 1] > a[j])
//			{
//				int t = a[j - 1];
//				a[j - 1] = a[j];
//				a[j] = t;
//			}
//		}
//		sll++;
//		o1 = (n - 1 - i) * 1;
//		printf("\n");
//		printf("Do phuc tap cua ham for(j) : O(%d)", o1);
//	}
//	o2 = (n - 1)*sll;
//	printf("\n");
//	printf("Do phuc tap cua ham for(i) : O(%d)", o2);
//	printf("\n");
//	printf("Do phuc tap cua thuat toan : %d)", o2);
//}
////
////void taoMaTran(arr[][Max] , int dong , int cot)
////{
////	for (int i = 0; i < dong; i++)
////	{
////		for (int j = 0 ; j < cot; j++)
////		{
////			printf("")
////		}
////	}
////}
//
//void tich2MaTran(int a[][Max], int b[][Max], int c[][Max], int n)
//{
//	for (int i = 0; i < n; i++)
//	for (int j = 0; i < n; j++)
//	{
//		c[i][j] = 0;
//		for (int k = 0; k < n; k++)
//			c[i][j] += a[i][k] * b[k][j];
//	}
//}
//
//void menu()
//{
//	printf("\n");
//	printf("1.Do phuc tap cua TKTT\n");
//	printf("2.Do phuc tap bubleSort");
//}
//
//int main()
//{
//	int arr[Max];
//	int n;
//	printf("Nhap so phan tu cua mang : ");
//	scanf_s("%d", &n);
//	nhapMang(arr, n);
//	int x;
//	xuatMang(arr, n);
//	printf("\n");
//	int luachon;
//	do
//	{
//		menu();
//		printf("\n");
//		printf("Nhap lua chon : ");
//		scanf_s("%d", &luachon);
//		switch (luachon)
//		{
//		case 1 : 
//		printf("Nhap gia tri can tim : ");
//		scanf_s("%d", &x);
//		if (TKT(arr, n, x) == x)
//			printf("tim thay %d tai vi tri %d", x, TKTT(arr, n, x));
//		else
//			printf("Khong tim thay");
//		printf("\n");
//		printf("Do phuc tap cua thuat toan : O(%d)", tinhDoPT(arr, n, x));
//		break;
//		case 2 : 
//			xuatMang(arr, n);
//			printf("Mang sau khi sap xep");
//			BubbleSort(arr,n);
//			xuatMang(arr, n);
//			doPhucTapBubbleSort(arr, n);
//			break;
//		}
//	} while (luachon != 0);
//	_getch();
//	return 0;
//}