#pragma once

#include "iterator_traits.hpp"

namespace ft
{
    template<typename Iterator>
    class random_access_iterator 
    {

        private:
            Iterator    _iter; // 실제 반복자를 저장할 멤버 변수

        public:
            // 반복자 타입 정의
            typedef typename iterator_traits<Iterator>::iterator_category   iterator_category;
            typedef typename iterator_traits<Iterator>::value_type          value_type;
            typedef typename iterator_traits<Iterator>::difference_type     difference_type;
            typedef typename iterator_traits<Iterator>::pointer             pointer;
            typedef typename iterator_traits<Iterator>::reference           reference;    

            // 생성자와 소멸자
            random_access_iterator() : _iter(NULL) {}
            random_access_iterator(Iterator iter) : _iter(iter) {}
            random_access_iterator(const random_access_iterator &ref) : _iter(ref._iter) {}
            template

    };
}