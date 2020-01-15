#include <iostream>
using namespace std;

#include <string> 

#include <conio.h> 

using namespace std; 

 

//物品信息结构体 

struct goodinfo 

{ 

    float p; //物品效益 

    float w; //物品重量 

    float X; //物品该放的数量 

    int flag; //物品编号 

}; 

 

//*********按物品效益，重量比值做升序排列***************// 

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

 

//*********将物品放入背包**************// 

void bag(goodinfo goods[],float M,int n) 

{ 

    float cu; 

    int i,j; 

    for(i=1;i<=n;i++) 

        goods[i].X=0; 

    cu=M; //背包剩余容量 

    for(i=1;i<n;i++) 

    { 

        if(goods[i].w>cu)//当该物品重量大与剩余容量跳出 

            break; 

        goods[i].X=1; 

        cu=cu-goods[i].w;//确定背包新的剩余容量 

    } 

    if(i<=n) goods[i].X=cu/goods[i].w;//该物品所要放的量 

    for(j=2;j<=n;j++) /*按物品编号做降序排列*/ 

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

    cout<<"最优解为:"<<endl; 

    for(i=1;i<=n;i++) 

    { 

        cout<<"第"<<i<<"件物品要放:"; 

        cout<<goods[i].X<<endl; 

    } 

} 

 

//*************主函数***************// 

int main() 

{ 

    int n; 

char j; 

    float M; 

    goodinfo *goods;//定义一个指针 

    cout<<"#####背包问题的贪心算法#####\n"<<endl; 

 

    while(!(j=='n'||j=='N')) 

    { 

        cout<<"物品的种类数量："; 

        cin>>n; 

        goods=new struct goodinfo [n+1];// 

        cout<<"背包的最大容量："; 

        cin>>M; 

        cout<<endl; 

        int i; 

        for(i=1;i<=n;i++) 

        { 

            goods[i].flag=i; 

            cout<<"第"<<i<<"件物品:"<<endl; 

            cout<<"重量:"; 

            cin>>goods[i].w; 

            cout<<"价值:"; 

            cin>>goods[i].p; 

            goods[i].p=goods[i].p/goods[i].w;//得出物品的重量比 

            cout<<endl; 

        } 

        Insertionsort(goods,n); 

        bag(goods,M,n); 

         

        cout<<endl<<"是否继续（y/n）？"<<endl; 

        j= getch(); 

        cout<<"---------------------"<<endl; 

    } 
    return 0;

} 


