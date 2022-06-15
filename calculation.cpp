#include "calculation.h"

void moving_average::compute(storage_type *storage) {
    storage->moving_average(window_width);
}


void sort_table::compute(storage_type *storage) {
    storage->sort_table(ascending);
}

void average::compute(storage_type *storage) {
    storage->average();
}

void table_sum::compute(storage_type *storage) {
    storage->table_sum();
}


void table_count::compute(storage_type *storage) {
    storage->table_count();
}
