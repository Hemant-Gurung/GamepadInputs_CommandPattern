

#include "InputManager.h"
dae::InputManager::InputManager()
	:m_CurrentState{},
	m_PreviousState{}
{
	//Input* input{ Input::GetInstance() };
	
	m_ButtonA = std::make_unique<JumpCommand>();
	m_ButtonB = std::make_unique<DuckCommand>();
	m_ButtonY = std::make_unique<FartCommand>();
	m_ButtonRightShoulder = std::make_unique<FireGunCommand>();

	ZeroMemory(&m_PreviousState, sizeof(XINPUT_STATE));
	ZeroMemory(&m_CurrentState, sizeof(XINPUT_STATE));

	                               
	//get the state
	XInputGetState(0, &m_CurrentState);
}

void dae::InputManager::ProcessInput()
{
	//// todo: read the input
	
	//zeroize the  state
	
	
}

void dae::InputManager::Update()
{
	CopyMemory(&m_PreviousState, &m_CurrentState, sizeof(XINPUT_STATE));
	ZeroMemory(&m_CurrentState, sizeof(XINPUT_STATE));
	XInputGetState(0, &m_CurrentState);

	auto buttonchanges = m_CurrentState.Gamepad.wButtons ^ m_PreviousState.Gamepad.wButtons;
	
	buttonPressedThisFrame = buttonchanges & m_CurrentState.Gamepad.wButtons;
	
	buttonReleasedThisFrame = buttonchanges & (~m_CurrentState.Gamepad.wButtons);
	HandleInput();
}

void dae::InputManager::HandleInput()
{

	if (IsDownThisFrame(static_cast<unsigned int>(ControllerButton::ButtonA)))
	{
		std::cout << " ButtonA is down this frame\n";

		m_ButtonA->Execute();
	}
	else if (IsDownThisFrame(static_cast<unsigned int>(ControllerButton::ButtonB)))
	{
		std::cout << "Button B is down this frame\n";

		m_ButtonB->Execute();
	}
	else if (IsDownThisFrame(static_cast<unsigned int>(ControllerButton::ButtonY)))
	{
		std::cout << "Button Y is down this frame\n";

		m_ButtonY->Execute();
	}
	else if (IsDownThisFrame(static_cast<unsigned int>(ControllerButton::ButtonRightShoulder)))
	{
		std::cout << "Button RB is down this frame\n";
		m_ButtonRightShoulder->Execute();
	}

	//Released
	if (IsUpThisFrame(static_cast<unsigned int>(ControllerButton::ButtonY)))
	{
		std::cout << "Button Y is Up this frame\n";

		m_ButtonY->Execute();
	}
	else if (IsUpThisFrame(static_cast<unsigned int>(ControllerButton::ButtonA)))
	{
		std::cout << "Button A is Up this frame\n";

		m_ButtonA->Execute();
	}
	if (IsUpThisFrame(static_cast<unsigned int>(ControllerButton::ButtonB)))
	{
		std::cout << "Button B is Up this frame\n";

		m_ButtonB->Execute();
	}
	if (IsUpThisFrame(static_cast<unsigned int>(ControllerButton::ButtonRightShoulder)))
	{
		std::cout << "Button RB is Up this frame\n";

		m_ButtonRightShoulder->Execute();
	}
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

