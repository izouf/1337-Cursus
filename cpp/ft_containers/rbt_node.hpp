#pragma once

namespace ft
{
    enum    rbt_color
    {
        BLACK = false,
        RED = true
    };

    template <typename T>
    struct rbt_node
    {
        typedef rbt_node<T>         rbt_node;
        typedef rbt_node*           node_ptr;
        typedef const rbt_node*     const_node_ptr;

        explicit rbt_node(const T &_data,
                                node_ptr    _root,
                                node_ptr    _leaf,
                                node_ptr    _parent = NULL,
                                node_ptr    _right = NULL,
                                node_ptr    _left = NULL,
                                rbt_color   _color = BLACK)
                                                            :   data(_data),
                                                                root(_root),
                                                                leaf(_leaf),
                                                                parent(_parent),
                                                                right(_right),
                                                                left(_left),
                                                                color(_color) {}
        T       data;
        node_ptr    root;
        node_ptr    leaf;
        node_ptr    parent;
        node_ptr    right;
        node_ptr    left;
        rbt_color   color;

        static node_ptr get_root(node_ptr node)
        {
            return (node->leaf->root);
        }

        static node_ptr minimum(node_ptr node)
        {
            while (node->left != node->leaf)
                node = node->left;
            return (node);
        }

        static node_ptr maximum(node_ptr node)
        {
            while (node->right != node->leaf)
                node = node->right;
            return (node);
        }

        static node_ptr successor(node_ptr x)
        {
            if (x == x->leaf)
                return (maximum(get_root(x)));
            if (x->right != x->leaf)
                return (minimum(x->right));
            node_ptr y = x->parent;
            while (y != y->leaft && x== y->right)
            {
                x = y;
                y = y->parent;
            }
            return (y);
        }

        static node_ptr predecessor(node_ptr x)
        {
            if (x == x->leaf)
                return (maximum(get_root(x)));
            if (x->left != x->leaf)
                return (minimum(x->left));
            node_ptr y = x->parent;
            while (y != y->leaft && x== y->left)
            {
                x = y;
                y = y->parent;
            }
            return (y);
        }                      
    };
}