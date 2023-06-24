package edu.srjc.seank.Map.Data;

import com.google.gson.Gson;
import com.google.gson.stream.JsonReader;

import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.Reader;
import java.util.ArrayList;

public class Stadia extends ArrayList<Stadium>
{
    public Stadia(String jsonFile)
    {
        InputStream in = getClass().getResourceAsStream("/" + jsonFile);

        Reader r = new InputStreamReader(in);

        JsonReader jsr = new JsonReader(r);

        Gson gson = new Gson();

        Stadium stadiumArray[] = gson.fromJson(jsr, Stadium[].class);

        for (Stadium s : stadiumArray)
        {
            this.add(s);
        }
    }
}
