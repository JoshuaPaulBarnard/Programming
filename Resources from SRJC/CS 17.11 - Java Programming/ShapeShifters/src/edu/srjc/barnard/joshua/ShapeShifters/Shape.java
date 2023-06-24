package edu.srjc.barnard.joshua.ShapeShifters;

public abstract class Shape
{
    private String name;

    public String getName()
    {
        return name;
    }

    public void setName( String name )
    {
        this.name = name;
    }

    public abstract void draw();

}
