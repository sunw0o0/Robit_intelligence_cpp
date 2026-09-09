#include <iostream>
#include "ksw_vector.hpp"

using namespace std;

template <typename T>
void print_vector(ksw_vector<T>& vec, const string& title) 
{
    cout << title << endl;
    cout << "현재 크기(size): " << vec.size() << endl;
    cout << "데이터: [ ";
    for (size_t i = 0; i < vec.size(); i++) 
    {
        cout << vec[i] << " ";
    }
    cout << "]\n" << endl;
}

int main() {
    ksw_vector<int> vec;

    // 1. push_back() 테스트 (데이터 추가)
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    vec.push_back(40);
    vec.push_back(50);
    print_vector(vec, "1. push_back 5개 수행 후");

    // 2. operator[] (읽기 & 값 수정) 테스트
    cout << "2. operator[] 수정 테스트" << endl;
    cout << "수정 전 vec[2]: " << vec[2] << endl;
    vec[2] = 999; // 30을 999로 수정
    cout << "수정 후 vec[2]: " << vec[2] << "\n" << endl;

    // 3. pop_back() 테스트 (맨 뒤 값 삭제)
    vec.pop_back(); // 50 삭제
    print_vector(vec, "3. pop_back 1회 수행 후 (맨 뒤 50 삭제)");

    // 4. erase() 테스트 (지정한 인덱스 삭제)
    vec.erase(1); // 1번 위치(20) 삭제
    print_vector(vec, "4. erase(1) 수행 후 (1번 위치 20 삭제)");

    // 5. clear() 테스트 (전체 데이터 초기화)
    vec.clear();
    print_vector(vec, "5. clear() 수행 후 (전체 비우기)");

    return 0;
}
