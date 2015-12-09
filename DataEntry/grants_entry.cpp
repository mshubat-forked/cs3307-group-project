/*
 * Header File: grants_entry.cpp
 * --------------------------------
 * + Defines the declarations for functions
 *   for mainwindow.cpp
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

// + Sets a integer ed to end day
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
int grants_entry::get_emonth()
{
    return end_month;
}
void grants_entry::set_eyear(int ey)
{
    end_year=ey;
}
int grants_entry::get_eyear()
{
    return end_year;
}
void grants_entry::set_ftype(string ft)
{
    funding_type=ft;
    
}
string grants_entry::get_ftype()
{
    return funding_type;
}
void grants_entry::set_status(string s)
{
    status=s;
}
string grants_entry::get_status()
{
    return status;
}
void grants_entry::set_preview(bool p)
{
    peer_review=p;
}
bool grants_entry::get_preview()
{
    return peer_review;
}
void grants_entry::set_ind_grant(bool ig)
{
    industry_grant=ig;
}
bool grants_entry::get_ind_grant()
{
    return industry_grant;
}
void grants_entry::set_role(string r)
{
    role=r;
}
string grants_entry::get_role()
{
    return role;
}
void grants_entry::set_title(string t)
{
    title=t;
}
string grants_entry::get_title()
{
    return title;
}
void grants_entry::set_short_title(string st)
{
    short_title=st;
}
string grants_entry::get_short_title()
{
    return short_title;
}
void grants_entry::set_appl_summary(string as)
{
    appl_summary=as;
}
string grants_entry::get_appl_summary()
{
    return appl_summary;
}
void grants_entry::set_grant_purpose(string gp)
{
    grant_purpose=gp;
}
string grants_entry::get_grant_purpose()
{
    return grant_purpose;
}
void grants_entry::set_area(string a)
{
    area=a;
}
string grants_entry::get_area()
{
    return area;
}
void grants_entry::set_investigator(string i)
{
    investigator=i;
}
string grants_entry::get_investigator()
{
    return investigator;
}
void grants_entry::set_co_investigator(string ci)
{
    co_investigator=ci;
}
string grants_entry::get_co_investigator()
{
    return co_investigator;
}
void grants_entry::set_grant_num(int gn)
{
    grant_num=gn;
}
int grants_entry::get_grant_num()
{
    return grant_num;
}
void grants_entry::set_prorated(float p)
{
    prorated=p;
}
float grants_entry::get_prorated()
{
    return prorated;
}
void grants_entry::set_admin_by(string a)
{
    admin_by=a;
}
string grants_entry::get_admin_by()
{
    return admin_by;
}
void grants_entry::set_funding_source(string fs)
{
    funding_source=fs;
}
string grants_entry::get_funding_source()
{
    return funding_source;
}
void grants_entry::set_project(string p)
{
    project=p;
}
string grants_entry::get_project()
{
    return project;
}
void grants_entry::set_currency(string c)
{
    currency=c;
}
string grants_entry::get_currency()
{
    return currency;
}
void grants_entry::set_rec_amt(int ra)
{
    rec_amt=ra;
}
int grants_entry::get_rec_amt()
{
    return rec_amt;
}
void grants_entry::set_total_amount(int ta)
{
    total_amt=ta;
}
int grants_entry::get_total_amount()
{
    return total_amt;
}
void grants_entry::set_rpt(int r)
{
    rpt=r;
}
int grants_entry::get_rpt()
{
    return rpt;
}
void grants_entry::set_weekly_hours(int wh)
{
    weekly_hours=wh;
}
int grants_entry::get_weekly_hours()
{
    return weekly_hours;
}
void grants_entry::set_rnw(int r)
{
    rnw=r;
}
int grants_entry::get_rnw()
{
    return rnw;
}
void grants_entry::set_education(bool e)
{
    education=e;
}
bool grants_entry::get_education()
{
    return education;
}
void grants_entry::set_duplicate(bool d)
{
    duplicate=d;
}
bool grants_entry::get_duplicate()
{
    return duplicate;
}
void grants_entry::set_other(string o)
{
    other=o;
}
string grants_entry::get_other()
{
    return other;
}
void grants_entry::set_acad_year(string ay)
{
    acad_year=ay;
}
string grants_entry::get_acad_year()
{
    return acad_year;
}
void grants_entry::set_member_share(int ms)
{
    member_share=ms;
}
int grants_entry::get_member_share()
{
    return member_share;
}
void grants_entry::set_monetary(int m)
{
    monetary=m;
}
int grants_entry::get_monetary()
{
    return monetary;
}
void grants_entry::set_personell_paid(int pp)
{
    personell_paid=pp;
}
int grants_entry::get_personell_paid()
{
    return personell_paid;
}
