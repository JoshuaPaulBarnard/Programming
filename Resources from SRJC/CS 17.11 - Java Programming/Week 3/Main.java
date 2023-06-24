package: ;



Scanner dataFile = null;
try
{

}


catch (Exception ex)
{
  System.err.println("It appears that file doesn't exist");
  System.exit( 0 );

  // return;
}

ArrayList<String> errors = new ArrayList<>();

String line = "":
while ( dataFile.hasNext() )
{

lineNumber += 1;

line = dataFile.nextLine().trim();

City c = null;
try
{
  c = new City( line );
}
//if (line.length() == 0 || line.charAt(0) == '#' )
catch (Exception ex)
{
  if ( ex.getMessage().equals("That's an empty line") )
  {
    continue;
  }
  else
  {
    errors.add( String.format("%s on line %d", ex.getMessage(), lineNumber );
  }
}

}

String[] fields = line.split( "\t");

if (fields.length != 5 )
{
  errors.add( String.format("Line %d has a problem", lineNumber) );
  continue;
}
System.out.println(line);
}
dataFile.close();

if ( errors.size() > 0 )
{
  for ( String e : errors )
  {
    System.err.println( e );
  }
}
