package edu.srjc.barnard.joshua.A2.police.shootings;

public class City
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

    public City(String line) throws Exception
    {
        if (line.length() == 0 || line.charAt(0) == '#' )
        {
            throw new Exception("That's an empty line");
        }

        String[] fields = line.split(",");

        if (fields.length != 14)
        {
            throw new Exception("That line has an invalid number of fields");
        }
        name = fields[1];
        state = fields[9];
    }

    public String getName()
    {
        return name;
    }

    public String getState()
    {
        return state;
    }
}

