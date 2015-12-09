/*
 * Source File: data_entry.cpp
 * --------------------------------
 * + Defines a source file that handles a users input for display
 *   a chosen graph
 */

#include "data_entry.h"


data_entry::data_entry()
{
    
}

void data_entry::set_record(int r)
{
    record=r;
}
int data_entry::get_record()
{
    return record;
}
void data_entry::set_user(string u)
{
    lm_user=u;
}
string data_entry::get_user()
{
    return lm_user;
}
void data_entry::set_date(string d)
{
    lm_date=d;
}
string data_entry::get_date()
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
void data_entry::set_member(string m)
{
    member_name=m;
}
string data_entry::get_member()
{
    return member_name;
}
void data_entry::set_domain(string d)
{
    primary_domain=d;
}
string data_entry::get_domain()
{
    return primary_domain;
}
void data_entry::set_include(bool i)
{
    include=i;
}
bool data_entry::get_include()
{
    return include;
}
