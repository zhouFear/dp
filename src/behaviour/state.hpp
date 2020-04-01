#pragma once 

// 状态模式
#include <iostream>

using namespace std;

namespace State {
	class Context;
	class ConcreteStateB;
	class State
	{
	public:
		State() = default;
		virtual ~State() = default;

		virtual void handle(Context* context) = 0;
	private:

	};

	class ConcreteStateA : public State
	{
	public:
		ConcreteStateA() : State() {};
		~ConcreteStateA() = default;


		void handle(Context* context) override;

	public:
		static State* instance;
		static State* getInstance() {
			if (!instance)
			{
				instance = new ConcreteStateA();
			}
			return instance;
		}
	};


	class ConcreteStateB : public State
	{
	public:
		ConcreteStateB() : State() {};
		~ConcreteStateB() = default;


		void handle(Context* context) override;
	public:
		static State* instance;
		static State* getInstance() {
			if (!instance)
			{
				instance = new ConcreteStateB();
			}
			return instance;
		}
	};


	class Context
	{
	public:
		Context() = default;
		~Context() = default;

	public:
		void request() {
			if (state) {
				state->handle(this);
			}
		}


		void setState(State* s) {
			state = s;
		}
	private:
		State* state = ConcreteStateA::getInstance();
	};


	void ConcreteStateA::handle(Context* context) {
		cout << "现在是状态A， 切换到状态B" << endl;
		if (context) {
			context->setState(ConcreteStateB::getInstance());
		}
	}

	void ConcreteStateB::handle(Context* context) {
		cout << "现在是状态A， 切换到状态B" << endl;
		if (context) {
			context->setState(ConcreteStateA::getInstance());
		}
	}
};
