// A book consists of chapters, chapters consist of sections and sections consist of subsections.Construct a tree and print the nodes.Find the time and space requirements of your method.
#include <bits/stdc++.h>
using namespace std;

class node {
   public:
    string label;
    node* childrens;
    int count;
};

class Book {
   private:
    string bookName;
    node* chapters;
    int chapterCount = 0;

   public:
    addChapters() {
        cout << "Enter book name : ";
        cin >> bookName;
        cout << "\nEnter how many chapters you want to add : ";
        cin >> chapterCount;
        chapters = new node[chapterCount];

        // adding chapters to book
        for (size_t i = 0; i < chapterCount; i++) {
            cout << "Enter chapter name : " << endl;
            cin >> chapters[i].label;
            cout << "Enter how many sections you want to add in chapter " << chapters[i].label << endl;
            cin >> chapters[i].count;
            chapters[i].childrens = new node[chapters[i].count];

            // adding sections to chapters array
            for (size_t j = 0; j < chapters[i].count; j++) {
                cout << "Enter section name : " << endl;
                cin >> chapters[i].childrens[j].label;
                cout << "Enter how many subsections you want to add : " << endl;
                cin >> chapters[i].childrens[j].count;
                chapters[i].childrens[j].childrens = new node[chapters[i].childrens[j].count];

                // add sub sections to each section in chapter
                for (size_t k = 0; k < chapters[i].childrens[j].count; k++) {
                    cout << "Enter subsection name : " << endl;
                    cin >> chapters[i].childrens[j].childrens[k].label;
                    chapters[i].childrens[j].childrens[k].count = 0;
                }
            }
        }
    }

    void displayData() {
        cout << "Book Name :" << bookName << endl;
        for (size_t i = 0; i < chapterCount; i++) {
            cout << "Chapter Name : " << chapters[i].label << endl;
            for (size_t j = 0; j < chapters[i].count; j++) {
                cout << "\tSection Name : " << chapters[i].childrens[j].label << endl;
                for (size_t k = 0; k < chapters[i].childrens[j].count; k++) {
                    cout << "\t\t Sub section Name : " << chapters[i].childrens[j].childrens[k].label << endl;
                }
            }
        }
    }
};

int main() {
    int ch;
    Book book;

    while (true) {
        cout << "\n\nSelect the option \n1.create tree \n2.Display book data \n3.Exit program" << endl;
        cin >> ch;
        switch (ch) {
            case 1:
                book.addChapters();
                break;
            case 2:
                book.displayData();
            case 3:
                exit(0);
                break;

            default:
                cout << "Please select the correct option" << endl;
                break;
        }
    }

    return 0;
}
