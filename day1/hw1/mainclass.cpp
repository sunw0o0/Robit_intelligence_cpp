#include <iostream>
#include "mainclass.h"

using namespace std;

//생성자 초기값
mainclass::mainclass()
{
	p = NULL;
	num = 0;
}

//소멸자 메모리 삭제
mainclass::~mainclass()
{
	if (p != NULL)
	{
		delete[] p; //동적할당 메모리 해제
	}
}

//입력함수
void mainclass::inputdata()
{
	cout << "몇 개의 원소를 할당하겠습니까? : ";
	cin >> num;

	p = new int[num]; //입력받은 만큼 동적할당

	for (int i = 0; i < num; i++)
	{
		cout << "정수형 데이터 입력 : ";
		cin >> p[i];
	}
}

//결과 함수
void mainclass::printdata()
{
	//임시로 첫번째를 min,max로 지정
	int max = p[0];
	int min = p[0];
	int sum = 0;

	//i를 늘려가며 비교하기
	for (int i = 0; i < num;i = i + 1)
	{
		if (p[i] > max)
		{
			max = p[i];
		}
		if (p[i] < min)
		{
			min = p[i];
		}
		sum = sum + p[i];
	}
	
	//평균 구하기
	double avg = (double)sum / num;

	//출력
	cout << "최댓값 : " << max << endl;
	cout << "최솟값 : " << min << endl;
	cout << "전체합 : " << sum << endl;
	cout << "평균 : " << avg << endl;
}
