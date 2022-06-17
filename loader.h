#ifndef MO54_TD_CPP_LOADER_H
#define MO54_TD_CPP_LOADER_H


#include <utility>

#include "storage_type.h"

//this class is for loader
class loader {
public:
    virtual ~loader()= default;
    virtual void load(storage_type* storoge)=0;
};

class text_loader : public loader {
    std::string path_to_file;
public:
    text_loader()= default;
    explicit text_loader(std::string path_to_file){
        this->path_to_file=std::move(path_to_file);
    }
    void load(storage_type* storoge) override;
};

class bin_loader : public loader {
    std::string path_to_file;
public:
    bin_loader()= default;
    explicit bin_loader(std::string path_to_file){
        this->path_to_file=std::move(path_to_file);
    }
    void load(storage_type* storoge) override;
};


#endif //MO54_TD_CPP_LOADER_H
