#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QTreeView>
#include <QTableView>
#include <QFileSystemModel>
#include <QSplitter>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget window;
    window.setWindowTitle("File Browser");

    QVBoxLayout *layout = new QVBoxLayout;
    QHBoxLayout *topLayout = new QHBoxLayout;

    QLineEdit *pathEdit = new QLineEdit;
    QLineEdit *searchEdit = new QLineEdit;

    topLayout->addWidget(pathEdit);
    topLayout->addWidget(searchEdit);

    QSplitter *splitter = new QSplitter;

    QTreeView *treeView = new QTreeView(splitter);
    QTableView *tableView = new QTableView(splitter);

    QFileSystemModel *dirModel = new QFileSystemModel;
    dirModel->setFilter(QDir::NoDotAndDotDot | QDir::AllDirs);
    treeView->setModel(dirModel);

    QFileSystemModel *fileModel = new QFileSystemModel;
    fileModel->setFilter(QDir::NoDotAndDotDot | QDir::Files);
    tableView->setModel(fileModel);

    QObject::connect(treeView->selectionModel(), &QItemSelectionModel::selectionChanged,
                     [&](){
                         QModelIndex index = treeView->currentIndex();
                         QString path = dirModel->fileInfo(index).absoluteFilePath();
                         tableView->setRootIndex(fileModel->setRootPath(path));
                     });

    layout->addLayout(topLayout);
    layout->addWidget(splitter);

    window.setLayout(layout);
    window.show();

    return app.exec();
}
