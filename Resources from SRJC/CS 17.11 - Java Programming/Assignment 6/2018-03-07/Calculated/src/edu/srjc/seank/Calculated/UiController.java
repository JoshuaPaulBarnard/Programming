/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package edu.srjc.seank.Calculated;

import java.net.URL;
import java.util.ResourceBundle;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.*;
import javafx.scene.text.Text;

/**
 *
 * @author 
 */
public class UiController implements Initializable
{
    
    @FXML
    TextField txtFirstNumber;

    @FXML
    TextField txtSecondNumber;

    @FXML
    TextField txtTheAnswer;

    private int validateTextField(TextField t)
    {
        int first = Integer.MAX_VALUE;
        try
        {
            first  = Integer.parseInt(t.getText());
        }
        catch (Exception ex)
        {
            Dialog dlg = new Alert(Alert.AlertType.ERROR);
            dlg.setContentText("That is not a number");
            t.requestFocus();

            dlg.showAndWait();
        }
        return first;
    }

    @FXML
    private void btnAll_Click(ActionEvent e)
    {
//        System.out.println("btnAll_Click");

        Button thisButton = (Button)e.getSource();

        int first = validateTextField(txtFirstNumber);
        int second = validateTextField(txtSecondNumber);

        if (first == Integer.MAX_VALUE || second == Integer.MAX_VALUE)
        {
            return;
        }

        if (thisButton.getId().equals("btnPlus"))
        {
            txtTheAnswer.setText(String.format("%s", first + second));
        }
        else if (thisButton.getId().equals("btnMinus"))
        {
            txtTheAnswer.setText(String.format("%s", first - second));
        }
        else if (thisButton.getId().equals("btnMultiply"))
        {
            txtTheAnswer.setText(String.format("%s", first * second));
        }
        else if (thisButton.getId().equals("btnDivide"))
        {
            txtTheAnswer.setText(String.format("%s", first / second));
        }
//        int first = 0;
//        int second = 0;
//        try
//        {
//            first  = Integer.parseInt(txtFirstNumber.getText());
//        }
//        catch (Exception ex)
//        {
//            Dialog dlg = new Alert(Alert.AlertType.ERROR);
//            dlg.setContentText("That is not a number");
//            txtFirstNumber.requestFocus();
//
//            dlg.showAndWait();
//
//            return;
//        }
//        try
//        {
//            second  = Integer.parseInt(txtSecondNumber.getText());
//        }
//        catch (Exception ex)
//        {
//            Dialog dlg = new Alert(Alert.AlertType.ERROR);
//            dlg.setContentText("That is not a number");
//            txtSecondNumber.requestFocus();
//
//            dlg.showAndWait();
//
//            return;
//        }
//
//        txtTheAnswer.setText(String.format("%s", first + second));
    }
//    @FXML
//    private void btnPlus_Click(ActionEvent e)
//    {
//        int first = 0;
//        int second = 0;
//        try
//        {
//            first  = Integer.parseInt(txtFirstNumber.getText());
//        }
//        catch (Exception ex)
//        {
//            Dialog dlg = new Alert(Alert.AlertType.ERROR);
//            dlg.setContentText("That is not a number");
//            txtFirstNumber.requestFocus();
//
//            dlg.showAndWait();
//
//            return;
//        }
//        try
//        {
//            second  = Integer.parseInt(txtSecondNumber.getText());
//        }
//        catch (Exception ex)
//        {
//            Dialog dlg = new Alert(Alert.AlertType.ERROR);
//            dlg.setContentText("That is not a number");
//            txtSecondNumber.requestFocus();
//
//            dlg.showAndWait();
//
//            return;
//        }
//
//        txtTheAnswer.setText(String.format("%s", first + second));
//    }
//    @FXML
//    private void btnMinus_Click(ActionEvent e)
//    {
//        int first = 0;
//        int second = 0;
//        try
//        {
//            first  = Integer.parseInt(txtFirstNumber.getText());
//        }
//        catch (Exception ex)
//        {
//            Dialog dlg = new Alert(Alert.AlertType.ERROR);
//            dlg.setContentText("That is not a number");
//            txtFirstNumber.requestFocus();
//
//            dlg.showAndWait();
//
//            return;
//        }
//        try
//        {
//            second  = Integer.parseInt(txtSecondNumber.getText());
//        }
//        catch (Exception ex)
//        {
//            Dialog dlg = new Alert(Alert.AlertType.ERROR);
//            dlg.setContentText("That is not a number");
//            txtSecondNumber.requestFocus();
//
//            dlg.showAndWait();
//
//            return;
//        }
//
//        txtTheAnswer.setText(String.format("%s", first - second));
//    }
//    @FXML
//    private void btnMultiply_Click(ActionEvent e)
//    {
//        int first = 0;
//        int second = 0;
//        try
//        {
//            first  = Integer.parseInt(txtFirstNumber.getText());
//        }
//        catch (Exception ex)
//        {
//            Dialog dlg = new Alert(Alert.AlertType.ERROR);
//            dlg.setContentText("That is not a number");
//            txtFirstNumber.requestFocus();
//
//            dlg.showAndWait();
//
//            return;
//        }
//        try
//        {
//            second  = Integer.parseInt(txtSecondNumber.getText());
//        }
//        catch (Exception ex)
//        {
//            Dialog dlg = new Alert(Alert.AlertType.ERROR);
//            dlg.setContentText("That is not a number");
//            txtSecondNumber.requestFocus();
//
//            dlg.showAndWait();
//
//            return;
//        }
//
//        txtTheAnswer.setText(String.format("%s", first * second));
//    }
//    @FXML
//    private void btnDivide_Click(ActionEvent e)
//    {
//        int first = 0;
//        int second = 0;
//        try
//        {
//            first  = Integer.parseInt(txtFirstNumber.getText());
//        }
//        catch (Exception ex)
//        {
//            Dialog dlg = new Alert(Alert.AlertType.ERROR);
//            dlg.setContentText("That is not a number");
//            txtFirstNumber.requestFocus();
//
//            dlg.showAndWait();
//
//            return;
//        }
//        try
//        {
//            second  = Integer.parseInt(txtSecondNumber.getText());
//
//
//        }
//        catch (Exception ex)
//        {
//            Dialog dlg = new Alert(Alert.AlertType.ERROR);
//            dlg.setContentText("That is not a number");
//            txtSecondNumber.requestFocus();
//
//            dlg.showAndWait();
//
//            return;
//        }
//
//        if (second == 0)
//        {
//            Dialog dlg = new Alert(Alert.AlertType.ERROR);
//            dlg.setContentText("Divided by zero not allowed!");
//            txtSecondNumber.requestFocus();
//
//            dlg.showAndWait();
//
//            return;
//        }
//        txtTheAnswer.setText(String.format("%s", first / second));
//    }

    @Override
    public void initialize(URL url, ResourceBundle rb)
    {
        // TODO
    }    
    
}
