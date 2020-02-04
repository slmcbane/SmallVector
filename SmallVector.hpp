/*
 * Copyright 2020 The University of Texas at Austin.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */

#ifndef SMALLVECTOR_HPP
#define SMALLVECTOR_HPP

#include <cstddef>
#include <exception>

namespace smv
{

struct MaxSizeExceeded : public std::exception {};

template <class T, std::size_t MAX_SIZE, bool CHECK_BOUNDS = true>
class SmallVector
{
public:
    SmallVector() : m_size{0} {}

    void push_back(T val)
    {
        if (CHECK_BOUNDS && m_size == MAX_SIZE)
        {
            throw MaxSizeExceeded{};
        }
        m_storage[m_size++] = val;
    }
    
    typedef T value_type;
    typedef std::size_t size_type;
    typedef std::ptrdiff_t difference_type;
    typedef T& reference;
    typedef const T& const_reference;
    typedef T* iterator;
    typedef const T* const_iterator;

    iterator begin() noexcept { return &m_storage[0]; }
    const_iterator begin() const noexcept { return &m_storage[0]; }
    iterator end() noexcept { return (&m_storage[0]) + m_size; }
    const_iterator end() const noexcept { return (&m_storage[0]) + m_size; }

    iterator erase(const_iterator first, const_iterator last)
    {
        if (last == end())
        {
            m_size = first - begin();
        }
        else
        {
            iterator dst = begin() + (first - begin());
            for (auto src = last; src < end(); ++dst, ++src)
            {
                *dst = *src;
            }
            m_size = dst - begin();
        }
        // This might happen if there is undefined behavior
        if (m_size > MAX_SIZE)
        {
            throw MaxSizeExceeded{};
        }

        return end();
    }

    reference operator[](std::size_t i) noexcept
    {
        return m_storage[i];
    }

    const_reference operator[](std::size_t i) const noexcept
    {
        return m_storage[i];
    }

    std::size_t size() const noexcept { return m_size; }

private:
    T m_storage [MAX_SIZE];
    std::size_t m_size;
};

} // namespace smv

#endif // SMALLVECTOR_HPP
