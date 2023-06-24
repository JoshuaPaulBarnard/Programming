package edu.srjc.seank.MyDb;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.sql.Statement;

public class Main {

    public static void main(String[] args) {

        try
        {
            Class.forName("org.sqlite.JDBC");
        }
        catch (ClassNotFoundException e)
        {
            e.printStackTrace();
            System.exit(0);
        }

        Connection conn = null;

        try
        {
            conn = DriverManager.getConnection("jdbc:sqlite:people.sqlite");
        }
        catch (SQLException e)
        {
            e.printStackTrace();
            System.exit(0);
        }

        try
        {
            Statement stmt = conn.createStatement();

            stmt.setQueryTimeout(30);

            stmt.executeUpdate("DROP TABLE IF EXISTS Person");
            stmt.executeUpdate("create table Person (id integer, name string)");




            stmt.executeUpdate("inSeRt INto Person values (1, 'Sean')");
            stmt.executeUpdate("inSeRt INto Person values (2, 'Stanley')");
            stmt.executeUpdate("inSeRt INto Person values (1, 'Billy Bob')");
            stmt.executeUpdate("inSeRt INto person (name) values ('Whiffle Pooff')");


        }
        catch (SQLException e)
        {
            e.printStackTrace();
            System.exit(0);
        }

    }
}
