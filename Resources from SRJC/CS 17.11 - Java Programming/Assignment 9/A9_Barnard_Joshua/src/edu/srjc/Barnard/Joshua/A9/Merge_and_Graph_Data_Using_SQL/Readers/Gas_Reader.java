/*
Joshua P. Barnard
jpb68@humboldt.edu
04/06/2018
A9 - Merge and Graph Data Using SQL
CS 17.11 - Spring 2018

 */

package edu.srjc.Barnard.Joshua.A9.Merge_and_Graph_Data_Using_SQL.Readers;

import java.security.InvalidParameterException;

public class Gas_Reader
{

    private String Date;
    private Double Quantity;
    private String Cost;

    public Gas_Reader( String Lines )
    {
        String [] fields = Lines.split(  "," );
        if ( fields.length != 5 || Lines.length() == 0 )
        {
            throw new InvalidParameterException( "Invalid Number of Fields. List Wise Deletion was used to deal with Missing Data." );
        }

        setDate( fields[1] );
        setQuantity( Double.parseDouble( fields[2] ) );
    }


    public String getDate()
    {
        return Date;
    }

    public void setDate( String date )
    {
        Date = date;
    }

    public Double getQuantity()
    {
        return Quantity;
    }

    public void setQuantity( Double quantity )
    {
        Quantity = quantity;
    }

    public String getCost()
    {
        return Cost;
    }

    public void setCost( String cost )
    {
        Cost = cost;
    }


    @Override
    public String toString()
    {
        return "Gas Reading{" +
                ", Date ='" + Date + '\'' +
                ", Quantity =" + Quantity +
                ", Cost =" + Cost +
                '}';
    }
}