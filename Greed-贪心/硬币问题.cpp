//Ӳ������
// 1     5     10    50    100      500
// C1   C5    C10    C50  C100     C500

//3 2 1 3 0 2 620
#include<iostream>
#include<cstring>
using namespace std;

int main(void)
{
	int Value[6]= {1, 5, 10, 50, 100, 500};
	int C[6];
	for(int i=0; i<6; i++)	cin>>C[i];
	int A;
	cin>>A;

	int cnt=5, count=0;     //cntΪ��ֵ�±�
	while(A && cnt>-1) {
		if(A<Value[cnt]) { //�������ͻ�С��ֵ��
			cnt--;
		} else {
			if(C[cnt]!=0) {
				A -= Value[cnt];
				C[cnt]--;
//				cout<<"subtraction: "<<Value[cnt]<<endl;
				count++;
			} else {
				cnt--;
			}
		}
	}

	cout<<count<<endl;
	return 0;
}
