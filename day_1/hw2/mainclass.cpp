#include <iostream>
#include <cstdlib> // rand() 사용
#include <cmath>   // sqrt() 사용
#include "point.h"

using namespace std;

// 생성자
point::point() 
{
    points = NULL;
    count = 0;
    min = 0;
    max = 0;
}

// 소멸자
point::~point() 
{
    if (points != NULL) 
    {
        delete[] points; // 메모리 해제
    }
}

// 입력 함수
void point::input() 
{
    cout << "Please define the number of points: ";
    cin >> count;

    cout << "Please define minimum of value: ";
    cin >> min;

    cout << "Please define maximum of value: ";
    cin >> max;
}

// 랜덤 점 생성 함수
void point::randompoint() 
{
    // 구조체 배열 동적 할당
    points = new PointStruct[count];

    cout << "\ngenerate random points\n";

    for (int i = 0; i < count; i++) 
    {
        points[i].x = rand() % (max - min + 1) + min;
        points[i].y = rand() % (max - min + 1) + min;

        cout << "Point " << (i + 1) << ". x=" << points[i].x << " , y=" << points[i].y << endl;
    }
}

// 거리 계산 및 결과 출력 함수
void point::distance() 
{
    // 첫 번째 비교 대상 (0번 점과 1번 점의 거리)
    double dx = points[0].x - points[1].x;
    double dy = points[0].y - points[1].y;
    double firstDist = sqrt(dx * dx + dy * dy);

    double minDist = firstDist;
    double maxDist = firstDist;

    int minP1 = 0, minP2 = 1;
    int maxP1 = 0, maxP2 = 1;

    // 모든 두 점의 쌍을 비교하는 이중 반복문
    for (int i = 0; i < count; i++) 
    {
        for (int j = i + 1; j < count; j++) 
        {
            double diffX = points[i].x - points[j].x;
            double diffY = points[i].y - points[j].y;

            // 피타고라스 정리
            double dist = sqrt(diffX * diffX + diffY * diffY);

            // 최솟값 갱신
            if (dist < minDist) 
            {
                minDist = dist;
                minP1 = i;
                minP2 = j;
            }

            // 최댓값 갱신
            if (dist > maxDist) 
            {
                maxDist = dist;
                maxP1 = i;
                maxP2 = j;
            }
        }
    }

    // 결과 출력
    cout << "\n---- Result --------------\n";
    cout << "MinDist = " << minDist << endl;
    cout << "Pair of Min Coord.(x, y) : P" << (minP1 + 1)
        << "(" << points[minP1].x << "," << points[minP1].y << ") & P"
        << (minP2 + 1) << "(" << points[minP2].x << "," << points[minP2].y << ")\n\n";

    cout << "MaxDist = " << maxDist << endl;
    cout << "Pair of Max Coord.(x, y) : P" << (maxP1 + 1)
        << "(" << points[maxP1].x << "," << points[maxP1].y << ") & P"
        << (maxP2 + 1) << "(" << points[maxP2].x << "," << points[maxP2].y << ")\n";
    cout << "-------------------------------\n";
}
