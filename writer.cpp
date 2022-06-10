//
// writer.cpp
// Output methods
// created by yuan.cao@utbm.fr on 10/06/2022
//
#include "writer.h"
#include <fstream>
#include <exception>
#include <array>
#include <iostream>
#include <algorithm>

void list_writer::to_text(const std::string &destination) {
    ofstream f{destination};
    if (f.is_open()) {
        for (size_t i=0; i<this->datalist._values.size(); ++i) {
            f << this->datalist._values.get_value(i) << endl;
        }
    }
}

void list_writer::to_binary(const std::string &destination) {
    ofstream f{destination, std::ios::binary};
    if (f.is_open()) {
        for (size_t i=0; i<this->datalist._values.size(); ++i) {
            double val = this->datalist._values.get_value(i);
            f.write(reinterpret_cast<const char *>(&val), sizeof(double));
        }
    } else  {
        throw ios_base::failure("File cannot be opened for writing.");
    }
}

void list_writer::print_data() const {
    for (size_t i=0; i< this->datalist._values.size(); ++i) {
        cout << this->datalist._values.get_value(i) << endl;
    }
}

void table_writer::to_text(const std::string &destination) {
    ofstream f{destination};
    if (f.is_open()) {
        for (const double &value: this->datatable._table) {
            f << value << endl;
        }
    }
}

void table_writer::to_binary(const std::string &destination) {
    ofstream f{destination, std::ios::binary};
    if (f.is_open()) {
        for (const double &value: this->datatable._table) {
            f.write(reinterpret_cast<const char *>(&value), sizeof(double));
        }
    } else  {
        throw ios_base::failure("File cannot be opened for writing.");
    }
}

void table_writer::print_data() const {
    for (const double &value: this->datatable._table) {
        cout << value << endl;
    }
}


