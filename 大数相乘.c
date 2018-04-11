#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void bigmul(char *mul1,char *mul2,char *res)
{
	int a=strlen(mul1),b=strlen(mul2);//获取a，b的长度
	size_t size=sizeof(int)*(a+b);//获取需要int数组长度
	int *Result=(int *)malloc(size);//定义数组 存储每一位的值
	char *CResult=(char *)malloc(sizeof(char)*(a+b+1));//定义数组 存储结果
	int i,j;
	memset(Result,0,size);
	for(i=0;i<a;i++)
	{
		for(j=0;j<b;j++)
		{
			
			Result[i+j+1]+=(mul1[i]-'0')*(mul2[j]-'0');//按照小学乘法一位一位计算 
		}
	}
	for(i=a+b-1;i>0;i--)
	{
		if(Result[i]>=10)//如果大于等于10 
		{
			Result[i-1]+=Result[i]/10;//进位 
			Result[i]%=10;//去余 
		}
	}
	i=0;
	while(Result[i]==0)
	{
		i++;
	} 
	for(j=0;i<a+b;i++,j++)
	{
		CResult[j]=Result[i]+'0';//获取结果 
	}
	strcpy(res,CResult); 
	
}
int main(){
	char data1[100]={'\0'},data2[100]={'\0'};
	char RES[200]={'\0'};
	scanf("%s",data1);
	scanf("%s",data2);
	bigmul(data1,data2,RES);
	printf("%s*%s=\n%s",data1,data2,RES);
	return 0;
}