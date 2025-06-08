// dvirbto@gmail.com

#ifndef MYCONTAINER_HPP
#define MYCONTAINER_HPP

#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <vector>

/**
 * A costumed namespace.
 */
namespace Ex4Container
{
    /**
     * This class represents a generic container which contains a comparable data types.\n
     * This costumed container has many iterators and supports the methods:\n
     * add - Adds a given generic comparable data type to the container.\n
     * remove - Removes all the data types equal to the given value (if such exist. Otherwise, throws an exception).\n
     * size - Returns the size of the container (amount of values).\n
     * operator << - prints the generic container.\n
     * begin and end methods of each iterator.\n
     */
    template<typename T = int> // the default T is int if not declared otherwise
    class MyContainer
    {
        private:
            std::vector<T> values;

        public:
            /**
             * A default constructor to MyContainer.
             * Initializes the 'values' to an empty vector.
             */
            MyContainer() : values({}) {}

            /**
             * A constructor with a given generic vector.
             * Initializes the 'values' to the given vector.
             * @param values a given vector of a generic primitive data type.
             */
            MyContainer(const std::vector<T> &values) : values(values) {}

            /**
             * Adds a given generic primitive data type to the container.
             * @param newValue the new value that will be added.
             */
            void add(const T &newValue)
            {
                // adds the new value to the vector
                values.emplace_back(newValue);
            }

            /**
             * Removes all the primitive data types equal to the given value.
             * @param removeValue the desired value to remove from the container.
             * @throw std::runtime_error if there are no such data types to remove.
             */
            void remove(const T &removeValue)
            {
                bool found = false; // will be used as a flag (removed or not)
                for (int i = 0; i < values.size(); i++)
                {
                    // primitive data members have operator '==' implementation
                    if (values.at(i) == removeValue)
                    {
                        found = true; // found at least 1 value to remove
                        values.erase(values.begin() + i); // remove the value
                        i--; // the value erased -> need to check the current value at place i again
                        // therefore -> i-- "+" i++ = i
                    }
                }

                // if found still false -> no such value was found -> throw
                if (!found)
                    throw std::runtime_error("Such value to remove does not exist!");
            }

            /**
             * Returns the size of the container.
             * @return the amount of values the container has.
             */
            const int size() const
            {
                return values.size();
            }

            /**
             * Prints MyContainer values.
             * Prints a title and below all the values it has by the order of insertion.
             */
            friend std::ostream &operator<<(std::ostream &output, const MyContainer &container)
            {
                output << std::endl;
                output << "MyContainer:" << std::endl;
                output << "------------" << std::endl;
                output << "[";

                bool first = true;
                for (const auto &value: container.values)
                {
                    // the first and last values will not get a ", "
                    if (!first)
                        output << ", ";

                    output << value;
                    first = false;
                }

                output << "]" << std::endl;
                output << std::endl;
                return output;
            }

            /**
             * Returns a read-only values of the container.
             * @return the values that the container has.
             */
            const std::vector<T> getValues() const
            {
                return values;
            }

            /**
             * This Iterator creates an ascending order of the values the container has.
             * Ascending order: [1,15,3,7,9] -> [1,3,7,9,15]
             */
            class AscendingOrderIterator
            {
                private:
                    std::vector<T> sorted;
                    int currentIndex;

                public:
                    /**
                     * Initializes the sorted vector and the index with initial data.
                     * Then, sorts the vector using std::sort algorithm and to get ascending order.
                     * @param container a given generic container.
                     */
                    explicit AscendingOrderIterator(const MyContainer &container, int index)
                        : sorted(container.getValues()), currentIndex(index)
                    {
                        // sorts the vector from the beginning iterator until it reaches the end iterator
                        std::sort(sorted.begin(), sorted.end());
                    }

                    /**
                     * Postfix overloading to operator '++'.
                     * Increments the current index by 1 and returns a reference to the object.
                     * @return a reference to this object after the current index incremented by 1.
                     */
                    AscendingOrderIterator &operator++()
                    {
                        // increment the current index by 1 and return the reference
                        currentIndex++;
                        return *this;
                    }

                    /**
                     * Returns a read-only reference to the current value in the vector.
                     * @return a generic reference to the data primitive value in the current index.
                     * @throw std::runtime_error if the current index is at least the size of the vector.
                     */
                    const T &operator*() const
                    {
                        // if the current index >= size -> it does not point to any data at all
                        if (currentIndex >= sorted.size())
                            throw std::runtime_error("Index out of range!");

                        // return the value
                        return sorted.at(currentIndex);
                    }

                    /**
                     * Checks if this iterator and a given one point to the same object in the sorted vector.
                     * @param other a given other AscendingOrderIterator iterator.
                     * @return true if both iterators point to the same object. Otherwise, returns false.
                     */
                    bool operator!=(const AscendingOrderIterator &other)
                    {
                        // if both current indexes are identical -> true
                        return currentIndex != other.currentIndex;
                    }
            };

            /**
             * Returns an Iterator points to the beginning of the container by ascending order.
             * @return an AscendingOrder Iterator points to the beginning of the container.
             */
            AscendingOrderIterator begin_ascending_order() const
            {
                return AscendingOrderIterator(values, 0);
            }

            /**
             * Returns an Iterator points to the end of the container by ascending order.
             * @return an AscendingOrder Iterator points to the end of the container.
             */
            AscendingOrderIterator end_ascending_order() const
            {
                return AscendingOrderIterator(values, values.size());
            }

            /**
             * This Iterator creates a descending order of the values the container has.
             * Descending order: [1,15,3,7,9] -> [15,9,7,3,1]
             */
            class DescendingOrderIterator
            {
                private:
                    std::vector<T> sorted;
                    int currentIndex;

                public:
                    /**
                     * Initializes the sorted vector and the index with initial data.
                     * Then, sorts the vector using std::sort algorithm and to get ascending order
                     * and simply use std::reverse algorithm to get the descending order.
                     * @param container a given generic container.
                     */
                    explicit DescendingOrderIterator(const MyContainer &container, int index)
                        : sorted(container.getValues()), currentIndex(index)
                    {
                        // sort the vector from the start iterator until reaches the end iterator
                        std::sort(sorted.begin(), sorted.end());

                        // now the reverse will result the opposite (high to low)
                        std::reverse(sorted.begin(), sorted.end());
                    }

                    /**
                     * Postfix overloading to operator '++'.
                     * Increments the current index by 1 and returns a reference to the object.
                     * @return a reference to this object after the current index incremented by 1.
                     */
                    DescendingOrderIterator &operator++()
                    {
                        currentIndex++;
                        return *this;
                    }

                    /**
                     * Returns a read-only reference to the current value in the vector.
                     * @return a generic reference to the data primitive value in the current index.
                     * @throw std::runtime_error if the current index is at least the size of the vector.
                     */
                    const T &operator*() const
                    {
                        // if the current index >= size -> the current index exceeded the limit of the container values
                        if (currentIndex >= sorted.size())
                            throw std::runtime_error("Index out of range!");

                        return sorted.at(currentIndex);
                    }

                    /**
                     * Checks if this iterator and a given one point to the same object in the sorted vector.
                     * @param other a given other DescendingOrderIterator iterator.
                     * @return true if both containers point to the same object. Otherwise, returns false.
                     */
                    bool operator!=(const DescendingOrderIterator &other)
                    {
                        // if both current indexes are identical -> true, otherwise -> false
                        return currentIndex != other.currentIndex;
                    }
            };

            /**
             * Returns an Iterator points to the beginning of the container by descending order.
             * @return a DescendingOrderIterator Iterator points to the beginning of the container.
             */
            DescendingOrderIterator begin_descending_order() const
            {
                return DescendingOrderIterator(values, 0);
            }

            /**
             * Returns an Iterator points to the end of the container by descending order.
             * @return a DescendingOrderIterator Iterator points to the end of the container.
             */
            DescendingOrderIterator end_descending_order() const
            {
                return DescendingOrderIterator(values, values.size());
            }

            /**
             * This Iterator creates a side-cross order of the values the container has.\n
             * It starts from the minimum number and then the maximum one until it reaches all the values.\n
             * Side cross order: [1,15,3,7,9] -> [1,15,3,9,7]
             */
            class SideCrossOrderIterator
            {
                private:
                    std::vector<T> sorted;
                    int currentIndex;
                    int leftIndex; // points to the current minimum
                    int rightIndex; // points to the current maximum
                    bool min; // flag to choose if to take a minimum or maximum

                public:
                    /**
                     * Initializes the sorted vector and the index with initial data.
                     * Then, sorts the vector using std::sort algorithm and to get ascending order.
                     * Three pointers are initialized. One to a given index and the other two point to
                     * the start of the container and to the end of it.
                     * @param container a given container.
                     * @param index a given position to point to.
                     */
                    explicit SideCrossOrderIterator(const MyContainer &container, int index)
                        : sorted(container.getValues()), currentIndex(index), leftIndex(0),
                          rightIndex(sorted.size() - 1), min(false)
                    {
                        std::sort(sorted.begin(), sorted.end()); // sort the vector
                    }

                    /**
                     * Postfix overloading to operator '++'.
                     * If 'min' variable is true - the current minimum should be picked.\n
                     * Otherwise ('min' is false) - the current maximum is picked.
                     * The iteration stops when all values have been picked.
                     * @return a reference to this object after the selection of minimum/maximum.
                     */
                    SideCrossOrderIterator &operator++()
                    {
                        // when leftIndex >= rightIndex -> finished to iterate -> end
                        if (leftIndex >= rightIndex)
                        {
                            currentIndex = sorted.size(); // -> end
                            return *this;
                        }

                        // min = true -> pick from left (minimum)
                        if (min)
                        {
                            leftIndex++; // move to the next 'minimum' available
                            currentIndex = leftIndex; // update current index
                        }

                        // min = false -> pick from right (maximum)
                        else
                        {
                            currentIndex = rightIndex; // update current index
                            rightIndex--; // move to the next 'maximum' available
                        }

                        // change the next value to take
                        // min = true -> pick from left
                        // min = false -> pick from right
                        min = !min;

                        return *this;
                    }

                    /**
                     * Returns a read-only reference to the current value that this iterator points to.
                     * @return a const reference (read-only) to the current value.
                     * @throw std::runtime_error if the current index is out of range.
                     */
                    const T &operator*() const
                    {
                        if (currentIndex < 0 || currentIndex >= sorted.size())
                            throw std::runtime_error("Index out of range!");

                        return sorted.at(currentIndex);
                    }

                    /**
                     * Checks if two iterators point to the same object in a given vector.
                     * @param other a given SideCrossOrderIterator.
                     * @return true if both this iterator and the given one point to the same generic data type. Otherwise, returns false.
                     */
                    bool operator!=(const SideCrossOrderIterator &other)
                    {
                        return currentIndex != other.currentIndex;
                    }
            };

            /**
             * Returns an Iterator points to the beginning of the container by side-cross order.
             * @return a SideCrossOrderIterator Iterator points to the beginning of the container.
             */
            SideCrossOrderIterator begin_side_cross_order() const
            {
                return SideCrossOrderIterator(values, 0);
            }

            /**
             * Returns an Iterator points to the end of the container by side-cross order.
             * @return a SideCrossOrderIterator Iterator points to the end of the container.
             */
            SideCrossOrderIterator end_side_cross_order() const
            {
                return SideCrossOrderIterator(values, values.size());
            }

            /**
             * This Iterator creates a reverse order of the values the container has.\n
             * It reverses the values order by their insertion.\n
             * Reverse order: [1,15,3,7,9] -> [9,7,3,15,1]
             */
            class ReverseOrderIterator
            {
                private:
                    std::vector<T> original;
                    int currentIndex;

                public:
                    /**
                     * Initializes the 'original' vector amd the current index with initial given data
                     * from the container and a given integer.
                     * Also uses std::reverse algorithm to change the direction of insertion.
                     * @param container
                     * @param index
                     */
                    explicit ReverseOrderIterator(const MyContainer &container, int index)
                        : original(container.getValues()), currentIndex(index)
                    {
                        std::reverse(original.begin(), original.end());
                    }

                    /**
                     * Increments the current index by 1 to get to the next value in this iterator.
                     * @return a const reference to this iterator after incrementation by 1.
                     */
                    const ReverseOrderIterator &operator++()
                    {
                        currentIndex++;
                        return *this;
                    }

                    /**
                     * Returns a read-only reference to the current primitive data member.
                     * @return a const reference to the current value in this iterator.
                     */
                    const T &operator*() const
                    {
                        // trying to reach beyond the original memory allocation -> throw
                        if (currentIndex >= original.size())
                            throw std::runtime_error("Index out of range!");

                        return original.at(currentIndex);
                    }

                    /**
                     * Checks if this iterator and a given one point to the same object.
                     * @param other a given ReverseOrderIterator iterator.
                     * @return true if both this and the given iterator point to the same object. Otherwise, returns false.
                     */
                    bool operator!=(const ReverseOrderIterator &other)
                    {
                        // if the current indexes are different -> they do not point to the same object
                        return currentIndex != other.currentIndex;
                    }
            };

            /**
             * Returns an Iterator points to the beginning of the container by reverse order.
             * @return a ReverseOrderIterator Iterator points to the beginning of the container.
             */
            ReverseOrderIterator begin_reverse_order() const
            {
                return ReverseOrderIterator(values, 0);
            }

            /**
             * Returns an Iterator points to the end of the container by reverse order.
             * @return a ReverseOrderIterator Iterator points to the end of the container.
             */
            ReverseOrderIterator end_reverse_order() const
            {
                return ReverseOrderIterator(values, values.size());
            }

            /**
             * This Iterator creates the same order by insertion of the values the container has.\n
             * 'Order' order: [1,15,3,7,9] -> [1,15,3,7,9]
             */
            class OrderIterator
            {
                private:
                    std::vector<T> original;
                    int currentIndex;

                public:
                    /**
                     * Initializes original and the current index with initial given data.
                     * @param container a given container.
                     * @param index a given position.
                     */
                    explicit OrderIterator(const MyContainer &container, int index) : original(container.getValues()),
                        currentIndex(index) {}

                    /**
                     * Postfix overloading to operator '++'.
                     * Increments the current index by 1 and returns a reference to the object.
                     * @return a reference to this object after the current index incremented by 1.
                     */
                    OrderIterator &operator++()
                    {
                        currentIndex++;
                        return *this;
                    }

                    /**
                     * Returns a read-only reference to the current value that this iterator points to.
                     * @return a const reference (read-only) to the current value.
                     * @throw std::runtime_error if the current index is out of range.
                     */
                    const T &operator*() const
                    {
                        // if the current index point to unused memory -> throw
                        if (currentIndex >= original.size())
                            throw std::runtime_error("Index out of range!");

                        return original.at(currentIndex);
                    }

                    /**
                     * Checks if this iterator and a given one point to the same object.
                     * @param other a given other OrderIterator iterator.
                     * @return true if both this and the given iterator point to the same object. Otherwise, returns false.
                     */
                    bool operator!=(const OrderIterator &other)
                    {
                        // same current index = same object
                        return currentIndex != other.currentIndex;
                    }
            };

            /**
             * Returns an Iterator points to the beginning of the container by the original order of insertion.
             * @return an OrderIterator Iterator points to the beginning of the container.
             */
            OrderIterator begin_order() const
            {
                return OrderIterator(values, 0);
            }

            /**
             * Returns an Iterator points to the end of the container by the original order of insertion.
             * @return an OrderIterator Iterator points to the end of the container.
             */
            OrderIterator end_order() const
            {
                return OrderIterator(values, values.size());
            }

            /**
             * This Iterator creates a middle-cross order of the values the container has.\n
             * It starts from the middle of the vector and then prints 1 value from left and 1 value from right
             * until it prints all the values.\n
             * If the amount of values is even - the middle value is the right one (size/2).\n
             * Middle cross order (odd): [1,15,3,7,9] -> [3,15,7,1,9]
             * Middle cross order (even): [1,15,3,7,9,4] -> [7,3,9,15,4,1]
             */
            class MiddleOutOrderIterator
            {
                private:
                    std::vector<T> origin;
                    int currentIndex;
                    int leftIndex; // points from the middle to the left side of the container
                    int rightIndex; // points from the middle to the right side of the container
                    bool left; // a flag used to determine if to choose a 'left' value or 'right' value

                public:
                    /**
                     * Initializes the 'origin' and current index with initial given data.
                     * Moreover, a leftIndex, eightIndex and a flag also initialized.
                     * @param myContainer a given generic primitive data type container.
                     * @param index a given start position.
                     */
                    explicit MiddleOutOrderIterator(const MyContainer &myContainer, int index)
                        : origin(myContainer.getValues()), currentIndex(index), leftIndex(currentIndex),
                          rightIndex(currentIndex), left(true) {}

                    /**
                     * Postfix overloading to operator '++'.
                     * If 'left' variable is true - a value from left side should be picked next.\n
                     * Otherwise ('left' is false) - a value from right side should be picked.\n
                     * The iteration stops when left index reached to 0 and also right index reached to the size of origin-1
                     * which means all values have been picked and displayed.
                     * @return a reference to this object after the selection of value.
                     */
                    MiddleOutOrderIterator &operator++()
                    {
                        // left and right indexes reached all the values -> stop
                        if (leftIndex == 0 && rightIndex == origin.size() - 1)
                        {
                            currentIndex = origin.size(); // current index -> end
                            return *this;
                        }

                        // left = true -> pick a value from left side
                        if (left)
                        {
                            leftIndex--;
                            currentIndex = leftIndex;
                        }

                        // left = false -> pick a value from right side
                        else
                        {
                            rightIndex++;
                            currentIndex = rightIndex;
                        }

                        left = !left; // change to the next side that the next value will be picked from

                        return *this;
                    }

                    /**
                     * Returns a read-only reference to the current value that this iterator points to.
                     * @return a const reference (read-only) to the current value.
                     * @throw std::runtime_error if the current index is out of range.
                     */
                    const T &operator*() const
                    {
                        // if the current index is pointing to garbage info -> throw
                        if (currentIndex >= origin.size() || currentIndex < 0)
                            throw std::runtime_error("Index out of range!");

                        return origin.at(currentIndex);
                    }

                    /**
                     * Checks if this iterator and a given one point to the same object.
                     * @param other a given ReverseOrderIterator iterator.
                     * @return true if both this and the given iterator point to the same object. Otherwise, returns false.
                     */
                    bool operator!=(const MiddleOutOrderIterator &other) const
                    {
                        // if they both have the same current index -> they point to the same object
                        return currentIndex != other.currentIndex;
                    }
            };

            /**
             * Returns an Iterator points to the beginning of the container by middle-out order.
             * @return a MiddleOutOrderIterator Iterator points to the beginning of the container.
             */
            MiddleOutOrderIterator begin_middle_out_order() const
            {
                return MiddleOutOrderIterator(values, values.size() / 2);
            }

            /**
             * Returns an Iterator points to the end of the container by middle-out order.
             * @return a MiddleOutOrderIterator Iterator points to the end of the container.
             */
            MiddleOutOrderIterator end_middle_out_order() const
            {
                return MiddleOutOrderIterator(values, values.size());
            }
    };
};


// /**
//  * This class represents a costumed generic container with it's own unique methods such as:
//  * Add -
//  * Remove -
//  * ETC..
//  * TODO: continue
//  */
// template<typename T>
// class MyContainer
// {
//     private:
//     T* value; // the generic data members array
//     int containerSize; // the current size of the container
//     int capacity; // the capacity of the container
//
//     public:
//
//     /**
//      * This is the constructor of the costumed generic container.
//      * It initializes the current size to 0, the capacity to 2
//      * and the value is initialized according to the capacity size.
//      */
//     MyContainer() : containerSize(0), capacity(2)
//     {
//         value = new T[capacity];
//     }
//
//
//     MyContainer(T* elements, int size) : value(elements) ,containerSize(0), capacity(size) {}
//
//     /**
//      * This is the destructor of the costumed generic container.
//      * It deletes the dynamic array value.
//      */
//     ~MyContainer()
//     {
//         // for (int i = 0; i < containerSize; i++)
//         //     delete value[i];
//
//         delete[] value;
//     }
//
//     /**
//      * Adds a given generic data type to the generic container.
//      * @param addValue the object that will be added to the container.
//      */
//     void add(const T& addValue)
//     {
//         // if the container is full -> increase the capacity
//         if (containerSize == capacity)
//         {
//             capacity *= 2;
//             T* newValue = new T[capacity]; // create a new array in the new size
//
//             // init the new array with the current values
//             for (int i = 0; i < containerSize; i++)
//                 newValue[i] = value[i];
//
//             // delete the previous values
//             delete[] value;
//
//             // set the value to the new values
//             value = newValue;
//         }
//
//         // add the new value to the container and the new size
//         value[containerSize] = addValue;
//         containerSize++;
//     }
//
//     /**
//      * Removes all the data members equal to the given element value.
//      * @param removeValue the desired element to remove from the container.
//      * @throw std::runtime_error if there are no such data members to remove.
//      */
//     void remove(const T& removeValue)
//     {
//         bool found = false; // a flag
//
//         // loop over all the values
//         for (int i = 0; i < containerSize; i++)
//         {
//             // if they are equal -> set the flag to true and remove the element
//             if (value[i] == removeValue)
//             {
//                 // found at least 1 element that matches
//                 found = true;
//
//                 // rearrange the container
//                 int j = i;
//                 while (j != containerSize-1)
//                 {
//                     value[j] = value[j + 1];
//                     j++;
//                 }
//                 // delete value[containerSize-1];
//                 i--;
//             }
//         }
//
//         // if no such element was found -> exception
//         if (!found)
//             throw std::runtime_error("No such value was found!");
//
//         // if the capacity >> current size -> divide it by 2
//         if (capacity > 2*containerSize)
//             capacity /= 2;
//     }
//
//     /**
//      * Returns the number of elements in the container.
//      * @return the current size of the container.
//      */
//     const int size() const
//     {
//         return containerSize;
//     }
//
//
//
//     // create the iterators
//
//
//     // class AscendingOrderIterator
//     // {
//     //     private:
//     //     T** pointer_to_current_value;
//     //
//     //     MyContainer myContainer;
//     //
//     //     public:
//     //
//     //     AscendingOrderIterator(T* elements, int size) : myContainer(MyContainer()) {}
//     //     T* AscendingOrderIterator_begin() : element(value)
//     //     {
//     //         return element;
//     //     }
//     //
//     //
//     //
//     //     /**
//     //      * Returns an AscendingOrderIterator by value as it's small.
//     //      * @return iterator by value.
//     //      */
//     //     const AscendingOrderIterator operator++()
//     //     {
//     //         AscendingOrderIterator tmp = *this;
//     //         ++(*this);
//     //         return tmp;
//     //     }
//     //
//     //     /**
//     //      * Returns a pointer to the current value and the value can not be modified.
//     //      * @return a pointer to the current value of the container.
//     //      */
//     //     T& operator*() const {
//     //         return pointer_to_current_value;
//     //     }
//     //
//     //     /**
//     //      * Checks if this iterator points to the same object as a given iterator also does.
//     //      * @param other the other given iterator.
//     //      * @return true if both iterators point to the same object. Otherwise, returns false.
//     //      */
//     //     bool operator==(const AscendingOrderIterator& other) const
//     //     {
//     //         // if they both point to the same value -> returns true
//     //         // otherwise -> returns false
//     //         return pointer_to_current_value == other.pointer_to_current_value;
//     //     }
//     //
//     //     /**
//     //      * Checks if this iterator does not point to the same object as a given iterator does.
//     //      * @param other the other given iterator.
//     //      * @return true if both iterators don't point to the same object. Otherwise, returns false.
//     //      */
//     //     bool operator!=(const AscendingOrderIterator& other) const
//     //     {
//     //         // if they both point to the same value -> returns false
//     //         // otherwise -> returns true
//     //         return pointer_to_current_value != other.pointer_to_current_value;
//     //     }
//
//
//     class AscendingOrderIterator
//     {
//         private:
//             T** ASCsort;
//             int currentIndex;
//             int size;
//
//         public:
//
//             AscendingOrderIterator(T* elements, int size) : currentIndex(0), size(size)
//             {
//                 ASCsort = new T*[size];
//
//                 for (int i = 0; i < size; i++)
//                     ASCsort[i] = &elements[i];
//
//                 std::sort(ASCsort, ASCsort+size);
//             }
//
//             AscendingOrderIterator(int offset) : currentIndex(offset)
//             {
//
//             }
//
//             ~AscendingOrderIterator()
//             {
//                 delete[] ASCsort;
//             }
//
//             AscendingOrderIterator& operator++()
//             {
//                 return ASCsort[currentIndex++];
//             }
//
//             const AscendingOrderIterator& operator*()
//             {
//                 return ASCsort[currentIndex];
//             }
//
//             bool operator!=(const AscendingOrderIterator& other)
//             {
//                 return currentIndex != other.currentIndex;
//             }
//
//             AscendingOrderIterator& begin()
//             {
//                 return
//             }
//     };
// };

#endif //MYCONTAINER_HPP
