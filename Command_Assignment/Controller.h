#pragma once
#include <map>
#include <Windows.h>
#include <Xinput.h>
namespace dae
{
	class Controller final
	{
		class ControllerImpl;
		ControllerImpl* pImpl;
	public:
		enum class ControllerButton
		{
			ButtonA = XINPUT_GAMEPAD_A,
			ButtonB = XINPUT_GAMEPAD_B,
			ButtonX = XINPUT_GAMEPAD_X,
			ButtonY = XINPUT_GAMEPAD_Y,
			DpadUp = XINPUT_GAMEPAD_DPAD_UP,
			DpadDown = XINPUT_GAMEPAD_DPAD_DOWN,
			DpadLeft = XINPUT_GAMEPAD_DPAD_LEFT,
			DpadRight = XINPUT_GAMEPAD_DPAD_RIGHT,
			ButtonStart = XINPUT_GAMEPAD_START,
			ButtonBack = XINPUT_GAMEPAD_BACK,
			StickLeftThumb = XINPUT_GAMEPAD_LEFT_THUMB,
			StickRightThumb = XINPUT_GAMEPAD_RIGHT_THUMB,
			ButtonLeftShoulder = XINPUT_GAMEPAD_LEFT_SHOULDER,
			ButtonRightShoulder = XINPUT_GAMEPAD_RIGHT_SHOULDER

		};
		void Update();

		bool IsDown(ControllerButton button) const;
		bool IsUp(ControllerButton button) const;
		bool IsPressed(ControllerButton button) const;

		explicit Controller(int controllerindex);
		~Controller();

	};
}
