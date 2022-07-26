#pragma once

#define MAP_TEMPLATE typename Key,
                     typename T,
                     typename Compare,
                     typename Alloc

#define MAP_CLAS map <Key, T, Compare, Alloc>

#include <functional>
#include <memory>
#include "rbt.hpp"
#include "pair.hpp"

namespace ft
{
    template <class Key,
              class T,
              class Compare = std::less<Key>.
              Class Alloc = std::allocator<ft::pair<const Key, T> > >
    class map
    {
        template <typename P>
        struct _Select1st
        {
            key operator()(const P &x) const
            {
                return (x.first);
            }
        };
    public:
        typedef Key                             key_type;
        typedef T                               mapped_type;
        typedef ft::pair<const Key, T>          value_type;
        typedef Compare                         key_compare;
        typedef typename Alloc::reference       reference;
        typedef typename Alloc::const_reference const_reference;
        typedef typename Alloc::pointer         pointer;
        typedef typename Alloc::const_pointer   const_pointer;

        class value_compare : public std::binary_function<value_type, value_type, bool>
        {
            friend class map <Key, T, Conpare, Alloc>;
            protected:
                Compare comp;

            explicit value_compare(Compare c) : comp(c) {}
            public:
                bool operator()(const value_type &x, const value_type &y) const
                {
                    return (comp(x.first, y.first));
                }
        };
        private:
            typedef rbt<key_type, value_type, _Select1st<value_type>, key_compare, Alloc>   rbt_type;

            rbt_type _rbt;
    
        public:
            typedef typename rbt_type::allocator_type           allocator_type;
            typedef typename rbt_type::iterator                 iterator;
            typedef typename rbt_type::const_iterator           const_iterator;
            typedef typename rbt_type::reverse_iterator         reverse_iterator;
            typedef typename rbt_type::const_reverse_iterator   const_reverse_iterator;
            typedef typename rbt_type::size_type                size_type;
            typedef typename rbt_type::difference_type          difference_type;

            explicit map(const key_compare &comp = key_compare(),
                         const allocator_type &alloc = allocator_type());

            template <class InputIterator>
            map(InputIterator first, InputIterator last,
                const key_compare &comp = key_compare(),
                const allocator_type &alloc = allocator_type());

            map (const map &x);

            ~map();

            map &operator=(const map &x);

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

            mapped_type &operator[](const key_type &k);

            ft::pair<iterator, bool> insert(const_value_type &val);

            iterator insert(iterator position, const value_type &val);

            template <class InputIterator>
            void insert(InputIterator first, InputIterator last);

            void erase(iterator position);

            size_type erase(const key_type &k);

            void erase(iterator first, iterator last);

            void swap(map &x);

            void clear();

            key_compare key_comp() const;

            value_compare value_comp() const;

            iterator find(const key_type &k);

            const_iterator find(const key_type &k) const;

            size_type   count(const key_type &k) const;

            iterator lower_bound(const key_type &k);

            const_iterator lower_bound(const key_type &k) const;

            iterator upper_bound(const key_type &k);

            const_iterator upper_bound(const key_type &k) const;

            ft::pair<iterator, iterator> equal_range(const key_type &k);

            ft::pair<const_iterator, const_iterator> equal_range(const key_type &k) const;

            allocator_type get_allocator() const;

            template <typename K1, typename T1, typename C1, typename A1>
            friend bool
            operator==(const map<K1, T1, C1, A1,>&,
                       const map<K1, T1, C1, A1>&);

                       template<typename K1, typename T1, typename C1, typename A1>
            friend bool
            operator<(const map<K1, T1, C1, A1,>&,
                       const map<K1, T1, C1, A1>&);
    };

    template <class Key, class T, class Compare, class Alloc>
    bool operator==(const map<Key, T, Compare, Alloc>& lhs,
                    const map<Key, T, Compare, Alloc>& rhs)
    {
        return (lhs._rbt == rhs._rbt);
    }

    template <class Key, class T, class Compare, class Alloc>
    bool operator!=(const map<Key, T, Compare, Alloc>& lhs,
                    const map<Key, T, Compare, Alloc>& rhs)
    {
        return (!(lhs == rhs));
    }

    template <class Key, class T, class Compare, class Alloc>
    bool operator<(const map<Key, T, Compare, Alloc>& lhs,
                    const map<Key, T, Compare, Alloc>& rhs)
    {
        return (lhs._rbt < rhs._rbt);
    }

    template <class Key, class T, class Compare, class Alloc>
    bool operator<=(const map<Key, T, Compare, Alloc>& lhs,
                    const map<Key, T, Compare, Alloc>& rhs)
    {
        return (!(rhs < lhs));
    }

    template <class Key, class T, class Compare, class Alloc>
    bool operator>(const map<Key, T, Compare, Alloc>& lhs,
                    const map<Key, T, Compare, Alloc>& rhs)
    {
        return (rhs < lhs);
    }

    template <class Key, class T, class Compare, class Alloc>
    bool operator>=(const map<Key, T, Compare, Alloc>& lhs,
                    const map<Key, T, Compare, Alloc>& rhs)
    {
        return (!(lhs < rhs));
    }    
}

#include "map.tpp"