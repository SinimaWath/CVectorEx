//
// Created by sinimawath on 22.04.18.
//

#ifndef CVECTOR_CSTACK_H
#define CVECTOR_CSTACK_H

#include <cstddef>
#include <algorithm>
#include <iostream>
#include <iterator>

template <typename _T>
class CStack {
public:
    using size_type = size_t;
    using value_type = _T;
    using pointer = _T*;
    using const_pointer = const _T*;
    using reference = value_type&;
    using const_reference = const value_type&;

    CStack(): bufferSize_(0), capacity_(2), buffer_(new _T[capacity_]()) {}

    explicit CStack(size_type capacity): bufferSize_(0), capacity_(2) {

        while(capacity_ <= capacity)
            capacity_ <<=1;

        buffer_ = new _T[capacity_]();

    }

    CStack(const CStack& other): bufferSize_(other.bufferSize_), capacity_(other.capacity_),
        buffer_(new _T[capacity_]){

        std::copy(other.buffer_, other.buffer_ + bufferSize_, buffer_);

    }

    CStack& operator=(const CStack& other){
        if (this == &other)
            return *this;

        delete[] buffer_;

        bufferSize_ = other.bufferSize_;
        capacity_ = other.capacity_;

        buffer_ = new _T[capacity_];
        std::copy(other.buffer_, other.buffer_ + bufferSize_, buffer_);

        return *this;

    }

    virtual ~CStack(){
        delete[] buffer_;
    }

    virtual void push_back(const value_type& value){
        if (bufferSize_ >= capacity_)
            grow();

        buffer_[bufferSize_++] = value;
    }
    virtual reference back(){
        return buffer_[bufferSize_ - 1];
    }
    virtual const_reference back() const{
        return buffer_[bufferSize_ - 1];
    }
    virtual void pop_back(){
        bufferSize_--;
    }

    virtual size_type size() const{
        return bufferSize_;
    }
    virtual size_type capacity() const{
        return capacity_;
    }

    virtual pointer data(){
        return buffer_;
    }
    virtual const_pointer data() const{
        return buffer_;
    }

    virtual bool empty() const {
        return bufferSize_ == 0;
    }

    virtual void show() const{
        std::cout << "It's STACK: ";
        std::reverse_copy(buffer_, buffer_ + bufferSize_, std::ostream_iterator<value_type >(std::cout, " "));
    }

protected:

    virtual void grow() {

        capacity_ <<= 1;
        auto tmp = new _T[capacity_];
        std::copy(buffer_, buffer_ + bufferSize_, tmp);

        delete[] buffer_;

        buffer_ = nullptr;
        buffer_ = tmp;

    }

    size_type bufferSize_;
    size_type capacity_;
    pointer buffer_;
};


#endif //CVECTOR_CSTACK_H
