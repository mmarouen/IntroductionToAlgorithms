#include "../include/algorithms/chap10.hpp"
#include <stdexcept>

namespace chap10
{
    bool ListSearch(LinkedList list, float value, Cell& x)
    {
        bool found_cell = false;
        if(list.head == nullptr)
        {
            throw(std::runtime_error("List is empty"));
        }
        if(list.head->value == value)
        {
            x = *list.head;
        }
        else if(list.head->next != nullptr)
        {
            while(x.next != nullptr && x.value != value)
            {
                x = *x.next;
            }
        }
        if(x.value == value)
        {
            found_cell = true;
        }
        return found_cell;
    }

    void ListPrepend(LinkedList& list, Cell& cell)
    {
        cell.next = list.head;
        cell.prev = nullptr;
        if(list.head != nullptr)
        {
            list.head->prev = &cell;
        }
        list.head = &cell;
    }

    void ListInsert(Cell& current, Cell& next)
    {
        next.prev = &current;
        next.next = current.next;
        if(current.next != nullptr)
        {
            current.next->prev = &next;
        }
        current.next = &next;
    }

    void ListDelete(LinkedList& list, Cell& cell)
    {
        Cell tmp, prev, next;
        if(list.head == nullptr)
        {
            throw(std::runtime_error("List is empty"));
        }
        if(ListSearch(list, cell.value, tmp))
        {
            if(cell.prev != nullptr)
            {
                cell.prev->next = cell.next;
            }
            else
            { // cell is head and next exists
                list.head = &next;
            }
            if(cell.next != nullptr)
            {
                cell.next->prev = cell.prev;
            }
        }
    }

    std::string DisplayLists(LinkedList list)
    {
        if(list.head == nullptr)
        {
            throw(std::runtime_error("List is empty"));
        }
        Cell*  current_cell_ptr = list.head;
        std::string msg = "Cell " + std::to_string(current_cell_ptr->value);
        while(current_cell_ptr->next != nullptr)
        {
            current_cell_ptr = current_cell_ptr->next;
            msg +=  " --> " + std::to_string(current_cell_ptr->value);
        }
        return msg;
    }

    LinkedList FillupList(std::vector<float> input_vals)
    {
        LinkedList list;
        Cell* current_cell = new Cell;
        current_cell->value = input_vals[0];
        list.head = current_cell;
        for(int i = 1; i < input_vals.size(); i++)
        {
            Cell* cell = new Cell;
            cell->value = input_vals[i];
            cell->prev = current_cell;
            current_cell->next = cell;
            current_cell = cell;
        }
        return list;
    }
}