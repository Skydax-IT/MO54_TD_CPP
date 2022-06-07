//
// calculation.h
//
// created by yonghui on 06/07/2022
//
#include "calculation.h"
#include <fstream>
#include <exception>
#include <array>
#include <iostream>
#include <algorithm>

using namespace std;

//data_list
data_list list_calculation::moving_average(size_t window_width) {
    data_list result;
    if (window_width < this->datalist._values.size()) {
        double current_sum = 0.0;
        for (size_t i=0; i<window_width; ++i) {
            current_sum += datalist._values.get_value(i);
        }
        result._values.add_value(current_sum/window_width);
        for (size_t i=0; i+window_width<datalist._values.size(); ++i) {
            current_sum -= datalist._values.get_value(i);
            current_sum += datalist._values.get_value(i+window_width);
            result._values.add_value(current_sum/window_width);
        }
    }
    return result;
}

data_list list_calculation::sort_table(bool ascending) {
    data_list result{datalist};
    result._values.sort_list(ascending);
    return result;
}

data_list list_calculation::average() {
    data_list result;
    data_list sum_table = table_sum();
    result._values.add_value(sum_table._values.get_value(0) / datalist._values.size());
    return result;
}

data_list list_calculation::table_sum() {
    data_list result;
    double current_sum = 0.0;
    for (size_t i=0; i<datalist._values.size(); ++i) {
        current_sum += datalist._values.get_value(i);
    }
    result._values.add_value(current_sum);
    return result;
}

data_list list_calculation::table_count() {
    data_list result;
    result._values.add_value(static_cast<double>(datalist._values.size()));
    return result;
}

//data_table
data_table table_calculation::moving_average(size_t window_width) {
    data_table result;
    if (window_width < datatable._table.size()) {
        double current_sum = 0.0;
        for (size_t i=0; i<window_width; ++i) {
            current_sum += datatable._table[i];
        }
        result._table.push_back(current_sum/window_width);
        for (size_t i=0; i+window_width<datatable._table.size(); ++i) {
            current_sum -= datatable._table[i];
            current_sum += datatable._table[i+window_width];
            result._table.push_back(current_sum/window_width);
        }
    }
    return result;
}

data_table table_calculation::sort_table(bool ascending) {
    data_table result;
    result._table = datatable._table;
    if (ascending)
        sort(result._table.begin(), result._table.end());
    else
        sort(result._table.begin(), result._table.end(), [](const double &a, const double &b) {
            return a > b;
        });
    return result;
}

data_table table_calculation::average() {
    data_table result;
    data_table sum_table = table_sum();
    result._table.push_back(sum_table._table[0] / datatable._table.size());
    return result;
}

data_table table_calculation::table_sum() {
    data_table result;
    double current_sum = 0.0;
    for (const double &value: datatable._table) {
        current_sum += value;
    }
    result._table.push_back(current_sum);
    return result;
}

data_table table_calculation::table_count() {
    data_table result;
    result._table.push_back(static_cast<double>(datatable._table.size()));
    return result;
}