//
//  teaching_entry.cpp
//  cs3307-Project
//
//

#include "teaching_entry.h"
#include <string>
using namespace std;


//i figured because there were so many fields we should just set them all using setter methods
//instead of initializing them when we create the object (that way we could check if an entry object
//has any null values, in which case it might be easier to filter)
//im going to initialize the date values to 0 though because theyre so inconsistent in the excel sheet
teaching_entry::teaching_entry()
{
    start_day=0;
    start_month=0;
    start_year=0;
    end_day=0;
    end_month=0;
    end_year=0;
}

void teaching_entry::set_sday(int sd)
{
    start_day=sd;
}
int teaching_entry::get_sday()
{
    return start_day;
}
void teaching_entry::set_smonth(int sm)
{
    start_month=sm;
}
int teaching_entry::get_smonth()
{
    return start_month;
}
void teaching_entry::set_syear(int sy)
{
    sy=start_year;
}
int teaching_entry::get_syear()
{
    return start_year;
}
void teaching_entry::set_eday(int ed)
{
    end_day=ed;
}
int teaching_entry::get_eday()
{
    return end_day;
}
void teaching_entry::set_month(int em)
{
    end_month=em;
}
int teaching_entry::get_emonth()
{
    return end_month;
}
void teaching_entry::set_eyear(int ey)
{
    end_year=ey;
}
int teaching_entry::get_eyear()
{
    return end_year;
}
void teaching_entry::set_program(string p)
{
    program=p;
}
string teaching_entry::get_program()
{
    return program;
}
void teaching_entry::set_course_type(string c)
{
    course_type=c;
}
string teaching_entry::get_course_type()
{
    return course_type;
}
void teaching_entry::set_course(string c)
{
    course_type=c;
}
string teaching_entry::get_course()
{
    return course;
}
void teaching_entry::set_gscope(string g)
{
    geo_scope=g;
}
string teaching_entry::get_gscope()
{
    return geo_scope;
}
void teaching_entry::set_institution(string i)
{
    institution=i;
}
string teaching_entry::get_institution()
{
    return institution;
}
void teaching_entry::set_faculty(string f)
{
    faculty=f;
}
string teaching_entry::get_faculty()
{
    return faculty;
}
void teaching_entry::set_dept(string d)
{
    department=d;
}
string teaching_entry::get_dept()
{
    return department;
}
void teaching_entry::set_division(string d)
{
    division=d;
}
string teaching_entry::get_divison()
{
    return division;
}
void teaching_entry::set_location(string l)
{
    location=l;
}
string teaching_entry::get_location()
{
    return location;
}
int teaching_entry::get_num_sessions()
{
    return number_of_sessons;
}
void teaching_entry::set_num_sessions(int n)
{
    number_of_sessons=n;
}
int teaching_entry::get_session_hours()
{
    return hours_per_session;
}
void teaching_entry::set_session_hours(int h)
{
    hours_per_session=h;
}
int teaching_entry::get_trainees()
{
    return trainees;
}
void teaching_entry::set_trainees(int t)
{
    trainees=t;
}
void teaching_entry::set_faculty_comments(string fc)
{
    faculty_comments=fc;
}
string teaching_entry::get_faculty_comments()
{
    return faculty_comments;
}
string teaching_entry::get_student_names()
{
    return student_names;
}
void teaching_entry::set_student_names(string sn)
{
    student_names=sn;
}
bool teaching_entry::get_init_lecture()
{
    return init_lecture;
}
void teaching_entry::set_init_lecture(bool il)
{
    init_lecture=il;
}
bool teaching_entry::get_fac_dev()
{
    return fac_dev;
}
void teaching_entry::set_fac_dec(bool fd)
{
    fac_dev=fd;
}
bool teaching_entry::get_stipend()
{
    return stipend;
}
void teaching_entry::set_stipend(bool s)
{
    stipend=s;
}
string teaching_entry::get_comments()
{
    return comments;
}
void teaching_entry::set_comments(string c)
{
    comments=c;
}
void teaching_entry::set_other_details(string od)
{
    other_details=od;
}
string teaching_entry::get_other_details()
{
    return other_details;
}
double teaching_entry::get_total_hours()
{
    return total_hours;
}
void teaching_entry::set_total_hours(double th)
{
    total_hours=th;
}
