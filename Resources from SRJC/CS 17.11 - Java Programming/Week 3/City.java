package edu.srjc.seank.cities;

public class City
{
  private String id;
  private String name;
  private String latitude;
  private String longitude;
  private String country;

public City(String line)
{
  if( line.length() == 0 || line.charAt(0) == '#')
  {
    throw new Exception("That's an empty line");
  }

  String[] fields = line.split( "\t" );
  
}

}
