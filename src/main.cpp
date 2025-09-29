#include <QDebug>
#include <QList>
#include <algorithm>
#include "book.h"

bool compareByTitle(const Book &book1, const Book &book2){

    return book1.getTitle() < book2.getTitle();
}

int main()
{
    QList<Book> books = {
        Book("Jack London", "The call of the wild"),
        Book("Lev Tolstoy", "War and Peace"),
        Book("William Shakespire", "Hamlet"),
        Book("Honore Balsac", "Father Gotorn")
    };

    std::sort(books.begin(), books.end(),compareByTitle);

    for (auto b : books)
    {
        qInfo() << b.getAuthor()<<": "<< b.getTitle() <<Qt::endl;
    }

    return 0;
}