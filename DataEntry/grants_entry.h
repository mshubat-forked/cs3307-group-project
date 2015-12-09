/*
 * Header File: grants_entry.h
 * --------------------------------
 * + Defines the declarations for getter and setter functions
 *   for grants_entry.cpp
 */

#ifndef __grants_entry__
#define __grants_entry__

#include <stdio.h>
#include <string>
#include "data_entry.h"
using namespace std;

class grants_entry: public data_entry
{
private:
    int start_day;
    int start_month;
    int start_year;
    int end_day;
    int end_month;
    int end_year;
    string funding_type;
    string status;
    bool peer_review;
    bool industry_grant;
    string role;
    string title;
    string short_title;
    string appl_summary;
    string grant_purpose;
    string area;
    string investigator;
    string co_investigator;
    int grant_num;
    float prorated;
    string admin_by;
    string funding_source;
    string project;
    string currency;
    int rec_amt;
    int total_amt;
    int rpt;
    int weekly_hours;
    int rnw;
    bool education;
    bool duplicate;
    string other;
    string acad_year;
    
    //not sure what these actually are (there arent any values in the excel sheet) but i just assumed ints
    int member_share;
    int monetary;
    int personell_paid;
    
public:
    grants_entry();
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
    void set_ftype(string);
    string get_ftype();
    void set_status(string);
    string get_status();
    void set_preview(bool);
    bool get_preview();
    void set_ind_grant(bool);
    bool get_ind_grant();
    void set_role(string);
    string get_role();
    void set_title(string);
    string get_title();
    void set_short_title(string);
    string get_short_title();
    void set_appl_summary(string);
    string get_appl_summary();
    void set_grant_purpose(string);
    string get_grant_purpose();
    void set_area(string);
    string get_area();
    void set_investigator(string);
    string get_investigator();
    void set_co_investigator(string);
    string get_co_investigator();
    void set_grant_num(int);
    int get_grant_num();
    void set_prorated(float);
    float get_prorated();
    void set_admin_by(string);
    string get_admin_by();
    void set_funding_source(string);
    string get_funding_source();
    void set_project(string);
    string get_project();
    void set_currency(string);
    string get_currency();
    void set_rec_amt(int);
    int get_rec_amt();
    void set_total_amount(int);
    int get_total_amount();
    void set_rpt(int);
    int get_rpt();
    void set_weekly_hours(int);
    int get_weekly_hours();
    void set_rnw(int);
    int get_rnw();
    void set_education(bool);
    bool get_education();
    void set_duplicate(bool);
    bool get_duplicate();
    void set_other(string);
    string get_other();
    void set_acad_year(string);
    string get_acad_year();
    void set_member_share(int);
    int get_member_share();
    void set_monetary(int);
    int get_monetary();
    void set_personell_paid(int);
    int get_personell_paid();
    
    
};
#endif /* defined(__grants_entry__) */
