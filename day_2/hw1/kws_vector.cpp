#ifndef KSW_VECTOR_CPP
#define KSW_VECTOR_CPP

#include "ksw_vector.hpp"

// 1. 생성자
template <typename T>
ksw_vector<T>::ksw_vector(size_t init_capacity) 
{
    capacity_ = init_capacity;
    data_ = new T[capacity_];
    size_ = 0;
}

// 2. size() : 크기 반환
template <typename T>
size_t ksw_vector<T>::size() 
{
    return size_;
}

// 3. clear() : 데이터 초기화
template <typename T>
void ksw_vector<T>::clear() 
{
    size_ = 0;
}

// 4. push_back() : 맨 뒤에 값 추가
template <typename T>
void ksw_vector<T>::push_back(const T& element) 
{
    if (size_ >= capacity_) 
    {
        size_t new_capacity = capacity_ * 2;
        T* new_data = new T[new_capacity];

        for (size_t i = 0; i < size_; i++) 
        {
            new_data[i] = data_[i];
        }

        delete[] data_;
        data_ = new_data;
        capacity_ = new_capacity;
    }

    data_[size_] = element;
    size_++;
}

// 5. pop_back() : 맨 뒤 값 삭제 - c++자료 stl에는 없지만, c에서 pop을 다뤘기에 넣어봤다.
template <typename T>
void ksw_vector<T>::pop_back() 
{
    if (size_ > 0) 
    {
        size_--;
    }
}

// 6. erase() : 지정한 위치 값 삭제
template <typename T>
void ksw_vector<T>::erase(size_t index) 
{
    if (index >= size_) 
    {
        return;
    }

    for (size_t i = index; i < size_ - 1; i++) 
    {
        data_[i] = data_[i + 1];
    }

    size_--;
}

// 7. operator[] : vec[i] 위치 값 접근
template <typename T>
T& ksw_vector<T>::operator[](size_t index) 
{
    return data_[index];
}

#endif
