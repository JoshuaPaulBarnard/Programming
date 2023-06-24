package edu.srjc.seank.DB;

import java.sql.*;

import static java.sql.DriverManager.*;

public class Main {

    private static String dbName =  "data/world_cities.sqlite";

    public static void main(String[] args) throws SQLException
    {


        try
        {
            Class.forName("org.sqlite.JDBC");
        }
        catch (ClassNotFoundException e)
        {
            System.err.println("Cannot load SQLite-JDBC: Fatal Error");
            System.exit(0);
        }

        System.out.println(dbName);

        Connection connection = null;
        Statement statement = null;
        try
        {
            connection = getConnection(String.format("jdbc:sqlite:%s", dbName)) ;
            statement = connection.createStatement();
            statement.setQueryTimeout(30);

        }
        catch (SQLException e)
        {
            System.err.println(String.format("Fatal Error: Cannot connect to database %s, error is %s", dbName, e.getMessage()));
            System.exit(0);
        }

        ResultSet rs = null;
//        String sql = "SELECT count(*) FROM World_Cities where country = 'LK'";
        try
        {

            rs = statement.executeQuery(sql);
        }
        catch (SQLException e)
        {
            System.err.println(String.format("Query failed: %s", sql));
        }


        System.out.println(String.format("There are %s cities in LK", rs.getInt(1)));
//        if (rs != null)
//        {
//            try
//            {
//                while (rs.next())
//                {
//                    System.out.println(String.format("ID: %s, Name: %s, Country: %s", rs.getString("CITY_ID"), rs.getString("CITY_NAME"), rs.getString("COUNTRY")));
//                }
//            }
//            catch (Exception ex)
//            {
//                System.out.println(String.format("Error iterating over recordset"));
//            }
//
//        }
//        else
//        {
//            System.out.println("No records found!");
//        }
    }
}
