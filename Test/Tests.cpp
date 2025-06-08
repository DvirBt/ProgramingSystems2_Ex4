// dvirbto@gmail.com

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <iostream>
#include "../MyContainer.hpp"

using namespace std;
using namespace Ex4Container;

/**
 * This class contains all the test of MyContainer - a costumed generic container with primitive data types.\n
 * All the methods and iterators of MyContainer will be tested.\n
 * All the functions will be tested with DocTest.\n
 */

/**
 * This test case will test the basic methods of MyContainer class which are:\n
 * add - Adds a given generic primitive data type to the container.\n
 * remove - Removes all the primitive data types equal to the given value.\n
 * size - Returns the size of the container (amount of values).\n
 * operator << - prints the generic container.
 */
TEST_CASE("Methods of MyContainer")
{
    /**
    * Adds a given generic primitive data type to the container.
    * @param newValue the new value that will be added.
    */
    SUBCASE("add method")
    {
        // integer container
        MyContainer<> intContainer;
        CHECK_EQ(intContainer.size(), 0); // the container is empty

        cout << endl;
        cout << "add 1";
        intContainer.add(1); // add the integer 1
        CHECK_EQ(intContainer.size(), 1); // the size is now 1
        CHECK_EQ(intContainer.getValues().at(0), 1); // make sure 1 is inserted
        cout << intContainer;

        cout << "add 2";
        intContainer.add(2); // add the integer 2
        CHECK_EQ(intContainer.size(), 2); // size is now 2
        CHECK_EQ(intContainer.getValues().at(0), 1); // make sure 1 is still there
        CHECK_EQ(intContainer.getValues().at(1), 2); // make sure 2 is now added
        cout << intContainer;

        // double container
        MyContainer<double> doubleContainer;
        CHECK_EQ(doubleContainer.size(), 0); // the container is empty

        cout << "add 1.1";
        doubleContainer.add(1.1); // add the double 1.1
        CHECK_EQ(doubleContainer.size(), 1); // the size is now 1
        CHECK_EQ(doubleContainer.getValues().at(0), 1.1); // make sure 1.1 is inserted
        cout << doubleContainer;

        cout << "add 2.2";
        doubleContainer.add(2.2); // add the double 2.2
        CHECK_EQ(doubleContainer.size(), 2); // size is now 2
        CHECK_EQ(doubleContainer.getValues().at(0), 1.1); // make sure 1.1 is still there
        CHECK_EQ(doubleContainer.getValues().at(1), 2.2); // make sure 2.2 is now added
        cout << doubleContainer;

        // char container
        MyContainer<char> charContainer;
        CHECK_EQ(charContainer.size(), 0); // the container is empty

        cout << "add 'a'";
        charContainer.add('a'); // add the char 'a'
        CHECK_EQ(charContainer.size(), 1); // the size is now 1
        CHECK_EQ(charContainer.getValues().at(0), 'a'); // make sure 'a' is inserted
        cout << charContainer;

        cout << "add 'b'";
        charContainer.add('b'); // add the char 'b'
        CHECK_EQ(charContainer.size(), 2); // size is now 2
        CHECK_EQ(charContainer.getValues().at(0), 'a'); // make sure 'a' is still there
        CHECK_EQ(charContainer.getValues().at(1), 'b'); // make sure 'b' is now added
        cout << charContainer;

        // string container
        MyContainer<string> stringContainer;
        CHECK_EQ(stringContainer.size(), 0); // the container is empty

        cout << "add 'aa'";
        stringContainer.add("aa"); // add the string "aa"
        CHECK_EQ(stringContainer.size(), 1); // the size is now 1
        CHECK_EQ(stringContainer.getValues().at(0), "aa"); // make sure "aa" is inserted
        cout << stringContainer;

        cout << "add 'bb'";
        stringContainer.add("bb"); // add the string "bb"
        CHECK_EQ(stringContainer.size(), 2); // size is now 2
        CHECK_EQ(stringContainer.getValues().at(0), "aa"); // make sure "aa" is still there
        CHECK_EQ(stringContainer.getValues().at(1), "bb"); // make sure "bb" is now added
        cout << stringContainer;
    }

    /**
     * Removes all the primitive data types equal to the given value.
     * @param removeValue the desired value to remove from the container.
     * @throw std::runtime_error if there are no such data types to remove.
     */
    SUBCASE("remove method")
    {
        // test an int container
        MyContainer<> intContainer({1, 1, 2, 3, 1, -1});
        CHECK_EQ(intContainer.size(), 6); // the container is initialized with 6 values
        cout << intContainer;

        cout << "remove 1";
        intContainer.remove(1); // there are 3 values equal to 1
        CHECK_EQ(intContainer.size(), 3); // remove method should have removed all of them
        // make sure all the values are not 1
        CHECK_EQ(intContainer.getValues().at(0), 2);
        CHECK_EQ(intContainer.getValues().at(1), 3);
        CHECK_EQ(intContainer.getValues().at(2), -1);
        cout << intContainer;

        cout << "remove 3";
        intContainer.remove(3); // only 1 value equals 3
        CHECK_EQ(intContainer.size(), 2); // remove method should have removed only 3 (1 value)
        // make sure all the values are not 3
        CHECK_EQ(intContainer.getValues().at(0), 2);
        CHECK_EQ(intContainer.getValues().at(1), -1);
        cout << intContainer;

        CHECK_THROWS(intContainer.remove(0)); // 0 is not a value in the container -> remove throws exception

        // test a double container
        MyContainer<double> doubleContainer({1.0, 1.0, 2.2, 3.3, 1, -1.0});
        CHECK_EQ(doubleContainer.size(), 6); // the container is initialized with 6 values
        cout << doubleContainer;

        cout << "remove 1.0";
        doubleContainer.remove(1.0); // there are 3 values equal to 1.0 (2X1.0 + 1)
        CHECK_EQ(doubleContainer.size(), 3); // remove method should have removed all of them
        // make sure all the values are not 1.0
        CHECK_EQ(doubleContainer.getValues().at(0), 2.2);
        CHECK_EQ(doubleContainer.getValues().at(1), 3.3);
        CHECK_EQ(doubleContainer.getValues().at(2), -1.0);
        cout << doubleContainer;

        cout << "remove 3.3";
        doubleContainer.remove(3.3); // only 1 value equals 3.3
        CHECK_EQ(doubleContainer.size(), 2); // remove method should have removed only 3.3 (1 value)
        // make sure all the values are not 3.3
        CHECK_EQ(doubleContainer.getValues().at(0), 2.2);
        CHECK_EQ(doubleContainer.getValues().at(1), -1.0);
        cout << doubleContainer;

        CHECK_THROWS(doubleContainer.remove(1)); // 1 (=1.0) is not a value in the container -> remove throws exception

        // test a char container
        MyContainer<char> charContainer({'a', 'a', 'b', 'c', 'a', 'A'});
        CHECK_EQ(charContainer.size(), 6); // the container is initialized with 6 values
        cout << charContainer;

        cout << "remove 'a'";
        charContainer.remove('a'); // there are 3 values equal to 'a'
        CHECK_EQ(charContainer.size(), 3); // remove method should have removed all of them
        // make sure all the values are not 'a'
        CHECK_EQ(charContainer.getValues().at(0), 'b');
        CHECK_EQ(charContainer.getValues().at(1), 'c');
        CHECK_EQ(charContainer.getValues().at(2), 'A');
        cout << charContainer;

        cout << "remove 'c'";
        charContainer.remove('c'); // only 1 value equals 'c'
        CHECK_EQ(charContainer.size(), 2); // remove method should have removed only 'c' (1 value)
        // make sure all the values are not 'c'
        CHECK_EQ(charContainer.getValues().at(0), 'b');
        CHECK_EQ(charContainer.getValues().at(1), 'A');
        cout << charContainer;

        CHECK_THROWS(charContainer.remove('a')); // 'a' is not a value in the container -> remove throws exception

        // test a string container
        MyContainer<string> stringContainer({"aa", "aa", "bb", "cc", "aa", "aA"});
        CHECK_EQ(stringContainer.size(), 6); // the container is initialized with 6 values
        cout << stringContainer;

        cout << "remove 'aa'";
        stringContainer.remove("aa"); // there are 3 values equal to "aa"
        CHECK_EQ(stringContainer.size(), 3); // remove method should have removed all of them
        // make sure all the values are not "aa"
        CHECK_EQ(stringContainer.getValues().at(0), "bb");
        CHECK_EQ(stringContainer.getValues().at(1), "cc");
        CHECK_EQ(stringContainer.getValues().at(2), "aA");
        cout << stringContainer;

        cout << "remove 'cc'";
        stringContainer.remove("cc"); // only 1 value equals "cc"
        CHECK_EQ(stringContainer.size(), 2); // remove method should have removed only 'c' (1 value)
        // make sure all the values are not "cc"
        CHECK_EQ(stringContainer.getValues().at(0), "bb");
        CHECK_EQ(stringContainer.getValues().at(1), "aA");
        cout << stringContainer;

        CHECK_THROWS(stringContainer.remove("Aa")); // "Aa" is not a value in the container -> remove throws exception
    }

    /**
     * Returns the size of the container.
     * @return the amount of values the container has.
     */
    SUBCASE("size method")
    {
        // test int container
        MyContainer<> intContainer({1, 1, 2, -1});
        CHECK_EQ(intContainer.size(), 4); // the container is initialized with 4 values

        // remove the value 2 which is exactly 1 element
        intContainer.remove(2);
        CHECK_EQ(intContainer.size(), 3); // after the removal -> 3 values remaining

        // try to remove a non-existing value -> size should not be changed
        CHECK_THROWS(intContainer.remove(0));
        CHECK_EQ(intContainer.size(), 3); // size stayed the same (=3)

        // remove the value 1 -> the container will contain only 1 value
        intContainer.remove(1);
        CHECK_EQ(intContainer.size(), 1); //  2/3 values are 1 -> size will be 1

        // remove the value -1 -> the container will become empty
        intContainer.remove(-1);
        CHECK_EQ(intContainer.size(), 0); //  1/1 values are -1 -> size will be 0

        // test double container
        MyContainer<double> doubleContainer({1.1, 1.1, 2.2, -1.1});
        CHECK_EQ(doubleContainer.size(), 4); // the container is initialized with 4 values

        // remove the value 2.2 which is exactly 1 element
        doubleContainer.remove(2.2);
        CHECK_EQ(doubleContainer.size(), 3); // after the removal -> 3 values remaining

        // try to remove a non-existing value -> size should not be changed
        CHECK_THROWS(doubleContainer.remove(0));
        CHECK_EQ(doubleContainer.size(), 3); // size stayed the same (=3)

        // remove the value 1.1 -> the container will contain only 1 value
        doubleContainer.remove(1.1);
        CHECK_EQ(doubleContainer.size(), 1); //  2/3 values are 1.1 -> size will be 1

        // remove the value -1.1 -> the container will become empty
        doubleContainer.remove(-1.1);
        CHECK_EQ(doubleContainer.size(), 0); //  1/1 values are -1.1 -> size will be 0

        // test char container
        MyContainer<char> charContainer({'a', 'a', 'b', 'A'});
        CHECK_EQ(charContainer.size(), 4); // the container is initialized with 4 values

        // remove the value 'b' which is exactly 1 element
        charContainer.remove('b');
        CHECK_EQ(charContainer.size(), 3); // after the removal -> 3 values remaining

        // try to remove a non-existing value -> size should not be changed
        CHECK_THROWS(charContainer.remove('z'));
        CHECK_EQ(charContainer.size(), 3); // size stayed the same (=3)

        // remove the value 'a' -> the container will contain only 1 value
        charContainer.remove('a');
        CHECK_EQ(charContainer.size(), 1); //  2/3 values are 'a' -> size will be 1

        // remove the value 'A' -> the container will become empty
        charContainer.remove('A');
        CHECK_EQ(charContainer.size(), 0); //  1/1 values are 'A' -> size will be 0

        // test string container
        MyContainer<string> stringContainer({"aa", "aa", "bb", "aA"});
        CHECK_EQ(stringContainer.size(), 4); // the container is initialized with 4 values

        // remove the value "bb" which is exactly 1 element
        stringContainer.remove("bb");
        CHECK_EQ(stringContainer.size(), 3); // after the removal -> 3 values remaining

        // try to remove a non-existing value -> size should not be changed
        CHECK_THROWS(stringContainer.remove("a"));
        CHECK_EQ(stringContainer.size(), 3); // size stayed the same (=3)

        // remove the value "aa" -> the container will contain only 1 value
        stringContainer.remove("aa");
        CHECK_EQ(stringContainer.size(), 1); //  2/3 values are "aa" -> size will be 1

        // remove the value "aA" -> the container will become empty
        stringContainer.remove("aA");
        CHECK_EQ(stringContainer.size(), 0); //  1/1 values are "aA" -> size will be 0
    }

    /**
     * Prints MyContainer values.
     * Prints a title and below all the values it has by the order of insertion.
     */
    SUBCASE("overloaded operator << method")
    {
        ostringstream output; // will store the string print of the container
        ostringstream expected; // will store the expected string output

        // test int container print
        MyContainer<> intContainer({1, 1, 2, -1});

        output << intContainer; // get the ostream by method

        // create the expected result
        expected << endl;
        expected << "MyContainer:" << endl;
        expected << "------------" << endl;
        expected << "[1, 1, 2, -1]" << endl;
        expected << endl;

        CHECK_EQ(output.str(), expected.str()); // convert to string to make comparison

        // test double container print
        MyContainer<double> doubleContainer({1.1, 1.1, 2.2, -1.1});

        output << doubleContainer; // get the ostream by method

        // create the expected result
        expected << endl;
        expected << "MyContainer:" << endl;
        expected << "------------" << endl;
        expected << "[1.1, 1.1, 2.2, -1.1]" << endl;
        expected << endl;

        CHECK_EQ(output.str(), expected.str()); // convert to string to make comparison

        // test char container print
        MyContainer<char> charContainer({'a', 'a', 'b', 'A'});

        output << charContainer; // get the ostream by method

        // create the expected result
        expected << endl;
        expected << "MyContainer:" << endl;
        expected << "------------" << endl;
        expected << "[a, a, b, A]" << endl;
        expected << endl;

        CHECK_EQ(output.str(), expected.str());

        // test int container print
        MyContainer<string> stringContainer({"aa", "aa", "bb", "aA"});

        output << stringContainer; // get the ostream by method

        // create the expected result
        expected << endl;
        expected << "MyContainer:" << endl;
        expected << "------------" << endl;
        expected << "[aa, aa, bb, aA]" << endl;
        expected << endl;

        CHECK_EQ(output.str(), expected.str()); // convert to string to make comparison
    }
}

// now let's test the different iterators


/**
 * This is a helper struct to initialize a setup data.
 */
struct allContainers
{
    MyContainer<> intContainer;
    MyContainer<double> doubleContainer;
    MyContainer<char> charContainer;
    MyContainer<string> stringContainer;

    allContainers() : intContainer({1, 15, 3, 7, 9}), doubleContainer({-1.1, 10.3, 7.2, 3.4, 5.8}),
                      charContainer({'d', 'a', 'G', 'm', 'Z'}), stringContainer({"abc", "ABC", "aBc", "deg", "ze"}) {}
};

/**
 * This Iterator creates an ascending order of the values the container has.
 * Ascending order: [1,15,3,7,9] -> [1,3,7,9,15]
 */
TEST_CASE_FIXTURE(allContainers, "AscendingOrder iterator methods")
{
    // this case will check all the operators of int container - {1, 15, 3, 7, 9}
    SUBCASE("operator '++' & operator '*' & operator '!=' tests for an integer container")
    {
        int min = INT_MIN;
        auto it = intContainer.begin_ascending_order(); // it points to the minimum value
        auto endit = intContainer.end_ascending_order(); // endit points to the end of the container

        // the original container is {1, 15, 3, 7, 9}
        // after ascending order -> {1, 3, 7, 9, 15}
        const vector<int> asc = {1, 3, 7, 9, 15}; // this is the expected result
        int index = 0; // will be used to iterate over the vector asc

        bool result; // will be used to determine if the value is indeed the minimum of all other values

        for (; it != endit; ++it)
        {
            result = min <= *it; // check if each value is >= the last one
            CHECK(result); // make sure that it points to the minimum value available in the container
            CHECK_EQ(*it, asc.at(index)); // check if the values match
            index++; // move to the next value to check
            min = *it; // update the last minimum
        }

        CHECK_FALSE(it != endit); // it reached to the end
        CHECK_THROWS(*it); // *it contains garbage data -> exception
    }

    // this case will check all the operators of double container - {-1.1, 10.3, 7.2, 3.4, 5.8}
    SUBCASE("operator '++' & operator '*' & operator '!=' tests for a double container")
    {
        double min = numeric_limits<double>::lowest(); // the lowest negative double number

        auto it = doubleContainer.begin_ascending_order(); // it points to the minimum value
        auto endit = doubleContainer.end_ascending_order(); // endit points to the end of the container

        // the original container is {-1.1, 10.3, 7.2, 3.4, 5.8}
        // after ascending order -> {-1.1, 3.4, 5.8, 7.2, 10.3}
        const vector<double> asc = {-1.1, 3.4, 5.8, 7.2, 10.3}; // this is the expected result
        int index = 0; // will be used to iterate over the vector asc

        bool result; // will be used to determine if the value is indeed the minimum of all other values

        for (; it != endit; ++it)
        {
            result = min <= *it; // check if each value is >= the last one
            CHECK(result); // make sure that it points to the minimum value available in the container
            CHECK_EQ(*it, asc.at(index)); // check if the values match
            index++; // move to the next value to check
            min = *it; // update the last minimum
        }

        CHECK_FALSE(it != endit); // it reached to the end
        CHECK_THROWS(*it); // *it contains garbage data -> exception
    }

    // this case will check all the operators of char container - {'d', 'a', 'G', 'm', 'Z'}
    SUBCASE("operator '++' & operator '*' & operator '!=' tests for a char container")
    {
        char min = 'A'; // 'A' is the "minimum" char (A-Z = [65,90], a-z = [97,122])

        auto it = charContainer.begin_ascending_order(); // it points to the minimum value
        auto endit = charContainer.end_ascending_order(); // endit points to the end of the container

        // the original container is {'d', 'a', 'G', 'm', 'Z'}
        // after ascending order -> {'G', 'Z', 'a', 'd', 'm'}
        const vector<char> asc = {'G', 'Z', 'a', 'd', 'm'}; // this is the expected result
        int index = 0; // will be used to iterate over the vector asc

        bool result; // will be used to determine if the value is indeed the minimum of all other values

        for (; it != endit; ++it)
        {
            result = min <= *it; // check if each value is >= the last one
            CHECK(result); // make sure that it points to the minimum value available in the container
            CHECK_EQ(*it, asc.at(index)); // check if the values match
            index++; // move to the next value to check
            min = *it; // update the last minimum
        }

        CHECK_FALSE(it != endit); // it reached to the end
        CHECK_THROWS(*it); // *it contains garbage data -> exception
    }

    // this case will check all the operators of string container - {"abc", "ABC", "aBc", "deg", "ze"}
    SUBCASE("operator '++' & operator '*' & operator '!=' tests for a string container")
    {
        string min = ""; // this is "minimum" string

        auto it = stringContainer.begin_ascending_order(); // it points to the minimum value
        auto endit = stringContainer.end_ascending_order(); // endit points to the end of the container

        // the original container is {"abc", "ABC", "aBc", "deg", "ze"}
        // after ascending order -> {"ABC", "aBc", "abc", "deg", "ze"}
        const vector<string> asc = {"ABC", "aBc", "abc", "deg", "ze"}; // this is the expected result
        int index = 0; // will be used to iterate over the vector asc

        bool result; // will be used to determine if the value is indeed the minimum of all other values

        for (; it != endit; ++it)
        {
            result = min <= *it; // check if each value is >= the last one
            CHECK(result); // make sure that it points to the minimum value available in the container
            CHECK_EQ(*it, asc.at(index)); // check if the values match
            index++; // move to the next value to check
            min = *it; // update the last minimum
        }

        CHECK_FALSE(it != endit); // it reached to the end
        CHECK_THROWS(*it); // *it contains garbage data -> exception
    }
}

/**
 * This Iterator creates a descending order of the values the container has.
 * Ascending order: [1,15,3,7,9] -> [15,9,7,3,1]
 */
TEST_CASE_FIXTURE(allContainers, "Descending iterator methods")
{
    // this case will check all the operators of int container - {1, 15, 3, 7, 9}
    SUBCASE("operator '++' & operator '*' & operator '!=' tests for an integer container")
    {
        int max = INT_MAX;
        auto it = intContainer.begin_descending_order(); // it points to the maximum value
        auto endit = intContainer.end_descending_order(); // endit points to the end of the container

        // the original container is {1, 15, 3, 7, 9}
        // after descending order -> {15, 9, 7, 3, 1}
        const vector<int> des = {15, 9, 7, 3, 1}; // this is the expected result
        int index = 0; // will be used to iterate over the vector dec

        bool result; // will be used to determine if the value is indeed the minimum of all other values

        for (; it != endit; ++it)
        {
            result = max >= *it; // check if each value is <= the last one
            CHECK(result); // make sure that it points to the minimum value available in the container
            CHECK_EQ(*it, des.at(index)); // check if the values match
            index++; // move to the next value to check
            max = *it; // update the last max
        }

        CHECK_FALSE(it != endit); // it reached to the end
        CHECK_THROWS(*it); // *it contains garbage data -> exception
    }

    // this case will check all the operators of double container - {-1.1, 10.3, 7.2, 3.4, 5.8}
    SUBCASE("operator '++' & operator '*' & operator '!=' tests for a double container")
    {
        double max = numeric_limits<double>::max(); // the maximum double number

        auto it = doubleContainer.begin_descending_order(); // it points to the maximum value
        auto endit = doubleContainer.end_descending_order(); // endit points to the end of the container

        // the original container is {-1.1, 10.3, 7.2, 3.4, 5.8}
        // after descending order -> {10.3, 7.2, 5.8, 3.4, -1.1}
        const vector<double> des = {10.3, 7.2, 5.8, 3.4, -1.1}; // this is the expected result
        int index = 0; // will be used to iterate over the vector asc

        bool result; // will be used to determine if the value is indeed the minimum of all other values

        for (; it != endit; ++it)
        {
            result = max >= *it; // check if each value is <= the last one
            CHECK(result); // make sure that it points to the minimum value available in the container
            CHECK_EQ(*it, des.at(index)); // check if the values match
            index++; // move to the next value to check
            max = *it; // update the last max
        }

        CHECK_FALSE(it != endit); // it reached to the end
        CHECK_THROWS(*it); // *it contains garbage data -> exception
    }

    // this case will check all the operators of char container - {'d', 'a', 'G', 'm', 'Z'}
    SUBCASE("operator '++' & operator '*' & operator '!=' tests for a char container")
    {
        char max = 'z'; // 'z' is the "maximum" char (A-Z = [65,90], a-z = [97,122])

        auto it = charContainer.begin_descending_order(); // it points to the maximum value
        auto endit = charContainer.end_descending_order(); // endit points to the end of the container

        // the original container is {'d', 'a', 'G', 'm', 'Z'}
        // after descending order -> {'m', 'd', 'a', 'Z', 'G'}
        const vector<char> des = {'m', 'd', 'a', 'Z', 'G'}; // this is the expected result
        int index = 0; // will be used to iterate over the vector asc

        bool result; // will be used to determine if the value is indeed the minimum of all other values

        for (; it != endit; ++it)
        {
            result = max >= *it; // check if each value is <= the last one
            CHECK(result); // make sure that it points to the minimum value available in the container
            CHECK_EQ(*it, des.at(index)); // check if the values match
            index++; // move to the next value to check
            max = *it; // update the last max
        }

        CHECK_FALSE(it != endit); // it reached to the end
        CHECK_THROWS(*it); // *it contains garbage data -> exception
    }

    // this case will check all the operators of string container - {"abc", "ABC", "aBc", "deg", "ze"}
    SUBCASE("operator '++' & operator '*' & operator '!=' tests for a string container")
    {
        string max = "zz"; // this is "maximum" string in this case

        auto it = stringContainer.begin_descending_order(); // it points to the maximum value
        auto endit = stringContainer.end_descending_order(); // endit points to the end of the container

        // the original container is {"abc", "ABC", "aBc", "deg", "ze"}
        // after descending order -> {"ze", "deg", "abc", "aBc", "ABC"}
        const vector<string> des = {"ze", "deg", "abc", "aBc", "ABC"}; // this is the expected result
        int index = 0; // will be used to iterate over the vector asc

        bool result; // will be used to determine if the value is indeed the minimum of all other values

        for (; it != endit; ++it)
        {
            result = max >= *it; // check if each value is <= the last one
            CHECK(result); // make sure that it points to the minimum value available in the container
            CHECK_EQ(*it, des.at(index)); // check if the values match
            index++; // move to the next value to check
            max = *it; // update the last max
        }

        CHECK_FALSE(it != endit); // it reached to the end
        CHECK_THROWS(*it); // *it contains garbage data -> exception
    }
}

/**
 * This Iterator creates a side-cross order of the values the container has.\n
 * It starts from the minimum number and then the maximum one until it reaches all the values.\n
 * Side cross order: [1,15,3,7,9] -> [1,15,3,9,7]
 */
TEST_CASE_FIXTURE(allContainers, "SideCross iterator methods")
{
    // this case will check all the operators of int container - {1, 15, 3, 7, 9}
    SUBCASE("operator '++' & operator '*' & operator '!=' tests for an integer container")
    {
        // set the minimum and maximum of this example
        int max = INT_MAX;
        int min = INT_MIN;

        auto it = intContainer.begin_side_cross_order(); // it points to the minimum number
        auto endit = intContainer.end_side_cross_order(); // endit points to the end of the container

        // the original container is {1, 15, 3, 7, 9}
        // after side-cross order -> {1, 15, 3, 9, 7}
        const vector<int> minMax = {1, 15, 3, 9, 7}; // this is the expected result
        int index = 0; // will be used to iterate over the vector dec
        bool minTurn = true; // a flag declares if to take the minimum (true) or maximum (false)

        bool result; // will be used to determine if the value is indeed the minimum of all other values

        for (; it != endit; ++it)
        {
            // pick a minimum value
            if (minTurn)
            {
                result = min <= *it; // check if the value >= the last min
                min = *it;
            }

            // pick a maximum value
            else
            {
                result = max >= *it; // check if the value is <= the last one
                max = *it; // update the last max
            }

            CHECK(result); // make sure that it points to the minimum value available in the container
            CHECK_EQ(*it, minMax.at(index)); // check if the values match
            index++; // move to the next value to check
            minTurn = !minTurn; // change turns
        }

        CHECK_FALSE(it != endit); // it reached to the end
        CHECK_THROWS(*it); // *it contains garbage data -> exception
    }

    // this case will check all the operators of double container - {-1.1, 10.3, 7.2, 3.4, 5.8}
    SUBCASE("operator '++' & operator '*' & operator '!=' tests for a double container")
    {
        // set the minimum and maximum
        double max = numeric_limits<double>::max(); // the maximum double number
        double min = numeric_limits<double>::lowest(); // the minimum double number

        auto it = doubleContainer.begin_side_cross_order(); // it points to the minimum number
        auto endit = doubleContainer.end_side_cross_order(); // endit points to the end of the container

        // the original container is {-1.1, 10.3, 7.2, 3.4, 5.8}
        // after side-cross order -> {-1.1, 10.3, 3.4, 5.8, 7.2}
        const vector<double> minMax = {-1.1, 10.3, 3.4, 7.2, 5.8}; // this is the expected result
        int index = 0; // will be used to iterate over the vector dec
        bool minTurn = true; // a flag declares if to take the minimum (true) or maximum (false)

        bool result; // will be used to determine if the value is indeed the minimum of all other values

        for (; it != endit; ++it)
        {
            // pick a minimum value
            if (minTurn)
            {
                result = min <= *it; // check if the value >= the last min
                min = *it;
            }

            // pick a maximum value
            else
            {
                result = max >= *it; // check if the value is <= the last one
                max = *it; // update the last max
            }

            CHECK(result); // make sure that it points to the minimum value available in the container
            CHECK_EQ(*it, minMax.at(index)); // check if the values match
            index++; // move to the next value to check
            minTurn = !minTurn; // change turns
        }

        CHECK_FALSE(it != endit); // it reached to the end
        CHECK_THROWS(*it); // *it contains garbage data -> exception
    }

    // this case will check all the operators of char container - {'d', 'a', 'G', 'm', 'Z'}
    SUBCASE("operator '++' & operator '*' & operator '!=' tests for a char container")
    {
        // init min and max
        char max = 'z'; // 'z' is the "maximum" char (A-Z = [65,90], a-z = [97,122])
        char min = 'A';

        auto it = charContainer.begin_side_cross_order(); // it points to the minimum number
        auto endit = charContainer.end_side_cross_order(); // endit points to the end of the container

        // the original container is {'d', 'a', 'G', 'm', 'Z'}
        // after side-cross order -> {'G', 'm', 'Z', 'd', 'a'}
        const vector<char> minMax = {'G', 'm', 'Z', 'd', 'a'}; // this is the expected result
        int index = 0; // will be used to iterate over the vector dec
        bool minTurn = true; // a flag declares if to take the minimum (true) or maximum (false)

        bool result; // will be used to determine if the value is indeed the minimum of all other values

        for (; it != endit; ++it)
        {
            // pick a minimum value
            if (minTurn)
            {
                result = min <= *it; // check if the value >= the last min
                min = *it;
            }

            // pick a maximum value
            else
            {
                result = max >= *it; // check if the value is <= the last one
                max = *it; // update the last max
            }

            CHECK(result); // make sure that it points to the minimum value available in the container
            CHECK_EQ(*it, minMax.at(index)); // check if the values match
            index++; // move to the next value to check
            minTurn = !minTurn; // change turns
        }

        CHECK_FALSE(it != endit); // it reached to the end
        CHECK_THROWS(*it); // *it contains garbage data -> exception
    }

    // this case will check all the operators of string container - {"abc", "ABC", "aBc", "deg", "ze"}
    SUBCASE("operator '++' & operator '*' & operator '!=' tests for a string container")
    {
        // init min and max
        string min = ""; // in this case this is the min string
        string max = "zzz"; // in this case this is the max string

        auto it = stringContainer.begin_side_cross_order(); // it points to the minimum number
        auto endit = stringContainer.end_side_cross_order(); // endit points to the end of the container

        // the original container is {"abc", "ABC", "aBc", "deg", "ze"}
        // after side-cross order -> {"ABC", "ze", "aBc", "deg", "abc"}
        const vector<string> minMax = {"ABC", "ze", "aBc", "deg", "abc"}; // this is the expected result
        int index = 0; // will be used to iterate over the vector dec
        bool minTurn = true; // a flag declares if to take the minimum (true) or maximum (false)

        bool result; // will be used to determine if the value is indeed the minimum of all other values

        for (; it != endit; ++it)
        {
            // pick a minimum value
            if (minTurn)
            {
                result = min <= *it; // check if the value >= the last min
                min = *it;
            }

            // pick a maximum value
            else
            {
                result = max >= *it; // check if the value is <= the last one
                max = *it; // update the last max
            }

            CHECK(result); // make sure that it points to the minimum value available in the container
            CHECK_EQ(*it, minMax.at(index)); // check if the values match
            index++; // move to the next value to check
            minTurn = !minTurn; // change turns
        }

        CHECK_FALSE(it != endit); // it reached to the end
        CHECK_THROWS(*it); // *it contains garbage data -> exception
    }
}

/**
 * This Iterator creates a reverse order of the values the container has.\n
 * It reverses the values order by their insertion.\n
 * Reverse order: [1,15,3,7,9] -> [9,7,3,15,1]
 */
TEST_CASE_FIXTURE(allContainers, "Reverse iterator methods")
{
    // this case will check all the operators of int container - {1, 15, 3, 7, 9}
    SUBCASE("operator '++' & operator '*' & operator '!=' tests for an integer container")
    {
        auto it = intContainer.begin_reverse_order(); // it points to the last value
        auto endit = intContainer.end_reverse_order(); // endit points to the end of the container

        const vector<int> arr = intContainer.getValues(); // arr = {1, 15, 3, 7, 9}
        int index = arr.size() - 1; // point to the end of the vector

        for (; it != endit; ++it)
        {
            CHECK_EQ(*it, arr.at(index)); // check if the values match
            index--; // move to the next value in opposite direction
        }

        CHECK_FALSE(it != endit); // it reached to the end
        CHECK_THROWS(*it); // *it contains garbage data -> exception
    }

    // this case will check all the operators of double container - {-1.1, 10.3, 7.2, 3.4, 5.8}
    SUBCASE("operator '++' & operator '*' & operator '!=' tests for a double container")
    {
        auto it = doubleContainer.begin_reverse_order(); // it points to the last value
        auto endit = doubleContainer.end_reverse_order(); // endit points to the end of the container

        const vector<double> arr = doubleContainer.getValues(); // arr = {-1.1, 10.3, 7.2, 3.4, 5.8}
        int index = arr.size() - 1; // point to the end of the vector

        for (; it != endit; ++it)
        {
            CHECK_EQ(*it, arr.at(index)); // check if the values match
            index--; // move to the next value in opposite direction
        }

        CHECK_FALSE(it != endit); // it reached to the end
        CHECK_THROWS(*it); // *it contains garbage data -> exception
    }

    // this case will check all the operators of char container - {'d', 'a', 'G', 'm', 'Z'}
    SUBCASE("operator '++' & operator '*' & operator '!=' tests for a char container")
    {
        auto it = charContainer.begin_reverse_order(); // it points to the last value
        auto endit = charContainer.end_reverse_order(); // endit points to the end of the container

        const vector<char> arr = charContainer.getValues(); // arr = {'d', 'a', 'G', 'm', 'Z'}
        int index = arr.size() - 1; // point to the end of the vector

        for (; it != endit; ++it)
        {
            CHECK_EQ(*it, arr.at(index)); // check if the values match
            index--; // move to the next index in the vector (from last to first)
        }

        CHECK_FALSE(it != endit); // it reached to the end
        CHECK_THROWS(*it); // *it contains garbage data -> exception
    }

    // this case will check all the operators of string container - {"abc", "ABC", "aBc", "deg", "ze"}
    SUBCASE("operator '++' & operator '*' & operator '!=' tests for a string container")
    {
        auto it = stringContainer.begin_reverse_order(); // it points to the first value
        auto endit = stringContainer.end_reverse_order(); // endit points to the end of the container

        const vector<string> arr = stringContainer.getValues(); // arr = {"abc", "ABC", "aBc", "deg", "ze"}
        int index = arr.size() - 1; // point to the end of the vector

        for (; it != endit; ++it)
        {
            CHECK_EQ(*it, arr.at(index)); // check if the values match
            index--; // move to the next value from last to first
        }

        CHECK_FALSE(it != endit); // it reached to the end
        CHECK_THROWS(*it); // *it contains garbage data -> exception
    }
}

/**
 * This Iterator creates the same order by insertion of the values the container has.\n
 * 'Order' order: [1,15,3,7,9] -> [1,15,3,7,9]
 */
TEST_CASE_FIXTURE(allContainers, "Order iterator methods")
{
    // this case will check all the operators of int container - {1, 15, 3, 7, 9}
    SUBCASE("operator '++' & operator '*' & operator '!=' tests for an integer container")
    {
        auto it = intContainer.begin_order(); // it points to the first value
        auto endit = intContainer.end_order(); // endit points to the end of the container

        const vector<int> arr = intContainer.getValues(); // arr = {1, 15, 3, 7, 9}
        int index = 0;

        for (; it != endit; ++it)
        {
            CHECK_EQ(*it, arr.at(index)); // check if the values match
            index++;
        }

        CHECK_FALSE(it != endit); // it reached to the end
        CHECK_THROWS(*it); // *it contains garbage data -> exception
    }

    // this case will check all the operators of double container - {-1.1, 10.3, 7.2, 3.4, 5.8}
    SUBCASE("operator '++' & operator '*' & operator '!=' tests for an double container")
    {
        auto it = doubleContainer.begin_order(); // it points to the first value
        auto endit = doubleContainer.end_order(); // endit points to the end of the container

        const vector<double> arr = doubleContainer.getValues(); // arr = {-1.1, 10.3, 7.2, 3.4, 5.8}
        int index = 0;

        for (; it != endit; ++it)
        {
            CHECK_EQ(*it, arr.at(index)); // check if the values match
            index++;
        }

        CHECK_FALSE(it != endit); // it reached to the end
        CHECK_THROWS(*it); // *it contains garbage data -> exception
    }

    // this case will check all the operators of char container - {'d', 'a', 'G', 'm', 'Z'}
    SUBCASE("operator '++' & operator '*' & operator '!=' tests for a char container")
    {
        auto it = charContainer.begin_order(); // it points to the first value
        auto endit = charContainer.end_order(); // endit points to the end of the container

        const vector<char> arr = charContainer.getValues(); // arr = {'d', 'a', 'G', 'm', 'Z'}
        int index = 0;

        for (; it != endit; ++it)
        {
            CHECK_EQ(*it, arr.at(index)); // check if the values match
            index++; // move to the next index in the vector
        }

        CHECK_FALSE(it != endit); // it reached to the end
        CHECK_THROWS(*it); // *it contains garbage data -> exception
    }

    // this case will check all the operators of string container - {"abc", "ABC", "aBc", "deg", "ze"}
    SUBCASE("operator '++' & operator '*' & operator '!=' tests for a string container")
    {
        auto it = stringContainer.begin_order(); // it points to the first value
        auto endit = stringContainer.end_order(); // endit points to the end of the container

        const vector<string> arr = stringContainer.getValues(); // arr = {"abc", "ABC", "aBc", "deg", "ze"}
        int index = 0;

        for (; it != endit; ++it)
        {
            CHECK_EQ(*it, arr.at(index)); // check if the values match
            index++; // move to the next value
        }

        CHECK_FALSE(it != endit); // it reached to the end
        CHECK_THROWS(*it); // *it contains garbage data -> exception
    }
}

/**
 * This Iterator creates a middle-cross order of the values the container has.\n
 * It starts from the middle of the vector and then prints 1 value from left and 1 value from right
 * until it prints all the values.\n
 * If the amount of values is even - the middle value is the right one (size/2).\n
 * Middle cross order (odd): [1,15,3,7,9] -> [3,15,7,1,9]
 * Middle cross order (even): [1,15,3,7,9,4] -> [7,3,9,15,4,1]
 */
TEST_CASE_FIXTURE(allContainers, "MiddleCross iterator methods")
{
    // this case will check all the operators of int container - {1, 15, 3, 7, 9}
    SUBCASE("operator '++' & operator '*' & operator '!=' tests for an integer container")
    {
        // odd amount of values

        auto it = intContainer.begin_middle_out_order(); // it points to the middle value
        auto endit = intContainer.end_middle_out_order(); // endit points to the end of the container

        // the original container is {1, 15, 3, 7, 9}
        // after middle-cross order -> {3, 15, 7, 1, 9}
        const vector<int> odd = {3, 15, 7, 1, 9}; // this is the expected result
        int index = 0;

        for (; it != endit; ++it)
        {
            CHECK_EQ(*it, odd.at(index)); // check if the values match
            index++;
        }

        CHECK_FALSE(it != endit); // it reached to the end
        CHECK_THROWS(*it); // *it contains garbage data -> exception

        // even amount of values

        intContainer.add(20); // add 20 to make the container size even

        it = intContainer.begin_middle_out_order(); // it points to the middle value
        endit = intContainer.end_middle_out_order(); // endit points to the end of the container

        // this is the original container - {1, 15, 3, 7, 9, 20}
        // after middle-cross order - {7, 3, 9, 15, 20, 1}
        const vector<int> even = {7, 3, 9, 15, 20, 1}; // the expected result
        index = 0;

        for (; it != endit; ++it)
        {
            CHECK_EQ(*it, even.at(index)); // check if the values match
            index++; // move to the next value
        }

        CHECK_FALSE(it != endit); // it reached to the end
        CHECK_THROWS(*it); // *it contains garbage data -> exception
    }

    // this case will check all the operators of double container - {-1.1, 10.3, 7.2, 3.4, 5.8}
    SUBCASE("operator '++' & operator '*' & operator '!=' tests for a double container")
    {
        // odd amount of values

        auto it = doubleContainer.begin_middle_out_order(); // it points to the middle value
        auto endit = doubleContainer.end_middle_out_order(); // endit points to the end of the container

        // this is the original container - {-1.1, 10.3, 7.2, 3.4, 5.8}
        // after middle-cross order - {7.2, 10.3, 3.4, -1.1, 5.8}
        const vector<double> odd = {7.2, 10.3, 3.4, -1.1, 5.8}; // the expected result
        int index = 0;

        for (; it != endit; ++it)
        {
            CHECK_EQ(*it, odd.at(index)); // check if the values match
            index++;
        }

        CHECK_FALSE(it != endit); // it reached to the end
        CHECK_THROWS(*it); // *it contains garbage data -> exception

        // even amount of values

        doubleContainer.add(20.0); // add 20.0 to make the container size even

        it = doubleContainer.begin_middle_out_order(); // it points to the middle value
        endit = doubleContainer.end_middle_out_order(); // endit points to the end of the container

        // this is the original container - {-1.1, 10.3, 7.2, 3.4, 5.8, 20.0}
        // after middle-cross order - {3.4, 7.2, 5.8, 10.3, 20.0, -1.1}
        const vector<double> even = {3.4, 7.2, 5.8, 10.3, 20.0, -1.1}; // the expected result
        index = 0;

        for (; it != endit; ++it)
        {
            CHECK_EQ(*it, even.at(index)); // check if the values match
            index++; // move to the next value
        }

        CHECK_FALSE(it != endit); // it reached to the end
        CHECK_THROWS(*it); // *it contains garbage data -> exception
    }

    // this case will check all the operators of char container - {'d', 'a', 'G', 'm', 'Z'}
    SUBCASE("operator '++' & operator '*' & operator '!=' tests for a char container")
    {
        // odd amount of values

        auto it = charContainer.begin_middle_out_order(); // it points to the middle value
        auto endit = charContainer.end_middle_out_order(); // endit points to the end of the container

        // this is the original container - {'d', 'a', 'G', 'm', 'Z'}
        // after middle-cross order - {'G', 'a', 'm', 'd', 'Z'}
        const vector<char> odd = {'G', 'a', 'm', 'd', 'Z'}; // the expected result
        int index = 0;

        for (; it != endit; ++it)
        {
            CHECK_EQ(*it, odd.at(index)); // check if the values match
            index++; // move to the next index in the vector
        }

        CHECK_FALSE(it != endit); // it reached to the end
        CHECK_THROWS(*it); // *it contains garbage data -> exception

        // even amount of values

        charContainer.add('e'); // add 1 char to make the container size even

        it = charContainer.begin_middle_out_order(); // it points to the middle value
        endit = charContainer.end_middle_out_order(); // endit points to the end of the container

        // this is the original container - {'d', 'a', 'G', 'm', 'Z', 'e'}
        // after middle-cross order - {'m', 'G', 'Z', 'a', 'e', 'd'}
        const vector<char> even = {'m', 'G', 'Z', 'a', 'e', 'd'}; // the expected result
        index = 0;

        for (; it != endit; ++it)
        {
            CHECK_EQ(*it, even.at(index)); // check if the values match
            index++; // move to the next value
        }

        CHECK_FALSE(it != endit); // it reached to the end
        CHECK_THROWS(*it); // *it contains garbage data -> exception
    }

    // this case will check all the operators of string container - {"abc", "ABC", "aBc", "deg", "ze"}
    SUBCASE("operator '++' & operator '*' & operator '!=' tests for a string container")
    {
        // odd amount of values

        auto it = stringContainer.begin_middle_out_order(); // it points to the middle value
        auto endit = stringContainer.end_middle_out_order(); // endit points to the end of the container

        // this is the original container - {"abc", "ABC", "aBc", "deg", "ze"}
        // after middle-cross order - {"aBc", "ABC", "deg", "abc", "ze"}
        const vector<string> arr = {"aBc", "ABC", "deg", "abc", "ze"}; // the expected result
        int index = 0;

        for (; it != endit; ++it)
        {
            CHECK_EQ(*it, arr.at(index)); // check if the values match
            index++; // move to the next value
        }

        CHECK_FALSE(it != endit); // it reached to the end
        CHECK_THROWS(*it); // *it contains garbage data -> exception

        // even amount of values

        stringContainer.add("even"); // add 1 string to make the container size even

        it = stringContainer.begin_middle_out_order(); // it points to the middle value
        endit = stringContainer.end_middle_out_order(); // endit points to the end of the container

        // this is the original container - {"abc", "ABC", "aBc", "deg", "ze", "even"}
        // after middle-cross order - {"deg", "aBc", "ze", "ABC", "even", "abc"}
        const vector<string> even = {"deg", "aBc", "ze", "ABC", "even", "abc"}; // the expected result
        index = 0;

        for (; it != endit; ++it)
        {
            CHECK_EQ(*it, even.at(index)); // check if the values match
            index++; // move to the next value
        }

        CHECK_FALSE(it != endit); // it reached to the end
        CHECK_THROWS(*it); // *it contains garbage data -> exception
    }
}
