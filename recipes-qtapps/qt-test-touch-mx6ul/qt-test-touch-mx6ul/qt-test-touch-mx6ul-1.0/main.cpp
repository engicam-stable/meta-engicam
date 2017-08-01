#include <QApplication>
#include <QDeclarativeView>
#include <QDeclarativeContext>
#include <QDeclarativeProperty>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
  
    QDeclarativeView viewer;
    viewer.setSource(QStringLiteral("qrc:/main.qml"));
    viewer.show();

    return app.exec();
}
