

#include "InputManager.h"
dae::InputManager::InputManager()
{
	//Input* input{ Input::GetInstance() };
	
	m_ButtonA = std::make_unique<JumpCommand>();
	m_ButtonB = std::make_unique<DuckCommand>();
	m_ButtonY = std::make_unique<FartCommand>();
	m_ButtonRightShoulder = std::make_unique<FireGunCommand>();
}

void dae::InputManager::ProcessInput()
{
	//// todo: read the input
	
	//zeroize the  state
	ZeroMemory(&m_PreviousState, sizeof(XINPUT_STATE));
	ZeroMemory(&m_CurrentState, sizeof(XINPUT_STATE));

	//get the state
	XInputGetState(0, &m_CurrentState);
	HandleInput();
}

void dae::InputManager::Update()
{
	CopyMemory(&m_PreviousState, &m_CurrentState, sizeof(XINPUT_STATE));
	ZeroMemory(&m_CurrentState, sizeof(XINPUT_STATE));
	XInputGetState(0, &m_CurrentState);

	auto buttonchanges = m_CurrentState.Gamepad.wButtons ^ m_PreviousState.Gamepad.wButtons;
	buttonPressedThisFrame = buttonchanges & m_CurrentState.Gamepad.wButtons;
	
	if(buttonPressedThisFrame>0)
	{
		std::cout << "pressed\n";
	}
	buttonReleasedThisFrame = buttonchanges & (~m_CurrentState.Gamepad.wButtons);

}

bool dae::InputManager::IsPressed(ControllerButton button) const
{
	// todo: return whether the given button is pressed or not.
	if (m_CurrentState.Gamepad.wButtons & (int)button)
	{
		
		//if (buttonPressedThisFrame)
		{
			//std::cout << "is pressed/n";
			return true;
		}
	}
	return false;
}

bool dae::InputManager::IsDownThisFrame(unsigned int button) const
{
	return buttonPressedThisFrame & button;
}

bool dae::InputManager::IsUpThisFrame(unsigned int button) const
{
	return buttonReleasedThisFrame & button;

}

bool dae::InputManager::IsPressed(unsigned int button) const
{
	return m_CurrentState.Gamepad.wButtons & button;
}


void dae::InputManager::HandleInput()
{
	
	if (IsPressed(ControllerButton::ButtonA))
	{
		std::cout << "Button A has been pressed" << std::endl;
		m_ButtonA->Execute();
	}
	else if (IsPressed(ControllerButton::ButtonB))
	{
		std::cout << "Button B has been pressed" << std::endl;
		m_ButtonB->Execute();
	}
	else if (IsPressed(ControllerButton::ButtonY))
	{
		std::cout << "Button Y has been pressed" << std::endl;
		m_ButtonY->Execute();
	}
	else if (IsPressed(ControllerButton::ButtonRightShoulder))
	{
		std::cout << "Button RightShoulder has been pressed" << std::endl;
		m_ButtonRightShoulder->Execute();
	}
}
