package edu.srjc.barnard.joshua.Cards;

public class Main
{

    public static void main( String[] args )
    {
        Deck deck = new Deck();

        Card c = new Card();
        c.setRank( Card.Ranks.Eight );
        c.SetSuit( Card.Suits.Clubs );

        deck.add(c);


        //System.out.println( String.format( "This is the %s", c.toString() ) );

        c = new Card( Card.Suits.Diamonds, Card.Ranks.Ace );
        //System.out.println( String.format( "This is the %s", c.toString() ) );


        deck.add(c);

        for( Card deck : deck )
        {
            System.out.println( String.format( "This is the %s", c.toString() ) );
        }
    }
}
