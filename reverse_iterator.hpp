#pragma once

#include "iterator_traits.hpp"

namespace ft 
{
    template<typename Iterator>
    class reverse_iterator
    {
        protected:
            Iterator    current;
    }
}