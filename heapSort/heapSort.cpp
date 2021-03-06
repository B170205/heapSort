// ShellSort.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#include<conio.h>
void sift(int a[], int low, int high)
{
	int i, j, tmp;
	i = low;
	j = 2 * i;
	tmp = a[i];
	while(j<=high)//没到最下层，该子树继续分裂为最大堆
	{
		if ((j<high)&&(a[j] < a[j + 1]))//如果不是最后一个叶子节点，则比较左右叶子节点的值，取大者，如果是最后一个叶子节点，则j不变
				j = j + 1;

		if (tmp < a[j])//如果当前父亲节点比左右叶子节点小，那么叶子节点中较大的那个节点的值要上浮为父亲节点，然后将该叶子节点作为下一个父亲节点，继续形成子树最大堆，如果父亲节点大，则停止分裂
			{
				a[i] = a[j];
				i = j;
				j = 2 * i;
			}
		else
			break;
	}
	a[i] = tmp;//将最后的叶子节点赋值为刚才的父亲节点，即较小的值下沉。
}
void heap_Sort(int a[], int n)
{
	int i;
	int tmp;
	for (i = n / 2; i >= 1; i--)
		sift(a, i, n);//调用sift直到形成最大堆，从最下层的那个子树开始
	for(i=n;i>=2;i--)
	{
		tmp = a[1]; a[1] = a[i]; a[i] = tmp;//将第一个元素和第i个元素交换
		sift(a, 1, i-1);//从第一个元素到i-1个元素继续调整为最大堆
	}

}

void output(int a[], int n)
{
	int i;
	for (i = 1; i < n; i++)
		printf("%d ", a[i]);
}
int main()
{
	int a[9] = { 0,1,-1,2,-2,3,-3,4,-4 };//第一个节点为占位的
	heap_Sort(a, 8);//实际最后一个有效元素下标是8
	output(a, 9);
	//system("PAUSE");
	return 0;
}

