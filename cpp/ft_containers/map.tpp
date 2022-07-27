#pragma once

#include "map.hpp"

namespace ft
{
    template <MAP_TEMPLATE>
    MAP_CLASS:map(const key_compare &comp, const allocator_type &alloc) : _rbt(comp, alloc) {}

    template <MAP_TEMPLATE>
    template <class InputIterator>
    MAP_CLASS::map(InputIterator first, InputIterator last,
                   const key_compare &comp,
                   const allocator_type &alloc) : _rbt(comp, alloc)
    {
        while (first != last)
        {
            insert(*first);
            ++first;
        }
    }

    template <MAP_TEMPLATE>
    MAP_CLASS::map(const map &x) : _rbt(x._rbt){}

    template <MAP_TEMPLATE>
    MAP_CLASS::~map()
    {
        clear();
    }

    template <MAP_TEMPLATE>
    MAP_CLASS &MAP_CLASS::operator=(const map &x)
    {
        _rbt = x._rbt;
        return (*this);
    }

    template<MAP_TEMPLATE>
    typename MAP_CLASS::iterator MAP_CLASS::begin()
    {
        return (_rbt.begin());
    }

    template<MAP_TEMPLATE>
    typename MAP_CLASS::const_iterator MAP_CLASS::begin() const
    {
        return (_rbt.begin());
    }

    template<MAP_TEMPLATE>
    typename MAP_CLASS::iterator MAP_CLASS::end()
    {
        return (_rbt.end());
    }

    template<MAP_TEMPLATE>
    typename MAP_CLASS::const_iterator MAP_CLASS::end() const
    {
        return (_rbt.end());
    }

    template<MAP_TEMPLATE>
    typename MAP_CLASS::reverse_iterator MAP_CLASS::rbegin()
    {
        return (_rbt.rbegin());
    }

    template<MAP_TEMPLATE>
    typename MAP_CLASS::const_reverse_iterator MAP_CLASS::begin() const
    {
        return (_rbt.rbegin());
    }

    template<MAP_TEMPLATE>
    typename MAP_CLASS::reverse_iterator MAP_CLASS::rend()
    {
        return (_rbt.rend());
    }

    template<MAP_TEMPLATE>
    typename MAP_CLASS::const_reverse_iterator MAP_CLASS::rend() const
    {
        return (_rbt.rend());
    }

    template<MAP_TEMPLATE>
    bool MAP_CLASS::empty() const
    {
        return (_rbt.empty());
    }

    template<MAP_TEMPLATE>
    typename MAP_CLASS::size_type MAP_CLASS::size() const
    {
        return (_rbt.size());
    }

    template<MAP_TEMPLATE>
    typename MAP_CLASS::size_type MAP_CLASS::max_size() const
    {
        return (_rbt.max_size());
    }

    template<MAP_TEMPLATE>
    typename MAP_CLASS::mapped_type &MAP_CLASS::operator[](const key_type &k)
    {
        iterator x = insert(begin(), ft::make_pair(k, mapped_type()));
        return (x->second;)
    }

    template <MAP_TEMPLATE>
    ft::pair<typename MAP_CLASS::iterator, bool> MAP_CLASS::insert(const value_type &val)
    {
        iterator x = find(val.first);
        if (x != end())
            return (ft::make_pair(x, false));
        else
        {
            iterator y = _rbt.insert_unique(val);
            return (ft::make_pair(y, true));
        }
    }

    template <MAP_TEMPLATE>
    ft::pair<typename iterator MAP_CLASS::insert(iterator position, const value_type &val))
    {
        iterator x = find(val.first);
        if (x != end())
            return (x);
        else
        {
            _rbt.insert(val, position.base());
            iterator y = find(val.first);
            return (y);
        }
    }

    template <MAP_TEMPLATE>
    template <class InputIterator>
    void MAP_CLASS::insert(InputIterator first, InputIterator last)
    {
        while (first != last)
        {
            insert(*first);
            ++first;
        }
    }

    template <MAP_TEMPLATE>
    void MAP_CLASS::erase(iterator position)
    {
        _rbt.erase(position->first);
    }

    template <MAP_TEMPLATE>
    typename MAP_CLASS::size_type MAP_CLASS::erase(const key_type &k)
    {
        if (find(k) != end())
        {
            _rbt.erase(k);
            return (1);
        }
        return (0);
    }

    template <MAP_TEMPLATE>
    void MAP_CLASS::erase(iterator first, iterator last)
    {
        iterator    it;
        while (first != last)
        {
            it = first;
            ++first;
            _rbt.erase(it->first);
        }
    }

    template <MAP_TEMPLATE>
    void MAP_CLASS::swap(map &x)
    {
        _rbt.swap(x._rbt);
    }

    template <MAP_TEMPLATE>
    void MAP_CLASS::clear()
    {
        _rbt.clear();
    }

    template <MAP_TEMPLATE>
    typename MAP_CLASS::key_compare MAP_CLASS::key_comp() const
    {
        return (_rbt.key_comp());
    }

    template <MAP_TEMPLATE>
    typename MAP_CLASS::value_compare MAP_CLASS::value_comp() const
    {
        return (value_compare(_rbt.key_comp()));
    }

    template <MAP_TEMPLATE>
    typename MAP_CLASS::iterator MAP_CLASS::find(const key_type &k)
    {
        iterator    it(_rbt.search(k));
        return (it);
    }

    template <MAP_TEMPLATE>
    typename MAP_CLASS::const_iterator MAP_CLASS::find(const key_type &k) const
    {
        const_iterator    it(_rbt.search(k));
        return (it);
    }

    template <MAP_TEMPLATE>
    typename MAP_CLASS::size_type MAP_CLASS::count(const key_type &k) const
    {
        const_iterator it = find(k);
        if (it != end())
            return (1);
        return (0);
    }

    template <MAP_TEMPLATE>
    typename MAP_CLASS::iterator MAP_CLASS::lower_bound(const key_type &k)
    {
        return (_rbt.lower_bound(k));
    }

    template <MAP_TEMPLATE>
    typename MAP_CLASS::const_iterator MAP_CLASS::lower_bound(const key_type &k) const
    {
        return (_rbt.lower_bound(k));
    }

    template <MAP_TEMPLATE>
    typename MAP_CLASS::iterator MAP_CLASS::upper_bound(const key_type &k)
    {
        return (_rbt.upper_bound(k));
    }

    template <MAP_TEMPLATE>
    typename MAP_CLASS::const_iterator MAP_CLASS::upper_bound(const key_type &k) const
    {
        return (_rbt.upper_bound(k));
    }

    template <MAP_TEMPLATE>
    ft::pair<typename MAP_CLASS::iterator, typename MAP_CLASS::iterator>
    MAP_CLASS::equal_range(const key_type &k)
    {
        iterator lower_bound = lower_bound(k);
        iterator upper_bound = upper_bound(k);
        return (ft::make_pair(lower_bound, upper_bound));
    }

    template <MAP_TEMPLATE>
    ft::pair<typename MAP_CLASS::const_iterator, typename MAP_CLASS::const_iterator>
    MAP_CLASS::equal_range(const key_type &k) const
    {
        const_iterator lowerBound = lower_bound(k);
        const_iterator upperBound = upper_bound(k);
        return (ft::make_pair(lowerBound, upperBound));
    }

    template <MAP_TEMPLATE>
    typename MAP_CLASS::allocator_type MAP_CLASS::get_allocator() const
    {
        return (_rbt.get_allocator());
    }
}