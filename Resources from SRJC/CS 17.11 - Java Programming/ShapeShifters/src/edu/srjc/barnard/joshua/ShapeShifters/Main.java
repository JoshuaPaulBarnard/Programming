package edu.srjc.barnard.joshua.ShapeShifters;

import edu.srjc.barnard.joshua.ShapeShifters.TwoD.Circle;

public class Main {

    public static void main( String[] args )
    {
        ArrayList<Shape2D> twoDObjects = new ArrayList<Shape2D>();

        Circle c = new Circle( 5.8 );
        c.setName( "Fred Flintstone" );

        twoDObjects.add( c );

//        System.out.println( "The circle is " + c.getArea() );

        Square s = new Square( 2 );
        s.setName( "Olivia" );
//        System.out.println( "The square is " + s.getArea() );

        Shape2D twoD = new Shape2D();

        twoDObjects.add( s );

        for( Shape2D shp : twoDObjects )
        {
            System.out.println( String.format( "%s is named %s and has an area of %s",
                    shp.getClass().getSimpleName(),
                    shp.getName(),
                    shp.getArea() ) );
        }
    }
}
