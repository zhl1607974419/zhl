#include <iostream>
using namespace std;

#include <string> 

#include <conio.h> 

using namespace std; 

 

//��Ʒ��Ϣ�ṹ�� 

struct goodinfo 

{ 

    float p; //��ƷЧ�� 

    float w; //��Ʒ���� 

    float X; //��Ʒ�÷ŵ����� 

    int flag; //��Ʒ��� 

}; 

 

//*********����ƷЧ�棬������ֵ����������***************// 

void Insertionsort(goodinfo goods[],int n) 

{ 

    int j,i; 

    for(j=2;j<=n;j++) 

    { 

        goods[0]=goods[j]; 

        i=j-1; 

        while (goods[0].p>goods[i].p) 

        { 

            goods[i+1]=goods[i]; 

            i--; 

        } 

        goods[i+1]=goods[0]; 

    } 

} 

 

//*********����Ʒ���뱳��**************// 

void bag(goodinfo goods[],float M,int n) 

{ 

    float cu; 

    int i,j; 

    for(i=1;i<=n;i++) 

        goods[i].X=0; 

    cu=M; //����ʣ������ 

    for(i=1;i<n;i++) 

    { 

        if(goods[i].w>cu)//������Ʒ��������ʣ���������� 

            break; 

        goods[i].X=1; 

        cu=cu-goods[i].w;//ȷ�������µ�ʣ������ 

    } 

    if(i<=n) goods[i].X=cu/goods[i].w;//����Ʒ��Ҫ�ŵ��� 

    for(j=2;j<=n;j++) /*����Ʒ�������������*/ 

    { 

        goods[0]=goods[j]; 

        i=j-1; 

        while (goods[0].flag<goods[i].flag) 

        { 

            goods[i+1]=goods[i]; 

            i--; 

        } 

        goods[i+1]=goods[0]; 

    } 

    cout<<"���Ž�Ϊ:"<<endl; 

    for(i=1;i<=n;i++) 

    { 

        cout<<"��"<<i<<"����ƷҪ��:"; 

        cout<<goods[i].X<<endl; 

    } 

} 

 

//*************������***************// 

int main() 

{ 

    int n; 

char j; 

    float M; 

    goodinfo *goods;//����һ��ָ�� 

    cout<<"#####���������̰���㷨#####\n"<<endl; 

 

    while(!(j=='n'||j=='N')) 

    { 

        cout<<"��Ʒ������������"; 

        cin>>n; 

        goods=new struct goodinfo [n+1];// 

        cout<<"���������������"; 

        cin>>M; 

        cout<<endl; 

        int i; 

        for(i=1;i<=n;i++) 

        { 

            goods[i].flag=i; 

            cout<<"��"<<i<<"����Ʒ:"<<endl; 

            cout<<"����:"; 

            cin>>goods[i].w; 

            cout<<"��ֵ:"; 

            cin>>goods[i].p; 

            goods[i].p=goods[i].p/goods[i].w;//�ó���Ʒ�������� 

            cout<<endl; 

        } 

        Insertionsort(goods,n); 

        bag(goods,M,n); 

         

        cout<<endl<<"�Ƿ������y/n����"<<endl; 

        j= getch(); 

        cout<<"---------------------"<<endl; 

    } 
    return 0;

} 


