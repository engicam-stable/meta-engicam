#if 0
    #include "qmlapplicationviewer.h"
#endif

#include <QApplication>
#include <QDeclarativeView>
#include <QDeclarativeContext>
#include <QDeclarativeProperty>
#include <QDesktopWidget>
#include <QDebug>
#include "cprfilerclass.h"

Q_DECL_EXPORT int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    cPrfilerClass mProfiler;

    mProfiler.start();

   //
  //  qDebug() << height << " - " << width;
#if 0
    QmlApplicationViewer viewer;
    viewer.setOrientation(QmlApplicationViewer::ScreenOrientationAuto);
    viewer.setMainQmlFile(QStringLiteral("qrc:/main.qml"));
    viewer.rootContext()->setContextProperty("CPPProfiler", &mProfiler);
    viewer.showExpanded();
#else

    QDeclarativeView viewer;
    viewer.setSource(QStringLiteral("qrc:/main.qml"));
    viewer.rootContext()->setContextProperty("CPPProfiler", &mProfiler);

    // Set the dimension of the screen
    QRect rec = QApplication::desktop()->screenGeometry();
    int screen_width = rec.width();
    int screen_height = rec.height();

    QObject *object = (QObject *)viewer.rootObject();
    QDeclarativeProperty(object, "screen_width").write(screen_width);
    QDeclarativeProperty(object, "screen_height").write(screen_height);
    QDeclarativeProperty(object, "pref_image").write(QString("%1x%2").arg(screen_width).arg(screen_height));

    if ( (screen_width == 480) && (screen_height == 272) ) // Smooth is enabled only when resolution is 480x272
    {
        QDeclarativeProperty(object, "smooth_enabled").write(true);
    }

    viewer.show();

#endif
    return app.exec();
}

