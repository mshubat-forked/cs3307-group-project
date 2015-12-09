/*
 * Header File: publication_entry.h
 * --------------------------------
 * + Defines the declarations for getter and setter functions
 *   for publication_entry.cpp
 */

#ifndef ___3307__publication_entry__
#define ___3307__publication_entry__

#include <stdio.h>
#include <string>
using namespace std;

class publication_entry
{
private:
    string publication_status;
    int pubmed_article;
    string type;
    string area;
    int status_month;
    int status_year;
    int status_day;
    string role;
    bool peer_reviewed;
    int contributors;
    int author_num;
    string journal;
    int volume;
    int issue;
    string page_range;
    string DOI;
    string website;
    int citations;
    int journal_impact_factor;
    string international;
    string publication_country;
    string publication_province;
    string publication_city;
    string publisher;
    string contribution_level;
    bool is_presentation;
    string impact;
    bool open_access;
    string personal_renumeration;
    bool trainee;
    string trainee_details;
    bool most_significant_publication;
    string most_significant_details;
    bool education_publication;
    string other_details;
    string authors;
    string title;
    string rest_of_citation;
    string isbnissn;
    int funding_ref_no;
    
public:
    publication_entry();
    void set_publication_status(string);
    void set_pubmed_article(int);
    void set_type(string);
    void set_area(string);
    void set_status_month(int);
    void set_status_year(int);
    void set_status_day(int);
    void set_role(string);
    void set_peer_reviewed(bool);
    void set_contributors(int);
    void set_author_num(int);
    void set_journal(string);
    void set_volume(int);
    void set_issue(int);
    void set_page_range(string);
    void set_DOI(string);
    void set_website(string);
    void set_citations(int);
    void set_journal_impact_factor(int);
    void set_international(string);
    void set_publication_country(string);
    void set_publication_province(string);
    void set_publication_city(string);
    void set_publisher(string);
    void set_contribution_level(string);
    void set_is_presentation(bool);
    void set_impact(string);
    void set_open_access(bool);
    void set_personal_renumeration(string);
    void set_trainee(bool);
    void set_trainee_details(string);
    void set_most_significant_publication(bool);
    void set_most_significant_details(string);
    void set_education_publication(bool);
    void set_other_details(string);
    void set_authors(string);
    void set_title(string);
    void set_rest_of_citation(string);
    void set_isbnissn(string);
    void set_funding_ref_no(int);
    
    string get_publication_status();
    int get_pubmed_article();
    string get_type();
    string get_area();
    int get_status_month();
    int get_status_year();
    int get_status_day();
    string get_role();
    bool get_peer_reviewed();
    int get_contributors();
    int get_author_num();
    string get_journal();
    int get_volume();
    int get_issue();
    string get_page_range();
    string get_DOI();
    string get_website();
    int get_citations();
    int get_journal_impact_factor();
    string get_international();
    string get_publication_country();
    string get_publication_province();
    string get_publication_city();
    string get_publisher();
    string get_contribution_level();
    bool get_is_presentation();
    string get_impact();
    bool get_open_access();
    string get_personal_renumeration();
    bool get_trainee();
    string get_trainee_details();
    bool get_most_significant_publication();
    string get_most_significant_details();
    bool get_education_publication();
    string get_other_details();
    string get_authors();
    string get_title();
    string get_rest_of_citation();
    string get_isbnissn();
    int get_funding_ref_no();
    
    
    
};



#endif /* defined(___3307__publication_entry__) */
