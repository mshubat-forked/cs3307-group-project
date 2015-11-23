//
//  publication_entry.cpp
//  3307
//

#include "publication_entry.h"

publication_entry::publication_entry()
{
    status_month=0;
    status_day=0;
    status_year=0;
}
void publication_entry::set_publication_status(string ps)
{
    publication_status=ps;
}
int publication_entry::get_pubmed_article()
{
    return pubmed_article;
}
void publication_entry::set_pubmed_article(int pa)
{
    pubmed_article=pa;
}

string publication_entry::get_publication_status()
{
    return publication_status;
}
void publication_entry::set_type(string t)
{
    type=t;
    
}
string publication_entry::get_type()
{
    return type;
}
void publication_entry::set_area(string a)
{
    area=a;
}
string publication_entry::get_area()
{   
    return area;
}
void publication_entry::set_status_month(int m)
{
    status_month=m;
}
int publication_entry::get_status_month()
{
    return status_month;
}
void publication_entry::set_status_year(int y)
{
    status_year=y;
}
int publication_entry::get_status_year()
{
    return status_year;
}
void publication_entry::set_status_day(int d)
{
    status_day=d;
}
int publication_entry::get_status_day()
{
    return status_day;
}
void publication_entry::set_role(string r)
{
    role=r;
}
string publication_entry::get_role()
{
    return role;
}
void publication_entry::set_peer_reviewed(bool pr)
{
    peer_reviewed=pr;
}
bool publication_entry::get_peer_reviewed()
{
    return peer_reviewed;
}
void publication_entry::set_contributors(int c)
{
    contributors=c;
}
int publication_entry::get_contributors()
{
    return contributors;
}
void publication_entry::set_author_num(int n)
{
    author_num=n;
}
int publication_entry::get_author_num()
{
    return author_num;
}
void publication_entry::set_journal(string j)
{
    journal=j;
}
string publication_entry::get_journal()
{
    return journal;
}
void publication_entry::set_volume(int v)
{
    volume=v;
}
int publication_entry::get_volume()
{
    return volume;
}
void publication_entry::set_issue(int i)
{
    issue=i;
}
int publication_entry::get_issue()
{
    return issue;
}
void publication_entry::set_page_range(string pr)
{
    page_range=pr;
}
string publication_entry::get_page_range()
{
    return page_range;
}
void publication_entry::set_DOI(string doi)
{
    DOI=doi;
}
string publication_entry::get_DOI()
{
    return DOI;
}
void publication_entry::set_website(string w)
{
    website=w;
}
string publication_entry::get_website()
{
    return website;
}
void publication_entry::set_citations(int c)
{
    citations=c;
}
int publication_entry::get_citations()
{
    return citations;
}
void publication_entry::set_journal_impact_factor(int jif)
{
    journal_impact_factor=jif;
}
int publication_entry::get_journal_impact_factor()
{
    return journal_impact_factor;
}
void publication_entry::set_international(string i)
{
    international=i;
}
string publication_entry::get_international()
{
    return international;
}
void publication_entry::set_publication_country(string pc)
{
    publication_country=pc;
}
string publication_entry::get_publication_country()
{
    return publication_country;
}
void publication_entry::set_publication_province(string pp)
{
    publication_province=pp;
}
string publication_entry::get_publication_province()
{
    return publication_province;
}
void publication_entry::set_publication_city(string pci)
{
    publication_city=pci;
}
string publication_entry::get_publication_city()
{
    return publication_city;
}
void publication_entry::set_publisher(string p)
{
    publisher=p;
}
string publication_entry::get_publisher()
{
    return publisher;
}
void publication_entry::set_contribution_level(string cl)
{
    contribution_level=cl;
}
string publication_entry::get_contribution_level()
{
    return contribution_level;
}
void publication_entry::set_is_presentation(bool p)
{
    is_presentation=p;
}
bool publication_entry::get_is_presentation()
{
    return is_presentation;
}
void publication_entry::set_impact(string i)
{
    impact=i;
}
string publication_entry::get_impact()
{
    return impact;
}
void publication_entry::set_open_access(bool oa)
{
    open_access=oa;
}
bool publication_entry::get_open_access()
{
    return open_access;
}
void publication_entry::set_personal_renumeration(string pr)
{
    personal_renumeration=pr;
}
string publication_entry::get_personal_renumeration()
{
    return personal_renumeration;
}
void publication_entry::set_trainee(bool t)
{
    trainee=t;
}
bool publication_entry::get_trainee()
{
    return trainee;
}
void publication_entry::set_trainee_details(string td)
{
    trainee_details=td;
}
string publication_entry::get_trainee_details()
{
    return trainee_details;
}
void publication_entry::set_most_significant_publication(bool sp)
{
    most_significant_publication=sp;
}
bool publication_entry::get_most_significant_publication()
{
    return most_significant_publication;
}
void publication_entry::set_most_significant_details(string sd)
{
    most_significant_details=sd;
}
string publication_entry::get_most_significant_details()
{
    return most_significant_details;
}
void publication_entry::set_education_publication(bool ep)
{
    education_publication=ep;
}
bool publication_entry::get_education_publication()
{
    return education_publication;
}
void publication_entry::set_other_details(string od)
{
    other_details=od;
}
string publication_entry::get_other_details()
{
    return other_details;
}
void publication_entry::set_authors(string a)
{
    authors=a;
}
string publication_entry::get_authors()
{
    return authors;
}
void publication_entry::set_title(string t)
{
    title=t;
}
string publication_entry::get_title()
{
    return title;
}
void publication_entry::set_rest_of_citation(string roc)
{
    rest_of_citation=roc;
}
string publication_entry::get_rest_of_citation()
{
    return rest_of_citation;
}
void publication_entry::set_isbnissn(string isbn)
{
    isbnissn=isbn;
}
string publication_entry::get_isbnissn()
{
    return isbnissn;
}
void publication_entry::set_funding_ref_no(int rno)
{
    funding_ref_no=rno;
}
int publication_entry::get_funding_ref_no()
{
    return funding_ref_no;
}







