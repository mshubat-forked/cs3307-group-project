/*
 * Source File: teaching_entry.cpp
 * --------------------------------
 * + Defines the declarations for functions
 *   for teaching_entry.cpp
 */

#include "teaching_entry.h"
#include <string>
using namespace std;

// + Constructor for teaching_entry object
teaching_entry::teaching_entry()
{
    start_day=0;
    start_month=0;
    start_year=0;
    end_day=0;
    end_month=0;
    end_year=0;
}

// + Sets a integer parameter sd to start_day
void teaching_entry::set_sday(int sd)
{
    start_day=sd;
}

// + Gets a start_day value
int teaching_entry::get_sday()
{
    return start_day;
}

// + Sets a integer parameter sm to start_month
void teaching_entry::set_smonth(int sm)
{
    start_month=sm;
}

// + Gets a start_month value
int teaching_entry::get_smonth()
{
    return start_month;
}

// + Sets a integer parameter sy to start_year
void teaching_entry::set_syear(int sy)
{
    start_year = sy;
}

// + Gets a start_year
int teaching_entry::get_syear()
{
    return start_year;
}

// + Sets a integer parameter ed to end_day
void teaching_entry::set_eday(int ed)
{
    end_day=ed;
}

// + Gets a end_day value
int teaching_entry::get_eday()
{
    return end_day;
}

// + Sets a integer parameter em to end_month
void teaching_entry::set_month(int em)
{
    end_month=em;
}

// + Gets a end_month value
int teaching_entry::get_emonth()
{
    return end_month;
}

// + Sets a integer parameter ey to end_year
void teaching_entry::set_eyear(int ey)
{
    end_year=ey;
}

// + Gets a end_year value
int teaching_entry::get_eyear()
{
    return end_year;
}

// + Sets a string parameter p to program
void teaching_entry::set_program(string p)
{
    program=p;
}

// + Gets a program value
string teaching_entry::get_program()
{
    return program;
}

// + Sets a string parameter c to course_type
void teaching_entry::set_course_type(string c)
{
    course_type=c;
}

// + Gets a course_type value
string teaching_entry::get_course_type()
{
    return course_type;
}

// + Sets a string parameter c to course_type
void teaching_entry::set_course(string c)
{
    course_type=c;
}

// + Gets a course value
string teaching_entry::get_course()
{
    return course;
}

// + Sets a string parameter g to geo_scope
void teaching_entry::set_gscope(string g)
{
    geo_scope=g;
}

// + Gets a geo_scope value
string teaching_entry::get_gscope()
{
    return geo_scope;
}

// + Sets a string parameter i to institution
void teaching_entry::set_institution(string i)
{
    institution=i;
}

// + Gets a institution value
string teaching_entry::get_institution()
{
    return institution;
}

// + Sets a string parameter f to faculty
void teaching_entry::set_faculty(string f)
{
    faculty=f;
}

// + Gets a faculty value
string teaching_entry::get_faculty()
{
    return faculty;
}

// + Sets a string parameter d to department
void teaching_entry::set_dept(string d)
{
    department=d;
}

// + Gets a department value
string teaching_entry::get_dept()
{
    return department;
}

// + Sets a string parameter d to division
void teaching_entry::set_division(string d)
{
    division=d;
}

// + Gets a division value
string teaching_entry::get_divison()
{
    return division;
}

// + Sets a string parameter l to location
void teaching_entry::set_location(string l)
{
    location=l;
}

// + Gets a lcoation value
string teaching_entry::get_location()
{
    return location;
}

// + Gets a number_of_seasons value
int teaching_entry::get_num_sessions()
{
    return number_of_sessons;
}

// + Sets a integer parameter n to number_of_sessons
void teaching_entry::set_num_sessions(int n)
{
    number_of_sessons=n;
}

// + Gets a hour_per_session value
int teaching_entry::get_session_hours()
{
    return hours_per_session;
}

// + Sets a integer parameter h to hours_per_session
void teaching_entry::set_session_hours(int h)
{
    hours_per_session=h;
}

// + Gets a trainees value
int teaching_entry::get_trainees()
{
    return trainees;
}

// + Sets a integer parameter t to trainees
void teaching_entry::set_trainees(int t)
{
    trainees=t;
}

// + sets a string parameter fc to faculty_comments
void teaching_entry::set_faculty_comments(string fc)
{
    faculty_comments=fc;
}

// + Gets a faculty_comments value
string teaching_entry::get_faculty_comments()
{
    return faculty_comments;
}

// + Gets a student_names value
string teaching_entry::get_student_names()
{
    return student_names;
}

// + Sets a string parameter sn to student_names
void teaching_entry::set_student_names(string sn)
{
    student_names=sn;
}

// + Gets a init_lecture value
bool teaching_entry::get_init_lecture()
{
    return init_lecture;
}

// + Sets a boolean parameter il to init_lecture
void teaching_entry::set_init_lecture(bool il)
{
    init_lecture=il;
}

// + Gets a fac_dev value
bool teaching_entry::get_fac_dev()
{
    return fac_dev;
}

// + Sets boolean parameter fd to fac_dev
void teaching_entry::set_fac_dec(bool fd)
{
    fac_dev=fd;
}

// + Gets a stipend value
bool teaching_entry::get_stipend()
{
    return stipend;
}

// + Sets a boolean parameter s to stipend
void teaching_entry::set_stipend(bool s)
{
    stipend=s;
}

// + Gets a comments value
string teaching_entry::get_comments()
{
    return comments;
}

// + Sets a string parameter c to comments
void teaching_entry::set_comments(string c)
{
    comments=c;
}

// + Sets a string parameter od to other_details
void teaching_entry::set_other_details(string od)
{
    other_details=od;
}

// + Gets a other_details value
string teaching_entry::get_other_details()
{
    return other_details;
}

// + Gets a total_hours value
double teaching_entry::get_total_hours()
{
    return total_hours;
}

// + Sets a double parameter th to total_hours
void teaching_entry::set_total_hours(double th)
{
    total_hours=th;
}
