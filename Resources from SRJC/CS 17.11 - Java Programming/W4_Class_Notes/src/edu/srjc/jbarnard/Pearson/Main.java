package edu.srjc.jbarnard.Pearson;

public class Main {

    public static void main(String[] args)
    {
        Pearson p = null;

        try
        {
            p = new Pearson("Will", "here", "Santa Rosa", 64, 1400);
        }
        catch ( Exception ex )
        {
            System.out.println( String.format( "an error occured", ex.getMessage() ) );
            System.exit( 0 );
        }

        System.out.println( String.format( "Hello %s", p.toString() ) );

        p.
    }



}
