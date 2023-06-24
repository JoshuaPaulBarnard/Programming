package edu.srjc.Barnard.Joshua.Final.Idle_game.libclicker2.formatting;

import edu.srjc.Barnard.Joshua.Final.Idle_game.libclicker2.Currency;

/**
 * Formats a currency to a nice string representation.
 */
public class CurrencyFormatter extends Formatter
{
    private final Currency currency;

    CurrencyFormatter( Builder builder, Currency currency )
    {
        super( builder );
        this.currency = currency;
    }

    @Override
    public String toString()
    {
        setRawString( currency.getValue().toString() );
        return super.toString();
    }
}
