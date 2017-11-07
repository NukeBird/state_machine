#include "state_machine.h"
#include "state.h"
#include <exception>

void StateMachine::push_state(const StateRef& state)
{
	stack.emplace(state);
}

StateRef StateMachine::pop_state()
{
	auto state = get_current_state();

	stack.pop();

	return state;
}

StateRef StateMachine::get_current_state() const
{
	if (stack.empty())
		throw std::logic_error("Stack is empty");

	return stack.top();
}

void StateMachine::update(float dt)
{
	if(!stack.empty())
	{
		auto state = get_current_state();

		state->update(dt);
		state->draw(dt);
	}
}
