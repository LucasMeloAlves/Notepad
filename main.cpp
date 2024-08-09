#include <QApplication>
#include <QWidget>
#include <QObject>
#include <QVBoxLayout>
#include <QListWidget>
#include <QDebug>
#include "Note.h"
#include "Collection.h"
#include "Observer.h"

class MainWindow : public QWidget {


public:
    MainWindow(QWidget* parent = nullptr){
        QVBoxLayout* layout = new QVBoxLayout(this);

        noteListWidget = new QListWidget();
        layout->addWidget(noteListWidget);
    }

private:
    Collection* workCollection;
    Collection* personalCollection;
    QListWidget* noteListWidget;
};

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

