#pragma once

#include <Windows.h>


typedef struct _controllerState {
    // Overall state
    bool isConnected;

    // Joy states
    double leftThumbX;   // (-1->1)
    double leftThumbY;   // (-1->1)
    double rightThumbX;  // (-1->1)
    double rightThumbY;  // (-1->1)
    double leftTrigger;  // (0->1)
    double rightTrigger; // (0->1)

    // Button states
    bool buttonA;
    bool buttonB;
    bool buttonX;
    bool buttonY;

    bool DpadLeft;
    bool DpadRight;
    bool DpadUp;
    bool DpadDown;

    bool leftThumb;
    bool rightThumb;

    bool leftShoulder;
    bool rightShoulder;

    bool start;
    bool back;
} controllerState;


class ControllerInterface {
public:
    /**
    * Constructs a class with the controller number to be default as 1
    * and connecting to an x-box controller
    **/
    ControllerInterface();

    /**
    * Constructs a class setting the controller number and input type as specified
    * Definition of controller type for use when running softare to be controllable
    * by keyboard and xbox controller independently.
    * Use keyboard for testing at home if you do not have a controller
    * @param playerNum number of the controller being communicated with
    * (specified by the controller) as an integer in the range 1-4
    * @param input 0 for X-Box controller and 1 for keyboard
    */
    ControllerInterface(unsigned long playerNum, int input_type);

    /**
    * Gets the state of all inputs from the controller
    * @returns struct as the state of all controller inputs.
    * Return type is as defined in the struct above.
    */
    controllerState GetState();

    /**
    * Check whether there is a controller connected currently based on the class instantiation.
    * If keyboard mode is used, this will always return true
    * @returns true if controller is currently connected
    */
    bool IsConnected();

    /**
    * Helpful function for printing out the state of the whole controller (based on what you
    * would have got from the GetState function).
    * @param state current state of the controller (as returned by ControllerInterface::GetState()
    */
    static void printControllerState(controllerState state);

private:
    // You do not need to (and cannot) interface with these functions
    // They allow for independent control based on the CONTROL_TYPE defined above
    controllerState GetKeyboardState();
    controllerState GetControllerState();

private:
    unsigned long controllerNum_;
    int input_type_;
};