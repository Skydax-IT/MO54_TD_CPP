#include <iostream>
#include "data_table.h"
#include "data_list.h"
#include "resource_manager.h"
#include "process.h"

using namespace std;

int main() {
//    data_list t;
//    t.from_text("C:\\Users\\86180\\Desktop\\MO54_TD_CPP\\texte.txt");
//    cout << "t:" << endl;
//    t.print_data();
//    //auto t2 = t.sort_table(false);
//    auto t2 = t.moving_average(2);
//    cout << "t2:" << endl;
//    t2.print_data();

    resource_manager mgr=resource_manager();
    process p=process(mgr.make_storage("LIST"),
                      mgr.make_reader("TEXT",R"(C:\Users\86180\Desktop\MO54_TD_CPP\texte.txt)"),
                      mgr.make_calculation("MAVG",2),
                      mgr.make_writer("SCREEN")
    );

    p.execute();

    return 0;
}
