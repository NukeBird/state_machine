#include "state_machine.h"
#include "state.h"

void StateMachine::push_state(const StateRef& state)
{
	stack.emplace(state);
}

void StateMachine::push_state(State* state)
{
	push_state(StateRef(state));
}

StateRef StateMachine::pop_state()
{
	auto state = get_current_state();

	stack.pop();

	return state;
}

StateRef StateMachine::get_current_state() const
{
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
