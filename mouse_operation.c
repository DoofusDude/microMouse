///
/// @file       mouse_operation.c
/// @author     Kyeong Soo (Joseph) Kim <k.s.kim@swansea.ac.uk>
/// @date       2012-02-21
///
/// @brief      Implements functions for mouse operation modes.
///
/// @remarks    This program is based on Dr Tim Davies' assembly version of
///             micro mouse program and the C port of it by Mr Gareth Evans.
///
/// @copyright  Copyright (C) 2012 Swansea University. All rights reserved.
///
/// @copyright  This software is written and distributed under the GNU General
///             Public License Version 2 (http://www.gnu.org/licenses/gpl-2.0.html).
///             You must not remove this notice, or any other, from this software.
///


#include "mouse.h"	// for the declaration of types, constants, variables and functions


void AvoidObstacle() {
   mouseMode = MOUSE_MODE_OBSTACLE_AVOIDING;

    for (;;) {
    
        ControlMouse(MOUSE_ACTION_FORWARD);
        
        if (!touchBarFrontLeft && !touchBarFrontRight) {
        
             if (!infraredFrontLeft && !infraredFrontRight) {
              }
	   
              else if (infraredFrontLeft) {
                // left sensor detects; avoid left obstacle
				            ControlMouse(MOUSE_ACTION_TURNRIGHT);
				            Delay(20);
              }
              else if (infraredFrontRight) {
                // right sensor detects; avoid right obstacle
				          	ControlMouse(MOUSE_ACTION_TURNLEFT);
			              Delay(20);
              }
	            else {
				    	ControlMouse(MOUSE_ACTION_STOP);
				    	Delay(20);
				    	ControlMouse(MOUSE_ACTION_REVERSE);
				    	ControlMouse(MOUSE_ACTION_STOP);
				    	Delay(20);
			        ControlMouse(MOUSE_ACTION_TURNAROUND);
				    	Delay(20);
			        } 
        }
         
        else if (touchBarFrontLeft) {
        	ControlMouse(MOUSE_ACTION_STOP);
				  Delay(20);
				 	ControlMouse(MOUSE_ACTION_REVERSE);
				  ControlMouse(MOUSE_ACTION_STOP);
				  Delay(20);
          ControlMouse(MOUSE_ACTION_TURNRIGHT);
				  Delay(20);
        } 
        
        else if (touchBarFrontRight){
          ControlMouse(MOUSE_ACTION_STOP);
				  Delay(20);
				 	ControlMouse(MOUSE_ACTION_REVERSE);
				 	ControlMouse(MOUSE_ACTION_STOP);
				  Delay(20);
        	ControlMouse(MOUSE_ACTION_TURNLEFT);
			    Delay(20);
        } 
	     }
    }

void LineFollowing(){
      
  byte LSFRight, LSFLeft, LSRRight, LSRLeft;

  mouseMode = MOUSE_MODE_OBSTACLE_AVOIDING;
    
  
    for (;;) {
        LSFRight = ADCFrontRight();
        LSFLeft = ADCFrontLeft();
    
       // first move forward
       // ControlMouse(MOUSE_ACTION_FORWARD);
        

        
       
    } // end of for() loop
}


void Combat()
{
    // fill your code here for the combat mode    
}


// debug mode with simple command-line interface
void Debug()
{
    byte command;

    // display a welcome message with a list of commands
    SCISendNewLine();
    SCISendStr("Welcome to the debug mode of EG-252 sample micromouse programme!\r\n");
    SCISendNewLine();
    SCISendNewLine();
    SCISendStr("List of available commands:\r\n");
    SCISendStr("F\tForward\r\n");
    SCISendStr("R\tReverse\r\n");
    SCISendStr("S\tStop\r\n");
    SCISendStr("A\troate Anticlockwise\r\n");
    SCISendStr("C\trotate Clockwise\r\n");
    SCISendStr("V\tVeer left Clockwise\r\n");
    SCISendStr("B\tVeer right Clockwise\r\n");
    SCISendStr("+\tIncrement speed by 256 units\r\n");
    SCISendStr("-\tDecrement speed by 256 units\r\n");
    SCISendStr("D\tDisplay ADC value 7 through 0\r\n");
    SCISendStr("P\tDisplay PTA as binary number\r\n");

  while (1) {
        // display prompt and wait for a user input
        SCIDisplayPrompt();
        command = SCIGetChar();
        
        // TEST
        SCIDisplayBitString(command);
        SCIDisplayBitString((char)'F');
        SCIDisplayBitString((byte)'R');
        SCIDisplayBitString('S');
        if ((int)command == 70)
        {
            SCISendStr("Forward ... \r\n");
        }
        if ((command & 0b01111111) == 0x52)
        {
            SCISendStr("Reverse ... \r\n");
        }
        if ((int)command > 256) 
        {
            SCISendStr("Greater than 256\r\n");
        }
        else if ((int)command > 128) 
        {
            SCISendStr("Greater than 128\r\n");
        }
        else if ((int)command > 64)
        {
            SCISendStr("Greater than 64\r\n");
        }
        else
        {
            SCISendStr("Less than or eqal to 64\r\n");
        }
        // TEST

        switch(command) {
            case 70:  // ascii code for 'F'
                SCISendStr("Forward ... \r\n");
                break;
            case 82:  // ascii code for 'R'
                SCISendStr("Reverse ... \r\n");
                break;
            case 83:  // ascii code for 'S'
                SCISendStr("Stop ... \r\n");
                break;
            case 'A':
                break;
            case 'C':
                break;        
            case '+':
                break;
            case '-':
                break;
            case 'D':
                break;
            case 'P':
                break;
            case 'V':
                break;
            case 'B':
                break;
            case '?':
                break;
            default:
                break;
        }
    }   // end of while ()
}


// simple test mode for testing functions
void Test()
{
  int opDelay = 10000;
  
  while (1) {
    ControlMouse(MOUSE_ACTION_FORWARD);
   // Delay(opDelay);
  /*
    ControlMouse(MOUSE_ACTION_FORWARD);
    Delay(opDelay);
    ControlMouse(MOUSE_ACTION_REVERSE);
    Delay(opDelay);
    ControlMouse(MOUSE_ACTION_TURNLEFT);
    Delay(opDelay);
    ControlMouse(MOUSE_ACTION_TURNRIGHT);
    Delay(opDelay);
    ControlMouse(MOUSE_ACTION_TURNAROUND);
    Delay(opDelay);
    ControlMouse(MOUSE_ACTION_STOP);
    Delay(opDelay);
    */
  }
}


// ADC test mode for line following sensors
void ADCTest()
{
    while (1)
    {
        ADCRead();
    }
}