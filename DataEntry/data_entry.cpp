/*
 * Source File: data_entry.cpp
 * --------------------------------
 * + Defines getter and setter functions for
 *   data entry items
 */

#include "data_entry.h"

data_entry::data_entry(){}

// + Sets a parameter int r to record
void data_entry::set_record(int r)
{
    record=r;
}

// + Gets a record
int data_entry::get_record()
{
    return record;
}

// + Sets a paramater string u to lm_user
void data_entry::set_user(string u)
{
    lm_user=u;
}

// + Gets a user
string data_entry::get_user()
{
    return lm_user;
}

// + Sets parameter string d to lm_date
void data_entry::set_date(string d)
{
    lm_date=d;
}

// + Gets the date
string data_entry::get_date()
{
    return lm_date;
}

// + Sets parameter integer i to ID
void data_entry::set_ID(int i)
{
    ID=i;
}

// + Gets the ID
int data_entry::get_ID()
{
    return ID;
}

// + Sets a parameter string m to member_name
void data_entry::set_member(string m)
{
    member_name=m;
}

// + Gets a member
string data_entry::get_member()
{
    return member_name;
}

// + Sets a parameter d to the primary domain
void data_entry::set_domain(string d)
{
    primary_domain=d;
}

// + Gets the domain
string data_entry::get_domain()
{
    return primary_domain;
}

// + Sets a parameter boolean i to include
void data_entry::set_include(bool i)
{
    include=i;
}

// + Gets an include
bool data_entry::get_include()
{
    return include;
}
