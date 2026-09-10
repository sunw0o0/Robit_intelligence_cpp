#include <iostream>
#include "ksw_vector.hpp"

using namespace std;

int main() 
{
    ksw_vector<int> v1;
    v1.push_back(10);
    v1.push_back(20);

    // 1. vector += data
    v1 += 30; // 30 추가
    v1 += 40; // 40 추가

    cout << "v1 데이터 (data 추가 후): ";
    for (size_t i = 0; i < v1.size(); i++) 
    {
        cout << v1[i] << " ";
    }
    cout << endl;

    // 2. vector += vector
    ksw_vector<int> v2;
    v2.push_back(100);
    v2.push_back(200);

    v1 += v2; // v1 뒤에 v2(100, 200) 붙이기

    cout << "v1 데이터 (v2 이어붙인 후): ";
    for (size_t i = 0; i < v1.size(); i++) 
    {
        cout << v1[i] << " ";
    }
    cout << endl;

    return 0;
}
