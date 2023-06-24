/*
Joshua P. Barnard
jpb68@humboldt.edu
04/06/2018
A9 - Merge and Graph Data Using SQL
CS 17.11

 */

package edu.srjc.Barnard.Joshua.A9.Merge_and_Graph_Data_Using_SQL;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Stage;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.sql.Statement;

public class Main extends Application
{



    @Override
    public void start( Stage stage ) throws Exception
    {
        Parent root = FXMLLoader.load( getClass().getResource("UI_Layout.fxml" ) );

        Scene scene = new Scene( root );

        stage.setScene( scene );
        stage.show();
    }

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args)
    {
        launch(args);
    }

    /**
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
*/
}
