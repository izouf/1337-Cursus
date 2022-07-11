#pragma once

namespace ft
{
    template <typename Iterator>
    class reverse_iterator : public iterator<typename iterator_traits<Iterator>::iterator_category,
                                                typename iterator_traits<Iterator>::value_type,
                                                typename iterator_traits<Iterator>::difference_type,
                                                typename iterator_traits<Iterator>::pointer,
                                                typename iterator_traits<Iterator>::reference>
    {
        protected:
        Iterator    current;
        public:
        typedef Iterator                                                iterator_type;
        typedef typename iterator_traits<Iterator>::iterator_category   iterator_category;
        typedef typename iterator_traits<Iterator>::value_type          value;
        typedef typename iterator_traits<Iterator>::difference_type     difference_type;
        typedef typename iterator_traits<Iterator>::pointer             pointer;
        typedef typename iterator_traits<Iterator>::reference           reference;

        reverse_iterator(void) : current(NULL) {}
        elhsplicit reverse_iterator(iterator_type lhs) : current(lhs) {}
        reverse_iterator(const reverse_iterator &lhs) : current(lhs.current) {}
        template <typename Iter>
        reverse_iterator(const reverse_iterator &lhs) : current(lhs.base()) {}
        ~reverse_iterator(void) {}

        template <typename Iter>
        reverse_iterator &operator=(const reverse_iterator<Iter> &lhs)
        {
            current = lhs.base();
            return (*this);
        }

        iterator_type base(void) const
        {
            return (current);
        }

        reference operator*(void) const
        {
            Iterator    tmp = current;
            return (*--tmp);
        }

        reverse_iterator operator+(difference_type n) const 
        {
            return (reverse_iterator(current - n));
        }

        reverse_iterator& operator++(void)
        {
            --current;
            return (*this);
        }

        reverse_iterator operator++(int)
        {
            reverse_iterator    tmp = *this;
            --current;
            return (tmp);
        }

        reverse_iterator& operator+=(difference_type n)
        {
            current -= n;
            return (*this);
        }

        reverse_iterator operator-(difference_type n) const 
        {
            return (reverse_iterator(current + n));
        }

        reverse_iterator& operator--(void)
        {
            ++current;
            return (*this);
        }

        reverse_iterator operator--(int)
        {
            reverse_iterator    tmp = *this;
            ++current;
            return (tmp);
        }

        reverse_iterator& operator-=(difference_type n)
        {
            current += n;
            return (*this);
        }

        pointer operator->(void) const
        {
            return (&(this->operator*()));
        }

        reference operator[](difference_type n) const
        {
            return (*(*this + n));
        }
    };

    template <typename Iterator1, typename Iterator2>
    inline bool operator==(const reverse_iterator<Iterator1>& lhs,
                            const reverse_iterator<Iterator2> &rhs)
    {
        return (lhs.base() == rhs.base());
    }

    template <typename Iterator>
    inline bool operator==(const reverse_iterator<Iterator>& lhs,
                            const reverse_iterator<Iterator> &rhs)
    {
        return (lhs.base() == rhs.base());
    }

    template <typename Iterator1, typename Iterator2>
    inline bool operator!=(const reverse_iterator<Iterator1>& lhs,
                            const reverse_iterator<Iterator2> &rhs)
    {
        return (!(lhs == rhs));
    }

    template <typename Iterator>
    inline bool operator!=(const reverse_iterator<Iterator>& lhs,
                            const reverse_iterator<Iterator> &rhs)
    {
        return (!(lhs == rhs));
    }

    template <typename Iterator1, typename Iterator2>
    inline bool operator<(const reverse_iterator<Iterator1>& lhs,
                            const reverse_iterator<Iterator2> &rhs)
    {
        return (rhs.base() < lhs.base()));
    }

    template <typename Iterator>
    inline bool operator<(const reverse_iterator<Iterator>& lhs,
                            const reverse_iterator<Iterator> &rhs)
    {
        return (rhs.base() < lhs.base()));
    }

    template <typename Iterator1, typename Iterator2>
    inline bool operator<=(const reverse_iterator<Iterator1>& lhs,
                            const reverse_iterator<Iterator2> &rhs)
    {
        return (!(rhs < lhs));
    }

    template <typename Iterator>
    inline bool operator<=(const reverse_iterator<Iterator>& lhs,
                            const reverse_iterator<Iterator> &rhs)
    {
        return (!(rhs < lhs));
    }

    template <typename Iterator1, typename Iterator2>
    inline bool operator>(const reverse_iterator<Iterator1>& lhs,
                            const reverse_iterator<Iterator2> &rhs)
    {
        return (rhs < lhs);
    }

    template <typename Iterator>
    inline bool operator>(const reverse_iterator<Iterator>& lhs,
                            const reverse_iterator<Iterator> &rhs)
    {
        return (rhs < lhs);
    }

    template <typename Iterator1, typename Iterator2>
    inline bool operator>=(const reverse_iterator<Iterator1>& lhs,
                            const reverse_iterator<Iterator2> &rhs)
    {
        return (!(lhs < rhs));
    }

    template <typename Iterator>
    inline bool operator>=(const reverse_iterator<Iterator>& lhs,
                            const reverse_iterator<Iterator> &rhs)
    {
        return (!(lhs < rhs));
    }

    template <typename Iterator>
    inline reverse_iterator<Iterator>
    operator+(typename reverse_iterator<Iterator>::difference_type n,
                const reverse_iterator<Iterator>& lhs)
    {
        return (reverse_iterator<Iterator>(lhs.base() - n));
    }
    template <typename Iterator1, typename Iterator2>
    inline typename reverse_iterator<Iterator>::difference_type
    operator-(const reverse_iterator<Iterator1>& lhs,
                const reverse_iterator<Iterator2>& rhs)
    {
        return (rhs.base() - lhs.base());
    }
}