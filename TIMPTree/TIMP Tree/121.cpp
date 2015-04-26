/**
   *@file 121.cpp
   *@version 1.0
   *@title Release tree
   */
#include<stdlib.h>
#include<iostream>
using namespace std;
/**
	*@func ����������� ������� ������� ������ ������
	*@param c - ���������� �������� ���� (��������)
	*@param n - ���������� ���������� �����
	*@param *A - ���������� ��������� �� ������ ��������� �����
	*/
void pramoi(int c,int n,int* A)
{

	int b;
 cout<<c+1<<" ";
 for(int i=0;i<n;i++)
 {
	if(A[i]==c+1)
	{
		b=i;
		pramoi(b,n,A);
	}
 }

}
/**
	*@func ����������� ������� ��������� ������ ������
	*@param c - ���������� �������� ���� (��������)
	*@param n - ���������� ���������� �����
	*@param *A - ���������� ��������� �� ������ ��������� �����
	*/
void obratni(int c,int n, int*A)
{
	int* Buf=new int[n];
	for(int i=0;i<n;i++)
	{
		Buf[i]=0;
	}
	for(int j=0;j<n;j++)
	{
		if (A[j] == c+1)
		{
			Buf[j]=A[j];
		}
	}
	for (int k=0;k<n;k++)
	{
		if (Buf[k])
		{
			obratni(k,n,A);
		}
	}
	cout<<c+1<<" ";
	delete []Buf;
}
/**
	*@func ����������� ������� ������������� ������ ������
	*@param c - ���������� �������� ���� (��������)
	*@param n - ���������� ���������� �����
	*@param *A - ���������� ��������� �� ������ ��������� �����
	*/
void simmetr(int c, int n, int *A) 
{ 
	int *Buf = new int [n];  	
	for (int i = 0; i < n; i++) 
		{
			Buf[i] = 0;
		}
  
	for (int j = 0; j < n; j++) 
		if (A[j] == c + 1) Buf[j] = A[j]; 	 
 	 
 	for (int k = 0; k < n; k++)			 
		if (Buf[k]) simmetr(k, n, A);  	 
 	int q = 0; 
	for (int z = 0; z < n; z++)		 
 		if (A[z] == c+1) q++;		 
 	 
 	if (q == 0) cout << c + 1 << " ";	 
 	if ((A[c-1] != A[c]) && (A[c])) 
		cout << A[c] << " ";  
 	 
 	delete []Buf; 
 } 
 
/**
	*@brief �������� ���������� �����, ����� ��� ������� ���� �������� ��������. 
	�� ����� ��������� �������� ������ � ���� ���������, ��������������� 3�� ������� ������


/* � - ����� ����, ��� - ��������*/
void main()
{
	int N;
	cout<<"Vvedite kolichestvo uzlov: ";
	cin>>N;
	int*D= new int[N];
	cout<<"Vvedite roditelja"<<endl;
	cout<<"Dlja "<<1<<" uzla:"<<endl;
	cout<<"0"<<endl;
	D[0]=0;
	for(int i=1;i<N;i++)
		{
			cout<<"Dlja "<<i+1<<" uzla:"<<endl;
			cin>>D[i];
		}
	for(int i=0;i<N;i++)
		{
			cout<<D[i]<<" ";
		}
	cout<<"\n\nPrjamoij obchod"<<endl;
	pramoi(0,N,D);
	cout<<"\n\nObatnij obchod"<<endl;
	obratni(0,N,D);
	cout<<"\n\nSimmetr obchod"<<endl;
	simmetr(0,N,D);
	delete[]D;
	return;
}
