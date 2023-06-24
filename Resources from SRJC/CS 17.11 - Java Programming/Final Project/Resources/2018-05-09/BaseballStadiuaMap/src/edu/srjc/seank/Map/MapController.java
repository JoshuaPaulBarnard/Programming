/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package edu.srjc.seank.Map;

import java.net.URL;
import java.util.ResourceBundle;

import com.lynden.gmapsfx.GoogleMapView;
import com.lynden.gmapsfx.MapComponentInitializedListener;
import com.lynden.gmapsfx.javascript.event.UIEventType;
import com.lynden.gmapsfx.javascript.object.*;
import edu.srjc.seank.Map.Data.Stadia;
import edu.srjc.seank.Map.Data.Stadium;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.Button;

/**
 *
 * @author 
 */
public class MapController implements Initializable, MapComponentInitializedListener
{

    @FXML
    private Button button;

    @FXML
    private GoogleMapView mapView;

    private GoogleMap map;

    @Override
    public void initialize(URL url, ResourceBundle rb)
    {

        mapView.addMapInializedListener(this);

    }

    @Override
    public void mapInitialized()
    {

        //Set the initial properties of the map.
        MapOptions mapOptions = new MapOptions();

        mapOptions.center(new LatLong(39.82835,-98.5816684))
            .mapType(MapTypeIdEnum.ROADMAP)
            .overviewMapControl(false)
            .panControl(false)
            .rotateControl(false)
            .scaleControl(false)
            .streetViewControl(false)
            .zoomControl(false)
            .zoom(4);

        map = mapView.createMap(mapOptions);

        loadStadiumMarkers();

    }

    private void loadStadiumMarkers()
    {
        Stadia stadia = new Stadia("stadia.json");

        for (Stadium s : stadia)
        {
            MarkerOptions markerOpts = new MarkerOptions();

            LatLong ll = new LatLong(Double.parseDouble(s.getLat()), Double.parseDouble(s.getLng()));

            markerOpts.position(ll);

            Marker marker = new Marker(markerOpts);

            map.addMarker(marker);

            InfoWindowOptions winOpts = new InfoWindowOptions();

            if (s.getteam().toLowerCase().contains("giants"))
            {
                winOpts.content(String.format("<h1>%s</h1><br>Address: %s", s.getteam(), s.getAddress()));
            }
            else
            {
                winOpts.content(String.format("<h4>%s</h4><br>Address: %s", s.getteam(), s.getAddress()));
            }

            InfoWindow winFo = new InfoWindow(winOpts);

            map.addUIEventHandler(marker, UIEventType.mouseover, jsObject -> {winFo.open(map, marker);});

            map.addUIEventHandler(marker, UIEventType.mouseout, jsObject -> {winFo.close();});
        }
    }
}