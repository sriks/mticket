#include <QStringList>
#include <QMessageAddress>
#include <QDebug>
#include "TicketRequest.h"


// Expected parameters in request
const int PHONENUM = 0;
const int FROM = PHONENUM+1;
const int TO = FROM+1;
const int COUNT = TO+1;

const int MINREQUIRED = 2;
const int MAXALLOWED = COUNT+1; // make sure this is the last parameter

TicketRequest::TicketRequest(QMessage msg) {
    valid = parseAndUpdate(msg);
}

// Example format of ticket request
// Begumpet to Lingampally 2 tickets
// BGM LPI 2
// TODO: accomodate class also
bool TicketRequest::parseAndUpdate(QMessage msg) {
    bool res = false;
    QString content = msg.textContent();
    QStringList l = content.split(QString(" "));
    l.insert(0,msg.from().addressee());
    qDebug()<<l.size();
    if(l.size()>= MINREQUIRED && l.size() <= MAXALLOWED)
    {
        // TODO: Do type checking before appending, like count is only numerical.
        details = l;
        res = true;
    }
    return res;
}

QString TicketRequest::from() const {
    return (isValid())?(details.at(FROM)):(QString());
}

QString TicketRequest::to() const {
    return (isValid())?(details.at(TO)):(QString());
}

int TicketRequest::count() const {
    return (isValid())?(details.at(COUNT).toInt()):(0);
}

bool TicketRequest::isValid() const {
    return valid;
}

QString TicketRequest::phoneNum() const {
    return (isValid())?(details.at(PHONENUM)):(QString());
}

// eof
