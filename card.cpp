#include "card.h"

Card::Card()
{

}

Card::Card(CardPoint point, CardSuit suit):m_point(point), m_suit(suit)
{

}

void Card::setPoint(CardPoint point)
{
    m_point = point;
}

Card::CardPoint Card::getPoint() const
{
    return m_point;
}

void Card::setSuit(CardSuit suit)
{
    m_suit = suit;
}

Card::CardSuit Card::getSuit() const
{
    return m_suit;
}

bool lessSort(const Card &c1, const Card &c2)
{
    if (c1.getPoint() == c2.getPoint())
    {
        return c1.getSuit() < c2.getSuit();
    } else {
        return c1.getPoint() < c2.getPoint();
    }
}

bool greaterSort(const Card &c1, const Card &c2)
{
    if (c1.getPoint() == c2.getPoint())
    {
        return c1.getSuit() > c2.getSuit();
    } else {
        return c1.getPoint() > c2.getPoint();
    }
}
bool operator ==(const Card& left, const Card& right)
{
    return (left.getPoint() == right.getPoint() && left.getSuit() == right.getSuit());
}

bool operator <(const Card& c1, const Card& c2)
{
    return lessSort(c1, c2);
}


uint qHash(const Card &card)
{
    return card.getPoint() * 100 + card.getSuit();
}
