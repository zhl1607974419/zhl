#include<string.h>
#include<stdio.h>
int k;
int binarysearch(int a[],int x,int low,int high)//a��ʾ��Ҫ���ֵ��������飨���򣩣�x��ʾ��Ҫ���ҵ����֣�low��high��ʾ�ߵ�λ
{
    if(low>high)
    {
        return -1;//û���ҵ�
    }
    int mid=(low+high)/2;
    if(x==a[mid])//�ҵ�x
    {
        k=mid;
        return x;
    }
    else if(x>a[mid]) //x�ں�벿��
    {
        binarysearch(a,x,mid+1,high);//�ں�벿�ּ������ֲ���
    }
    else//x��ǰ�벿��
    {
        binarysearch(a,x,low,mid-1);
    }
}
int main()
{
    int a[10]={1,2,3,4,5,6,7,8,9,10};
    printf("��������Ҫ���ҵ������֣�\n");
    int x;
    scanf("%d",&x);
    int r=binarysearch(a,x,0,9);
    if(r==-1)
    {
        printf("û�в鵽\n");
    }
    else
    {
        printf("�鵽��,�����еĵ�%d��λ����\n",k+1);
    }
    return 0;
}
