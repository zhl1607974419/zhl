#include <iostream>
#include<stdio.h> 
using namespace std;

void Merge(int A[], int TmpA[], int L, int R, int RightEnd)
{
	int LeftEnd, ElementNum, Tmp;
	LeftEnd = R - 1; 
	Tmp = L;  
	ElementNum = RightEnd - L + 1; 
	while (L <= LeftEnd && R <= RightEnd)
	{
		if (A[L] <= A[R])
			TmpA[Tmp++] = A[L++];
		else
			TmpA[Tmp++] = A[R++];
	}
	while (L <= LeftEnd)
		TmpA[Tmp++] = A[L++];
	while (R <= RightEnd)
		TmpA[Tmp++] = A[R++];
	for (int i = 0; i < ElementNum; i++, RightEnd--)
		A[RightEnd] = TmpA[RightEnd];
}
 

void Msort(int A[], int TmpA[], int L, int RightEnd)
{
	int Center;
	if (L < RightEnd)  
	{ 
		Center = (L + RightEnd) / 2;
		Msort(A, TmpA, L, Center);
		Msort(A, TmpA, Center + 1, RightEnd);
		Merge(A, TmpA, L, Center + 1, RightEnd);
	}
}
 

void MergeSort(int A[], int N)
{
	int *TmpA;  
	TmpA = new int[N];
	if (TmpA)
	{
		Msort(A, TmpA, 0, N - 1);
		delete[] TmpA;
	}
	else
		cout << "空间不足" << endl;
}
 
int main()
{
	int N, i;
		printf("请输入要排列的个数："); 
	cin >> N;
 
	int A[N]; 

	printf("请输入%d个整数排列: ", N);
	for(i = 0; i < N; i++)
	{
		cin >> A[i];
	}

	printf("它们从小到大的顺序为: ");
	MergeSort(A,N);

	for(i=0;i < N; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl;
	
	return 0;
}

