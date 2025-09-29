#include <QString>

class Book
{
private:
    QString author;
    QString title;

public:
    Book(QString, QString);
    QString getAuthor() const;
    QString getTitle() const;
};
