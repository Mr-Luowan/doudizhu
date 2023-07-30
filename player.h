#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include "cards.h"

class Player: public QObject
{
    Q_OBJECT
public:
    //角色
    enum Role{Land, Farmer};
    //性别
    enum Gender {Man, WoMan};
    //头像的显示方向
    enum Direction{Left, Right};
    //玩家类型
    enum Type{Robot, User, UnKnow};
    explicit Player(QObject *parent = nullptr);
    explicit Player(QString name, QObject *parent = nullptr);

protected:
    int m_score = 0;
    QString m_name;

};

#endif // PLAYER_H
