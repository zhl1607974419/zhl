 #include <iostream>
 #include <algorithm>
 #include <cstring>
 #include <string>
 using namespace std;
 
 int main()
 { 
 	cout<<"����������1������2:"<<endl;
     string str1,str2;
     int length1,length2;
     //int** arr;
     const int row=300;
	   const int col=300; 
     int arr[row][col];
     while (cin >> str1 >> str2)
     {
     	cout<<"����������г���:"<<endl; 
         length1 = str1.length(); 
         length2 = str2.length();
         memset(arr,0,sizeof(arr));
         for (int i=1;i<=length1;i++)
         {
             for (int j=1;j<=length2;j++)
			             {
                 if (str1[i-1] == str2[j-1])//����ΪʲôҪ��i-1��j-1����Ϊstr�е��±��0��ʼ
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
 
         //��ӡ����һ���������
         cout<<"�����������Ϊ:"<<endl; 
         string print="";
         for (int i=length1,j=length2;i>=1&&j>=1;)//�����ǵ����ӡ��
         {
             if (str1[i-1] == str2[j-1])
             {
                 //cout << str1[i-1]<<" ";//���������ᵹ���ӡ
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
