package edu.srjc.barnard.joshua.A3.coldest_hour;

import java.security.InvalidParameterException;

public class WeatherDataPoint
{
    private String dateTime;
    private String usUnits;
    private String interval;
    private String barometer;
    private String pressure;
    private String altimeter;
    private String inTemp;
    private String outTemp;
    private String inHumidity;
    private String outHumidity;
    private String windSpeed;
    private String windDir;
    private String windGust;
    private String windGustDir;
    private String rainRate;
    private String rain;
    private String dewpoint;
    private String windchill;
    private String heatindex;
    private String ET;
    private String radiation;
    private String UV;
    private String extraTemp1;
    private String extraTemp2;
    private String extraTemp3;
    private String soilTemp1;
    private String soilTemp2;
    private String soilTemp3;
    private String soilTemp4;
    private String leafTemp1;
    private String leafTemp2;
    private String extraHumid1;
    private String extraHumid2;
    private String soilMoist1;
    private String soilMoist2;
    private String soilMoist3;
    private String soilMoist4;
    private String leafWet1;
    private String leafWet2;
    private String rxCheckPercent;
    private String txBatteryStatus;
    private String consBatteryVoltage;
    private String hail;
    private String hailRate;
    private String heatingTemp;
    private String heatingVoltage;
    private String supplyVoltage;
    private String referenceVoltage;
    private String windBatteryStatus;
    private String rainBatteryStatus;
    private String outTempBatteryStatus;
    private String inTempBatteryStatus;

    private int date = 0;
    private int time = 0;
    private int temperature = 0;


    public WeatherDataPoint( String input ) throws Exception
    {
        String[] category = input.split("," );
        if( category.length != 50 )
        {
            throw new Exception("Invalid Categories");
        }

        if( input.length() == 0 || input.charAt(0) == '#' )
        {
            throw new Exception( "Empty Line" );
        }

        dateTime = category[0];
        inTemp = category[6];
        outTemp = category[7];
    }

    public String getDateTime()
    {
        return dateTime;
    }

    public void setDateTime( String dateTime )
    {
        this.dateTime = dateTime;
    }

    public String getOutTemp()
    {
        return outTemp;
    }

    public void setOutTemp( String outTemp )
    {
        this.outTemp = outTemp;
    }

    private void convertTime(  )
    {

    }

    public int getDate()
    {
        return date;
    }

    public void setDate( int date )
    {


        this.date = date;
    }

    public int getTime()
    {
        return time;
    }

    public void setTime( int time )
    {


        this.time = time;
    }

    public int getTemperature()
    {
        return temperature;
    }

    public void setTemperature( int temperature )
    {


        this.temperature = temperature;
    }

}
