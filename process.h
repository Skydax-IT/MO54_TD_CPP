#ifndef MO54_TD_CPP_PROCESS_H
#define MO54_TD_CPP_PROCESS_H

#include <iostream>
#include "storage_type.h"
#include "loader.h"
#include "calculation.h"
#include "writer.h"

//this class is for process
class process {
    storage_type *_storage;
    loader *_loader;
    calculation *_calc;
    writer *_writer;

public:
    process(storage_type *stor, loader *load, calculation *calc, writer *write){
        _storage=stor;
        _loader=load;
        _calc=calc;
        _writer=write;
    }
    ~process()= default;
    void execute();
};


#endif //MO54_TD_CPP_PROCESS_H
