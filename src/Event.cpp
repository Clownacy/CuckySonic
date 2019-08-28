#include "SDL_events.h"
#include "Input.h"

bool HandleEvents()
{
	bool noExit = true;
	bool focusYield = false;
	
	while (SDL_PollEvent(NULL) || focusYield)
	{
		//Wait for next event (instantaneous if focus gained, just polling then stopping when done)
		SDL_Event event;
		SDL_WaitEvent(&event);
		
		switch (event.type)
		{
			case SDL_QUIT:	//Window/game is closed
				noExit = false;
				break;
			
			case SDL_WINDOWEVENT:
				switch (event.window.event)
				{
					case SDL_WINDOWEVENT_FOCUS_GAINED: //Window focused, unyield
						focusYield = false;
						break;
					case SDL_WINDOWEVENT_FOCUS_LOST: //Window unfocused, yield until refocused
						focusYield = true;
						ClearControllerInput();
						break;
					default:
						break;
				}
				break;
				
			case SDL_KEYDOWN:	//Input events
			case SDL_KEYUP:
				HandleInputEvent(&event);
				break;
				
			default:	//Unhandled just to be handled by our operating system
				break;
		}
	}
	
	//Update our input (such as pressed keys, or analogue stick input)
	UpdateInput();
	
	return noExit;
}
