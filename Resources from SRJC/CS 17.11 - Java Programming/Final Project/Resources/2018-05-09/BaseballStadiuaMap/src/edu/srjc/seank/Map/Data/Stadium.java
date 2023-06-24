package edu.srjc.seank.Map.Data;

public class Stadium
{
    private String team;
    private String address;
    private String lat;
    private String lng;

    public Stadium(String team, String address, String lat, String lng)
    {
        this.team = team;
        this.address = address;
        this.lat = lat;
        this.lng = lng;
    }

    public String getteam()
    {
        return team;
    }

    public void setteam(String team)
    {
        this.team = team;
    }

    public String getAddress()
    {
        return address;
    }

    public void setAddress(String address)
    {
        this.address = address;
    }

    public String getLat()
    {
        return lat;
    }

    public void setLat(String lat)
    {
        this.lat = lat;
    }

    public String getLng()
    {
        return lng;
    }

    public void setLng(String lng)
    {
        this.lng = lng;
    }
}
