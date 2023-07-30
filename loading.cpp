#include "loading.h"
#include <QPixmap>
#include <QTimer>
#include <QPainter>
#include "gamepanel.h"

Loading::Loading(QWidget *parent)
    : QWidget{parent}
{
    m_bg.load("./images/loading.png");
    setFixedSize(m_bg.size());
    setWindowFlags(Qt::FramelessWindowHint | windowFlags());
    setAttribute(Qt::WA_TranslucentBackground);

    QPixmap progress("./images/progress.png");
    QTimer* timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, [=](){
        m_process = progress.copy(0, 0, m_dist, progress.height());
        update();
        if (m_dist >= progress.width())
        {
            timer->stop();
            timer->deleteLater();
            //展示主页面
            GamePanel* panel = new GamePanel();
            panel->show();
            close();
        }
        m_dist += 5;
    });
    timer->start(15);
}

void Loading::paintEvent(QPaintEvent *event)
{
    QPainter p(this);
    p.drawPixmap(rect(), m_bg);
    p.drawPixmap(62, 417, m_process.width(), m_process.height(), m_process);
}
