//
// calculation.h
//
// created by yonghui on 06/07/2022
//
#ifndef CALCULATION_H
#define CALCULATION_H

#include "data_list.h"
#include "data_table.h"
#include <vector>
#include <string>

template <typename T>
class calculation
{
public:

    virtual T moving_average(size_t window_width) = 0;
    virtual T sort_table(bool ascending=true) = 0;
    virtual T average() = 0; 
    virtual T table_sum() = 0; 
    virtual T table_count() = 0;

};

class list_calculation:public calculation<data_list>
{
    data_list datalist;
public:
    list_calculation(data_list data);

    data_list moving_average(size_t window_width);
    data_list sort_table(bool ascending=true);
    data_list average(); // returns a data_list with only one value
    data_list table_sum(); // returns a data_list with only one value
    data_list table_count();
};

class table_calculation:public calculation<data_table>
{
    data_table datatable;
public:
    table_calculation(data_table table);

    data_table moving_average(size_t window_width);
    data_table sort_table(bool ascending=true);
    data_table average(); // returns a data_table with only one value
    data_table table_sum(); // returns a data_table with only one value
    data_table table_count(); // returns a data_table with only one value
};
#endif // calculation_H