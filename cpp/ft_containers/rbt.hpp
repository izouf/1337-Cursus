#pragma once

#include "algorithm.hpp"
#include "rbt_iterator.hpp"
#include "rbt_reverse_iterator.hpp"
#include "rbt_node.hpp"

#define RBT_TEMPLATE    typename Key,           \
                        typename Val,           \
                        typename Keyofvalue,    \
                        typename Compare,       \
                        typename Alloc

#define RBT_CLASS   rbtree<Key, Val, Keyofvalue, Compare, Alloc>

namespace ft
{
    template <typename Key,
              typename Val,
              typename Keyofvalue,
              typename Compare,
              typename Alloc = std::allocator<val> >
    class   rbtree
    {
        typedef typename Alloc::template rebind<rbt_node<Val> >::other  node_allocator;

        public:
            typedef rbt_node<Val>   rbt_node;
            typedef rbt_node*       node_ptr;
            typedef const rbt_node* const_node_ptr;

            typedef Key                                         key_type;
            typedef Val                                         value_type;
            typedef Compare                                     key_compare;
            typedef value_type*                                 pointer;
            typedef const value_type*                           const_pointer;
            typedef value_type&                                 reference;
            typedef const value_type&                           const_reference;
            typedef size_t                                      size_type;
            typedef ptrdiff_t                                   difference_type;
            //typedef Alloc                                     allocator_type;
            typedef node_allocator                              allocator_type;
            typedef ft::rbt_iterator<pointer>                   iterator;
            typedef ft::rbt_iterator<const_pointer>             const_iterator;
            typedef ft::rbt_reverse_iterator<iterator>          reverse_iterator;
            typedef ft::rbt_reverse_iterator<const_iterator>    const_reverse_iterator;

            explicit rbtree(const key_compare& comp = key_compare(), const allocator_type &alloc = allocator_type());

            rbtree(const rbtree &src);

            rbtree &operator=(const rbtree &rhs);

            ~rbtree();

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

            void swap(rbtree &x);

            void clear();

            key_compare key_comp() const;

            iterator lower_bound(const key_type &k);

            const_iterator lower_bound(const key_type &k) const;

            iterator upper_bound(const key_type &k);

            const_iterator upper_bound(const key_type &k) const;

            allocator_type get_allocator() const;

            /**************** Red Black Tree Functions ********************/
            node_ptr    search(Key k) const;

            node_ptr    search(Key k, node_ptr _root) const;

            node_ptr    minimum(node_ptr node) const;

            node_ptr    maximum(node_ptr node) const;

            node_ptr    sucessor(node_ptr x) const;

            node_ptr    predecessor(node_ptr x) const;

            void        insert(value_type data);
            
            void        insert(value_type data, node_ptr _root);

            iterator    insert_unique(value_type data);

            void        erase(Key key);

            node_ptr    get_root();

            private:
                allocator_type  _alloc;
                node_ptr        root;
                node_ptr        TNULL;
                size_type       _size;
                key_compare     _comp;

            /**************** Red Black Tree Helpers **********************/
            void    left_rotate(node_ptr x);

            void    right_rotate(node_ptr x);

            void    destructor_h(node_ptr node);

            node_ptr    search_h(node_ptr node, Key key) const;

            iterator    insert_node_h(value_type data);

            void        erase_fix(node_ptr x);

            void        transplant(node_ptr u, node_ptr v);

            void        erase_node_h(node_ptr z);

            void        insert_fix(node_ptr node);

            void        copy_rbt(node_ptr node);
            
            rbt_node    create_node(value_type data, rbt_color color);
    };

    template <RBT_TEMPLATE>
    inline bool operator==(const RBT_CLASS &x, const RBT_CLASS &y)
    {
        return (x.size() == y.size() && ft::equal(x.begin(), x.end(), y.begin()));
    }

    template <RBT_TEMPLATE>
    inline bool operator!=(const RBT_CLASS &x, const RBT_CLASS &y)
    {
        return (!(x == y));
    }

    template <RBT_TEMPLATE>
    inline bool operator<(const RBT_CLASS &x, const RBT_CLASS &y)
    {
        return (ft::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end()));
    }

    template <RBT_TEMPLATE>
    inline bool operator<=(const RBT_CLASS &x, const RBT_CLASS &y)
    {
        return (!(y < x));
    }

    template <RBT_TEMPLATE>
    inline bool operator>(const RBT_CLASS &x, const RBT_CLASS &y)
    {
        return (y < x);
    }

    template <RBT_TEMPLATE>
    inline bool operator>=(const RBT_CLASS &x, const RBT_CLASS &y)
    {
        return (!(x < y));
    }
    
    #include "rbt.tpp"
    #include "rbt_private.tpp"
}