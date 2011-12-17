#include <QtGui/QApplication>
#include <QDeclarativeContext>
#include <QDeclarativeView>
#include "qmlapplicationviewer.h"
#include "ServerSimulator.h"

Q_DECL_EXPORT int main(int argc, char *argv[])
{
    QScopedPointer<QApplication> app(createApplication(argc, argv));
    ServerSimulator s;
    QDeclarativeView dv;
    QDeclarativeContext* context = dv.rootContext();
    context->setContextProperty("engine",(QObject*)&s);
    dv.setSource(QUrl("qml/ServerSimulator/main.qml"));
    dv.showFullScreen();


//    QScopedPointer<QmlApplicationViewer> viewer(QmlApplicationViewer::create());

//    viewer->setOrientation(QmlApplicationViewer::ScreenOrientationLockPortrait);
//    viewer->setMainQmlFile(QLatin1String("qml/ServerSimulator/main.qml"));
//    viewer->showExpanded();

    return app->exec();
}
