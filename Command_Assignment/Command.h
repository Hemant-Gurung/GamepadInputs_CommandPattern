#pragma once
#include <iostream>
class Command
{
public:
	virtual ~Command() = default;
	virtual void Execute() = 0;
	 
};

//jump

class JumpCommand: public Command
{
public:
	void  Execute() override { std::cout << "Jumping\n"; };
};

//FireGun 

class FireGunCommand : public Command
{
public:
	void  Execute() override { std::cout << "Firing Gun\n"; }
};

//Duck

class DuckCommand : public Command
{
public:
	void  Execute() override { std::cout << "Ducking\n"; }
};

//Fart

class FartCommand : public Command
{
public:
	void  Execute() override { std::cout << "Farting \n"; }
};