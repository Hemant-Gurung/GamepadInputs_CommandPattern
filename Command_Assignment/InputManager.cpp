

#include "InputManager.h"

using namespace dae;
class InputManager::InputManagetImpl
{

	XINPUT_STATE m_CurrentState{};
	XINPUT_STATE m_PreviousState{};
	XINPUT_KEYSTROKE m_CurrentKeyStroke{};
	WORD buttonPressedThisFrame;
	WORD buttonReleasedThisFrame;


	int _controllerIndex;
public:
	InputManagetImpl()
	{
		ZeroMemory(&m_PreviousState, sizeof(XINPUT_STATE));
		ZeroMemory(&m_CurrentState, sizeof(XINPUT_STATE));
		//get the state
		XInputGetState(0, &m_CurrentState);
	}

	void Update()
	{
		CopyMemory(&m_PreviousState, &m_CurrentState, sizeof(XINPUT_STATE));
		ZeroMemory(&m_CurrentState, sizeof(XINPUT_STATE));
		XInputGetState(0, &m_CurrentState);

		auto buttonchanges = m_CurrentState.Gamepad.wButtons ^ m_PreviousState.Gamepad.wButtons;

		buttonPressedThisFrame = buttonchanges & m_CurrentState.Gamepad.wButtons;

		buttonReleasedThisFrame = buttonchanges & (~m_CurrentState.Gamepad.wButtons);

	}

	bool IsDownThisFrame(unsigned int button) const{return buttonPressedThisFrame & button;}

	bool IsUpThisFrame(unsigned int button) const{return buttonReleasedThisFrame & button;}

	bool IsPressed(unsigned int button) const {return m_CurrentState.Gamepad.wButtons & button;}

};


InputManager::InputManager()
{
	pImpl = new InputManagetImpl();

	//buttons for interraction
	m_ButtonA = std::make_unique<JumpCommand>();
	m_ButtonB = std::make_unique<DuckCommand>();
	m_ButtonY = std::make_unique<FartCommand>();
	m_ButtonRightShoulder = std::make_unique<FireGunCommand>();
}

void InputManager::ProcessInput()
{}

InputManager::~InputManager()
{
	delete pImpl;
}

void InputManager::Update()
{
	pImpl->Update();
	HandleInput();
}

bool InputManager::IsDown(unsigned button) const{return pImpl->IsDownThisFrame(static_cast<unsigned int>(button));}

bool InputManager::IsUp(unsigned button) const{return pImpl->IsUpThisFrame(static_cast<unsigned int>(button));}

bool InputManager::IsPressed(unsigned button) const{return pImpl->IsPressed(static_cast<unsigned int>(button));}

void InputManager::HandleInput()
{

	if (IsDown(static_cast<unsigned int>(ControllerButton::ButtonA)))
	{
		std::cout << " ButtonA is down this frame\n";
		m_ButtonA->Execute();
	}
	else if (IsDown(static_cast<unsigned int>(ControllerButton::ButtonB)))
	{
		std::cout << "Button B is down this frame\n";
		m_ButtonB->Execute();
	}
	else if (IsDown(static_cast<unsigned int>(ControllerButton::ButtonY)))
	{
		std::cout << "Button Y is down this frame\n";
		m_ButtonY->Execute();
	}
	else if (IsDown(static_cast<unsigned int>(ControllerButton::ButtonRightShoulder)))
	{
		std::cout << "Button RB is down this frame\n";
		m_ButtonRightShoulder->Execute();
	}

	//Released
	if (IsUp(static_cast<unsigned int>(ControllerButton::ButtonY)))
	{
		std::cout << "Button Y is Up this frame\n";
		m_ButtonY->Execute();
	}
	else if (IsUp(static_cast<unsigned int>(ControllerButton::ButtonA)))
	{
		std::cout << "Button A is Up this frame\n";
		m_ButtonA->Execute();
	}
	if (IsUp(static_cast<unsigned int>(ControllerButton::ButtonB)))
	{
		std::cout << "Button B is Up this frame\n";
		m_ButtonB->Execute();
	}
	if (IsUp(static_cast<unsigned int>(ControllerButton::ButtonRightShoulder)))
	{
		std::cout << "Button RB is Up this frame\n";
		m_ButtonRightShoulder->Execute();
	}
}
