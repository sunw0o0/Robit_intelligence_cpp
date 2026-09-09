#ifndef KSW_VECTOR_HPP
#define KSW_VECTOR_HPP

#include "DataFrame.hpp"

template <typename T>
class ksw_vector : public dataframe<T> 
{
protected:
    using dataframe<T>::data_;
    using dataframe<T>::size_;

private:
    size_t capacity_;

public:
    ksw_vector(size_t init_capacity = 10);

    virtual size_t size() override;
    virtual void clear() override;

    void push_back(const T& element);
    void pop_back();
    void erase(size_t index);

    T& operator[](size_t index);
};

#include "ksw_vector.cpp"

#endif
