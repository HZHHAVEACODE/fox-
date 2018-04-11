#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void bigmul(char *mul1,char *mul2,char *res)
{
	int a=strlen(mul1),b=strlen(mul2);//��ȡa��b�ĳ���
	size_t size=sizeof(int)*(a+b);//��ȡ��Ҫint���鳤��
	int *Result=(int *)malloc(size);//�������� �洢ÿһλ��ֵ
	char *CResult=(char *)malloc(sizeof(char)*(a+b+1));//�������� �洢���
	int i,j;
	memset(Result,0,size);
	for(i=0;i<a;i++)
	{
		for(j=0;j<b;j++)
		{
			
			Result[i+j+1]+=(mul1[i]-'0')*(mul2[j]-'0');//����Сѧ�˷�һλһλ���� 
		}
	}
	for(i=a+b-1;i>0;i--)
	{
		if(Result[i]>=10)//������ڵ���10 
		{
			Result[i-1]+=Result[i]/10;//��λ 
			Result[i]%=10;//ȥ�� 
		}
	}
	i=0;
	while(Result[i]==0)
	{
		i++;
	} 
	for(j=0;i<a+b;i++,j++)
	{
		CResult[j]=Result[i]+'0';//��ȡ��� 
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