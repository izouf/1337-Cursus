#pragma once

#include <cstddef>
#include <iterator>

namespace ft
{
    struct bidirectional_iterator_tag {};
    struct random_access_iterator_tag {};

    //base Class Template
    template <class Category, class T, class Distance = std::ptrdiff_t
	    , class Pointer = T*, class Reference = T&>
    struct iterator 
    {
        typedef T			value_type;
        typedef Distance	difference_type;
        typedef Pointer		pointer;
        typedef Reference	reference;
        typedef Category	iterator_category;
    };
    // Traits

    template <class Iterator>
    struct iterator_traits
    {
        typedef typename Iterator::value_type				value_type;
        typedef typename Iterator::difference_type			difference_type;
        typedef typename Iterator::pointer					pointer;
        typedef typename Iterator::reference				reference;
        typedef typename Iterator::iterator_category		iterator_category;
    };

    template <class T>
    struct iterator_traits<T*>
    {
        typedef T									value_type;
        typedef std::ptrdiff_t						difference_type;
        typedef T *									pointer;
        typedef T &									reference;
        typedef random_access_iterator_tag			iterator_category;
    };

    template <class T>
    struct iterator_traits<T const *>
    {
        typedef T									value_type;
        typedef std::ptrdiff_t						difference_type;
        typedef T const *							pointer;
        typedef T const &							reference;
        typedef random_access_iterator_tag			iterator_category;
    };

    //Reverse Iterator Class
    template <class Iterator>
    class reverse_iterator : public iterator
            <typename iterator_traits<Iterator>::iterator_category,
            typename iterator_traits<Iterator>::value_type,
            typename iterator_traits<Iterator>::difference_type,
            typename iterator_traits<Iterator>::pointer,
            typename iterator_traits<Iterator>::reference>
    {
        protected:
        Iterator							current;

        typedef iterator_traits<Iterator>	traits_type;

        public:
            // Member Typedefs
            typedef Iterator									iterator_type;
            typedef typename traits_type::difference_type		difference_type;
            typedef typename traits_type::pointer				pointer;
            typedef typename traits_type::reference             reference;

            // Canonic Class
            reverse_iterator() : current() {}
            explicit reverse_iterator (iterator_type x) : current(x) {}
            template <class It>
            reverse_iterator(reverse_iterator<It> const & x) : current(x.base()) {}
            reverse_iterator &	operator=(reverse_iterator const & x) {
                this->current = x.current;
                return (*this);
            }
            virtual ~reverse_iterator() {}

            // Member Functions

            iterator_type base() const { return this->current; }
            reference	operator*() const {
                Iterator	tmp = this->current;
                return *tmp;
            }
            pointer	operator->() const {
                Iterator	tmp = this->current;
                return (tmp);
            }
            reverse_iterator &	operator++() {
                --this->current;
                return *this;
            }
            reverse_iterator	operator++(int) {
                reverse_iterator	tmp = *this;
                --this->current;
                return (tmp);
            }
            reverse_iterator &	operator--() {
                ++this->current;
                return (*this);
            }
            reverse_iterator	operator--(int) {
                reverse_iterator	tmp = *this;
                ++this->current;
                return (tmp);
            }
            reverse_iterator	operator+(difference_type n) const {
                return (reverse_iterator(this->current - n));
            }
            reverse_iterator &	operator+=(difference_type n) {
                this->current -= n;
                return (*this);
            }
            reverse_iterator	operator-(difference_type n) const {
                return (reverse_iterator(this->current + n));
            }
            reverse_iterator &	operator-=(difference_type n) {
                this->current += n;
                return (*this);
            }
            reference	operator[](difference_type n) const {
                return *(*this - n);
            }
    };

    //Non Member Function Overload

    template <typename Iterator>
    inline bool		operator==(reverse_iterator<Iterator> const & x,
            reverse_iterator<Iterator> const & y) 
    {
        return x.base() == y.base();
    }

    template <typename Iterator>
    inline bool		operator!=(reverse_iterator<Iterator> const & x,
        reverse_iterator<Iterator> const & y)
        {
            return !(x == y);
        }

    template <typename Iterator>
    inline bool		operator<(reverse_iterator<Iterator> const & x,
        reverse_iterator<Iterator> const & y)
    {
        return y.base() < x.base();
    }

    template <typename Iterator>
    inline bool		operator>(reverse_iterator<Iterator> const & x
            , reverse_iterator<Iterator> const & y)
    {
        return y < x;
    }

    template <typename Iterator>
    inline bool		operator<=(reverse_iterator<Iterator> const & x,
        reverse_iterator<Iterator> const & y)
    {
        return !(y < x);
    }

    template <typename Iterator>
    inline bool		operator>=(reverse_iterator<Iterator> const & x,
        reverse_iterator<Iterator> const & y)
    {
        return !(x < y);
    }

    template <typename Iterator>
    inline typename	reverse_iterator<Iterator>::difference_type	operator-(
            reverse_iterator<Iterator> const & x, reverse_iterator<Iterator> const & y)
    {
        return y.base() - x.base();
    }

    template <typename Iterator>
    inline typename	reverse_iterator<Iterator>::difference_type	operator+(
            typename reverse_iterator<Iterator>::difference_type n,
                reverse_iterator<Iterator> const & x)
    {
        return reverse_iterator<Iterator>(x.base() - n);
    }
};