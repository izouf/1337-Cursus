#pragma once

#include "iterator_traits.hpp"
#include "rbt_node.hpp"

namespace ft
{
    template <typnename Iterator>
    class rbt_iterator : public iterator<std::bidirectional_iterator_tag, Iterator>
    {
        public:
            typedef Iterator                                            iterator_type;
            typedef typename iterator_traits<Iterator>::value_type      value_type;
            typedef typename iterator_traits<Iterator>::difference_type difference_type;
            typedef typename iterator_traits<Iterator>::pointer         pointer;
            typedef typename iterator_traits<Iterator>::reference       reference;

            typedef rbt_node<value_type>    rbt_node;
            typedef rbt_node*               node_ptr;
            typedef const rbt_node*          const_node_ptr;

        protected:
            node_ptr    node;
        public:
            rbt_iterator() : node(NULL) {}
            explicit rbt_iterator(node_ptr _node) : node(_node) {}

            template <typename Iter>
            rbt_iterator(const rbt_iterator<Iter> &i) : node(i.base()) {}

            ~rbt_iterator() {}

            template <typename Iter>
            rbt_iterator &operator=(const rbt_iterator<Iter> &i)
            {
                node = i.base();
                return (*this);
            }

            const node_ptr base() const
            {
                return (node);
            }

            reference operator*() const 
            {
                return (node->data);
            }

            rbt_iterator &operator++()
            {
                node = rbt_node::successor(node);
                return (*this);
            }

            rbt_iterator operator++(int)
            {
                node_ptr tmp = node;
                node = rbt_node::successor(node);
                return (rbt_iterator(tmp));
            }

            rbt_iterator &operator--()
            {
                node = rbt_node::predecessor(node);
                return (*this);
            }

            rbt_iterator operator--(int)
            {
                node_ptr tmp = node;
                node = rbt_node::predecessor(node);
                return (rbt_iterator(tmp));
            }

            pointer operator->()const
            {
                return (&(operator*()));
            }
    };

    template <typnename Iterator1, typename Iterator2>
    inline bool operator==(const rbt_iterator<Iterator1> &lhs, const rbt_iterator<Iterator2> &rhs)
    {
        return (lhs.base() == rhs.base());
    }

    template <typnename Iterator>
    inline bool operator==(const rbt_iterator<Iterator> &lhs, const rbt_iterator<Iterator> &rhs)
    {
        return (lhs.base() == rhs.base());
    }

    template <typnename Iterator1, typename Iterator2>
    inline bool operator!=(const rbt_iterator<Iterator1> &lhs, const rbt_iterator<Iterator2> &rhs)
    {
        return (lhs.base() != rhs.base());
    }

    template <typnename Iterator>
    inline bool operator!=(const rbt_iterator<Iterator> &lhs, const rbt_iterator<Iterator> &rhs)
    {
        return (lhs.base() != rhs.base());
    }
}