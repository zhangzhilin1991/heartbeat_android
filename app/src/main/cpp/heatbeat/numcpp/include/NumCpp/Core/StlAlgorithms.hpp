/// @file
/// @author David Pilger <dpilger26@gmail.com>
/// [GitHub Repository](https://github.com/dpilger26/NumCpp)
/// @version 1.2
///
/// @section License
/// Copyright 2019 David Pilger
///
/// Permission is hereby granted, free of charge, to any person obtaining a copy of this
/// software and associated documentation files(the "Software"), to deal in the Software
/// without restriction, including without limitation the rights to use, copy, modify,
/// merge, publish, distribute, sublicense, and/or sell copies of the Software, and to
/// permit persons to whom the Software is furnished to do so, subject to the following
/// conditions :
///
/// The above copyright notice and this permission notice shall be included in all copies
/// or substantial portions of the Software.
///
/// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
/// INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR
/// PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE
/// FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
/// OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
/// DEALINGS IN THE SOFTWARE.
///
/// @section Description
/// Macro to define whether or not c++17 parallel algorithm policies are supported
///
#pragma once

#include <algorithm>
#include <iterator>
#include <utility>

#if defined(__cpp_lib_execution) && defined(__cpp_lib_parallel_algorithm)
#define PARALLEL_ALGORITHMS_SUPPORTED
#include <execution>
#endif

namespace nc
{
    namespace stl_algorithms
    {
        //============================================================================
        // Method Description:
        ///						Tests if all of the elements of a range satisy a predicate
        ///
        /// @param first: the first iterator of the source
        /// @param last: the last iterator of the source
        /// @param p: unary predicate function
        /// @return bool
        /// 
        template<class InputIt, class UnaryPredicate>
        bool all_of(InputIt first, InputIt last, UnaryPredicate p)
        {
#ifdef PARALLEL_ALGORITHMS_SUPPORTED
            return std::all_of(std::execution::par_unseq, first, last, p);
#else
            return std::all_of(first, last, p);
#endif
        }

        //============================================================================
        // Method Description:
        ///						Tests if any of the elements of a range satisy a predicate
        ///
        /// @param first: the first iterator of the source
        /// @param last: the last iterator of the source
        /// @param p: unary predicate function
        /// @return bool
        /// 
        template<class InputIt, class UnaryPredicate>
        bool any_of(InputIt first, InputIt last, UnaryPredicate p)
        {
#ifdef PARALLEL_ALGORITHMS_SUPPORTED
            return std::any_of(std::execution::par_unseq, first, last, p);
#else
            return std::any_of(first, last, p);
#endif
        }

        //============================================================================
        // Method Description:
        ///						Copies from one container to another
        ///
        /// @param first: the first iterator of the source
        /// @param last: the last iterator of the source
        /// @param destination: the first iterator of the destination
        /// @return OutputIt
        ///
        template<class InputIt, class OutputIt>
        OutputIt copy(InputIt first, InputIt last, OutputIt destination)
        {
#ifdef PARALLEL_ALGORITHMS_SUPPORTED
            return std::copy(std::execution::par_unseq, first, last, destination);
#else
            return std::copy(first, last, destination);
#endif
        }

        //============================================================================
        // Method Description:
        ///						Counts the values in the range
        ///
        /// @param first: the first iterator of container
        /// @param last: the last iterator of container
        /// @param value: the initial value
        /// @return count
        ///
        template<class InputIt, class T>
        typename std::iterator_traits<InputIt>::difference_type
            count(InputIt first, InputIt last, const T &value)
        {
#ifdef PARALLEL_ALGORITHMS_SUPPORTED
            return std::count(std::execution::par_unseq, first, last, value);
#else
            return std::count(first, last, value);
#endif
        }

        //============================================================================
        // Method Description:
        ///						Test if two ranges are equal
        ///
        /// @param first1: the first iterator of first container
        /// @param last1: the last iterator of first container
        /// @param first2: the first iterator of second container
        /// @return bool
        ///
        template<class InputIt1, class InputIt2>
        bool equal(InputIt1 first1, InputIt1 last1,
            InputIt2 first2)
        {
#ifdef PARALLEL_ALGORITHMS_SUPPORTED
            return std::equal(std::execution::par_unseq, first1, last1, first2);
#else
            return std::equal(first1, last1, first2);
#endif
        }

        //============================================================================
        // Method Description:
        ///						Test if two ranges are equal
        ///
        /// @param first1: the first iterator of first container
        /// @param last1: the last iterator of first container
        /// @param first2: the first iterator of second container
        /// @param p: binary predicate to compare the elements
        /// @return bool
        ///
        template<class InputIt1, class InputIt2, class BinaryPredicate>
        bool equal(InputIt1 first1, InputIt1 last1,
            InputIt2 first2, BinaryPredicate p)
        {
#ifdef PARALLEL_ALGORITHMS_SUPPORTED
            return std::equal(std::execution::par_unseq, first1, last1, first2, p);
#else
            return std::equal(first1, last1, first2, p);
#endif
        }

        //============================================================================
        // Method Description:
        ///						Fills the range with the value
        ///
        /// @param first: the first iterator of the source
        /// @param last: the last iterator of the source
        /// @param value: the function to apply to the input iterators
        ///
        template<class ForwardIt, class T>
        void fill(ForwardIt first, ForwardIt last, const T& value)
        {
#ifdef PARALLEL_ALGORITHMS_SUPPORTED
            return std::fill(std::execution::par_unseq, first, last, value);
#else
            return std::fill(first, last, value);
#endif
        }

        //============================================================================
        // Method Description:
        ///						Returns the first element in the range [first, last) 
        ///                     that satisfies specific criteria:
        ///
        /// @param first: the first iterator of the source
        /// @param last: the last iterator of the source
        /// @param value: the value to find
        /// @return InputIt
        ///
        template<class InputIt, class T>
        InputIt find(InputIt first, InputIt last, const T& value)
        {
#ifdef PARALLEL_ALGORITHMS_SUPPORTED
            return std::find(std::execution::par_unseq, first, last, value);
#else
            return std::find(first, last, value);
#endif
        }

        //============================================================================
        // Method Description:
        ///						Runs the function on each element of the range
        ///
        /// @param first: the first iterator of the source
        /// @param last: the last iterator of the source
        /// @param f: the function to apply to the input iterators
        ///
        template<class InputIt, class UnaryFunction>
        void for_each(InputIt first, InputIt last, UnaryFunction f)
        {
#ifdef PARALLEL_ALGORITHMS_SUPPORTED
            std::for_each(std::execution::par_unseq, first, last, f);
#else
            std::for_each(first, last, f);
#endif
        }

        //============================================================================
        // Method Description:
        ///						Returns true if the array is sorted
        ///
        /// @param first: the first iterator of the source
        /// @param last: the last iterator of the source
        /// @return bool true if sorted
        ///
        template<class ForwardIt>
        bool is_sorted(ForwardIt first, ForwardIt last)
        {
#ifdef PARALLEL_ALGORITHMS_SUPPORTED
            return std::is_sorted(std::execution::par_unseq, first, last);
#else
            return std::is_sorted(first, last);
#endif
        }

        //============================================================================
        // Method Description:
        ///						Runs the maximum element of the range
        ///
        /// @param first: the first iterator of the source
        /// @param last: the last iterator of the source
        /// @return ForwordIt
        ///
        template<class ForwardIt>
        ForwardIt max_element(ForwardIt first, ForwardIt last)
        {
#ifdef PARALLEL_ALGORITHMS_SUPPORTED
            return std::max_element(std::execution::par_unseq, first, last);
#else
            return std::max_element(first, last);
#endif
        }

        //============================================================================
        // Method Description:
        ///						Runs the minimum element of the range
        ///
        /// @param first: the first iterator of the source
        /// @param last: the last iterator of the source
        /// @return ForwardIt
        template<class ForwardIt>
        ForwardIt min_element(ForwardIt first, ForwardIt last)
        {
#ifdef PARALLEL_ALGORITHMS_SUPPORTED
            return std::min_element(std::execution::par_unseq, first, last);
#else
            return std::min_element(first, last);
#endif
        }

        //============================================================================
        // Method Description:
        ///						Runs the minimum and maximum elements of the range
        ///
        /// @param first: the first iterator of the source
        /// @param last: the last iterator of the source
        /// @return std::pair
        ///
        template<class ForwardIt>
        std::pair<ForwardIt, ForwardIt>
            minmax_element(ForwardIt first, ForwardIt last)
        {
#ifdef PARALLEL_ALGORITHMS_SUPPORTED
            return std::minmax_element(std::execution::par_unseq, first, last);
#else
            return std::minmax_element(first, last);
#endif
        }

        //============================================================================
        // Method Description:
        ///						Tests if none of the elements of a range satisy a predicate
        ///
        /// @param first: the first iterator of the source
        /// @param last: the last iterator of the source
        /// @param p: unary predicate function
        /// @return bool
        /// 
        template<class InputIt, class UnaryPredicate>
        bool none_of(InputIt first, InputIt last, UnaryPredicate p)
        {
#ifdef PARALLEL_ALGORITHMS_SUPPORTED
            return std::none_of(std::execution::par_unseq, first, last, p);
#else
            return std::none_of(first, last, p);
#endif
        }

        //============================================================================
        // Method Description:
        ///						Sorts up to the nth element
        ///
        /// @param first: the first iterator of the range
        /// @param nth: the element that should be sorted
        /// @param last: the last iterator of the range
        ///
        template<class RandomIt>
        void nth_element(RandomIt first, RandomIt nth, RandomIt last)
        {
#ifdef PARALLEL_ALGORITHMS_SUPPORTED
            std::nth_element(std::execution::par_unseq, first, nth, last);
#else
            std::nth_element(first, nth, last);
#endif
        }

        //============================================================================
        // Method Description:
        ///						replaces a value in the range with another value
        ///
        /// @param first: the first iterator of the source
        /// @param last: the last iterator of the source
        /// @param oldValue: the value to replace
        /// @param newValue: the replacement value
        ///
        template<class ForwardIt, class T>
        void replace(ForwardIt first, ForwardIt last,
            const T& oldValue, const T& newValue)
        {
#ifdef PARALLEL_ALGORITHMS_SUPPORTED
            std::replace(std::execution::par_unseq, first, last, oldValue, newValue);
#else
            std::replace(first, last, oldValue, newValue);
#endif
        }

        //============================================================================
        // Method Description:
        ///						reverses the range
        ///
        /// @param first: the first iterator of the source
        /// @param last: the last iterator of the source
        ///
        template<class BidirIt>
        void reverse(BidirIt first, BidirIt last)
        {
#ifdef PARALLEL_ALGORITHMS_SUPPORTED
            std::reverse(std::execution::par_unseq, first, last);
#else
            std::reverse(first, last);
#endif
        }

        //============================================================================
        // Method Description:
        ///						Rotates the elements of a range
        ///
        /// @param first: the first iterator of the range
        /// @param firstN: the element that should appear at the beginning of the rotated range
        /// @param last: the last iterator of the range
        ///
        template<class ForwardIt>
        void rotate(ForwardIt first, ForwardIt firstN, ForwardIt last)
        {
#ifdef PARALLEL_ALGORITHMS_SUPPORTED
            std::rotate(std::execution::par_unseq, first, firstN, last);
#else
            std::rotate(first, firstN, last);
#endif
        }

        //============================================================================
        // Method Description:
        ///						finds the difference of two ranges
        ///
        /// @param first1: the first iterator of the source
        /// @param last1: the last iterator of the source
        /// @param first2: the first iterator of the second source
        /// @param last2: the first iterator of the destination
        /// @param destination: the function to apply to the input iterators
        /// @return OutputIt
        ///
        template<class InputIt1, class InputIt2, class OutputIt>
        OutputIt set_difference(InputIt1 first1, InputIt1 last1,
            InputIt2 first2, InputIt2 last2,
            OutputIt destination)
        {
#ifdef PARALLEL_ALGORITHMS_SUPPORTED
            return std::set_difference(std::execution::par_unseq,
                first1, last1, first2, last2, destination);
#else
            return std::set_difference(first1, last1, first2, last2, destination);
#endif
        }

        //============================================================================
        // Method Description:
        ///						finds the intersection of two ranges
        ///
        /// @param first1: the first iterator of the source
        /// @param last1: the last iterator of the source
        /// @param first2: the first iterator of the second source
        /// @param last2: the first iterator of the destination
        /// @param destination: the function to apply to the input iterators
        /// @return OutputIt
        ///
        template<class InputIt1, class InputIt2, class OutputIt>
        OutputIt set_intersection(InputIt1 first1, InputIt1 last1,
            InputIt2 first2, InputIt2 last2,
            OutputIt destination)
        {
#ifdef PARALLEL_ALGORITHMS_SUPPORTED
            return std::set_intersection(std::execution::par_unseq,
                first1, last1, first2, last2, destination);
#else
            return std::set_intersection(first1, last1, first2, last2, destination);
#endif
        }

        //============================================================================
        // Method Description:
        ///						finds the union of two ranges
        ///
        /// @param first1: the first iterator of the source
        /// @param last1: the last iterator of the source
        /// @param first2: the first iterator of the second source
        /// @param last2: the first iterator of the destination
        /// @param destination: the function to apply to the input iterators
        /// @return OutputIt
        ///
        template<class InputIt1, class InputIt2, class OutputIt>
        OutputIt set_union(InputIt1 first1, InputIt1 last1,
            InputIt2 first2, InputIt2 last2,
            OutputIt destination)
        {
#ifdef PARALLEL_ALGORITHMS_SUPPORTED
            return std::set_union(std::execution::par_unseq,
                first1, last1, first2, last2, destination);
#else
            return std::set_union(first1, last1, first2, last2, destination);
#endif
        }

        //============================================================================
        // Method Description:
        ///						Sorts the range
        ///
        /// @param first: the first iterator of the source
        /// @param last: the last iterator of the source
        ///
        template<class RandomIt>
        void sort(RandomIt first, RandomIt last)
        {
#ifdef PARALLEL_ALGORITHMS_SUPPORTED
            return std::sort(std::execution::par_unseq, first, last);
#else
            return std::sort(first, last);
#endif
        }

        //============================================================================
        // Method Description:
        ///						Sorts the range preserving order
        ///
        /// @param first: the first iterator of the source
        /// @param last: the last iterator of the source
        /// @param comp: the comparitor function
        ///
        template<class RandomIt, class Compare>
        void stable_sort(RandomIt first, RandomIt last, Compare comp)
        {
#ifdef PARALLEL_ALGORITHMS_SUPPORTED
            std::stable_sort(std::execution::par_unseq, first, last, comp);
#else
            std::stable_sort(first, last, comp);
#endif
        }

        //============================================================================
        // Method Description:
        ///						Transforms the elements of the range
        ///
        /// @param first: the first iterator of the source
        /// @param last: the last iterator of the source
        /// @param destination: the first iterator of the destination
        /// @param unaryFunction: the function to apply to the input iterators
        /// @return OutputIt
        ///
        template<class InputIt, class OutputIt, class UnaryOperation>
        OutputIt transform(InputIt first, InputIt last, OutputIt destination,
            UnaryOperation unaryFunction)
        {
#ifdef PARALLEL_ALGORITHMS_SUPPORTED
            return std::transform(std::execution::par_unseq, first, last, destination, unaryFunction);
#else
            return std::transform(first, last, destination, unaryFunction);
#endif
        }

        //============================================================================
        // Method Description:
        ///						Transforms the elements of the range
        ///
        /// @param first1: the first iterator of the source
        /// @param last1: the last iterator of the source
        /// @param first2: the first iterator of the second source
        /// @param destination: the first iterator of the destination
        /// @param unaryFunction: the function to apply to the input iterators
        /// @return OutputIt
        ///
        template<class InputIt1, class InputIt2, class OutputIt, class BinaryOperation>
        OutputIt  transform(InputIt1 first1, InputIt1 last1, InputIt2 first2,
            OutputIt destination, BinaryOperation unaryFunction)
        {
#ifdef PARALLEL_ALGORITHMS_SUPPORTED
            return std::transform(std::execution::par_unseq,
                first1, last1, first2, destination, unaryFunction);
#else
            return std::transform(first1, last1, first2, destination, unaryFunction);
#endif
        }
    }
}
