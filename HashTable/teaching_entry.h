//
//  teaching_entry.h
//  cs3307-Project
//
//

#ifndef __teaching_entry__
#define __teaching_entry__

#include "data_entry.h"


class teaching_entry: public data_entry
{
    
private:
    
    //it looks like some of the start/end dates consist of just the month and day
    //some consist of the day/month/year, some consist of only a year
    //since its so inconsistent I figured I'd create a separate variable for each part of the date
    //and if we didn't have the data for something it would just be initialized to 0 (which i do in the cpp file)
    
    int start_day;
    int start_month;
    int start_year;
    int end_day;
    int end_month;
    int end_year;
    
    std::string program;
    std::string course_type;
    std::string course;
    std::string geo_scope;
    std::string institution;
    std::string faculty;
    std::string department;
    std::string division;
    std::string location;
    int hours_per_session;
    int number_of_sessons;
    std::string faculty_comments;
    int trainees;
    std::string student_names;
    bool init_lecture;
    bool fac_dev;
    bool stipend;
    std::string comments;
    std::string other_details;
    double total_hours;
    
public:
    
    teaching_entry();
    void set_sday(int);
    int get_sday();
    void set_smonth(int);
    int get_smonth();
    void set_syear(int);
    int get_syear();
    void set_eday(int);
    int get_eday();
    void set_month(int);
    int get_emonth();
    void set_eyear(int);
    int get_eyear();
    void set_program(std::string);
    std::string get_program();
    void set_course_type(std::string);
    std::string get_course_type();
    void set_course(std::string);
    std::string get_course();
    void set_gscope(std::string);
    std::string get_gscope();
    void set_institution(std::string);
    std::string get_institution();
    void set_faculty(std::string);
    std::string get_faculty();
    void set_dept(std::string);
    std::string get_dept();
    void set_division(std::string);
    std::string get_divison();
    void set_location(std::string);
    std::string get_location();
    int get_num_sessions();
    void set_num_sessions(int);
    int get_session_hours();
    void set_session_hours(int);
    int get_trainees();
    void set_trainees(int);
    void set_faculty_comments(std::string);
    std::string get_faculty_comments();
    std::string get_student_names();
    void set_student_names(std::string);
    bool get_init_lecture();
    void set_init_lecture(bool);
    bool get_fac_dev();
    void set_fac_dec(bool);
    bool get_stipend();
    void set_stipend(bool);
    std::string get_comments();
    void set_comments(std::string);
    void set_other_details(std::string);
    std::string get_other_details();
    double get_total_hours();
    void set_total_hours(double);
    
    
    
};



#endif /* defined(__test__teaching_entry__) */
