#pragma once

#include "iterator_traits.hpp"
// using std::iterator (gnu reference)
#include <iostream>

namespace ft
{
    template<typename Iterator>
    class random_access_iterator 
    {
        protected:
            Iterator    _iter; // 실제 반복자를 저장할 멤버 변수
            typedef iterator_traits<Iterator>   _traits_type;

        public:
            typedef Iterator    iterator_type;
            // 반복자 타입 정의. iterator_traits.hpp의 iterator_traits 구조체가 사용됨
            typedef typename _traits_type::iterator_category   iterator_category;
            typedef typename _traits_type::value_type          value_type;
            typedef typename _traits_type::difference_type     difference_type;
            typedef typename _traits_type::pointer             pointer;
            typedef typename _traits_type::reference           reference;    

            // 생성자와 소멸자
            // 기본 생성자
            random_access_iterator() : _iter() {}
            // 주의점: iterator를 NULL로 생성하지 않는다.
            // iterator don't have a Null State. null or nil.
            // iterator가 end를 가리키는 것이 반드시 Null과 동치되는 것은 아님
            // 이때, iter는 Iterator 타입의 기본 생성자로 초기화된다. 
            // 기본 타입, 혹은 사용자 정의 클래스
            
            // 단일 인자 생성자
            explicit
            random_access_iterator(const Iterator& ref) : _iter(ref) {}
            
            // Iterator로 const Iterator를 초기화할 수 있도록 한다. (gnu reference)
            template<typename Iter>
            random_access_iterator(const random_access_iterator<Iter> &ref) : _iter(ref.base()) {}

            // 현재 위치인 기점 반복자(base iterator) 반환, 모든 유형의 반복자에서 사용
            const Iterator& 
            base() const
            { return _iter; }
            
            // --- 순방향 반복자 필요 기능 ---   //
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
            operator++(int) 
            { 
                random_access_iterator  tmp = *this;
                ++_iter;
                return tmp; 
            }

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
            operator--(int) 
            { 
                random_access_iterator  tmp = *this;
                --_iter;
                return tmp; 
            }
    
            // --- 임의 접근 반복자 필요 기능 --- //
            reference
            operator[] (difference_type _n) const
            { return _iter[_n]; }

            random_access_iterator&
            operator+=(const difference_type& _n)
            {
                _iter += _n;
                return *this;
            }

            random_access_iterator
            operator+(const difference_type& _n) const
            {  return (random_access_iterator(_iter + _n)); }

            random_access_iterator&
            operator-=(const difference_type& _n)
            {
                _iter -= _n;
                return *this;
            }

            random_access_iterator
            operator-(const difference_type& _n) const 
            { return (random_access_iterator(_iter - _n)); }
    };
    
    // -- 순방향 반복자 필요 기능 --//
    template<typename _IteratorL, typename _IteratorR>
    inline bool 
    operator==(const random_access_iterator<_IteratorL>& _lhs, 
    const random_access_iterator<_IteratorR>& _rhs)
    { return _lhs.base() == _rhs.base(); }

    template<typename _Iterator>
    inline bool
    operator==(const random_access_iterator<_Iterator>&_lhs, 
    const random_access_iterator<_Iterator>& _rhs)
    { return _lhs.base() == _rhs.base(); }

    template<typename _IteratorL, typename _IteratorR>
    inline bool 
    operator!=(const random_access_iterator<_IteratorL>& _lhs, 
    const random_access_iterator<_IteratorR>& _rhs)
    { return _lhs.base() != _rhs.base(); }

    template<typename _Iterator>
    inline bool
    operator!=(const random_access_iterator<_Iterator>& _lhs, 
    const random_access_iterator<_Iterator>& _rhs)
    { return _lhs.base() != _rhs.base(); }

    // -- 임의 접근 반복자 필요 기능 --//
    template<typename _IteratorL, typename _IteratorR>
    inline bool
    operator<(const random_access_iterator<_IteratorL>& _lhs, 
    const random_access_iterator<_IteratorR>& _rhs)
    { return _lhs.base() < _rhs.base(); } 

    template<typename _Iterator>
    inline bool
    operator<(const random_access_iterator<_Iterator>& _lhs, 
    const random_access_iterator<_Iterator>& _rhs)
    { return _lhs.base() < _rhs.base(); }

    template<typename _IteratorL, typename _IteratorR>
    inline bool
    operator>(const random_access_iterator<_IteratorL>& _lhs, 
    const random_access_iterator<_IteratorR>& _rhs)
    { return _lhs.base() < _rhs.base(); }

    template<typename _Iterator>
    inline bool
    operator>(const random_access_iterator<_Iterator>& _lhs, 
    const random_access_iterator<_Iterator>& _rhs)
    { return _lhs.base() < _rhs.base(); }

    template<typename _IteratorL, typename _IteratorR>
    inline bool
    operator<=(const random_access_iterator<_IteratorL>& _lhs, 
    const random_access_iterator<_IteratorR>& _rhs)
    { return _lhs.base() <= _rhs.base(); }

    template<typename _Iterator>
    inline bool
    operator<=(const random_access_iterator<_Iterator>& _lhs, 
    const random_access_iterator<_Iterator>& _rhs)
    { return _lhs.base() <= _rhs.base(); }

    template<typename _IteratorL, typename _IteratorR>
    inline bool
    operator>=(const random_access_iterator<_IteratorL>& _lhs, 
    const random_access_iterator<_IteratorR>& _rhs)
    { return _lhs.base() >= _rhs.base(); }

    template<typename _Iterator>
    inline bool
    operator>=(const random_access_iterator<_Iterator>& _lhs, 
    const random_access_iterator<_Iterator>& _rhs)
    { return _lhs.base() >= _rhs.base(); }

    // 마찬가지로 iterator와 const iterator 간의 연산도 지원해야 한다.
    template<typename _IteratorL, typename _IteratorR>
    inline typename random_access_iterator<_IteratorL>::difference_type
    operator-(const random_access_iterator<_IteratorL>& _lhs, 
    const random_access_iterator<_IteratorR>& _rhs) 
    { return _lhs.base() - _rhs.base(); }

    template<typename _Iterator>
    inline typename random_access_iterator<_Iterator>::difference_type
    operator-(const random_access_iterator<_Iterator>& _lhs, 
    const random_access_iterator<_Iterator>& _rhs)
    { return _lhs.base() - _rhs.base(); }

    // iterantor + n의 형태 뿐만 아니라, n + iterator 형태의 연산도 지원
    template<typename _Iterator>
    inline random_access_iterator<_Iterator> 
    operator+(typename random_access_iterator<_Iterator>::difference_type _n,
    const random_access_iterator<_Iterator>& _i)
    { return random_access_iterator<_Iterator>(_i.base() + _n); }
}
