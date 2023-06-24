package edu.srjc.barnard.joshua.ShapeShifters.TwoD;

public class Square extends Shape2D
{
    private int side;

    public int getSide()
    {
        return side;
    }

    public void setSide( int side )
    {
        this.side = side;
    }

    public Square()
    {
        side = sideLength;
    }

    @Override
    public double getArea()
    {
        return side * side;
    }

//    @Override
  //  public void draw() {
//
  //  }
}
