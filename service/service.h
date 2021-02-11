/**
 * @file service.h
 * @copyright 2020 Open Mobile Platform LLC.
 * @author Dmitry Butakov d.butakov@omprussia.ru
 */

#ifndef SERVICE_H
#define SERVICE_H

#include <QDBusContext>
#include <QDBusUnixFileDescriptor>
#include <QTimer>

class Service: public QObject, public QDBusContext
{
    Q_OBJECT

public:
    explicit Service(QObject *parent = nullptr);
    virtual ~Service();

public slots:
    QString decodeFromDescriptor(QDBusUnixFileDescriptor fd,
            uint size, int width, int height, int pixelFormat);
    void quit();

private:
    QTimer m_autoclose;
};

#endif // SERVICE_H
