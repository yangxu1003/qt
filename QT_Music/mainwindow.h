#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QMainWindow>
#include<QtMultimedia/QMediaPlayer>
#include<QtMultimedia/QMediaPlaylist>
#include<QNetworkAccessManager>
#include<QNetworkReply>
#include<QVector>
#include<QMap>
#include<QMovie>
#include<QSize>
#include<QPushButton>
#include<QJsonObject>
#include <QSignalMapper>

#include"JsonInfo.h"
#include"historydata.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void mousePressEvent(QMouseEvent *event);    //鼠标点击
    void mouseMoveEvent(QMouseEvent *event);     //鼠标移动
    void mouseReleaseEvent(QMouseEvent *event);  //鼠标释放

    void search(QString str,int page,int pagesize); //搜索
    JsonInfo parseJson(QString json);
    QString getcontains(QJsonObject Object,QString strInfo);
    void parseJsonSongInfo(QString json);


private slots:
    void on_buttonSearch_clicked();

    void on_pushButton_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_17_clicked();

    void on_horizontalSlider_sliderReleased();

    void on_last_btn_clicked();

    void on_play_btn_clicked();

    void on_next_btn_2_clicked();

    void on_button_value_clicked();

    void on_tableWidget_cellDoubleClicked(int row, int column);

    void replyFinished(QNetworkReply *reply);
    void replyFinished2(QNetworkReply *reply);
    void replyFinished3(QNetworkReply *reply);

    void onDurationChanged(qint64 duration); //文件时长变化，更新当前播放文件名显示
    //播放文件数据总大小的信号， 它可以获得文件时间长度。
    void onPositionChanged(qint64 position); //当前文件播放位置变化，更新进度显示
    //播放到什么位置的信号， 参数是以毫秒来计算的。

    void onPlaylistChanged(int position);//显示歌名

    void on_buttonOpen_clicked();

    void on_min_btn_clicked();

    void on_close_btn_clicked();

    void on_horizontalSlider_2_valueChanged(int value);

private:
    Ui::MainWindow *ui;

    QMediaPlayer * player;//播放器
    QMediaPlaylist * playlist;//播放列表
    QString durationTime;       //当前文件播放进度
    QString positionTime;       //文件播放总进度

    QNetworkRequest * network_request;      //用于歌曲搜索
    QNetworkRequest * network_request2;     //用于歌曲播放
    QNetworkRequest * network_request3;     //显示歌词
    QNetworkAccessManager * network_manager;
    QNetworkAccessManager * network_manager2;
    QNetworkAccessManager * network_manager3;

    QPoint m_point;                     //鼠标坐标
    QMovie * m_movie;                   //添加动态图
    QSize m_si;                         //动态图压缩大小

    int m_Amount = 0; //用来记录文件总数
    int m_Value = 0; //当前播放的文件标记
    bool m_IsPause = true;//判断播放器状态
    bool m_IsVolume = false;//判断音量状态
    int m_StackedIndex =0;              //获取当前页面索引

    JsonInfo JI;
    QMap<int,QString> lrcMap;           //保存歌词
    bool m_IsLyricsShow = false;        //判断歌词显示状态
    HistoryData  music;//历史播放
    QSignalMapper * myMapper;
    int IsExecute = 1;
};
#endif // MAINWINDOW_H
