package edu.srjc.barnard.joshua.A2.police.shootings;

public class KilledPerson
{
    private String id;
    private String name;
    private String date;
    private String manner_of_death;
    private String armed;
    private String age;
    private String gender;
    private String race;
    private String city;
    private String state;
    private String signs_of_mental_illness;
    private String threat_level;
    private String flee;
    private String body_camera;


    public KilledPerson(String input) throws Exception
    {
        String[] category = input.split(",");
        if( category.length != 14 )
        {
            throw new Exception( "Invalid Categories" );
        }

        if( input.length() == 0 || input.charAt(0) == '#' )
        {
            throw new Exception( "Empty Line" );
        }

        gender = category[6];
        race = category[7];
        state = category[9];
    }


    public String getGender()
    {
        return gender;
    }

    public String getRace()
    {
        return race;
    }

    public String getState()
    {
        return state;
    }

}
