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
list_calculation::list_calculation(data_list data) {
    this->datalist = data;
}

data_list list_calculation::moving_average(size_t window_width) {
    this->datalist.moving_average(window_width);
}

data_list list_calculation::sort_table(bool ascending) {
    this->datalist.sort_table(ascending);
}

data_list list_calculation::average() {
    this->datalist.average();
}

data_list list_calculation::table_sum() {
    this->datalist.table_sum();
}

data_list list_calculation::table_count() {
    this->datalist.table_sum();
}

//data_table
table_calculation::table_calculation(data_table table){
    this->datatable.table_sum();
}

data_table table_calculation::moving_average(size_t window_width) {
    this->datatable.moving_average(window_width);
}

data_table table_calculation::sort_table(bool ascending) {
    this->datatable.sort_table(ascending);
}

data_table table_calculation::average() {
    this->datatable.average();
}

data_table table_calculation::table_sum() {
    this->datatable.table_sum();
}

data_table table_calculation::table_count() {
    this->datatable.table_count();
}