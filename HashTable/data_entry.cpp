//
//  data_entry.cpp
//  cs3307-Project
//

#include "data_entry.h"


void data_entry::set_record(int r)
{
    record=r;
}
int data_entry::get_record()
{
    return record;
}
void data_entry::set_user(std::string u)
{
    lm_user=u;
}
std::string data_entry::get_user()
{
    return lm_user;
}
void data_entry::set_date(std::string d)
{
    lm_date=d;
}
std::string data_entry::get_date()
{
    return lm_date;
}
void data_entry::set_ID(int i)
{
    ID=i;
}
int data_entry::get_ID()
{
    return ID;
}
void data_entry::set_member(std::string m)
{
    member_name=m;
}
std::string data_entry::get_member()
{
    return member_name;
}
void data_entry::set_domain(std::string d)
{
    primary_domain=d;
}
std::string data_entry::get_domain()
{
    return primary_domain;
}
