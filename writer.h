//
// writer.h
// Output methods
// created by yuan.cao@utbm.fr on 10/06/2022
//
#ifndef MO54_TD_CPP_WRITER_H
#define MO54_TD_CPP_WRITER_H

#include <utility>

#include "storage_type.h"

//this class is for writer
class writer {
public:
    virtual ~writer()= default;
    virtual void write(storage_type* storage)=0;
};

class text_writer : public writer{
    std::string destination;
public:
    text_writer()= default;
    explicit text_writer(std::string destination){
        this->destination=std::move(destination);
    }
    void write(storage_type* storage) override;
};

class bin_writer : public writer{
    std::string destination;
public:
    bin_writer()= default;
    explicit bin_writer(std::string destination){
        this->destination=std::move(destination);
    }
    void write(storage_type* storage) override;
};

class screen_writer : public writer{
public:
    void write(storage_type* storage) override;
};

#endif //MO54_TD_CPP_WRITER_H

