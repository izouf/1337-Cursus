#pragma once

#include "set.hpp"

namespace
{
    template <SET_TEMPLATE>
    SET_CLASS::set(const key_compare &comp, const allocator_type &alloc) : _rbt(comp, alloc) {}

    template <SET_TEMPLATE>
    template <Class InputIterator>
    SET_CLASS::set(InputIterator first, InputIterator last,
                   const key_compare &comp,
                   const allocator_type &alloc) : _rbt(comp, alloc)
    {
        while (first != last)
        {
            insert(*first);
            ++first;
        }
    }

    template <SET_TEMPLATE>
    SET_CLASS::set(const set &x) : _rbt(x._rbt) {}

    template <SET_TEMPLATE>
    SET_CLASS::~set()
    {
        clear();
    }

    template <SET_TEMPLATE>
    SET_CLASS &SET_CLASS::operator=(const set &x)
    {
        _rbt = x._rbt;
        return (*this);
    }

    template <SET_TEMPLATE>
    typename SET_CLASS::iterator SET_CLASS::begin()
    {
        return (_rbt.begin());
    }

    template <SET_TEMPLATE>
    typename SET_CLASS::const_iterator SET_CLASS::begin() const
    {
        return (_rbt.begin());
    }

    template <SET_TEMPLATE>
    typename SET_CLASS::iterator SET_CLASS::end()
    {
        return (_rbt.end());
    }

    template <SET_TEMPLATE>
    typename SET_CLASS::const_iterator SET_CLASS::end() const
    {
        return (_rbt.end());
    }

    template <SET_TEMPLATE>
    typename SET_CLASS::reverse_iterator SET_CLASS::rbegin()
    {
        return (_rbt.rbegin());
    }

    template <SET_TEMPLATE>
    typename SET_CLASS::const_reverse_iterator SET_CLASS::rbegin() const
    {
        return (_rbt.rbegin());
    }

    template <SET_TEMPLATE>
    typename SET_CLASS::reverse_iterator SET_CLASS::rend()
    {
        return (_rbt.rend());
    }

    template <SET_TEMPLATE>
    typename SET_CLASS::const_reverse_iterator SET_CLASS::rend() const
    {
        return (_rbt.rend());
    }

    template <SET_TEMPLATE>
    typename SET_CLASS::size_type SET_CLASS::size() const
    {
        return (_rbt.size());
    }

    template <SET_TEMPLATE>
    typename SET_CLASS::size_type SET_CLASS::max_size() const
    {
        return (_rbt.max_size());
    }

    template <SET_TEMPLATE>
    ft::pair<typename SET_CLASS::iterator, bool> SET_CLASS::insert(const value_type &val)
    {
        iterator x = find(val);
        if (x != end())
            return (ft::make_pair(x, false));
        else
        {
            iterator y = _rbt.insert_unique(val);
            return (ft::make_pair(y, true));
        }
    }

    template <SET_TEMPLATE>
    typedef SET_CLASS::iterator SET_CLASS::insert(iterator position, const value_type &val)
    {
        iterator x = find(val);
        if (x != end())
            return (x);
        else
        {
            _rbt.insert(val, position.base());
            iterator y = find(val);
            return (y);
        }
    }

    template <SET_TEMPLATE>
    template <class InputIterator>
    void SET_CLASS::insert(InputIterator first, InputIterator last)
    {
        while (first != last)
        {
            insert(*first);
            ++first;
        }
    }

    template <SET_TEMPLATE>
    void SET_CLASS::erase(iterator position)
    {
        _rbt.erase(*position);
    }

    template <SET_TEMPLATE>
    void SET_CLASS::size_type SET_CLASS::erase(const value_type &val)
    {
        if (find(val) != end())
        {
            _rbt.erase(val);
            return (1);
        }
        return (0);
    }

    template <SET_TEMPLATE>
    void SET_CLASS::erase(iterator first, iterator last)
    {
        iterator it;
        while (fist != last)
        {
            it = first;
            ++first;
            _rbt.erase(*it);
        }
    }

    template <SET_TEMPLATE>
    void SET_CLASS::swap(set &x)
    {
        _rbt.swap(x._rbt);
    }

    template <SET_TEMPLATE>
    void SET_CLASS::clear()
    {
        _rbt.clear();
    }

    template <SET_TEMPLATE>
    typename SET_CLASS::key_compare SET_CLASS::key_comp() const
    {
        return (_rbt.key_comp());
    }

    template <SET_TEMPLATE>
    typename SET_CLASS::value_compare SET_CLASS::value_comp() const
    {
        return (value_compare(_rbt.key_comp()));
    }

    template <SET_TEMPLATE>
    typename SET_CLASS::iterator SET_CLASS::find(const value_type &val) const
    {
        iterator it(_rbt.search(val));
        return (it);
    }

    template <SET_TEMPLATE>
    typename SET_CLASS::size_type SET_CLASS::count(const value_type &val) const
    {
        const_iterator it = find(val);
        if (it != end())
            return (1);
        return (0);
    }

    template <SET_TEMPLATE>
    typename SET_CLASS::iterator SET_CLASS::lower_bound(const value_type &val) const
    {
        return (_rbt.lower_bound(val));
    }

    template <SET_TEMPLATE>
    typename SET_CLASS::iterator SET_CLASS::upper_bound(const value_type &val) const
    {
        return (_rbt.upper_bound(val));
    }

    template <SET_TEMPLATE>
    ft::pair<typename SET_CLASS::iterator, typename SET_CLASS::iterator>
    SET_CLASS::equal_range(const value_type &val) const
    {
        iterator lowerBound = lower_bound(val);
        iterator upperBound = upper_bound(val);
        return (ft::make_pair(lowerBound, upperBound)); 
    }

    template <SET_TEMPLATE>
    typename SET_CLASS::allocator_type SET_CLASS::get_allocator() const
    {
        return (_rbt.get_allocator());
    }
}