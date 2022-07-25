#pragma once

#include "rbt.hpp"

namespace ft
{
    template <RBT_TEMPLATE>
    void RBT_CLASS::left_rotate(node_ptr x)
    {
        node_ptr    y;

        y = x->right;
        x->right = y->left;
        if (y->left != TNULL)
            y ->left->parent = x;
        y->parent = x->parent;
        if (x->parent == TNULL)
            root = y;
        else if (x == x->parent->left)
            x->parent->left = y;
        else
            x->parent->right = y;
        y->left = x;
        x->parent = y;
    }

    template <RBT_TEMPLATE>
    void RBT_CLASS::right_rotate(node_ptr x)
    {
        node_ptr    y;

        y = x->left;
        x->left = y->right;
        if (y->right != TNULL)
            y ->right->parent = x;
        y->parent = x->parent;
        if (x->parent == TNULL)
            root = y;
        else if (x == x->parent->right)
            x->parent->right = y;
        else
            x->parent->left = y;
        y->right = x;
        x->parent = y;
    }

    template <RBT_TEMPLATE>
    typename RBT_CLASS::node_ptr RBT_CLASS::search_h(node_ptr node, Key key) const
    {
        if (node == NULL || (!_comp(key, Keyofvalue()(node->data)) && !_comp(Keyofvalue()(node->data), key)))
            return (node);
        if (_comp(key, Keyofvalue()(node->data)))
            return (search_h(node->left, key));
        else
            return (search_h(node->right, key));
    }

    template <RBT_TEMPLATE>
    typename RBT_CLASS::iterator RBT_CLASS::insert_node_h(value_type data)
    {
        node_ptr x = root;
        node_ptr y = TNULL;
        node_ptr z = _alloc.allocate(1);
        _alloc.construct(z, create_node(data, RED));

        while (x != TNULL)
        {
            y = x;
            if (_comp(Keyofvalue()(z->data), Keyofvalue()(x->data)))
                x = x->left;
            else
                x = x->right;
        }
        z->parent = y;
        if (y == TNULL)
            root = z;
        else if (_comp(Keyofvalue()(z->data), Keyofvalue()(y->data)))
            y->left = z;
        else
        {
            y->right = z;
            z->left = TNULL;
            z->right = TNULL;
            z->color = RED;
        }

        insert_fix(z);
        TNULL->root = root;
        _size++;
        return (iterator(z));
    }

    template <RBT_TEMPLATE>
    void    RBT_CLASS::erase_fix(node_ptr x)
    {
        node_ptr    w;

        while (x != root && x->color == BLACK)
        {
            if (x == x->parent->left)
            {
                w = x->parent->right;
                if (w->color == RED)
                {
                    w->color = BLACK;
                    x->parent->color = RED;
                    left_rotate(x->parent);
                    w = x->parent->right;
                }
                if (w->left->color == BLACK && w->right->color == BLACK)
                {
                    w->color = RED;
                    x = x->parent;
                }
                else
                {
                    if (w->right->color == BLACK)
                    {
                        w->left->color = BLACK;
                        w->color = RED;
                        right_rotate(w);
                        w = x->parent->right;
                    }
                    x->color = x->parent->color;
                    x->parent->color = BLACK;
                    w->right->color = BLACK;
                    left_rotate(x->parent);
                    x = root;
                }
            }
            else
            {
                w = x->parent->left;
                if (w->color == RED)
                {
                    w->color = BLACK;
                    x->parent->color = RED;
                    right_rotate(x->parent);
                    w = x->parent->left;
                }
                if (w->right->color == BLACK && w->left->color == BLACK)
                {
                    w->color = RED;
                    x = x->parent;
                }
                else
                {
                    if (w->left->color == BLACK)
                    {
                        w->right->color == BLACK;
                        w->color = RED;
                        left_rotate(w);
                        w = x->parent->left;
                    }
                    w->color = x->parent->color;
                    x->parent->color = BLACK;
                    w->left->color = BLACK;
                    right_rotate(x->parent);
                    x = root;
                }
            }
        }
        x->color = BLACK;
    }

    template <RBT_TEMPLATE>
    void RBT_CLASS::transplant(node_ptr u, node_ptr v)
    {
        if (u->parent == TNULL)
            root = v;
        else if (u == u->parent->left)
            u->parent->left = v;
        else
            u->parent->right = v;
        v->parent = u->parent;
    }

    template <RBT_TEMPLATE>
    void RBT_CLASS::erase_node_h(node_ptr z)
    {
        node_ptr    x;
        node_ptr    y;
        rbt_color   y_original_c;

        y = z;
        y_original_c = y->color;
        if (z->left == TNULL)
        {
            x = z->right;
            transplant(z, z->right);
        }
        else if (z->right == TNULL)
        {
            x = z->left;
            transplant(z, z->left);
        }
        else
        {
            y = minimum(z->right);
            y_original_c = y->color;
            x = y->right;
            if (z != z->right)
            {
                transplant(y, y->right);
                y->right = z->right;
                y->right->parent = y;
            }
            else
                x->parent = y;
            transplant(z, y);
            y->left = z->left;
            y->left->parent = y;
            y->color = z->color;
        }
        _alloc.destroy(z);
        _alloc.deallocate(z, 1);

        if (y_original_c == BLACK)
            erase_fix(x);
        TNULL->root = root;
        _size--;
    }

    template <RBT_TEMPLATE>
    void    RBT_CLASS::insert_fix(node_ptr z)
    {
        node_ptr    y;
        while (z->parent->color == RED)
        {
            if (z->parent == z->parent->parent->left)
            {
                y = z->parent->parent->right;
                if (y->color == RED)
                {
                    z->parent->color = BLACK;
                    y->color = BLACK;
                    z->parent->parent->color = RED;
                    z = z->parent->parent;
                }
                else
                {
                    if (z == z->parent->right)
                    {
                        z = z->parent;
                        left_rotate(z);
                    }
                    z->parent->color = BLACK;
                    z->parent->parent->color = RED;
                    right_rotate(z->parent->parent);
                }
            }
            else
            {
                y = z->parent->parent->left;
                if (y->color == RED)
                {
                    z->parent->color = BLACK;
                    y->color = BLACK;
                    z->parent->parent->color = RED;
                    z = z->parent->parent;
                }
                else
                {
                    if (z == z->parent->left)
                    {
                        z = z->parent;
                        right_rotate(z);
                    }
                    z->parent->color = BLACK;
                    z->parent->parent->color = RED;
                    left_rotate(z->parent->parent);
                }
            }
        }
        root->color = BLACK;
    }

    template <RBT_TEMPLATE>
    void RBT_CLASS::copy_rbt(node_ptr node)
    {
        if (node != node->leaf)
        {
            insert_unique(node->data);
            copy_rbt(node->left);
            copy_rbt(node->right);
        }
    }

    template <RBT_TEMPLATE>
    typename RBT_CLASS::rbt_node RBT_CLASS::create_node(value_type data, rbt_color color)
    {
        return (rbt_node(data, root, TNULL, TNULL, TNULL, TNULL, color));
    }
}