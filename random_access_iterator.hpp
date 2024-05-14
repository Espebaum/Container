#pragma once

#include "iterator_traits.hpp"

namespace ft
{
    template<typename Iterator>
    class random_access_iterator 
    {
        protected:
            Iterator    _iter; // 실제 반복자를 저장할 멤버 변수

        public:
            // 반복자 타입 정의
            typedef typename iterator_traits<Iterator>::iterator_category   iterator_category;
            typedef typename iterator_traits<Iterator>::value_type          value_type;
            typedef typename iterator_traits<Iterator>::difference_type     difference_type;
            typedef typename iterator_traits<Iterator>::pointer             pointer;
            typedef typename iterator_traits<Iterator>::reference           reference;    

            // 생성자와 소멸자
            random_access_iterator(Iterator iter) : _iter(iter) {}
           
            explicit
            random_access_iterator(const  &ref) : _iter(ref._iter) {}
            
            // Iterator로 const Iterator를 초기화할 수 있도록 한다. (gnu reference)
            template<typename Iter>
            random_access_iterator(const random_access_iterator<Iter> &ref) : _iter(ref.base()) {}

            // 현재 위치인 기점 반복자(base iterator) 반환, 모든 유형의 반복자에서 사용
            const Iterator& 
            base() { return _iter; }
            
            // --- 순방향 반복자 필요 기능 --- //
            reference
            operator*() const { return *_iter; }
            
            pointer
            operator->() const { return _iter; }
            
            // 전위 증가 연산
            random_access_iterator&
            operator++() 
            { 
                ++_iter; 
                return *this;
            }

            // 후위 증가 연산
            random_access_iterator 
            operator++(int) { return (random_access_iterator(_iter++)); }

            // --- 양방향 반복자 필요 기능 --- //
            // 전위 감소 연산
            random_access_iterator&
            operator--()
            {
                --_iter;
                return *this;
            }
    
            // 후위 감소 연산
            random_access_iterator
            operator--(int) { return (random_access_iterator(_iter--)); }
    
            // --- 임의 접근 반복자 필요 기능 --- //
            reference
            operator[] (difference_type _n) const
            { return _iter[_n]; }

            random_access_iterator&
            operator+=(difference_type _n)
            {
                _iter += _n;
                return *this;
            }

            random_access_iterator
            operator+(difference_type _n) 
            const { return (random_access_iterator(_iter + _n)); }

            random_access_iterator&
            operator-=(difference_type _n)
            {
                _iter -= _n;
                return *this;
            }

            random_access_iterator
            operator-(difference_type _n)
            const { return (random_access_iterator(_iter - _n)); }

            // -- 순방향 반복자 필요 기능 --//
            template<typename _IteratorL, typename _IteratorR>
            inline bool
            operator==(const random_access_iterator<IteratorL>& _lhs,
                    const random_access_iterator<IteratorR>& _rhs)
            { return _lhs.base() == _rhs.base(); }

            template<typename _IteratorL, typename _IteratorR>
            inline bool
            operator!=(const random_access_iterator<IteratorL>& _lhs,
                    const random_access_iterator<IteratorR>& _rhs)
            { return _lhs.base() != _rhs.base(); }

    };
}