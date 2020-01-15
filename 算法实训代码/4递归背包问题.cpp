#include <iostream>
#include<cstdio>

using namespace std;

#define N 100

struct goods{
int sign;
int wight;
int value;
};

int n,bestValue,cv,cw,C;
int X[N],cx[N];
struct goods goods[N];

int Force(int i){
if(i>n-1){
    if(bestValue < cv && cw + goods[i].wight <= C){
        for(int k=0;k<n;k++)
            X[k] = cx[k];
        bestValue = cv;
    }
    return bestValue;
}
cw = cw + goods[i].wight;
cv = cv + goods[i].value;
cx[i] = 1;
Force(i+1);
cw = cw-goods[i].wight;
cv = cv-goods[i].value;
cx[i] = 0;
Force(i+1);
return bestValue;
}

int main()
{
    printf("物品种类n：");
    scanf("%d",&n);
    printf("背包容量C：");
    scanf("%d",&C);
    for(int i=0;i<n;i++){
        printf("物品%d的重量w[%d]及其价值v[%d]：",i+1,i+1,i+1);
        scanf("%d%d",&goods[i].wight,&goods[i].value);
    }
    int sum1 = Force(0);
    printf("蛮力法求解0/1背包问题：\nX=[");
    for(int i=0;i<n;i++){
        cout << X[i]<<" ";
        }
        printf("] 装入总价值%d\n",sum1);
    return 0;
}
