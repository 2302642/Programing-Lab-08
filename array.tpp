/*!*********************************************************************************************************************************************************************************************************************
\file       array.tpp
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
#ifndef ARRAY_TPP_
#define ARRAY_TPP_

namespace hlp2 {
//###################################################################################################################################################################################################################################################################################
template <typename T, size_t N> 
void swap(Array<T, N>& lhs, Array<T, N>& rhs) { lhs.swap(rhs); }                                                                                            // non-member swap function to swap contents of two arrays
template <typename T, size_t N> 
bool operator==(const Array<T, N>& lhs, const Array<T, N>& rhs) { return std::equal(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()); }                      // non-member equality comparison operator function
template <typename T, size_t N> 
bool operator!=(const Array<T, N>& lhs, const Array<T, N>& rhs) {  return !(lhs == rhs); }                                                                  // non-member inequality comparison operator function
template <typename T, size_t N> 
bool operator<(const Array<T, N>& lhs, const Array<T, N>& rhs) { return std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()); }     // non-member lesser-than comparison operator function
template <typename T, size_t N> 
bool operator>(const Array<T, N>& lhs, const Array<T, N>& rhs) { return rhs < lhs; }                                                                        // non-member greater-than comparison operator function
//###################################################################################################################################################################################################################################################################################
} // end namespace hlp2
#endif // ARRAY_TPP_

/*
namespace hlp2 {
    //###############################################################################################################################################################################################################################################################################
//===================================================================================================================================================================================================================================================================================
//|                                                                                    ITERATOR FUNCTIONS                                                                                                                                                                           |
//===================================================================================================================================================================================================================================================================================
    template <typename T, size_t N> typename Array<T, N>::iterator Array<T, N>::begin() { return data(); }                                                                                      // returning the iterator to the star of the array
    template <typename T, size_t N> typename Array<T, N>::const_iterator Array<T, N>::begin() const { return data(); }                                                                          // returning the iterator to the beginning of the array (const version)
    template <typename T, size_t N> typename Array<T, N>::const_iterator Array<T, N>::cbegin() const { return data(); }                                                                         // returning the iterator to the beginning of the array (const version)
//===================================================================================================================================================================================================================================================================================
//|                                                                                  REFERENCE FUNCTIONS                                                                                                                                                                            |
//===================================================================================================================================================================================================================================================================================
    template <typename T, size_t N> typename Array<T, N>::iterator Array<T, N>::end()   { return data() + N; }                                                                                  // returning the iterator to the end of the array
    template <typename T, size_t N> typename Array<T, N>::const_iterator Array<T, N>::end() const { return data() + N; }                                                                        // returning the iterator to the end of the array (const version)
    template <typename T, size_t N> typename Array<T, N>::const_iterator Array<T, N>::cend() const { return data() + N; }                                                                       // returning the iterator to the end of the array (const version)
//===================================================================================================================================================================================================================================================================================
//|                                                                                  REFERENCE FUNCTIONS                                                                                                                                                                            |
//===================================================================================================================================================================================================================================================================================
    template <typename T, size_t N> typename Array<T, N>::reference Array<T, N>::front() { return data()[0]; }                                                                                  // returning the reference to the first element of the array
    template <typename T, size_t N> typename Array<T, N>::const_reference Array<T, N>::front() const { return data()[0]; }                                                                      // returning the reference to the first element of the array (const version)
    template <typename T, size_t N> typename Array<T, N>::reference Array<T, N>::back() { return data()[N - 1]; }                                                                               // returning the reference to the last element of the array
    template <typename T, size_t N> typename Array<T, N>::const_reference Array<T, N>::back() const { return data()[N - 1]; }                                                                   // returning the reference to the last element of the array (const version)
//===================================================================================================================================================================================================================================================================================
//|                                                                              ELEMENT ACCESSOR OPERATORS                                                                                                                                                                         |
//===================================================================================================================================================================================================================================================================================
    template <typename T, size_t N> typename Array<T, N>::reference Array<T, N>::operator[](size_type index) { return data()[index]; }                                                          // returning the reference to the element at position index
    template <typename T, size_t N> typename Array<T, N>::const_reference Array<T, N>::operator[](size_type index) const { return data()[index]; }                                              // returning the reference to the element at position index (const version)
//===================================================================================================================================================================================================================================================================================
//|                                                                                 ARRAY STATUS FUNCTION                                                                                                                                                                           |
//===================================================================================================================================================================================================================================================================================
    template <typename T, size_t N> bool Array<T, N>::empty() const {  return size() == 0; }                                                                                                    // checking if the array is empty
    template <typename T, size_t N> typename Array<T, N>::pointer Array<T, N>::data() { return &elements[0]; }                                                                                  // returning pointer to the first element of the array
    template <typename T, size_t N> typename Array<T, N>::const_pointer Array<T, N>::data() const { return &elements[0]; }                                                                      // returning pointer to the first element of the array (const version)
    template <typename T, size_t N> typename Array<T, N>::size_type Array<T, N>::size() const { return N; }                                                                                     // returning the size of the array
//======================================================================================================================================================================================================================
//|                                                                                 MODIFIER FUNCTION                                                                                                             |
//======================================================================================================================================================================================================================
    template <typename T, size_t N> void Array<T, N>::fill(const T& value) { for (auto& elm : elements) { elm = value; } }                                                                      // to fill the array with the specified value
    template <typename T, size_t N> void Array<T, N>::swap(Array& other) { for (size_t i = 0; i < N; ++i) { std::swap(elements[i], other.elements[i]); } }                                      // to swap the contents of this array with another array
//===================================================================================================================================================================================================================================================================================
//|                                                                                  NON-MEMBER FUNCTIONS                                                                                                                                                                           |
//===================================================================================================================================================================================================================================================================================
    template <typename T, size_t N> void swap(Array<T, N>& lhs, Array<T, N>& rhs) { lhs.swap(rhs); }                                                                                            // swap function to swap contents of two arrays
    template <typename T, size_t N> bool operator==(const Array<T, N>& lhs, const Array<T, N>& rhs) { return std::equal(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()); }                      // equality comparison operator function
    template <typename T, size_t N> bool operator!=(const Array<T, N>& lhs, const Array<T, N>& rhs) {  return !(lhs == rhs); }                                                                  // inequality comparison operator function
    template <typename T, size_t N> bool operator<(const Array<T, N>& lhs, const Array<T, N>& rhs) { return std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()); }     // lesser-than comparison operator function
    template <typename T, size_t N> bool operator>(const Array<T, N>& lhs, const Array<T, N>& rhs) { return rhs < lhs; }                                                                        // greater-than comparison operator function
//###################################################################################################################################################################################################################################################################################
}
#endif // ARRAY_TPP_
*/
