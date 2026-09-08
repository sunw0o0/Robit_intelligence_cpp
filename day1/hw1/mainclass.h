#ifndef mainclass_h
#define mainclass_h

class mainclass
{
private:
	int* p; //배열 포인터 변수
	int num; //원소 개수 면수

public:
	mainclass(); //생성자
	~mainclass(); //소멸자

	void inputdata();
	void printdata();
};

#endif
