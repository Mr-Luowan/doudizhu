#ifndef LOADING_H
#define LOADING_H

#include <QWidget>

class Loading : public QWidget
{
    Q_OBJECT
public:
    explicit Loading(QWidget *parent = nullptr);
protected:
    void paintEvent(QPaintEvent* event);

signals:

private:
    QPixmap m_bg;
    QPixmap m_process;
    int m_dist = 15;

};

#endif // LOADING_H
