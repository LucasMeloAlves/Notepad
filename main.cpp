#include <QApplication>
#include "Collection.h"
#include "Observer.h"
#include "MainWindow.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    MainWindow mainWindow;
    Observer* obs;
    Collection* coll;

    mainWindow.setWindowTitle("Note Viewer");
    mainWindow.resize(400, 300);
    mainWindow.show();

    return app.exec();
}