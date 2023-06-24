package edu.srjc.barnard.joshua.ShapeShifters.TwoD;

public class Circle extends Shape2D
{
    private double radius;

    public Circle( double radius )
    {
        this.radius = radius;
    }

    public double getRadius()
    {
        return radius;
    }

    public void setRadius( double radius )
    {
        this.radius = radius;
    }

    @Override
    public double getArea()
    {
        return 0;
    }
}
