#include <QGuiApplication>
#include <QQuickView>
//#include <QDeclarativeContext>
//#include <QDeclarativeProperty>

Q_DECL_EXPORT int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQuickView viewer;
    viewer.setSource(QStringLiteral("qrc:/main.qml"));

    viewer.show();

    return app.exec();
}

