#pragma once

#include "rb_tree.hpp"

namespace ft
{
    template <RBT_TEMPLATE>
    RBT_CLASS::rbtree(const key_compare &comp, const allocator_type &alloc)
    {
        _alloc = alloc;
        TNULL = _alloc.allocate(1);
        _alloc.construct(TNULL, create_node(value_type(), BLACK));
        root = TNULL;
        _size = 0;
        _comp = comp;
    }

    template <RBT_TEMPLATE>
    RBT_CLASS::rbtree(const rbtree &src)
    {
        _alloc = src._alloc;
        TNULL = _alloc.allocate(1);
        _alloc.construct(TNULL, create_node(value_type(), BLACK));
        root = TNULL;
        copy_rbt(src.root);
        _size = src.size;
        _comp = src.comp;
    }

    template <RBT_TEMPLATE>
    RBT_CLASS &RBT_CLASS::operator=(const rbtree &rhs)
    {
        if (this != &rhs)
        {
            this->~rbtree();
            _alloc = rhs._alloc;
            TNULL = _alloc.allocate(1);
            _alloc.construct(TNULL, create_node(value_type(), BLACK));
            root = TNULL;
            copy_rbt(rhs.root);
            _size = rhs._size;
            _comp = rhs._comp;
        }
        return (*this);
    }

    template <RBT_TEMPLATE>
    RBT_CLASS::~rbt_tree()
    {
        destructor_h(root);
        _alloc.destroy(TNULL);
        _alloc.deallocate(TNULL, 1);
        _size = 0;
    }

    template <RBT_TEMPLATE>
    typename RBT_CLASS::iterator RBT_CLASS::begin()
    {
        return (iterator(minimum(root)));
    }

    template <RBT_TEMPLATE>
    typename RBT_CLASS::const_iterator RBT_CLASS::begin() const
    {
        return (const_iterator(minimum(root)));
    }

    template <RBT_TEMPLATE>
    typename RBT_CLASS::iterator RBT_CLASS::end()
    {
        return (iterator(TNULL));
    }

    template <RBT_TEMPLATE>
    typename RBT_CLASS::const_iterator RBT_CLASS::end() const
    {
        return (const_iterator(TNULL));
    }

    template <RBT_TEMPLATE>
    typename RBT_CLASS::reverse_iterator RBT_CLASS::rbegin()
    {
        return (reverse_iterator(end()));
    }

    template <RBT_TEMPLATE>
    typename RBT_CLASS::const_reverse_iterator RBT_CLASS::rbegin() const
    {
        return (const_reverse_iterator(end()));
    }

    template <RBT_TEMPLATE>
    typename RBT_CLASS::reverse_iterator RBT_CLASS::rend()
    {
        return (reverse_iterator(begin()));
    }

    template <RBT_TEMPLATE>
    typename RBT_CLASS::const_reverse_iterator RBT_CLASS::rend() const
    {
        return (const_reverse_iterator(begin()));
    }

    template <RBT_TEMPLATE>
    typename RBT_CLASS::size_type RBT_CLASS::size() const
    {
        return (_size);
    }

    template <RBT_TEMPLATE>
    typename RBT_CLASS::size_type RBT_CLASS::max_size() const
    {
        return (_alloc.max_size());
    }

    template <RBT_TEMPLATE>
    void RBT_CLASS::swap(rbtree &x)
    {
        allocator_type  tmp_alloc = x._alloc;
        node_ptr        tmp_root = x.root;
        node_ptr        tmp_TNUL = x.TNULL;
        size_type       tmp_size = x._size;
        key_compare     tmp_comp = x._comp;

        x._alloc = _alloc;
        x.root = root;
        x.TNULL = TNULL;
        x._size = _size;
        x._comp = _comp;

        _alloc = tmp_alloc;
        root = tmp_root;
        TNULL = tmp_TNULL;
        _size = tmp_size;
        _comp = tmp_comp;
    }

    template <RBT_TEMPLATE>
    void    RBT_CLASS::clear()
    {
        destructor_h(root);
        root = TNULL;
        _size = 0;
    }

    template <RBT_TEMPLATE>
    typename RBT_CLASS::key_compare RBT_CLASS::key_comp() const
    {
        return (_comp);
    }

    template <RBT_TEMPLATE>
    typename RBT_CLASS::iterator RBT_CLASS::lower_bound(const key_type &k)
    {
        node_ptr x = root; // Current
        node_ptr y = TNULL; // Last node > k

        while (x != TNULL)
            if (!_comp(Keyofvalue()(x->data), k))
                y = x, x = x->left;
            else
            x = x->right;
        return (iterator(y));
    }

    template <RBT_TEMPLATE>
    typename RBT_CLASS::const_iterator RBT_CLASS::lower_bound(const key_type &k) const
    {
        node_ptr x = root; // Current
        node_ptr y = TNULL; // Last node > k

        while (x != TNULL)
            if (!_comp(Keyofvalue()(x->data), k))
                y = x, x = x->left;
            else
            x = x->right;
        return (const_iterator(y));
    }

    template <RBT_TEMPLATE>
    typename RBT_CLASS::const_iterator RBT_CLASS::upper_bound(const key_type &k)
    {
        node_ptr x = root; // Current
        node_ptr y = TNULL; // Last node > k

        while (x != TNULL)
            if (_comp(k, Keyofvalue()(x->data)))
                y = x, x = x->left;
            else
            x = x->right;
        return (iterator(y));
    }

    template <RBT_TEMPLATE>
    typename RBT_CLASS::const_iterator RBT_CLASS::upper_bound(const key_type &k) const
    {
        node_ptr x = root; // Current
        node_ptr y = TNULL; // Last node > k

        while (x != TNULL)
            if (_comp(k, Keyofvalue()(x->data)))
                y = x, x = x->left;
            else
            x = x->right;
        return (const_iterator(y));
    }

    template <RBT_TEMPLATE>
    typename RBT_CLASS::allocator_type RBT_CLASS::get_allocator() const
    {
        return (_alloc);
    }

    /***************************** Red Black Tree Functions ***************************/

    template <RBT_TEMPLATE>
    typename RBT_CLASS::node_ptr RBT_CLASS::search(key k) const
    {
        return (search_h(root, k));
    }

    template <RBT_TEMPLATE>
    typename RBT_CLASS::node_ptr RBT_CLASS::search(key k, node_ptr _root) const
    {
        return (search_h(root, k));
    }

    template <RBT_TEMPLATE>
    typename RBT_CLASS::node_ptr RBT_CLASS::minimum(node_ptr node) const
    {
        return (rbt_node::minimum(node));
    }

    template <RBT_TEMPLATE>
    typename RBT_CLASS::node_ptr RBT_CLASS::maximum(node_ptr node) const
    {
        return (rbt_node::maximum(node));
    }

    template <RBT_TEMPLATE>
    typename RBT_CLASS::node_ptr RBT_CLASS::predecessor(node_ptr x) const
    {
        return (rbt_node::predecessor(x));
    }

    template <RBT_TEMPLATE>
    typename RBT_CLASS::node_ptr RBT_CLASS::successor(node_ptr x) const
    {
        return (rbt_node::successor(x));
    }

    template <RBT_TEMPLATE>
    void RBT_CLASS::insert(value_type data)
    {
        node_ptr z = search(Keyofvalue()(data), _root);
        if (z != TNULL)
            erase_node_h(z);
        insert_node_h(data);
    }

    template <RBT_TEMPLATE>
    void RBT_CLASS::insert(value_type data, node_ptr _root)
    {
        node_ptr z = search(Keyofvalue()(data), _root);
        if (z != TNULL)
            erase_node_h(z);
        insert_node_h(data);
    }

    template <RBT_TEMPLATE>
    typename RBT_CLASS::iterator RBT_CLASS::insert_unique(value_type data)
    {
        return (insert_node_h(data));
    }

    template <RBT_TEMPLATE>
    void RBT_CLASS::erase(Key key)
    {
        node_ptr z = search(key);
        if (z == TNULL)
            return ;
        erase_node_h(z);
    }

    template <RBT_TEMPLATE>
    typename RBT_CLASS::node_ptr RBT_CLASS::get_root()
    {
        return (root);
    }
}