#ifndef MO54_TD_CPP_STORAGE_TYPE_H
#define MO54_TD_CPP_STORAGE_TYPE_H

#include "data_list.h"
#include "data_table.h"

//this class is for storage_type
class storage_type {
public:
    virtual ~storage_type()= default;
    // Input methods
    virtual void from_text(const std::string &source)=0;
    virtual void from_binary(const std::string &source)=0;

    // Output methods
    virtual void to_text(const std::string &destination)=0;
    virtual void to_binary(const std::string &destination)=0;
    virtual void print_data()const=0;

    // Computation (return new instances of data_table)
    virtual void moving_average(size_t window_width)=0;
    virtual void sort_table(bool ascending)=0;
    virtual void average()=0; // returns a data_table with only one value
    virtual void table_sum()=0; // returns a data_table with only one value
    virtual void table_count()=0; // returns a data_table with only one value
};

class list_storage : public storage_type {
    data_list data;
public:
    ~list_storage() override= default;
    // Input methods
    void from_text(const std::string &source) override;
    void from_binary(const std::string &source) override;

    // Output methods
    void to_text(const std::string &destination) override;
    void to_binary(const std::string &destination) override;
    void print_data()const override;

    // Computation (return new instances of data_table)
    void moving_average(size_t window_width) override;
    void sort_table(bool ascending) override;
    void average() override; // returns a data_table with only one value
    void table_sum() override; // returns a data_table with only one value
    void table_count() override; // returns a data_table with only one value
};

class vector_storage : public storage_type {
    data_table data;
public:
//    ~vector_storage() override= default;

    // Input methods
    void from_text(const std::string &source) override;
    void from_binary(const std::string &source) override;

    // Output methods
    void to_text(const std::string &destination) override;
    void to_binary(const std::string &destination) override;
    void print_data()const override;

    // Computation (return new instances of data_table)
    void moving_average(size_t window_width) override;
    void sort_table(bool ascending) override;
    void average() override; // returns a data_table with only one value
    void table_sum() override; // returns a data_table with only one value
    void table_count() override; // returns a data_table with only one value
};



#endif //MO54_TD_CPP_STORAGE_TYPE_H
