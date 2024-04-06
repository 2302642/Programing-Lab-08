/*!*********************************************************************************************************************************************************************************************************************
\file       array.cpp
\par        Author:          Najih
\par        Email:           n.hajasheikallaudin
\par        Course:          RSE1202
\par        Section:         RSE
\par        Tutorial:        Lab 8
\par        File created on: 15/03/2024
\brief      Singly Linked List Implementation using class

\par        File information:
            This file contains 
            - 3 begin iterator functions, 3 end iterator functions
            - 2 front reference functions, 2 back referance functions
            - 2 element accessor operators
            - 1 array empty checker, 2 data pointers and 1 sizr identifier function
            - 2 modifier functions
            - 5 non-member fuinctions 1 swap and 4 operator functions 
***********************************************************************************************************************************************************************************************************************/
#ifndef ARRAY_HPP_
#define ARRAY_HPP_

#include <cstddef>    // for size_t
#include <algorithm>  // for std::swap

namespace hlp2 {
//######################################################################################################################################################################################################################
    template<typename T, size_t N> class Array {                          // FUNCTIONS ARE DECLARATION IN CLASS 
        public:
            // Type aliases
            using size_type = std::size_t;
            using value_type = T;
            using reference = T&;
            using const_reference = const T&;
            using iterator = T*;
            using const_iterator = const T*;
            using pointer = T*;
            using const_pointer = const T*;
//======================================================================================================================================================================================================================
//|                                                                                    ITERATOR FUNCTIONS                                                                                                              |
//======================================================================================================================================================================================================================
            iterator begin() { return data(); }                                                         // returning the iterator to the star of the array
            const_iterator begin() const { return data(); }                                             // returning the iterator to the beginning of the array (const version)
            const_iterator cbegin() const { return data(); }                                            // returning the iterator to the beginning of the array (const version)
            iterator end() { return data() + N; }                                                       // returning the iterator to the end of the array
            const_iterator end() const { return data() + N; }                                           // returning the iterator to the end of the array (const version)
            const_iterator cend() const { return data() + N; }                                          // returning the iterator to the end of the array (const version)
//======================================================================================================================================================================================================================
//|                                                                                  REFERENCE FUNCTIONS                                                                                                               |
//======================================================================================================================================================================================================================
            reference front() { return data()[0]; }                                                     // returning the reference to the first element of the array
            const_reference front() const { return data()[0]; }                                         // returning the reference to the first element of the array (const version)
            reference back() { return data()[N - 1]; }                                                  // returning the reference to the last element of the array
            const_reference back() const { return data()[N - 1]; }                                      // returning the reference to the last element of the array (const version)
//======================================================================================================================================================================================================================
//|                                                                              ELEMENT ACCESSOR OPERATORS                                                                                                             |
//======================================================================================================================================================================================================================
            reference operator[](size_type index) { return data()[index]; }                             // returning the reference to the element at position index
            const_reference operator[](size_type index) const { return data()[index]; }                 // returning the reference to the element at position index (const version)
//======================================================================================================================================================================================================================
//|                                                                                 ARRAY STATUS FUNCTION                                                                                                             |
//======================================================================================================================================================================================================================
            bool empty() const { return size() == 0; }                                                  // checking if the array is empty
            pointer data() { return elements; }                                                         // returning pointer to the first element of the array
            const_pointer data() const { return elements; }                                             // returning pointer to the first element of the array (const version)
            size_type size() const { return N; }                                                        // returning the size of the array
//======================================================================================================================================================================================================================
//|                                                                                 MODIFIER FUNCTION                                                                                                             |
//======================================================================================================================================================================================================================
            void fill(const T& val){ for (auto& elm : elements) { elm = val; } }                        // to fill the array with the specified value
            void swap(Array& other) {                                                                   // to swap the contents of this array with another array
                for (size_t i = 0; i < N; ++i) { std::swap(elements[i], other.elements[i]); }           // swapping each elements at the same position in the arrays
            }
            T elements[N];                                                                              // array storage for storing elements
        };
//======================================================================================================================================================================================================================
//|                                                                                  NON-MEMBER FUNCTIONS                                                                                                              |
//======================================================================================================================================================================================================================
    template <typename T, size_t N> void swap (Array<T, N>& lhs, Array<T, N>& rhs);                     // swap function to swap contents of two arrays
    template <typename T, size_t N> bool operator==(const Array<T, N>& lhs, const Array<T, N>& rhs);    // equality comparison operator function
    template <typename T, size_t N> bool operator!=(const Array<T, N>& lhs, const Array<T, N>& rhs);    // inequality comparison operator function
    template <typename T, size_t N> bool operator<(const Array<T, N>& lhs, const Array<T, N>& rhs);     // less-than comparison operator function
    template <typename T, size_t N> bool operator>(const Array<T, N>& lhs, const Array<T, N>& rhs);     // greater-than comparison operator function
//######################################################################################################################################################################################################################
} // end namespace hlp2
#include "array.tpp" // EVERY member and non-member function must be defined in separate file array.tpp
#endif // end ARRAY_HPP_


/*
namespace hlp2 {
template<typename T, size_t N>                                                                          // Define class template Array<T,N> and document each member function
    class Array {
        public:
        // Type aliases
        using size_type = size_t;
        using value_type = T;
        using reference = T&;
        using const_reference = const T&;
        using iterator = T*;
        using const_iterator = const T*;
        using pointer = T*;
        using const_pointer = const T*;

//======================================================================================================================================================================================================================
//|                                                                                    ITERATOR FUNCTIONS                                                                                                              |
//======================================================================================================================================================================================================================
        iterator begin();                                                                               // Return const iterator to the beginning of the array
        const_iterator begin() const;                                                                   // Return const iterator to the beginning of the array (const version)
        const_iterator cbegin() const;                                                                  // Return const iterator to the beginning of the array (const version)
        iterator end();                                                                                 // returning the iterator to the end of the array
        const_iterator end() const;                                                                     // returning the iterator to the end of the array (const version)
        const_iterator cend() const;                                                                    // returning the iterator to the end of the array (const version)
//======================================================================================================================================================================================================================
//|                                                                                  REFERENCE FUNCTIONS                                                                                                               |
//======================================================================================================================================================================================================================
        reference front();                                                                              // returning the reference to the first element of the array 
        const_reference front() const;                                                                  // returning the reference to the first element of the array (const version)
        reference back();                                                                               // returning the reference to the last element of the array 
        const_reference back() const;                                                                   // returning the reference to the last element of the array (const version)
//======================================================================================================================================================================================================================
//|                                                                              ELEMENT ACCESSOR OPERATORS                                                                                                             |
//======================================================================================================================================================================================================================
        reference operator[](size_type index);                                                          // returning the size_type(int) data of node at position index in linked list
        const_reference operator[](size_type index) const;                                              // returning the size_type(int) data of node at position index in linked list (const version)
//======================================================================================================================================================================================================================
//|                                                                                 ARRAY STATUS FUNCTION                                                                                                             |
//======================================================================================================================================================================================================================
        bool empty() const;                                                                             // checking if the array is empty
        pointer data();                                                                                 // returning pointer to the first element of the array                                                                     
        const_pointer data() const;                                                                     // returning pointer to the first element of the array (const version)                                                                     
        size_type size() const;                                                                         // returning the size of the array                                                                         
        void fill(const T& value);                                                                      // to fill the array with the specified value
        void swap(Array& other);                                                                        // to swap the contents of this array with another array
        T elements[N];                                                                                  // array storage for storing elements
    };
//======================================================================================================================================================================================================================
//|                                                                                  NON-MEMBER FUNCTIONS                                                                                                              |
//======================================================================================================================================================================================================================
    template <typename T, size_t N> void swap (Array<T, N>& lhs, Array<T, N>& rhs);                     // swap function to swap contents of two arrays
    template <typename T, size_t N> bool operator==(const Array<T, N>& lhs, const Array<T, N>& rhs);    // equality comparison operator function
    template <typename T, size_t N> bool operator!=(const Array<T, N>& lhs, const Array<T, N>& rhs);    // inequality comparison operator function
    template <typename T, size_t N> bool operator<(const Array<T, N>& lhs, const Array<T, N>& rhs);     // less-than comparison operator function
    template <typename T, size_t N> bool operator>(const Array<T, N>& lhs, const Array<T, N>& rhs);     // greater-than comparison operator function
//######################################################################################################################################################################################################################
} // end namespace hlp2
#include "array.tpp"        // EVERY member and non-member function must be defined in separate file array.tpp
#endif // end ARRAY_HPP_
*/
