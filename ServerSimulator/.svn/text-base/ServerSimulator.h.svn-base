#ifndef SERVERSIMULATOR_H
#define SERVERSIMULATOR_H

#include <QObject>
#include <QMessageManager>
#include <QMessageFilter>
#include <QMessageService>
QTM_USE_NAMESPACE

class ServerSimulatorPrivate;
class TicketRequest;
class ServerSimulator : public QObject
{
    Q_OBJECT
public:
    explicit ServerSimulator(QObject *parent = 0);
    virtual ~ServerSimulator();
signals:

public slots:
    void addListeners();
    void messageAdded(const QMessageId&,
                      const QMessageManager::NotificationFilterIdSet&);
protected slots:
    void processRequest(const QMessageId& id);
    bool sendTicket(TicketRequest& req);
private:
    ServerSimulatorPrivate* d;
};

#endif // SERVERSIMULATOR_H
