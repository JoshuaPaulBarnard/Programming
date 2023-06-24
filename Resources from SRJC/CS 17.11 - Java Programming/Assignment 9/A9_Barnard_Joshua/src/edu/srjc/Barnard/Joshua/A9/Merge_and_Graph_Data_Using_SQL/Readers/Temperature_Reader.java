/*
Joshua P. Barnard
jpb68@humboldt.edu
04/06/2018
A9 - Merge and Graph Data Using SQL
CS 17.11 - Spring 2018

 */

package edu.srjc.Barnard.Joshua.A9.Merge_and_Graph_Data_Using_SQL.Readers;

import java.security.InvalidParameterException;

public class Temperature_Reader
{
    private String Date;
    private String OutTemp;

    public Temperature_Reader(String Lines )
    {
        String[] fields = Lines.split( "," );

        if ( Lines.length() == 0 )
        {
            throw new InvalidParameterException( "Invalid Number of Fields. List Wise Deletion was used to deal with Missing Data." );
        }

        fields[0] = fields[0].replace( "\"", "" );
        fields[7] = fields[7].replace( "\"", "" );

        setDate( fields[0] );
        setOutTemp( fields[7] );

    }


    public String getDate() {
        return Date;
    }

    public void setDate(String date) {
        Date = date;
    }

    public String getOutTemp() {
        return OutTemp;
    }

    public void setOutTemp(String outTemp) {
        OutTemp = outTemp;
    }

    @Override
    public String toString()
    {
        return "KCASONOMA43 Reading{" +
                ", Date ='" + Date + '\'' +
                ", OutTemp ='" + OutTemp + '\'' +
                '}';
    }

}