#include <string>
#include "storage_type.h"

void list_storage::from_text(const std::string &source) {
    data.from_text(source);
}

void list_storage::from_binary(const std::string &source) {
    data.from_binary(source);
}

void list_storage::to_text(const std::string &destination) {
    data.to_text(destination);
}

void list_storage::to_binary(const std::string &destination) {
    data.to_binary(destination);
}

void list_storage::print_data() const {
    data.print_data();
}

void list_storage::moving_average(size_t window_width) {
    data=data.moving_average(window_width);
}

void list_storage::sort_table(bool ascending) {
    data=data.sort_table(ascending);
}

void list_storage::average() {
    data=data.average();
}

void list_storage::table_sum() {
    data=data.table_sum();
}

void list_storage::table_count() {
    data=data.table_count();
}

void vector_storage::from_text(const std::string &source) {
    data.from_text(source);
}

void vector_storage::from_binary(const std::string &source) {
    data.from_binary(source);
}

void vector_storage::to_text(const std::string &destination) {
    data.to_text(destination);
}

void vector_storage::to_binary(const std::string &destination) {
    data.to_binary(destination);
}

void vector_storage::print_data() const {
    data.print_data();
}

void vector_storage::moving_average(size_t window_width) {
    data=data.moving_average(window_width);
}

void vector_storage::sort_table(bool ascending) {
    data=data.sort_table(ascending);
}

void vector_storage::average() {
    data=data.average();
}

void vector_storage::table_sum() {
    data=data.table_sum();
}

void vector_storage::table_count() {
    data=data.table_count();
}







