/*

Author: Khadichabonu Valieva

Group Members: -

Program Description:
                        <In this activity, we are going to plan out and write a class definition that stores information for a book. Let’s say we want to store the following information about this book...>

*/

#include <iostream>
#include "activity_2_classes_Book.h"


int main(int argc, const char * argv[]) {
    
    vector<string> authors1 {"Masashi Kishimoto"};
    Book book1 = Book("Naruto", authors1, "Shueisha", "9781569319000", 9.99, 1999);
    
    vector<string> authors2 {"Debra J DeWitte", "Ralph M Larmann", "M Kathryn Shields"};
    Book book2 = Book("Gateways to Arts: Understanding the Visual Arts", authors2, "Thames & Hudson", "9780500841150", 175.49, 2018);
    
    vector<string> authors3 {"Walter Isaacson"};
    Book book3 = Book("Steve Jobs", authors3, "Simon & Schuster", "9781451648539", 17.33, 2011);
    
    
    book1.show_info();
    book2.show_info();
    book3.show_info();
  
    


    return 0;
}
