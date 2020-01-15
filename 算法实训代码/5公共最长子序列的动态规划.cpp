 #include <iostream>
 #include <algorithm>
 #include <cstring>
 #include <string>
 using namespace std;
 
 int main()
 { 
 	cout<<"请输入序列1和序列2:"<<endl;
     string str1,str2;
     int length1,length2;
     //int** arr;
     const int row=300;
	   const int col=300; 
     int arr[row][col];
     while (cin >> str1 >> str2)
     {
     	cout<<"最长公共子序列长度:"<<endl; 
         length1 = str1.length(); 
         length2 = str2.length();
         memset(arr,0,sizeof(arr));
         for (int i=1;i<=length1;i++)
         {
             for (int j=1;j<=length2;j++)
			             {
                 if (str1[i-1] == str2[j-1])//这里为什么要用i-1，j-1，因为str中的下标从0开始
                 {
                     arr[i][j]=arr[i-1][j-1]+1;
                }
                else
                 {
                    arr[i][j]=(arr[i-1][j] > arr[i][j-1]?arr[i-1][j]:arr[i][j-1]);
                }
             }
         }
         cout << arr[length1][length2]<<endl;
 
         //打印其中一个最长子序列
         cout<<"最长公共子序列为:"<<endl; 
         string print="";
         for (int i=length1,j=length2;i>=1&&j>=1;)//这里是倒序打印的
         {
             if (str1[i-1] == str2[j-1])
             {
                 //cout << str1[i-1]<<" ";//按照这样会倒序打印
                 print = str1[i-1]+print;
                 i--;
                j--;
             }else
             {
                 if(arr[i][j -1] >= arr[i - 1][j])j--;
                 else
                     i--;
 
             }
             
         }
         cout << print <<endl;
     }
 
     return 0;
}
