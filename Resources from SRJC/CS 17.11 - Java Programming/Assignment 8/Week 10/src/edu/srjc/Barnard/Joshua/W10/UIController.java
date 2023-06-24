/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package edu.srjc.Barnard.Joshua.W10;

import java.awt.event.MouseEvent;
import java.net.URL;
import java.util.ResourceBundle;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.scene.text.Text;

/**
 *
 * @author 
 */
public class UIController implements Initializable
{
    
    @FXML
    private Label lblCaption;

    @FXML
    private PieChart instrumentChart;

    private ArrayList<PieChart.Data> pcd;
    
    @Override
    public void initialize(URL url, ResourceBundle rb)
    {
        pcd = new ArrayList<>();
        pcd.add( new PieChart.Data( "Trumpets", 3 ) );
        pcd.add( new PieChart.Data( "Horns", 4 ) );
        pcd.add( new PieChart.Data( "Trombones", 3 ) );
        pcd.add( new PieChart.Data( "Tuba", 1 ) );
        pcd.add( new PieChart.Data( "Flutes", 2 ) );
        pcd.add( new PieChart.Data( "Clarinets", 2 ) );
        pcd.add( new PieChart.Data( "Oboes", 2 ) );
        pcd.add( new PieChart.Data( "Bassons", 2 ) );

        instruments = FXCollections.observableArrayList(pcd);
        instrumentChart.setData( instruments );
        instrumentChart.setLabelsVisible( true );

        for( PieChart.Data d : instrumentChart.getData() )
        {
            d.getNode().addEventHandler( MouseEvent.MOUSE_ENTERED, new EventHandler<MouseEvent>() )
            {
                @Override
                public void handle( MouseEvent event )
                {
                    lblCaption.setTranslateX( event.getSceneX() );
                    lblCaption.setTranslateY( event.getSceneY() );

                    String s = String.format( "%s %s", String.valueOf( (int)d.getPieValue() ),
                            d.getName() );
                    lblCaption.setText( s );
                    lblCaption.setVisible( true );
                    lblCaption.

                }
            }
        }

    }    
    
}
