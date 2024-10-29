// main.cpp

#include <QApplication>
#include "Collection.h"
#include "Observer.h"
#include "MainWindow.h"
#include "Controller.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // Inizializza la collezione di default
    QList<Collection*> collections;
    Collection *defaultCollection = new Collection("recently added");
    collections.append(defaultCollection);
    Controller controller(collections);

    // Crea la finestra principale con il controller
    MainWindow mainWindow(&controller);
    mainWindow.setWindowTitle("Note Viewer");
    mainWindow.resize(400, 300);
    mainWindow.show();

    return app.exec();
}