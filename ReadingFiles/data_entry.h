//
//  data_entry.h
//  cs3307-Project
//
//

#ifndef __data_entry__
#define __data_entry__

#include <stdio.h>
#include <string>


class data_entry
{
protected:
    int record;
    std::string lm_user;
    std::string lm_date;
    int ID;
    std::string member_name;
    std::string primary_domain;

public:
    data_entry * next;

    void set_record(int);
    int get_record();
    void set_user(std::string);
    std::string get_user();
    void set_date(std::string);
    std::string get_date();
    void set_ID(int);
    int get_ID();
    void set_member(std::string);
    std::string get_member();
    void set_domain(std::string);
    std::string get_domain();
    

};


#endif /* defined(__test__data_entry__) */
