
#ifndef ACTIVITIES_NOTE_H
#define ACTIVITIES_NOTE_H
#include <QObject>
#include <QString>
class Note: public QObject{
Q_OBJECT
private:
    QString title;
    QString text;
    bool important;
public:
    Note(QString title, QString text, bool important = false);
    QString getTitle() const;
    QString getText() const;
    bool isImportant() const;
    void setTitle(QString title);
    void setText(QString text);

};
#endif //ACTIVITIES_NOTE_H