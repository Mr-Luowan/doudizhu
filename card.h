#ifndef CARD_H
#define CARD_H

#include <QVector>

class Card
{
public:

    //花色
    enum CardSuit
    {
        Suit_Begin,
        Diamond,        //方块
        Club,           //梅花
        Heart,          //红心
        Spade,          //黑桃
        Suit_End
    };

    //点数
    enum CardPoint
    {
        Card_Begin,
        Card_3,
        Card_4,
        Card_5,
        Card_6,
        Card_7,
        Card_8,
        Card_9,
        Card_10,
        Card_J,
        Card_Q,
        Card_K,
        Card_A,
        Card_2,
        Card_SJ,    //小王 small Joker
        Card_BJ,    //大王 big Joker
        Card_End
    };

    Card();
    Card(CardPoint point, CardSuit suit);

    void setPoint(CardPoint point);
    CardPoint getPoint() const;

    void setSuit(CardSuit point);
    CardSuit getSuit() const;

private:
    CardSuit m_suit;
    CardPoint m_point;
};

bool lessSort(const Card& c1, const Card& c2);
bool greaterSort(const Card& c1, const Card& c2);
bool operator <(const Card& c1, const Card& c2);

bool operator ==(const Card& left, const Card& right);

uint qHash(const Card& card);

#endif // CARD_H
