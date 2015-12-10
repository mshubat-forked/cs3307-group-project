/*
 * Source File: grants_entry.cpp
 * --------------------------------
 * + Defines the declarations for functions
 *   for the class
 */

#include "grants_entry.h"
#include "data_Entry.h"
#include <string>
using namespace std;

// + Constructor for setting up a new grant object
grants_entry::grants_entry()
{
    start_day=0;
    start_month=0;
    start_year=0;
    end_day=0;
    end_month=0;
    end_year=0;
}

// + Sets a integer parameter sd to the start day
void grants_entry::set_sday(int sd)
{
    start_day=sd;
}

// + Get the start date
int grants_entry::get_sday()
{
    return start_day;
}

// + Sets a integer parameter sm to the start month
void grants_entry::set_smonth(int sm)
{
    start_month=sm;
}

// + Gets the start month
int grants_entry::get_smonth()
{
    return start_month;
}

// + Sets a integer paramter sy to start year
void grants_entry::set_syear(int sy)
{
    sy=start_year;
}

// + Gets the start year
int grants_entry::get_syear()
{
    return start_year;
}

// + Sets a integer parameter ed to end day
void grants_entry::set_eday(int ed)
{
    end_day=ed;
}

// + Gets the end day
int grants_entry::get_eday()
{
    return end_day;
}

// + Sets an integer
void grants_entry::set_month(int em)
{
    end_month=em;
}

// + Gets an end month
int grants_entry::get_emonth()
{
    return end_month;
}

// + Sets an integer parameter ey to the end year
void grants_entry::set_eyear(int ey)
{
    end_year=ey;
}

// + Gets an end year
int grants_entry::get_eyear()
{
    return end_year;
}

// + Sets an string parameter ft to funding type
void grants_entry::set_ftype(string ft)
{
    funding_type=ft;
    
}

// + Get a funding type
string grants_entry::get_ftype()
{
    return funding_type;
}

// + Sets a string parameter s to status
void grants_entry::set_status(string s)
{
    status=s;
}

// + Gets a status
string grants_entry::get_status()
{
    return status;
}

// + Sets a parameter p to peer review
void grants_entry::set_preview(bool p)
{
    peer_review=p;
}

// + Gets a peer review value
bool grants_entry::get_preview()
{
    return peer_review;
}

// + Sets a bool parameter ig to an industry grant
void grants_entry::set_ind_grant(bool ig)
{
    industry_grant=ig;
}

// + Gets an industry grant value
bool grants_entry::get_ind_grant()
{
    return industry_grant;
}

// + Sets a string parameter r to role
void grants_entry::set_role(string r)
{
    role=r;
}

// + Gets a role value
string grants_entry::get_role()
{
    return role;
}

// + Sets a string parameter t to title
void grants_entry::set_title(string t)
{
    title=t;
}

// + Gets a title value
string grants_entry::get_title()
{
    return title;
}

// + Sets a string parameter st to a short title field
void grants_entry::set_short_title(string st)
{
    short_title=st;
}

// + Gets a short title value
string grants_entry::get_short_title()
{
    return short_title;
}

// + Sets a string parameter as to an application summary
void grants_entry::set_appl_summary(string as)
{
    appl_summary=as;
}

// + Gets a application summary
string grants_entry::get_appl_summary()
{
    return appl_summary;
}

// + Sets a string parameter gp to a grant purpose
void grants_entry::set_grant_purpose(string gp)
{
    grant_purpose=gp;
}

// + Gets a grant purpose value
string grants_entry::get_grant_purpose()
{
    return grant_purpose;
}

// + Sets a parameter a to area
void grants_entry::set_area(string a)
{
    area=a;
}

// + Get an area value
string grants_entry::get_area()
{
    return area;
}

// + Sets a string parameter i to investigator
void grants_entry::set_investigator(string i)
{
    investigator=i;
}

// + Gets an investigator value
string grants_entry::get_investigator()
{
    return investigator;
}

// + Sets a string parameter ci to co investigator
void grants_entry::set_co_investigator(string ci)
{
    co_investigator=ci;
}

// + Get an investigator value
string grants_entry::get_co_investigator()
{
    return co_investigator;
}

// + Sets an integer parameter gn to a grant number
void grants_entry::set_grant_num(int gn)
{
    grant_num=gn;
}

// + Gets a grant number value
int grants_entry::get_grant_num()
{
    return grant_num;
}

// + Sets a float parameter p to prorated
void grants_entry::set_prorated(float p)
{
    prorated=p;
}

// + Get a prorated value
float grants_entry::get_prorated()
{
    return prorated;
}

// + Sets string parameter a to admin by
void grants_entry::set_admin_by(string a)
{
    admin_by=a;
}

// + Gets an admin by value
string grants_entry::get_admin_by()
{
    return admin_by;
}

// + Sets a string parameter fs to funding source
void grants_entry::set_funding_source(string fs)
{
    funding_source=fs;
}

// + Gets a funding source value
string grants_entry::get_funding_source()
{
    return funding_source;
}

// + Sets a string parameter p to project
void grants_entry::set_project(string p)
{
    project=p;
}

// + Get a project value
string grants_entry::get_project()
{
    return project;
}

// + Sets string parameter c to currency
void grants_entry::set_currency(string c)
{
    currency=c;
}

// + Gets a currency value
string grants_entry::get_currency()
{
    return currency;
}

// + Sets a integer parameter ra to rec_amt
void grants_entry::set_rec_amt(int ra)
{
    rec_amt=ra;
}

// + Gets a value rec_amt
int grants_entry::get_rec_amt()
{
    return rec_amt;
}

// + Sets an integer parameter ta to total_amt
void grants_entry::set_total_amount(int ta)
{
    total_amt=ta;
}

// + Gets a value total_amt
int grants_entry::get_total_amount()
{
    return total_amt;
}

// + Sets a integer parameter r to rpt
void grants_entry::set_rpt(int r)
{
    rpt=r;
}

// + Gets a value rpt
int grants_entry::get_rpt()
{
    return rpt;
}

// + Sets integer parameter wh to weekly hours
void grants_entry::set_weekly_hours(int wh)
{
    weekly_hours=wh;
}

// + Gets a the weekly hours value
int grants_entry::get_weekly_hours()
{
    return weekly_hours;
}

// + Sets a integer parameter r to rnw
void grants_entry::set_rnw(int r)
{
    rnw=r;
}
// + Gets a value rnw
int grants_entry::get_rnw()
{
    return rnw;
}

// + Sets a bool parameter e to education
void grants_entry::set_education(bool e)
{
    education=e;
}

// + Gets an education value
bool grants_entry::get_education()
{
    return education;
}

// + Sets a bool paramter d to duplicate
void grants_entry::set_duplicate(bool d)
{
    duplicate=d;
}

// + Gets a duplicate value
bool grants_entry::get_duplicate()
{
    return duplicate;
}

// + Sets a string paramter o to other
void grants_entry::set_other(string o)
{
    other=o;
}

// + Gets a other value
string grants_entry::get_other()
{
    return other;
}

// + Sets a string paramter ay to acad year
void grants_entry::set_acad_year(string ay)
{
    acad_year=ay;
}

// + Gets a acad_year year
string grants_entry::get_acad_year()
{
    return acad_year;
}

// + Sets a integer parameter ms to member_share
void grants_entry::set_member_share(int ms)
{
    member_share=ms;
}

// + Gets a member_share
int grants_entry::get_member_share()
{
    return member_share;
}

// + Sets a integer parameter m to monetary
void grants_entry::set_monetary(int m)
{
    monetary=m;
}

// + Gets a monetary value
int grants_entry::get_monetary()
{
    return monetary;
}

// + Sets a integer parameter to pp to peronell_paid
void grants_entry::set_personell_paid(int pp)
{
    personell_paid=pp;
}

// + Gets a personell_paid value
int grants_entry::get_personell_paid()
{
    return personell_paid;
}
