#pragma once
#include <memory>
#include <stack>
#include "state.h"

using StateRef = std::shared_ptr<State>;

class StateMachine
{
public:
	void push_state(const StateRef& state);

	StateRef pop_state();

	StateRef get_current_state() const;

	void update(float dt);
private:
	std::stack<StateRef> stack;
};
