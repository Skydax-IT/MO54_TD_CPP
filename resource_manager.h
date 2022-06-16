#ifndef MO54_TD_CPP_RESOURCE_MANAGER_H
#define MO54_TD_CPP_RESOURCE_MANAGER_H


#include "storage_type.h"
#include "loader.h"
#include "calculation.h"
#include "writer.h"

//this class is for resource manger, each kind of class will be stored in here
class resource_manager {
    list_storage ls;
    vector_storage vs;
    text_loader tl;
    bin_loader bl;
    moving_average ma;
    sort_table st;
    average avg;
    table_sum ts;
    table_count tc;
    text_writer tw;
    bin_writer bw;
    screen_writer sw;
public:

    storage_type* make_storage(const std::string& type);
    loader* make_reader(const std::string& type,std::string path_to_file);
    calculation* make_calculation(const std::string& type,size_t window_width);
    calculation* make_calculation(const std::string& type);
    writer* make_writer(const std::string& type,const std::string& destination);
    writer* make_writer(const std::string& type);
};


#endif //MO54_TD_CPP_RESOURCE_MANAGER_H
