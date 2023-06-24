package edu.srjc.barnard.joshua.A3.coldest_hour;

import java.io.File;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner inputFile = null;
        try {
            inputFile = new Scanner(new File("weatherdata.csv"));
        } catch (Exception ex) {
            System.err.println("There was an error loading your file.");
            System.err.println("Please reload the program, and try again");
            System.exit(-1);
        }


        ArrayList<String> errors = new ArrayList<>();
        int lineNumber = 2;
        ArrayList<WeatherDataPoint> weather = new ArrayList<>();
        HashMap<String, Integer> weatherCount = new HashMap<>();

        String line = "";

        boolean skip = true;
        while( inputFile.hasNext() )
        {
            lineNumber++;
            line = inputFile.nextLine().trim();

            WeatherDataPoint w = null;
            try
            {
                w = new WeatherDataPoint( line );
                weather.add( w );
            }
            catch ( Exception problem )
            {
                if ( problem.getMessage().equals( "Empty Line" ) )
                {
                    continue;
                }
                else
                {
                    errors.add( String.format( "%s on line %d", problem.getMessage(), lineNumber ) );
                }
            }
        }
        inputFile.close();


        if( errors.size() > 0 )
        {
            for( String e : errors )
            {
                System.err.println(e);
            }
        }

    }

}
