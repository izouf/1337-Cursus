#pragma once

namespace ft
{

    template <typename T, class Alloc>
    vector <T, Alloc>::vector(const allocator_type &alloc)
    {
        _alloc = alloc;
        _data = NULL;
        _size = 0;
        _capacity = 0;
    }

    template <typename T, class Alloc>
    vector <T, Alloc>::vector(size_type n, const value_type &val,
                                const allocator_type &alloc)
    {
        _alloc = alloc;
        _data = NULL;
        _size = 0;
        _capacity = 0;
        if (n > max_size())
            throw std::length_error("length_error");
        _data = _alloc.allocate(n);
        if (_data == NULL)
            throw std::bad_alloc();
        for (size_t i = 0; i < n; i++)
        {
            _alloc.construct(_data + i, val);
            _size++;
        }
        _capacity = n;
    }

    template <typename T, class Alloc>
    template <class InputIterator>
    vector<T, Alloc>::vector(InputIterator first, InputIterator last,
                                const allocator_type &alloc)
    {
        _alloc = alloc;
        _data = NULL;
        _size = 0;
        _capacity = 0;
        typedef typename ft::is_integral<InputIterator>::type Integral;
        initialize_dispatch(first,  last, Integral());
    }

    template <typename T, class Alloc>
    template <typename InputIterator>
    void vector<T, Alloc>::initialize_dispatch(InputIterator first, InputIterator last, false_type)
    {
        _size = ft::distance(first, last);
        _capacity = _size;
        _data = _alloc.allocate(_size);
        if (_data == NULL)
            throw std::bad_alloc();
        std::uninitialized_copy(first, last, _data);
    }

    template <typename T, class Alloc>
    vector<T, Alloc>::vector(const vector &x)
    {
        _alloc = x._alloc;
        _data = NULL;
        _size = 0;
        _capacity = 0;
        *this = x;
    }

    template <typename T, class Alloc>
    vector<T, Alloc>::~vector()
    {
        for (size_type i = 0; i < _size; i++)
            _alloc.destroy(_data + i);
        if (_capacity > 0)
            _alloc.deallocate(_data, _size);
        _size = 0;
        _capacity = 0;
    }

    template <typename T, class Alloc>
    vector<T, Alloc> &vector<T, Alloc>::operator=(const vector &x)
    {
        if (*this != x)
        {
            for (size_t i = 0; i < _size; i++)
                _alloc.destroy(&_data[i]);
            if (_capacity > 0)
                _alloc.deallocate(_data, _size);
            _size = x.size;
            _capacity = x.capacity();
            _data = _alloc.allocate(_capacity);
            for (size_t i = 0; i< _size; i++)
                _alloc.construct(&_data[i], x._data[i]);
        }
        return (*this);
    }

    template <typename T, class Alloc>
    typename vector<T, Alloc>::iterator vector<T, Alloc>::begin()
    {
        return (iterator(_data));
    }

    template <typename T, class Alloc>
    typename vector<T, Alloc>::const_iterator vector<T, Alloc>::begin() const
    {
        return (const_iterator(_data));
    }

    template <typename T, class Alloc>
    typename vector<T, Alloc>::iterator vector<T, Alloc>::end()
    {
        return (iterator(_data + size));
    }

    template <typename T, class Alloc>
    typename vector<T, Alloc>::const_iterator vector<T, Alloc>::end() const
    {
        return (const_iterator(_data + size));
    }

    template <typename T, class Alloc>
    typename vector<T, Alloc>::reverse_iterator vector<T, Alloc>::rbegin()
    {
        return (reverse_iterator(end()));
    }

    template <typename T, class Alloc>
    typename vector<T, Alloc>::const_reverse_iterator vector<T, Alloc>::rbegin() const
    {
        return (const_reverse_iterator(end()));
    }

    template <typename T, class Alloc>
    typename vector<T, Alloc>::reverse_iterator vector<T, Alloc>::rend()
    {
        return (reverse_iterator(begin()));
    }

    template <typename T, class Alloc>
    typename vector<T, Alloc>::const_reverse_iterator vector<T, Alloc>::rend() const
    {
        return (const_reverse_iterator(begin()));
    }

    template <typename T, class Alloc>
    typename vector<T, Alloc>::size_type vector<T, Alloc>::size()
    {
        return (_size);
    }

    template <typename T, class Alloc>
    typename vector<T, Alloc>::size_type vector<T, Alloc>::max_size() const
    {
        return (_alloc.max_size());
    }

    template <typename T, class Alloc>
    void vector<T, Alloc>::resize(size_type n, value_type val)
    {
        while (n < _size)
            pop_back();
        if (n > _capacity)
            reserve(n);
        while(n > _size)
            push_back(val);
    }

    template <typename T, class Alloc>
    typename vector<T, Alloc>::size_type vector<T, Alloc>::capacity() const
    {
        return (_capacity);
    }

    template<typename T, class Alloc>
    bool vector<T, Alloc>::empty() const
    {
        return (begin() == end());
    }

    template <typename T, class Alloc>
    void vector<T, Alloc>::reserve(size_type n)
    {
        if (n > capacity)
        {
            if (n > max_size())
                throw (std::length_error("length_error"));
            pointer tmp = _alloc.allocate(n);
            if (tmp == NULL)
                throw (std::bac_alloc());
            for (size_t i = 0; i < _size; i++)
            {
                _alloc.construct(tmp + i, _data[i]);
                _alloc.destroy(_data + i);
            }
            _alloc.deallocate(_data, _capacity);
            _data = tmp;
            _capacity = n;
        }
    }

    template <typename T, class Alloc>
    typename vector<T, Alloc>::reference vector<T, Alloc>::operator[](size_type n)
    {
        return (*(begin()+ n));
    }

    template <typename T, class Alloc>
    typename vector<T, Alloc>::const_reference vector<T, Alloc>::operator[](size_type n) const
    {
        return (*(begin()+ n));
    }

    template <typename T, class Alloc>
    typename vector<T, Alloc>::reference vector<T, Alloc>::at(size_type n)
    {
        if (n < 0 || n >= _size)
            throw (std::out_of_range("out_of_range"));
        return (*(begin() + n));
    }

    template <typename T, class Alloc>
    typename vector<T, Alloc>::const_reference vector<T, Alloc>::at(size_type n) const
    {
        if (n < 0 || n >= _size)
            throw (std::out_of_range("out_of_range"));
        return (*(begin() + n));
    }

    template <typename T, class Alloc>
    typename vector<T, Alloc>::reference vector<T, Alloc>::front()
    {
        return (*begin());
    }

    template <typename T, class Alloc>
    typename vector<T, Alloc>::const_reference vector<T, Alloc>::front() const
    {
        return (*begin());
    }

    template <typename T, class Alloc>
    typename vector<T, Alloc>::reference vector<T, Alloc>::back()
    {
        return (*(end() - 1));
    }

    template <typename T, class Alloc>
    typename vector<T, Alloc>::const_reference vector<T, Alloc>::back()const
    {
        return (*(end() - 1));
    }

    template <typename T, class Alloc>
    template <class InputIterator>
    void vector<T, Alloc>::assign(InputIterator first, InputIterator last)
    {
        typedef typename ft::is_integral<InputIterator>::type Integral;
        assign_dispatch(first, last, Integral());
    }

    template <typename T, class Alloc>
    template <typename Integer>
    void vector<T, Alloc>::assign_dispatch(Integer n, Integer val, true_type)
    {
        for (size_t i = 0; i < _size; i++)
            _alloc.destroy(&_data[i]);
        _alloc.deallocate(_data, _capacity);
        if (static_cast<size_type>(n) > _capacity)
            _capacity = n;
        _data = _alloc.allocate(n);
        if (_data = NULL)
            throw (std::bad_alloc());
        _size = n;
        for (size_t i = 0; i < _size; i++)
            _alloc.construct(&_data[i], val);
    }

    template <typename T, class Alloc>
    template <typename InputIterator>
    void vector<T, Alloc>::assign_dispatch(InputIterator first, InputIterator last, false_type)
    {
        for (size_t i = 0; i < _size; i++)
            _alloc.destroy(&_data[i]);
        _alloc.deallocate(_data, _capacity);
        if (static_cast<size_type>(ft::distance(first, last)) > _capacity)
            _capacity = ft::distance(first, last);
        _data = _alloc.allocate(_capacity);
        if (_data = NULL)
            throw (std::bad_alloc());
        _size = ft::distance(first, last);
        std::uninitialized_copy(first, last, _data);
    }

    template <typename T, class Alloc>
    void vector<T, Alloc>::push_back(const value_type &val)
    {
        if (_size + 1 > _capacity)
        {
            _capacity ? _capacity *= 2 : _capacity++;
            pointer tmp = _alloc.allocate(_capacity);
            if (tmp == NULL)
                throw (std::bad_alloc());
            for (size_t i = 0; i < _size; i++)
            {
                _alloc.construct(tmp + i, _data[i]);
                _alloc.destroy(_data + i);
            }
            _alloc.deallocate(_data, _capacity);
            _data = tmp;
        }
        _alloc.construct(_data + _size, val);
        _size++;
    }

    template <typename T, class Alloc>
    typename vector<T, Alloc>::iterator vector<T, Alloc>::insert(iterator position, const value_type &val)
    {
        size_type distance = ft::distance(begin(), position);
        if (_capacity == 0)
        {
            reserve(1);
            _alloc.construct(&_data[distance], val);
            _size++;
            return (iterator(&_datap[distance]));
        }
        if (_capacity < (_size + 1))
            reserve(_capacity * 2);
        if (position == end())
        {
            push_back(val);
            return (iterator(&_data[distance]));
        }
        if (ft::is_integral<value_type>::value)
            std::copy_backward(&_data[distance], &_data[_size], &_data[size + 1]);
        else
        {
            for (size_t i = _size; i > distance; i--)
            {
                _alloc.construct(&_data[i], _data[i - 1]);
                _alloc.destroy(&_data[i - 1]);
            }
        }
        _alloc.construct(&_data[distance], val);
        _size++;
        return (iterator(&_data[distance]));
    }

    template <typename T, class Alloc>
    void vector<T, Alloc>::insert(iterator position, size_type n, const value_type &val)
    {
         size_type distance = ft::distance(begin(), position);
        if (_capacity == 0)
        {
            reserve(n);
            _size = n ;
            for (size_t i = 0; i < n; i++)
                _alloc.construct(&_data[distance + 1], val);
            return ;
        }
        if (_capacity < (_size + n))
            reserve(_capacity * 2);
        for (size_t i = 0; i < n; i++)
            insert(begin() + distance, val);
    }

    template <typename T, class Alloc>
    template <class InputIterator>
    void vector<T, Alloc>::insert(iterator position, InputIterator first, InputIterator last)
    {
        typedef typename ft::is_integral<InputIterator>::type Integral;
        insert_dispatch(position, first, last, Integral());
    }

    template <typename T, class Alloc>
    template <class Integer>
    void    vector<T, Alloc>::insert_dispatch(iterator position, size_type n, const Integer &val, true_type)
    {
        size_type distance = ft::distance(begin(), position);
        if (_capacity == 0)
        {
            reserve(n);
            _size = n;
            for (size_t i = 0; i < n; i++)
            _alloc.construct(&_data[distance + i], val);
            return;
        }
        if (_capacity < (size + n))
            reserve(_capacity * 2);
        for (size_t i = 0; i < n; i++)
            insert(begin() + distance, val);
    }

    template <typename T, class Alloc>
    template <class InputIterator>
    void    vector<T, Alloc>::insert(iterator position, InputIterator first, InputIterator last, false_type)
    {
        size_type distance = ft::distance(begin(), position);
        size_type n = ft::distance(first, last);
        if (_capacity == 0)
        {
            reserve(n);
            _size = n;
            for (size_t i = 0; i < n; i++)
            {
                _alloc.construct(&_data[distance + i], *first);
                first++;
            }
            return;
        }
        if (_capacity < (size + n))
            reserve(_capacity * 2);
        for (size_t i = 0; i < n; i++)
        {
            last--;
            insert(begin() + distance, *last);
        }
    }

    template <typename T, class Alloc>
    typename vector<T, Alloc>::iterator vector<T, Alloc>::erase(iterator pisition)
    {
        if (position + 1 != end())
            std::copy(position.base() + 1, end().base, position.base());
        --_size;
        if (!ft::is_integral<value_type>::value)
            _alloc.destroy(_data + size);
        return (position);
    }

    template <typename T, class Alloc>
    typename vector<T, Alloc>::iterator vector<T, Alloc>::erase(iterator first, iterator last)
    {
        iterator it(std::copy(last.base(), end.base(), first.base()));
        if (!ft::is_integral<value_type>::value)
        {
            while (it != end())
            {
                _alloc.destroy(it.base());
                ++it
            }
        }
        _size -= (last - first);
        return (first);
    }

    template <typename T, class Alloc>
    void vector<T, Alloc>::swap(vector &x)
    {
        pointer     tmp_data = x._data;
        size_type   tmp_capacity = x._capacity;
        size_type   tmp_size = x._size;

        x._data = _data;
        x._capacity = _capacity;
        x._size = _size;

        _data = tmp_data;
        _capacity = tmp_capacity;
        _size = tmp_size;
    }

    template <typename T, class Alloc>
    void vector<T, Alloc>::clear()
    {
        erase(begin(), end());
    }

    template <typename T, class Alloc>
    typename vector<T, Alloc>::allocator_type vector<T, Alloc>::get_allocator() const
    {
        return (_alloc);
    }
}