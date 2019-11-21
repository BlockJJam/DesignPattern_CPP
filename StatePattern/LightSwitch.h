#pragma once
#include <iostream>

class LightSwitch;

class LightState
{
public:
	virtual void on_button_pushed(LightSwitch * light) = 0;
	virtual void off_button_pushed(LightSwitch * light) = 0;
	virtual ~LightState() {};
};

class ON : public LightState
{
private:
	static LightState * _onState;

public:
	~ON()
	{
		delete _onState;
	}

	static LightState & getInstance()
	{
		_onState = new ON();
		return *_onState;
	}

	void on_button_pushed(LightSwitch * light) override;

	void off_button_pushed(LightSwitch * light) override;

};

class OFF : public LightState
{
private:
	static LightState * _offState;

public:
	OFF()
	{
		_offState = nullptr;
	}
	~OFF()
	{
		delete _offState;
	}

	static LightState & getInstance()
	{
		_offState = new OFF();
		return *_offState;
	}

	void on_button_pushed(LightSwitch * light) override;

	void off_button_pushed(LightSwitch * light) override
	{
		std::cout << "Nothing" << std::endl;
	}

};

class SLEEP : public LightState
{
private:
	static LightState * _sleepState;

public:
	~SLEEP()
	{
		delete _sleepState;
	}

	static LightState & getInstance()
	{
		_sleepState = new SLEEP();
		return *_sleepState;
	}

	void on_button_pushed(LightSwitch * light) override
	{
		std::cout << "Nothing" << std::endl;
	}

	void off_button_pushed(LightSwitch * light) override;
};


class LightSwitch
{
private:
	LightState *_state = nullptr;

public:
	LightSwitch()
	{
		_state = new OFF();
	}

	~LightSwitch()
	{
		delete _state;
	}

	void setState(LightState * state) 
	{
		_state = state;
	}
	void on_button_pushed() 
	{
		_state->on_button_pushed(this);
	}
	void off_button_pushed() 
	{
		_state->off_button_pushed(this);
	}
};

void ON::on_button_pushed(LightSwitch * light)
{
	std::cout << "Sleeping Light On" << std::endl;
	light->setState(&(SLEEP::getInstance()));
}

void ON::off_button_pushed(LightSwitch * light)
{
	std::cout << "Light Off" << std::endl;
	light->setState(&(OFF::getInstance()));
}


void SLEEP::off_button_pushed(LightSwitch * light)
{
	std::cout << "Light off" << std::endl;
	light->setState(&(OFF::getInstance()));
}

void OFF::on_button_pushed(LightSwitch * light)
{
	std::cout << "Light On" << std::endl;
	light->setState(&(ON::getInstance()));
}

LightState* OFF::_offState ;
LightState* ON::_onState;
LightState* SLEEP::_sleepState;

// class 내부에 선언한 static 변수는 클래스 정의 끝부분에 반드시 추가해야함