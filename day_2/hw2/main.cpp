#include <iostream>
#include <fstream>
#include "ksw_vector.hpp"

using namespace std;

int main() {
    ksw_vector<int> vec;

    // 1. input.txt 파일에서 데이터 읽기
    cout << "1. input.txt 불러오기" << endl;
    if (vec.load_from_file("input.txt")) 
    {
        cout << "읽어온 데이터: ";
        for (size_t i = 0; i < vec.size(); i++) 
        {
            cout << vec[i] << " ";
        }
        cout << endl << endl;
    }
    else 
    {
        cout << "input.txt 파일을 열 수 없습니다!" << endl;
    }

    // 2. 읽어온 데이터 수정 테스트 (999 추가)
    cout << "2. 데이터 수정 (999 추가)" << endl;
    vec.push_back(999);
    cout << "수정 후 데이터: ";
    for (size_t i = 0; i < vec.size(); i++) 
    {
        cout << vec[i] << " ";
    }
    cout << endl << endl;

    // 3. output.txt 파일로 저장
    cout << "3. output.txt 저장" << endl;
    if (vec.save_to_file("output.txt")) 
    {
        cout << "output.txt에 성공적으로 저장되었습니다." << endl;
    }
    else 
    {
        cout << "파일 저장 실패" << endl; //예외처리
    }

    return 0;
}
