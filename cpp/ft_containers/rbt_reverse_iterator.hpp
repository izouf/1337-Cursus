#pragma once

#include "iterator_traits.hpp"
#include "rbt_node.hpp"

namespace ft
{
    template <typemame Iterator>
    class rbt_reverse_iterator : public iterator<typename iterator_traits<Iterator>::iterator_category,
                                                 typename iterator_traits<Iterator>::value_type,
                                                 typename iterator_traits<Iterator>::difference_type,
                                                 typename iterator_traits<Iterator>::pointer,
                                                 typename iterator_traits<Iterator>::reference>
    {
        public:
            typedef Iterator                                                iterator_type;
            typedef typename iterator_traits<Iterator>::iterator_category   iterator_category;
            typedef typename iterator_traits<Iterator>::value_type          value_type;
            typedef typename iterator_traits<Iterator>::difference_type     difference_type;
            typedef typename iterator_traits<Iterator>::pointer             pointer;
            typedef typename iterator_traits<Iterator>::reference           reference;

            typedef rbt_node<value_type>    rbt_node;
            typedef rbt_node*               node_ptr;
            typedef const rbt_node*         const_node_ptr;

            protected:
                node_ptr    node;
            public:
                rbt_reverse_iterator() : node(NULL) {}
                explicit rbt_reverse_iterator(node_ptr _node) : node(_node) {}
                explicit rbt_reverse_iterator(iterator_type x) : node(x.base()) {}
                rbt_reverse_iterator(const rbt_reverse_iterator &x) : node(x.node) {}

                template <typename Iter>
                rbt_reverse_iterator(const rbt_reverse_iterator<Iter> &x) : node(x.node) {}

                ~rbt_reverse_iterator() {}

                template<typename Iter>
                rbt_reverse_iterator &operator=(const rbt_reverse_iterator<Iter> &x)
                {
                    node = x.base();
                    return (*this);
                }

                const node_ptr base() const 
                {
                    return (node);
                }

                reference operator*() const 
                {
                    node_ptr tmp = rbt_node::predecessor(node);
                    return (tmp->data);
                }

                rbt_reverse_iterator &operator++()
                {
                    node = rbt_node::predecessor(node);
                    return (*this);
                }

                rbt_reverse_iterator operator++(int)
                {
                    node_ptr tmp = node;
                    node = rbt_node::predecessor(node);
                    return (rbt_reverse_iterator(tmp));
                }

                rbt_reverse_iterator &operator--()
                {
                    node = rbt_node::successor(node);
                    return (*this);
                }

                rbt_reverse_iterator operator--(int)
                {
                    node_ptr tmp = node;
                    node = rbt_node::successor(node);
                    return (rbt_reverse_iterator(tmp));
                }

                pointer operator->() const
                {
                    return (&(this->operator*()));
                }
    };

    template <typename Iterator1, typename Iterator2>
    inline bool operator==(const rbt_reverse_iterator<Iterator1> &lhs, const rbt_reverse_iterator<Iterator2> &rhs)
    {
        return (lhs.base() == rhs.base());
    }

    template <typename Iterator>
    inline bool operator==(const rbt_reverse_iterator<Iterator> &lhs, const rbt_reverse_iterator<Iterator> &rhs)
    {
        return (lhs.base() == rhs.base());
    }

    template <typename Iterator1, typename Iterator2>
    inline bool operator!=(const rbt_reverse_iterator<Iterator1> &lhs, const rbt_reverse_iterator<Iterator2> &rhs)
    {
        return (!(lhs == rhs));
    }

    template <typename Iterator>
    inline bool operator!=(const rbt_reverse_iterator<Iterator> &lhs, const rbt_reverse_iterator<Iterator> &rhs)
    {
         return (!(lhs == rhs));
    }
}