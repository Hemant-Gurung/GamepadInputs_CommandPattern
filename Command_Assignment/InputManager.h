#pragma once
#define WIN32_LEAN_AND_MEAN
#include  <iostream>
#include <map>
#include <Windows.h>
#include <Xinput.h>
#include "Singleton.h"
#include "Command.h"
#include <vector>
#include "Singleton.h"


#pragma comment(lib,"XInput.lib")
#pragma comment(lib,"XInput9_1_0.lib")

namespace dae
{
	enum class ControllerButton
	{
		ButtonA = XINPUT_GAMEPAD_A,
		ButtonB = XINPUT_GAMEPAD_B,
		ButtonX = XINPUT_GAMEPAD_X,
		ButtonY = XINPUT_GAMEPAD_Y,
		DpadUp  = XINPUT_GAMEPAD_DPAD_UP,
		DpadDown = XINPUT_GAMEPAD_DPAD_DOWN,
		DpadLeft = XINPUT_GAMEPAD_DPAD_LEFT,
		DpadRight = XINPUT_GAMEPAD_DPAD_RIGHT,
		ButtonStart= XINPUT_GAMEPAD_START,
		ButtonBack = XINPUT_GAMEPAD_BACK,
		StickLeftThumb = XINPUT_GAMEPAD_LEFT_THUMB,
		StickRightThumb = XINPUT_GAMEPAD_RIGHT_THUMB,
		ButtonLeftShoulder = XINPUT_GAMEPAD_LEFT_SHOULDER,
		ButtonRightShoulder = XINPUT_GAMEPAD_RIGHT_SHOULDER

	};

	class InputManager final
	{
		class InputManagetImpl;
		InputManagetImpl* pImpl;
	public:
		InputManager();
		~InputManager();

		void Update();
		void ProcessInput();
		void HandleInput();

		bool IsDown(unsigned int button) const;
		bool IsUp(unsigned int button) const;
		bool IsPressed(unsigned int button) const;

	private:
		/*XINPUT_STATE m_CurrentState{};
		XINPUT_STATE m_PreviousState{};
		XINPUT_KEYSTROKE m_CurrentKeyStroke{};
		WORD buttonPressedThisFrame;
		WORD buttonReleasedThisFrame;*/

		//
		//int _controllerIndex;
		////XINPUT_KEYSTROKE m_CurrentKeyStroke;
		std::unique_ptr<Command> m_ButtonA{};
		std::unique_ptr<Command> m_ButtonB{};
		std::unique_ptr<Command> m_ButtonRightShoulder{};
		std::unique_ptr<Command> m_ButtonY{};

		
	};


	//class Input final:public Singleton<Input>
	//{
	//	using controllerkey = std::pair<unsigned, dae::ControllerButton>;
	//	using ControllerCommandMap = std::map<controllerkey, std::unique_ptr<Command>>;
	//	ControllerCommandMap m_consoleCommands;
	//	std::vector<std::unique_ptr<dae::ControllerButton>> m_controllers{};
	//public:

	//
	//};



	///isdown is up is pressed
}