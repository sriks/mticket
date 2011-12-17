#include <QDateTime>
#include <QDebug>
#include "ServerSimulator.h"
#include "TicketRequest.h"

//#define OFFLINE;

const int MAXVALIDHRS = 3;
const QString respFormat("PNR:%1 %2-%3 Rs.%4 %5PRSN %6 Valid %7hrs\n%8");
struct ServerSimulatorPrivate {
    QMessageManager* mgr;
    QMessageManager::NotificationFilterIdSet regNotifications;
};


ServerSimulator::ServerSimulator(QObject *parent) :
                 QObject(parent) {
    d = new ServerSimulatorPrivate;
    d->mgr = new QMessageManager(this);
    addListeners();
#ifdef OFFLINE
    QMessageId invalid;
    processRequest(invalid);
#endif
}

ServerSimulator::~ServerSimulator() {
    delete d;
}

void ServerSimulator::addListeners() {
    connect(d->mgr,SIGNAL(messageAdded(QMessageId,QMessageManager::NotificationFilterIdSet)),
            this,SLOT(messageAdded(QMessageId,QMessageManager::NotificationFilterIdSet)),
            Qt::UniqueConnection);

    d->regNotifications.insert(
    d->mgr->registerNotificationFilter(QMessageFilter::byType(QMessage::Sms) &
                                       QMessageFilter::byStandardFolder(QMessage::InboxFolder)));
}

void ServerSimulator::messageAdded(const QtMobility::QMessageId &id,
                                   const QMessageManager::NotificationFilterIdSet &set) {
    if(set.contains(d->regNotifications))
        processRequest(id);
}

void ServerSimulator::processRequest(const QMessageId &id) {
    // Spawn a seperate thread to process multiple request more efficiently.
#ifdef OFFLINE
    QMessage m;
    m.setType(QMessage::Sms);
    m.setBody("BGT LGP 2");
    m.setFrom(QMessageAddress(QMessageAddress::Phone,"09885851504"));
#else
    QMessage m = d->mgr->message(id);
#endif
    TicketRequest req(m);
    if(req.isValid())
        sendTicket(req);
}

bool ServerSimulator::sendTicket(TicketRequest& req) {
    QString respBody;
    QString timeStamp = QDate::currentDate().toString("dd.M.yy")+" "+QTime::currentTime().toString("h:map");
    uint pnr = qHash(QDateTime::currentDateTime().toString());

    respBody = respFormat.arg(QString().number(pnr)) //pnr
                .arg(req.from())              // from
                .arg(req.to())                  // to
                .arg(QString("4"))              // price
                .arg(QString().number(req.count())) // passengers count
                .arg(timeStamp)                    // timestamp
                .arg(QString().number(MAXVALIDHRS)) // valid hours
                .arg(QString("Flat 25% off at InOrbit. Shop now!"));  // contextual ad

    qDebug()<<respBody<<" size:"<<respBody.size();
    QMessage ticket;
    ticket.setType(QMessage::Sms);
    ticket.setTo(QMessageAddress(QMessageAddress::Phone,req.phoneNum()));
    ticket.setBody(respBody);
    QMessageService service;
    service.send(ticket);
}


// eof
