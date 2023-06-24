package edu.srjc.barnard.joshua.A2.police.shootings;

import java.io.File;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;
import java.util.TreeMap;

public class Main
{

    public static void main(String[] args)
    {
        // write your code here
        Scanner inputFile = null;
        try
        {
            inputFile = new Scanner( new File( "WaPo-fatal-police-shootings-data.csv" ) );
        }
        catch (Exception ex)
        {
            System.err.println( "There was an error loading your file." );
            System.err.println( "Please reload the program, and try again" );
            System.exit( 0 );
        }


        ArrayList<String> errors = new ArrayList<>();
        int lineNumber = 0;
        ArrayList<KilledPerson> people = new ArrayList<>();
        HashMap<String, Integer> peopleCount = new HashMap<>();

        String line = "";

        boolean skip = true;
        while( inputFile.hasNext(  ) )
        {
            if( skip == true )
            {
                skip = false;
                continue;
            }

            lineNumber++;
            line = inputFile.nextLine().trim();

            KilledPerson k = null;
            try
            {
                k = new KilledPerson( line );
                people.add( k );
            }
            catch ( Exception problem )
            {
                if( problem.getMessage().equals( "Empty Line" ) )
                {
                    continue;
                }
                else
                {
                    errors.add(String.format( "%s on line %d", problem.getMessage(), lineNumber ) );
                }
            }
        }
        inputFile.close();

        for( KilledPerson currentPerson : people )
        {
            if( peopleCount.containsKey( currentPerson.getGender() ) )
            {
                int genderCount = peopleCount.get( currentPerson.getGender() );

                peopleCount.put( currentPerson.getGender(), genderCount + 1);
            }
            else
            {
                peopleCount.put( currentPerson.getGender(), 1 );
            }
        }

        for( String gender : peopleCount.keySet() )
        {
            int gCount = peopleCount.get(gender);

            System.out.println( String.format( "%s %d", gender, gCount) );
        }

        for( KilledPerson currentPerson : people )
        {
            if( peopleCount.containsKey( currentPerson.getRace() ) )
            {
                int raceCount = peopleCount.get( currentPerson.getRace() );

                peopleCount.put( currentPerson.getRace(), raceCount + 1);
            }
            else
            {
                peopleCount.put( currentPerson.getRace(), 1 );
            }
        }

        for( String race : peopleCount.keySet() )
        {
            int rCount = peopleCount.get(race);

            System.out.println( String.format( "%s %d", race, rCount) );
        }


        for( KilledPerson currentPerson : people )
        {
            if( peopleCount.containsKey( currentPerson.getState() ) )
            {
                int personCount = peopleCount.get( currentPerson.getState() );

                peopleCount.put( currentPerson.getState(), personCount + 1);
            }
            else
            {
                peopleCount.put( currentPerson.getState(), 1 );
            }
        }

        System.out.println( "State  Deaths" );
        TreeMap<String, Integer> sortedStates = new TreeMap<>( peopleCount );
        for( String state : sortedStates.keySet() )
        {
            int count = sortedStates.get( state );

            System.out.println( String.format( "%s       %d", state, count ) );
        }

        if( errors.size() > 0 )
        {
            for( String e : errors )
            {
                System.err.println(e);
            }
        }

    }
}
