#include <vld.h>
#include <thread>
#include "InputManager.h"

using namespace dae;

int main()
{
	auto inputManager = InputManager();
	auto t = std::chrono::high_resolution_clock::now();

	while (true)
	{
		inputManager.ProcessInput();
		inputManager.Update();
		
	
		//if (inputManager.IsPressed(ControllerButton::ButtonA))
		//	std::cout << "Button A has been pressed" << std::endl;
		//else if (inputManager.IsPressed(ControllerButton::ButtonB))
		//	std::cout << "Button B has been pressed" << std::endl;
		//else if (inputManager.IsPressed(ControllerButton::ButtonY))
		//	std::cout << "Button Y has been pressed" << std::endl;
		//else if (inputManager.IsPressed(ControllerButton::DpadUp))
		//	std::cout << "Button DpadUp has been pressed" << std::endl;
		//else if (inputManager.IsPressed(ControllerButton::DpadDown))
		//	std::cout << "Button DpadDown has been pressed" << std::endl;
		//else if (inputManager.IsPressed(ControllerButton::DpadLeft))
		//	std::cout << "Button DpadLeft has been pressed" << std::endl;
		//else if (inputManager.IsPressed(ControllerButton::DpadRight))
		//	std::cout << "Button DpadRight has been pressed" << std::endl;
		//else if (inputManager.IsPressed(ControllerButton::ButtonStart))
		//	std::cout << "Button start has been pressed" << std::endl;
		//else if (inputManager.IsPressed(ControllerButton::ButtonBack))
		//	std::cout << "Button back has been pressed" << std::endl;
		//else if (inputManager.IsPressed(ControllerButton::StickLeftThumb))
		//	std::cout << "Button left stick has been processed" << std::endl;
		//else if (inputManager.IsPressed(ControllerButton::StickRightThumb))
		//	std::cout << "Button right stick has been pressed" << std::endl;
		//else if (inputManager.IsPressed(ControllerButton::ButtonLeftShoulder))
		//	std::cout << "Button LEFT SHOULDER has been pressed" << std::endl;
		//else if (inputManager.IsPressed(ControllerButton::ButtonRightShoulder))
		//	std::cout << "Button RIGHT SHOULDER has been pressed" << std::endl;
		
		 if (inputManager.IsPressed((int)ControllerButton::ButtonX))
		{
			std::cout << "Button X has been pressed" << std::endl;
			break;
		}

		t += std::chrono::milliseconds(16); // we want 60 fps
		std::this_thread::sleep_until(t);
	}
	std::cout << "Let's end." << std::endl;

}
