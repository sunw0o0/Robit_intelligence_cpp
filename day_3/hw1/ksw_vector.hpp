#ifndef KSW_VECTOR_HPP
#define KSW_VECTOR_HPP

#include <string>
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

    bool load_from_file(const std::string& filename);
    bool save_to_file(const std::string& filename);

    ksw_vector<T>& operator+=(const T& element);
    ksw_vector<T>& operator+=(const ksw_vector<T>& other);
};

#include "ksw_vector.cpp"

#endif
