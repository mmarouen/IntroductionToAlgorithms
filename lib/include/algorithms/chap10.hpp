#ifndef CHAP_10_H
#define CHAP_10_H
#include <cmath>
#include "chap2.hpp"

struct Cell{
    float value;
    Cell* prev=nullptr;
    Cell* next=nullptr;
};

struct LinkedList
{
    Cell* head=nullptr;
};

namespace chap10
{
    /**
     * @brief Searches a cell within the linked list containing the given input value
     * 
     * @param list list to search within
     * @param value value to look for
     * @param[out] cell cell to find
     * @return true
     * @return false 
     */
    bool ListSearch(LinkedList list, float value, Cell& cell);

    /**
     * @brief Sets the given cell as head and translates the remaining items to the left
     * 
     * @param list list to modify
     * @param cell cell to set as head
     */
    void ListPrepend(LinkedList& list, Cell& cell);

    /**
     * @brief inserts a cell next after cell current
     * 
     * @param current cell to insert next to
     * @param next cell to insert
     */
    void ListInsert(Cell& current, Cell& next);

    /**
     * @brief delete a given cell from the list
     * 
     * @param list input list to delete from
     * @param cell cell to delete
     */
    void ListDelete(LinkedList& list, Cell& cell);

    /**
     * @brief stores list information in a string variable
     * 
     * @param list input list
     * @return std::string 
     */
    std::string DisplayLists(LinkedList list);

    /**
     * @brief populate a linked list starting from a vector of values
     * 
     * @param input_vals input values vector
     * @return LinkedList 
     */
    LinkedList FillupList(std::vector<float> input_vals);
}

#endif