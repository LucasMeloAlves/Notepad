
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
    Note(QString title, QString text, bool important = false){
        this->title = title;
        this->text = text;
    }
    QString getTitle() const{
        return title;
    }
    QString getText() const{
        return text;
    }
    bool isImportant() const{
        return important;
    }
    void setTitle(QString title){
        this->title = title;
    }
    void setText(QString text){
        this->text = text;
    }

};
#endif //ACTIVITIES_NOTE_H