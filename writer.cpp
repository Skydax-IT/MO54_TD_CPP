//
// writer.cpp
// Output methods
// created by yuan.cao@utbm.fr on 10/06/2022
//
#include "writer.h"

void text_writer::write(storage_type *storage) {
    storage->to_text(destination);
}

void bin_writer::write(storage_type *storage) {
    storage->to_binary(destination);
}

void screen_writer::write(storage_type *storage) {
    storage->print_data();
}
