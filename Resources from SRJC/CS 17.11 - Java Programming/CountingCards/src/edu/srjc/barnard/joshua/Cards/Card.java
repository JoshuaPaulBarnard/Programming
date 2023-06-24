package edu.srjc.barnard.joshua.Cards;

public class Card
{
    public enum Suits
    {
        Clubs,
        Diamonds,
        Hearts,
        Spades
    }

    public enum Ranks
    {
        Ace,
        Two,
        Three,
        Four,
        Five,
        Six,
        Seven,
        Eight,
        Nine,
        Ten,
        Jack,
        Queen,
        King
    }

    public Card()
    {

    }

    private Ranks rank;
    private Suits suit;

    @Override
    public String toString()
    {
        return rank + " of " + suit;
    }

}
