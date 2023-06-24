// Joshua Barnard
// youngstoic@gmail.com
// 2/2/18
// Palindromes
// CS 17.11
// This program will ask the user for a number and check whether or not the inputted number is a palindrome.

package edu.srjc.barnard.joshua.A1.palindromes;

import java.util.Scanner;

import static java.lang.System.in;

public class Main {

    // This method will check if a string passed into it is composed of only numbers, or not.
    // If the string contains only numbers, it will return true.
    // If the string contains any character besides 0 - 9, then it will display an error and ask for a new input.
    // This method was inspired by http://www.javadb.com/validate-if-string-is-a-number/
    public boolean numberTest (String in)
    {
        try
        {
            Integer.parseInt(in);
        }
        catch (NumberFormatException ex)
        {
            return false;
        }
        if( in.contains("-") | in.contains("+") )
        {
            return false;
        }

        return true;
    }

    // This method accepts a string and checks to see if it is the same forward and back.
    // Returns true if the string is the same forward and backwards.
    // Returns false if the string is not the same forward and backards.
    // This method was inspired by https://www.w3schools.in/java-program/check-palindrome-string/
    public boolean palindromeTest (String in)
    {
        String reversed = "";

        for ( int index = in.length() - 1; index >= 0; index-- )
        {
            reversed = reversed + in.charAt(index);
        }

        if (in.equals(reversed))
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    public static void main(String[] args)
    {
        Main main = new Main();

        // Initializes input variable and accepts initial input
        Scanner input = new Scanner(in);
        System.out.print("Please enter any number:  ");
        String inputText = input.nextLine();

        // Checks if first character in string is a dash (-)
        // if true, the program will immediately exit.
        // if false, nothing will happen.
        if ( inputText.startsWith("-") )
        {
            System.exit(0);
        }

        // Checks if the input is numeric
        // If true, the program will continue uninterrupted.
        // If false, the program will prompt for another input.
        while ( main.numberTest(inputText) == false )
        {
            System.out.println("Error, please try again.");
            System.out.print("Please enter any number:  ");
            inputText = input.nextLine();
        }

        // Checks if the inputted string is a palindrome
        // If True, the program will inform the user of such.
        // If false, the program will inform the user of such.
        if (main.palindromeTest(inputText) == true)
        {
            System.out.println(inputText + " is a palindrome.");
        }
        else if (main.palindromeTest(inputText) == false)
        {
            System.out.println("I'm sorry, but " + inputText + " is not a palindrome");
        }
    }
}
