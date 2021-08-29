#ifndef COUNTER_H_INCLUDED
#define COUNTER_H_INCLUDED

struct Counter
{
    int qtLines, qtColumns;
    int chairsAvaliable;
    int qtSoldTickets = 0;

    Counter(int amountLines, int amountColumns)
    {
        qtLines = amountLines;
        qtColumns = amountColumns;

        chairsAvaliable = qtLines * qtColumns;
    }

    int reserveChair()
    {
        chairsAvaliable -= 1;
        return chairsAvaliable;
    }

    int returnChair()
    {
        chairsAvaliable += 1;
        return chairsAvaliable;
    }

    int soldTickets()
    {
        qtSoldTickets += 1;
        return qtSoldTickets;
    }

    int returnTickets()
    {
        qtSoldTickets -= 1;
        return qtSoldTickets;
    }
};
#endif