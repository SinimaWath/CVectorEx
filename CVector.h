//
// Created by sinimawath on 22.04.18.
//

#ifndef CVECTOR_CVECTOR_H
#define CVECTOR_CVECTOR_H

#include "CStack.h"
template <typename _T>
class CVector: public CStack<_T>  {

public:

    using size_type = typename CStack<_T>::size_type;
    using value_type = typename CStack<_T>::value_type;
    using pointer = typename CStack<_T>::pointer ;
    using const_pointer = typename CStack<_T>::const_pointer;
    using reference = typename CStack<_T>::reference;
    using const_reference = typename CStack<_T>::const_reference;

public:

    CVector() = default;
    explicit CVector(size_type capacity): CStack<value_type>(capacity) {}

    ~CVector() override = default;

    CVector(const CVector &other) : CStack<value_type>(other) {}

    CVector(CVector&& other) noexcept: CStack<value_type >(std::move(other)) {}

    CVector& operator=(const CVector &other) {

        if (this == &other)
            return *this;

        delete[] this->buffer_;

        this->bufferSize_ = other.bufferSize_;
        this->capacity_ = other.capacity_;

        this->buffer_ = new _T[this->capacity_];
        std::copy(other.buffer_, other.buffer_ + this->bufferSize_, this->buffer_);

        return *this;
    }

    CVector&operator=(CVector&& other) noexcept {
        if (this == &other)
            return *this;

        delete[] this->buffer_;

        this->bufferSize_ = other.bufferSize_;
        this->capacity_ = other.capacity_;
        this->buffer_ = other.buffer_;

        other.buffer_ = nullptr;
        return *this;
    }

    reference operator[](size_type n){
        return this->buffer_[n];
    }

    const_reference operator[](size_type n) const {
        return this->buffer_[n];
    }

    void show() const override {
        std::cout << "It's VECTOR: ";
        std::copy(this->buffer_, this->buffer_ + this->bufferSize_, std::ostream_iterator<value_type >(std::cout, " "));
    }

private:

};


#endif //CVECTOR_CVECTOR_H
