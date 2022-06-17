#include <iostream>
#include "resource_manager.h"

storage_type* resource_manager::make_storage(const std::string& type) {
    if(type=="LIST"){
        ls=list_storage();
        storage_type* storage=&ls;
        return storage;
    }
    else if(type=="VECTOR"){
        vs=vector_storage();
        storage_type* storage=&vs;
        return storage;
    } else{
        std::cerr<<"No type of storage!"<<std::endl;
        return nullptr;
    }
}

loader *resource_manager::make_reader(const std::string &type,std::string path_to_file) {
    if(type=="TEXT"){
        tl=text_loader(std::move(path_to_file));
        loader* reader=&tl;
        return reader;
    }
    else if(type=="BIN"){
        bl=bin_loader(std::move(path_to_file));
        loader* reader=&bl;
        return reader;
    }else{
        std::cerr<<"No type of reader!"<<std::endl;
        return nullptr;
    }
}

calculation *resource_manager::make_calculation(const std::string &type, size_t window_width) {
    if(type=="MAVG"){
        ma= moving_average(window_width);
        calculation * out=&ma;
        return out;
    }else if(type=="SORT"){
        st= sort_table(window_width);
        calculation * out=&st;
        return out;
    }else{
        std::cerr<<"No type of calculation!"<<std::endl;
        return nullptr;
    }
}

calculation *resource_manager::make_calculation(const std::string &type) {
    if(type=="AVG"){
        avg= average();
        calculation * out=&avg;
        return out;
    }
    else if(type=="SUM"){
        ts= table_sum();
        calculation * out=&ts;
        return out;
    }
    else if(type=="COUNT"){
        tc= table_count();
        calculation * out=&tc;
        return out;
    }
    else{
        std::cerr<<"No type of calculation!"<<std::endl;
        return nullptr;
    }


}

writer *resource_manager::make_writer(const std::string &type, const std::string& destination) {
    if(type=="TEXT"){
        tw=text_writer(destination);
        writer* out=&tw;
        return out;
    }
    else if(type=="BIN"){
        bw=bin_writer(destination);
        writer* out=&bw;
        return out;
    }
    else{
        std::cerr<<"No type of writer!"<<std::endl;
        return nullptr;
    }
}

writer *resource_manager::make_writer(const std::string &type) {
    if(type=="SCREEN"){
        sw=screen_writer();
        writer* out=&sw;
        return out;
    }
    else{
        std::cerr<<"No type of writer!"<<std::endl;
        return nullptr;
    }
}
