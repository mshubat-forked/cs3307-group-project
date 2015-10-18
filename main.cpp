//
//  main.cpp
//  cs3307-Project
//

#include <iostream>
#include "teaching_entry.h"
#include "data_entry.h"

int main(int argc, const char * argv[]) {

    teaching_entry t;
    t.set_record(1);
    cout<<t.get_record();
    
}
