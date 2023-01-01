/*

Author: Khadichabonu Valieva

Group Members: -

Program Description:
                        <In this activity, we are going to plan out and write a class definition that stores information for a book. Let’s say we want to store the following information about this book...>

*/

#ifndef activity_2_classes_Book_h
#define activity_2_classes_Book_h
#include <string>
#include <vector>
#include <iomanip>


using std::string;
using std::vector;
using namespace std;
using std:: setw;


class Book
{
private:
    string title;
    vector <string>authors;
    string publisher;
    string ISBN_number;
    double price;
    int year_of_publication;
    
    
    
public:
    Book (string title, vector<string>authors, string publisher, string ISBN_number, double price, int year_of_publication)
    {
        this->title = title;
        
        this->authors = authors;
        this->publisher = publisher;
            
        this->ISBN_number = ISBN_number;
        this->price = price;
        this->year_of_publication = year_of_publication;
        
        
    }
    
    void show_info()
    {
        cout << "~~~~~~~~~~~~~~~~~~~~~ Book Description ~~~~~~~~~~~~~~~~~~~~~" << endl << endl;
        cout <<setw(30)<< "Title: "<< this-> title << endl;
        cout <<setw(30)<<  "Author: "   ;
        
        for (int i=0; i<this->authors.size(); i++)
        {
            cout<< authors[i];
            if (i != this-> authors.size()-1)
            {
                cout<< ", ";
            }
        }
        cout << endl;
        cout <<setw(30)<< "Publisher: "  << this->publisher <<endl;
        cout <<setw(30)<< "ISBN Number: " << this->ISBN_number <<endl;
        cout <<setw(30)<< "Price: " << "$" << this->price <<endl;
        cout <<setw(30)<< "Year of Publication: "  << this->year_of_publication <<endl <<endl << endl << endl;
    }
    
    
    
    
    string getTitle()
     {
     return title;
     }
    
    vector<string>getAuthor()
     {
     return authors;
     }
    
    void addAuthor (string name)
    {
        this->authors.push_back(name);
    }
    
    string getPublisher()
     {
     return publisher;
     }
    
    string getISBN_number()
     {
     return ISBN_number;
     }
    
   double getPrice()
     {
     return price;
     }
    
    int getYear_of_publication()
     {
     return year_of_publication;
     }
    
    
    
};


#endif /* activity_2_classes_Book_h */
