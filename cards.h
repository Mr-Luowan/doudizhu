#ifndef CARDS_H
#define CARDS_H

#include <QSet>
#include "card.h"

class Cards
{
public:
    enum SortType {Asc, Desc, NoSort};
    Cards();
    explicit Cards(const Card& card);

    void add(const Card& card);
    void add(const Cards& cards);
    void add(const QVector<Card>& cards);

    Cards operator << (const Card& card);
    Cards operator << (const Cards& cards);


    void remove(const Card& card);
    void remove(const Cards& cards);
    void remove(const QVector<Card>& cards);

    int cardCount();
    bool isEmpty();
    bool isEmpty() const;
    void clear();

    Card::CardPoint maxPoint();
    Card::CardPoint minPoint();
    int pointCount(Card::CardPoint point);

    bool contains(const Card& card);
    bool contains(const Cards& cards);

    Card takeRandomCard();

    QVector<Card> toCardList(SortType type = Desc);

    void printAllCardInfo();

private:
    QSet<Card> m_cards;

};

#endif // CARDS_H
