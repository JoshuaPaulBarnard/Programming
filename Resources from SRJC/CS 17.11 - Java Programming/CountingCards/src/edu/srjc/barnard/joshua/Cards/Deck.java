package edu.srjc.barnard.joshua.Cards;

import java.util.ArrayList;
import java.util.Collections

public class Deck extends ArrayList<Card>
{
    public Deck()
    {
        for( Card.Suits s : Card.Suits.values() )
        {
            for( Card.Ranks r : Card.Ranks.values() )
            {
                this.add( new Card(s, r) );
            }
        }
        Collections.shuffle( this );
    }

    public void dumpDeck()
    {
        for( Card c : this )
        {
            System.out.println( c );
        }
    }

}
