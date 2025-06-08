// dvirbto@gmail.com

#include <iostream>
#include "MyContainer.hpp"

using namespace std;
using namespace Ex4Container;

/**
 * This is the main of Ex4.\n
 * It runs an example of each comparable data type such as int, double, char and string.
 */
int main()
{
    // int container

    vector<int> intV = {7, 15, 6, 1, 2};
    MyContainer<> intContainer(intV);
    cout << intContainer;
    bool first = true; // flag to add ", " after each value

    cout << "Ascending order: [";
    for (auto it = intContainer.begin_ascending_order(); it != intContainer.end_ascending_order(); ++it)
    {
        if (!first)
            cout << ", ";
        cout << *it;
        first = false;
    }
    cout << "]" << endl;

    first = true;
    cout << "Descending order: [";
    for (auto it = intContainer.begin_descending_order(); it != intContainer.end_descending_order(); ++it)
    {
        if (!first)
            cout << ", ";
        cout << *it;
        first = false;
    }
    cout << "]" << endl;

    first = true;
    cout << "Side-cross order: [";
    for (auto it = intContainer.begin_side_cross_order(); it != intContainer.end_side_cross_order(); ++it)
    {
        if (!first)
            cout << ", ";
        cout << *it;
        first = false;
    }
    cout << "]" << endl;

    first = true;
    cout << "Reverse order: [";
    for (auto it = intContainer.begin_reverse_order(); it != intContainer.end_reverse_order(); ++it)
    {
        if (!first)
            cout << ", ";
        cout << *it;
        first = false;
    }
    cout << "]" << endl;

    first = true;
    cout << "Order order: [";
    for (auto it = intContainer.begin_order(); it != intContainer.end_order(); ++it)
    {
        if (!first)
            cout << ", ";
        cout << *it;
        first = false;
    }
    cout << "]" << endl;

    first = true;
    cout << "MiddleOut order: [";
    for (auto it = intContainer.begin_middle_out_order(); it != intContainer.end_middle_out_order(); ++it)
    {
        if (!first)
            cout << ", ";
        cout << *it;
        first = false;
    }
    cout << "]" << endl;

    // double container

    vector<double> doubleV = {-1.1, 10.3, 7.2, 3.4, 5.8};
    MyContainer<double> doubleContainer(doubleV);
    cout << doubleContainer;
    first = true;

    cout << "Ascending order: [";
    for (auto it = doubleContainer.begin_ascending_order(); it != doubleContainer.end_ascending_order(); ++it)
    {
        if (!first)
            cout << ", ";
        cout << *it;
        first = false;
    }
    cout << "]" << endl;

    first = true;
    cout << "Descending order: [";
    for (auto it = doubleContainer.begin_descending_order(); it != doubleContainer.end_descending_order(); ++it)
    {
        if (!first)
            cout << ", ";
        cout << *it;
        first = false;
    }
    cout << "]" << endl;

    first = true;
    cout << "Side-cross order: [";
    for (auto it = doubleContainer.begin_side_cross_order(); it != doubleContainer.end_side_cross_order(); ++it)
    {
        if (!first)
            cout << ", ";
        cout << *it;
        first = false;
    }
    cout << "]" << endl;

    first = true;
    cout << "Reverse order: [";
    for (auto it = doubleContainer.begin_reverse_order(); it != doubleContainer.end_reverse_order(); ++it)
    {
        if (!first)
            cout << ", ";
        cout << *it;
        first = false;
    }
    cout << "]" << endl;

    first = true;
    cout << "Order order: [";
    for (auto it = doubleContainer.begin_order(); it != doubleContainer.end_order(); ++it)
    {
        if (!first)
            cout << ", ";
        cout << *it;
        first = false;
    }
    cout << "]" << endl;

    first = true;
    cout << "MiddleOut order: [";
    for (auto it = doubleContainer.begin_middle_out_order(); it != doubleContainer.end_middle_out_order(); ++it)
    {
        if (!first)
            cout << ", ";
        cout << *it;
        first = false;
    }
    cout << "]" << endl;

    // char container

    vector<char> charV = {'d', 'a', 'G', 'm', 'Z'};
    MyContainer<char> charContainer(charV);
    cout << charContainer;
    first = true;

    cout << "Ascending order: [";
    for (auto it = charContainer.begin_ascending_order(); it != charContainer.end_ascending_order(); ++it)
    {
        if (!first)
            cout << ", ";
        cout << *it;
        first = false;
    }
    cout << "]" << endl;

    first = true;
    cout << "Descending order: [";
    for (auto it = charContainer.begin_descending_order(); it != charContainer.end_descending_order(); ++it)
    {
        if (!first)
            cout << ", ";
        cout << *it;
        first = false;
    }
    cout << "]" << endl;

    first = true;
    cout << "Side-cross order: [";
    for (auto it = charContainer.begin_side_cross_order(); it != charContainer.end_side_cross_order(); ++it)
    {
        if (!first)
            cout << ", ";
        cout << *it;
        first = false;
    }
    cout << "]" << endl;

    first = true;
    cout << "Reverse order: [";
    for (auto it = charContainer.begin_reverse_order(); it != charContainer.end_reverse_order(); ++it)
    {
        if (!first)
            cout << ", ";
        cout << *it;
        first = false;
    }
    cout << "]" << endl;

    first = true;
    cout << "Order order: [";
    for (auto it = charContainer.begin_order(); it != charContainer.end_order(); ++it)
    {
        if (!first)
            cout << ", ";
        cout << *it;
        first = false;
    }
    cout << "]" << endl;

    first = true;
    cout << "MiddleOut order: [";
    for (auto it = charContainer.begin_middle_out_order(); it != charContainer.end_middle_out_order(); ++it)
    {
        if (!first)
            cout << ", ";
        cout << *it;
        first = false;
    }
    cout << "]" << endl;

    // string container

    vector<string> stringV = {"abc", "ABC", "aBc", "deg", "ze"};
    MyContainer<string> stringContainer(stringV);
    cout << stringContainer;
    first = true;

    cout << "Ascending order: [";
    for (auto it = stringContainer.begin_ascending_order(); it != stringContainer.end_ascending_order(); ++it)
    {
        if (!first)
            cout << ", ";
        cout << *it;
        first = false;
    }
    cout << "]" << endl;

    first = true;
    cout << "Descending order: [";
    for (auto it = stringContainer.begin_descending_order(); it != stringContainer.end_descending_order(); ++it)
    {
        if (!first)
            cout << ", ";
        cout << *it;
        first = false;
    }
    cout << "]" << endl;

    first = true;
    cout << "Side-cross order: [";
    for (auto it = stringContainer.begin_side_cross_order(); it != stringContainer.end_side_cross_order(); ++it)
    {
        if (!first)
            cout << ", ";
        cout << *it;
        first = false;
    }
    cout << "]" << endl;

    first = true;
    cout << "Reverse order: [";
    for (auto it = stringContainer.begin_reverse_order(); it != stringContainer.end_reverse_order(); ++it)
    {
        if (!first)
            cout << ", ";
        cout << *it;
        first = false;
    }
    cout << "]" << endl;

    first = true;
    cout << "Order order: [";
    for (auto it = stringContainer.begin_order(); it != stringContainer.end_order(); ++it)
    {
        if (!first)
            cout << ", ";
        cout << *it;
        first = false;
    }
    cout << "]" << endl;

    first = true;
    cout << "MiddleOut order: [";
    for (auto it = stringContainer.begin_middle_out_order(); it != stringContainer.end_middle_out_order(); ++it)
    {
        if (!first)
            cout << ", ";
        cout << *it;
        first = false;
    }
    cout << "]" << endl;

    return 0;
}
