/*
Joshua P. Barnard
jpb68@humboldt.edu
04/06/2018
A9 - Merge and Graph Data Using SQL
CS 17.11 - Spring 2018

 */


package edu.srjc.Barnard.Joshua.A9.Merge_and_Graph_Data_Using_SQL.Readers;

import java.security.InvalidParameterException;


public class Electric_Reader
{

    private String Date;
    private String Start_Time;
    private String End_Time;
    private String Usage;


    public Electric_Reader( String Lines )
    {
        String [] fields = Lines.split(  "," );

        if ( Lines.length() == 0 || fields.length < 6 )
        {
            throw new InvalidParameterException( "Invalid Number of Fields. List Wise Deletion was used to deal with Missing Data." );
        }

        //setFields( fields );

        setDate( fields[1] );
        setStart_Time( fields[2] );
        setEnd_Time( fields[3] );
        setUsage( fields[4] );
    }




    public String getDate()
    {
        return Date;
    }

    public void setDate( String date )
    {
        Date = date;
    }

    public String getStart_Time()
    {
        return Start_Time;
    }

    public void setStart_Time( String start_Time )
    {
        Start_Time = start_Time;
    }

    public String getEnd_Time()
    {
        return End_Time;
    }

    public void setEnd_Time( String end_Time )
    {
        End_Time = end_Time;
    }

    public String getUsage()
    {
        return Usage;
    }

    public void setUsage( String usage )
    {
        Usage = usage;
    }


    @Override
    public String toString()
    {
        return "Electric Reading{" +
                ", Date ='" + Date + '\'' +
                ", Start_Time =" + Start_Time +
                ", End_Time =" + End_Time +
                ", Usage =" + Usage +
                '}';
    }
}
