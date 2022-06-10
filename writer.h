//
// writer.h
// Output methods
// created by yuan.cao@utbm.fr on 10/06/2022
//
#ifndef WRITER_H
#define WRITER_H
#include "data_list.h"
#include "data_table.h"
#include <vector>
#include <string>
using namespace std;

template <typename T>
class writer
{
public:

    virtual void to_text(const std::string &destination) = 0;
    virtual void to_binary(const std::string &destination) = 0;
    virtual void print_data()const = 0;
};

class list_writer:public writer<data_list>
{
    data_list datalist;
    string destination;
public:
    list_writer(data_list data, string dest){
        this->datalist = data;
        this->destination = dest;
    }

    void to_text(const std::string &destination);
    void to_binary(const std::string &destination);
    void print_data()const;
};

class table_writer:public writer<data_table>
{
    data_table datatable;
    string destination;

public:
    table_writer(data_table data, string dest){
        this->datatable = data;
        this->destination = dest;
    }

    void to_text(const std::string &destination);
    void to_binary(const std::string &destination);
    void print_data()const;
};
#endif // WRITER_H
