#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QListWidget>
#include "Note.h"
#include "Collection.h"
#include "Observer.h"

class MainWindow : public QWidget {
Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr){
        QVBoxLayout* layout = new QVBoxLayout(this);

        noteListWidget = new QListWidget(this);
        layout->addWidget(noteListWidget);

        workCollection = new Collection("Work");
        personalCollection = new Collection("Personal");

        Note* note1 = new Note("prova1", "sisi", true);
        Note* note2 = new Note("prova2", "nono", false);

        workCollection->addNote(note1);
        personalCollection->addNote(note2);




    }
    ~MainWindow();
private:
    Collection* workCollection;
    Collection* personalCollection;
    QListWidget* noteListWidget;
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    MainWindow mainWindow;
    mainWindow.setWindowTitle("Note Viewer");
    mainWindow.resize(400, 300);
    mainWindow.show();

    return app.exec();
}

#include "main.moc"


