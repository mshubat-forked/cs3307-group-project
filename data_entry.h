//
//  data_entry.h
//  cs3307-Project
//
//

#ifndef __data_entry__
#define __data_entry__

#include <stdio.h>
#include <string>
using namespace std;

class data_entry
{
protected:
    int record;
    string lm_user;
    string lm_date;
    int ID;
    string member_name;
    string primary_domain;
    bool include;

public:
    data_entry * next;

    void set_record(int);
    int get_record();
    void set_user(string);
    string get_user();
    void set_date(string);
    string get_date();
    void set_ID(int);
    int get_ID();
    void set_member(string);
    string get_member();
    void set_domain(string);
    string get_domain();
    void set_include(bool);
    bool get_include();
    

};


#endif /* defined(__test__data_entry__) */
