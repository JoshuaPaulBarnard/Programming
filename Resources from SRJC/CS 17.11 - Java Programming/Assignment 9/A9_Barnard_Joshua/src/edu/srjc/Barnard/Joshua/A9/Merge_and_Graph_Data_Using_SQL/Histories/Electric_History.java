/*
Joshua P. Barnard
jpb68@humboldt.edu
04/06/2018
A9 - Merge and Graph Data Using SQL
CS 17.11 - Spring 2018

 */

package edu.srjc.Barnard.Joshua.A9.Merge_and_Graph_Data_Using_SQL.Histories;
import edu.srjc.Barnard.Joshua.A9.Merge_and_Graph_Data_Using_SQL.Readers.Electric_Reader;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Electric_History extends ArrayList<Electric_Reader>
{
    public Electric_History( String fileName ) throws FileNotFoundException
    {
        Scanner inputFile = new Scanner( new File( fileName ) );
        String thisLine = "";

        while ( inputFile.hasNextLine() )
        {
            thisLine = inputFile.nextLine().trim();

            if ( thisLine.length() == 0 )
            {
                continue;
            }

            try
            {
                this.add( new Electric_Reader( thisLine ) );
            }
            catch ( Exception e )
            {
                System.out.println( String.format( "ERROR: %s, Ignoring This Field", e.getMessage() ) );
            }
        }

        inputFile.close();
    }
}
