//
//  presentation_entry.h
//  3307
//

#ifndef ___3307__presentation_entry__
#define ___3307__presentation_entry__

#include <stdio.h>
#include <string>
#include "data_entry.h"

using namespace std;


class presentation_entry: public data_entry
{
    
private:
    int day;
    int month;
    int year;
    string type;
    string area;
    string role;
    string activity_type;
    string geographical_scope;
    string host;
    string country;
    string province;
    string city;
    int attendees;
    string audience;
    int hours;
    int teaching_score;
    string url;
    bool competitive;
    bool education_presentation;
    string remarks;
    string funding_organization;
    string authorship;
    string title;
    string citation;
    int renumeration;
    string details;
    
    
public:
    
    presentation_entry();
    void set_day(int);
    void set_month(int);
    void set_year(int);
    void set_type(string);
    void set_area(string);
    void set_role(string);
    void set_activity_type(string);
    void set_geographical_scope(string);
    void set_host(string);
    void set_country(string);
    void set_province(string);
    void set_city(string);
    void set_attendees(int);
    void set_audience(string);
    void set_hours(int);
    void set_teaching_score(int);
    void set_url(string);
    void set_competitive(bool);
    void set_education_presentation(bool);
    void set_remarks(string);
    void set_funding_organization(string);
    void set_authorship(string);
    void set_title(string);
    void set_citation(string);
    void set_renumeration(int);
    void set_details(string);
    
    int get_day();
    int get_month();
    int get_year();
    string get_type();
    string get_area();
    string get_role();
    string get_activity_type();
    string get_geographical_scope();
    string get_host();
    string get_country();
    string get_province();
    string get_city();
    int get_attendees();
    string get_audience();
    int get_hours();
    int get_teaching_score();
    string get_url();
    bool get_competitive();
    bool get_education_presentation();
    string get_remarks();
    string get_funding_organization();
    string get_authorship();
    string get_title();
    string get_citation();
    int get_renumeration();
    string get_details();
    
    
};


#endif /* defined(___3307__presentation_entry__) */
