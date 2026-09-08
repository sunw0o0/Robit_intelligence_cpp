#ifndef POINT_H
#define POINT_H

//구조체 PointStruct
struct PointStruct 
{
    int x;
    int y;
};

// 2. 점 관리 클래스 point
class point 
{
private:
    PointStruct* points; // 구조체 배열을 가리키는 포인터
    int count;           // 점 개수
    int min;             // 최소 좌표 범위
    int max;             // 최대 좌표 범위

public:
    point();  // 생성자
    ~point(); // 소멸자

    void input();
    void randompoint();
    void distance();
};

#endif
