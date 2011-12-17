#ifndef TICKETREQUEST_H
#define TICKETREQUEST_H

#include <QString>
#include <QVariantMap>
#include <QMessage>
QTM_USE_NAMESPACE

class TicketRequest {
public:
    explicit TicketRequest(QMessage msg);
    QString phoneNum() const;
    QString from() const;
    QString to() const;
    int count() const;
    bool isValid() const;
protected:
    bool parseAndUpdate(QMessage msg);
private:
    QStringList details;
    bool valid;
};

#endif // TICKETREQUEST_H
