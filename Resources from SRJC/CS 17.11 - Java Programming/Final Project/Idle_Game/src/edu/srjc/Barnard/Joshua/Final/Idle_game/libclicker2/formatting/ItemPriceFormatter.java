package edu.srjc.Barnard.Joshua.Final.Idle_game.libclicker2.formatting;

import edu.srjc.Barnard.Joshua.Final.Idle_game.libclicker2.Item;

/**
 * Formats an item's price to a nice string representation.
 */
public class ItemPriceFormatter extends Formatter
{
    private final Item item;

    ItemPriceFormatter(Builder builder, Item item)
    {
        super(builder);
        this.item = item;
    }

    @Override
    public String toString()
    {
        setRawString(item.getPrice().toString());
        return super.toString();
    }
}
