/**AUTHOR: Appendix(Zheng YU)
 * DATE: 2014.12.16
 * 
 * Software function: simple easy-to-use calculator, multi-base 32-bit, designed for programmer,
 * 						who may find it useful when he write asm-program
 * 
 * Copyright @author Appendix(Zheng YU)
 */

package com.thepackage;

import java.awt.*;
import java.awt.event.*;

import javax.swing.*;
import javax.swing.event.*;

public class Calculator extends JFrame implements ActionListener, ChangeListener{
	JLabel screen;
	JButton num0, num1, num2, num3, num4, num5, num6, num7, num8, num9, numa, numb, numc, numd, nume, numf;
	JButton operand0, operand1, operand2, operand3, operand4;
	JButton clr;
	JSlider slider;
	long first, second;
	int base;
	int operand;
	
	public static void main(String args[]) {
		Calculator calculator = new Calculator();
		calculator.setSize(400, 400);
		calculator.setVisible(true);
		calculator.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
	}
	
	public Calculator() {
//define all the components
		super("Multi-base 32-bit Calculator");
		screen = new JLabel("", JLabel.RIGHT);
		num0 = new JButton("0");
		num1 = new JButton("1");
		num2 = new JButton("2");
		num3 = new JButton("3");
		num4 = new JButton("4");
		num5 = new JButton("5");
		num6 = new JButton("6");
		num7 = new JButton("7");
		num8 = new JButton("8");
		num9 = new JButton("9");
		numa = new JButton("A");
		numb = new JButton("B");
		numc = new JButton("C");
		numd = new JButton("D");
		nume = new JButton("E");
		numf = new JButton("F");
		operand0 = new JButton("=");
		operand1 = new JButton("+");
		operand2 = new JButton("-");
		operand3 = new JButton("*");
		operand4 = new JButton("/");
		clr = new JButton("C");
		num0.addActionListener(this);
		num1.addActionListener(this);
		num2.addActionListener(this);
		num3.addActionListener(this);
		num4.addActionListener(this);
		num5.addActionListener(this);
		num6.addActionListener(this);
		num7.addActionListener(this);
		num8.addActionListener(this);
		num9.addActionListener(this);
		numa.addActionListener(this);
		numb.addActionListener(this);
		numc.addActionListener(this);
		numd.addActionListener(this);
		nume.addActionListener(this);
		numf.addActionListener(this);
		operand0.addActionListener(this);
		operand1.addActionListener(this);
		operand2.addActionListener(this);
		operand3.addActionListener(this);
		operand4.addActionListener(this);
		clr.addActionListener(this);
		slider = new JSlider(JSlider.VERTICAL, 2, 16, 10);
		slider.setMajorTickSpacing(2);
		slider.setMinorTickSpacing(2);
		slider.setPaintTicks(true);
		slider.setPaintLabels(true);
		slider.setSnapToTicks(true);
		slider.addChangeListener(this);
		
//set layout
		Container c = this.getContentPane();
		GridBagLayout gbl = new GridBagLayout();
		GridBagConstraints gbc = new GridBagConstraints();
		c.setLayout(gbl);
		gbc.fill = GridBagConstraints.BOTH;
		gbc.weightx = 1;
		gbc.weighty = 1;
		
		gbc.gridx = 0;
		gbc.gridy = 0;
		gbc.gridwidth = 7;
		gbc.gridheight = 1;
		gbl.setConstraints(screen, gbc);
		c.add(screen);
		
		gbc.gridwidth = 1;
		gbc.gridheight = 1;
		gbc.gridx = 0;
		gbc.gridy = 1;
		gbl.setConstraints(num0, gbc);
		c.add(num0);
		
		gbc.gridx = 1;
		gbc.gridy = 1;
		gbl.setConstraints(num1, gbc);
		c.add(num1);
		
		gbc.gridx = 2;
		gbc.gridy = 1;
		gbl.setConstraints(num2, gbc);
		c.add(num2);
		
		gbc.gridx = 3;
		gbc.gridy = 1;
		gbl.setConstraints(num3, gbc);
		c.add(num3);
		

		gbc.gridx = 0;
		gbc.gridy = 2;
		gbl.setConstraints(num4, gbc);
		c.add(num4);
		
		gbc.gridx = 1;
		gbc.gridy = 2;
		gbl.setConstraints(num5, gbc);
		c.add(num5);
		
		gbc.gridx = 2;
		gbc.gridy = 2;
		gbl.setConstraints(num6, gbc);
		c.add(num6);
		
		gbc.gridx = 3;
		gbc.gridy = 2;
		gbl.setConstraints(num7, gbc);
		c.add(num7);
		
		gbc.gridx = 0;
		gbc.gridy = 3;
		gbl.setConstraints(num8, gbc);
		c.add(num8);
		
		gbc.gridx = 1;
		gbc.gridy = 3;
		gbl.setConstraints(num9, gbc);
		c.add(num9);
		
		gbc.gridx = 2;
		gbc.gridy = 3;
		gbl.setConstraints(numa, gbc);
		c.add(numa);
		
		gbc.gridx = 3;
		gbc.gridy = 3;
		gbl.setConstraints(numb, gbc);
		c.add(numb);
		
		gbc.gridx = 0;
		gbc.gridy = 4;
		gbl.setConstraints(numc, gbc);
		c.add(numc);
		
		gbc.gridx = 1;
		gbc.gridy = 4;
		gbl.setConstraints(numd, gbc);
		c.add(numd);
		
		gbc.gridx = 2;
		gbc.gridy = 4;
		gbl.setConstraints(nume, gbc);
		c.add(nume);
		
		gbc.gridx = 3;
		gbc.gridy = 4;
		gbl.setConstraints(numf, gbc);
		c.add(numf);
		
		gbc.gridx = 4;
		gbc.gridy = 2;
		gbl.setConstraints(operand1, gbc);
		c.add(operand1);
		
		gbc.gridx = 5;
		gbc.gridy = 2;
		gbl.setConstraints(operand2, gbc);
		c.add(operand2);
		
		gbc.gridx = 4;
		gbc.gridy = 3;
		gbl.setConstraints(operand3, gbc);
		c.add(operand3);
		
		gbc.gridx = 5;
		gbc.gridy = 3;
		gbl.setConstraints(operand4, gbc);
		c.add(operand4);
		
		gbc.gridwidth = 2;
		gbc.gridheight = 1;
		gbc.gridx = 4;
		gbc.gridy = 4;
		gbl.setConstraints(operand0, gbc);
		c.add(operand0);
		
		gbc.gridwidth = 2;
		gbc.gridheight = 1;
		gbc.gridx = 4;
		gbc.gridy = 1;
		gbl.setConstraints(clr, gbc);
		c.add(clr);
	
		gbc.gridwidth = 2;
		gbc.gridheight = 4;
		gbc.gridx = 8;
		gbc.gridy = 0;
		gbl.setConstraints(slider, gbc);
		c.add(slider);
		
		first = second = 0;
		operand = 0;
		this.base = 10;
		screen.setText("");
		
		int base = this.base;	
		num0.setEnabled(base-- > 0 ? true : false);
		num1.setEnabled(base-- > 0 ? true : false);
		num2.setEnabled(base-- > 0 ? true : false);
		num3.setEnabled(base-- > 0 ? true : false);
		num4.setEnabled(base-- > 0 ? true : false);
		num5.setEnabled(base-- > 0 ? true : false);
		num6.setEnabled(base-- > 0 ? true : false);
		num7.setEnabled(base-- > 0 ? true : false);
		num8.setEnabled(base-- > 0 ? true : false);
		num9.setEnabled(base-- > 0 ? true : false);
		numa.setEnabled(base-- > 0 ? true : false);
		numb.setEnabled(base-- > 0 ? true : false);
		numc.setEnabled(base-- > 0 ? true : false);
		numd.setEnabled(base-- > 0 ? true : false);
		nume.setEnabled(base-- > 0 ? true : false);
		numf.setEnabled(base-- > 0 ? true : false);			
	}
	

	public void actionPerformed(ActionEvent click) {
//按钮为数字的时候
		if (click.getSource() == num0 || 
			click.getSource() == num1 || 
			click.getSource() == num2 ||
			click.getSource() == num3 ||
			click.getSource() == num4 ||
			click.getSource() == num5 ||
			click.getSource() == num6 ||
			click.getSource() == num7 ||
			click.getSource() == num8 ||
			click.getSource() == num9 ||
			click.getSource() == numa ||
			click.getSource() == numb ||
			click.getSource() == numc ||
			click.getSource() == numd ||
			click.getSource() == nume ||
			click.getSource() == numf ) {

			String now;
			now = screen.getText();
			if (now.equals("0"))
				now = "";
			if (now.length() >= 8)
				return;
			
			String x = null;
			if (click.getSource() == num0)
				x = "0";
			else if (click.getSource() == num1)
				x = "1";
			else if (click.getSource() == num2)
				x = "2";
			else if (click.getSource() == num3)
				x = "3";
			else if (click.getSource() == num4)
				x = "4";
			else if (click.getSource() == num5)
				x = "5";
			else if (click.getSource() == num6)
				x = "6";
			else if (click.getSource() == num7)
				x = "7";
			else if (click.getSource() == num8)
				x = "8";
			else if (click.getSource() == num9)
				x = "9";
			else if (click.getSource() == numa)
				x = "A";
			else if (click.getSource() == numb)
				x = "B";
			else if (click.getSource() == numc)
				x = "C";
			else if (click.getSource() == numd)
				x = "D";
			else if (click.getSource() == nume)
				x = "E";
			else if (click.getSource() == numf)
				x = "F";
			
			now = now + x;
			screen.setText(now);			
		} else
//按钮为运算符的时候
			if (click.getSource() == operand0 || 
				click.getSource() == operand1 || 
				click.getSource() == operand2 ||
				click.getSource() == operand3 ||
				click.getSource() == operand4) {
				
				String now;
				now = screen.getText();
				second = Long.parseLong(now, base);
	
				switch (operand) {
				case 0: first = second; break;
				case 1: first += second; break;
				case 2: first -= second; break;
				case 3: first *= second; break;
				case 4: if (second == 0) {
							first = 0;
							screen.setText("0");							
							}
						else
							first /= second; 
						break;
				
				default: break;
				}
				
				if (click.getSource() == operand0) {
					operand = 0;
					String result = Long.toString(first, base);
					if (result.length() > 8)
						result = result.substring(result.length() - 8, result.length() - 1);
					screen.setText(result);					
					return;
				} else
					if (click.getSource() == operand1) 
						operand = 1;
					else
						if (click.getSource() == operand2)
							operand = 2;
						else
							if (click.getSource() == operand3)
								operand = 3;
							else
								if (click.getSource() == operand4)
									operand = 4;
				screen.setText("");
			}
			else
				if (click.getSource() == clr) {
					operand = 0;
					first = second = 0;
					screen.setText("0");
				}
		
		

	}
	
	
	public void stateChanged(ChangeEvent slide) {
		int base = slider.getValue();
		this.base = base;
		
		num0.setEnabled(base-- > 0 ? true : false);
		num1.setEnabled(base-- > 0 ? true : false);
		num2.setEnabled(base-- > 0 ? true : false);
		num3.setEnabled(base-- > 0 ? true : false);
		num4.setEnabled(base-- > 0 ? true : false);
		num5.setEnabled(base-- > 0 ? true : false);
		num6.setEnabled(base-- > 0 ? true : false);
		num7.setEnabled(base-- > 0 ? true : false);
		num8.setEnabled(base-- > 0 ? true : false);
		num9.setEnabled(base-- > 0 ? true : false);
		numa.setEnabled(base-- > 0 ? true : false);
		numb.setEnabled(base-- > 0 ? true : false);
		numc.setEnabled(base-- > 0 ? true : false);
		numd.setEnabled(base-- > 0 ? true : false);
		nume.setEnabled(base-- > 0 ? true : false);
		numf.setEnabled(base-- > 0 ? true : false);	
		
		
	}
}
