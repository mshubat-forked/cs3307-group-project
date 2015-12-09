/*
 * Source File: publication_entry.cpp
 * --------------------------------
 * + Defines the declarations for functions
 *   for publication_entry.cpp
 */

#include "publication_entry.h"

// + Constructor for publication_entry object
publication_entry::publication_entry()
{
    status_month=0;
    status_day=0;
    status_year=0;
}

// + Sets a string parameter ps to publication_status
void publication_entry::set_publication_status(string ps)
{
    publication_status=ps;
}

// + Get a pubmed_article value
int publication_entry::get_pubmed_article()
{
    return pubmed_article;
}

// + Sets a integer parameter pa to pubmed_article
void publication_entry::set_pubmed_article(int pa)
{
    pubmed_article=pa;
}

// + Gets a publication_status
string publication_entry::get_publication_status()
{
    return publication_status;
}

// + Sets a string parameter t to type
void publication_entry::set_type(string t)
{
    type=t;
}

// + Gets a type value
string publication_entry::get_type()
{
    return type;
}

// + Sets string parameter a to area
void publication_entry::set_area(string a)
{
    area=a;
}

// + Gets a area value
string publication_entry::get_area()
{   
    return area;
}

// + Sets a integer parameter value m to status_month
void publication_entry::set_status_month(int m)
{
    status_month=m;
}

// + Gets a status_month
int publication_entry::get_status_month()
{
    return status_month;
}

// + Sets a integer parameter y to status_year
void publication_entry::set_status_year(int y)
{
    status_year=y;
}

// + Gets status_year value
int publication_entry::get_status_year()
{
    return status_year;
}

// + Sets a integer parameter d to status_day
void publication_entry::set_status_day(int d)
{
    status_day=d;
}

// + Gets status_day value
int publication_entry::get_status_day()
{
    return status_day;
}

// + Sets a string integer r to role
void publication_entry::set_role(string r)
{
    role=r;
}

// + Gets a role value
string publication_entry::get_role()
{
    return role;
}

// + Sets a boolean parameter pr to peer_reviewed
void publication_entry::set_peer_reviewed(bool pr)
{
    peer_reviewed=pr;
}

// + Gets a peer_reviewed value
bool publication_entry::get_peer_reviewed()
{
    return peer_reviewed;
}

// + Sets a integer parameter c to contributors
void publication_entry::set_contributors(int c)
{
    contributors=c;
}

// + Gets a  contributors value
int publication_entry::get_contributors()
{
    return contributors;
}

// + Sets a integer parameter n to author_num
void publication_entry::set_author_num(int n)
{
    author_num=n;
}

// + Gets a author_num value
int publication_entry::get_author_num()
{
    return author_num;
}

// + Sets a string parameter j to journal
void publication_entry::set_journal(string j)
{
    journal=j;
}

// + Gets a journal value
string publication_entry::get_journal()
{
    return journal;
}

// + Sets a integer parameter v to volume
void publication_entry::set_volume(int v)
{
    volume=v;
}

// + Gets a return volume
int publication_entry::get_volume()
{
    return volume;
}

// + Sets a integer parameter to i
void publication_entry::set_issue(int i)
{
    issue=i;
}

// + Gets a issue value
int publication_entry::get_issue()
{
    return issue;
}

// + Sets a string parameter pr to page_range
void publication_entry::set_page_range(string pr)
{
    page_range=pr;
}

// + Gets a page_range value
string publication_entry::get_page_range()
{
    return page_range;
}

// + Sets a string parameter doi to DOI
void publication_entry::set_DOI(string doi)
{
    DOI=doi;
}

// + Gets a DOI value
string publication_entry::get_DOI()
{
    return DOI;
}

// + Sets a string parameter w to website
void publication_entry::set_website(string w)
{
    website=w;
}

// + Gets a website value
string publication_entry::get_website()
{
    return website;
}

// + Sets a integer parameter c to citations
void publication_entry::set_citations(int c)
{
    citations=c;
}

// + Gets a citations value
int publication_entry::get_citations()
{
    return citations;
}

// + Sets a integer jif to journal_impact_factor
void publication_entry::set_journal_impact_factor(int jif)
{
    journal_impact_factor=jif;
}

// + Gets a journal_impact_factor value
int publication_entry::get_journal_impact_factor()
{
    return journal_impact_factor;
}

// + Sets a string parameter i to international
void publication_entry::set_international(string i)
{
    international=i;
}

// + Gets a international value
string publication_entry::get_international()
{
    return international;
}

// + Sets a string parameter pc to publication_country
void publication_entry::set_publication_country(string pc)
{
    publication_country=pc;
}

// + Gets a publication_country value
string publication_entry::get_publication_country()
{
    return publication_country;
}

// + Sets a string parameter pp to publication_province
void publication_entry::set_publication_province(string pp)
{
    publication_province=pp;
}

// + Gets a publication_province
string publication_entry::get_publication_province()
{
    return publication_province;
}

// + Sets a string parameter pci to publication_city
void publication_entry::set_publication_city(string pci)
{
    publication_city=pci;
}

// + Gets a publication_city value
string publication_entry::get_publication_city()
{
    return publication_city;
}

// + Sets a string parameter p to publisher
void publication_entry::set_publisher(string p)
{
    publisher=p;
}

// + Gets a publisher value
string publication_entry::get_publisher()
{
    return publisher;
}

// + Sets a string parameter cl to contribution_level
void publication_entry::set_contribution_level(string cl)
{
    contribution_level=cl;
}

// + Gets a contribution_level value
string publication_entry::get_contribution_level()
{
    return contribution_level;
}

// + Sets a boolean parameter p to is_presentation
void publication_entry::set_is_presentation(bool p)
{
    is_presentation=p;
}

// + Gets a is_presentation value
bool publication_entry::get_is_presentation()
{
    return is_presentation;
}

// + Sets a string parameter i to impact
void publication_entry::set_impact(string i)
{
    impact=i;
}

// + Gets a impact value
string publication_entry::get_impact()
{
    return impact;
}

// + Sets a boolean parameter oa to open_access
void publication_entry::set_open_access(bool oa)
{
    open_access=oa;
}

// + Gets a open_access value
bool publication_entry::get_open_access()
{
    return open_access;
}

// + Sets a string parameter pr to personal_renumeration
void publication_entry::set_personal_renumeration(string pr)
{
    personal_renumeration=pr;
}

// + Gets a personal_renumeration value
string publication_entry::get_personal_renumeration()
{
    return personal_renumeration;
}

// + Sets a boolean parameter t to trainee
void publication_entry::set_trainee(bool t)
{
    trainee=t;
}

// + Gets a trainee value
bool publication_entry::get_trainee()
{
    return trainee;
}

// + Sets a string parameter td to trainee_details
void publication_entry::set_trainee_details(string td)
{
    trainee_details=td;
}

// + Gets a trainee_details value
string publication_entry::get_trainee_details()
{
    return trainee_details;
}

// + Sets a boolean sp parameter to most_significant_publication
void publication_entry::set_most_significant_publication(bool sp)
{
    most_significant_publication=sp;
}

// + Gets a most_significant_publication value
bool publication_entry::get_most_significant_publication()
{
    return most_significant_publication;
}

// + Sets a string parameter sd to most_significant_details
void publication_entry::set_most_significant_details(string sd)
{
    most_significant_details=sd;
}

// + Gets a most_significant_details value
string publication_entry::get_most_significant_details()
{
    return most_significant_details;
}

// + Sets a boolean parameter ep to education_publication
void publication_entry::set_education_publication(bool ep)
{
    education_publication=ep;
}

// + Gets a education_publication value
bool publication_entry::get_education_publication()
{
    return education_publication;
}

// + Sets a string parameter od to other_details
void publication_entry::set_other_details(string od)
{
    other_details=od;
}

// + Gets a other_details value
string publication_entry::get_other_details()
{
    return other_details;
}

// + Sets a string parameter a to authors
void publication_entry::set_authors(string a)
{
    authors=a;
}

// + Gets authors values
string publication_entry::get_authors()
{
    return authors;
}

// + Sets a string parameter t to title
void publication_entry::set_title(string t)
{
    title=t;
}

// + Gets a title value
string publication_entry::get_title()
{
    return title;
}

// + Sets a string parameter roc to rest_of_citation
void publication_entry::set_rest_of_citation(string roc)
{
    rest_of_citation=roc;
}

// + Gets a rest_of_citation
string publication_entry::get_rest_of_citation()
{
    return rest_of_citation;
}

// + Sets a string parameter isbn to isbnissn
void publication_entry::set_isbnissn(string isbn)
{
    isbnissn=isbn;
}

// + Gets a isbnissn value
string publication_entry::get_isbnissn()
{
    return isbnissn;
}

// + Sets a string parameter rno to funding_ref_no
void publication_entry::set_funding_ref_no(int rno)
{
    funding_ref_no=rno;
}

// + Gets a funding_ref_no value
int publication_entry::get_funding_ref_no()
{
    return funding_ref_no;
}







