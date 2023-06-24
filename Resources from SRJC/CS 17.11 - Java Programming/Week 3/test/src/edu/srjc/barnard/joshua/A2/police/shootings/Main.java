package edu.srjc.barnard.joshua.A2.police.shootings;

import java.io.File;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;
import java.util.TreeMap;

public class Main
{

    public static void main(String[] args)
    {

        Scanner dataFile = null;
        try
        {
            dataFile = new Scanner(new File("WaPo-fatal-police-shootings-data.csv"));
        }
        catch (Exception ex)
        {
            System.err.println("It appears that file doesn't exist");
            System.exit(0);

            //            return;
        }

        ArrayList<String> errors = new ArrayList<>();

        int lineNumber = 0;

        ArrayList<City> cities = new ArrayList<>();

        HashMap<String, Integer> citiesCount = new HashMap<>();

        String line = "";
        while (dataFile.hasNext())
        {
            lineNumber += 1;

            line = dataFile.nextLine().trim();

            City c = null;
            try
            {
                c = new City(line);
                cities.add(c);
            }
            catch (Exception ex)
            {
                if (ex.getMessage().equals("That's an empty line"))
                {
                    continue;
                } else
                {
                    errors.add(String.format("%s on line %d", ex.getMessage(), lineNumber));
                }
            }


            //            System.out.println(line);
        }
        dataFile.close();

        for (City currentCity : cities)
        {
            //            System.out.println(String.format("%s %s", c.getName(), c.getState()));
            if (citiesCount.containsKey(currentCity.getState()))
            {
                int cityCount = citiesCount.get(currentCity.getState());

                citiesCount.put(currentCity.getState(), cityCount + 1);

                //                citiesCount.put(c.getState(), citiesCount.get(c.getState()) + 1);
            } else
            {
                citiesCount.put(currentCity.getState(), 1);
            }
        }

//        unsorted
//        for (String state : citiesCount.keySet())
//        {
//            int count = citiesCount.get(state);
//
//            System.out.println(String.format("%s %d", state, count));
//        }

        TreeMap<String, Integer> sortedCountries = new TreeMap<>(citiesCount);

        for (String state : sortedCountries.keySet())
        {
            int count = sortedCountries.get(state);

            System.out.println(String.format("%s %d", state, count));
        }

        if (errors.size() > 0)
        {
            for (String e : errors)
            {
                System.err.println(e);
            }
        }
    }
}

