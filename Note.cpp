//
// Created by lucas on 07/10/24.
//
#include "Note.h"

Note::Note(QString title, QString text, bool important){
this->title = title;
this->text = text;
}
QString Note::getTitle() const{
    return title;
}
QString Note::getText() const{
    return text;
}
bool Note::isImportant() const{
    return important;
}

void Note::setTitle(QString title){
this->title = title;
}
void Note::setText(QString text){
this->text = text;
}