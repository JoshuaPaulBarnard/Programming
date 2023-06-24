/*
Joshua P. Barnard
jpb68@humboldt.edu
04/06/2018
A9 - Merge and Graph Data Using SQL
CS 17.11

 */

package edu.srjc.Barnard.Joshua.A9.Merge_and_Graph_Data_Using_SQL;

import edu.srjc.Barnard.Joshua.A9.Merge_and_Graph_Data_Using_SQL.Histories.Electric_History;
import edu.srjc.Barnard.Joshua.A9.Merge_and_Graph_Data_Using_SQL.Histories.Gas_History;
import edu.srjc.Barnard.Joshua.A9.Merge_and_Graph_Data_Using_SQL.Histories.Temperature_History;
import edu.srjc.Barnard.Joshua.A9.Merge_and_Graph_Data_Using_SQL.Readers.Gas_Reader;

import java.io.FileNotFoundException;
import java.net.URL;
import java.util.ResourceBundle;

import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.chart.CategoryAxis;
import javafx.scene.chart.LineChart;
import javafx.scene.chart.NumberAxis;
import javafx.scene.chart.XYChart;
import javafx.scene.layout.StackPane;
import javafx.scene.input.MouseEvent;
import javafx.scene.Cursor;
import javafx.scene.control.Label;
import javafx.event.EventHandler;
import javafx.scene.paint.Color;


public class UI_Controller implements Initializable
{

    private Electric_History elec_history = null;
    private Gas_History gas_history = null;
    private Temperature_History temp_history = null;

    @FXML
    private LineChart<String, Number> MainChart;

    private CategoryAxis dateAxis = new CategoryAxis();
    private NumberAxis valueAxis = new NumberAxis();


    @Override
    public void initialize( URL url, ResourceBundle rb )
    {
        // Load in Data
        try
        {
            gas_history = new Gas_History( "gas.csv" );
            elec_history = new Electric_History( "elec.csv" );
            temp_history = new Temperature_History( "KCASONOMA42.csv" );
        }
        catch ( FileNotFoundException e )
        {
            System.out.println( "File not found" );
        }

        // Chart Parameters
        dateAxis.setLabel( "Date" );
        valueAxis.setLabel( "Observations" );

        XYChart.Series Electric_Series = new XYChart.Series();
        Electric_Series.setName( "Electric" );

        XYChart.Series Gas_Series = new XYChart.Series();
        Gas_Series.setName( "Gas" );

        XYChart.Series lowTemp_Series = new XYChart.Series();
        lowTemp_Series.setName( "Low Temp" );

        XYChart.Series highTemp_Series = new XYChart.Series();
        highTemp_Series.setName( "High Temp" );


        for( Gas_Reader r : gas_history )
        {
            String lblData1 = String.format( "Date: %s\nQuantity: %s\n",
                    r.getDate(), r.getQuantity() );

            XYChart.Data<String, Double> dataPoint = new XYChart.Data<>( r.getDate(), r.getQuantity() );
            Gas_Series.getData().add( dataPoint );
            dataPoint.setNode( new DataPopup( lblData1 ) );
        }

/*

        System.out.print( Gas_History.toString() );
        System.out.print( Electric_History.toString() );
        System.out.print( Temperature_History.toString() );


        for ( Electric_Reader Results : elec_history)
        {
            String lblData = String
                    .format
                            (
                                    "Date: %s\nStart Time: %s\nEnd Time: %s\n%s\nUsage:"
                                    , Results.getDate()
                                    , Results.getStart_Time()
                                    , Results.getEnd_Time()
                                    , Results.getUsage()
                            );

            XYChart.Data<Integer, Integer> dataPoint = new XYChart.Data<>( Results.getDate(), Results.getUsage() );
            Electric.getData().add( dataPoint );
            dataPoint.setNode( new DataPopup( lblData ) );
        }


        for ( Gas_Reader Results : gas_history)
        {
            String lblData = String.
                    format
                            (
                                    "Date: %s\nQuantity: %s\nCost:"
                                    , Results.getDate()
                                    , Results.getQuantity()
                                    , Results.getCost()
                            );

            XYChart.Data<Integer, Integer> dataPoint = new XYChart.Data<>( Results.getDate(), Results.getQuantity() );
            Gas.getData().add( dataPoint );
            dataPoint.setNode( new DataPopup( lblData ) );
        }


        for ( Temperature_Reader Results : temp_history)
        {
            String lblData = String
                    .format
                            (
                                    "Date: %s\nOutTemp:"
                                    , Results.getDate()
                                    , Results.getOutTemp()
                            );

            XYChart.Data<Integer, Integer> dataPoint = new XYChart.Data<>( Results.getDate(), Results.getOutTemp() );
            lowTemp.getData().add( dataPoint );
            dataPoint.setNode( new DataPopup( lblData ) );
        }

*/

        // Populate Chart with Data Points
        MainChart.getData().add( Electric_Series );
        MainChart.getData().add( Gas_Series );
        MainChart.getData().add( lowTemp_Series );
        MainChart.getData().add( highTemp_Series );

    }

    class DataPopup extends StackPane
    {
        public DataPopup( String content )
        {
            setPrefSize(10, 10 );
            Label lblContent = createBpDataLabel( content );
            setOnMouseEntered( new EventHandler<MouseEvent>()
            {
                @Override
                public void handle( MouseEvent event )
                {
                    getChildren().setAll( lblContent );
                    setCursor( Cursor.NONE );
                    toFront();
                }
            });

            setOnMouseExited(new EventHandler<MouseEvent>()
            {
                @Override
                public void handle (MouseEvent event )
                {
                    getChildren().clear();
                }
            });
        }

        private Label createBpDataLabel( String content )
        {
            Label lbl = new Label( content );

            lbl.getStyleClass().addAll("default-color0", "chart-line-symbol", "chart-series-line" );
            lbl.setStyle( "-fx-font-size: 12px; -fx-font-weight: bold" );
            lbl.setTextFill( Color.FIREBRICK );
            lbl.setMinSize( Label.USE_PREF_SIZE, Label.USE_PREF_SIZE );
            return lbl;
        }

    }
}

