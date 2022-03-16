#ifndef HISTORYDATA_H
#define HISTORYDATA_H

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include<QTableWidget>
#include<QtMultimedia/QMediaPlayer>
#include<QtMultimedia/QMediaPlaylist>
#include<QFileDialog>
#include<QDir>
#include<QPoint>
#include<QNetworkAccessManager>
#include<QVariant>
#include<QByteArray>
#include<QJsonParseError>
#include<QJsonDocument>
#include<QJsonObject>
#include<QJsonArray>
#include<QUrl>
#include<QPixmap>
#include<QMapIterator>
#include<QRegExp>
#include <QPainter>
#include <qdebug.h>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QMouseEvent>
#include"jsoninfo.h"
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

class HistoryData
{
public:
    QSqlDatabase database;
    QString albumid;
    QString songname;
    QString authorname;
    QString albumname;
    QString time;
    HistoryData();
    ~HistoryData();
    QSqlQuery createData();
    void getData(QSqlQuery sql_query);
};

#endif // HISTORYDATA_H
