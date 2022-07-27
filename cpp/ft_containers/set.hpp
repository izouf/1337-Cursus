#pragma once

#define SET_TEMPLATE typename Key,
                     typename Compare,
                     typename alloc

#define SET_CLASS set <Key, Compare, Alloc>

#include <functional>
#include <memory>
#include "rbt.hpp"
#include "utility.hpp"

namespace 
{
    template <class Key,
              class Compare = std::less<Key>,
              class Alloc = std::allocator<Key>>
    class set
    {
        template <typename P>
        struct _Identity
        {
            Key operator()(const P &x)const
            {
                return (x);
            }
        };

        public:
            typedef Key                             key_type;
            typedef Key                             value_type;
            typedef Compare                         key_compare;
            typedef Compare                         value_compare;
            typedef typename Alloc::reference       reference;
            typedef typename Alloc::const_reference const_reference;
            typedef typename Alloc::pointer         pointer;
            typedef typename Alloc::const_pointer   const_pointer;

        private:
            typedef rbt<key_type, value_type, _Identity<value_type>, key_compare, Alloc> rbt_type;

            rbt_type    _rbt;

        public:
            typedef typename rbt_type::allocator_type               allocator_type;
            typedef typename rbt_type::iterator                     iterator;
            typedef typename rbt_type::const_iterator               const_iterator;
            typedef typename rbt_type::reverse_iterator             reverse_iterator;
            typedef typename rbt_type::const_reverse_iterator       const_reverse_iterator;
            typedef typename rbt_type::size_type                    size_type;
            typedef typename rbt_type::difference_type              difference_type;

            explicit set(const key_compare &comp = key_compare(),
                        const allocator_type &alloc = allocator_type());

            template <class InputIterator>
            set(InputIterator first, InputIterator last,
                const key_compare &comp = key_compare(),
                const allocator_type &alloc = allocator_type());

            set(const set &x);

            ~set();

            set &operator=(const set &x);

            iterator begin();

            const_iterator begin() const;

            iterator end();

            const_iterator end() const;

            reverse_iterator rbegin();

            const_reverse_iterator rbegin() const;

            reverse_iterator rend();

            const_reverse_iterator rend() const;

            bool empty() const;

            size_type size() const;

            size_type max_size() const;

            ft::pair<iterator, bool> insert(const value_type &val);

            iterator insert(iterator position, const value_type &val);

            template <class InputIterator>
            void insert(InputIterator first, InputIterator last);

            void erase (iterator position);

            size_type erase(const value_type &val);

            void erase(iterator first, iterator last);

            void swap(set &x);

            void clear();

            key_compare key_comp() const;

            value_compare value_comp() const;

            iterator find(const value_type &val) const;

            size_type count(const value_type &val) const;

            iterator lower_bound(const value_type &val) const;

            iterator upper_bound(const value_type &val) const;

            ft::pair<iterator, iterator> equal_range(const value_type &val) const;

            allocator_type get_allocator() const;

            template <typename K1, typename C1, typename A1>
            friend bool
            operator==(const set<K1, C1, A1> &, const set<K1, C1, A1> &);

            template <typename K1, typename C1, typename A1>
            friend bool
            operator<(const set<K1, C1, A1> &, const set<K1, C1, A1> &);
    };

    template <class Key, class Compare, class Alloc>
        operator==(const set<Key, Compare, Alloc> &lhs,
                   const set<Key, Compare, Alloc> &rhs)
    {
        return (lhs._rbt == rhs._rbt);
    }

    template <class Key, class Compare, class Alloc>
        operator!=(const set<Key, Compare, Alloc> &lhs,
                   const set<Key, Compare, Alloc> &rhs)
    {
        return (!(lhs == rhs));
    }

    template <class Key, class Compare, class Alloc>
        operator<(const set<Key, Compare, Alloc> &lhs,
                   const set<Key, Compare, Alloc> &rhs)
    {
        return (lhs._rbt < rhs._rbt);
    }

    template <class Key, class Compare, class Alloc>
        operator<=(const set<Key, Compare, Alloc> &lhs,
                   const set<Key, Compare, Alloc> &rhs)
    {
        return (!(rhs < lhs));
    }

    template <class Key, class Compare, class Alloc>
        operator>(const set<Key, Compare, Alloc> &lhs,
                   const set<Key, Compare, Alloc> &rhs)
    {
        return (rhs < lhs);
    }

    template <class Key, class Compare, class Alloc>
        operator>=(const set<Key, Compare, Alloc> &lhs,
                   const set<Key, Compare, Alloc> &rhs)
    {
        return (!(lhs < rhs));
    }
}

#include "set.tpp"