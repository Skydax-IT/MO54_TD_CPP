#ifndef MO54_TD_CPP_CALCULATION_H
#define MO54_TD_CPP_CALCULATION_H


#include "storage_type.h"

//this class is for calculation
class calculation {
public:
    virtual ~calculation()= default;
    virtual void compute(storage_type* storage)=0;
};

class moving_average : public calculation {
    size_t window_width{};
public:
    moving_average()= default;
    explicit moving_average(size_t window_width){
        this->window_width=window_width;
    }
    void compute(storage_type* storage) override;
};

class sort_table : public calculation {
    bool ascending{};
public:
    sort_table()= default;
    explicit sort_table(bool ascending){
        this->ascending=ascending;
    }
    void compute(storage_type* storage) override;
};

class average : public calculation {
public:
    void compute(storage_type* storage) override;
};

class table_sum : public calculation {
public:
    void compute(storage_type* storage) override;
};

class table_count : public calculation {
public:
    void compute(storage_type* storage) override;
};


#endif //MO54_TD_CPP_CALCULATION_H
