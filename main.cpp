#include "include/Simulation.h"

int main()
{
    //Create simulation
    Simulation simulation;

    //Main Loop
    while (simulation.Running()) 
    {
        //Update 
        simulation.Update();

        //Render frame
        simulation.Render();
    }

    return 0;
}