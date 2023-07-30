#ifndef GAMEPANEL_H
#define GAMEPANEL_H

#include <QMainWindow>
#include <QLabel>
#include "cards.h"

namespace Ui {
class GamePanel;
}

class GamePanel : public QMainWindow
{
    Q_OBJECT

public:
    explicit GamePanel(QWidget *parent = nullptr);
    ~GamePanel();
protected:
    void paintEvent(QPaintEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
private:

    enum CardAlign {HorizonTal, Vertical};
    struct PlayerContext{
        QRect cardRect;
        QRect playHandRect;
        CardAlign align;
        bool isFrontSide;
        QLabel* info;
        QLabel* roleImg;
        Cards lastCards;
    };

    Ui::GamePanel *ui;

    QPixmap m_bgImg;
};

#endif // GAMEPANEL_H
