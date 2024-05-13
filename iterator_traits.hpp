#pragma once

#include <memory>
#include <cstddef>

namespace ft
{
    // struct input_iterator_tag {};
    // struct output_iterator_tag {};
    // struct forward_iterator_tag : public input_iterator_tag {};
    // struct bidirectional_iterator_tag : public forward_iterator_tag {};
    // struct random_access_iterator_tag : public bidirectional_iterator_tag {};

    template<typename Category, typename T, typename Distance = ptrdiff_t, typename Pointer = T*, typename Reference = T&>
    struct iterator 
    {
        typedef Category    iterator_category;
        typedef T           value_type;
        typedef Distance    difference_type;
        typedef Pointer     pointer;
        typedef Reference   reference;
    };  // 내부적인 구조, 사용자가 정의하는 iterator는 위의 요소들을 포함하고 있다.
        // 이 과정에서 iterator_traits가 이용된다.

    // iterator_traits의 구현부
    // 일반 iterator의 경우 아래 템플릿을 통해 생성
    template<typename Iterator>
    struct iterator_traits
    {
        typedef typename Iterator::iterator_category    iterator_category;
        typedef typename Iterator::value                value_type;
        typedef typename Iterator::difference_type      difference_type;
        typedef typename Iterator::pointer              pointer;
        typedef typename Iterator::reference            reference; 
    };
    // 포인터 형태로 iterator가 사용될 경우 아래 템플릿 활용
    template<typename T>
    struct iterator_traits<T*>
    {
        typedef random_access_iterator_tag  iterator_category;
        typedef T                           value_type;
        typedef ptrdiff_t                   difference_type;       
        typedef T*                          pointer;
        typedef T&                          reference;
    };
    template<typename T>
    struct iterator_traits<const T*>
    {
        typedef random_access_iterator_tag  iterator_category;
        typedef T                           value_type;
        typedef ptrdiff_t                   difference_type;       
        typedef const T*                    pointer;
        typedef const T&                    reference;
    };
}