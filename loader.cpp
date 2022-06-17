#include "loader.h"

void text_loader::load(storage_type* storoge) {
    storoge->from_text(path_to_file);
}


void bin_loader::load(storage_type *storoge) {
    storoge->from_binary(path_to_file);
}
