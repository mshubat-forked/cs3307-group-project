//
//  main.cpp
//  3307
//
//

#include <iostream>
#include "teaching_entry.h"

int main(int argc, const char * argv[]) {
    
    teaching_entry t;
    
    t.set_comments("madhavi's pretty cool");
    cout<<t.get_comments();
    

    return 0;
}
