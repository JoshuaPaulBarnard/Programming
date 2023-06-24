package edu.srjc.jbarnard.Pearson;

import java.security.InvalidParameterException;

public class Pearson
{
    private String name = "";
    private String address = "";
    private String city = "";
    private String state = "";
    private String zip = "";

    private String birthYear = 0;
    private String birthMonth = 0;
    private String birthDay = 0;

    // CTOR

    /**
     *
     * @param name
     * @param address
     * @param city
     * @param birthYear
     */

    public Pearson()
    {

    }

    public Pearson( String name, String address, String city, int birthYear )
    {
        this.name = name;
        this.address = address;
        this.city = city;

        validateBirthYear(birthYear);
        // this.birthYear = birthYear;

    }

    public String getName()
    {
        return name;
    }

    public void setName(String name)
    {
        this.name = name;
    }

    public String getAddress()
    {
        return address;
    }

    public void setAddress(String address)
    {
        this.address = address;
    }

    public String getCity()
    {
        return city;
    }

    public void setCity(String city)
    {
        this.city = city;
    }

    public String getState()
    {
        return state;
    }

    public void setState(String state)
    {
        this.state = state;
    }

    public String getZip()
    {
        return zip;
    }

    public void setZip(String zip)
    {
        this.zip = zip;
    }

    public String getBirthYear()
    {
        return birthYear;
    }

    public void setBirthYear(String birthYear)
    {
        validateBirthYear(birthYear);

        if ( birthYear < 1800)
        {
            throw new InvalidParameterException("Invalid Birth Year");

        }

        this.birthYear = birthYear;
    }

    private void validateBirthYear(int birthYear)
    {
        if ( birthYear < 1800 )
        {
            throw new InvalidParameterException("Invalid Birth Year");
        }
    }

    public String getBirthMonth()
    {
        return birthMonth;
    }

    public void setBirthMonth(String birthMonth)
    {
        this.birthMonth = birthMonth;
    }

    public String getBirthDay()
    {
        return birthDay;
    }

    public void setBirthDay(String birthDay)
    {
        this.birthDay = birthDay;
    }

    @Override
    public String toString()
    {
        return "Pearson{" +
                "name='" + name + '\'' +
                ", address='" + address + '\'' +
                ", city='" + city + '\'' +
                ", state='" + state + '\'' +
                ", zip='" + zip + '\'' +
                ", birthYear='" + birthYear + '\'' +
                ", birthMonth='" + birthMonth + '\'' +
                ", birthDay='" + birthDay + '\'' +
                '}';
    }
}
